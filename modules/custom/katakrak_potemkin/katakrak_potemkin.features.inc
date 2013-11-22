<?php
/**
 * @file
 * katakrak_potemkin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_potemkin_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function katakrak_potemkin_node_info() {
  $items = array(
    'dvd' => array(
      'name' => t('DVD'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
