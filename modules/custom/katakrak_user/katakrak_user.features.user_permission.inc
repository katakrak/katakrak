<?php

/**
 * @file
 * katakrak_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function katakrak_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  return $permissions;
}
