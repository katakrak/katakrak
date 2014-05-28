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
  $context->tag = 'Book';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'faq-librería' => 'faq-librería',
        'faq-liburudenda' => 'faq-liburudenda',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'libros',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Book');
  $export['faq-libreria'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'libros_por_categoria';
  $context->description = '';
  $context->tag = 'Book';
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
        'katakrak_search-katakrak_books_search_block' => array(
          'module' => 'katakrak_search',
          'delta' => 'katakrak_books_search_block',
          'region' => 'content_bottom_left',
          'weight' => '-10',
        ),
        'libro-katakrak_libro_estilo' => array(
          'module' => 'libro',
          'delta' => 'katakrak_libro_estilo',
          'region' => 'content_bottom_right',
          'weight' => '-10',
        ),
      ),
      'layout' => 'book',
    ),
    'menu' => 'libros',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Book');
  $export['libros_por_categoria'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node_book';
  $context->description = '';
  $context->tag = 'Book';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'libro' => 'libro',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'libros:page' => 'libros:page',
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
          'weight' => '-10',
        ),
        'katakrak_search-katakrak_books_search_block' => array(
          'module' => 'katakrak_search',
          'delta' => 'katakrak_books_search_block',
          'region' => 'content_bottom_left',
          'weight' => '-10',
        ),
        'libro-katakrak_libro_estilo' => array(
          'module' => 'libro',
          'delta' => 'katakrak_libro_estilo',
          'region' => 'content_bottom_right',
          'weight' => '-10',
        ),
      ),
      'layout' => 'book',
    ),
    'menu' => 'libros',
    'theme' => array(
      'title' => 'Leer os hará libros',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Book');
  $export['node_book'] = $context;

  return $export;
}
