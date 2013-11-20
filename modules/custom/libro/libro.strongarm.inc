<?php
/**
 * @file
 * libro.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function libro_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__libro';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'search_index' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'product:sku' => array(
          'default' => array(
            'weight' => '-10',
            'visible' => FALSE,
          ),
          'search_index' => array(
            'weight' => '-10',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '-10',
            'visible' => FALSE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'search_index' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
        ),
        'product:status' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'search_index' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_price' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'product:commerce_product_tariff_weight' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'product:commerce_product_tariff_service' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'product:commerce_stock' => array(
          'default' => array(
            'weight' => '37',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '37',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '37',
            'visible' => TRUE,
          ),
        ),
        'product:field_product_peso' => array(
          'default' => array(
            'weight' => '36',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '36',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '36',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__libro'] = $strongarm;

  return $export;
}
