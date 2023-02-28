<?php

/**
 * @file
 * katakrak_nncc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_nncc_ctools_plugin_api($module = NULL, $api = NULL) {
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
function katakrak_nncc_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function katakrak_nncc_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: ciclos_cas
  $nodequeues['ciclos_cas'] = array(
    'name' => 'ciclos_cas',
    'title' => 'Ciclos cas',
    'subqueue_title' => '',
    'size' => 0,
    'link' => 'Quitar de ciclos cas',
    'link_remove' => 'Añadir a ciclos cas',
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
    'types' => array(
      0 => 'ciclo',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function katakrak_nncc_image_default_styles() {
  $styles = array();

  // Exported image style: square_thumbnail.
  $styles['square_thumbnail'] = array(
    'label' => 'square_thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'weight' => 0,
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function katakrak_nncc_node_info() {
  $items = array(
    'ciclo' => array(
      'name' => t('Ciclo'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titulo'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
