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
  $page->path = 'search/%type/%term';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'type' => array(
      'id' => 2,
      'identifier' => 'Type',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'term' => array(
      'id' => 3,
      'identifier' => 'Term',
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
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Book search',
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
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'books',
            'case' => 0,
          ),
          'context' => 'argument_string_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'search';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'col_left' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Buscando %term:raw';
  $display->uuid = 'd1f19336-19bf-4844-b8d5-3fd3eecb621c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4fdb32a4-e213-4ace-980b-70edd773c557';
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
    $pane->uuid = '4fdb32a4-e213-4ace-980b-70edd773c557';
    $display->content['new-4fdb32a4-e213-4ace-980b-70edd773c557'] = $pane;
    $display->panels['col_left'][0] = 'new-4fdb32a4-e213-4ace-980b-70edd773c557';
    $pane = new stdClass();
    $pane->pid = 'new-09bbd6df-efef-4c7f-9404-76b5548c67e5';
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
    $pane->uuid = '09bbd6df-efef-4c7f-9404-76b5548c67e5';
    $display->content['new-09bbd6df-efef-4c7f-9404-76b5548c67e5'] = $pane;
    $display->panels['col_left'][1] = 'new-09bbd6df-efef-4c7f-9404-76b5548c67e5';
    $pane = new stdClass();
    $pane->pid = 'new-a89603e7-edee-4eae-b08f-2d777000c1ec';
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
    $pane->uuid = 'a89603e7-edee-4eae-b08f-2d777000c1ec';
    $display->content['new-a89603e7-edee-4eae-b08f-2d777000c1ec'] = $pane;
    $display->panels['col_left'][2] = 'new-a89603e7-edee-4eae-b08f-2d777000c1ec';
    $pane = new stdClass();
    $pane->pid = 'new-f398993c-eb14-4970-979b-3c36567149ac';
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
    $pane->uuid = 'f398993c-eb14-4970-979b-3c36567149ac';
    $display->content['new-f398993c-eb14-4970-979b-3c36567149ac'] = $pane;
    $display->panels['col_left'][3] = 'new-f398993c-eb14-4970-979b-3c36567149ac';
    $pane = new stdClass();
    $pane->pid = 'new-9c0b5806-59df-4b5e-8349-94da99daa999';
    $pane->panel = 'content';
    $pane->type = 'apachesolr_form';
    $pane->subtype = 'apachesolr_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'path_type' => 'custom',
      'path' => 'search/books',
      'override_prompt' => 0,
      'prompt' => '',
      'show_keys' => 1,
      'override_title' => 1,
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
    $pane->uuid = '9c0b5806-59df-4b5e-8349-94da99daa999';
    $display->content['new-9c0b5806-59df-4b5e-8349-94da99daa999'] = $pane;
    $display->panels['content'][0] = 'new-9c0b5806-59df-4b5e-8349-94da99daa999';
    $pane = new stdClass();
    $pane->pid = 'new-3252c655-f47b-45e3-8832-39bf28e3f748';
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
    $pane->uuid = '3252c655-f47b-45e3-8832-39bf28e3f748';
    $display->content['new-3252c655-f47b-45e3-8832-39bf28e3f748'] = $pane;
    $display->panels['content'][1] = 'new-3252c655-f47b-45e3-8832-39bf28e3f748';
    $pane = new stdClass();
    $pane->pid = 'new-228dcb3d-915a-48ae-97ca-6d53090813ec';
    $pane->panel = 'content';
    $pane->type = 'apachesolr_info';
    $pane->subtype = 'apachesolr_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => FALSE,
      'title_override_text' => '',
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
    $pane->uuid = '228dcb3d-915a-48ae-97ca-6d53090813ec';
    $display->content['new-228dcb3d-915a-48ae-97ca-6d53090813ec'] = $pane;
    $display->panels['content'][2] = 'new-228dcb3d-915a-48ae-97ca-6d53090813ec';
    $pane = new stdClass();
    $pane->pid = 'new-4c7d7032-ac9b-4a93-858c-6966d47218af';
    $pane->panel = 'content';
    $pane->type = 'apachesolr_result';
    $pane->subtype = 'apachesolr_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'keys_action' => 'none',
      'keys' => '',
      'keys_required' => 0,
      'filters_action' => 'override',
      'filters' => 'bundle:libro',
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
      'context' => 'argument_string_3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4c7d7032-ac9b-4a93-858c-6966d47218af';
    $display->content['new-4c7d7032-ac9b-4a93-858c-6966d47218af'] = $pane;
    $display->panels['content'][3] = 'new-4c7d7032-ac9b-4a93-858c-6966d47218af';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4c7d7032-ac9b-4a93-858c-6966d47218af';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_page_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'search_page';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Event search',
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
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'agenda',
            'case' => 0,
          ),
          'context' => 'argument_string_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'search';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'col_left' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Buscando %term:raw';
  $display->uuid = '9ad630c8-b0a1-4054-98fd-4dba6c637f61';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-823e3f7d-9556-4a2f-9fc2-d33b8906e0da';
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
    $pane->uuid = '823e3f7d-9556-4a2f-9fc2-d33b8906e0da';
    $display->content['new-823e3f7d-9556-4a2f-9fc2-d33b8906e0da'] = $pane;
    $display->panels['col_left'][0] = 'new-823e3f7d-9556-4a2f-9fc2-d33b8906e0da';
    $pane = new stdClass();
    $pane->pid = 'new-fb9257db-9bdf-4225-a738-26a58bc7216e';
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
    $pane->uuid = 'fb9257db-9bdf-4225-a738-26a58bc7216e';
    $display->content['new-fb9257db-9bdf-4225-a738-26a58bc7216e'] = $pane;
    $display->panels['col_left'][1] = 'new-fb9257db-9bdf-4225-a738-26a58bc7216e';
    $pane = new stdClass();
    $pane->pid = 'new-a9ce84bc-5cb6-45db-a379-d9cd82320777';
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
    $pane->uuid = 'a9ce84bc-5cb6-45db-a379-d9cd82320777';
    $display->content['new-a9ce84bc-5cb6-45db-a379-d9cd82320777'] = $pane;
    $display->panels['col_left'][2] = 'new-a9ce84bc-5cb6-45db-a379-d9cd82320777';
    $pane = new stdClass();
    $pane->pid = 'new-e47c9403-d376-48e9-8192-b58e5ff76ac9';
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
    $pane->uuid = 'e47c9403-d376-48e9-8192-b58e5ff76ac9';
    $display->content['new-e47c9403-d376-48e9-8192-b58e5ff76ac9'] = $pane;
    $display->panels['col_left'][3] = 'new-e47c9403-d376-48e9-8192-b58e5ff76ac9';
    $pane = new stdClass();
    $pane->pid = 'new-3e298c17-ed4f-4dd4-b542-1a653c8f5e46';
    $pane->panel = 'content';
    $pane->type = 'apachesolr_form';
    $pane->subtype = 'apachesolr_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'path_type' => 'custom',
      'path' => 'search/agenda',
      'override_prompt' => 0,
      'prompt' => '',
      'show_keys' => 1,
      'override_title' => 1,
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
    $pane->uuid = '3e298c17-ed4f-4dd4-b542-1a653c8f5e46';
    $display->content['new-3e298c17-ed4f-4dd4-b542-1a653c8f5e46'] = $pane;
    $display->panels['content'][0] = 'new-3e298c17-ed4f-4dd4-b542-1a653c8f5e46';
    $pane = new stdClass();
    $pane->pid = 'new-ebf543c8-f079-4059-80ea-1836389a6930';
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
    $pane->uuid = 'ebf543c8-f079-4059-80ea-1836389a6930';
    $display->content['new-ebf543c8-f079-4059-80ea-1836389a6930'] = $pane;
    $display->panels['content'][1] = 'new-ebf543c8-f079-4059-80ea-1836389a6930';
    $pane = new stdClass();
    $pane->pid = 'new-7d7deaab-dbdd-4812-88f0-13e8e91718d0';
    $pane->panel = 'content';
    $pane->type = 'apachesolr_info';
    $pane->subtype = 'apachesolr_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => FALSE,
      'title_override_text' => '',
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
    $pane->uuid = '7d7deaab-dbdd-4812-88f0-13e8e91718d0';
    $display->content['new-7d7deaab-dbdd-4812-88f0-13e8e91718d0'] = $pane;
    $display->panels['content'][2] = 'new-7d7deaab-dbdd-4812-88f0-13e8e91718d0';
    $pane = new stdClass();
    $pane->pid = 'new-5d52db8d-fd19-40fe-8517-cb032f2d1ac1';
    $pane->panel = 'content';
    $pane->type = 'apachesolr_result';
    $pane->subtype = 'apachesolr_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'keys_action' => 'none',
      'keys' => '',
      'keys_required' => 0,
      'filters_action' => 'override',
      'filters' => 'bundle:event',
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
      'context' => 'argument_string_3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '5d52db8d-fd19-40fe-8517-cb032f2d1ac1';
    $display->content['new-5d52db8d-fd19-40fe-8517-cb032f2d1ac1'] = $pane;
    $display->panels['content'][3] = 'new-5d52db8d-fd19-40fe-8517-cb032f2d1ac1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5d52db8d-fd19-40fe-8517-cb032f2d1ac1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_page_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'search_page';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Search',
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
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'all',
            'case' => 0,
          ),
          'context' => 'argument_string_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'search';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'col_left' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Buscando %term:raw';
  $display->uuid = 'b32fdae4-7b43-49a6-b8a2-d798b54a8a95';
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
      'path_type' => 'custom',
      'path' => 'search/books',
      'override_prompt' => 0,
      'prompt' => '',
      'show_keys' => 1,
      'override_title' => 1,
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
      'title_override' => FALSE,
      'title_override_text' => '',
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
      'keys_action' => 'none',
      'keys' => '',
      'keys_required' => 0,
      'filters_action' => 'none',
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
      'context' => 'argument_string_3',
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
  $pages['search_page'] = $page;

  return $pages;

}
