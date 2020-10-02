<?php

/**
 * @file
 * katakrak.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function katakrak_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-enlaces.
  $menus['menu-enlaces'] = array(
    'menu_name' => 'menu-enlaces',
    'title' => 'Enlaces',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-menu-nagusia.
  $menus['menu-menu-nagusia'] = array(
    'menu_name' => 'menu-menu-nagusia',
    'title' => 'Menu nagusia',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Enlaces');
  t('Menu nagusia');

  return $menus;
}
