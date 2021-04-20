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
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_term_1',
          'name' => 'term_vocabulary',
          'not' => FALSE,
          'settings' => array(
            'machine_name' => array(
              'materias' => 'materias',
            ),
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Secciones',
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
  $pane->pid = 'new-4a4b8451-4ece-4d1d-b4d0-f102f6dfb35a';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'libros';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'books_category',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '12',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4a4b8451-4ece-4d1d-b4d0-f102f6dfb35a';
  $display->content['new-4a4b8451-4ece-4d1d-b4d0-f102f6dfb35a'] = $pane;
  $display->panels['middle'][0] = 'new-4a4b8451-4ece-4d1d-b4d0-f102f6dfb35a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_2';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_term_1',
          'name' => 'term_vocabulary',
          'not' => FALSE,
          'settings' => array(
            'machine_name' => array(
              'autores' => 'autores',
            ),
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Autores',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%term:i18n-name';
  $display->uuid = '847d2879-b445-4cc9-9491-bfd5826fbaca';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1744bff1-4c02-4595-bcc3-d204c1dc82ef';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'libros';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block_2',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '12',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1744bff1-4c02-4595-bcc3-d204c1dc82ef';
  $display->content['new-1744bff1-4c02-4595-bcc3-d204c1dc82ef'] = $pane;
  $display->panels['center'][0] = 'new-1744bff1-4c02-4595-bcc3-d204c1dc82ef';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_2'] = $handler;

  return $export;
}
