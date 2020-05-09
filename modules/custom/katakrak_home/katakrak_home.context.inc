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
        'views-editorial-block_4' => array(
          'module' => 'views',
          'delta' => 'editorial-block_4',
          'region' => 'content',
          'weight' => '-10',
        ),
        'katakrak_home-katakrak_home_promo' => array(
          'module' => 'katakrak_home',
          'delta' => 'katakrak_home_promo',
          'region' => 'content',
          'weight' => '-9',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-8',
        ),
        'mailchimp_signup-recibe_nuestro_boletin_semanal' => array(
          'module' => 'mailchimp_signup',
          'delta' => 'recibe_nuestro_boletin_semanal',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
        'views-blog-block' => array(
          'module' => 'views',
          'delta' => 'blog-block',
          'region' => 'content_bottom_third',
          'weight' => '-9',
        ),
        'views-libros-book_block_home' => array(
          'module' => 'views',
          'delta' => 'libros-book_block_home',
          'region' => 'content_bottom_fourth',
          'weight' => '-10',
        ),
        'views-itinerarios-block' => array(
          'module' => 'views',
          'delta' => 'itinerarios-block',
          'region' => 'content_bottom_fourth',
          'weight' => '-9',
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
