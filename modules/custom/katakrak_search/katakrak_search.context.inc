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
        'buscar/libros/*' => 'buscar/libros/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'libro-libreria_home_bizikrak' => array(
          'delta' => 'libreria_home_bizikrak',
          'module' => 'libro',
          'region' => 'banners',
          'weight' => '-9',
        ),
      ),
    ),
    'menu' => array(
      0 => 'main-menu:tienda',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Tienda online');
  $export['search'] = $context;

  return $export;
}
