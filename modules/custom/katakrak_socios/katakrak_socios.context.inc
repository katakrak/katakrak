<?php

/**
 * @file
 * katakrak_socios.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_socios_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'campana-socios';
  $context->description = 'La página de la campaña de socios';
  $context->tag = 'katakrak socios';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'hazte-socio' => 'hazte-socio',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-coming_soon' => array(
          'module' => 'boxes',
          'delta' => 'coming_soon',
          'region' => 'content',
          'weight' => '-10',
        ),
        'boxes-como_hacer_crack' => array(
          'module' => 'boxes',
          'delta' => 'como_hacer_crack',
          'region' => 'content_campana_right',
          'weight' => '-10',
        ),
      ),
      'layout' => 'campana',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('La página de la campaña de socios');
  t('katakrak socios');
  $export['campana-socios'] = $context;

  return $export;
}
