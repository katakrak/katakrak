<?php
/**
 * @file
 * libro.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function libro_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'libros';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Libros';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Libros';
  $handler->display->display_options['css_class'] = 'book-page-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'views_content_cache';
  $handler->display->display_options['cache']['results_min_lifespan'] = '-1';
  $handler->display->display_options['cache']['results_max_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_min_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_max_lifespan'] = '21600';
  $handler->display->display_options['cache']['keys'] = array(
    'comment' => array(
      'changed' => 0,
    ),
    'node' => array(
      'libro' => 'libro',
      'article' => 0,
      'page' => 0,
      'blog' => 0,
      'boletin' => 0,
      'event' => 0,
      'itinerario' => 0,
      'portfolio' => 0,
      'simplenews' => 0,
      'webform' => 0,
    ),
    'node_only' => array(
      'node_changed' => 'node_changed',
    ),
  );
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Contenido: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'libro_portada' => 'libro_portada',
    'evento_portada' => 0,
    'producto_kafeta_destacado' => 0,
    'libros_destacados' => 0,
    'evento_home' => 0,
  );
  /* Campo: Contenido: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Contenido: Portada */
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
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'book-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Contenido: Autor */
  $handler->display->display_options['fields']['field_libro_autores']['id'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['field'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['label'] = '';
  $handler->display->display_options['fields']['field_libro_autores']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_libro_autores']['element_class'] = 'book-author';
  $handler->display->display_options['fields']['field_libro_autores']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_autores']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_libro_autores']['delta_offset'] = '0';
  /* Campo: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = '';
  $handler->display->display_options['fields']['add_to_cart_form']['exclude'] = TRUE;
  $handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 0;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Contenido: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'libros_destacados' => 'libros_destacados',
    'evento_portada' => 0,
    'libro_portada' => 0,
    'producto_kafeta_destacado' => 0,
    'evento_home' => 0,
  );
  $handler->display->display_options['path'] = 'libros';

  /* Display: Books block home */
  $handler = $view->new_display('block', 'Books block home', 'book_block_home');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Libros por categoria */
  $handler = $view->new_display('block', 'Libros por categoria', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Contenido: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Contenido: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Contenido: Sección (field_libro_categoria) */
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['id'] = 'field_libro_categoria_tid';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['table'] = 'field_data_field_libro_categoria';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['field'] = 'field_libro_categoria_tid';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['summary_options']['items_per_page'] = '25';
  $translatables['libros'] = array(
    t('Master'),
    t('Libros'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('Products referenced by field_libro_producto'),
    t('queue'),
    t('Nid'),
    t('Page'),
    t('more'),
    t('Books block home'),
    t('Libros por categoria'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Todo(s)'),
  );
  $export['libros'] = $view;

  $view = new view();
  $view->name = 'libros_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Libros admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Libros admin';
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
  /* Relationship: Contenido: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Contenido: Subtitulo */
  $handler->display->display_options['fields']['field_libro_subtitulo']['id'] = 'field_libro_subtitulo';
  $handler->display->display_options['fields']['field_libro_subtitulo']['table'] = 'field_data_field_libro_subtitulo';
  $handler->display->display_options['fields']['field_libro_subtitulo']['field'] = 'field_libro_subtitulo';
  $handler->display->display_options['fields']['field_libro_subtitulo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_libro_subtitulo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_subtitulo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_libro_subtitulo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_libro_subtitulo']['field_api_classes'] = TRUE;
  /* Campo: Commerce Product: Peso */
  $handler->display->display_options['fields']['field_product_peso']['id'] = 'field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['table'] = 'field_data_field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['field'] = 'field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['field_product_peso']['click_sort_column'] = 'weight';
  /* Campo: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = 'Precio';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Campo: Commerce Product: Stock */
  $handler->display->display_options['fields']['commerce_stock']['id'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['field'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['commerce_stock']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Campo: Contenido: Ean */
  $handler->display->display_options['fields']['field_libro_ean']['id'] = 'field_libro_ean';
  $handler->display->display_options['fields']['field_libro_ean']['table'] = 'field_data_field_libro_ean';
  $handler->display->display_options['fields']['field_libro_ean']['field'] = 'field_libro_ean';
  /* Campo: Contenido: Estado */
  $handler->display->display_options['fields']['field_libro_estado']['id'] = 'field_libro_estado';
  $handler->display->display_options['fields']['field_libro_estado']['table'] = 'field_data_field_libro_estado';
  $handler->display->display_options['fields']['field_libro_estado']['field'] = 'field_libro_estado';
  /* Campo: Contenido: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Campo: Contenido: Autor */
  $handler->display->display_options['fields']['field_libro_autores']['id'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['field'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['delta_offset'] = '0';
  /* Campo: Contenido: Año */
  $handler->display->display_options['fields']['field_libro_year']['id'] = 'field_libro_year';
  $handler->display->display_options['fields']['field_libro_year']['table'] = 'field_data_field_libro_year';
  $handler->display->display_options['fields']['field_libro_year']['field'] = 'field_libro_year';
  $handler->display->display_options['fields']['field_libro_year']['type'] = 'taxonomy_term_reference_plain';
  /* Campo: Nodequeue: Add/remove links */
  $handler->display->display_options['fields']['nodequeue_links']['id'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['table'] = 'node';
  $handler->display->display_options['fields']['nodequeue_links']['field'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['label'] = 'Promocionar';
  /* Sort criterion: Contenido: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Contenido: Páginas (field_libro_paginas) */
  $handler->display->display_options['sorts']['field_libro_paginas_value']['id'] = 'field_libro_paginas_value';
  $handler->display->display_options['sorts']['field_libro_paginas_value']['table'] = 'field_data_field_libro_paginas';
  $handler->display->display_options['sorts']['field_libro_paginas_value']['field'] = 'field_libro_paginas_value';
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
    'libro' => 'libro',
  );
  /* Filter criterion: Commerce Product: SKU */
  $handler->display->display_options['filters']['sku']['id'] = 'sku';
  $handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['sku']['field'] = 'sku';
  $handler->display->display_options['filters']['sku']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['sku']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['label'] = 'GESLIB ID';
  $handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
  $handler->display->display_options['filters']['sku']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Commerce Product: Stock (commerce_stock) */
  $handler->display->display_options['filters']['commerce_stock_value']['id'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['filters']['commerce_stock_value']['field'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['commerce_stock_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['commerce_stock_value']['expose']['operator_id'] = 'commerce_stock_value_op';
  $handler->display->display_options['filters']['commerce_stock_value']['expose']['label'] = 'Stock';
  $handler->display->display_options['filters']['commerce_stock_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['commerce_stock_value']['expose']['operator'] = 'commerce_stock_value_op';
  $handler->display->display_options['filters']['commerce_stock_value']['expose']['identifier'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Commerce Product: Título */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Título';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Contenido: Ean (field_libro_ean:format) */
  $handler->display->display_options['filters']['field_libro_ean_format']['id'] = 'field_libro_ean_format';
  $handler->display->display_options['filters']['field_libro_ean_format']['table'] = 'field_data_field_libro_ean';
  $handler->display->display_options['filters']['field_libro_ean_format']['field'] = 'field_libro_ean_format';
  $handler->display->display_options['filters']['field_libro_ean_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['operator_id'] = 'field_libro_ean_format_op';
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['label'] = 'EAN';
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['operator'] = 'field_libro_ean_format_op';
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['identifier'] = 'field_libro_ean_format';
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Contenido: Estado (field_libro_estado) */
  $handler->display->display_options['filters']['field_libro_estado_value']['id'] = 'field_libro_estado_value';
  $handler->display->display_options['filters']['field_libro_estado_value']['table'] = 'field_data_field_libro_estado';
  $handler->display->display_options['filters']['field_libro_estado_value']['field'] = 'field_libro_estado_value';
  $handler->display->display_options['filters']['field_libro_estado_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['operator_id'] = 'field_libro_estado_value_op';
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['label'] = 'Estado';
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['operator'] = 'field_libro_estado_value_op';
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['identifier'] = 'field_libro_estado_value';
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Contenido: Dilve (field_libro_dilve) */
  $handler->display->display_options['filters']['field_libro_dilve_value']['id'] = 'field_libro_dilve_value';
  $handler->display->display_options['filters']['field_libro_dilve_value']['table'] = 'field_data_field_libro_dilve';
  $handler->display->display_options['filters']['field_libro_dilve_value']['field'] = 'field_libro_dilve_value';
  $handler->display->display_options['filters']['field_libro_dilve_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_libro_dilve_value']['expose']['operator_id'] = 'field_libro_dilve_value_op';
  $handler->display->display_options['filters']['field_libro_dilve_value']['expose']['label'] = 'Dilve';
  $handler->display->display_options['filters']['field_libro_dilve_value']['expose']['operator'] = 'field_libro_dilve_value_op';
  $handler->display->display_options['filters']['field_libro_dilve_value']['expose']['identifier'] = 'field_libro_dilve_value';
  $handler->display->display_options['filters']['field_libro_dilve_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Commerce Product: Peso (field_product_peso:weight) */
  $handler->display->display_options['filters']['field_product_peso_weight']['id'] = 'field_product_peso_weight';
  $handler->display->display_options['filters']['field_product_peso_weight']['table'] = 'field_data_field_product_peso';
  $handler->display->display_options['filters']['field_product_peso_weight']['field'] = 'field_product_peso_weight';
  $handler->display->display_options['filters']['field_product_peso_weight']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['field_product_peso_weight']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_product_peso_weight']['expose']['operator_id'] = 'field_product_peso_weight_op';
  $handler->display->display_options['filters']['field_product_peso_weight']['expose']['label'] = 'Peso';
  $handler->display->display_options['filters']['field_product_peso_weight']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_product_peso_weight']['expose']['operator'] = 'field_product_peso_weight_op';
  $handler->display->display_options['filters']['field_product_peso_weight']['expose']['identifier'] = 'field_product_peso_weight';
  $handler->display->display_options['filters']['field_product_peso_weight']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Contenido: Editorial (field_libro_editorial) */
  $handler->display->display_options['filters']['field_libro_editorial_tid']['id'] = 'field_libro_editorial_tid';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['table'] = 'field_data_field_libro_editorial';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['field'] = 'field_libro_editorial_tid';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['value'] = '';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_libro_editorial_tid']['expose']['operator_id'] = 'field_libro_editorial_tid_op';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['expose']['label'] = 'Editorial';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['expose']['operator'] = 'field_libro_editorial_tid_op';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['expose']['identifier'] = 'field_libro_editorial_tid';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_libro_editorial_tid']['vocabulary'] = 'editoriales';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/books';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Libros';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Contenido: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'libros_destacados' => 'libros_destacados',
    'evento_portada' => 0,
    'libro_portada' => 0,
    'producto_kafeta_destacado' => 0,
    'evento_home' => 0,
  );
  $handler->display->display_options['path'] = 'admin/content/books/current';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Libros de la semana';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['libros_admin'] = array(
    t('Master'),
    t('Libros admin'),
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
    t('Products referenced by field_libro_producto'),
    t('Título'),
    t('Subtitulo'),
    t('Peso'),
    t('Precio'),
    t('Stock'),
    t('Ean'),
    t('Estado'),
    t('Portada'),
    t('Autor'),
    t('Año'),
    t('Promocionar'),
    t('GESLIB ID'),
    t('EAN'),
    t('Dilve'),
    t('Editorial'),
    t('Page'),
    t('more'),
    t('queue'),
  );
  $export['libros_admin'] = $view;

  return $export;
}
