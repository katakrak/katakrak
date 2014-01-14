<?php
/**
 * @file
 * katakrak_sukaldea.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function katakrak_sukaldea_user_default_permissions() {
  $permissions = array();

  // Exported permission: create sukalde_errezeta content.
  $permissions['create sukalde_errezeta content'] = array(
    'name' => 'create sukalde_errezeta content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: create sukalde_produktua content.
  $permissions['create sukalde_produktua content'] = array(
    'name' => 'create sukalde_produktua content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any sukalde_errezeta content.
  $permissions['delete any sukalde_errezeta content'] = array(
    'name' => 'delete any sukalde_errezeta content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any sukalde_produktua content.
  $permissions['delete any sukalde_produktua content'] = array(
    'name' => 'delete any sukalde_produktua content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own sukalde_errezeta content.
  $permissions['delete own sukalde_errezeta content'] = array(
    'name' => 'delete own sukalde_errezeta content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own sukalde_produktua content.
  $permissions['delete own sukalde_produktua content'] = array(
    'name' => 'delete own sukalde_produktua content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any sukalde_errezeta content.
  $permissions['edit any sukalde_errezeta content'] = array(
    'name' => 'edit any sukalde_errezeta content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any sukalde_produktua content.
  $permissions['edit any sukalde_produktua content'] = array(
    'name' => 'edit any sukalde_produktua content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own sukalde_errezeta content.
  $permissions['edit own sukalde_errezeta content'] = array(
    'name' => 'edit own sukalde_errezeta content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own sukalde_produktua content.
  $permissions['edit own sukalde_produktua content'] = array(
    'name' => 'edit own sukalde_produktua content',
    'roles' => array(
      0 => 'Sukaldari',
    ),
    'module' => 'node',
  );

  return $permissions;
}
