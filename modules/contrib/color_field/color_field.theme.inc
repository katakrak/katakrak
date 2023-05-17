<?php

/**
 * @file
 * Theming functions.
 */

/**
 * Formats a spectrum color field widget.
 */
function theme_color_field_spectrum_widget($vars) {
  $element = $vars['element'];
  $field_settings = $element['#field_settings'];
  $instance_settings = $element['#instance_settings'];

  // Javascript settings.
  $settings = array();
  $settings['id'] = $element['rgb']['#id'];
  $settings['show_input'] = ($instance_settings['show_input']) ? TRUE : FALSE;
  $settings['show_palette'] = ($instance_settings['show_palette']) ? TRUE : FALSE;
  $settings['show_palette_only'] = ($instance_settings['show_palette_only']) ? TRUE : FALSE;
  $settings['show_buttons'] = ($instance_settings['show_buttons']) ? TRUE : FALSE;
  $settings['allow_empty'] = ($instance_settings['allow_empty']) ? TRUE : FALSE;

  $default_colors = $instance_settings['palette'];
  preg_match_all("/#[0-9a-fA-F]{6}/", $default_colors, $default_colors, PREG_SET_ORDER);
  if (!empty($default_colors)) {
    foreach ($default_colors as $color) {
      $settings['palette'][] = $color[0];
    }
  }

  // Enable or not opacity capture.
  if ($field_settings['opacity']) {
    $settings['show_alpha'] = TRUE;
    // Hide the opacity field.
    // @todo find a better way.
    $element['opacity']['#attributes']['class'] = array('element-invisible');
    unset($element['opacity']['#title']);
    unset($element['opacity']['#description']);
  } else {
    $settings['show_alpha'] = FALSE;
  }

  // Attach javascript and style.
  $element['rgb']['#attached'] = array(
    // Add Spectrum color picker.
    'library' => array(array('color_field', 'bgrins-spectrum')),
    'js' => array(
      drupal_get_path('module', 'color_field') . '/color_field_spectrum_color_picker/color_field_spectrum_color_picker.jquery.js',
      array(
        'data' => array('color_field_spectrum' => array('#' . $element['rgb']['#id'] => $settings)),
        'type' => 'setting',
      ),
    ),
  );

  $output = '';
  $output .= '<div class="link-field-subrow clearfix">';
  $output .= '<div class="link-field-title color-field-column">' . drupal_render($element['rgb']) . '</div>';

  if ($field_settings['opacity']) {
    $output .= '<div class="link-field-title color-field-column">' . drupal_render($element['opacity']) . '</div>';
  }

  $output .= '</div>';
  $output .= drupal_render_children($element);
  return $output;
}

/**
 * Formats a default color field widget.
 */
function theme_color_field_simple_widget($vars) {
  $element = $vars['element'];

  // Add library.
  drupal_add_library('color_field', 'jquery-simple-color');

  // Javascript settings.
  $settings = array();
  $settings['id'] = $element['rgb']['#id'];
  $settings['cell_width'] = (isset($field['settings']['cell_width']) && $field['settings']['cell_width'] != '') ? (int) $field['settings']['cell_width'] : 10;
  $settings['cell_height'] = (isset($field['settings']['cell_height']) && $field['settings']['cell_height'] != '') ? (int) $field['settings']['cell_height'] : 10;
  $settings['cell_margin'] = (isset($field['settings']['cell_margin']) && $field['settings']['cell_margin'] != '') ? (int) $field['settings']['cell_margin'] : 1;
  $settings['box_width'] = (isset($field['settings']['box_width']) && $field['settings']['box_width'] != '') ? $field['settings']['box_width'] . 'px' : '115px';
  $settings['box_height'] = (isset($field['settings']['box_height']) && $field['settings']['box_height'] != '') ? $field['settings']['box_height'] . 'px' : '20px';
  $settings['columns'] = (isset($field['settings']['columns']) && $field['settings']['columns'] != '') ? $field['settings']['columns'] : '16';

  // Attach javascript and style.
  $element['rgb']['#attached'] = array(
    'js' => array(
      drupal_get_path('module', 'color_field') . '/color_field_jquery_simple_color/color_field_jquery_simple_color.jquery.js',
      array(
        'data' => array('color_field_jquery_simple_color' => array('#' . $element['rgb']['#id'] => $settings)),
        'type' => 'setting',
      ),
    ),
    'css' => array(drupal_get_path('module', 'color_field') . '/color_field_jquery_simple_color/color_field_jquery_simple_color.css'),
  );

  $output = '';
  $output .= '<div class="link-field-subrow clearfix">';
  $output .= '<div class="link-field-title color-field-column">' . drupal_render($element['rgb']) . '</div>';

  if (isset($element['opacity'])) {
    $output .= '<div class="link-field-title color-field-column">' . drupal_render($element['opacity']) . '</div>';
  }

  $output .= '</div>';
  $output .= drupal_render_children($element);
  return $output;
}

