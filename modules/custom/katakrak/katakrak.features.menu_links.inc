<?php

/**
 * @file
 * katakrak.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function katakrak_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_concenos:conocenos.
  $menu_links['main-menu_concenos:conocenos'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'conocenos',
    'router_path' => 'conocenos',
    'link_title' => 'Conócenos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_concenos:conocenos',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Conócenos');

  return $menu_links;
}
