<?php

/**
 * @file
 * katakrak_itinerarios.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function katakrak_itinerarios_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'itinerarios';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Itinerarios';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Itinerarios de lectura';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'katakrak_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Contenido: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Contenido: Color */
  $handler->display->display_options['fields']['field_itinerario_color']['id'] = 'field_itinerario_color';
  $handler->display->display_options['fields']['field_itinerario_color']['table'] = 'field_data_field_itinerario_color';
  $handler->display->display_options['fields']['field_itinerario_color']['field'] = 'field_itinerario_color';
  $handler->display->display_options['fields']['field_itinerario_color']['label'] = '';
  $handler->display->display_options['fields']['field_itinerario_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_itinerario_color']['element_label_colon'] = FALSE;
  /* Campo: Contenido: Número */
  $handler->display->display_options['fields']['field_itinerario_linea']['id'] = 'field_itinerario_linea';
  $handler->display->display_options['fields']['field_itinerario_linea']['table'] = 'field_data_field_itinerario_linea';
  $handler->display->display_options['fields']['field_itinerario_linea']['field'] = 'field_itinerario_linea';
  $handler->display->display_options['fields']['field_itinerario_linea']['label'] = '';
  $handler->display->display_options['fields']['field_itinerario_linea']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_itinerario_linea']['alter']['text'] = '<div class="linea-[field_itinerario_linea-value]">
<div class="circle">
  <div class="circle-[field_itinerario_linea-value]">
  </div>
</div>
</div>';
  $handler->display->display_options['fields']['field_itinerario_linea']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_itinerario_linea']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_itinerario_linea']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_itinerario_linea']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Contenido: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Contenido: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenido: Idioma */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'itinerario' => 'itinerario',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Página */
  $handler = $view->new_display('page', 'Página', 'itinerarios');
  $handler->display->display_options['path'] = 'itinerarios';
  $translatables['itinerarios'] = array(
    t('Master'),
    t('Itinerarios de lectura'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Nid'),
    t('<div class="linea-[field_itinerario_linea-value]">
<div class="circle">
  <div class="circle-[field_itinerario_linea-value]">
  </div>
</div>
</div>'),
    t('Block'),
    t('Página'),
  );
  $export['itinerarios'] = $view;

  $view = new view();
  $view->name = 'itinerarios_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Itinerarios admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Itinerarios admin';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_event_date' => 'field_event_date',
    'field_event_type' => 'field_event_type',
    'field_event_image' => 'field_event_image',
    'language' => 'language',
    'nodequeue_links' => 'nodequeue_links',
  );
  $handler->display->display_options['style_options']['default'] = 'field_event_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nodequeue_links' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Encabezado: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/event">Crear evento</a>';
  $handler->display->display_options['header']['area']['format'] = 'sinopsis';
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Contenido: Idioma */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Campo: Contenido: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Editar';
  /* Campo: Contenido: Número */
  $handler->display->display_options['fields']['field_itinerario_linea']['id'] = 'field_itinerario_linea';
  $handler->display->display_options['fields']['field_itinerario_linea']['table'] = 'field_data_field_itinerario_linea';
  $handler->display->display_options['fields']['field_itinerario_linea']['field'] = 'field_itinerario_linea';
  $handler->display->display_options['fields']['field_itinerario_linea']['label'] = 'Línea';
  $handler->display->display_options['fields']['field_itinerario_linea']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_itinerario_linea']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Campo: Contenido: Color */
  $handler->display->display_options['fields']['field_itinerario_color']['id'] = 'field_itinerario_color';
  $handler->display->display_options['fields']['field_itinerario_color']['table'] = 'field_data_field_itinerario_color';
  $handler->display->display_options['fields']['field_itinerario_color']['field'] = 'field_itinerario_color';
  $handler->display->display_options['fields']['field_itinerario_color']['alter']['text'] = '<span class="color-swatch" style="background-color: [field_itinerario_color-rgb]; width: 50px; height: 50px; border-radius: 50%;">[field_itinerario_linea]</span>';
  $handler->display->display_options['fields']['field_itinerario_color']['type'] = 'color_field_swatch';
  $handler->display->display_options['fields']['field_itinerario_color']['settings'] = array(
    'width' => '30',
    'height' => '30',
  );
  /* Sort criterion: Contenido: Fecha de modificación */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Contenido: Páginas (field_libro_paginas) */
  $handler->display->display_options['sorts']['field_libro_paginas_value']['id'] = 'field_libro_paginas_value';
  $handler->display->display_options['sorts']['field_libro_paginas_value']['table'] = 'field_data_field_libro_paginas';
  $handler->display->display_options['sorts']['field_libro_paginas_value']['field'] = 'field_libro_paginas_value';
  /* Filter criterion: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'itinerario' => 'itinerario',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/ibilbideak';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Itinerarios';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['itinerarios_admin'] = array(
    t('Master'),
    t('Itinerarios admin'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('<a href="/node/add/event">Crear evento</a>'),
    t('Título'),
    t('Idioma'),
    t('Editar'),
    t('Línea'),
    t('Color'),
    t('<span class="color-swatch" style="background-color: [field_itinerario_color-rgb]; width: 50px; height: 50px; border-radius: 50%;">[field_itinerario_linea]</span>'),
    t('Page'),
    t('more'),
  );
  $export['itinerarios_admin'] = $view;

  return $export;
}
