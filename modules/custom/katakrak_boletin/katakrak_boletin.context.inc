<?php

/**
 * @file
 * katakrak_boletin.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_boletin_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'boletin_node';
  $context->description = 'Boletin node';
  $context->tag = 'Boletin';
  $context->conditions = array(
    'node' => array(
      'options' => array(
        'node_form' => '1',
      ),
      'values' => array(
        'boletin' => 'boletin',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Boletin');
  t('Boletin node');
  $export['boletin_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'boletin_page';
  $context->description = '';
  $context->tag = 'Boletin';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'boletin:page' => 'boletin:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak-newsletter_suscribe' => array(
          'delta' => 'newsletter_suscribe',
          'module' => 'katakrak',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Boletin');
  $export['boletin_page'] = $context;

  return $export;
}
