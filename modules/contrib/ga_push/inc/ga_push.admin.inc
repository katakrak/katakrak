<?php
/**
 * @file
 * The administration functions and forms.
 */

/**
 * Form: GA Push settings.
 */
function ga_push_settings_form($form, &$form_state) {

  $options = ga_push_get_methods_option_list(NULL, FALSE);

  $help = array(
    '#theme' => 'item_list',
    '#items' => array(
      t("Universal methods are compatible with google_analytics 2.x (recommended), Classic methods are compatible with google_analytics 1.x"),
      t("Client-side: the action will be sent on the next page load - Server-side: the action will be sent immediately."),
    ),
  );

  $form['help'] = array(
    '#markup' => render($help),
  );

  $form['ga_push_default_method'] = array(
    '#type' => 'radios',
    '#title' => t('Default method'),
    '#options' => $options,
    '#default_value' => variable_get('ga_push_default_method', GA_PUSH_METHOD_ANALYTICS_JS),
    '#description' => t("Select the default method, it could be overriden in function call or each configuration of rules."),
    '#required' => TRUE,
  );

  $form['ga_push_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Debug mode'),
    '#default_value' => variable_get('ga_push_debug', FALSE),
    '#description' => t('Active the debug mode: log GA push requests.'),
  );

  return system_settings_form($form);
}
