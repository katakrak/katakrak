<?php

/**
 * @file
 * katakrak_blog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_home';
  $context->description = 'Blog home';
  $context->tag = 'Blog';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'blog_type' => 'blog_type',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'blog:blogs_landing' => 'blog:blogs_landing',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_blog-katakrak_blog_search' => array(
          'module' => 'katakrak_blog',
          'delta' => 'katakrak_blog_search',
          'region' => 'content',
          'weight' => '-9',
        ),
        'katakrak_blog-katakrak_blog_nav_secundary' => array(
          'module' => 'katakrak_blog',
          'delta' => 'katakrak_blog_nav_secundary',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'agenda',
    ),
    'menu' => array(
      0 => 'menu-menu-nagusia:blog',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Blog home');
  $export['blog_home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_post';
  $context->description = '';
  $context->tag = 'Blog';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
        'boletin' => 'boletin',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'menu-menu-nagusia:blog',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  $export['blog_post'] = $context;

  return $export;
}
