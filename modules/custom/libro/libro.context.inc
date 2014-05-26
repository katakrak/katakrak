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
    'menu' => 'libros',
    'region' => array(
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'coworker' => array(
        'disable' => array(
          'content' => 'content',
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'slider' => 0,
          'contact_map' => 0,
          'header' => 0,
          'header_right' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content_top' => 0,
          'content_bottom' => 0,
          'content_bottom_left' => 0,
          'content_bottom_right' => 0,
          'post_content_bottom_right' => 0,
          'footer' => 0,
          'footer_first' => 0,
          'footer_second' => 0,
          'footer_third' => 0,
          'footer_fourth' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
    'theme' => array(
      'title' => 'Leer os hará libros',
      'subtitle' => '',
    ),
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
