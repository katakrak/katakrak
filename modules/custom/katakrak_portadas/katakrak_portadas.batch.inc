<?php

/**
 * Devuelve, de una lista de URIs, las que existen en la base de datos.
 *
 * Si tu tabla es otra, cambia solo esta función (tabla y columna).
 *
 * @return array
 *   array(uri => TRUE).
 */
function katakrak_portadas_uris_en_bd(array $uris) {
  if (empty($uris)) {
    return array();
  }
  $encontradas = db_select('file_managed', 'f')
    ->fields('f', array('uri'))
    ->condition('f.uri', $uris, 'IN')
    ->execute()
    ->fetchCol();

  return array_fill_keys($encontradas, TRUE);
}

/**
 * Añade una fila al CSV.
 */
function katakrak_portadas_csv($uri_csv, array $fila) {
  if ($fh = @fopen($uri_csv, 'a')) {
    fputcsv($fh, $fila, ';');
    fclose($fh);
  }
}

/**
 * Redimensiona una imagen si con ello baja de peso.
 *
 * @return array
 *   array(estado, bytes_despues). bytes_despues es '' si no aplica.
 */
function katakrak_portadas_redimensionar($uri, $ruta, $size, array &$s, array $op) {
  global $conf;

  $info = image_get_info($ruta);
  if (!$info || !in_array($info['extension'], array('jpg', 'jpeg', 'png'), TRUE)) {
    $s['omitidos']++;
    return array('omitido_no_jpg_png', '');
  }

  // Protección de memoria: GD necesita unos 4-5 bytes por píxel.
  $limite = ini_get('memory_limit');
  if ($limite != -1) {
    $necesaria = $info['width'] * $info['height'] * 5 + memory_get_usage();
    if ($necesaria > parse_size($limite)) {
      $s['fallos']++;
      return array('error_memoria_insuficiente', '');
    }
  }

  if ($op['simular']) {
    return array('simulado_' . $info['width'] . 'x' . $info['height'], '');
  }

  // Calidad JPEG solo para esta petición (no se guarda en la BD).
  $conf['image_jpeg_quality'] = $op['calidad'];

  $image = image_load($ruta);
  if (!$image) {
    $s['fallos']++;
    return array('error_carga', '');
  }

  $ok = image_scale($image, $op['ancho'], $op['alto'], FALSE);
  $tmp = drupal_tempnam('temporary://', 'katakrak');
  $tmp_real = drupal_realpath($tmp);
  $ok = $ok && image_save($image, $tmp);

  if (isset($image->resource) && is_resource($image->resource)) {
    imagedestroy($image->resource);
  }
  unset($image);

  if (!$ok) {
    @unlink($tmp_real);
    $s['fallos']++;
    return array('error_procesando', '');
  }

  clearstatcache(TRUE, $tmp_real);
  $nuevo = @filesize($tmp_real);

  // Solo se sustituye si realmente pesa menos.
  if (!$nuevo || $nuevo >= $size) {
    @unlink($tmp_real);
    $s['sin_mejora']++;
    return array('sin_mejora', '');
  }

  // Copia de seguridad del original (solo ahora que sabemos que se va a sustituir).
  if (!empty($s['backup_uri'])) {
    $relativa = substr($uri, strlen($s['base_uri']));
    $destino = $s['backup_uri'] . '/' . $relativa;
    $dir_destino = dirname($destino);
    if (!file_prepare_directory($dir_destino, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)
      || !@copy($ruta, $destino)
      || !file_exists($destino)) {
      @unlink($tmp_real);
      $s['fallos']++;
      return array('error_copia_seguridad', '');
    }
  }

  // Sustitución atómica: archivo oculto (se ignora al leer el directorio) + rename.
  $aux = dirname($ruta) . '/.katakrak_' . basename($ruta);
  if (!@copy($tmp_real, $aux) || !@rename($aux, $ruta)) {
    @unlink($aux);
    @unlink($tmp_real);
    $s['fallos']++;
    return array('error_escritura', '');
  }
  @unlink($tmp_real);
  @drupal_chmod($ruta);

  // Mantener la BD y los derivados coherentes.
  db_update('file_managed')
    ->fields(array('filesize' => $nuevo))
    ->condition('uri', $uri)
    ->execute();
  image_path_flush($uri);

  $s['redimensionados']++;
  $s['bytes_ahorrados'] += ($size - $nuevo);

  return array('redimensionado', $nuevo);
}

/**
 * Comprueba un bloque de archivos grandes y los trata según la acción.
 *
 * @param array $s
 *   Sandbox del batch (por referencia).
 * @param array $buffer
 *   array(uri => array('size' => bytes, 'ruta' => ruta real)).
 * @param array $op
 *   Opciones del proceso.
 */
