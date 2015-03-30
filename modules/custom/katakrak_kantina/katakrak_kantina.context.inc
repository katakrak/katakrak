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
  $context->tag = 'Kantina';
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
        'katakrak_kantina-katakrak_kantina_page_header' => array(
          'module' => 'katakrak_kantina',
          'delta' => 'katakrak_kantina_page_header',
          'region' => 'content_top',
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
  $export['kantina'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'menu-dia';
  $context->description = '';
  $context->tag = 'Kantina';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'eguneko_menua' => 'eguneko_menua',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'cantina/denoche' => 'cantina/denoche',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_kantina-katakrak_kantina_page_header' => array(
          'module' => 'katakrak_kantina',
          'delta' => 'katakrak_kantina_page_header',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'kantina',
    ),
    'menu' => array(
      0 => 'main-menu:cantina',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kantina');
  $export['menu-dia'] = $context;

  return $export;
}
