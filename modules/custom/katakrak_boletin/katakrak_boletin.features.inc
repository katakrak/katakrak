<?php
/**
 * @file
 * katakrak_boletin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_boletin_ctools_plugin_api($module = NULL, $api = NULL) {
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
function katakrak_boletin_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function katakrak_boletin_image_default_styles() {
  $styles = array();

  // Exported image style: boletin_destacado.
  $styles['boletin_destacado'] = array(
    'label' => 'boletin_destacado',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 580,
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
function katakrak_boletin_node_info() {
  $items = array(
    'boletin' => array(
      'name' => t('Boletin'),
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
