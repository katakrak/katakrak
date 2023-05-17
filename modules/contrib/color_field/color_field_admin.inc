<?php

/**
 * @file
 * Date administration code.
 */

/**
 * Helper function for color_field_field_settings_form().
 */
function _color_field_field_settings_form($field, $instance, $has_data) {
  $field_settings = $field['settings'];

  $form = array();

  $form['opacity'] = array(
    '#type' => 'checkbox',
    '#title' => t('Record opacity'),
    '#default_value' => $field_settings['opacity'],
    '#description' => t('If checked, the opacity will be recorded.'),
  );
  return $form;
}

/**
 * Helper function for color_field_field_instance_settings_form().
 */
function _color_field_field_instance_settings_form($field, $instance) {
  $widget = $instance['widget'];
  $instance_settings = $instance['settings'];

  $form = array();

  switch ($widget['type']) {
    // Spectrum widget.
    case 'color_field_spectrum_widget':
      $form['show_input'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show Input'),
        '#default_value' => $instance_settings['show_input'],
        '#description' => t('Allow free form typing.'),
      );
      $form['show_palette'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show Palette'),
        '#default_value' => $instance_settings['show_palette'],
        '#description' => t('Show or hide the palette.'),
      );
      $form['palette'] = array(
        '#type' => 'textarea',
        '#title' => t('Color Palette'),
        '#default_value' => $instance_settings['palette'],
        '#description' => t('Selectable color palette to accompany the Spectrum widget.'),
        '#states' => array(
          'visible' => array(
            ':input[name="instance[settings][show_palette]"]' => array('checked' => TRUE),
          ),
        ),
      );
      $form['show_palette_only'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show Palette Only'),
        '#default_value' => $instance_settings['show_palette_only'],
        '#description' => t('Only show the palette in Spectrum widget and nothing else.'),
      );
      $form['show_buttons'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show Buttons'),
        '#default_value' => $instance_settings['show_buttons'],
        '#description' => t('Add Cancel/Confirm buttons.'),
      );
      $form['allow_empty'] = array(
        '#type' => 'checkbox',
        '#title' => t('Allow Empty'),
        '#default_value' => $instance_settings['allow_empty'],
        '#description' => t('Allow empty value.'),
      );
      break;

    // Spectrum default widget.
    case 'color_field_default_widget':
      $form['default_colors'] = array(
        '#type' => 'textarea',
        '#title' => t('Default colors'),
        '#default_value' => $instance_settings['default_colors'],
        '#required' => TRUE,
        '#description' => t('Default colors for pre-selected color boxes'),
      );
      break;

    // Spectrum simple widget.
    // Use to be color_field_simple_color.
    case 'color_field_simple_color':
    case 'color_field_simple_widget':
      $form['cell_width'] = array(
        '#type' => 'textfield',
        '#title' => t('Cell width'),
        '#description' => t('Width of each individual color cell.'),
        '#default_value' => $instance_settings['cell_width'],
        '#required' => TRUE,
      );
      $form['cell_height'] = array(
        '#type' => 'textfield',
        '#title' => t('Height width'),
        '#description' => t('Height of each individual color cell.'),
        '#default_value' => $instance_settings['cell_height'],
        '#required' => TRUE,
      );
      $form['cell_margin'] = array(
        '#type' => 'textfield',
        '#title' => t('Cell margin'),
        '#description' => t('Margin of each individual color cell.'),
        '#default_value' => $instance_settings['cell_margin'],
        '#required' => TRUE,
      );
      $form['box_width'] = array(
        '#type' => 'textfield',
        '#title' => t('Box width'),
        '#description' => t('Width of the color display box.'),
        '#default_value' => $instance_settings['box_width'],
        '#required' => TRUE,
      );
      $form['box_height'] = array(
        '#type' => 'textfield',
        '#title' => t('Box height'),
        '#description' => t('Height of the color display box.'),
        '#default_value' => $instance_settings['box_height'],
        '#required' => TRUE,
      );
      $form['columns'] = array(
        '#type' => 'textfield',
        '#title' => t('Columns number'),
        '#description' => t('Number of columns to display. Color order may look strange if this is altered.'),
        '#default_value' => $instance_settings['columns'],
        '#required' => TRUE,
      );
      break;
  }

  return $form;
}

/**
 * Helper function for color_field_field_settings_form().
 */
function _color_field_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $widget = $instance['widget'];
  $field_settings = $field['settings'];
  $instance_settings = $instance['settings'];

  // Default value.
  $default_value = isset($instance['default_value'][0]['rgb']) ? $instance['default_value'][0]['rgb'] : '';
  $default_opacity = isset($instance['default_value'][0]['opacity']) ? $instance['default_value'][0]['opacity'] : '';

  $value = isset($items[$delta]['rgb']) ? $items[$delta]['rgb'] : $default_value;
  $opacity = isset($items[$delta]['opacity']) ? $items[$delta]['opacity'] : $default_opacity;

  $element['rgb'] = array(
    '#type' => 'textfield',
    '#title' => '',
    '#description' => t('Format #FFFFFF'),
    '#default_value' => $value,
    '#size' => 7,
    '#maxlength' => 7,
    '#element_validate' => array('color_field_field_widget_element_validate'),
  );

  if ($field_settings['opacity']) {
    $element['rgb']['#title'] = t('Color');
    $element['opacity'] = array(
      '#type' => 'textfield',
      '#title' => t('Opacity'),
      '#description' => t('Between 0 and 1'),
      '#default_value' => $opacity,
      '#size' => 4,
      '#maxlength' => 4,
      '#element_validate' => array('color_field_field_widget_element_validate'),
    );
  }

  $element += array(
    '#field_settings' => $field_settings,
    '#instance_settings' => $instance_settings,
    '#type' => $widget['type'],
    '#default_value' => isset($items[$delta]) ? $items[$delta] : NULL,
  );

  return $element;
}
