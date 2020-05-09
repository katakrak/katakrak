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
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'hazte-socio' => 'hazte-socio',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'campana',
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('La página de la campaña de socios');
  $export['campana-socios'] = $context;

  return $export;
}
