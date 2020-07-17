<?php

/**
 * @file
 * katakrak_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search';
  $context->description = '';
  $context->tag = 'Tienda online';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'buscar/*' => 'buscar/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
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
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Tienda online');
  $export['search'] = $context;

  return $export;
}
