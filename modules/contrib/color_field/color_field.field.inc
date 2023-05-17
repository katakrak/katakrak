<?php

/**
 * @file
 * Field hooks to implement a color field.
 */

/**
 * Implements hook_field_info().
 */
function color_field_field_info() {
  return array(
    'color_field_rgb' => array(
      'label' => t('Color Field'),
      'description' => t('Field using a hexadecimal notation.'),
      // These settings apply to the color field field everywhere it is used.
      'settings' => array(
        'opacity' => FALSE,
      ),
      // These settings apply to the color field instance.
      'instance_settings' => array(
        // Simple widget.
        'default_colors' => '
#AC725E,#D06B64,#F83A22,#FA573C,#FF7537,#FFAD46
#42D692,#16A765,#7BD148,#B3DC6C,#FBE983
#92E1C0,#9FE1E7,#9FC6E7,#4986E7,#9A9CFF
#B99AFF,#C2C2C2,#CABDBF,#CCA6AC,#F691B2
#CD74E6,#A47AE2',
        // Simple color.
        'cell_width' => 10,
        'cell_height' => 10,
        'cell_margin' => 1,
        'box_width' => 115,
        'box_height' => 20,
        'columns' => 16,
        // Spectrum.
        'show_input' => FALSE,
        'show_palette' => FALSE,
        'palette' => '',
        'show_palette_only' => TRUE,
        'show_buttons' => FALSE,
        'allow_empty' => FALSE,
      ),
      'default_widget' => 'color_field_default_widget',
      'default_formatter' => 'color_field_default_formatter',
      // Support hook_entity_property_info() from contrib "Entity API".
      'property_type' => 'color_field',
      'property_callbacks' => array('color_field_property_info_callback'),
    ),
  );
}

/**
 * Additional callback to adapt the property info of link fields.
 *
 * @see entity_metadata_field_entity_property_info()
 */
function color_field_property_info_callback(&$info, $entity_type, $field, $instance, $field_type) {
  $field_settings = $field['settings'];

  $property = &$info[$entity_type]['bundles'][$instance['bundle']]['properties'][$field['field_name']];
  // Define a data structure so it's possible to deal with both the color
  // and opacity.
  $property['getter callback'] = 'entity_metadata_field_verbatim_get';
  $property['setter callback'] = 'entity_metadata_field_verbatim_set';

  // Auto-create the field item as soon as a property is set.
  $property['auto creation'] = 'color_field_item_create';

  $property['property info'] = color_field_item_property_info();

  if (!$field_settings['opacity']) {
    unset($property['property info']['opacity']);
  }
  unset($property['query callback']);
}

/**
 * Callback for creating a new, empty link field item.
 *
 * @see color_field_property_info_callback()
 */
function color_field_item_create() {
  return array('rgb' => NULL, 'opacity' => NULL);
}

/**
 * Defines info for the properties of the link-field item data structure.
 */
function color_field_item_property_info() {
  $properties['rgb'] = array(
    'type' => 'text',
    'label' => t('The color of the color field.'),
    'setter callback' => 'entity_property_verbatim_set',
  );
  $properties['opacity'] = array(
    'type' => 'float',
    'label' => t('The opacity of the color field.'),
    'setter callback' => 'entity_property_verbatim_set',
  );
  return $properties;
}

/**
 * Implements hook_field_validate().
 *
 * We want to verify that the color items only contain RGB hex values like
 * this: #RRGGBB. If the item validates, we do nothing. If it doesn't
 * validate, we add our own error notification to the $errors parameter.
 *
 * @see color_field_widget_error()
 */
