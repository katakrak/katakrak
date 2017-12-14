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
  $context->name = 'nodo_editorial';
  $context->description = 'Nodos editorial';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'autor_ed' => 'autor_ed',
        'libro_ed' => 'libro_ed',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'book',
    ),
    'menu' => array(
      0 => 'main-menu:editorial',
      1 => 'main-menu:editorial',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial');
  t('Nodos editorial');
  $export['nodo_editorial'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pagina_editorial';
  $context->description = 'Página Editorial CAS';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'language' => array(
      'values' => array(
        'es' => 'es',
      ),
    ),
    'views' => array(
      'values' => array(
        'editorial:page' => 'editorial:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-editorial-block_2' => array(
          'module' => 'views',
          'delta' => 'editorial-block_2',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'book',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial');
  t('Página Editorial CAS');
  $export['pagina_editorial'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pagina_editorial_eus';
  $context->description = 'Página Editorial EUS';
  $context->tag = 'Editorial';
  $context->conditions = array(
    'language' => array(
      'values' => array(
        'eu' => 'eu',
      ),
    ),
    'views' => array(
      'values' => array(
        'editorial:page' => 'editorial:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-editorial-block_1' => array(
          'module' => 'views',
          'delta' => 'editorial-block_1',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'book',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editorial');
  t('Página Editorial EUS');
  $export['pagina_editorial_eus'] = $context;

  return $export;
}
