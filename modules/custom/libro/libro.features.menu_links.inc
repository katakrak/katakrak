<?php

/**
 * @file
 * libro.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function libro_menu_default_menu_links() {
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
  // Exported menu link: main-menu_blog:blog.
  $menu_links['main-menu_blog:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_blog:blog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_cantina:cantina.
  $menu_links['main-menu_cantina:cantina'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'cantina',
    'router_path' => 'cantina',
    'link_title' => 'Cantina',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_cantina:cantina',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_editorial:editorial.
  $menu_links['main-menu_editorial:editorial'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'editorial',
    'router_path' => 'editorial',
    'link_title' => 'Editorial',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_editorial:editorial',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_tienda-online:tienda.
  $menu_links['main-menu_tienda-online:tienda'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tienda',
    'router_path' => 'tienda',
    'link_title' => 'Tienda online',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_tienda-online:tienda',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Cantina');
  t('Editorial');
  t('Tienda online');

  return $menu_links;
}
