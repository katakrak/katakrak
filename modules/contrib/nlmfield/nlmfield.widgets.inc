<?php

/**
 * @file
 * Provides field widget hooks for nlmfield module.
 */

/**
 * Implements hook_field_widget_info().
 */
function nlmfield_field_widget_info() {
  $widgets = array();
  $widgets['nlmfield_xml'] = array(
    'label' => t('XML'),
    'field types' => array('nlmfield_contributor'),
  );
  $widgets['nlmfield_text'] = array(
    'label' => t('TEXT'),
    'field types' => array('nlmfield_contributor'),
  );
  return $widgets;
}

/**
 * Implements hook_field_widget_form().
 */
function nlmfield_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $widget = $instance['widget'];
  $settings = $field['settings'];

  $element += array(
    '#type' => 'fieldset',
    '#title' => t('Nlmfield'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => true
  );

  $element['xml']['#title'] = 'XML';
  $element['xml']['#type'] = 'textarea';
  $element['xml']['#default_value'] = !empty($items[$delta]['xml']) ? $items[$delta]['xml'] : '';

  $xml = $element['xml']['#default_value'];

  switch ($widget['type']) {

    case 'nlmfield_xml':
    // This case is not being used for now, just leaving in place, in case needed in future.
    break;

    case 'nlmfield_text':

      $element['xml']['#type'] = 'hidden';
      $element['xml']['#delta'] = $delta;
      $element['xml']['#field_name'] = $element['#field_name'];
      $element['xml']['#element_validate'] = array('nlmfield_field_widget_text_to_xml');
      $element['xml']['#nlmfield_namespace'] = $settings['nlmfield_namespace'] ? $settings['nlmfield_namespace'] : 'nlm';
      $element['xml']['#nlmfield_namespace_def_url'] = $settings['nlmfield_namespace_def_url'] ? $settings['nlmfield_namespace_def_url'] : 'http://www.ncbi.nlm.nih.gov';
      $element['xml']['#additional_namespaces'] = $settings['additional_namespaces'] ? $settings['additional_namespaces'] : '';
      

      $element['string_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Name String'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 'n', $xml)),
      );

      $element['prefix'] = array(
        '#type' => 'textfield',
        '#title' => t('Name Prefix'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 'p', $xml)),
      );
      
      $element['given_names'] = array(
        '#type' => 'textfield',
        '#title' => t('First name and middle name'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 'g', $xml)),
        '#description' => t("First or given name, e.g. 'Peter'."),
      );
      
      $element['surname'] = array(
        '#type' => 'textfield',
        '#title' => t('Last Name'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 's', $xml)),
        '#description' => t("Your last, or family, name, e.g. 'MacMoody'."),
      );
      
      $element['suffix'] = array(
        '#type' => 'textfield',
        '#title' => t('Name Suffix'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 'x', $xml)),
      );
      
      $element['degrees'] = array(
        '#type' => 'textfield',
        '#title' => t('Degrees'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 'd', $xml)),
      );
      
      $element['email'] = array(
        '#type' => 'textfield',
        '#title' => t('Email'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 'e', $xml)),
        '#description' => t("Your email address, e.g. higgs-boson@gmail.com"),
      );

      $element['contributor_type'] = array(
        '#type' => 'textfield',
        '#title' => t('Contributor type'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 't', $xml)),
        '#description' => t("Specifies contribution type, typical values are 'author', 'editor' etc"),
      );

      $element['role'] = array(
        '#type' => 'textfield',
        '#title' => t('Role / Occupation'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 'r', $xml)),
        '#description' => t("Your role and/or occupation, e.g. 'Orthopedic Surgeon'."),
      );

      $element['aff'] = array(
        '#type' => 'textfield',
        '#title' => t('Affiliation'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 'a', $xml)),
        '#description' => t("Your organization or institution (if applicable), e.g. 'Royal Free Hospital'.")
      );

      $element['address'] = array(
        '#type' => 'textfield',
        '#title' => t('Address'),
        '#default_value' => drupal_html_to_text(nlmfield_process_bit('nlmfield_contributor', 'A', $xml)),
        '#description' => t("Your organization, institution's or residential address."),
      );

    break;
  }

  return $element;
}

function nlmfield_field_widget_text_to_xml($element, &$form_state) {

  $delta = $element['#delta'];
  $field_name = $element['#field_name'];
  $ns_url = $element['#nlmfield_namespace_def_url'];
  $ns = $element['#nlmfield_namespace'];
  
  $add_ns = array();
  if ($add_ns_string = $element['#additional_namespaces']) {
    foreach (explode("\n", $add_ns_string) as $part) {
      $pair = explode('|', $part);
      $add_ns[$pair[0]] = $pair[1];
    }
  }
  $xml = NULL;
  $val = $form_state['values'][$field_name]['und'][$delta];
  if ($val['string_name'] || $val['email']) {

    nlmfield_load_library();
    $dom = new BetterDOMDocument("<contrib xmlns='$ns_url' />", $ns);

    // Set additional namespaces
    foreach ($add_ns as $prefix => $url) {
      $dom->documentElement->setAttribute('xmlns:' . $prefix, $url);
      $dom->registerNamespace($prefix, $url);
    }

    if ($val['contributor_type']) {
      $dom->documentElement->setAttribute("contrib-type", $val['contributor_type']);
    }

    // Create the name element and sub-elements
    if ($val['string_name']) {
      $dom->append("<string-name>" . drupal_html_to_text($val['string_name']). "</string-name>");
    }
    if ($val['surname'] || $val['given_names'] || $val['prefix'] || $val['suffix']) {
      $name = $dom->append("<name />");
      if ($val['prefix']) {
        $dom->append("<prefix>" . drupal_html_to_text($val['prefix']) . "</prefix>", $name);
      }
      if ($val['given_names']) {
        $dom->append("<given-names>" . drupal_html_to_text($val['given_names']) . "</given-names>", $name);
      }
      if ($val['surname']) {
        $dom->append("<surname>" . drupal_html_to_text($val['surname']) . "</surname>", $name);
      }
      if ($val['suffix']) {
        $dom->append("<suffix>" . drupal_html_to_text($val['suffix']) . "</suffix>", $name);
      }
    }

    // Add in all the other elements
    if ($val['email']) {
      $dom->append("<email>" . drupal_html_to_text($val['email']) . "</email>");
    }

    if ($val['role']) {
      $dom->append("<role>" . drupal_html_to_text($val['role']) . "</role>");
    }

    if ($val['aff']) {
      $dom->append("<aff>" . drupal_html_to_text($val['aff']) . "</aff>");
    }

    if ($val['address']) {
      $dom->append("<address>" . drupal_html_to_text($val['address']) . "</address>");
    }

    if ($val['degrees']) {
      $dom->append("<degrees>" . drupal_html_to_text($val['degrees']) . "</degrees>");
    }
    $xml = $dom->out();
  }

  form_set_value($element, $xml, $form_state);
}