function color_field_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  foreach ($items as $delta => $item) {
    // Test required color fields.
    if($instance['required'] && empty($item['rgb'])) {
      $errors[$field['field_name']][$langcode][$delta][] = array(
        'error' => 'color_required',
        'message' => t('The color for %field is required.', array(
          '%value' => trim($item['rgb']),
          '%field' => $instance['label'],
        )),
        'error_element' => array('rgb' => TRUE, 'opacity' => FALSE),
      );
    }
    // Test required opacity fields is opacity need to be recorded.
    if($field['settings']['opacity'] && $instance['required'] && empty($item['opacity'])) {
      $errors[$field['field_name']][$langcode][$delta][] = array(
        'error' => 'color_required',
        'message' => t('The opacity for %field is required.', array(
          '%value' => trim($item['rgb']),
          '%field' => $instance['label'],
        )),
        'error_element' => array('rgb' => FALSE, 'opacity' => TRUE),
      );
    }
    // Test rgb field format.
    $regexp = '@^#[0-9a-fA-F]{6}$@';
    if (!empty($item['rgb']) && !preg_match($regexp, $item['rgb'])) {
      $errors[$field['field_name']][$langcode][$delta][] = array(
        'error' => 'color_invalid',
        'message' => t('The value %value provided for %field is not a valid color.', array(
          '%value' => trim($item['rgb']),
          '%field' => $instance['label'],
        )),
        'error_element' => array('rgb' => TRUE, 'opacity' => FALSE),
      );
    }
    // Test opacity field.
    $regexp = '@^[0]?(\.)(\d)*$|^[01]$@';
    if (!empty($item['opacity']) && !preg_match($regexp, $item['opacity'])) {
      $errors[$field['field_name']][$langcode][$delta][] = array(
        'error' => 'opacity_invalid',
        'message' => t('The value %value provided for %field is not a valid opacity.', array(
          '%value' => trim($item['opacity']),
          '%field' => $instance['label'],
        )),
        'error_element' => array('rgb' => FALSE, 'opacity' => TRUE),
      );
    }
  }
}

/**
 * Implements hook_field_widget_error().
 *
 * @see color_field_validate()
 * @see form_error()
 */
function color_field_field_widget_error($element, $error, $form, &$form_state) {
  if ($error['error_element']['rgb']) {
    form_error($element['rgb'], $error['message']);
  }
  if ($error['error_element']['opacity']) {
    form_error($element['opacity'], $error['message']);
  }
}

/**
 * Implements #element_validate function.
 *
 * If a palette is set for the Spectrum widget, there are no default values
 * available until the field has been saved. However, values are needed when a
 * field is marked as required, otherwise errors occur. Therefore, when rgb or
 * opacity are empty, and field is required, set the default values to rgb =
 * #000000 and opacity = 1.
 *
 * @see _color_field_field_widget_form()
 */
function color_field_field_widget_element_validate($element, &$form_state) {
  if ($form_state['build_info']['form_id'] == 'field_ui_field_edit_form') {
    $field = $form_state['build_info']['args'][0];
    if ($field['widget']['type'] == 'color_field_spectrum_widget' && $field['required']) {
      $value = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
      if (empty($value)) {
        $parents = $element['#parents'];
        $field_name = array_pop($parents);
        $field_value = '';
        if ($field_name == 'rgb') {
          $field_value = '#000000';
        }
        elseif ($field_name == 'opacity') {
          $field_value = 1;
        }
        drupal_array_set_nested_value($form_state['values'], $element['#parents'], $field_value);
      }
    }
  }
}

/**
 * Implements hook_field_is_empty().
 */
function color_field_field_is_empty($item, $field) {
  if (!is_array($item)) {
    return FALSE;
  }
  if (empty($item['rgb'])) {
    return TRUE;
  }
  elseif ($field['settings']['opacity'] && empty($item['opacity'])) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Implements hook_field_insert().
 */
function color_field_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as $delta => $value) {
    if (!isset($items[$delta]['opacity'])) {
      $items[$delta]['opacity'] = 1;
    }
  }
}

/**
 * Implements hook_field_update().
 */
