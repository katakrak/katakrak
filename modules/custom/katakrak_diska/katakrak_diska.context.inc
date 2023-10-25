<?php

/**
 * @file
 * libro.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_diska_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node_diska';
  $context->description = '';
  $context->tag = 'Diska';
  $context->conditions = array(
    'node' => array(
      'options' => array(
        'node_form' => '0',
      ),
      'values' => array(
        'disco' => 'disco',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:tienda',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Diska');
  $export['node_diska'] = $context;

  

  return $export;
}
