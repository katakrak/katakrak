<?php
/**
 * @file
 * katakrak_sukaldea.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_sukaldea_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function katakrak_sukaldea_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function katakrak_sukaldea_node_info() {
  $items = array(
    'sukalde_errezeta' => array(
      'name' => t('Sukalde Errezeta'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'sukalde_produktua' => array(
      'name' => t('Sukalde Produktua'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Izena'),
      'help' => '',
    ),
  );
  return $items;
}
