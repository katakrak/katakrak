<?php
/**
 * @file
 * katakrak_agenda.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function katakrak_agenda_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ciclo content'.
  $permissions['create ciclo content'] = array(
    'name' => 'create ciclo content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ciclo content'.
  $permissions['delete any ciclo content'] = array(
    'name' => 'delete any ciclo content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ciclo content'.
  $permissions['delete own ciclo content'] = array(
    'name' => 'delete own ciclo content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ciclo content'.
  $permissions['edit any ciclo content'] = array(
    'name' => 'edit any ciclo content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ciclo content'.
  $permissions['edit own ciclo content'] = array(
    'name' => 'edit own ciclo content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
