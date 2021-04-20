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
  $view->human_name = 'Tienda Online';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tienda';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'katakrak_grid_plugin_style';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodo: Referenced products */
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
    'recomendados_narrativa' => 'recomendados_narrativa',
    'evento_home' => 0,
    'producto_kafeta_destacado' => 0,
    'blog_portada' => 0,
    'libros_recomendados' => 0,
    'libros_editorial' => 0,
    'autore_editorial_eus' => 0,
    'autores_editorial' => 0,
    'traductores_cas' => 0,
    'traductores_eus' => 0,
    'libros_mas_vendidos' => 0,
    'grupos_de_lectura' => 0,
    'recomendados_ensayo' => 0,
  );
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['empty'] = '<i class="fa fa-book fa-26x book-cover-not-found"></i>';
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
  /* Campo: Nodo: Autor Geslib */
  $handler->display->display_options['fields']['field_libro_autores']['id'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['field'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['label'] = '';
  $handler->display->display_options['fields']['field_libro_autores']['element_type'] = 'h4';
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
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Nodo: Estado (field_libro_estado) */
  $handler->display->display_options['filters']['field_libro_estado_value']['id'] = 'field_libro_estado_value';
  $handler->display->display_options['filters']['field_libro_estado_value']['table'] = 'field_data_field_libro_estado';
  $handler->display->display_options['filters']['field_libro_estado_value']['field'] = 'field_libro_estado_value';
  $handler->display->display_options['filters']['field_libro_estado_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_libro_estado_value']['value'] = array(
    2 => '2',
    3 => '3',
    8 => '8',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Librería';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '3';
  $handler->display->display_options['style_options']['columns_lg'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'card_book_smgrid';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Referenced products */
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
    'recomendados_ensayo' => 'recomendados_ensayo',
    'evento_home' => 0,
    'producto_kafeta_destacado' => 0,
    'blog_portada' => 0,
    'libros_recomendados' => 0,
    'libros_editorial' => 0,
    'autore_editorial_eus' => 0,
    'autores_editorial' => 0,
    'traductores_cas' => 0,
    'traductores_eus' => 0,
    'libros_mas_vendidos' => 0,
    'grupos_de_lectura' => 0,
    'recomendados_narrativa' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['alter']['path'] = 'node/[nid]?utm_source=tienda&utm_medium=web&utm_content=imagen&utm_campaign=libros';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['empty'] = '<i class="fa fa-book fa-26x book-cover-not-found"></i>';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'cover_home',
    'image_link' => '',
  );
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]?utm_source=tienda&utm_medium=web&utm_content=titulo&utm_campaign=libros';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'book-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Campo: Producto de Comercio: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = 'Precio';
  $handler->display->display_options['fields']['commerce_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['path'] = 'tienda';
  $handler->display->display_options['menu']['title'] = 'Librería';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Books block home */
  $handler = $view->new_display('block', 'Books block home', 'book_block_home');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Librería';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'book-block-home book-recomendados-view ';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Entra en la tienda online';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'katakrak_grid_plugin_style';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'libros_recomendados' => 'libros_recomendados',
    'evento_home' => 0,
    'libro_portada' => 0,
    'libros_destacados' => 0,
    'producto_kafeta_destacado' => 0,
    'blog_portada' => 0,
    'imagenes_kantina' => 0,
  );
  /* Relationship: Nodo: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['label'] = 'Producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['alter']['path'] = 'node/[nid]?utm_source=portada&utm_medium=web&utm_content=imagen&utm_campaign=libros';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['empty'] = '<i class="fa fa-book fa-26x book-cover-not-found"></i>';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'cover_home',
    'image_link' => '',
  );
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Producto de Comercio: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
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

  /* Display: Libros de evento */
  $handler = $view->new_display('block', 'Libros de evento', 'books_related_event');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Libros relacionados';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Libro (field_event_libro) */
  $handler->display->display_options['relationships']['field_event_libro_nid']['id'] = 'field_event_libro_nid';
  $handler->display->display_options['relationships']['field_event_libro_nid']['table'] = 'field_data_field_event_libro';
  $handler->display->display_options['relationships']['field_event_libro_nid']['field'] = 'field_event_libro_nid';
  $handler->display->display_options['relationships']['field_event_libro_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_event_libro_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_event_libro_nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['relationship'] = 'field_event_libro_nid';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_libro_portada']['alter']['path'] = 'node/[nid]?utm_source=libro_agenda&utm_medium=web&utm_content=imagen&utm_campaign=libros';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'book_medium',
    'image_link' => '',
  );
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_event_libro_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]?utm_source=libro_agenda&utm_medium=web&utm_content=titulo&utm_campaign=libros';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'book-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Libros de boletin */
  $handler = $view->new_display('block', 'Libros de boletin', 'books_related_boletin');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Libros relacionados';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'katakrak_grid_plugin_style';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['style_options']['columns_md'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Libros (field_boletin_libros) */
  $handler->display->display_options['relationships']['field_boletin_libros_nid']['id'] = 'field_boletin_libros_nid';
  $handler->display->display_options['relationships']['field_boletin_libros_nid']['table'] = 'field_data_field_boletin_libros';
  $handler->display->display_options['relationships']['field_boletin_libros_nid']['field'] = 'field_boletin_libros_nid';
  $handler->display->display_options['relationships']['field_boletin_libros_nid']['label'] = 'libros';
  $handler->display->display_options['relationships']['field_boletin_libros_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_boletin_libros_nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['relationship'] = 'field_boletin_libros_nid';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_libro_portada']['alter']['path'] = 'node/[nid]?utm_source=libro_agenda&utm_medium=web&utm_content=imagen&utm_campaign=libros';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'book_thumbnail',
    'image_link' => '',
  );
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_boletin_libros_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]?utm_source=libro_agenda&utm_medium=web&utm_content=titulo&utm_campaign=libros';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'book-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Libros grupo de lectura */
  $handler = $view->new_display('block', 'Libros grupo de lectura', 'libros_grupo_lectura');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Libros';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Libros (field_ciclo_libros) - reverse (to Nodo) */
  $handler->display->display_options['relationships']['reverse_field_ciclo_libros_node']['id'] = 'reverse_field_ciclo_libros_node';
  $handler->display->display_options['relationships']['reverse_field_ciclo_libros_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_ciclo_libros_node']['field'] = 'reverse_field_ciclo_libros_node';
  $handler->display->display_options['relationships']['reverse_field_ciclo_libros_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['empty'] = '<i class="fa fa-book fa-26x book-cover-not-found"></i>';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'book_irakurle_taldea',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_ciclo_libros_node';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Libros relacionados por autor */
  $handler = $view->new_display('block', 'Libros relacionados por autor', 'libros_rel_autor');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'katakrak_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['empty'] = '<i class="fa fa-book fa-26x book-cover-not-found"></i>';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'editorial_page',
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
  /* Campo: Nodo: Autor Geslib */
  $handler->display->display_options['fields']['field_libro_autores']['id'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['field'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['label'] = '';
  $handler->display->display_options['fields']['field_libro_autores']['element_type'] = 'h4';
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
  $handler->display->display_options['fields']['add_to_cart_form']['button_text'] = 'Comprar';
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'product';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Nodo: Autor Geslib (field_libro_autores) */
  $handler->display->display_options['arguments']['field_libro_autores_tid']['id'] = 'field_libro_autores_tid';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['field'] = 'field_libro_autores_tid';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;

  /* Display: Libros relacionados por categoría */
  $handler = $view->new_display('block', 'Libros relacionados por categoría', 'libros_rel_cat');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'katakrak_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['empty'] = '<i class="fa fa-book fa-26x book-cover-not-found"></i>';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'editorial_page',
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
  /* Campo: Nodo: Autor Geslib */
  $handler->display->display_options['fields']['field_libro_autores']['id'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['field'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['label'] = '';
  $handler->display->display_options['fields']['field_libro_autores']['element_type'] = 'h4';
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
  $handler->display->display_options['fields']['add_to_cart_form']['button_text'] = 'Comprar';
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'product';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Nodo: Sección (field_libro_categoria) */
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['id'] = 'field_libro_categoria_tid';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['table'] = 'field_data_field_libro_categoria';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['field'] = 'field_libro_categoria_tid';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_libro_categoria_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Producto de Comercio: Stock (commerce_stock) */
  $handler->display->display_options['filters']['commerce_stock_value']['id'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['filters']['commerce_stock_value']['field'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['commerce_stock_value']['operator'] = '>';
  $handler->display->display_options['filters']['commerce_stock_value']['value']['value'] = '0';
  /* Filter criterion: Nodo: Portada (field_libro_portada:fid) */
  $handler->display->display_options['filters']['field_libro_portada_fid']['id'] = 'field_libro_portada_fid';
  $handler->display->display_options['filters']['field_libro_portada_fid']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['filters']['field_libro_portada_fid']['field'] = 'field_libro_portada_fid';
  $handler->display->display_options['filters']['field_libro_portada_fid']['operator'] = 'not empty';

  /* Display: Libros por categoria */
  $handler = $view->new_display('block', 'Libros por categoria', 'books_category');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '3';
  $handler->display->display_options['style_options']['columns_lg'] = '2';
  $handler->display->display_options['style_options']['column_class'] = 'col';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'card_book_smgrid';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_libro_portada']['alter']['path'] = 'node/[nid]?utm_source=pagina_categorias&utm_medium=web&utm_content=imagen&utm_campaign=libros';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['empty'] = '<i class="fa fa-book fa-26x book-cover-not-found"></i>';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'cover_home',
    'image_link' => '',
  );
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]?utm_source=pagina_categorias&utm_medium=web&utm_content=titulo&utm_campaign=libros';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'book-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Campo: Nodo: Autor Geslib */
  $handler->display->display_options['fields']['field_libro_autores']['id'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['field'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['label'] = '';
  $handler->display->display_options['fields']['field_libro_autores']['element_type'] = 'h4';
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
  $handler->display->display_options['fields']['add_to_cart_form']['button_text'] = 'Comprar';
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'product';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Nodo: Sección (field_libro_categoria) */
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

  /* Display: Libros por autor landing */
  $handler = $view->new_display('block', 'Libros por autor landing', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Libros autor landing';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '3';
  $handler->display->display_options['style_options']['columns_lg'] = '2';
  $handler->display->display_options['style_options']['column_class'] = 'col';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'card_book_smgrid';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = '';
  $handler->display->display_options['fields']['field_libro_portada']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_libro_portada']['alter']['path'] = 'node/[nid]?utm_source=pagina_categorias&utm_medium=web&utm_content=imagen&utm_campaign=libros';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['empty'] = '<i class="fa fa-book fa-26x book-cover-not-found"></i>';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'cover_home',
    'image_link' => '',
  );
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]?utm_source=pagina_categorias&utm_medium=web&utm_content=titulo&utm_campaign=libros';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'book-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Campo: Nodo: Autor Geslib */
  $handler->display->display_options['fields']['field_libro_autores']['id'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['field'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['label'] = '';
  $handler->display->display_options['fields']['field_libro_autores']['element_type'] = 'h4';
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
  $handler->display->display_options['fields']['add_to_cart_form']['button_text'] = 'Comprar';
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'product';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Nodo: Autor Geslib (field_libro_autores) */
  $handler->display->display_options['arguments']['field_libro_autores_tid']['id'] = 'field_libro_autores_tid';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['field'] = 'field_libro_autores_tid';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_libro_autores_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Recomendados narrativa */
  $handler = $view->new_display('block', 'Recomendados narrativa', 'recomendados_narrativa');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['clear_columns'] = FALSE;
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '3';
  $handler->display->display_options['style_options']['columns_lg'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'card_book_smgrid';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Referenced products */
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
    'recomendados_narrativa' => 'recomendados_narrativa',
    'evento_home' => 0,
    'producto_kafeta_destacado' => 0,
    'blog_portada' => 0,
    'libros_recomendados' => 0,
    'libros_editorial' => 0,
    'autore_editorial_eus' => 0,
    'autores_editorial' => 0,
    'traductores_cas' => 0,
    'traductores_eus' => 0,
    'libros_mas_vendidos' => 0,
    'grupos_de_lectura' => 0,
    'recomendados_ensayo' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['block_description'] = 'Recomendados narrativa';

  /* Display: Recomendados infantil */
  $handler = $view->new_display('block', 'Recomendados infantil', 'recomendados_infantil');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['clear_columns'] = FALSE;
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '3';
  $handler->display->display_options['style_options']['columns_lg'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'card_book_smgrid';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Referenced products */
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
    'recomendados_infantil' => 'recomendados_infantil',
    'evento_home' => 0,
    'producto_kafeta_destacado' => 0,
    'blog_portada' => 0,
    'libros_recomendados' => 0,
    'libros_editorial' => 0,
    'autore_editorial_eus' => 0,
    'autores_editorial' => 0,
    'traductores_cas' => 0,
    'traductores_eus' => 0,
    'grupos_de_lectura' => 0,
    'recomendados_ensayo' => 0,
    'recomendados_narrativa' => 0,
    'recomendados_comic' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['block_description'] = 'Recomendados infantil';

  /* Display: Recomendados comic */
  $handler = $view->new_display('block', 'Recomendados comic', 'recomendados_comic');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['clear_columns'] = FALSE;
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '3';
  $handler->display->display_options['style_options']['columns_lg'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'card_book_smgrid';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Referenced products */
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
    'recomendados_comic' => 'recomendados_comic',
    'evento_home' => 0,
    'producto_kafeta_destacado' => 0,
    'blog_portada' => 0,
    'libros_recomendados' => 0,
    'libros_editorial' => 0,
    'autore_editorial_eus' => 0,
    'autores_editorial' => 0,
    'traductores_cas' => 0,
    'traductores_eus' => 0,
    'grupos_de_lectura' => 0,
    'recomendados_ensayo' => 0,
    'recomendados_narrativa' => 0,
    'recomendados_infantil' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['block_description'] = 'Recomendados comic';
  $translatables['libros'] = array(
    t('Master'),
    t('Tienda'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('Products referenced by field_libro_producto'),
    t('queue'),
    t('Nid'),
    t('<i class="fa fa-book fa-26x book-cover-not-found"></i>'),
    t('Page'),
    t('Librería'),
    t('more'),
    t('Precio'),
    t('Books block home'),
    t('Entra en la tienda online'),
    t('Producto'),
    t('Libros de evento'),
    t('Libros relacionados'),
    t('field_event_libro'),
    t('Todo(s)'),
    t('Libros de boletin'),
    t('libros'),
    t('Libros grupo de lectura'),
    t('Libros'),
    t('field_ciclo_libros'),
    t('Libros relacionados por autor'),
    t('Libros relacionados por categoría'),
    t('Libros por categoria'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Libros por autor landing'),
    t('Libros autor landing'),
    t('Recomendados narrativa'),
    t('Recomendados infantil'),
    t('Recomendados comic'),
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
  $handler->display->display_options['title'] = 'Liburuak';
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
    'field_libro_editorial' => 'field_libro_editorial',
    'nodequeue_links' => 'nodequeue_links',
    'edit_node' => 'edit_node',
    'view_product' => 'view_product',
  );
  $handler->display->display_options['style_options']['class'] = '';
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
      'sortable' => 1,
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
    'field_libro_editorial' => array(
      'sortable' => 0,
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
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_product' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Nodo: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
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
  /* Campo: Producto de Comercio: Peso */
  $handler->display->display_options['fields']['field_product_peso']['id'] = 'field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['table'] = 'field_data_field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['field'] = 'field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['field_product_peso']['click_sort_column'] = 'weight';
  /* Campo: Producto de Comercio: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = 'Prezioa';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Campo: Producto de Comercio: Stock */
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
  /* Campo: Nodo: Ean */
  $handler->display->display_options['fields']['field_libro_ean']['id'] = 'field_libro_ean';
  $handler->display->display_options['fields']['field_libro_ean']['table'] = 'field_data_field_libro_ean';
  $handler->display->display_options['fields']['field_libro_ean']['field'] = 'field_libro_ean';
  /* Campo: Nodo: Estado */
  $handler->display->display_options['fields']['field_libro_estado']['id'] = 'field_libro_estado';
  $handler->display->display_options['fields']['field_libro_estado']['table'] = 'field_data_field_libro_estado';
  $handler->display->display_options['fields']['field_libro_estado']['field'] = 'field_libro_estado';
  $handler->display->display_options['fields']['field_libro_estado']['label'] = 'Egoera';
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Campo: Nodo: Autor Geslib */
  $handler->display->display_options['fields']['field_libro_autores']['id'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['table'] = 'field_data_field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['field'] = 'field_libro_autores';
  $handler->display->display_options['fields']['field_libro_autores']['delta_offset'] = '0';
  /* Campo: Nodo: Año */
  $handler->display->display_options['fields']['field_libro_year']['id'] = 'field_libro_year';
  $handler->display->display_options['fields']['field_libro_year']['table'] = 'field_data_field_libro_year';
  $handler->display->display_options['fields']['field_libro_year']['field'] = 'field_libro_year';
  $handler->display->display_options['fields']['field_libro_year']['label'] = 'Urtea';
  $handler->display->display_options['fields']['field_libro_year']['type'] = 'taxonomy_term_reference_plain';
  /* Campo: Nodo: Editorial */
  $handler->display->display_options['fields']['field_libro_editorial']['id'] = 'field_libro_editorial';
  $handler->display->display_options['fields']['field_libro_editorial']['table'] = 'field_data_field_libro_editorial';
  $handler->display->display_options['fields']['field_libro_editorial']['field'] = 'field_libro_editorial';
  /* Campo: Nodequeue: Add/remove links */
  $handler->display->display_options['fields']['nodequeue_links']['id'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['table'] = 'node';
  $handler->display->display_options['fields']['nodequeue_links']['field'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['label'] = '';
  $handler->display->display_options['fields']['nodequeue_links']['element_label_colon'] = FALSE;
  /* Campo: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Campo: Commerce Product: Link */
  $handler->display->display_options['fields']['view_product']['id'] = 'view_product';
  $handler->display->display_options['fields']['view_product']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['view_product']['field'] = 'view_product';
  $handler->display->display_options['fields']['view_product']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['view_product']['label'] = 'Editar producto';
  $handler->display->display_options['fields']['view_product']['text'] = 'editar producto';
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
    'libro' => 'libro',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Product: SKU */
  $handler->display->display_options['filters']['sku']['id'] = 'sku';
  $handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['sku']['field'] = 'sku';
  $handler->display->display_options['filters']['sku']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['sku']['group'] = 1;
  $handler->display->display_options['filters']['sku']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['label'] = 'GESLIB ID';
  $handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
  $handler->display->display_options['filters']['sku']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Producto de Comercio: Stock (commerce_stock) */
  $handler->display->display_options['filters']['commerce_stock_value']['id'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['filters']['commerce_stock_value']['field'] = 'commerce_stock_value';
  $handler->display->display_options['filters']['commerce_stock_value']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['commerce_stock_value']['group'] = 1;
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
  /* Filter criterion: Commerce Product: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Título';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Nodo: Ean (field_libro_ean:format) */
  $handler->display->display_options['filters']['field_libro_ean_format']['id'] = 'field_libro_ean_format';
  $handler->display->display_options['filters']['field_libro_ean_format']['table'] = 'field_data_field_libro_ean';
  $handler->display->display_options['filters']['field_libro_ean_format']['field'] = 'field_libro_ean_format';
  $handler->display->display_options['filters']['field_libro_ean_format']['group'] = 1;
  $handler->display->display_options['filters']['field_libro_ean_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['operator_id'] = 'field_libro_ean_format_op';
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['label'] = 'EAN';
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['operator'] = 'field_libro_ean_format_op';
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['identifier'] = 'field_libro_ean_format';
  $handler->display->display_options['filters']['field_libro_ean_format']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Nodo: Estado (field_libro_estado) */
  $handler->display->display_options['filters']['field_libro_estado_value']['id'] = 'field_libro_estado_value';
  $handler->display->display_options['filters']['field_libro_estado_value']['table'] = 'field_data_field_libro_estado';
  $handler->display->display_options['filters']['field_libro_estado_value']['field'] = 'field_libro_estado_value';
  $handler->display->display_options['filters']['field_libro_estado_value']['group'] = 1;
  $handler->display->display_options['filters']['field_libro_estado_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['operator_id'] = 'field_libro_estado_value_op';
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['label'] = 'Egoera';
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['operator'] = 'field_libro_estado_value_op';
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['identifier'] = 'field_libro_estado_value';
  $handler->display->display_options['filters']['field_libro_estado_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Nodo: Dilve (field_libro_dilve) */
  $handler->display->display_options['filters']['field_libro_dilve_value']['id'] = 'field_libro_dilve_value';
  $handler->display->display_options['filters']['field_libro_dilve_value']['table'] = 'field_data_field_libro_dilve';
  $handler->display->display_options['filters']['field_libro_dilve_value']['field'] = 'field_libro_dilve_value';
  $handler->display->display_options['filters']['field_libro_dilve_value']['group'] = 1;
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
  /* Filter criterion: Producto de Comercio: Peso (field_product_peso:weight) */
  $handler->display->display_options['filters']['field_product_peso_weight']['id'] = 'field_product_peso_weight';
  $handler->display->display_options['filters']['field_product_peso_weight']['table'] = 'field_data_field_product_peso';
  $handler->display->display_options['filters']['field_product_peso_weight']['field'] = 'field_product_peso_weight';
  $handler->display->display_options['filters']['field_product_peso_weight']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['field_product_peso_weight']['group'] = 1;
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
  /* Filter criterion: Nodo: Editorial (field_libro_editorial) */
  $handler->display->display_options['filters']['field_libro_editorial_tid']['id'] = 'field_libro_editorial_tid';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['table'] = 'field_data_field_libro_editorial';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['field'] = 'field_libro_editorial_tid';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['value'] = '';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_libro_editorial_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_libro_editorial_tid']['expose']['operator_id'] = 'field_libro_editorial_tid_op';
  $handler->display->display_options['filters']['field_libro_editorial_tid']['expose']['label'] = 'Argitaletxea';
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

  /* Display: Libros de la semana */
  $handler = $view->new_display('page', 'Libros de la semana', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Libros de la semana';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodo: Referenced products */
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

  /* Display: Libros por isbn */
  $handler = $view->new_display('block', 'Libros por isbn', 'libro_por_isbn');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Nodo: Isbn (field_libro_isbn) */
  $handler->display->display_options['arguments']['field_libro_isbn_value']['id'] = 'field_libro_isbn_value';
  $handler->display->display_options['arguments']['field_libro_isbn_value']['table'] = 'field_data_field_libro_isbn';
  $handler->display->display_options['arguments']['field_libro_isbn_value']['field'] = 'field_libro_isbn_value';
  $handler->display->display_options['arguments']['field_libro_isbn_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_libro_isbn_value']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_libro_isbn_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_libro_isbn_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_libro_isbn_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_libro_isbn_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_libro_isbn_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Libros sin portada */
  $handler = $view->new_display('block', 'Libros sin portada', 'libros_sin_portada');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Nodo: Portada (field_libro_portada:fid) */
  $handler->display->display_options['filters']['field_libro_portada_fid']['id'] = 'field_libro_portada_fid';
  $handler->display->display_options['filters']['field_libro_portada_fid']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['filters']['field_libro_portada_fid']['field'] = 'field_libro_portada_fid';
  $handler->display->display_options['filters']['field_libro_portada_fid']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_libro_portada_fid']['value']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'libro' => 'libro',
  );

  /* Display: Libros por EAN */
  $handler = $view->new_display('block', 'Libros por EAN', 'libros_por_ean');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Nodo: Ean (field_libro_ean) */
  $handler->display->display_options['arguments']['field_libro_ean_value']['id'] = 'field_libro_ean_value';
  $handler->display->display_options['arguments']['field_libro_ean_value']['table'] = 'field_data_field_libro_ean';
  $handler->display->display_options['arguments']['field_libro_ean_value']['field'] = 'field_libro_ean_value';
  $handler->display->display_options['arguments']['field_libro_ean_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_libro_ean_value']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_libro_ean_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_libro_ean_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_libro_ean_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_libro_ean_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_libro_ean_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $translatables['libros_admin'] = array(
    t('Master'),
    t('Liburuak'),
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
    t('Title'),
    t('Subtitulo'),
    t('Peso'),
    t('Prezioa'),
    t('Stock'),
    t('Ean'),
    t('Egoera'),
    t('Portada'),
    t('Autor Geslib'),
    t('Urtea'),
    t('Editorial'),
    t('Editar producto'),
    t('editar producto'),
    t('GESLIB ID'),
    t('Título'),
    t('EAN'),
    t('Dilve'),
    t('Argitaletxea'),
    t('Page'),
    t('more'),
    t('Libros de la semana'),
    t('queue'),
    t('Libros por isbn'),
    t('Nid'),
    t('Todo(s)'),
    t('Libros sin portada'),
    t('Libros por EAN'),
  );
  $export['libros_admin'] = $view;

  $view = new view();
  $view->name = 'libros_blog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Libreria blog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog de librería';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ver el blog de kantina';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Field: Imagen */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'kantina_medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Content: Link to content */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'leer más [+]';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
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
    'blog' => 'blog',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Nodo: Blog_type (field_blog_type) */
  $handler->display->display_options['filters']['field_blog_type_tid']['id'] = 'field_blog_type_tid';
  $handler->display->display_options['filters']['field_blog_type_tid']['table'] = 'field_data_field_blog_type';
  $handler->display->display_options['filters']['field_blog_type_tid']['field'] = 'field_blog_type_tid';
  $handler->display->display_options['filters']['field_blog_type_tid']['value'] = array(
    40849 => '40849',
  );
  $handler->display->display_options['filters']['field_blog_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_blog_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_blog_type_tid']['vocabulary'] = 'blog_type';

  /* Display: Bloque */
  $handler = $view->new_display('block', 'Bloque', 'block_1');
  $translatables['libros_blog'] = array(
    t('Master'),
    t('Blog de librería'),
    t('ver el blog de kantina'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('leer más [+]'),
    t('Bloque'),
    t('more'),
  );
  $export['libros_blog'] = $view;

  $view = new view();
  $view->name = 'productos_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_product';
  $view->human_name = 'Productos Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Productos Admin';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
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
    'product_id' => 'product_id',
    'field_product_peso' => 'field_product_peso',
    'commerce_stock' => 'commerce_stock',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'product_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_product_peso' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_stock' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Campo: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_product'] = 1;
  /* Campo: Commerce Product: Product ID */
  $handler->display->display_options['fields']['product_id']['id'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['product_id']['field'] = 'product_id';
  /* Campo: Producto de Comercio: Peso */
  $handler->display->display_options['fields']['field_product_peso']['id'] = 'field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['table'] = 'field_data_field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['field'] = 'field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['click_sort_column'] = 'weight';
  /* Campo: Producto de Comercio: Stock */
  $handler->display->display_options['fields']['commerce_stock']['id'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['field'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Filter criterion: Commerce Product: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'libro' => 'libro',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/productos';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Productos';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['productos_admin'] = array(
    t('Master'),
    t('Productos Admin'),
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
    t('Title'),
    t('Product ID'),
    t('Peso'),
    t('Stock'),
    t('Page'),
    t('more'),
  );
  $export['productos_admin'] = $view;

  $view = new view();
  $view->name = 'secciones';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Secciones';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'katakrak_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'materias' => 'materias',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;

  /* Display: Secciones movil */
  $handler = $view->new_display('block', 'Secciones movil', 'secciones_block_m');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Field: Imagen */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'seccion',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Campo: Taxonomy term: Rendered Término de taxonomía */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_taxonomy_term';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_type'] = 'h4';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';

  /* Display: Secciones lateral */
  $handler = $view->new_display('block', 'Secciones lateral', 'secciones_lateral');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Secciones';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'hidden-sm hidden-xs';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Taxonomy term: Rendered Término de taxonomía */
  $handler->display->display_options['fields']['rendered_entity_1']['id'] = 'rendered_entity_1';
  $handler->display->display_options['fields']['rendered_entity_1']['table'] = 'views_entity_taxonomy_term';
  $handler->display->display_options['fields']['rendered_entity_1']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_1']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity_1']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'materias' => 'materias',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = 'NULL';
  $handler->display->display_options['filters']['parent']['group'] = 1;
  /* Filter criterion: Término de taxonomía: Mostrar (field_seccion_mostrar) */
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['id'] = 'field_seccion_mostrar_value';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['table'] = 'field_data_field_seccion_mostrar';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['field'] = 'field_seccion_mostrar_value';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Secciones lateral';

  /* Display: Secciones home tienda */
  $handler = $view->new_display('block', 'Secciones home tienda', 'secciones_home_tienda');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['clear_columns'] = FALSE;
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['style_options']['column_class'] = 'mb-2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Pie de página: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="text-center mb-2 mt-2"><a class="btn btn-secondary" href="/cas/tienda/secciones">Ver todas las secciones</a></div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Campo: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Campo: Field: Imagen */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'is-circle';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'materias' => 'materias',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = 'NULL';
  /* Filter criterion: Término de taxonomía: Mostrar en portada (field_seccion_portada) */
  $handler->display->display_options['filters']['field_seccion_portada_value']['id'] = 'field_seccion_portada_value';
  $handler->display->display_options['filters']['field_seccion_portada_value']['table'] = 'field_data_field_seccion_portada';
  $handler->display->display_options['filters']['field_seccion_portada_value']['field'] = 'field_seccion_portada_value';
  $handler->display->display_options['filters']['field_seccion_portada_value']['value'] = array(
    1 => '1',
  );

  /* Display: Secciones home tienda EUS */
  $handler = $view->new_display('block', 'Secciones home tienda EUS', 'secciones_home_tienda_eus');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['clear_columns'] = FALSE;
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['style_options']['column_class'] = 'mb-2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Pie de página: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="text-center mb-2 mt-2"><a class="btn btn-secondary" href="/eus/denda/sailak">Ikusi sail guztiak</a></div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Campo: Field: Imagen */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'is-circle';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Campo: Término de taxonomía: Nombre euskera */
  $handler->display->display_options['fields']['field_nombre_euskera']['id'] = 'field_nombre_euskera';
  $handler->display->display_options['fields']['field_nombre_euskera']['table'] = 'field_data_field_nombre_euskera';
  $handler->display->display_options['fields']['field_nombre_euskera']['field'] = 'field_nombre_euskera';
  $handler->display->display_options['fields']['field_nombre_euskera']['label'] = '';
  $handler->display->display_options['fields']['field_nombre_euskera']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Término de taxonomía: Nombre euskera (field_nombre_euskera) */
  $handler->display->display_options['sorts']['field_nombre_euskera_value']['id'] = 'field_nombre_euskera_value';
  $handler->display->display_options['sorts']['field_nombre_euskera_value']['table'] = 'field_data_field_nombre_euskera';
  $handler->display->display_options['sorts']['field_nombre_euskera_value']['field'] = 'field_nombre_euskera_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'materias' => 'materias',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = 'NULL';
  /* Filter criterion: Término de taxonomía: Mostrar en portada (field_seccion_portada) */
  $handler->display->display_options['filters']['field_seccion_portada_value']['id'] = 'field_seccion_portada_value';
  $handler->display->display_options['filters']['field_seccion_portada_value']['table'] = 'field_data_field_seccion_portada';
  $handler->display->display_options['filters']['field_seccion_portada_value']['field'] = 'field_seccion_portada_value';
  $handler->display->display_options['filters']['field_seccion_portada_value']['value'] = array(
    1 => '1',
  );

  /* Display: Página ES */
  $handler = $view->new_display('page', 'Página ES', 'pagina_secciones');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Secciones';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['clear_columns'] = FALSE;
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['style_options']['column_class'] = 'mb-2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Campo: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Campo: Field: Imagen */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'is-circle is-seccion';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'materias' => 'materias',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = 'NULL';
  /* Filter criterion: Término de taxonomía: Mostrar (field_seccion_mostrar) */
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['id'] = 'field_seccion_mostrar_value';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['table'] = 'field_data_field_seccion_mostrar';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['field'] = 'field_seccion_mostrar_value';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'tienda/secciones';

  /* Display: Página EUS */
  $handler = $view->new_display('page', 'Página EUS', 'pagina_secciones_eus');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Secciones';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['clear_columns'] = FALSE;
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['style_options']['column_class'] = 'mb-2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Campo: Field: Imagen */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Campo: Término de taxonomía: Nombre euskera */
  $handler->display->display_options['fields']['field_nombre_euskera']['id'] = 'field_nombre_euskera';
  $handler->display->display_options['fields']['field_nombre_euskera']['table'] = 'field_data_field_nombre_euskera';
  $handler->display->display_options['fields']['field_nombre_euskera']['field'] = 'field_nombre_euskera';
  $handler->display->display_options['fields']['field_nombre_euskera']['label'] = '';
  $handler->display->display_options['fields']['field_nombre_euskera']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Término de taxonomía: Nombre euskera (field_nombre_euskera) */
  $handler->display->display_options['sorts']['field_nombre_euskera_value']['id'] = 'field_nombre_euskera_value';
  $handler->display->display_options['sorts']['field_nombre_euskera_value']['table'] = 'field_data_field_nombre_euskera';
  $handler->display->display_options['sorts']['field_nombre_euskera_value']['field'] = 'field_nombre_euskera_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'materias' => 'materias',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = 'NULL';
  /* Filter criterion: Término de taxonomía: Mostrar (field_seccion_mostrar) */
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['id'] = 'field_seccion_mostrar_value';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['table'] = 'field_data_field_seccion_mostrar';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['field'] = 'field_seccion_mostrar_value';
  $handler->display->display_options['filters']['field_seccion_mostrar_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'denda/sailak';
  $translatables['secciones'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('Name'),
    t('Secciones movil'),
    t('more'),
    t('Secciones lateral'),
    t('Secciones'),
    t('Secciones home tienda'),
    t('<div class="text-center mb-2 mt-2"><a class="btn btn-secondary" href="/cas/tienda/secciones">Ver todas las secciones</a></div>'),
    t('.'),
    t('Secciones home tienda EUS'),
    t('<div class="text-center mb-2 mt-2"><a class="btn btn-secondary" href="/eus/denda/sailak">Ikusi sail guztiak</a></div>'),
    t('Página ES'),
    t(','),
    t('Página EUS'),
  );
  $export['secciones'] = $view;

  $view = new view();
  $view->name = 'service_libros';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'service_libros';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tienda';
  $handler->display->display_options['css_class'] = 'book-page-view book-recomendados-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'katakrak_grid_plugin_style';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'libros_recomendados' => 'libros_recomendados',
    'evento_home' => 0,
    'libro_portada' => 0,
    'libros_destacados' => 0,
    'producto_kafeta_destacado' => 0,
    'blog_portada' => 0,
  );
  /* Campo: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Campo: Nodo: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['label'] = 'portada';
  $handler->display->display_options['fields']['field_libro_portada']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_libro_portada']['empty'] = '<i class="fa fa-book fa-26x book-cover-not-found"></i>';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'book_thumbnail',
    'image_link' => '',
  );
  /* Campo: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'book-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'service_libros';
  $translatables['service_libros'] = array(
    t('Master'),
    t('Tienda'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('nid'),
    t('portada'),
    t('<i class="fa fa-book fa-26x book-cover-not-found"></i>'),
    t('title'),
    t('Services'),
    t('more'),
  );
  $export['service_libros'] = $view;

  return $export;
}
