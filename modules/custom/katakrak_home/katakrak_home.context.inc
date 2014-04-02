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
        'views-libros-book_block_home' => array(
          'module' => 'views',
          'delta' => 'libros-book_block_home',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'layer_slider-1' => array(
          'module' => 'layer_slider',
          'delta' => '1',
          'region' => 'slider',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'katakrak-newsletter_suscribe' => array(
          'module' => 'katakrak',
          'delta' => 'newsletter_suscribe',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_search-katakrak_search_block' => array(
          'module' => 'katakrak_search',
          'delta' => 'katakrak_search_block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'views-blog-block' => array(
          'module' => 'views',
          'delta' => 'blog-block',
          'region' => 'content_bottom',
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
