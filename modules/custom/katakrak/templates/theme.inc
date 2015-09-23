<?php

/**
 * Implementation of template preprocess for the view.
 */
function template_preprocess_katakrak_grid_plugin_style(&$vars) {
  $view     = $vars['view'];
  $options  = $view->style_plugin->options;
  $horizontal = ($options['alignment'] === 'horizontal');

  // Split items by rows and columns.
  //$vars['items'] = _katakrak_view_grid_split_rows($vars, $columns, $horizontal);
  $vars['columns_lg'] = 12 / $options['columns_lg'];
  $vars['columns_md'] = 12 / $options['columns_md'];
  $vars['columns_sm'] = 12 / $options['columns_sm'];
  $vars['columns_xs'] = 12 / $options['columns_xs'];
  
  if (!$horizontal) {
    $vars['items_lg'] = _views_bootstrap_split_rows($vars, $options['columns_lg'], $horizontal);
    $vars['items_md'] = _views_bootstrap_split_rows($vars, $options['columns_md'], $horizontal);
    $vars['items_sm'] = _views_bootstrap_split_rows($vars, $options['columns_sm'], $horizontal);
    $vars['items_xs'] = _views_bootstrap_split_rows($vars, $options['columns_xs'], $horizontal);
  }
}


function _katakrak_view_grid_split_rows($vars, $columns, $horizontal) {
  
}