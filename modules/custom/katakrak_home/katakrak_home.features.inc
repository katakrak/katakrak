<?php
/**
 * @file
 * katakrak_home.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_home_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function katakrak_home_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: evento_home
  $nodequeues['evento_home'] = array(
    'name' => 'evento_home',
    'title' => 'Evento Home',
    'subqueue_title' => '',
    'size' => 2,
    'link' => 'Llevar a portada',
    'link_remove' => 'Quitar de portada',
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
      0 => 'event',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function katakrak_home_image_default_styles() {
  $styles = array();

  // Exported image style: home_promo.
  $styles['home_promo'] = array(
    'label' => 'Home Promo',
    'effects' => array(
      28 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 390,
          'height' => 390,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
