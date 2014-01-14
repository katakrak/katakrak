<?php
/**
 * @file
 * katakrak_sukaldea.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function katakrak_sukaldea_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_sukalde_errezeta';
  $strongarm->value = 0;
  $export['comment_anonymous_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_sukalde_produktua';
  $strongarm->value = 0;
  $export['comment_anonymous_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_sukalde_errezeta';
  $strongarm->value = 0;
  $export['comment_default_mode_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_sukalde_produktua';
  $strongarm->value = 1;
  $export['comment_default_mode_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_sukalde_errezeta';
  $strongarm->value = '50';
  $export['comment_default_per_page_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_sukalde_produktua';
  $strongarm->value = '50';
  $export['comment_default_per_page_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_sukalde_errezeta';
  $strongarm->value = 1;
  $export['comment_form_location_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_sukalde_produktua';
  $strongarm->value = 1;
  $export['comment_form_location_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_sukalde_errezeta';
  $strongarm->value = '1';
  $export['comment_preview_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_sukalde_produktua';
  $strongarm->value = '1';
  $export['comment_preview_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_sukalde_errezeta';
  $strongarm->value = 1;
  $export['comment_subject_field_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_sukalde_produktua';
  $strongarm->value = 1;
  $export['comment_subject_field_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_sukalde_errezeta';
  $strongarm->value = '0';
  $export['comment_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_sukalde_produktua';
  $strongarm->value = '2';
  $export['comment_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__sukalde_errezeta';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__sukalde_produktua';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_sukalde_errezeta';
  $strongarm->value = 1;
  $export['i18n_node_extended_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_sukalde_errezeta';
  $strongarm->value = array();
  $export['i18n_node_options_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_sukalde_errezeta';
  $strongarm->value = array();
  $export['i18n_sync_node_type_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_sukalde_produktua';
  $strongarm->value = array();
  $export['i18n_sync_node_type_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_sukalde_errezeta';
  $strongarm->value = '0';
  $export['language_content_type_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_sukalde_produktua';
  $strongarm->value = '0';
  $export['language_content_type_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_sukalde_errezeta';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_sukalde_produktua';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_sukalde_errezeta';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_sukalde_produktua';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_sukalde_errezeta';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_sukalde_produktua';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_sukalde_errezeta';
  $strongarm->value = '0';
  $export['node_preview_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_sukalde_produktua';
  $strongarm->value = '1';
  $export['node_preview_sukalde_produktua'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_sukalde_errezeta';
  $strongarm->value = 1;
  $export['node_submitted_sukalde_errezeta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_sukalde_produktua';
  $strongarm->value = 1;
  $export['node_submitted_sukalde_produktua'] = $strongarm;

  return $export;
}
