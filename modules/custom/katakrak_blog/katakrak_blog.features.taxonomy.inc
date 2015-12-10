<?php
/**
 * @file
 * katakrak_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function katakrak_blog_taxonomy_default_vocabularies() {
  return array(
    'blog_type' => array(
      'name' => 'Blogs',
      'machine_name' => 'blog_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
  );
}
