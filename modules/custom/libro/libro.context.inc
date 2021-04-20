<?php

/**
 * @file
 * libro.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function libro_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'faq-libreria';
  $context->description = '';
  $context->tag = 'Libro';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'faq-librería' => 'faq-librería',
        'faq-liburudenda' => 'faq-liburudenda',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Libro');
  $export['faq-libreria'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'landing_libreria';
  $context->description = '';
  $context->tag = 'Landing';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'libreria' => 'libreria',
        'liburudenda' => 'liburudenda',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'libro-libreria_landing_hero' => array(
          'delta' => 'libreria_landing_hero',
          'module' => 'libro',
          'region' => 'hero',
          'weight' => '-10',
        ),
        'libro-libreria_landing_highlight' => array(
          'delta' => 'libreria_landing_highlight',
          'module' => 'libro',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'landing',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing');
  $export['landing_libreria'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'libros_secciones';
  $context->description = 'Libros secciones';
  $context->tag = 'Tienda online';
  $context->conditions = array(
    'taxonomy_term' => array(
      'options' => array(
        'term_form' => '0',
      ),
      'values' => array(
        'autores' => 'autores',
        'materias' => 'materias',
      ),
    ),
    'views' => array(
      'values' => array(
        'secciones:pagina_secciones' => 'secciones:pagina_secciones',
        'secciones:pagina_secciones_eus' => 'secciones:pagina_secciones_eus',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'libro-libreria_home_bizikrak' => array(
          'delta' => 'libreria_home_bizikrak',
          'module' => 'libro',
          'region' => 'banners',
          'weight' => '-10',
        ),
        'libro-libreria_home_search' => array(
          'delta' => 'libreria_home_search',
          'module' => 'libro',
          'region' => 'content_top',
          'weight' => '-9',
        ),
        'libro-libreria_secciones_breadcrumb' => array(
          'delta' => 'libreria_secciones_breadcrumb',
          'module' => 'libro',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'libro-libreria_secciones_titulo' => array(
          'delta' => 'libreria_secciones_titulo',
          'module' => 'libro',
          'region' => 'content_top',
          'weight' => '-8',
        ),
      ),
    ),
    'menu' => array(
      0 => 'main-menu:tienda',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Libros secciones');
  t('Tienda online');
  $export['libros_secciones'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node_book';
  $context->description = '';
  $context->tag = 'Tienda online';
  $context->conditions = array(
    'node' => array(
      'options' => array(
        'node_form' => '0',
      ),
      'values' => array(
        'libro' => 'libro',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'libro-libreria_home_bizikrak' => array(
          'delta' => 'libreria_home_bizikrak',
          'module' => 'libro',
          'region' => 'banners',
          'weight' => '-10',
        ),
        'libro-libreria_home_search' => array(
          'delta' => 'libreria_home_search',
          'module' => 'libro',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'system-main' => array(
          'delta' => 'main',
          'module' => 'system',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
    'menu' => array(
      0 => 'main-menu:tienda',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Tienda online');
  $export['node_book'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pagina_libreria';
  $context->description = 'Página principal librería';
  $context->tag = 'Tienda online';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'libros:page' => 'libros:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'libro-libreria_categorias' => array(
          'delta' => 'libreria_categorias',
          'module' => 'libro',
          'region' => 'content',
          'weight' => '10',
        ),
        'libro-libreria_home_bizikrak' => array(
          'delta' => 'libreria_home_bizikrak',
          'module' => 'libro',
          'region' => 'banners',
          'weight' => '-9',
        ),
        'libro-libreria_home_destacado' => array(
          'delta' => 'libreria_home_destacado',
          'module' => 'libro',
          'region' => 'content_middle',
          'weight' => '-9',
        ),
        'libro-libreria_home_search' => array(
          'delta' => 'libreria_home_search',
          'module' => 'libro',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-libros-recomendados_comic' => array(
          'delta' => 'libros-recomendados_comic',
          'module' => 'views',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-libros-recomendados_infantil' => array(
          'delta' => 'libros-recomendados_infantil',
          'module' => 'views',
          'region' => 'content',
          'weight' => '7',
        ),
        'views-libros-recomendados_narrativa' => array(
          'delta' => 'libros-recomendados_narrativa',
          'module' => 'views',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Página principal librería');
  t('Tienda online');
  $export['pagina_libreria'] = $context;

  return $export;
}
