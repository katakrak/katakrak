<?php

/**
 * @file
 * katakrak_sukaldea.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function katakrak_sukaldea_user_default_roles() {
  $roles = array();

  // Exported role: Sukaldari.
  $roles['Sukaldari'] = array(
    'name' => 'Sukaldari',
    'weight' => 5,
  );

  return $roles;
}
