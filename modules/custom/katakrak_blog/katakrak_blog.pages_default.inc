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
  $handler->name = 'node_view__panel_context_d6324ce4-104a-43b9-b09d-03ecb602f114';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Término de taxonomía from Nodo (on Nodo: Blog_type [field_blog_type])',
        'keyword' => 'Blog type',
        'name' => 'entity_from_field:field_blog_type-node-taxonomy_term',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'blog' => 'blog',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
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
      'header' => NULL,
      'right' => NULL,
      'left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ddbe68ec-bde8-49ed-997b-8795be8ed158';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-37401d5a-23bb-4d19-9dbd-f03c4acb1307';
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
        'image_link' => 'content',
      ),
      'context' => 'relationship_entity_from_field:field_blog_type-node-taxonomy_term_1',
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
    $pane->uuid = '37401d5a-23bb-4d19-9dbd-f03c4acb1307';
    $display->content['new-37401d5a-23bb-4d19-9dbd-f03c4acb1307'] = $pane;
    $display->panels['header'][0] = 'new-37401d5a-23bb-4d19-9dbd-f03c4acb1307';
    $pane = new stdClass();
    $pane->pid = 'new-85af7824-4fe1-451b-b812-644327076e6c';
    $pane->panel = 'left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '85af7824-4fe1-451b-b812-644327076e6c';
    $display->content['new-85af7824-4fe1-451b-b812-644327076e6c'] = $pane;
    $display->panels['left'][0] = 'new-85af7824-4fe1-451b-b812-644327076e6c';
    $pane = new stdClass();
    $pane->pid = 'new-fb3568ec-0c53-428b-af95-a4d0c27a757f';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-blog-block_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'fb3568ec-0c53-428b-af95-a4d0c27a757f';
    $display->content['new-fb3568ec-0c53-428b-af95-a4d0c27a757f'] = $pane;
    $display->panels['right'][0] = 'new-fb3568ec-0c53-428b-af95-a4d0c27a757f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-85af7824-4fe1-451b-b812-644327076e6c';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_d6324ce4-104a-43b9-b09d-03ecb602f114'] = $handler;

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
    'body_classes_to_add' => 'blog-type-page',
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
        'image_link' => 'content',
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
    $pane->pid = 'new-0d41fb77-6c84-4b78-b973-c3e4d9533956';
    $pane->panel = 'header';
    $pane->type = 'term_name';
    $pane->subtype = 'term_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0d41fb77-6c84-4b78-b973-c3e4d9533956';
    $display->content['new-0d41fb77-6c84-4b78-b973-c3e4d9533956'] = $pane;
    $display->panels['header'][1] = 'new-0d41fb77-6c84-4b78-b973-c3e4d9533956';
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
