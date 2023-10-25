<?php

/**
 * @file
 * katakrak_diska.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_diska_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function katakrak_diska_node_info() {
  $items = array(
    'disco' => array(
      'name' => t('Disco'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
