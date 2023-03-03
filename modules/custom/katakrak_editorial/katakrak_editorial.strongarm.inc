<?php

/**
 * @file
 * katakrak_editorial.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function katakrak_editorial_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_autor_ed';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_libro_ed';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_autor_ed';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_libro_ed';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_autor_ed';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_libro_ed';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__autor_ed';
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
          'weight' => '2',
        ),
        'metatags' => array(
          'weight' => '6',
        ),
        'path' => array(
          'weight' => '3',
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
  $export['field_bundle_settings_node__autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__libro_ed';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'language' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '3',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
        'product:commerce_price' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '2',
          ),
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
        ),
        'product:sku' => array(
          'card_book' => array(
            'visible' => FALSE,
            'weight' => '-10',
          ),
          'card_book_md' => array(
            'visible' => FALSE,
            'weight' => '-10',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'default' => array(
            'visible' => FALSE,
            'weight' => '-10',
          ),
        ),
        'product:status' => array(
          'card_book' => array(
            'visible' => FALSE,
            'weight' => '5',
          ),
          'card_book_md' => array(
            'visible' => FALSE,
            'weight' => '5',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '4',
          ),
          'default' => array(
            'visible' => FALSE,
            'weight' => '5',
          ),
        ),
        'product:title' => array(
          'card_book' => array(
            'visible' => FALSE,
            'weight' => '-5',
          ),
          'card_book_md' => array(
            'visible' => FALSE,
            'weight' => '-5',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '1',
          ),
          'default' => array(
            'visible' => FALSE,
            'weight' => '-5',
          ),
        ),
        'sharethis' => array(
          'card_book' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
          'card_book_md' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
          'card_book_smgrid' => array(
            'visible' => TRUE,
            'weight' => '5',
          ),
          'default' => array(
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
          'weight' => '10',
        ),
        'path' => array(
          'weight' => '8',
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
  $export['field_bundle_settings_node__libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_default_language_for_autor_ed';
  $strongarm->value = '-- current --';
  $export['i18n_node_default_language_for_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_default_language_for_libro_ed';
  $strongarm->value = '-- current --';
  $export['i18n_node_default_language_for_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_autor_ed';
  $strongarm->value = '1';
  $export['i18n_node_extended_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_libro_ed';
  $strongarm->value = '1';
  $export['i18n_node_extended_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_autor_ed';
  $strongarm->value = array();
  $export['i18n_node_options_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_libro_ed';
  $strongarm->value = array(
    0 => 'current',
  );
  $export['i18n_node_options_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_autor_ed';
  $strongarm->value = array(
    0 => 'field_autor_nacimiento',
    1 => 'field_imagen',
    2 => 'field_libro_autores',
    3 => 'field_autor_apellido',
    4 => 'field_tipo_de_autor',
    5 => 'status',
    6 => 'created',
  );
  $export['i18n_sync_node_type_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_libro_ed';
  $strongarm->value = array(
    0 => 'field_editorial_libro',
    1 => 'field_libro_ed_autor',
    2 => 'field_libro_ed_encuadernacion',
    3 => 'field_libro_ed_precio',
    4 => 'field_libro_ed_prologo',
    5 => 'field_libro_ed_proxima',
    6 => 'field_libro_ed_tamano',
    7 => 'field_libro_ed_traductor',
    8 => 'field_libro_idioma',
    9 => 'field_libro_isbn',
    10 => 'field_libro_paginas',
    11 => 'field_libro_portada',
    12 => 'field_libro_sinopsis',
    13 => 'field_libro_subtitulo',
    14 => 'field_libro_editorial_nota',
    15 => 'field_editorial_prologuista',
    16 => 'field_libro_ed_resenas',
    17 => 'field_donacion',
    18 => 'field_libro_ed_pdf_descarga',
    19 => 'field_libro_ed_color',
    20 => 'status',
  );
  $export['i18n_sync_node_type_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_autor_ed';
  $strongarm->value = '2';
  $export['language_content_type_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_libro_ed';
  $strongarm->value = '2';
  $export['language_content_type_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_autor_ed';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_libro_ed';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_autor_ed';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_libro_ed';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_autor_ed';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_libro_ed';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_autor_ed';
  $strongarm->value = '1';
  $export['node_preview_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_libro_ed';
  $strongarm->value = '1';
  $export['node_preview_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_autor_ed';
  $strongarm->value = 1;
  $export['node_submitted_autor_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_libro_ed';
  $strongarm->value = 1;
  $export['node_submitted_libro_ed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_autor_ed_es_pattern';
  $strongarm->value = 'editorial/autor/[node:title]';
  $export['pathauto_node_autor_ed_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_autor_ed_eu_pattern';
  $strongarm->value = 'argitaletxea/autorea/[node:title]';
  $export['pathauto_node_autor_ed_eu_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_autor_ed_pattern';
  $strongarm->value = 'editorial/autor/[node:title]';
  $export['pathauto_node_autor_ed_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_autor_ed_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_autor_ed_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_libro_ed_es_pattern';
  $strongarm->value = 'editorial/libro/[node:title]';
  $export['pathauto_node_libro_ed_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_libro_ed_eu_pattern';
  $strongarm->value = 'argitaletxea/liburua/[node:title]';
  $export['pathauto_node_libro_ed_eu_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_libro_ed_pattern';
  $strongarm->value = 'editorial/libro/[node:title]';
  $export['pathauto_node_libro_ed_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_libro_ed_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_libro_ed_und_pattern'] = $strongarm;

  return $export;
}
