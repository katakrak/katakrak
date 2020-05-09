<?php

/**
 * @file
 * katakrak.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function katakrak_user_default_roles() {
  $roles = array();

  // Exported role: Cliente.
  $roles['Cliente'] = array(
    'name' => 'Cliente',
    'weight' => 3,
  );

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 4,
  );

  // Exported role: Librero.
  $roles['Librero'] = array(
    'name' => 'Librero',
    'weight' => 6,
  );

  return $roles;
}
