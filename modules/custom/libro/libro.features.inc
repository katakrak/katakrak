<?php
/**
 * @file
 * libro.features.inc
 */

/**
 * Implements hook_views_api().
 */
function libro_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function libro_node_info() {
  $items = array(
    'libro' => array(
      'name' => t('Libro'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
