<?php
/**
 * @file
 * katakrak_editorial.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function katakrak_editorial_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'editorial';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Editorial';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Editorial';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'katakrak_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['style_options']['columns_md'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'libros_editorial' => 'libros_editorial',
    'evento_home' => 0,
    'producto_kafeta_destacado' => 0,
    'blog_portada' => 0,
    'libros_recomendados' => 0,
  );
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'cover_home',
    'image_link' => 'content',
  );
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'book-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Nodo: Autor */
  $handler->display->display_options['fields']['field_libro_ed_autor']['id'] = 'field_libro_ed_autor';
  $handler->display->display_options['fields']['field_libro_ed_autor']['table'] = 'field_data_field_libro_ed_autor';
  $handler->display->display_options['fields']['field_libro_ed_autor']['field'] = 'field_libro_ed_autor';
  $handler->display->display_options['fields']['field_libro_ed_autor']['label'] = '';
  $handler->display->display_options['fields']['field_libro_ed_autor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_ed_autor']['delta_offset'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'libro_ed' => 'libro_ed',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'editorial';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Editorial';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Libros de Autor */
  $handler = $view->new_display('block', 'Libros de Autor', 'libros_autor');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Libros del autor';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'book_medium',
    'image_link' => 'content',
  );
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'book-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Nodo: Autor (field_libro_ed_autor) */
  $handler->display->display_options['arguments']['field_libro_ed_autor_nid']['id'] = 'field_libro_ed_autor_nid';
  $handler->display->display_options['arguments']['field_libro_ed_autor_nid']['table'] = 'field_data_field_libro_ed_autor';
  $handler->display->display_options['arguments']['field_libro_ed_autor_nid']['field'] = 'field_libro_ed_autor_nid';
  $handler->display->display_options['arguments']['field_libro_ed_autor_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_libro_ed_autor_nid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_libro_ed_autor_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_libro_ed_autor_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_libro_ed_autor_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_libro_ed_autor_nid']['summary_options']['items_per_page'] = '25';
  $translatables['editorial'] = array(
    t('Master'),
    t('Editorial'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('queue'),
    t('Page'),
    t('Libros de Autor'),
    t('Libros del autor'),
    t('Todo(s)'),
  );
  $export['editorial'] = $view;

  $view = new view();
  $view->name = 'editorial_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Editorial Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Editorial';
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
    'field_libro_subtitulo' => 'field_libro_subtitulo',
    'field_product_peso' => 'field_product_peso',
    'commerce_price' => 'commerce_price',
    'commerce_stock' => 'commerce_stock',
    'field_libro_ean' => 'field_libro_ean',
    'field_libro_estado' => 'field_libro_estado',
    'field_libro_portada' => 'field_libro_portada',
    'field_libro_autores' => 'field_libro_autores',
    'field_libro_year' => 'field_libro_year',
    'nodequeue_links' => 'nodequeue_links',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_libro_subtitulo' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_product_peso' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_stock' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_libro_ean' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_libro_estado' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_libro_portada' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_libro_autores' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_libro_year' => array(
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
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/libro-ed">Añadir libro</a>';
  $handler->display->display_options['header']['area']['format'] = 'sinopsis';
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Nodo: Subtitulo */
  $handler->display->display_options['fields']['field_libro_subtitulo']['id'] = 'field_libro_subtitulo';
  $handler->display->display_options['fields']['field_libro_subtitulo']['table'] = 'field_data_field_libro_subtitulo';
  $handler->display->display_options['fields']['field_libro_subtitulo']['field'] = 'field_libro_subtitulo';
  $handler->display->display_options['fields']['field_libro_subtitulo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_libro_subtitulo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_subtitulo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_libro_subtitulo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_libro_subtitulo']['field_api_classes'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Campo: Nodo: Año */
  $handler->display->display_options['fields']['field_libro_year']['id'] = 'field_libro_year';
  $handler->display->display_options['fields']['field_libro_year']['table'] = 'field_data_field_libro_year';
  $handler->display->display_options['fields']['field_libro_year']['field'] = 'field_libro_year';
  $handler->display->display_options['fields']['field_libro_year']['label'] = 'Urtea';
  $handler->display->display_options['fields']['field_libro_year']['type'] = 'taxonomy_term_reference_plain';
  /* Campo: Nodequeue: Add/remove links */
  $handler->display->display_options['fields']['nodequeue_links']['id'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['table'] = 'node';
  $handler->display->display_options['fields']['nodequeue_links']['field'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['label'] = '';
  $handler->display->display_options['fields']['nodequeue_links']['element_label_colon'] = FALSE;
  /* Campo: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'libro_ed' => 'libro_ed',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/editorial';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Editorial';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['editorial_admin'] = array(
    t('Master'),
    t('Editorial'),
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
    t('<a href="/node/add/libro-ed">Añadir libro</a>'),
    t('Title'),
    t('Subtitulo'),
    t('Portada'),
    t('Urtea'),
    t('Page'),
    t('more'),
  );
  $export['editorial_admin'] = $view;

  return $export;
}
