<?php
/**
 * @file
 * katakrak_kantina.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_kantina_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kantina';
  $context->description = 'Kantina';
  $context->tag = 'kantina';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'kantina' => 'kantina',
        'cantina' => 'cantina',
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
        'views-kantina-block_page' => array(
          'module' => 'views',
          'delta' => 'kantina-block_page',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
      'layout' => 'kantina',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kantina');
  t('kantina');
  $export['kantina'] = $context;

  return $export;
}
