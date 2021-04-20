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
      'options' => array(
        'term_form' => '1',
      ),
      'values' => array(
        'blog_type' => 'blog_type',
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
        'katakrak_blog-katakrak_blog_nav_secundary' => array(
          'delta' => 'katakrak_blog_nav_secundary',
          'module' => 'katakrak_blog',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_blog-katakrak_blog_search' => array(
          'delta' => 'katakrak_blog_search',
          'module' => 'katakrak_blog',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
      'layout' => 'agenda',
    ),
    'menu' => array(
      0 => 'main-menu:blog',
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
      'options' => array(
        'node_form' => '1',
      ),
      'values' => array(
        'blog' => 'blog',
        'boletin' => 'boletin',
      ),
    ),
    'path' => array(
      'values' => array(
        'buscar/blogs*' => 'buscar/blogs*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:blog',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  $export['blog_post'] = $context;

  return $export;
}
