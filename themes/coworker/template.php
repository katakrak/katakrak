<?php

include_once 'includes/custom_menu.inc';
include_once 'includes/custom_form.inc';

function _coworker_add_css() {

  $theme_path = path_to_theme();
  $css_files = array(
      'style.css',
      'css/tipsy.css',
      'css/bootstrap.css',
      'css/font-dinnext.css',
      'css/font-calibri.css',
      'css/font.css',
      'css/prettyPhoto.css',
      'css/coworker.css',
      'katakrak.css',
  );
  foreach ($css_files as $css_file) {
    drupal_add_css($theme_path . '/' . $css_file);
  }
  $theme_color = variable_get('coworker_theme_color', 'coworker');

  drupal_add_css($theme_color);
  if (theme_get_setting('enable_responsive')) {
    drupal_add_css($theme_path . '/css/responsive.css');
  }
}

function coworker_preprocess_html(&$variables) {

  $theme_path = path_to_theme();
  _coworker_add_css();


  drupal_add_html_head(
          array(
      '#tag' => 'meta',
      '#attributes' => array(
          'name' => 'viewport',
          'content' => 'width=device-width, initial-scale=1',
      ),
          ), 'centum:viewport_meta'
  );
}

function coworker_preprocess_page(&$vars) {

  // navigation
  $custom_main_menu = _custom_main_menu_render_superfish();
  if (!empty($custom_main_menu['content'])) {
    $vars['navigation'] = $custom_main_menu['content'];
  }
  $vars['rentina_logo'] = theme_get_setting('rentina_logo', 'coworker');

  if (module_exists('search')) {
    $seach_block_form = drupal_get_form('search_block_form');
    $vars['search_block'] = drupal_render($seach_block_form);
  }
}

function coworker_preprocess_search_result(&$vars) {
  
  if ($vars['result']['entity_type'] == 'node') {
    $node = node_load($vars['result']['node']->entity_id);
    if ($node->field_libro_portada) {
      $vars['cover'] = l(theme('image_style', array(
        'style_name' => 'search_result_cover',
        'path' => $node->field_libro_portada['und'][0]['uri']
      )), 'node/'.$node->nid, array('html' => TRUE));
    }
    else {
      $vars['cover'] = theme('image_style', array(
        'style_name' => 'search_result_cover',
        'path' => 'public://image-not-found.gif'
      ));
    }
    $vars['node'] = $node;
  }
}

function coworker_format_comma_field($field_category, $node, $limit = NULL) {

  if (module_exists('i18n_taxonomy')) {
    $language = i18n_language();
  }

  $category_arr = array();
  $category = '';
  $field = field_get_items('node', $node, $field_category);

  if (!empty($field)) {
    foreach ($field as $item) {
      $term = taxonomy_term_load($item['tid']);


      if ($term) {
        if (module_exists('i18n_taxonomy')) {
          $term_name = i18n_taxonomy_term_name($term, $language->language);

          // $term_desc = tagclouds_i18n_taxonomy_term_description($term, $language->language);
        } else {
          $term_name = $term->name;
          //$term_desc = $term->description;
        }

        $category_arr[] = l($term_name, 'taxonomy/term/' . $item['tid']);
      }

      if ($limit) {
        if (count($category_arr) == $limit) {
          $category = implode(', ', $category_arr);
          return $category;
        }
      }
    }
  }
  $category = implode(', ', $category_arr);

  return $category;
}

function coworker_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="nav nav-tabs primary">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="nav nav-pills secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

function coworker_status_messages(&$variables) {
  $display = $variables['display'];
  $output = '';

  $message_info = array(
      'status' => array(
          'heading' => 'Status message',
          'class' => 'success',
      ),
      'error' => array(
          'heading' => 'Error message',
          'class' => 'error',
      ),
      'warning' => array(
          'heading' => 'Warning message',
          'class' => '',
      ),
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    if (empty($message_info[$type]['class'])) {
      $message_info[$type]['class'] = 'status';
    }
    $message_class = $type != 'warning' ? $message_info[$type]['class'] : 'warning';
    $output .= "<div class=\"alert alert-block alert-$message_class fade in\">\n<a class=\"close\" data-dismiss=\"alert\" href=\"#\">&times;</a>";
    if (!empty($message_info[$type]['heading'])) {
      $output .= '<h2 class="element-invisible">' . $message_info[$type]['heading'] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    } else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
  }
  return $output;
}

function coworker_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb) && (count($breadcrumb) > 1)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode(' » ', $breadcrumb) . '</div>';
    return $output;
  }
}
