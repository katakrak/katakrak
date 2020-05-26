<?php

/**
 * @file
 * katakrak_commerce.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function katakrak_commerce_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'commerce_customer_profile-billing-field_customer_telefono'.
  $field_instances['commerce_customer_profile-billing-field_customer_telefono'] = array(
    'bundle' => 'billing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -9,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'field_customer_telefono',
    'label' => 'Teléfono',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 18,
      ),
      'type' => 'text_textfield',
      'weight' => -9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Teléfono');

  return $field_instances;
}
