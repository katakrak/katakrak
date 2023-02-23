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
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ciclos');
  $export['ciclos_landing'] = $context;

  return $export;
}
