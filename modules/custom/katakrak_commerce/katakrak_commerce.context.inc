<?php

/**
 * @file
 * katakrak_commerce.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_commerce_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'checkout';
  $context->description = 'Checkout context';
  $context->tag = 'Katakrak commerce';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'cart' => 'cart',
        'checkout*' => 'checkout*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_commerce-checkout_breadcrumb' => array(
          'module' => 'katakrak_commerce',
          'delta' => 'checkout_breadcrumb',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'checkout',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Checkout context');
  t('Katakrak commerce');
  $export['checkout'] = $context;

  return $export;
}
