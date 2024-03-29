<?php

/**
 * @file
 * katakrak_diska.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function katakrak_diska_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cabecera'.
  $field_bases['field_cabecera'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_id_type' => NULL,
    'entity_types' => array(),
    'field_name' => 'field_cabecera',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
