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
function katakrak_editorial_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function katakrak_editorial_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: autore_editorial_eus
  $nodequeues['autore_editorial_eus'] = array(
    'name' => 'autore_editorial_eus',
    'title' => 'Autores editorial EUS',
    'subqueue_title' => '',
    'size' => 6,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 1,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'autor_ed',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: autores_editorial
  $nodequeues['autores_editorial'] = array(
    'name' => 'autores_editorial',
    'title' => 'Autores editorial CAS',
    'subqueue_title' => '',
    'size' => 6,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 1,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'autor_ed',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: libros_editorial
  $nodequeues['libros_editorial'] = array(
    'name' => 'libros_editorial',
    'title' => 'Editorial portada',
    'subqueue_title' => '',
    'size' => 4,
    'link' => 'Añadir a portada ',
    'link_remove' => 'Quitar de portada',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 1,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'libro_ed',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: traductores_cas
  $nodequeues['traductores_cas'] = array(
    'name' => 'traductores_cas',
    'title' => 'Traductores CAS',
    'subqueue_title' => '',
    'size' => 6,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 1,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'autor_ed',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: traductores_eus
  $nodequeues['traductores_eus'] = array(
    'name' => 'traductores_eus',
    'title' => 'Traductores EUS',
    'subqueue_title' => '',
    'size' => 6,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 1,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'autor_ed',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function katakrak_editorial_image_default_styles() {
  $styles = array();

  // Exported image style: autor_editorial_ficha_libro.
  $styles['autor_editorial_ficha_libro'] = array(
    'label' => 'Autor editorial ficha libro',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 450,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: editorial_ficha.
  $styles['editorial_ficha'] = array(
    'label' => 'Editorial ficha (390px)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 390,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: editorial_page.
  $styles['editorial_page'] = array(
    'label' => 'editorial_page',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 209,
          'height' => 320,
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
      'title_label' => t('Izenburua'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
