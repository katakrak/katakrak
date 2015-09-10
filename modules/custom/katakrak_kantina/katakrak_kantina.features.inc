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
 * Implements hook_image_default_styles().
 */
function katakrak_kantina_image_default_styles() {
  $styles = array();

  // Exported image style: kantina_full.
  $styles['kantina_full'] = array(
    'name' => 'kantina_full',
    'label' => 'Kantina full',
    'effects' => array(
      3 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 950,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: kantina_medium.
  $styles['kantina_medium'] = array(
    'name' => 'kantina_medium',
    'label' => 'Kantina medium',
    'effects' => array(
      7 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 457,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: kantina_thumbnail.
  $styles['kantina_thumbnail'] = array(
    'name' => 'kantina_thumbnail',
    'label' => 'Kantina thumbnail',
    'effects' => array(
      4 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'receta_page',
    'label' => 'Receta page',
    'effects' => array(
      8 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
