<?php

/**
 * @file
 * katakrak_itinerarios.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function katakrak_itinerarios_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_itinerario';
  $strongarm->value = 0;
  $export['comment_anonymous_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_itinerario';
  $strongarm->value = 1;
  $export['comment_default_mode_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_itinerario';
  $strongarm->value = '50';
  $export['comment_default_per_page_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_itinerario';
  $strongarm->value = 1;
  $export['comment_form_location_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_itinerario';
  $strongarm->value = '1';
  $export['comment_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_itinerario';
  $strongarm->value = '1';
  $export['comment_preview_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_itinerario';
  $strongarm->value = 1;
  $export['comment_subject_field_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__itinerario';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'language' => array(
          'weight' => '2',
        ),
        'metatags' => array(
          'weight' => '3',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(),
  );
  $export['field_bundle_settings_node__itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_itinerario';
  $strongarm->value = '4';
  $export['i18n_node_extended_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_itinerario';
  $strongarm->value = array();
  $export['i18n_node_options_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_itinerario';
  $strongarm->value = array(
    0 => 'field_itinerario_paradas',
    1 => 'field_itinerario_color',
    2 => 'field_itinerario_linea',
    3 => 'uid',
    4 => 'status',
    5 => 'created',
  );
  $export['i18n_sync_node_type_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_itinerario';
  $strongarm->value = '2';
  $export['language_content_type_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_itinerario';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_itinerario';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_itinerario';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_itinerario';
  $strongarm->value = '1';
  $export['node_preview_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_itinerario';
  $strongarm->value = 0;
  $export['node_submitted_itinerario'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_itinerario_es_pattern';
  $strongarm->value = 'itinerario/[node:title]';
  $export['pathauto_node_itinerario_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_itinerario_eu_pattern';
  $strongarm->value = 'ibilbide/[node:title]';
  $export['pathauto_node_itinerario_eu_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_itinerario_pattern';
  $strongarm->value = '';
  $export['pathauto_node_itinerario_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_itinerario_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_itinerario_und_pattern'] = $strongarm;

  return $export;
}
