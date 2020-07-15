<?php

/**
 * @file
 * Defines a plugin for a multiselect facet API widget.
 */

/**
 * Widget that renders facets as a multiselect element.
 */
class FacetapiMultiSelectWidget extends FacetapiWidgetLinks {
  /**
   * Renders the facet.
   */
  public function execute() {
    // We need a separate form ID for each facet, so Drupal can distinguish
    // between multiple facets on the page. See facetapi_multiselect_forms().
    // Use drupal_static() because a regular static variable is buggy here for
    // some reason.
    $count = &drupal_static('FacetapiMultiSelectWidget:execute', 0);
    $form_id = 'facetapi_multiselect_form_' . ++$count;
    $element = &$this->build[$this->facet['field alias']];
    $element = drupal_get_form($form_id, $this, $element);
  }

  /**
   * Builds an array of #options for our select element.
   */
  public function buildOptions($element, $options = array(), $depth = 0) {
    $settings = $this->settings->settings;
    foreach ($element as $item) {
      if (empty($item['#item_children']) || !$settings['optgroups']) {
        $key = $this->getOptionKey($item);

        $markup = $item['#markup'];

        if ($settings['add_count']) {
          if (!$settings['remove_count_on_active'] || ($settings['remove_count_on_active'] && !$item['#active'])) {
            $markup .= ' (' . $item['#count'] . ')';
          }
        }

        $options[$key] = $markup;

        // Prepend the text with a depth indicator.
        if ($depth > 0) {
          $options[$key] = str_repeat('-', $depth) . ' ' . $options[$key];
        }
        // If the current item is active, but if we have selected the "Remove
        // selected" option, remove this items from our array, since we want to
        // hide it.
        if ($item['#active'] && $settings['remove_selected']) {
          unset($options[$key]);
        }
      }
      if ($item['#item_children']) {
        if ($settings['optgroups']) {
          // Recursively add any children of the item to the #options array (this
          // will result in them being placed inside optgroups).
          $options[$item['#markup']] = $this->buildOptions($item['#item_children']);
        }
        else {
          // Not using optgroups, so put all items at the root level.
          $options = $options + $this->buildOptions($item['#item_children'], $options, $depth + 1);
        }
      }
    }
    return $options;
  }

  /**
   * Builds a #default_value array for our select element.
   */
  public function buildDefaultValue($element) {
    $active_items = $this->facet->getAdapter()->getActiveItems($this->facet->getFacet());
    $default_value = array();
    foreach ($active_items as $id => $values) {
      $default_value[] = rawurlencode($values['field alias']) . ":" . $id;
    }
    return $default_value;
  }

  /**
   * Gets the key to use for an item in the select element #options array.
   */
  protected function getOptionKey($item) {
    $settings = $this->settings->settings;
    if ($settings['act_single'] && isset($item['#query']['f'])) {
      return implode('&', $item['#query']['f']);
    }
    // Set the key to the filter that will appear in the URL if this item is
    // selected. We need to do it this way (rather than using $item['#query'])
    // so that multiple selections can be combined together in the form's
    $facet_url = drupal_encode_path($this->facet['field alias']) . ':' . $item['#indexed_value'];
    if (isset($settings['disable_empty']) && $settings['disable_empty'] == 1 && $item['#count'] == 0) {
      // Submit handler. ":disabled" is added for facets with 0 items.
      $facet_url .= ':disabled';
    }
    return $facet_url;
  }

  /**
   * Allows the widget to provide additional settings to the form.
   */
  function settingsForm(&$form, &$form_state) {
    $form['widget']['widget_settings']['links'][$this->id]['add_count'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add count'),
      '#description' => t('Add available item count in brackets.'),
      '#default_value' => $this->settings->settings['add_count'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['remove_count_on_active'] = array(
      '#type' => 'checkbox',
      '#title' => t('Remove parenthetical counts on active items'),
      '#description' => t('Counts will only appear for unselected items, ideal for Chosen theming.'),
      '#default_value' => $this->settings->settings['remove_count_on_active'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
          'input[name="add_count"]' => array('checked' => TRUE),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['disable_empty'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show empty facets as disabled'),
      '#description' => t('When facets have zero items, show them anyway, but disallow selecting them.'),
      '#default_value' => $this->settings->settings['disable_empty'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['remove_selected'] = array(
      '#type' => 'checkbox',
      '#title' => t('Remove selected'),
      '#description' => t('Remove selected options from select list.'),
      '#default_value' => $this->settings->settings['remove_selected'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['auto_submit'] = array(
      '#type' => 'checkbox',
      '#title' => t('Autosubmit'),
      '#description' => t('Hide submit button and submit selection automatically.'),
      '#default_value' => $this->settings->settings['auto_submit'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['act_single'] = array(
      '#type' => 'checkbox',
      '#title' => t('Act as single select element'),
      '#description' => t('Change query path to work with facets from connected fields.'),
      '#default_value' => $this->settings->settings['act_single'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['optgroups'] = array(
      '#type' => 'checkbox',
      '#title' => t('Nest hierarchical facets in optgroups.'),
      '#description' => t('Parent facets will be rendered as optgroups in the select element.'),
      '#default_value' => $this->settings->settings['optgroups'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
    $form['widget']['widget_settings']['links'][$this->id]['placeholder_label'] = array(
      '#type' => 'textfield',
      '#title' => t('Facet placeholder text'),
      '#description' => t('The placeholder text will appear before any options are selected.'),
      '#default_value' => $this->settings->settings['placeholder_label'],
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        )
      )
    );
  }

  /**
   * Returns defaults for the settings this widget provides.
   */
  function getDefaultSettings() {
    return array(
      'add_count' => 0,
      'remove_count_on_active' => 0,
      'remove_selected' => 0,
      'auto_submit' => 0,
      'act_single' => 0,
      'optgroups' => 1,
      'placeholder_label' => t('Select some options'),
    );
  }
}
