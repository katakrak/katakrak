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
        'katakrak-language_switcher' => array(
          'module' => 'katakrak',
          'delta' => 'language_switcher',
          'region' => 'header_right',
          'weight' => '-10',
        ),
        'katakrak-katakrak_user_top' => array(
          'module' => 'katakrak',
          'delta' => 'katakrak_user_top',
          'region' => 'header_right',
          'weight' => '-8',
        ),
        'katakrak-katakrak_cart' => array(
          'module' => 'katakrak',
          'delta' => 'katakrak_cart',
          'region' => 'header_right',
          'weight' => '-7',
        ),
        'katakrak-katakrak_social' => array(
          'module' => 'katakrak',
          'delta' => 'katakrak_social',
          'region' => 'post_content_bottom_right',
          'weight' => '-9',
        ),
        'boxes-footer' => array(
          'module' => 'boxes',
          'delta' => 'footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'boxes-about_us' => array(
          'module' => 'boxes',
          'delta' => 'about_us',
          'region' => 'footer_first',
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
