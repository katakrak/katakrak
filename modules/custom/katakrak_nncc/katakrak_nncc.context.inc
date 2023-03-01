<?php

/**
 * @file
 * katakrak_nncc.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_nncc_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ciclos_landing';
  $context->description = '';
  $context->tag = 'Ciclos';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'ciclos' => 'ciclos',
        'zikloak' => 'zikloak',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_nncc-nncc_landing' => array(
          'delta' => 'nncc_landing',
          'module' => 'katakrak_nncc',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'katakrak_nncc-nncc_page_hero' => array(
          'delta' => 'nncc_page_hero',
          'module' => 'katakrak_nncc',
          'region' => 'hero',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ciclos');
  $export['ciclos_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pagina_nncc';
  $context->description = 'Páginas NNCC';
  $context->tag = 'Ciclos';
  $context->conditions = array(
    'node' => array(
      'options' => array(
        'node_form' => '1',
      ),
      'values' => array(
        'ciclo' => 'ciclo',
      ),
    ),
    'path' => array(
      'values' => array(
        'ciclos*' => 'ciclos*',
      ),
    ),
    'views' => array(
      'values' => array(
        'ciclos' => 'ciclos',
        'ciclos:page_1' => 'ciclos:page_1',
        'ciclos:page_cursos' => 'ciclos:page_cursos',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ciclos');
  t('Páginas NNCC');
  $export['pagina_nncc'] = $context;

  return $export;
}
