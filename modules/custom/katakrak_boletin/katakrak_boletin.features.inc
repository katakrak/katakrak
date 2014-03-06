<?php
/**
 * @file
 * katakrak_boletin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_boletin_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function katakrak_boletin_image_default_styles() {
  $styles = array();

  // Exported image style: boletin_destacado.
  $styles['boletin_destacado'] = array(
    'name' => 'boletin_destacado',
    'label' => 'boletin_destacado',
    'effects' => array(
      10 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
