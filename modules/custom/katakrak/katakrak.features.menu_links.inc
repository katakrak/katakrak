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

  // Exported menu link: main-menu_:agenda.
  $menu_links['main-menu_:agenda'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'agenda',
    'router_path' => 'agenda',
    'link_title' => '',
    'options' => array(
      'identifier' => 'main-menu_:agenda',
    ),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
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
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Conócenos');

  return $menu_links;
}
