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
        'katakrak_commerce-katakrak_commerce_cart' => array(
          'module' => 'katakrak_commerce',
          'delta' => 'katakrak_commerce_cart',
          'region' => 'header_right',
          'weight' => '-10',
        ),
        'katakrak-footer_first' => array(
          'module' => 'katakrak',
          'delta' => 'footer_first',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'katakrak-footer_second' => array(
          'module' => 'katakrak',
          'delta' => 'footer_second',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
        'katakrak-footer_third' => array(
          'module' => 'katakrak',
          'delta' => 'footer_third',
          'region' => 'footer_third',
          'weight' => '-10',
        ),
        'mailchimp_signup-recibe_nuestro_boletin_semanal' => array(
          'module' => 'mailchimp_signup',
          'delta' => 'recibe_nuestro_boletin_semanal',
          'region' => 'footer_fourth',
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
