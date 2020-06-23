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
  $strongarm->name = 'comment_anonymous_libro';
  $strongarm->value = 0;
  $export['comment_anonymous_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_libro';
  $strongarm->value = 1;
  $export['comment_default_mode_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_libro';
  $strongarm->value = '50';
  $export['comment_default_per_page_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_libro';
  $strongarm->value = 1;
  $export['comment_form_location_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_libro';
  $strongarm->value = '2';
  $export['comment_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_libro';
  $strongarm->value = '1';
  $export['comment_preview_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_libro';
  $strongarm->value = 1;
  $export['comment_subject_field_libro'] = $strongarm;

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
      'home_event' => array(
        'custom_settings' => TRUE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'language' => array(
          'weight' => '1',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '12',
        ),
        'metatags' => array(
          'weight' => '12',
        ),
      ),
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
          'teaser' => array(
            'weight' => '-10',
            'visible' => FALSE,
          ),
          'card_book' => array(
            'weight' => '-10',
            'visible' => TRUE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'search_index' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'card_book' => array(
            'weight' => '-5',
            'visible' => TRUE,
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
          'teaser' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'card_book' => array(
            'weight' => '5',
            'visible' => TRUE,
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
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'card_book' => array(
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
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'card_book' => array(
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
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'card_book' => array(
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
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '37',
            'visible' => TRUE,
          ),
          'card_book' => array(
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
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '36',
            'visible' => TRUE,
          ),
          'card_book' => array(
            'weight' => '36',
            'visible' => TRUE,
          ),
        ),
        'language' => array(
          'search_index' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'card_book' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'product:field_peso_medio' => array(
          'search_index' => array(
            'weight' => '38',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '38',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '38',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '38',
            'visible' => TRUE,
          ),
          'card_book' => array(
            'weight' => '38',
            'visible' => TRUE,
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'card_book' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_libro';
  $strongarm->value = 1;
  $export['i18n_node_extended_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_libro';
  $strongarm->value = array();
  $export['i18n_node_options_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_libro';
  $strongarm->value = array();
  $export['i18n_sync_node_type_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_libro';
  $strongarm->value = '1';
  $export['language_content_type_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_libro';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_libro';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_libro';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_libro';
  $strongarm->value = '1';
  $export['node_preview_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_libro';
  $strongarm->value = 1;
  $export['node_submitted_libro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_libro_es_pattern';
  $strongarm->value = 'lib/[node:title]';
  $export['pathauto_node_libro_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_libro_eu_pattern';
  $strongarm->value = 'lib/[node:title]';
  $export['pathauto_node_libro_eu_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_libro_pattern';
  $strongarm->value = 'lib/[node:title]';
  $export['pathauto_node_libro_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_libro_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_libro_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_autores_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_autores_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_editoriales_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_editoriales_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_materias_pattern';
  $strongarm->value = 'libros/seccion/[term:name]';
  $export['pathauto_taxonomy_term_materias_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_urtea_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_urtea_pattern'] = $strongarm;

  return $export;
}
