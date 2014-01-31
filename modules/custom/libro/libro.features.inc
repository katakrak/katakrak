<?php
/**
 * @file
 * libro.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function libro_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function libro_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function libro_image_default_styles() {
  $styles = array();

  // Exported image style: book_cover.
  $styles['book_cover'] = array(
    'name' => 'book_cover',
    'label' => 'Book cover',
    'effects' => array(
      1 => array(
        'label' => 'Escala',
        'help' => 'El escalado mantiene la relación de proporciones de la imagen original. Si sólo se especifica una dimensión, la otra se calculará.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '290',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: cover_home.
  $styles['cover_home'] = array(
    'name' => 'cover_home',
    'label' => 'Cover home',
    'effects' => array(
      1 => array(
        'label' => 'Escala',
        'help' => 'El escalado mantiene la relación de proporciones de la imagen original. Si sólo se especifica una dimensión, la otra se calculará.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '300',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
      2 => array(
        'label' => 'Recortar',
        'help' => 'El recorte eliminará partes de una imagen para que tenga las dimensiones especificadas.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => '300',
          'height' => '400',
          'anchor' => 'center-center',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: search_result_cover.
  $styles['search_result_cover'] = array(
    'name' => 'search_result_cover',
    'label' => 'Search result cover',
    'effects' => array(
      4 => array(
        'label' => 'Escala',
        'help' => 'El escalado mantiene la relación de proporciones de la imagen original. Si sólo se especifica una dimensión, la otra se calculará.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '150',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '-10',
      ),
      3 => array(
        'label' => 'Recortar',
        'help' => 'El recorte eliminará partes de una imagen para que tenga las dimensiones especificadas.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => '150',
          'height' => '100',
          'anchor' => 'center-center',
        ),
        'weight' => '-9',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function libro_node_info() {
  $items = array(
    'libro' => array(
      'name' => t('Libro'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