function color_field_field_update($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as $delta => $value) {
    if (!isset($items[$delta]['opacity'])) {
      $items[$delta]['opacity'] = 1;
    }
  }
}

/**
 * Implements hook_element_info().
 */
function color_field_element_info() {
  $elements = array();
  $elements['color_field_plain_text'] = array(
    '#input' => TRUE,
    '#theme' => 'color_field_plain_text',
    '#theme_wrappers' => array('form_element'),
  );
  $elements['color_field_default_widget'] = array(
    '#input' => TRUE,
    '#theme' => 'color_field_default_widget',
    '#theme_wrappers' => array('form_element'),
  );
  $elements['color_field_simple_widget'] = array(
    '#input' => TRUE,
    '#theme' => 'color_field_simple_widget',
    '#theme_wrappers' => array('form_element'),
  );
  $elements['color_field_spectrum_widget'] = array(
    '#input' => TRUE,
    '#theme' => 'color_field_spectrum_widget',
    '#theme_wrappers' => array('form_element'),
  );
  return $elements;
}

/**
 * Implements hook_field_widget_info().
 *
 * Enable the different field widgets.
 *
 * @see color_field_field_settings_form()
 * @see color_field_field_instance_settings_form
 * @see color_field_field_widget_form()
 */
function color_field_field_widget_info() {
  // If jquery-simple-color is enable so widget can be used.
  $jquery_simple_color_picker_enable = TRUE;
  $color_field_library_jquery_simple_color = drupal_get_library('color_field', 'jquery-simple-color');
  foreach ($color_field_library_jquery_simple_color['js'] as $path => $js) {
    if (!file_exists($path)) {
      $jquery_simple_color_picker_enable = FALSE;
    }
  }

  // If jquery_dematte_color_picker_enable is enable so widget can be used.
  $jquery_dematte_color_picker_enable = TRUE;
  $color_field_library_dematte_color = drupal_get_library('color_field', 'dematte-color-picker');
  foreach ($color_field_library_dematte_color['js'] as $path => $js) {
    if (!file_exists($path)) {
      $jquery_dematte_color_picker_enable = FALSE;
    }
  }

  // If jquery_eyecon_color_picker_enable is enable so widget can be used.
  $jquery_eyecon_color_picker_enable = TRUE;
  $color_field_library_eyecon_color = drupal_get_library('color_field', 'eyecon-color-picker');
  foreach ($color_field_library_eyecon_color['js'] as $path => $js) {
    if (!file_exists($path)) {
      $jquery_eyecon_color_picker_enable = FALSE;
    }
  }

  // If jquery_spectrum_color_picker_enable is enable so widget can be used.
  $jquery_spectrum_color_picker_enable = TRUE;
  $color_field_library_spectrum_color = drupal_get_library('color_field', 'bgrins-spectrum');
  foreach ($color_field_library_spectrum_color['js'] as $path => $js) {
    if (!file_exists($path)) {
      $jquery_spectrum_color_picker_enable = FALSE;
    }
  }
  foreach ($color_field_library_spectrum_color['css'] as $path => $js) {
    if (!file_exists($path)) {
      $jquery_spectrum_color_picker_enable = FALSE;
    }
  }

  $widgets = array();

  $widgets['color_field_default_widget'] = array(
    'label' => t('Pre-selected Color Boxes'),
    'field types' => array('color_field_rgb'),
    'weight' => 2,
  );

  // Color_field_farbtastic_widget need more work before release.
  /*$widgets['color_field_farbtastic_widget'] = array(
    'label' => t('Farbtastic Color-Picker'),
    'field types' => array('color_field_rgb'),
  );*/

  // Check if color_field_simple_color can become color_field_simple_widget
  if ($jquery_simple_color_picker_enable) {
    $widgets['color_field_simple_widget'] = array(
      'label' => t('Simple Color-Picker'),
      'field types' => array('color_field_rgb'),
      'weight' => 3,
    );
  }

  // Color_field_dematte_widget need more work before release.
  /*if ($jquery_dematte_color_picker_enable) {
    $widgets['color_field_dematte_widget'] = array(
      'label' => t('Dematte Color-Picker'),
      'field types' => array('color_field_rgb'),
    );
  }*/

  // color_field_eyecon_widget need more work before release.
  /*if ($jquery_eyecon_color_picker_enable) {
    $widgets['color_field_eyecon_widget'] = array(
      'label' => t('Eyecon Color-Picker'),
      'field types' => array('color_field_rgb'),
    );
  }*/

  // Dematte colorPicker.
  if ($jquery_spectrum_color_picker_enable) {
    $widgets['color_field_spectrum_widget'] = array(
      'label' => t('Spectrum Color-Picker'),
      'field types' => array('color_field_rgb'),
      'weight' => 4,
    );
  }

  // Textfield.
  $widgets['color_field_plain_text'] = array(
    'label' => t('Plain text (RGB value as #ffffff)'),
    'field types' => array('color_field_rgb'),
    'weight' => 1,
  );

  return $widgets;
}

