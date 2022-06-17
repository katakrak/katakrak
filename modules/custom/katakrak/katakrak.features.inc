<?php

/**
 * @file
 * katakrak.features.inc
 */

/**
 * Implements hook_default_commerce_discount().
 */
function katakrak_default_commerce_discount() {
  $items = array();
  $items['discount_descuento_biblioteca'] = entity_import('commerce_discount', '{
    "name" : "discount_descuento_biblioteca",
    "label" : "Descuento biblioteca",
    "type" : "product_discount",
    "status" : "0",
    "component_title" : "Descuento bibliotecas",
    "sort_order" : "10",
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "10.00" } ] }
    },
    "commerce_compatibility_strategy" : { "und" : [ { "value" : "any" } ] },
    "commerce_compatibility_selection" : [],
    "commerce_discount_date" : [],
    "inline_conditions" : [],
    "discount_usage_per_person" : [],
    "discount_usage_limit" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_views_api().
 */
function katakrak_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function katakrak_image_default_styles() {
  $styles = array();

  // Exported image style: extra_large.
  $styles['extra_large'] = array(
    'label' => 'Extra large',
    'effects' => array(
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => '',
          'upscale' => 0,
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
function katakrak_node_info() {
  $items = array(
    'imagen' => array(
      'name' => t('Imagen'),
      'base' => 'node_content',
      'description' => t('Proporciona imágenes para galerias'),
      'has_title' => '1',
      'title_label' => t('Titulo'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
