<?php

/**
 * @file
 * katakrak_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function katakrak_user_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: biblioteca.
  $roles['biblioteca'] = array(
    'name' => 'Biblioteca',
    'weight' => 7,
  );

  return $roles;
}
