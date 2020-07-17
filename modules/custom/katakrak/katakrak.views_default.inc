<?php

/**
 * @file
 * katakrak.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function katakrak_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'imagenes_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Imagenes admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Imagenes admin';
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
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/imagen">Crear imagen</a>';
  $handler->display->display_options['header']['area']['format'] = 'sinopsis';
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Campo: Nodequeue: Add/remove links */
  $handler->display->display_options['fields']['nodequeue_links']['id'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['table'] = 'node';
  $handler->display->display_options['fields']['nodequeue_links']['field'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['label'] = 'Promocionar';
  /* Campo: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Editar';
  /* Campo: Nodo: Foto */
  $handler->display->display_options['fields']['field_imagen']['id'] = 'field_imagen';
  $handler->display->display_options['fields']['field_imagen']['table'] = 'field_data_field_imagen';
  $handler->display->display_options['fields']['field_imagen']['field'] = 'field_imagen';
  $handler->display->display_options['fields']['field_imagen']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_imagen']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Campo: Nodequeue: Add/remove links */
  $handler->display->display_options['fields']['nodequeue_links_1']['id'] = 'nodequeue_links_1';
  $handler->display->display_options['fields']['nodequeue_links_1']['table'] = 'node';
  $handler->display->display_options['fields']['nodequeue_links_1']['field'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links_1']['label'] = 'Queue';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Nodo: Páginas (field_libro_paginas) */
  $handler->display->display_options['sorts']['field_libro_paginas_value']['id'] = 'field_libro_paginas_value';
  $handler->display->display_options['sorts']['field_libro_paginas_value']['table'] = 'field_data_field_libro_paginas';
  $handler->display->display_options['sorts']['field_libro_paginas_value']['field'] = 'field_libro_paginas_value';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'imagen' => 'imagen',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Nodo: Etiqueta (field_imagen_etiqueta) */
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['id'] = 'field_imagen_etiqueta_tid';
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['table'] = 'field_data_field_imagen_etiqueta';
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['field'] = 'field_imagen_etiqueta_tid';
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['expose']['operator_id'] = 'field_imagen_etiqueta_tid_op';
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['expose']['label'] = 'Etiqueta';
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['expose']['operator'] = 'field_imagen_etiqueta_tid_op';
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['expose']['identifier'] = 'field_imagen_etiqueta_tid';
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_imagen_etiqueta_tid']['vocabulary'] = 'tags';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/imagenes';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Imagenes';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['imagenes_admin'] = array(
    t('Master'),
    t('Imagenes admin'),
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
    t('<a href="/node/add/imagen">Crear imagen</a>'),
    t('Title'),
    t('Language'),
    t('Promocionar'),
    t('Editar'),
    t('Foto'),
    t('Queue'),
    t('Etiqueta'),
    t('Page'),
  );
  $export['imagenes_admin'] = $view;

  return $export;
}