/**
 * Implements hook_field_settings_form().
 */
function color_field_field_settings_form($field, $instance, $has_data) {
  module_load_include('inc', 'color_field', 'color_field_admin');
  return _color_field_field_settings_form($field, $instance, $has_data);
}

/**
 * Implements hook_field_instance_settings_form().
 */
function color_field_field_instance_settings_form($field, $instance) {
  module_load_include('inc', 'color_field', 'color_field_admin');
  return _color_field_field_instance_settings_form($field, $instance);
}

/**
 * Implements hook_field_widget_form().
 */
function color_field_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  module_load_include('inc', 'color_field', 'color_field_admin');
  return _color_field_field_widget_form($form, $form_state, $field, $instance, $langcode, $items, $delta, $element);
}

/**
 * Implements hook_field_formatter_info().
 *
 * @see color_field_field_formatter_view()
 */
function color_field_field_formatter_info() {
  return array(
    'color_field_default_formatter' => array(
      'label' => t('Plain text color'),
      'field types' => array('color_field_rgb'),
    ),
    'color_field_css_declaration' => array(
      'label' => t('CSS Declaration'),
      'field types' => array('color_field_rgb'),
      'settings' => array(
        'selector' => 'body',
        'property' => 'background-color',
        'important' => TRUE,
        'opacity_disabled' => FALSE,
      ),
    ),
    'color_field_swatch' => array(
      'label' => t('Color Swatch'),
      'field types' => array('color_field_rgb'),
      'settings' => array(
        'width' => '50',
        'height' => '50',
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function color_field_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();

  switch ($display['type']) {
    case 'color_field_css_declaration':
      $element['selector'] = array(
        '#title' => t('Selector'),
        '#type' => 'textarea',
        '#default_value' => $settings['selector'],
        '#required' => TRUE,
        '#description' => t('A valid CSS selector such as <code>.links > li > a, #logo</code>.'),
      );
      $element['token'] = array(
        '#theme' => 'token_tree',
        '#token_types' => array($instance['entity_type']),
        '#dialog' => TRUE,
      );
      $element['property'] = array(
        '#title' => t('Property'),
        '#type' => 'select',
        '#default_value' => $settings['property'],
        '#required' => TRUE,
        '#options' => array(
          'background-color' => t('Background color'),
          'color' => t('Text color'),
        ),
      );
      $element['important'] = array(
        '#title' => t('Important'),
        '#type' => 'checkbox',
        '#default_value' => $settings['important'],
        '#description' => t('Whenever this declaration is more important than others.'),
      );
      if ($field['settings']['opacity'] === 1) {
        $element['opacity_disabled'] = array(
          '#title' => t('Disable opacity'),
          '#type' => 'checkbox',
          '#default_value' => $settings['opacity_disabled'],
          '#description' => t('Disable the color opacity.'),
        );
      }
      break;

    case 'color_field_swatch':
      $element['width'] = array(
        '#title' => t('Width'),
        '#type' => 'textfield',
        '#default_value' => $settings['width'],
        '#description' => t('Enter desired pixel width for the color swatch as a number only.'),
        '#required' => TRUE,
        "#element_validate" => array('_color_field_validate_number'),
      );
      $element['height'] = array(
        '#title' => t('Height'),
        '#type' => 'textfield',
        '#default_value' => $settings['height'],
        '#description' => t('Enter desired pixel height for the color swatch as a number only.'),
        '#required' => TRUE,
        "#element_validate" => array('_color_field_validate_number'),
      );
      break;
  }

  return $element;

}

/**
 * validating numerical input
 *
 * @param $element
 * @param $form_state
 * @param $form
 */
function _color_field_validate_number($element, &$form_state, $form) {
  if (!is_numeric($element['#value'])) {
    form_error($element, t('This needs to be a numeric value'));
  }
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function color_field_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

  switch ($display['type']) {
    case 'color_field_css_declaration':
      $summary[] = t('CSS selector : @css_selector', array('@css_selector' => $settings['selector']));
      $summary[] = t('CSS property : @css_property', array('@css_property' => $settings['property']));
      $summary[] = t('!important declaration : @important_declaration', array('@important_declaration' => (($settings['important']) ? t('Yes') : t('No'))));
      if ($field['settings']['opacity'] === 1) {
        $summary[] = t('Disable opacity : @opacity_disabled', array('@opacity_disabled' => ($settings['opacity_disabled']) ? t('Yes') : t('No')));
      }
      break;

    case 'color_field_swatch':
      $summary[] = t('Width : @width', array('@width' => $settings['width']));
      $summary[] = t('Height : @height', array('@height' => $settings['height']));
      break;
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view().
 *
 * Three formatters are implemented.
 * - color_field_default_formatter just outputs markup indicating the color that
 *   was entered and uses an inline style to set the text color to that value.
 * - color_field_css_declaration does the same but also changes the
 *   background color or color of a region defined by the selector.
 *
 * @see color_field_formatter_info()
 */
function color_field_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $field_settings = $field['settings'];
  $display_settings = $display['settings'];

  switch ($display['type']) {
    case 'color_field_default_formatter':
      foreach ($items as $delta => $item) {
        if ($field_settings['opacity']) {
          $value = color_field_hex2rgba(drupal_substr($item['rgb'], 1, 6), $item['opacity']);
        }
        else {
          $value = $item['rgb'];
        }
        $element[$delta]['#markup'] = $value;
      }
      break;

    case 'color_field_css_declaration':
      foreach ($items as $delta => $item) {
        if ($field_settings['opacity'] && $display_settings['opacity_disabled'] === 0) {
          $value = color_field_hex2rgba(drupal_substr($item['rgb'], 1, 6), $item['opacity']);
        }
        else {
          $value = $item['rgb'];
        }

        $selector = token_replace($display_settings['selector'], array($entity_type => $entity), array('clear' => TRUE));
        $important = ($display_settings['important']) ? ' !important' : '';

        $inline_css = $selector . '{ ' . $display_settings['property'] . ': ' . $value . $important . '; }';

        drupal_add_css($inline_css, 'inline');
      }
      break;

    case 'color_field_swatch':
      foreach ($items as $delta => $item) {
        if ($field_settings['opacity']) {
          $value = color_field_hex2rgba(drupal_substr($item['rgb'], 1, 6), $item['opacity']);
        }
        else {
          $value = $item['rgb'];
        }
        $width = $display_settings['width'];
        $height = $display_settings['height'];

        $element[$delta] = array(
          '#theme' => 'color_swatch',
          '#color' => $value,
          '#width' => $width,
          '#height' => $height,
        );
      }
      break;
  }

  return $element;
}