/**
 * Formats a default color field widget.
 */
function theme_color_field_default_widget($vars) {
  $element = $vars['element'];

  // Javascript settings.
  $settings = array();
  $settings['id'] = $element['rgb']['#id'];
  $settings['divid'] = 'div-' . $element['rgb']['#id'];
  $settings['value'] = (isset($element['#value']['rgb'])) ? $element['#value']['rgb'] : '';
  $default_colors = (isset($element['#instance_settings']['default_colors'])) ? $element['#instance_settings']['default_colors'] : '';
  preg_match_all("/#[0-9a-fA-F]{6}/", $default_colors, $default_colors, PREG_SET_ORDER);
  foreach ($default_colors as $color) {
    $settings['colors'][] = $color[0];
  }

  // Attach javascript and style.
  $element['rgb']['#attached'] = array(
    'js' => array(
      drupal_get_path('module', 'color_field') . '/color_field_default_widget/color_field.js',
      drupal_get_path('module', 'color_field') . '/color_field_default_widget/color_field.jquery.js',
      array(
        'data' => array('color_field' => array('#' . $settings['id'] => $settings)),
        'type' => 'setting',
      ),
    ),
    'css' => array(drupal_get_path('module', 'color_field') . '/color_field_default_widget/color_field.css'),
  );

  $element['rgb']['#title'] = (isset($element['rgb']['#title'])) ? $element['rgb']['#title'] : '';
  $element['rgb']['#suffix'] = '<label> ' . $element['rgb']['#title'] . ' </label><div id=div-' . $settings['id'] . '></div><div class="description">' . $element['rgb']['#description'] . '</div>';
  unset($element['rgb']['#title']);
  unset($element['rgb']['#description']);

  // Hide the input field.
  $element['rgb']['#attributes']['class'] = array('element-invisible');

  $output = '';
  $output .= '<div class="link-field-subrow clearfix">';
  $output .= '<div class="link-field-title color-field-column">' . drupal_render($element['rgb']) . '</div>';

  if (isset($element['opacity'])) {
    $output .= '<div class="link-field-title color-field-column">' . drupal_render($element['opacity']) . '</div>';
  }

  $output .= '</div>';
  $output .= drupal_render_children($element);
  return $output;
}

/**
 * Formats a plain color field widget.
 */
function theme_color_field_plain_text($vars) {
  drupal_add_css(drupal_get_path('module', 'color_field') . '/color_field_plain_text/color_field.css');
  $element = $vars['element'];
  $output = '';
  $output .= '<div class="link-field-subrow clearfix">';
  $output .= '<div class="link-field-title color-field-column">' . drupal_render($element['rgb']) . '</div>';
  if (isset($element['opacity'])) {
    $output .= '<div class="link-field-title color-field-column">' . drupal_render($element['opacity']) . '</div>';
  }
  $output .= '</div>';
  $output .= drupal_render_children($element);
  return $output;
}

/**
 * Formats a color swatch.
 */
function theme_color_swatch($variables) {
  $color = check_plain($variables['color']);
  $width = check_plain($variables['width']);
  $height = check_plain($variables['height']);
  return '<div class="color-swatch" style="background-color: ' . $color .  '; width: ' . $width . 'px; height: ' . $height . 'px;"></div>';
}
