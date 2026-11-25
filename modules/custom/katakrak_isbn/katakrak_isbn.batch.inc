<?php

/**
 * @file
 * Operaciones del Batch API para katakrak_isbn.
 */

/**
 * Operación del batch: procesa un bloque de líneas por llamada.
 *
 * @param string $uri
 *   URI del CSV ya normalizado (UTF-8, saltos de línea "\n").
 * @param string $delimitador
 *   Delimitador detectado (';' o ',').
 * @param bool $tiene_cabecera
 *   TRUE si la primera línea es una cabecera y hay que saltarla.
 */
function katakrak_isbn_batch_procesar($uri, $delimitador, $tiene_cabecera, &$context) {
  $limite = 200;          // Líneas por iteración.
  $max_errores = 200;     // Tope de errores guardados en el contexto.

  $ruta = drupal_realpath($uri);

  // Inicialización (solo en la primera llamada).
  if (!isset($context['sandbox']['posicion'])) {
    $context['sandbox']['posicion'] = 0;
    $context['sandbox']['tamano'] = $ruta ? filesize($ruta) : 0;
    $context['results']['uri'] = $uri;
    $context['results']['linea'] = 0;
    $context['results']['leidas'] = 0;
    $context['results']['procesadas'] = 0;
    $context['results']['no_encontradas'] = 0;
    $context['results']['errores'] = array();
  }

  $fh = $ruta ? fopen($ruta, 'r') : FALSE;
  if (!$fh) {
    $context['results']['errores'][] = t('No se pudo abrir el archivo.');
    $context['finished'] = 1;
    return;
  }

  fseek($fh, $context['sandbox']['posicion']);

  // Primera llamada: saltar la cabecera.
  if ($context['sandbox']['posicion'] === 0 && $tiene_cabecera) {
    fgetcsv($fh, 0, $delimitador);
    $context['results']['linea']++;
  }

  $leidas = 0;
  $fin_archivo = FALSE;

  while ($leidas < $limite) {
    $fila = fgetcsv($fh, 0, $delimitador);
    if ($fila === FALSE) {
      $fin_archivo = TRUE;
      break;
    }
    $leidas++;
    $context['results']['linea']++;

    // Línea en blanco.
    if ($fila === array(NULL)) {
      continue;
    }

    $context['results']['leidas']++;

    // Diagnóstico: registrar cómo se leen las primeras filas.
    if ($context['results']['leidas'] <= 3) {
      watchdog('katakrak_isbn', 'Fila @n leída con @c campos: @datos', array(
        '@n' => $context['results']['linea'],
        '@c' => count($fila),
        '@datos' => implode(' | ', $fila),
      ), WATCHDOG_DEBUG);
    }

    // Extraer las 3 columnas en variables.
    $fila = array_pad($fila, 3, '');
    $columna1 = trim($fila[0]);
    $columna2 = trim($fila[1]);
    $columna3 = trim($fila[2]);

    try {
      if (katakrak_isbn_procesar_linea($columna1, $columna2, $columna3)) {
        $context['results']['procesadas']++;
      }
      else {
        $context['results']['no_encontradas']++;
        if (count($context['results']['errores']) < $max_errores) {
          $context['results']['errores'][] = t('Línea @n: no existe el SKU @sku.', array(
            '@n' => $context['results']['linea'],
            '@sku' => $columna1,
          ));
        }
      }
    }
    catch (Exception $e) {
      if (count($context['results']['errores']) < $max_errores) {
        $context['results']['errores'][] = t('Línea @n: @msg', array(
          '@n' => $context['results']['linea'],
          '@msg' => $e->getMessage(),
        ));
      }
      watchdog('katakrak_isbn', 'Error en línea @n: @msg', array(
        '@n' => $context['results']['linea'],
        '@msg' => $e->getMessage(),
      ), WATCHDOG_ERROR);
    }
  }

  $context['sandbox']['posicion'] = ftell($fh);
  fclose($fh);

  // Progreso (0 a 1). Con 1 el batch termina.
  if ($fin_archivo || $context['sandbox']['tamano'] == 0) {
    $context['finished'] = 1;
  }
  else {
    $context['finished'] = min(0.99, $context['sandbox']['posicion'] / $context['sandbox']['tamano']);
  }

  $context['message'] = t('Leídas @n líneas...', array('@n' => $context['results']['linea']));
}

