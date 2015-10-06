<?php
/**
 * @file
 * katakrak_agenda.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function katakrak_agenda_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_3';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Ciclos',
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
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'ciclo' => 'ciclo',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b66d7860-63d6-4753-8dd2-e78a706af61d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-287f4f55-a379-4649-b70e-7f377c4eb2db';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'taxonomy_term:field_ciclo_imagen';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => 'content',
      ),
      'context' => 'argument_term_1',
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
    $pane->uuid = '287f4f55-a379-4649-b70e-7f377c4eb2db';
    $display->content['new-287f4f55-a379-4649-b70e-7f377c4eb2db'] = $pane;
    $display->panels['middle'][0] = 'new-287f4f55-a379-4649-b70e-7f377c4eb2db';
    $pane = new stdClass();
    $pane->pid = 'new-b5c75887-4ec8-49bc-84b5-a839fc1db26c';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'taxonomy_term:field_adjunto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_term_1',
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
    $pane->uuid = 'b5c75887-4ec8-49bc-84b5-a839fc1db26c';
    $display->content['new-b5c75887-4ec8-49bc-84b5-a839fc1db26c'] = $pane;
    $display->panels['middle'][1] = 'new-b5c75887-4ec8-49bc-84b5-a839fc1db26c';
    $pane = new stdClass();
    $pane->pid = 'new-264f8297-1e4c-48aa-83c9-f3e6c11e8fa9';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'views-libros-libros_grupo_lectura';
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
    $pane->uuid = '264f8297-1e4c-48aa-83c9-f3e6c11e8fa9';
    $display->content['new-264f8297-1e4c-48aa-83c9-f3e6c11e8fa9'] = $pane;
    $display->panels['middle'][2] = 'new-264f8297-1e4c-48aa-83c9-f3e6c11e8fa9';
    $pane = new stdClass();
    $pane->pid = 'new-d1e882fa-1681-44d8-b310-48a76000d5ba';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'views-agenda-citas_ciclo';
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
    $pane->uuid = 'd1e882fa-1681-44d8-b310-48a76000d5ba';
    $display->content['new-d1e882fa-1681-44d8-b310-48a76000d5ba'] = $pane;
    $display->panels['middle'][3] = 'new-d1e882fa-1681-44d8-b310-48a76000d5ba';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_3'] = $handler;

  return $export;
}
