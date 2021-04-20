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
  $context->name = 'landing_conocenos';
  $context->description = 'Landing for conocenos';
  $context->tag = 'landing';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'conocenos' => 'conocenos',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak-katakrak_conocenos_baldosas' => array(
          'delta' => 'katakrak_conocenos_baldosas',
          'module' => 'katakrak',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak-katakrak_conocenos_destacado' => array(
          'delta' => 'katakrak_conocenos_destacado',
          'module' => 'katakrak',
          'region' => 'banners',
          'weight' => '-10',
        ),
        'katakrak-katakrak_conocenos_visita' => array(
          'delta' => 'katakrak_conocenos_visita',
          'module' => 'katakrak',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
      'layout' => 'landing',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing for conocenos');
  t('landing');
  $export['landing_conocenos'] = $context;

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
        'katakrak-footer_first' => array(
          'delta' => 'footer_first',
          'module' => 'katakrak',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'katakrak-footer_second' => array(
          'delta' => 'footer_second',
          'module' => 'katakrak',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
        'katakrak_commerce-katakrak_commerce_cart' => array(
          'delta' => 'katakrak_commerce_cart',
          'module' => 'katakrak_commerce',
          'region' => 'header_right',
          'weight' => '-10',
        ),
        'mailchimp_signup-recibe_nuestro_boletin_semanal' => array(
          'delta' => 'recibe_nuestro_boletin_semanal',
          'module' => 'mailchimp_signup',
          'region' => 'footer_third',
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
