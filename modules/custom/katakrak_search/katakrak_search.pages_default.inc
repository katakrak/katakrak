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
  $page->name = 'search_page';
  $page->task = 'page';
  $page->admin_title = 'Search Page';
  $page->admin_description = '';
  $page->path = 'buscar/%type/!term';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array(
    'term' => array(
      'id' => 3,
      'identifier' => 'Term',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'type' => array(
      'id' => 2,
      'identifier' => 'Type',
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
  $handler->name = 'page_search_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search_page';
  $handler->handler = 'panel_context';
  $handler->weight = -3;
  $handler->conf = array(
    'access' => array(
      'logic' => 'or',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_2',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'libros',
          ),
        ),
        1 => array(
          'context' => 'argument_string_2',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'liburuak',
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
    'title' => 'Book search',
  );
  $display = new panels_display();
  $display->layout = 'search';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'col_left' => NULL,
      'content' => NULL,
      'content_top' => NULL,
      'default' => NULL,
      'facet_left' => NULL,
      'facet_middle' => NULL,
      'facet_right' => NULL,
      'facetapi_badge' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'search_sort' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd1f19336-19bf-4844-b8d5-3fd3eecb621c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_search_page_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-17ceb96f-8dc5-4cf7-b598-a300f730cb7b';
  $pane->panel = 'content';
  $pane->type = 'apachesolr_result';
  $pane->subtype = 'apachesolr_result';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'breadcrumb' => 1,
    'context' => 'argument_string_3',
    'empty_override' => 0,
    'empty_override_format' => 'plain_text',
    'empty_override_text' => array(
      'format' => 'plain_text',
      'value' => '',
    ),
    'empty_override_title' => '',
    'env_id' => 'host_solr',
    'filters' => 'bundle:libro',
    'filters_action' => 'append',
    'keys' => '',
    'keys_action' => 'none',
    'keys_required' => 1,
    'log' => 0,
    'rows' => '12',
    'sort' => '',
    'sort_action' => 'none',
    'substitute' => 0,
    'title_override' => 1,
    'title_override_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '17ceb96f-8dc5-4cf7-b598-a300f730cb7b';
  $display->content['new-17ceb96f-8dc5-4cf7-b598-a300f730cb7b'] = $pane;
  $display->panels['content'][0] = 'new-17ceb96f-8dc5-4cf7-b598-a300f730cb7b';
  $pane = new stdClass();
  $pane->pid = 'new-5c9fe66a-4865-4cac-ba9f-6bcc9948d81d';
  $pane->panel = 'content';
  $pane->type = 'search_result';
  $pane->subtype = 'search_result';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'breadcrumb' => 1,
    'context' => 'argument_string_3',
    'empty_override' => 0,
    'empty_override_format' => 'plain_text',
    'empty_override_text' => array(
      'format' => 'plain_text',
      'value' => '',
    ),
    'empty_override_title' => '',
    'env_id' => 'host_solr',
    'filters' => 'bundle:libro',
    'filters_action' => 'override',
    'keys' => '',
    'keys_action' => 'none',
    'keys_required' => 1,
    'log' => 0,
    'rows' => '12',
    'sort' => '',
    'sort_action' => 'none',
    'substitute' => 0,
    'tipo' => 'libros',
    'title_override' => 1,
    'title_override_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5c9fe66a-4865-4cac-ba9f-6bcc9948d81d';
  $display->content['new-5c9fe66a-4865-4cac-ba9f-6bcc9948d81d'] = $pane;
  $display->panels['content'][1] = 'new-5c9fe66a-4865-4cac-ba9f-6bcc9948d81d';
  $pane = new stdClass();
  $pane->pid = 'new-c162f5df-f763-443c-8561-de90980d3dc2';
  $pane->panel = 'content';
  $pane->type = 'book_search_info';
  $pane->subtype = 'book_search_info';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'title_override' => FALSE,
    'title_override_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c162f5df-f763-443c-8561-de90980d3dc2';
  $display->content['new-c162f5df-f763-443c-8561-de90980d3dc2'] = $pane;
  $display->panels['content'][2] = 'new-c162f5df-f763-443c-8561-de90980d3dc2';
  $pane = new stdClass();
  $pane->pid = 'new-730ebbae-acdf-4c8b-a3ba-bdd8e6a17744';
  $pane->panel = 'content';
  $pane->type = 'search_title';
  $pane->subtype = 'search_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '730ebbae-acdf-4c8b-a3ba-bdd8e6a17744';
  $display->content['new-730ebbae-acdf-4c8b-a3ba-bdd8e6a17744'] = $pane;
  $display->panels['content'][3] = 'new-730ebbae-acdf-4c8b-a3ba-bdd8e6a17744';
  $pane = new stdClass();
  $pane->pid = 'new-fb8d964c-e577-4ca7-937c-2908b8f4b42e';
  $pane->panel = 'content_top';
  $pane->type = 'block';
  $pane->subtype = 'libro-libreria_home_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'fb8d964c-e577-4ca7-937c-2908b8f4b42e';
  $display->content['new-fb8d964c-e577-4ca7-937c-2908b8f4b42e'] = $pane;
  $display->panels['content_top'][0] = 'new-fb8d964c-e577-4ca7-937c-2908b8f4b42e';
  $pane = new stdClass();
  $pane->pid = 'new-305fb4d7-25e7-48b9-bb13-60c1fbda3d88';
  $pane->panel = 'content_top';
  $pane->type = 'apachesolr_form';
  $pane->subtype = 'apachesolr_form';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_prompt' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'path' => '',
    'path_type' => 'same',
    'prompt' => '',
    'show_keys' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '305fb4d7-25e7-48b9-bb13-60c1fbda3d88';
  $display->content['new-305fb4d7-25e7-48b9-bb13-60c1fbda3d88'] = $pane;
  $display->panels['content_top'][1] = 'new-305fb4d7-25e7-48b9-bb13-60c1fbda3d88';
  $pane = new stdClass();
  $pane->pid = 'new-d1502980-44bb-49f3-af09-530024e62258';
  $pane->panel = 'facetapi_badge';
  $pane->type = 'block';
  $pane->subtype = 'katakrak_search-katakrak_search_facetapi_badges';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'd1502980-44bb-49f3-af09-530024e62258';
  $display->content['new-d1502980-44bb-49f3-af09-530024e62258'] = $pane;
  $display->panels['facetapi_badge'][0] = 'new-d1502980-44bb-49f3-af09-530024e62258';
  $pane = new stdClass();
  $pane->pid = 'new-250e07a7-e959-4ffe-b267-5cfdc385f29a';
  $pane->panel = 'facet_left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-PAPjfNGXLf8kwELGjKWKtreSo3uLpN7o';
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
  $pane->uuid = '250e07a7-e959-4ffe-b267-5cfdc385f29a';
  $display->content['new-250e07a7-e959-4ffe-b267-5cfdc385f29a'] = $pane;
  $display->panels['facet_left'][0] = 'new-250e07a7-e959-4ffe-b267-5cfdc385f29a';
  $pane = new stdClass();
  $pane->pid = 'new-0d315684-f8d8-47d7-aa82-a3b04904c2b9';
  $pane->panel = 'facet_middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-epXisguuKvVoi6fMMxKqzboj7TLY0Uv4';
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
  $pane->uuid = '0d315684-f8d8-47d7-aa82-a3b04904c2b9';
  $display->content['new-0d315684-f8d8-47d7-aa82-a3b04904c2b9'] = $pane;
  $display->panels['facet_middle'][0] = 'new-0d315684-f8d8-47d7-aa82-a3b04904c2b9';
  $pane = new stdClass();
  $pane->pid = 'new-4cb9ad4d-0a29-4bfb-8e5c-73d5aa870beb';
  $pane->panel = 'facet_right';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-10g0ejljiIMmKZgIOLoj9YiSr0A0LxYe';
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
  $pane->uuid = '4cb9ad4d-0a29-4bfb-8e5c-73d5aa870beb';
  $display->content['new-4cb9ad4d-0a29-4bfb-8e5c-73d5aa870beb'] = $pane;
  $display->panels['facet_right'][0] = 'new-4cb9ad4d-0a29-4bfb-8e5c-73d5aa870beb';
  $pane = new stdClass();
  $pane->pid = 'new-3f31ef65-2e1f-41f0-8651-33e5d34c0cdd';
  $pane->panel = 'search_sort';
  $pane->type = 'block';
  $pane->subtype = 'apachesolr_search-sort';
  $pane->shown = FALSE;
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
  $pane->uuid = '3f31ef65-2e1f-41f0-8651-33e5d34c0cdd';
  $display->content['new-3f31ef65-2e1f-41f0-8651-33e5d34c0cdd'] = $pane;
  $display->panels['search_sort'][0] = 'new-3f31ef65-2e1f-41f0-8651-33e5d34c0cdd';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-730ebbae-acdf-4c8b-a3ba-bdd8e6a17744';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_page_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'search_page';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_2',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'agenda',
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
    'title' => 'Event search',
  );
  $display = new panels_display();
  $display->layout = 'search';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'col_left' => NULL,
      'content' => NULL,
      'content_top' => NULL,
      'default' => NULL,
      'facet_left' => NULL,
      'facet_middle' => NULL,
      'facet_right' => NULL,
      'facetapi_badge' => NULL,
      'left' => NULL,
      'right' => NULL,
      'search_sort' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Buscando %term:raw';
  $display->uuid = '9ad630c8-b0a1-4054-98fd-4dba6c637f61';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_search_page_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f8c73b3f-2299-4701-ba1b-f4bff1522de4';
  $pane->panel = 'content';
  $pane->type = 'search_result';
  $pane->subtype = 'search_result';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'breadcrumb' => 1,
    'context' => 'argument_string_3',
    'empty_override' => 0,
    'empty_override_format' => 'plain_text',
    'empty_override_text' => array(
      'format' => 'plain_text',
      'value' => '',
    ),
    'empty_override_title' => '',
    'env_id' => '',
    'filters' => 'bundle:event',
    'filters_action' => 'override',
    'keys' => '',
    'keys_action' => 'none',
    'keys_required' => 1,
    'log' => 0,
    'rows' => '20',
    'sort' => '',
    'sort_action' => 'none',
    'substitute' => 0,
    'tipo' => 'agenda',
    'title_override' => 1,
    'title_override_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f8c73b3f-2299-4701-ba1b-f4bff1522de4';
  $display->content['new-f8c73b3f-2299-4701-ba1b-f4bff1522de4'] = $pane;
  $display->panels['content'][0] = 'new-f8c73b3f-2299-4701-ba1b-f4bff1522de4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_page_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'search_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_2',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'all',
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
    'title' => 'Search',
  );
  $display = new panels_display();
  $display->layout = 'search';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'col_left' => NULL,
      'content' => NULL,
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Buscando %term:raw';
  $display->uuid = 'b32fdae4-7b43-49a6-b8a2-d798b54a8a95';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_search_page_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-deb76053-50b8-463e-95f2-cd8bbcad44b0';
  $pane->panel = 'col_left';
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
  $pane->uuid = 'deb76053-50b8-463e-95f2-cd8bbcad44b0';
  $display->content['new-deb76053-50b8-463e-95f2-cd8bbcad44b0'] = $pane;
  $display->panels['col_left'][0] = 'new-deb76053-50b8-463e-95f2-cd8bbcad44b0';
  $pane = new stdClass();
  $pane->pid = 'new-d0df89e5-1d89-4600-ada5-c71f76ed8665';
  $pane->panel = 'col_left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-R2UTz6TzAt7lw1croPaTispTk1IwtN2e';
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
  $pane->uuid = 'd0df89e5-1d89-4600-ada5-c71f76ed8665';
  $display->content['new-d0df89e5-1d89-4600-ada5-c71f76ed8665'] = $pane;
  $display->panels['col_left'][1] = 'new-d0df89e5-1d89-4600-ada5-c71f76ed8665';
  $pane = new stdClass();
  $pane->pid = 'new-c8835d14-8d7f-4052-aefe-89493cae1daa';
  $pane->panel = 'col_left';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c8835d14-8d7f-4052-aefe-89493cae1daa';
  $display->content['new-c8835d14-8d7f-4052-aefe-89493cae1daa'] = $pane;
  $display->panels['col_left'][2] = 'new-c8835d14-8d7f-4052-aefe-89493cae1daa';
  $pane = new stdClass();
  $pane->pid = 'new-66527d4d-83dc-412d-bd4d-10111e7aa965';
  $pane->panel = 'col_left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-YMxL6TyYd1dRvjZOiUikBq0F3tS8YTPY';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '66527d4d-83dc-412d-bd4d-10111e7aa965';
  $display->content['new-66527d4d-83dc-412d-bd4d-10111e7aa965'] = $pane;
  $display->panels['col_left'][3] = 'new-66527d4d-83dc-412d-bd4d-10111e7aa965';
  $pane = new stdClass();
  $pane->pid = 'new-2ff3ec36-6717-4f70-97d2-a7ac57fc93dd';
  $pane->panel = 'content';
  $pane->type = 'apachesolr_form';
  $pane->subtype = 'apachesolr_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_prompt' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'path' => 'search/books',
    'path_type' => 'custom',
    'prompt' => '',
    'show_keys' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2ff3ec36-6717-4f70-97d2-a7ac57fc93dd';
  $display->content['new-2ff3ec36-6717-4f70-97d2-a7ac57fc93dd'] = $pane;
  $display->panels['content'][0] = 'new-2ff3ec36-6717-4f70-97d2-a7ac57fc93dd';
  $pane = new stdClass();
  $pane->pid = 'new-1d938658-cdee-4434-be50-776f6cc2e10d';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'apachesolr_search-sort';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '1d938658-cdee-4434-be50-776f6cc2e10d';
  $display->content['new-1d938658-cdee-4434-be50-776f6cc2e10d'] = $pane;
  $display->panels['content'][1] = 'new-1d938658-cdee-4434-be50-776f6cc2e10d';
  $pane = new stdClass();
  $pane->pid = 'new-174896c2-5b85-4088-a63b-d7bc91830f38';
  $pane->panel = 'content';
  $pane->type = 'apachesolr_info';
  $pane->subtype = 'apachesolr_info';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'title_override' => FALSE,
    'title_override_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '174896c2-5b85-4088-a63b-d7bc91830f38';
  $display->content['new-174896c2-5b85-4088-a63b-d7bc91830f38'] = $pane;
  $display->panels['content'][2] = 'new-174896c2-5b85-4088-a63b-d7bc91830f38';
  $pane = new stdClass();
  $pane->pid = 'new-56e01a2d-86e3-4a63-bf16-13b143d84779';
  $pane->panel = 'content';
  $pane->type = 'apachesolr_result';
  $pane->subtype = 'apachesolr_result';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'breadcrumb' => 0,
    'context' => 'argument_string_3',
    'empty_override' => 0,
    'empty_override_format' => 'plain_text',
    'empty_override_text' => array(
      'format' => 'plain_text',
      'value' => '',
    ),
    'empty_override_title' => '',
    'env_id' => 'solr',
    'filters' => '',
    'filters_action' => 'none',
    'keys' => '',
    'keys_action' => 'none',
    'keys_required' => 0,
    'log' => 0,
    'rows' => '10',
    'sort' => '',
    'sort_action' => 'none',
    'substitute' => 0,
    'title_override' => 1,
    'title_override_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '56e01a2d-86e3-4a63-bf16-13b143d84779';
  $display->content['new-56e01a2d-86e3-4a63-bf16-13b143d84779'] = $pane;
  $display->panels['content'][3] = 'new-56e01a2d-86e3-4a63-bf16-13b143d84779';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-56e01a2d-86e3-4a63-bf16-13b143d84779';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_page__panel_context_b44588cd-b409-4b50-bffb-52d6a1fb8ad1';
  $handler->task = 'page';
  $handler->subtask = 'search_page';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_2',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'blogs',
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
    'title' => 'Blog search',
  );
  $display = new panels_display();
  $display->layout = 'search';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'content' => NULL,
      'content_top' => NULL,
      'default' => NULL,
      'facet_left' => NULL,
      'facet_middle' => NULL,
      'facet_right' => NULL,
      'facetapi_badge' => NULL,
      'search_sort' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7848fba6-ab37-4293-9256-b8d824184341';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_search_page__panel_context_b44588cd-b409-4b50-bffb-52d6a1fb8ad1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3eb2e9fb-de1d-4bc7-aeee-feff177ae557';
  $pane->panel = 'content';
  $pane->type = 'search_result';
  $pane->subtype = 'search_result';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'breadcrumb' => 1,
    'context' => 'argument_string_3',
    'empty_override' => 0,
    'empty_override_format' => 'plain_text',
    'empty_override_text' => array(
      'format' => 'plain_text',
      'value' => '',
    ),
    'empty_override_title' => '',
    'env_id' => '',
    'filters' => 'bundle:blog',
    'filters_action' => 'override',
    'keys' => '',
    'keys_action' => 'none',
    'keys_required' => 1,
    'log' => 0,
    'rows' => '15',
    'sort' => '',
    'sort_action' => 'none',
    'substitute' => 0,
    'tipo' => 'blogs',
    'title_override' => 1,
    'title_override_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3eb2e9fb-de1d-4bc7-aeee-feff177ae557';
  $display->content['new-3eb2e9fb-de1d-4bc7-aeee-feff177ae557'] = $pane;
  $display->panels['content'][0] = 'new-3eb2e9fb-de1d-4bc7-aeee-feff177ae557';
  $pane = new stdClass();
  $pane->pid = 'new-de594a9d-d2b0-4f32-baee-b05c56091156';
  $pane->panel = 'content_top';
  $pane->type = 'block';
  $pane->subtype = 'katakrak_blog-katakrak_blog_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'de594a9d-d2b0-4f32-baee-b05c56091156';
  $display->content['new-de594a9d-d2b0-4f32-baee-b05c56091156'] = $pane;
  $display->panels['content_top'][0] = 'new-de594a9d-d2b0-4f32-baee-b05c56091156';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_page'] = $page;

  return $pages;

}
