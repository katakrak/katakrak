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
    'extra_fields' => array(
      'display' => array(
        'language' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'search_index' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'teaser' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
        'product:commerce_price' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'search_index' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'search_result' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'teaser' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
        'product:commerce_product_tariff_service' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'search_index' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'teaser' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
        'product:commerce_product_tariff_weight' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'search_index' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '0',
          ),
          'teaser' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
        'product:commerce_stock' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '37',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '37',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '37',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '37',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '37',
          ),
          'search_index' => array(
            'visible' => FALSE,
            'weight' => '37',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '37',
          ),
          'teaser' => array(
            'visible' => TRUE,
            'weight' => '37',
          ),
        ),
        'product:field_peso_medio' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '38',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '38',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '38',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '38',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '38',
          ),
          'search_index' => array(
            'visible' => FALSE,
            'weight' => '38',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '38',
          ),
          'teaser' => array(
            'visible' => TRUE,
            'weight' => '38',
          ),
        ),
        'product:field_product_peso' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '36',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '36',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '36',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '36',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '36',
          ),
          'search_index' => array(
            'visible' => FALSE,
            'weight' => '36',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '36',
          ),
          'teaser' => array(
            'visible' => TRUE,
            'weight' => '36',
          ),
        ),
        'product:sku' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '-10',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '-10',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '-10',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '-10',
          ),
          'default' => array(
            'visible' => FALSE,
            'weight' => '-10',
          ),
          'search_index' => array(
            'visible' => FALSE,
            'weight' => '-10',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '-10',
          ),
          'teaser' => array(
            'visible' => FALSE,
            'weight' => '-10',
          ),
        ),
        'product:status' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '5',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '5',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '5',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '5',
          ),
          'default' => array(
            'visible' => FALSE,
            'weight' => '5',
          ),
          'search_index' => array(
            'visible' => FALSE,
            'weight' => '5',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '5',
          ),
          'teaser' => array(
            'visible' => FALSE,
            'weight' => '5',
          ),
        ),
        'product:title' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '-5',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '-5',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '-5',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '-5',
          ),
          'default' => array(
            'visible' => FALSE,
            'weight' => '-5',
          ),
          'search_index' => array(
            'visible' => TRUE,
            'weight' => '-5',
          ),
          'search_result' => array(
            'visible' => FALSE,
            'weight' => '-5',
          ),
          'teaser' => array(
            'visible' => FALSE,
            'weight' => '-5',
          ),
        ),
        'sharethis' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
          'card_book_editorial' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
          'teaser' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
        ),
      ),
      'form' => array(
        'language' => array(
          'weight' => '1',
        ),
        'metatags' => array(
          'weight' => '12',
        ),
        'path' => array(
          'weight' => '12',
        ),
        'title' => array(
          'weight' => '0',
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
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'home_event' => array(
        'custom_settings' => TRUE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
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
