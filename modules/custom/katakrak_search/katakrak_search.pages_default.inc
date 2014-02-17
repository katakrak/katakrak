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
  $page->name = 'search_books';
  $page->task = 'page';
  $page->admin_title = 'Search books';
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
      'id' => 1,
      'identifier' => 'Texto',
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
  $handler->name = 'page_search_books_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search_books';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
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
    $display->content['new-1'] = $pane;
    $display->panels['col_left'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
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
    $display->content['new-2'] = $pane;
    $display->panels['col_left'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
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
    $display->content['new-3'] = $pane;
    $display->panels['col_left'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
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
    $display->content['new-4'] = $pane;
    $display->panels['col_left'][3] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
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
    $display->content['new-5'] = $pane;
    $display->panels['content'][0] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
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
    $display->content['new-6'] = $pane;
    $display->panels['content'][1] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
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
    $display->content['new-7'] = $pane;
    $display->panels['content'][2] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
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
      'context' => 'argument_string_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['content'][3] = 'new-8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_books_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'search_books';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9';
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
    $display->content['new-9'] = $pane;
    $display->panels['col_left'][0] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
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
    $display->content['new-10'] = $pane;
    $display->panels['col_left'][1] = 'new-10';
    $pane = new stdClass();
    $pane->pid = 'new-11';
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
    $display->content['new-11'] = $pane;
    $display->panels['col_left'][2] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
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
    $display->content['new-12'] = $pane;
    $display->panels['col_left'][3] = 'new-12';
    $pane = new stdClass();
    $pane->pid = 'new-13';
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
    $display->content['new-13'] = $pane;
    $display->panels['content'][0] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
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
    $display->content['new-14'] = $pane;
    $display->panels['content'][1] = 'new-14';
    $pane = new stdClass();
    $pane->pid = 'new-15';
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
    $display->content['new-15'] = $pane;
    $display->panels['content'][2] = 'new-15';
    $pane = new stdClass();
    $pane->pid = 'new-16';
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
      'context' => 'argument_string_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-16'] = $pane;
    $display->panels['content'][3] = 'new-16';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-16';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_books'] = $page;

  return $pages;

}
