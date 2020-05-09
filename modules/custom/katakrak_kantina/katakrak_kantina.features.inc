<?php

/**
 * @file
 * katakrak_kantina.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_kantina_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
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
    'i18n' => NULL,
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function katakrak_kantina_image_default_styles() {
  $styles = array();

  // Exported image style: kantina_large.
  $styles['kantina_large'] = array(
    'label' => 'Kantina large',
    'effects' => array(
      23 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 667,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: kantina_medium.
  $styles['kantina_medium'] = array(
    'label' => 'Kantina medium',
    'effects' => array(
      24 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 472,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: kantina_thumbnail.
  $styles['kantina_thumbnail'] = array(
    'label' => 'Kantina thumbnail',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: receta_page.
  $styles['receta_page'] = array(
    'label' => 'Receta page',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
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
function katakrak_kantina_node_info() {
  $items = array(
    'eguneko_menua' => array(
      'name' => t('Eguneko menua'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
    'receta' => array(
      'name' => t('Receta'),
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
