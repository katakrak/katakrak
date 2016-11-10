<?php
/**
 * @file
 * katakrak_editorial.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_editorial_ctools_plugin_api($module = NULL, $api = NULL) {
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
function katakrak_editorial_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function katakrak_editorial_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: libros_editorial
  $nodequeues['libros_editorial'] = array(
    'name' => 'libros_editorial',
    'title' => 'Libros editorial',
    'subqueue_title' => '',
    'size' => 3,
    'link' => 'Añadir a página de editorial',
    'link_remove' => 'Quitar de página de editorial',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'libro_ed',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function katakrak_editorial_node_info() {
  $items = array(
    'autor_ed' => array(
      'name' => t('Autor editorial'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nombre'),
      'help' => '',
    ),
    'libro_ed' => array(
      'name' => t('Libro Editorial'),
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
