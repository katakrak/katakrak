<?php
/**
 * @file
 * Definition of views_bootstrap_plugin_style.
 */

/**
 * Class to define a style plugin handler.
 */
class katakrak_agenda_grid_plugin_style extends views_plugin_style {
  /**
   * Definition.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['first_row_columns'] = array('default' => '1');
    $options['second_row_columns'] = array('default' => '2');
    $options['columns'] = array('default' => 3);
    return $options;
  }

  /**
   * Form.
   */
  function options_form(&$form, &$form_state) {
    $options = array(1, 2, 3, 4, 6, 12);
    $form['first_row_columns'] = array(
      '#type' => 'select',
      '#title' => t('Number of columns for the first row'),
      '#default_value' => $this->options['first_row_columns'],
      '#options' => array_combine($options, $options),
      '#required' => TRUE,
    );
    $form['second_row_columns'] = array(
      '#type' => 'select',
      '#title' => t('Number of columns for the second row'),
      '#default_value' => $this->options['second_row_columns'],
      '#options' => array_combine($options, $options),
      '#required' => TRUE,
    );
    $form['columns'] = array(
      '#type' => 'select',
      '#title' => t('Number of columns for the rest'),
      '#default_value' => $this->options['columns'],
      '#options' => array_combine($options, $options),
      '#required' => TRUE,
    );
  }
}
