<?php

/**
 * @file
 * katakrak_editorial.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function katakrak_editorial_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'editorial';
  $page->task = 'page';
  $page->admin_title = 'Editorial';
  $page->admin_description = '';
  $page->path = 'editorial';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array(
    'name' => 'main-menu',
    'parent' => array(
      'name' => 'navigation',
      'title' => '',
      'type' => 'none',
      'weight' => '0',
    ),
    'title' => 'Editorial',
    'type' => 'normal',
    'weight' => '0',
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_editorial__panel';
  $handler->task = 'page';
  $handler->subtask = 'editorial';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'not' => FALSE,
          'settings' => array(
            'language' => array(
              'default' => 0,
              'es' => 'es',
              'eu' => 0,
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
    'name' => 'panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Editorial',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'book_info' => NULL,
      'buttons' => NULL,
      'cover' => NULL,
      'default' => NULL,
      'middle' => NULL,
      'title' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Editorial';
  $display->uuid = '7e1985bb-499b-4ab6-adf7-5dea25be8237';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_editorial__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d139a9ea-0bb5-4d2a-8bf6-6701f465b680';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'editorial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_2',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd139a9ea-0bb5-4d2a-8bf6-6701f465b680';
  $display->content['new-d139a9ea-0bb5-4d2a-8bf6-6701f465b680'] = $pane;
  $display->panels['middle'][0] = 'new-d139a9ea-0bb5-4d2a-8bf6-6701f465b680';
  $pane = new stdClass();
  $pane->pid = 'new-c8b17ca2-48db-48a2-9265-7ad63d7a40d6';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'editorial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_5',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c8b17ca2-48db-48a2-9265-7ad63d7a40d6';
  $display->content['new-c8b17ca2-48db-48a2-9265-7ad63d7a40d6'] = $pane;
  $display->panels['middle'][1] = 'new-c8b17ca2-48db-48a2-9265-7ad63d7a40d6';
  $pane = new stdClass();
  $pane->pid = 'new-7b0d3498-e111-44f8-8036-312e09f90398';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'editorial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_7',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7b0d3498-e111-44f8-8036-312e09f90398';
  $display->content['new-7b0d3498-e111-44f8-8036-312e09f90398'] = $pane;
  $display->panels['middle'][2] = 'new-7b0d3498-e111-44f8-8036-312e09f90398';
  $pane = new stdClass();
  $pane->pid = 'new-3051413d-3be1-4064-897a-67b82d79e31c';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'editorial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_8',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '3051413d-3be1-4064-897a-67b82d79e31c';
  $display->content['new-3051413d-3be1-4064-897a-67b82d79e31c'] = $pane;
  $display->panels['middle'][3] = 'new-3051413d-3be1-4064-897a-67b82d79e31c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_editorial__panel_context_067d6737-55da-41db-824e-68208fa1b993';
  $handler->task = 'page';
  $handler->subtask = 'editorial';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'not' => FALSE,
          'settings' => array(
            'language' => array(
              'default' => 0,
              'es' => 0,
              'eu' => 'eu',
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
    'name' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Argitaletxea',
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
  $display->title = 'Argitaletxea';
  $display->uuid = 'b745789f-762c-4081-ba88-e6670a20465a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_editorial__panel_context_067d6737-55da-41db-824e-68208fa1b993';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-630b22c1-5e19-404b-8a1b-6614612859ed';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'editorial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_1',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '630b22c1-5e19-404b-8a1b-6614612859ed';
  $display->content['new-630b22c1-5e19-404b-8a1b-6614612859ed'] = $pane;
  $display->panels['middle'][0] = 'new-630b22c1-5e19-404b-8a1b-6614612859ed';
  $pane = new stdClass();
  $pane->pid = 'new-24e4ac26-794d-4d40-8bf5-e5cf5452072d';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'editorial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_3',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '24e4ac26-794d-4d40-8bf5-e5cf5452072d';
  $display->content['new-24e4ac26-794d-4d40-8bf5-e5cf5452072d'] = $pane;
  $display->panels['middle'][1] = 'new-24e4ac26-794d-4d40-8bf5-e5cf5452072d';
  $pane = new stdClass();
  $pane->pid = 'new-37cb8a49-870d-47d6-8944-f67f4c7ed0eb';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'editorial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_6',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '37cb8a49-870d-47d6-8944-f67f4c7ed0eb';
  $display->content['new-37cb8a49-870d-47d6-8944-f67f4c7ed0eb'] = $pane;
  $display->panels['middle'][2] = 'new-37cb8a49-870d-47d6-8944-f67f4c7ed0eb';
  $pane = new stdClass();
  $pane->pid = 'new-fcc42a11-7438-46d2-a458-11557e57bb1a';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'editorial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_9',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'fcc42a11-7438-46d2-a458-11557e57bb1a';
  $display->content['new-fcc42a11-7438-46d2-a458-11557e57bb1a'] = $pane;
  $display->panels['middle'][3] = 'new-fcc42a11-7438-46d2-a458-11557e57bb1a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['editorial'] = $page;

  return $pages;

}