function katakrak_portadas_batch_volcar(array &$s, array &$buffer, array $op) {
  if (empty($buffer)) {
    return;
  }
  $en_bd = katakrak_portadas_uris_en_bd(array_keys($buffer));
  $redim = ($op['accion'] === 'redimensionar');

  foreach ($buffer as $uri => $info) {
    $referenciado = isset($en_bd[$uri]);

    if (($op['filtro'] === 'en_bd' && !$referenciado) || ($op['filtro'] === 'sin_bd' && $referenciado)) {
      continue;
    }

    $s['listados']++;
    $s['bytes_listados'] += $info['size'];

    $estado = 'listado';
    $despues = '';
    if ($redim) {
      list($estado, $despues) = katakrak_portadas_redimensionar($uri, $info['ruta'], $info['size'], $s, $op);
    }

    katakrak_portadas_csv($s['csv'], array(
      $uri,
      $info['size'],
      round($info['size'] / 1024, 1),
      $referenciado ? 'si' : 'no',
      $estado,
      $despues,
      ($despues === '') ? '' : round($despues / 1024, 1),
    ));
  }
  $buffer = array();
}

/**
 * Operación del batch.
 */
function katakrak_portadas_batch_calcular_peso($directorio, array $op, &$context) {
  $redim = ($op['accion'] === 'redimensionar');
  // Redimensionar es lento: lotes pequeños y comprobación de tiempo frecuente.
  $limite_tiempo = $redim ? 8 : 10;
  $tam_bloque = $redim ? 5 : 500;
  $intervalo = $redim ? 5 : 500;
  $inicio = microtime(TRUE);

  if (!isset($context['sandbox']['pendientes'])) {
    $raiz = drupal_realpath($directorio);
    if ($raiz === FALSE) {
      $context['finished'] = 1;
      return;
    }
    $base_uri = (substr($directorio, -3) === '://') ? $directorio : rtrim($directorio, '/') . '/';
    $uri_csv = 'temporary://katakrak_portadas_' . date('Ymd_His') . '.csv';

    $excluir = $op['excluir'];
    $backup_uri = '';
    if ($op['backup_dir'] !== '') {
      $backup_uri = $op['backup_dir'] . '/' . date('Ymd_His');
      // Si las copias están dentro del directorio analizado, excluirlas.
      if (strpos($op['backup_dir'] . '/', $base_uri) === 0) {
        $excluir[] = trim(substr($op['backup_dir'], strlen($base_uri)), '/');
      }
    }

    $context['sandbox']['raiz'] = rtrim($raiz, '/');
    $context['sandbox']['base_uri'] = $base_uri;
    $context['sandbox']['csv'] = $uri_csv;
    $context['sandbox']['backup_uri'] = $backup_uri;
    $context['sandbox']['excluir'] = $excluir;
    $context['sandbox']['pendientes'] = array($context['sandbox']['raiz']);
    $context['sandbox']['actual'] = NULL;
    $context['sandbox']['offset'] = 0;
    $context['sandbox']['directorios'] = 0;
    $context['sandbox']['revisados'] = 0;
    $context['sandbox']['listados'] = 0;
    $context['sandbox']['bytes_listados'] = 0;
    $context['sandbox']['redimensionados'] = 0;
    $context['sandbox']['bytes_ahorrados'] = 0;
    $context['sandbox']['sin_mejora'] = 0;
    $context['sandbox']['omitidos'] = 0;
    $context['sandbox']['fallos'] = 0;
    $context['sandbox']['errores'] = 0;

    katakrak_portadas_csv($uri_csv, array('uri', 'bytes', 'kb', 'en_bd', 'resultado', 'bytes_despues', 'kb_despues'));
  }

  $s = &$context['sandbox'];
  $agotado = FALSE;

  while (!$agotado) {
    if ($s['actual'] === NULL) {
      if (empty($s['pendientes'])) {
        break;
      }
      $s['actual'] = array_pop($s['pendientes']);
      $s['offset'] = 0;
      $s['directorios']++;
    }

    $dir = $s['actual'];
    $handle = @opendir($dir);
    if (!$handle) {
      $s['errores']++;
      $s['actual'] = NULL;
      continue;
    }

    $leidos = 0;
    $terminado = TRUE;
    $buffer = array();

    while (($entrada = readdir($handle)) !== FALSE) {
      $leidos++;

      if ($leidos <= $s['offset']) {
        continue;
      }
      // Se ignoran '.', '..' y archivos ocultos (incluidos los temporales del módulo).
      if ($entrada[0] === '.') {
        continue;
      }

      $ruta = $dir . '/' . $entrada;
      $st = @lstat($ruta);

      if ($st === FALSE) {
        $s['errores']++;
      }
      else {
        $tipo = $st['mode'] & 0170000;
        $relativa = ltrim(substr($ruta, strlen($s['raiz'])), '/');

        if ($tipo === 0040000) {
          if (!in_array($relativa, $s['excluir'], TRUE)) {
            $s['pendientes'][] = $ruta;
          }
        }
        elseif ($tipo === 0100000) {
          $s['revisados']++;

          if ($st['size'] > $op['umbral']) {
            $buffer[$s['base_uri'] . $relativa] = array('size' => $st['size'], 'ruta' => $ruta);

            if (count($buffer) >= $tam_bloque) {
              katakrak_portadas_batch_volcar($s, $buffer, $op);
            }
          }
        }
        // Enlaces simbólicos y otros: se ignoran.
      }

      if ($leidos % $intervalo === 0 && (microtime(TRUE) - $inicio) >= $limite_tiempo) {
        katakrak_portadas_batch_volcar($s, $buffer, $op);
        $s['offset'] = $leidos;
        $terminado = FALSE;
        $agotado = TRUE;
        break;
      }
    }
    closedir($handle);

    katakrak_portadas_batch_volcar($s, $buffer, $op);

    if ($terminado) {
      $s['actual'] = NULL;
      if ((microtime(TRUE) - $inicio) >= $limite_tiempo) {
        $agotado = TRUE;
      }
    }
  }

  $context['results']['directorio'] = $directorio;
  $context['results']['csv'] = $s['csv'];
  $context['results']['umbral'] = $op['umbral'];
  $context['results']['accion'] = $op['accion'];
  $context['results']['simular'] = $op['simular'];
  $context['results']['backup_uri'] = $s['backup_uri'];
  foreach (array('revisados', 'listados', 'bytes_listados', 'redimensionados', 'bytes_ahorrados', 'sin_mejora', 'omitidos', 'fallos', 'directorios', 'errores') as $k) {
    $context['results'][$k] = $s[$k];
  }

  $hecho = ($s['actual'] === NULL && empty($s['pendientes']));

  if ($redim && !$op['simular']) {
    $context['message'] = t('@r archivos revisados, @x redimensionados (@peso ahorrados). Directorios pendientes: @p', array(
      '@r' => number_format($s['revisados'], 0, ',', '.'),
      '@x' => number_format($s['redimensionados'], 0, ',', '.'),
      '@peso' => format_size($s['bytes_ahorrados']),
      '@p' => count($s['pendientes']),
    ));
  }
  else {
    $context['message'] = t('@r archivos revisados, @l listados (@peso). Directorios pendientes: @p', array(
      '@r' => number_format($s['revisados'], 0, ',', '.'),
      '@l' => number_format($s['listados'], 0, ',', '.'),
      '@peso' => format_size($s['bytes_listados']),
      '@p' => count($s['pendientes']),
    ));
  }

  $context['finished'] = $hecho ? 1 : 0.99;
}

