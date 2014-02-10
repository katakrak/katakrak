<?php
/**
 * @file
 * katakrak_kantina.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_kantina_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function katakrak_kantina_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function katakrak_kantina_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: producto_kafeta_destacado
  $nodequeues['producto_kafeta_destacado'] = array(
    'name' => 'producto_kafeta_destacado',
    'title' => 'Producto kafeta destacado',
    'subqueue_title' => '',
    'size' => 4,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'portfolio',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
