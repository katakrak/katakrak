<?php
/**
 * @file
 * katakrak.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'Sitewide context';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak-language' => array(
          'module' => 'katakrak',
          'delta' => 'language',
          'region' => 'top_left',
          'weight' => '-10',
        ),
        'boxes-social_widget' => array(
          'module' => 'boxes',
          'delta' => 'social_widget',
          'region' => 'top_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  t('Sitewide context');
  $export['sitewide'] = $context;

  return $export;
}
