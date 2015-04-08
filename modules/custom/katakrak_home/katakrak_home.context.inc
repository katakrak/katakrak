<?php
/**
 * @file
 * katakrak_home.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_home_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Home context';
  $context->tag = 'Home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_home-katakrak_home_promo_right' => array(
          'module' => 'katakrak_home',
          'delta' => 'katakrak_home_promo_right',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'boxes-twitter_feed' => array(
          'module' => 'boxes',
          'delta' => 'twitter_feed',
          'region' => 'bottom_two',
          'weight' => '-9',
        ),
        'katakrak_home-katakrak_home_promo_bottom' => array(
          'module' => 'katakrak_home',
          'delta' => 'katakrak_home_promo_bottom',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
      'layout' => 'home',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  t('Home context');
  $export['home'] = $context;

  return $export;
}
