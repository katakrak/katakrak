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
  $context->name = 'blog';
  $context->description = 'Blog';
  $context->tag = 'Blog';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'taxonomy_term' => array(
      'values' => array(
        'blog_type' => 'blog_type',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'blog',
    ),
    'menu' => array(
      0 => 'main-menu:blogs',
    ),
    'theme' => array(
      'title' => 'Blog',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  $export['blog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_page';
  $context->description = 'Blog page';
  $context->tag = 'blog';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'blog:page' => 'blog:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'blog',
    ),
    'theme' => array(
      'title' => 'Blog',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog page');
  t('blog');
  $export['blog_page'] = $context;

  return $export;
}
