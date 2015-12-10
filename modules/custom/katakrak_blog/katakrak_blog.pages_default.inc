<?php
/**
 * @file
 * katakrak_blog.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function katakrak_blog_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_be36e115-8c57-44cb-b384-0e9f7e36ab71';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Blog',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'blog_type' => 'blog_type',
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
  $display->layout = 'blog';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'right' => NULL,
      'left' => NULL,
      'header' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5d0a9c58-9c52-46d4-ae94-43d6bf868cc6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3be758fa-a129-4d80-a446-1e7b4400c2ab';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'taxonomy_term:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'image',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => '',
      ),
      'context' => 'argument_term_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3be758fa-a129-4d80-a446-1e7b4400c2ab';
    $display->content['new-3be758fa-a129-4d80-a446-1e7b4400c2ab'] = $pane;
    $display->panels['header'][0] = 'new-3be758fa-a129-4d80-a446-1e7b4400c2ab';
    $pane = new stdClass();
    $pane->pid = 'new-76683b64-bc0c-4822-939a-f2e56959616e';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'views-blog-blogs_by_cat';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '76683b64-bc0c-4822-939a-f2e56959616e';
    $display->content['new-76683b64-bc0c-4822-939a-f2e56959616e'] = $pane;
    $display->panels['left'][0] = 'new-76683b64-bc0c-4822-939a-f2e56959616e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3be758fa-a129-4d80-a446-1e7b4400c2ab';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_be36e115-8c57-44cb-b384-0e9f7e36ab71'] = $handler;

  return $export;
}
