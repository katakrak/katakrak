<?php

/**
 * @file
 * katakrak_nncc.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function katakrak_nncc_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'commerce_product-curso_centro_de_estudios-field_ciclo'.
  $field_instances['commerce_product-curso_centro_de_estudios-field_ciclo'] = array(
    'bundle' => 'curso_centro_de_estudios',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 1,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_ciclo',
    'label' => 'Ciclo',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 36,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Ciclo');

  return $field_instances;
}
