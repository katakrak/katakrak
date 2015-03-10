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
    'size' => 8,
    'link' => 'Añadir a página kantina',
    'link_remove' => 'Quitar de  página kantina',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
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

/**
 * Implements hook_node_info().
 */
function katakrak_kantina_node_info() {
  $items = array(
    'eguneko_menua' => array(
      'name' => t('Eguneko menua'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'sukalde_kontuak' => array(
      'name' => t('Sukalde kontuak'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
