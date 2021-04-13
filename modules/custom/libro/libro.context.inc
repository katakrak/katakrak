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
  $context->name = 'libros_secciones';
  $context->description = 'Libros secciones';
  $context->tag = 'Tienda online';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'materias' => 'materias',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'libro-libreria_home_bizikrak' => array(
          'module' => 'libro',
          'delta' => 'libreria_home_bizikrak',
          'region' => 'banners',
          'weight' => '-10',
        ),
      ),
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
      'values' => array(
        'libro' => 'libro',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'libro-libreria_home_search' => array(
          'module' => 'libro',
          'delta' => 'libreria_home_search',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => array(
      0 => 'menu-menu-nagusia:libreria',
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
        'libro-libreria_home_search' => array(
          'module' => 'libro',
          'delta' => 'libreria_home_search',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-libros-recomendados_narrativa' => array(
          'module' => 'views',
          'delta' => 'libros-recomendados_narrativa',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-libros-recomendados_infantil' => array(
          'module' => 'views',
          'delta' => 'libros-recomendados_infantil',
          'region' => 'content',
          'weight' => '2',
        ),
        'libro-libreria_categorias' => array(
          'module' => 'libro',
          'delta' => 'libreria_categorias',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-libros-recomendados_comic' => array(
          'module' => 'views',
          'delta' => 'libros-recomendados_comic',
          'region' => 'content',
          'weight' => '3',
        ),
        'libro-libreria_home_bizikrak' => array(
          'module' => 'libro',
          'delta' => 'libreria_home_bizikrak',
          'region' => 'banners',
          'weight' => '-9',
        ),
        'libro-libreria_home_destacado' => array(
          'module' => 'libro',
          'delta' => 'libreria_home_destacado',
          'region' => 'content_middle',
          'weight' => '-10',
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
