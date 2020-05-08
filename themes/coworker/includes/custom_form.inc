<?php

function coworker_button($variables) {

  $variables['element']['#attributes']['class'][] = 'btn';

  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));
  //$label = check_plain($element['#value']);
  $label = $element['#value'];
  
 
  if ($label == t('Add to cart')) {
    $element['#attributes']['data-title'] = t('+To Cart');
    $element['#attributes']['data-placement'] = 'top';
    $element['#attributes']['data-toggle'] = 'tooltip';
    $element['#attributes']['class'][] = 'btn-primary';
    $label = '<i class="icon-shopping-cart"></i>' . ' '.$label;
  }
  if ($label == t('Donar')) {
    $element['#attributes']['data-title'] = t('+To Cart');
    $element['#attributes']['data-placement'] = 'top';
    $element['#attributes']['data-toggle'] = 'tooltip';
    $element['#attributes']['class'][] = 'btn-primary';
    $label = '<i class="icon-hand-right"></i>' . ' '.$label;
  }

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  return '<button' . drupal_attributes($element['#attributes']) . '>' . $label . '</button>
  '; // This line break adds inherent margin between multiple buttons
}

/**
 * Implements theme_checkbox().
 */
function coworker_checkbox($variables) {
  $element = $variables['element'];
  $t = get_t();
  $element['#attributes']['type'] = 'checkbox';
  element_set_attributes($element, array('id', 'name', '#return_value' => 'value'));

  // Unchecked checkbox has #value of integer 0.
  if (!empty($element['#checked'])) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-checkbox'));

  switch ($element['#title_display']) {
    case 'attribute':
      $element['#attributes']['#title'] = $element['#description'];
      $output = '<input' . drupal_attributes($element['#attributes']) . ' />';
      break;
    // Bootstrap's default styles cause 'before' to render exactly like 'after':
    case 'before':
      $output = '<label class="checkbox">' . $element['#description'] . '<input' . drupal_attributes($element['#attributes']) . ' /></label>';
      break;
    // The 'invisible' option really makes no sense in the context of checkboxes
    // or radios, so just treat it like 'after':
    case 'invisible':
    case 'after':
    default:
      // There are some odd cases, such as the module list page, where checkboxes
      // apparently themed with a #title_display value of 'before' when it should
      // really be 'attribute'. The two possible outcomes handle this problem:
      $checkbox = '<input' . drupal_attributes($element['#attributes']) . ' />';
      if (isset($element['#description'])) {
        $output = '<label class="checkbox">' . $checkbox . $element['#description'] . '</label>';
      } else {
        $output = $checkbox;
      }
      break;
  }

  return $output;
}

function coworker_checkboxes($variables) {

  $option_children = '';
  foreach ($variables['element']['#options'] as $key => $description) {
    $option_variables = array(
        'element' => $variables['element'][$key],
    );
    $option_variables['element']['#description'] = $option_variables['element']['#title'];
    $option_children .= theme('checkbox', $option_variables) . "\n";
  }
  $variables['element']['#children'] = $option_children;
  // Proceed normally:
  $element = $variables['element'];
  // Attributes usually figured out here, but serve no purpose here (?)
  return !empty($element['#children']) ? $element['#children'] : '';
}

function coworker_fieldset($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id'));
  _form_set_class($element, array('form-wrapper'));

  $output = '<fieldset' . drupal_attributes($element['#attributes']) . '>';
  if (!empty($element['#title'])) {
    // Always wrap fieldset legends in a SPAN for CSS positioning.
    $output .= '<legend><span class="fieldset-legend">' . $element['#title'] . '</span></legend>';
  }
  // Add 'row-fluid' class to fieldset wrapper div so that, by adding Bootstrap
  // span classes to the sub-elements, we can theme forms in a very flexible way:
  $output .= '<div class="fieldset-wrapper row-fluid">';
  if (!empty($element['#description'])) {
    $output .= '<div class="fieldset-description">' . $element['#description'] . '</div>';
  }
  $output .= $element['#children'];
  if (isset($element['#value'])) {
    $output .= $element['#value'];
  }
  $output .= '</div>';
  $output .= "</fieldset>\n";
  return $output;
}

function coworker_file($variables) {
  // Assign the Bootstrap class:
  _form_set_class($variables['element'], array('input-file'));
  // Set a reasonably low default size:
  $variables['element']['#attributes']['size'] = '22';
  return theme_file($variables);
}

