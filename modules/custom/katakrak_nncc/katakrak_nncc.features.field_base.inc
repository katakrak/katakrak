<?php

/**
 * @file
 * katakrak_nncc.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function katakrak_nncc_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_ciclo'.
  $field_bases['field_ciclo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_id_type' => NULL,
    'entity_types' => array(),
    'field_name' => 'field_ciclo',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  return $field_bases;
}
