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
    'weight' => '3',
  );

  return $roles;
}
