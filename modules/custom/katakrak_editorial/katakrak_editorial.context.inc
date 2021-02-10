<?php

/**
 * @file
 * katakrak_editorial.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_editorial_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'autores_editorial_landing';
  $context->description = 'Landing de autores editorial';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'editorial:page_3' => 'editorial:page_3',
        'editorial:page_4' => 'editorial:page_4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_editorial-editorial_autores_nav_secunday' => array(
          'module' => 'katakrak_editorial',
          'delta' => 'editorial_autores_nav_secunday',
          'region' => 'content',
          'weight' => '-10',
        ),
        'katakrak_editorial-editorial_filter_autores' => array(
          'module' => 'katakrak_editorial',
          'delta' => 'editorial_filter_autores',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial');
  t('Landing de autores editorial');
  $export['autores_editorial_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'editorial_landing';
  $context->description = 'Landing editorial';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'editorial:page_1' => 'editorial:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-editorial-block_3' => array(
          'module' => 'views',
          'delta' => 'editorial-block_3',
          'region' => 'content_middle',
          'weight' => '-10',
        ),
        'views-editorial-block_5' => array(
          'module' => 'views',
          'delta' => 'editorial-block_5',
          'region' => 'content_middle',
          'weight' => '-9',
        ),
        'views-editorial-block_8' => array(
          'module' => 'views',
          'delta' => 'editorial-block_8',
          'region' => 'content_middle',
          'weight' => '-8',
        ),
        'views-editorial-block_9' => array(
          'module' => 'views',
          'delta' => 'editorial-block_9',
          'region' => 'content_middle',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial');
  t('Landing editorial');
  $export['editorial_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nodo_editorial';
  $context->description = 'Libro editorial';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'libro_ed' => 'libro_ed',
      ),
      'options' => array(
        'node_form' => '1',
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
      0 => 'main-menu:editorial',
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial');
  t('Libro editorial');
  $export['nodo_editorial'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pagina_editorial';
  $context->description = 'Página Editorial';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'autor_ed' => 'autor_ed',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'editorial' => 'editorial',
        'editorial:page_1' => 'editorial:page_1',
        'editorial:page_3' => 'editorial:page_3',
        'editorial:page_4' => 'editorial:page_4',
        'editorial:page_6' => 'editorial:page_6',
        'editorial:page_catalogo' => 'editorial:page_catalogo',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_editorial-katakrak_editorial_nav_submenu' => array(
          'module' => 'katakrak_editorial',
          'delta' => 'katakrak_editorial_nav_submenu',
          'region' => 'banners',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => array(
      0 => 'main-menu:editorial',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial');
  t('Página Editorial');
  $export['pagina_editorial'] = $context;

  return $export;
}
