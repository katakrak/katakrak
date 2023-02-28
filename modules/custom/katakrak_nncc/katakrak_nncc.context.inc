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
        'ciclos' => 'ciclos',
        'zikloak' => 'zikloak',
      ),
    ),
    'views' => array(
      'values' => array(
        'ciclos' => 'ciclos',
        'ciclos:page_1' => 'ciclos:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_nncc-nncc_page_hero' => array(
          'delta' => 'nncc_page_hero',
          'module' => 'katakrak_nncc',
          'region' => 'hero',
          'weight' => '-10',
        ),
        'katakrak_nncc-nncc_page_highlight' => array(
          'delta' => 'nncc_page_highlight',
          'module' => 'katakrak_nncc',
          'region' => 'content_top',
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

  return $export;
}
