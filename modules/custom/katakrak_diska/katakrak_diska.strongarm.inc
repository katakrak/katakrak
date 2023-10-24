<?php

/**
 * @file
 * katakrak_diska.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function katakrak_diska_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_disco';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_disco';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_disco';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__disco';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'language' => array(
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
        ),
      ),
      'form' => array(
        'language' => array(
          'weight' => '0',
        ),
        'metatags' => array(
          'weight' => '40',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'title' => array(
          'weight' => '-5',
        ),
      ),
    ),
    'view_modes' => array(
      'card_book' => array(
        'custom_settings' => TRUE,
      ),
      'card_book_md' => array(
        'custom_settings' => TRUE,
      ),
      'card_book_smgrid' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_node__disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_disco';
  $strongarm->value = array();
  $export['i18n_sync_node_type_disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_disco';
  $strongarm->value = '2';
  $export['language_content_type_disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_disco';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_disco';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_disco';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_disco';
  $strongarm->value = '1';
  $export['node_preview_disco'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_disco';
  $strongarm->value = 1;
  $export['node_submitted_disco'] = $strongarm;

  return $export;
}
