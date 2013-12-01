<?php

/**
 * Implementation of template preprocess for the view.
 */
function template_preprocess_katakrak_agenda_grid_plugin_style(&$vars) {
  if ($columns = $vars['view']->style_options['columns']) {
    $vars['column_type'] = 12 / $vars['view']->style_options['columns'];
    
    $i = 0;
    $row_num = 0;
    dpm($vars['view']->style_options);
    while ($i < $vars['view']->style_options['first_row_columns']) {
      $i++;
      $vars['columns'][$row_num]['rows'][] = array_shift($vars['rows']);
      $vars['columns'][$row_num]['column_type'] = 12 / $vars['view']->style_options['first_row_columns'];
    }
    
    $row_num++;
    $i = 0;
    while ($i < $vars['view']->style_options['second_row_columns']) {
      $i++;
      $vars['columns'][$row_num]['rows'][] = array_shift($vars['rows']);
      $vars['columns'][$row_num]['column_type'] = 12 / $vars['view']->style_options['second_row_columns'];
    }
    
    $row_num++;
    foreach ($vars['rows'] as $i => $row) {
      $vars['columns'][$row_num]['rows'][] = array_shift($vars['rows']);
      $vars['columns'][$row_num]['column_type'] = 12 / $vars['view']->style_options['columns'];
      if (count($vars['columns'][$row_num]['rows']) == 3)
        $row_num++;
    }
  }
}
