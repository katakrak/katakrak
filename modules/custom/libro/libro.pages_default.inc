<?php

/**
 * @file
 * libro.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function libro_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Secciones',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'materias' => 'materias',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%term:i18n-name';
  $display->uuid = 'a43c7295-d4a5-45b6-9805-5dbb59464dfb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f916320a-c72d-4e65-b551-75bc25ffab07';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-libros-block_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f916320a-c72d-4e65-b551-75bc25ffab07';
  $display->content['new-f916320a-c72d-4e65-b551-75bc25ffab07'] = $pane;
  $display->panels['middle'][0] = 'new-f916320a-c72d-4e65-b551-75bc25ffab07';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f916320a-c72d-4e65-b551-75bc25ffab07';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}
