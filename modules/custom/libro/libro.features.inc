<?php
/**
 * @file
 * libro.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function libro_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function libro_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function libro_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: libros_recomendados
  $nodequeues['libros_recomendados'] = array(
    'name' => 'libros_recomendados',
    'title' => 'Libros recomendados',
    'subqueue_title' => '',
    'size' => 12,
    'link' => 'Añadir a recomendados',
    'link_remove' => 'Quitar de recomendados',
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
      0 => 'libro',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function libro_image_default_styles() {
  $styles = array();

  // Exported image style: app_book_thumbnail.
  $styles['app_book_thumbnail'] = array(
    'label' => 'App book thumbnail',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: book_cover.
  $styles['book_cover'] = array(
    'label' => 'Book cover',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 290,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: book_irakurle_taldea.
  $styles['book_irakurle_taldea'] = array(
    'label' => 'Book irakurle taldea',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: book_medium.
  $styles['book_medium'] = array(
    'label' => 'Book medium (120x)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 120,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: book_thumbnail.
  $styles['book_thumbnail'] = array(
    'label' => 'Book thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 280,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: cover_home.
  $styles['cover_home'] = array(
    'label' => 'Cover home',
    'effects' => array(
      20 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: search_result_cover.
  $styles['search_result_cover'] = array(
    'label' => 'Search result cover',
    'effects' => array(
      27 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: seccion.
  $styles['seccion'] = array(
    'label' => 'seccion',
    'effects' => array(
      22 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 293,
          'height' => 293,
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
  drupal_alter('node_info', $items);
  return $items;
}
