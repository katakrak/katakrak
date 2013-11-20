<?php
/**
 * @file
 * katakrak_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function katakrak_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search';
  $page->task = 'page';
  $page->admin_title = 'Search';
  $page->admin_description = '';
  $page->path = 'search/libros/!keywords';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'keywords' => array(
      'id' => 1,
      'identifier' => 'keywords',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Search books',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'right' => NULL,
      'left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-FM9Alkv8hyOtkShgOh3ba7QsdDWF4EHK';
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
    $display->content['new-1'] = $pane;
    $display->panels['left'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-gsuabqVf0AVVqe53zFv7k6te9HVy12PJ';
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
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['left'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'right';
    $pane->type = 'apachesolr_form';
    $pane->subtype = 'apachesolr_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'path_type' => 'same',
      'path' => 'search/libros',
      'override_prompt' => 0,
      'prompt' => '',
      'show_keys' => 1,
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
    $display->content['new-3'] = $pane;
    $display->panels['right'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'right';
    $pane->type = 'apachesolr_result';
    $pane->subtype = 'apachesolr_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'keys_action' => 'none',
      'keys' => '',
      'keys_required' => 1,
      'filters_action' => 'fallback',
      'filters' => '',
      'rows' => '10',
      'env_id' => 'solr',
      'sort_action' => 'none',
      'sort' => '',
      'breadcrumb' => 0,
      'title_override' => 1,
      'title_override_text' => '',
      'empty_override' => 0,
      'empty_override_title' => '',
      'empty_override_text' => array(
        'value' => '',
        'format' => 'plain_text',
      ),
      'empty_override_format' => 'plain_text',
      'log' => 0,
      'substitute' => 0,
      'context' => 'argument_string_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['right'][1] = 'new-4';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  return $pages;

}
