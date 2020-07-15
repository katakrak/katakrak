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
  $context->name = 'libros_por_categoria';
  $context->description = '';
  $context->tag = 'Libro';
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
        'libro-libreria_home_search' => array(
          'module' => 'libro',
          'delta' => 'libreria_home_search',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'book',
    ),
    'theme_html' => array(
      'class' => 'block-book-search',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Libro');
  $export['libros_por_categoria'] = $context;

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
        'libro-libreria_home_search' => array(
          'module' => 'libro',
          'delta' => 'libreria_home_search',
          'region' => 'content_top',
          'weight' => '-10',
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
        'libro-libreria_home_bono_regalo' => array(
          'module' => 'libro',
          'delta' => 'libreria_home_bono_regalo',
          'region' => 'banners',
          'weight' => '-10',
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
        'views-libros-libros_mas_vendidos' => array(
          'module' => 'views',
          'delta' => 'libros-libros_mas_vendidos',
          'region' => 'content_bottom',
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
