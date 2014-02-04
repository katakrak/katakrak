<?php
/**
 * @file
 * katakrak_home.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_home_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function katakrak_home_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function katakrak_home_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: evento_portada
  $nodequeues['evento_portada'] = array(
    'name' => 'evento_portada',
    'title' => 'Evento_portada',
    'subqueue_title' => '',
    'size' => '1',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'event',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: libro_portada
  $nodequeues['libro_portada'] = array(
    'name' => 'libro_portada',
    'title' => 'Libro portada',
    'subqueue_title' => '',
    'size' => '1',
    'link' => 'Llevar a portada',
    'link_remove' => 'Eliminar de la portada',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '1',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'libro',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
