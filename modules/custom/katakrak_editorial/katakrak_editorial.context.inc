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
        'editorial:autores' => 'editorial:autores',
        'editorial:traductores' => 'editorial:traductores',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_editorial-editorial_autores_nav_secunday' => array(
          'delta' => 'editorial_autores_nav_secunday',
          'module' => 'katakrak_editorial',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_editorial-editorial_filter_autores' => array(
          'delta' => 'editorial_filter_autores',
          'module' => 'katakrak_editorial',
          'region' => 'content',
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
  $context->name = 'editorial_catalogo';
  $context->description = 'Página catálogo de la editorial castellano';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'language' => array(
      'values' => array(
        'es' => 'es',
      ),
    ),
    'views' => array(
      'values' => array(
        'editorial:page_catalogo' => 'editorial:page_catalogo',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-44383dfbcb8fff91d365de447606bb07' => array(
          'delta' => '44383dfbcb8fff91d365de447606bb07',
          'module' => 'views',
          'region' => 'content_top',
          'weight' => '-85',
        ),
        'views-d1750993613d6d2886e60049a5ecf5f1' => array(
          'delta' => 'd1750993613d6d2886e60049a5ecf5f1',
          'module' => 'views',
          'region' => 'content_top',
          'weight' => '-84',
        ),
        'views-editorial-editorial_blitz' => array(
          'delta' => 'editorial-editorial_blitz',
          'module' => 'views',
          'region' => 'content_top',
          'weight' => '-86',
        ),
        'views-editorial-editorial_ensayo' => array(
          'delta' => 'editorial-editorial_ensayo',
          'module' => 'views',
          'region' => 'content_top',
          'weight' => '-87',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial');
  t('Página catálogo de la editorial castellano');
  $export['editorial_catalogo'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'editorial_catalogo_euskera';
  $context->description = 'Página catálogo de la editorial euskera';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'language' => array(
      'values' => array(
        'eu' => 'eu',
      ),
    ),
    'views' => array(
      'values' => array(
        'editorial:page_catalogo' => 'editorial:page_catalogo',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-44383dfbcb8fff91d365de447606bb07' => array(
          'delta' => '44383dfbcb8fff91d365de447606bb07',
          'module' => 'views',
          'region' => 'content_top',
          'weight' => '-88',
        ),
        'views-d1750993613d6d2886e60049a5ecf5f1' => array(
          'delta' => 'd1750993613d6d2886e60049a5ecf5f1',
          'module' => 'views',
          'region' => 'content_top',
          'weight' => '-87',
        ),
        'views-editorial-editorial_blitz' => array(
          'delta' => 'editorial-editorial_blitz',
          'module' => 'views',
          'region' => 'content_top',
          'weight' => '-85',
        ),
        'views-editorial-editorial_ensayo' => array(
          'delta' => 'editorial-editorial_ensayo',
          'module' => 'views',
          'region' => 'content_top',
          'weight' => '-86',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial');
  t('Página catálogo de la editorial euskera');
  $export['editorial_catalogo_euskera'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'editorial_landing';
  $context->description = 'Landing editorial';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'argitaletxea' => 'argitaletxea',
        'editorial' => 'editorial',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_editorial-editorial_page_hero' => array(
          'delta' => 'editorial_page_hero',
          'module' => 'katakrak_editorial',
          'region' => 'hero',
          'weight' => '-10',
        ),
        'katakrak_editorial-editorial_page_highlight' => array(
          'delta' => 'editorial_page_highlight',
          'module' => 'katakrak_editorial',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_editorial-katakrak_editorial_landing' => array(
          'delta' => 'katakrak_editorial_landing',
          'module' => 'katakrak_editorial',
          'region' => 'content_bottom',
          'weight' => '-10',
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
      'options' => array(
        'node_form' => '1',
      ),
      'values' => array(
        'libro_ed' => 'libro_ed',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'libro-libreria_home_search' => array(
          'delta' => 'libreria_home_search',
          'module' => 'libro',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => array(
      0 => 'menu-menu-nagusia:editorial',
    ),
    'theme' => array(
      'subtitle' => '',
      'title' => '',
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
      'options' => array(
        'node_form' => '1',
      ),
      'values' => array(
        'autor_ed' => 'autor_ed',
      ),
    ),
    'path' => array(
      'values' => array(
        'argitaletxea*' => 'argitaletxea*',
        'editorial*' => 'editorial*',
      ),
    ),
    'views' => array(
      'values' => array(
        'editorial' => 'editorial',
        'editorial:page_1' => 'editorial:page_1',
        'editorial:page_catalogo' => 'editorial:page_catalogo',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_editorial-katakrak_editorial_nav_submenu' => array(
          'delta' => 'katakrak_editorial_nav_submenu',
          'module' => 'katakrak_editorial',
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
