<?php
/**
 * @file
 * katakrak_itinerarios.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_itinerarios_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function katakrak_itinerarios_node_info() {
  $items = array(
    'itinerario' => array(
      'name' => t('Itinerario'),
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
