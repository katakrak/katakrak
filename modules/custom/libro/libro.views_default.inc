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
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_product_peso' => 'field_product_peso',
    'commerce_price' => 'commerce_price',
    'commerce_stock' => 'commerce_stock',
    'field_libro_ean' => 'field_libro_ean',
    'field_libro_estado' => 'field_libro_estado',
    'field_libro_portada' => 'field_libro_portada',
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
      'sortable' => 0,
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
  );
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['id'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['table'] = 'field_data_field_libro_producto';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['field'] = 'field_libro_producto_product_id';
  $handler->display->display_options['relationships']['field_libro_producto_product_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Commerce Product: Peso */
  $handler->display->display_options['fields']['field_product_peso']['id'] = 'field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['table'] = 'field_data_field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['field'] = 'field_product_peso';
  $handler->display->display_options['fields']['field_product_peso']['relationship'] = 'field_libro_producto_product_id';
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = 'Precio';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Commerce Product: Stock */
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
  /* Field: Content: Ean */
  $handler->display->display_options['fields']['field_libro_ean']['id'] = 'field_libro_ean';
  $handler->display->display_options['fields']['field_libro_ean']['table'] = 'field_data_field_libro_ean';
  $handler->display->display_options['fields']['field_libro_ean']['field'] = 'field_libro_ean';
  /* Field: Content: Estado */
  $handler->display->display_options['fields']['field_libro_estado']['id'] = 'field_libro_estado';
  $handler->display->display_options['fields']['field_libro_estado']['table'] = 'field_data_field_libro_estado';
  $handler->display->display_options['fields']['field_libro_estado']['field'] = 'field_libro_estado';
  /* Field: Content: Portada */
  $handler->display->display_options['fields']['field_libro_portada']['id'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['table'] = 'field_data_field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['field'] = 'field_libro_portada';
  $handler->display->display_options['fields']['field_libro_portada']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_libro_portada']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
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
  /* Filter criterion: Commerce Product: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_libro_producto_product_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Ean (field_libro_ean:format) */
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
  /* Filter criterion: Content: Estado (field_libro_estado) */
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/books';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Libros';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['libros_admin'] = $view;

  return $export;
}
