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
        'keyword' => 'blogtype',
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_d6324ce4-104a-43b9-b09d-03ecb602f114';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-178848e4-07f1-4bdf-a79b-00aae294566b';
  $pane->panel = 'header';
  $pane->type = 'header';
  $pane->subtype = 'header';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 1,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
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
  $pane->uuid = '178848e4-07f1-4bdf-a79b-00aae294566b';
  $display->content['new-178848e4-07f1-4bdf-a79b-00aae294566b'] = $pane;
  $display->panels['header'][0] = 'new-178848e4-07f1-4bdf-a79b-00aae294566b';
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
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 1,
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
  $pane->pid = 'new-f8b3f688-6ccb-42d4-90a2-fc4a8f7aa5e5';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'blog-blog_post_libreria';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'arguments' => array(
      'field_blog_type_tid' => '%blogtype:tid',
      'nid' => '%node:nid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f8b3f688-6ccb-42d4-90a2-fc4a8f7aa5e5';
  $display->content['new-f8b3f688-6ccb-42d4-90a2-fc4a8f7aa5e5'] = $pane;
  $display->panels['right'][0] = 'new-f8b3f688-6ccb-42d4-90a2-fc4a8f7aa5e5';
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
    'body_classes_to_add' => 'blog-page',
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view__panel_context_be36e115-8c57-44cb-b384-0e9f7e36ab71';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-85fa99a1-8b0d-4d03-82b0-61beaecdb464';
  $pane->panel = 'header';
  $pane->type = 'header';
  $pane->subtype = 'header';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 1,
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '85fa99a1-8b0d-4d03-82b0-61beaecdb464';
  $display->content['new-85fa99a1-8b0d-4d03-82b0-61beaecdb464'] = $pane;
  $display->panels['header'][0] = 'new-85fa99a1-8b0d-4d03-82b0-61beaecdb464';
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
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_be36e115-8c57-44cb-b384-0e9f7e36ab71'] = $handler;

  return $export;
}
