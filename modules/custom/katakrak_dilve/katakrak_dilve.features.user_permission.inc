<?php
/**
 * @file
 * katakrak_dilve.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function katakrak_dilve_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access dilve information'.
  $permissions['access dilve information'] = array(
    'name' => 'access dilve information',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'katakrak_dilve',
  );

  return $permissions;
}