/**
 * Lógica de base de datos para cada línea del CSV.
 *
 * @return bool
 *   TRUE si el producto existe y se procesó; FALSE si el SKU no existe.
 *
 * @throws Exception
 *   Si el SKU está vacío o falla alguna consulta.
 */
function katakrak_isbn_procesar_linea($columna1, $columna2, $columna3) {
  if ($columna1 === '') {
    throw new Exception(t('SKU vacío.'));
  }

  // Transacción por línea: si algo falla, se revierte solo esa línea.
  $transaccion = db_transaction();

  try {
    // Buscar el producto por SKU y el nodo que lo referencia.
    $query = db_select('commerce_product', 'cp');
    $query->join('field_data_field_libro_producto', 'flp', 'flp.field_libro_producto_product_id = cp.product_id');
    $query->fields('cp', array('product_id', 'sku', 'title'))
      ->fields('flp', array('entity_id', 'entity_type', 'bundle'))
      ->condition('cp.sku', $columna1)
      ->condition('flp.deleted', 0)
      ->range(0, 1);

    $resultado = $query->execute()->fetchObject();
    if (!$resultado) {
      return FALSE;
    }

    $node = node_load($resultado->entity_id);
    if (empty($node->field_libro_ean['und'][0]['value']) || empty($node->field_libro_isbn['und'][0]['value'])) {
      $node->field_libro_ean['und'][0]['value'] = $columna2;
      $node->field_libro_isbn['und'][0]['value'] = $columna3;
      node_save($node);
    }
    else {
      return FALSE;
    }

    // Aquí ya tienes:
    //   $resultado->product_id  -> ID del producto Commerce.
    //   $resultado->entity_id   -> ID del nodo "libro" que referencia al producto.
    //
    // TODO: ejecutar aquí las consultas de escritura con $columna2 y $columna3.
    // IMPORTANTE: la condición debe depender de $resultado->product_id o
    // $resultado->entity_id, si no, cada línea sobreescribe la anterior.
    // Ejemplo:
    // db_update('commerce_product')
    //   ->fields(array('changed' => REQUEST_TIME))
    //   ->condition('product_id', $resultado->product_id)
    //   ->execute();

    return TRUE;
  }
  catch (Exception $e) {
    $transaccion->rollback();
    throw $e;
  }
}

/**
 * Callback final del batch.
 */
function katakrak_isbn_batch_finalizado($success, $results, $operations) {
  // Borrar la copia temporal del CSV.
  if (!empty($results['uri'])) {
    file_unmanaged_delete($results['uri']);
  }

  if ($success) {
    drupal_set_message(t('Proceso terminado. Filas leídas: @l. Procesadas: @p. SKU no encontrados: @ne.', array(
      '@l' => isset($results['leidas']) ? $results['leidas'] : 0,
      '@p' => isset($results['procesadas']) ? $results['procesadas'] : 0,
      '@ne' => isset($results['no_encontradas']) ? $results['no_encontradas'] : 0,
    )));
    if (!empty($results['errores'])) {
      drupal_set_message(t('Primeros avisos (hasta 10 de @n):', array(
        '@n' => count($results['errores']),
      )), 'warning');
      foreach (array_slice($results['errores'], 0, 10) as $error) {
        drupal_set_message($error, 'warning');
      }
    }
  }
  else {
    drupal_set_message(t('El proceso terminó con errores.'), 'error');
  }
}
