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

  // Exported menu link: menu-menu-nagusia_agenda:agenda.
  $menu_links['menu-menu-nagusia_agenda:agenda'] = array(
    'menu_name' => 'menu-menu-nagusia',
    'link_path' => 'agenda',
    'router_path' => 'agenda',
    'link_title' => 'Agenda',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-menu-nagusia_agenda:agenda',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-menu-nagusia_blog:blog.
  $menu_links['menu-menu-nagusia_blog:blog'] = array(
    'menu_name' => 'menu-menu-nagusia',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-menu-nagusia_blog:blog',
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
  // Exported menu link: menu-menu-nagusia_cantina:cantina.
  $menu_links['menu-menu-nagusia_cantina:cantina'] = array(
    'menu_name' => 'menu-menu-nagusia',
    'link_path' => 'cantina',
    'router_path' => 'cantina',
    'link_title' => 'Cantina',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-menu-nagusia_cantina:cantina',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-menu-nagusia_editorial:editorial.
  $menu_links['menu-menu-nagusia_editorial:editorial'] = array(
    'menu_name' => 'menu-menu-nagusia',
    'link_path' => 'editorial',
    'router_path' => 'editorial',
    'link_title' => 'Editorial',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-menu-nagusia_editorial:editorial',
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
  // Exported menu link: menu-menu-nagusia_tienda-online:tienda.
  $menu_links['menu-menu-nagusia_tienda-online:tienda'] = array(
    'menu_name' => 'menu-menu-nagusia',
    'link_path' => 'tienda',
    'router_path' => 'tienda',
    'link_title' => 'Tienda online',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-menu-nagusia_tienda-online:tienda',
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
  t('Agenda');
  t('Blog');
  t('Cantina');
  t('Editorial');
  t('Tienda online');

  return $menu_links;
}