/**
 * Callback final del batch.
 */
function katakrak_portadas_batch_peso_finalizado($success, $results, $operations) {
  if (!$success || empty($results)) {
    drupal_set_message(t('El proceso terminó con errores.'), 'error');
    return;
  }

  $nf = function ($n) {
    return number_format($n, 0, ',', '.');
  };

  drupal_set_message(t('Directorio @dir: @r archivos revisados; @l superan @kb KB y suman @peso.', array(
    '@dir' => $results['directorio'],
    '@r' => $nf($results['revisados']),
    '@l' => $nf($results['listados']),
    '@kb' => round($results['umbral'] / 1024),
    '@peso' => format_size($results['bytes_listados']),
  )));

  if ($results['accion'] === 'redimensionar') {
    if ($results['simular']) {
      drupal_set_message(t('SIMULACIÓN: no se ha modificado ningún archivo. Revisa el CSV para ver cuáles se procesarían.'), 'warning');
    }
    else {
      drupal_set_message(t('Redimensionados @n archivos, ahorrando @peso. Sin mejora (no se tocaron): @m. Omitidos (no JPG/PNG): @o.', array(
        '@n' => $nf($results['redimensionados']),
        '@peso' => format_size($results['bytes_ahorrados']),
        '@m' => $nf($results['sin_mejora']),
        '@o' => $nf($results['omitidos']),
      )));
      watchdog('katakrak_portadas', 'Redimensionado en @dir: @n archivos, @bytes bytes ahorrados.', array(
        '@dir' => $results['directorio'],
        '@n' => $results['redimensionados'],
        '@bytes' => $results['bytes_ahorrados'],
      ), WATCHDOG_NOTICE);

      if (!empty($results['backup_uri'])) {
        drupal_set_message(t('Copias de los originales en: @dir', array('@dir' => drupal_realpath($results['backup_uri']) ?: $results['backup_uri'])));
      }
    }
    if (!empty($results['fallos'])) {
      drupal_set_message(t('@n archivos no se pudieron procesar (ver columna "resultado" del CSV).', array('@n' => $results['fallos'])), 'error');
    }
  }

  if (!empty($results['errores'])) {
    drupal_set_message(t('@n entradas no se pudieron leer.', array('@n' => $results['errores'])), 'warning');
  }

  drupal_set_message(t('Listado CSV: @csv', array('@csv' => drupal_realpath($results['csv']))));
}
