<?php
/**
 * @file
 * Definition of views_bootstrap_plugin_style.
 */

/**
 * Class to define a style plugin handler.
 */
class katakrak_grid_plugin_style extends views_plugin_style {
  /**
   * Definition.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['alignment'] = array('default' => 'horizontal');
    $options['columns_lg'] = array('default' => '2');
    $options['columns_md'] = array('default' => '2');
    $options['columns_sm'] = array('default' => '2');
    $options['columns_xs'] = array('default' => '2');
    return $options;
  }

  /**
   * Form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
     $form['alignment'] = array(
      '#type' => 'radios',
      '#title' => t('Alignment'),
      '#options' => array(
        'horizontal' => t('Horizontal'),
        'vertical' => t('Vertical'),
      ),
      '#description' => t('Horizontal alignment will place items starting in the upper left and moving right.
      Vertical alignment will place items starting in the upper left and moving down.'),
      '#default_value' => $this->options['alignment'],
    );
     
    $options = array(1, 2, 3, 4, 6, 12);
    $form['columns_lg'] = array(
      '#type' => 'select',
      '#title' => t('Number of columns for large devices'),
      '#default_value' => $this->options['columns_lg'],
      '#options' => array_combine($options, $options),
      '#required' => TRUE,
    );
    $form['columns_md'] = array(
      '#type' => 'select',
      '#title' => t('Number of columns for medium devices'),
      '#default_value' => $this->options['columns_md'],
      '#options' => array_combine($options, $options),
      '#required' => TRUE,
    );
    $form['columns_sm'] = array(
      '#type' => 'select',
      '#title' => t('Number of columns for small devices'),
      '#default_value' => $this->options['columns_sm'],
      '#options' => array_combine($options, $options),
      '#required' => TRUE,
    );
    $form['columns_xs'] = array(
      '#type' => 'select',
      '#title' => t('Number of columns for extra small devices'),
      '#default_value' => $this->options['columns_xs'],
      '#options' => array_combine($options, $options),
      '#required' => TRUE,
    );
  }
}
