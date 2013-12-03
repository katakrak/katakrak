<?php
/**
 * @file
 * katakrak_potemkin.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function katakrak_potemkin_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dvds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'DVDs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'DVDs admin';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
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
    'field_dvd_caratula' => 'field_dvd_caratula',
    'field_dvd_starring' => 'field_dvd_starring',
    'field_dvd_ano' => 'field_dvd_ano',
    'field_dvd_director' => 'field_dvd_director',
    'field_dvd_duracion' => 'field_dvd_duracion',
    'field_dvd_formato' => 'field_dvd_formato',
    'field_dvd_genero' => 'field_dvd_genero',
    'field_dvd_pais' => 'field_dvd_pais',
  );
  $handler->display->display_options['style_options']['default'] = 'field_dvd_ano';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dvd_caratula' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dvd_starring' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dvd_ano' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dvd_director' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dvd_duracion' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dvd_formato' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dvd_genero' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dvd_pais' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Contenido: Actores/Actrices */
  $handler->display->display_options['fields']['field_dvd_starring']['id'] = 'field_dvd_starring';
  $handler->display->display_options['fields']['field_dvd_starring']['table'] = 'field_data_field_dvd_starring';
  $handler->display->display_options['fields']['field_dvd_starring']['field'] = 'field_dvd_starring';
  $handler->display->display_options['fields']['field_dvd_starring']['label'] = 'Actores';
  $handler->display->display_options['fields']['field_dvd_starring']['delta_offset'] = '0';
  /* Campo: Contenido: Año */
  $handler->display->display_options['fields']['field_dvd_ano']['id'] = 'field_dvd_ano';
  $handler->display->display_options['fields']['field_dvd_ano']['table'] = 'field_data_field_dvd_ano';
  $handler->display->display_options['fields']['field_dvd_ano']['field'] = 'field_dvd_ano';
  $handler->display->display_options['fields']['field_dvd_ano']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Campo: Contenido: Director */
  $handler->display->display_options['fields']['field_dvd_director']['id'] = 'field_dvd_director';
  $handler->display->display_options['fields']['field_dvd_director']['table'] = 'field_data_field_dvd_director';
  $handler->display->display_options['fields']['field_dvd_director']['field'] = 'field_dvd_director';
  $handler->display->display_options['fields']['field_dvd_director']['delta_offset'] = '0';
  /* Campo: Contenido: Duración */
  $handler->display->display_options['fields']['field_dvd_duracion']['id'] = 'field_dvd_duracion';
  $handler->display->display_options['fields']['field_dvd_duracion']['table'] = 'field_data_field_dvd_duracion';
  $handler->display->display_options['fields']['field_dvd_duracion']['field'] = 'field_dvd_duracion';
  $handler->display->display_options['fields']['field_dvd_duracion']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Campo: Contenido: Formato */
  $handler->display->display_options['fields']['field_dvd_formato']['id'] = 'field_dvd_formato';
  $handler->display->display_options['fields']['field_dvd_formato']['table'] = 'field_data_field_dvd_formato';
  $handler->display->display_options['fields']['field_dvd_formato']['field'] = 'field_dvd_formato';
  /* Campo: Contenido: Género */
  $handler->display->display_options['fields']['field_dvd_genero']['id'] = 'field_dvd_genero';
  $handler->display->display_options['fields']['field_dvd_genero']['table'] = 'field_data_field_dvd_genero';
  $handler->display->display_options['fields']['field_dvd_genero']['field'] = 'field_dvd_genero';
  /* Campo: Contenido: Pais */
  $handler->display->display_options['fields']['field_dvd_pais']['id'] = 'field_dvd_pais';
  $handler->display->display_options['fields']['field_dvd_pais']['table'] = 'field_data_field_dvd_pais';
  $handler->display->display_options['fields']['field_dvd_pais']['field'] = 'field_dvd_pais';
  /* Campo: Contenido: Caratula */
  $handler->display->display_options['fields']['field_dvd_caratula']['id'] = 'field_dvd_caratula';
  $handler->display->display_options['fields']['field_dvd_caratula']['table'] = 'field_data_field_dvd_caratula';
  $handler->display->display_options['fields']['field_dvd_caratula']['field'] = 'field_dvd_caratula';
  $handler->display->display_options['fields']['field_dvd_caratula']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_dvd_caratula']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Sort criterion: Contenido: Fecha de modificación */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dvd' => 'dvd',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Contenido: Año (field_dvd_ano) */
  $handler->display->display_options['filters']['field_dvd_ano_value']['id'] = 'field_dvd_ano_value';
  $handler->display->display_options['filters']['field_dvd_ano_value']['table'] = 'field_data_field_dvd_ano';
  $handler->display->display_options['filters']['field_dvd_ano_value']['field'] = 'field_dvd_ano_value';
  $handler->display->display_options['filters']['field_dvd_ano_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dvd_ano_value']['expose']['operator_id'] = 'field_dvd_ano_value_op';
  $handler->display->display_options['filters']['field_dvd_ano_value']['expose']['label'] = 'Año';
  $handler->display->display_options['filters']['field_dvd_ano_value']['expose']['operator'] = 'field_dvd_ano_value_op';
  $handler->display->display_options['filters']['field_dvd_ano_value']['expose']['identifier'] = 'field_dvd_ano_value';
  $handler->display->display_options['filters']['field_dvd_ano_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Contenido: Director (field_dvd_director) */
  $handler->display->display_options['filters']['field_dvd_director_tid']['id'] = 'field_dvd_director_tid';
  $handler->display->display_options['filters']['field_dvd_director_tid']['table'] = 'field_data_field_dvd_director';
  $handler->display->display_options['filters']['field_dvd_director_tid']['field'] = 'field_dvd_director_tid';
  $handler->display->display_options['filters']['field_dvd_director_tid']['value'] = '';
  $handler->display->display_options['filters']['field_dvd_director_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dvd_director_tid']['expose']['operator_id'] = 'field_dvd_director_tid_op';
  $handler->display->display_options['filters']['field_dvd_director_tid']['expose']['label'] = 'Director';
  $handler->display->display_options['filters']['field_dvd_director_tid']['expose']['operator'] = 'field_dvd_director_tid_op';
  $handler->display->display_options['filters']['field_dvd_director_tid']['expose']['identifier'] = 'field_dvd_director_tid';
  $handler->display->display_options['filters']['field_dvd_director_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_dvd_director_tid']['vocabulary'] = 'movie_stars';
  /* Filter criterion: Contenido: Pais (field_dvd_pais) */
  $handler->display->display_options['filters']['field_dvd_pais_value']['id'] = 'field_dvd_pais_value';
  $handler->display->display_options['filters']['field_dvd_pais_value']['table'] = 'field_data_field_dvd_pais';
  $handler->display->display_options['filters']['field_dvd_pais_value']['field'] = 'field_dvd_pais_value';
  $handler->display->display_options['filters']['field_dvd_pais_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dvd_pais_value']['expose']['operator_id'] = 'field_dvd_pais_value_op';
  $handler->display->display_options['filters']['field_dvd_pais_value']['expose']['label'] = 'Pais';
  $handler->display->display_options['filters']['field_dvd_pais_value']['expose']['operator'] = 'field_dvd_pais_value_op';
  $handler->display->display_options['filters']['field_dvd_pais_value']['expose']['identifier'] = 'field_dvd_pais_value';
  $handler->display->display_options['filters']['field_dvd_pais_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Contenido: Título */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Título';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/dvds';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'DVDs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['dvds'] = array(
    t('Master'),
    t('DVDs admin'),
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
    t('Título'),
    t('Actores'),
    t('Año'),
    t('Director'),
    t('Duración'),
    t('Formato'),
    t('Género'),
    t('Pais'),
    t('Caratula'),
    t('Page'),
  );
  $export['dvds'] = $view;

  return $export;
}
