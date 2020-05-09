<?php

/**
 * @file
 * katakrak_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function katakrak_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function katakrak_blog_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: blog_portada
  $nodequeues['blog_portada'] = array(
    'name' => 'blog_portada',
    'title' => 'Blog portada',
    'subqueue_title' => '',
    'size' => 2,
    'link' => 'Llevar a portada',
    'link_remove' => 'Quitar de portada',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function katakrak_blog_image_default_styles() {
  $styles = array();

  // Exported image style: blog_home.
  $styles['blog_home'] = array(
    'label' => 'Blog home',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: blog_post_page.
  $styles['blog_post_page'] = array(
    'label' => 'Blog post page',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function katakrak_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Bloga'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Izenburua'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