function coworker_form_element($variables) {
  $element = &$variables['element'];
  // Make sure no PHP notices are triggered when type is not provided:
  if (!isset($element['#type'])) {
    $element['#type'] = '';
  }
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
      '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array(
      'form-item',
      'control-group',
  );
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  // Get the description, if any, before we assemble the rest of the pieces:
  $description = !empty($element['#description']) ? '<p class="description help-block">' . $element['#description'] . "</p>\n" : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      switch ($element['#type']) {
        case 'password':
        case 'textfield':
        default:
          $output .= theme('form_element_label', $variables);
          $output .= '<div class="controls">' . "\n";
          $output .= $prefix . $element['#children'] . $suffix . "\n";
          $output .= $description . "\n";
          $output .= '</div>' . "\n";
          break;
      }
      break;

    case 'after':
      // Single checkboxes and radios are handled here by default, and need special
      // treatment:
      switch ($element['#type']) {
        case 'checkbox':
        case 'radio':
          $output .= theme('form_element_label', $variables) . "\n";
          $output .= '<div class="controls">' . "\n";
          $output .= $element['#children'];
          $output .= '</div>';
          break;
        default:
          $output .= ' ' . $prefix . $element['#children'] . $suffix;
          $output .= ' ' . theme('form_element_label', $variables) . "\n";
      }
      break;

    case 'none':
    case 'attribute':
      switch ($element['#type']) {
        case 'checkbox':
        case 'radio':
          $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
          break;
        default:
          // Output no label and no required marker, only the children.
          $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
          $output .= $description;
      }
      break;
  }

  $output .= "</div>\n";

  return $output;
}

function coworker_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // Add Bootstrap-related class to label:
  if (isset($attributes['class'])) {
    $attributes['class'] .= ' control-label';
  } else {
    $attributes['class'] = 'control-label';
  }

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
}

function coworker_radio($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'radio';
  element_set_attributes($element, array('id', 'name', '#return_value' => 'value'));

  if (isset($element['#return_value']) && $element['#value'] !== FALSE && $element['#value'] == $element['#return_value']) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-radio'));

  switch ($element['#title_display']) {
    // This *could* make sense e.g. in a table of mutually exclusive options...
    case 'attribute':
      $element['#attributes']['#title'] = $element['#description'];
      $output = '<input' . drupal_attributes($element['#attributes']) . ' />';
      break;
    // Bootstrap's default styles cause 'before' to render exactly like 'after':
    case 'before':
      $output = '<label class="radio">' . $element['#description'] . '<input' . drupal_attributes($element['#attributes']) . ' /></label>';
      break;
    // The 'invisible' option really makes no sense in the context of checkboxes
    // or radios, so just treat it like 'after':
    case 'invisible':
    case 'after':
    default:
      $radio = '<input' . drupal_attributes($element['#attributes']) . ' />';
      if (isset($element['#description'])) {
        $output = '<label class="radio">' . $radio . $element['#description'] . '</label>';
      } else {
        $output = $radio;
      }
      break;
  }

  return $output;
}

function coworker_radios($variables) {
  // Redefine #children:
  $option_children = '';
  foreach ($variables['element']['#options'] as $key => $description) {
    $option_variables = array(
        'element' => $variables['element'][$key],
    );
    $option_variables['element']['#description'] = $option_variables['element']['#title'];
    $option_children .= theme('radio', $option_variables) . "\n";
  }
  $variables['element']['#children'] = $option_children;
  $element = $variables['element'];
  // Attributes usually figured out here, but serve no purpose here (?)
  return !empty($element['#children']) ? $element['#children'] : '';
}

function coworker_textarea($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  // Add non-Drupal class here:
  _form_set_class($element, array('input-xlarge'));

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    // Don't add usual Drupal wrapper class here:
    $wrapper_attributes['class'][] = 'resizable';
  } else {
    $wrapper_attributes = array();
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}

function coworker_menu_tree($variables) {
  return '<ul class="menu unstyled my-account">' . $variables['tree'] . '</ul>';
}

function coworker_menu_link(array $variables) {
  $element = $variables['element'];
  $element['#localized_options']['html'] = TRUE;
  $element['#localized_options']['attributes']['class'][''] = 'invarseColor';

  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l('<i class="icon-caret-right"></i>' . $element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
