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

  // Exported field_base: 'field_disco_productos'.
  $field_bases['field_disco_productos'] = array(
    'active' => 1,
    'cardinality' => 3,
    'deleted' => 0,
    'entity_id_type' => NULL,
    'entity_types' => array(),
    'field_name' => 'field_disco_productos',
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_product_reference',
    'settings' => array(
      'options_list_limit' => '',
    ),
    'translatable' => 0,
    'type' => 'commerce_product_reference',
  );

  return $field_bases;
}
