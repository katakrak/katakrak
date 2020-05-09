<?php

/**
 * @file
 * katakrak_kantina.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function katakrak_kantina_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create eguneko_menua content'.
  $permissions['create eguneko_menua content'] = array(
    'name' => 'create eguneko_menua content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any eguneko_menua content'.
  $permissions['delete any eguneko_menua content'] = array(
    'name' => 'delete any eguneko_menua content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own eguneko_menua content'.
  $permissions['delete own eguneko_menua content'] = array(
    'name' => 'delete own eguneko_menua content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any eguneko_menua content'.
  $permissions['edit any eguneko_menua content'] = array(
    'name' => 'edit any eguneko_menua content',
    'roles' => array(
      'Sukaldari' => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own eguneko_menua content'.
  $permissions['edit own eguneko_menua content'] = array(
    'name' => 'edit own eguneko_menua content',
    'roles' => array(
      'Sukaldari' => 'Sukaldari',
    ),
    'module' => 'node',
  );

  return $permissions;
}
