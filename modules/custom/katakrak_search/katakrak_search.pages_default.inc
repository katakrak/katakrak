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
  $page->access = array();
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
  $display->uuid = 'b6a1510b-b06d-4776-95c9-ee65b4c55510';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1e9f60ef-eded-4648-93d3-da9d4d0872a0';
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
    $pane->uuid = '1e9f60ef-eded-4648-93d3-da9d4d0872a0';
    $display->content['new-1e9f60ef-eded-4648-93d3-da9d4d0872a0'] = $pane;
    $display->panels['col_left'][0] = 'new-1e9f60ef-eded-4648-93d3-da9d4d0872a0';
    $pane = new stdClass();
    $pane->pid = 'new-a781c0cf-7e30-45de-bfe5-2daabeeb40c4';
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
    $pane->uuid = 'a781c0cf-7e30-45de-bfe5-2daabeeb40c4';
    $display->content['new-a781c0cf-7e30-45de-bfe5-2daabeeb40c4'] = $pane;
    $display->panels['col_left'][1] = 'new-a781c0cf-7e30-45de-bfe5-2daabeeb40c4';
    $pane = new stdClass();
    $pane->pid = 'new-aa305457-affd-4df9-9da3-d68220e6958f';
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
    $pane->uuid = 'aa305457-affd-4df9-9da3-d68220e6958f';
    $display->content['new-aa305457-affd-4df9-9da3-d68220e6958f'] = $pane;
    $display->panels['col_left'][2] = 'new-aa305457-affd-4df9-9da3-d68220e6958f';
    $pane = new stdClass();
    $pane->pid = 'new-369d9940-ce98-4ff7-bb7f-f31955b63d55';
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
    $pane->uuid = '369d9940-ce98-4ff7-bb7f-f31955b63d55';
    $display->content['new-369d9940-ce98-4ff7-bb7f-f31955b63d55'] = $pane;
    $display->panels['col_left'][3] = 'new-369d9940-ce98-4ff7-bb7f-f31955b63d55';
    $pane = new stdClass();
    $pane->pid = 'new-0193f1cc-89eb-43aa-a6a6-015e6c290183';
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
    $pane->uuid = '0193f1cc-89eb-43aa-a6a6-015e6c290183';
    $display->content['new-0193f1cc-89eb-43aa-a6a6-015e6c290183'] = $pane;
    $display->panels['content'][0] = 'new-0193f1cc-89eb-43aa-a6a6-015e6c290183';
    $pane = new stdClass();
    $pane->pid = 'new-ea00e7ee-54b7-4c75-8960-487abcefc52b';
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
    $pane->uuid = 'ea00e7ee-54b7-4c75-8960-487abcefc52b';
    $display->content['new-ea00e7ee-54b7-4c75-8960-487abcefc52b'] = $pane;
    $display->panels['content'][1] = 'new-ea00e7ee-54b7-4c75-8960-487abcefc52b';
    $pane = new stdClass();
    $pane->pid = 'new-4dca428c-72e4-49de-a697-7c8b8953e9b7';
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
    $pane->uuid = '4dca428c-72e4-49de-a697-7c8b8953e9b7';
    $display->content['new-4dca428c-72e4-49de-a697-7c8b8953e9b7'] = $pane;
    $display->panels['content'][2] = 'new-4dca428c-72e4-49de-a697-7c8b8953e9b7';
    $pane = new stdClass();
    $pane->pid = 'new-97cd1847-525b-4aa3-9caa-be34feedf80b';
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
    $pane->uuid = '97cd1847-525b-4aa3-9caa-be34feedf80b';
    $display->content['new-97cd1847-525b-4aa3-9caa-be34feedf80b'] = $pane;
    $display->panels['content'][3] = 'new-97cd1847-525b-4aa3-9caa-be34feedf80b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-97cd1847-525b-4aa3-9caa-be34feedf80b';
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
  $display->uuid = '473e461d-1c8a-4fe8-bfff-b778c6b48066';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c25cfcdc-1939-42c0-a208-672877e2b83c';
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
    $pane->uuid = 'c25cfcdc-1939-42c0-a208-672877e2b83c';
    $display->content['new-c25cfcdc-1939-42c0-a208-672877e2b83c'] = $pane;
    $display->panels['col_left'][0] = 'new-c25cfcdc-1939-42c0-a208-672877e2b83c';
    $pane = new stdClass();
    $pane->pid = 'new-042eb2ef-5a5b-4d17-b574-204e8fbfa779';
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
    $pane->uuid = '042eb2ef-5a5b-4d17-b574-204e8fbfa779';
    $display->content['new-042eb2ef-5a5b-4d17-b574-204e8fbfa779'] = $pane;
    $display->panels['col_left'][1] = 'new-042eb2ef-5a5b-4d17-b574-204e8fbfa779';
    $pane = new stdClass();
    $pane->pid = 'new-abea9150-26b9-4099-8521-82515cf0cb3d';
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
    $pane->uuid = 'abea9150-26b9-4099-8521-82515cf0cb3d';
    $display->content['new-abea9150-26b9-4099-8521-82515cf0cb3d'] = $pane;
    $display->panels['col_left'][2] = 'new-abea9150-26b9-4099-8521-82515cf0cb3d';
    $pane = new stdClass();
    $pane->pid = 'new-4d1cfb62-5afb-4cb0-b3b0-f7f92de7f217';
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
    $pane->uuid = '4d1cfb62-5afb-4cb0-b3b0-f7f92de7f217';
    $display->content['new-4d1cfb62-5afb-4cb0-b3b0-f7f92de7f217'] = $pane;
    $display->panels['col_left'][3] = 'new-4d1cfb62-5afb-4cb0-b3b0-f7f92de7f217';
    $pane = new stdClass();
    $pane->pid = 'new-f201e560-d516-4746-90b4-865526354390';
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
    $pane->uuid = 'f201e560-d516-4746-90b4-865526354390';
    $display->content['new-f201e560-d516-4746-90b4-865526354390'] = $pane;
    $display->panels['content'][0] = 'new-f201e560-d516-4746-90b4-865526354390';
    $pane = new stdClass();
    $pane->pid = 'new-cb7ffcd1-1246-42f1-ab52-5eddc6e43f70';
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
    $pane->uuid = 'cb7ffcd1-1246-42f1-ab52-5eddc6e43f70';
    $display->content['new-cb7ffcd1-1246-42f1-ab52-5eddc6e43f70'] = $pane;
    $display->panels['content'][1] = 'new-cb7ffcd1-1246-42f1-ab52-5eddc6e43f70';
    $pane = new stdClass();
    $pane->pid = 'new-6e8f624e-94c7-47c1-b834-a876b350b4ab';
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
    $pane->uuid = '6e8f624e-94c7-47c1-b834-a876b350b4ab';
    $display->content['new-6e8f624e-94c7-47c1-b834-a876b350b4ab'] = $pane;
    $display->panels['content'][2] = 'new-6e8f624e-94c7-47c1-b834-a876b350b4ab';
    $pane = new stdClass();
    $pane->pid = 'new-760bbadf-c71a-412b-ba73-c1e1cc3fc23d';
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
    $pane->uuid = '760bbadf-c71a-412b-ba73-c1e1cc3fc23d';
    $display->content['new-760bbadf-c71a-412b-ba73-c1e1cc3fc23d'] = $pane;
    $display->panels['content'][3] = 'new-760bbadf-c71a-412b-ba73-c1e1cc3fc23d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-760bbadf-c71a-412b-ba73-c1e1cc3fc23d';
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
  $display->uuid = '8d25488c-f17c-428b-b24d-dd65976296ec';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a529d705-6483-47a6-bafc-f0d5e2610ede';
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
    $pane->uuid = 'a529d705-6483-47a6-bafc-f0d5e2610ede';
    $display->content['new-a529d705-6483-47a6-bafc-f0d5e2610ede'] = $pane;
    $display->panels['col_left'][0] = 'new-a529d705-6483-47a6-bafc-f0d5e2610ede';
    $pane = new stdClass();
    $pane->pid = 'new-8a2893f5-98d8-4975-a200-865269eaac73';
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
    $pane->uuid = '8a2893f5-98d8-4975-a200-865269eaac73';
    $display->content['new-8a2893f5-98d8-4975-a200-865269eaac73'] = $pane;
    $display->panels['col_left'][1] = 'new-8a2893f5-98d8-4975-a200-865269eaac73';
    $pane = new stdClass();
    $pane->pid = 'new-48f206c4-7f9d-4307-8843-801566c6b846';
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
    $pane->uuid = '48f206c4-7f9d-4307-8843-801566c6b846';
    $display->content['new-48f206c4-7f9d-4307-8843-801566c6b846'] = $pane;
    $display->panels['col_left'][2] = 'new-48f206c4-7f9d-4307-8843-801566c6b846';
    $pane = new stdClass();
    $pane->pid = 'new-04b5f017-b4c8-4c88-86d0-5d7a30516a07';
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
    $pane->uuid = '04b5f017-b4c8-4c88-86d0-5d7a30516a07';
    $display->content['new-04b5f017-b4c8-4c88-86d0-5d7a30516a07'] = $pane;
    $display->panels['col_left'][3] = 'new-04b5f017-b4c8-4c88-86d0-5d7a30516a07';
    $pane = new stdClass();
    $pane->pid = 'new-d1c8953c-6dbd-4efa-b60d-64345b1bd69d';
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
    $pane->uuid = 'd1c8953c-6dbd-4efa-b60d-64345b1bd69d';
    $display->content['new-d1c8953c-6dbd-4efa-b60d-64345b1bd69d'] = $pane;
    $display->panels['content'][0] = 'new-d1c8953c-6dbd-4efa-b60d-64345b1bd69d';
    $pane = new stdClass();
    $pane->pid = 'new-ae1627ff-41f2-4639-9d1e-34093afa076e';
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
    $pane->uuid = 'ae1627ff-41f2-4639-9d1e-34093afa076e';
    $display->content['new-ae1627ff-41f2-4639-9d1e-34093afa076e'] = $pane;
    $display->panels['content'][1] = 'new-ae1627ff-41f2-4639-9d1e-34093afa076e';
    $pane = new stdClass();
    $pane->pid = 'new-114aab21-af3f-4da2-b3cc-6d696d9ac2f9';
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
    $pane->uuid = '114aab21-af3f-4da2-b3cc-6d696d9ac2f9';
    $display->content['new-114aab21-af3f-4da2-b3cc-6d696d9ac2f9'] = $pane;
    $display->panels['content'][2] = 'new-114aab21-af3f-4da2-b3cc-6d696d9ac2f9';
    $pane = new stdClass();
    $pane->pid = 'new-4dd9c287-186f-4f76-b700-4e0b71613ce7';
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
    $pane->uuid = '4dd9c287-186f-4f76-b700-4e0b71613ce7';
    $display->content['new-4dd9c287-186f-4f76-b700-4e0b71613ce7'] = $pane;
    $display->panels['content'][3] = 'new-4dd9c287-186f-4f76-b700-4e0b71613ce7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4dd9c287-186f-4f76-b700-4e0b71613ce7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_page'] = $page;

  return $pages;

}
