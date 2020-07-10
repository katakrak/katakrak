<?php

/**
 * @file
 * katakrak_commerce.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function katakrak_commerce_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_cart_contents_pane_view';
  $strongarm->value = 'katakrak_commerce_cart_summary|default';
  $export['commerce_cart_contents_pane_view'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_cart_refresh_frequency';
  $strongarm->value = 0;
  $export['commerce_cart_refresh_frequency'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_checkout_completion_message';
  $strongarm->value = array(
    'value' => 'Tu número de pedido es el [commerce-order:order-number]. Puedes ver <a href="[commerce-order:url]">tu pedidor</a> en tu página de usuario.

<a href="[site:url]">Volver a la portada.</a>',
    'format' => 'filtered_html',
  );
  $export['commerce_checkout_completion_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_checkout_redirect_anonymous';
  $strongarm->value = 0;
  $export['commerce_checkout_redirect_anonymous'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_checkout_redirect_anonymous_as_login_option';
  $strongarm->value = 0;
  $export['commerce_checkout_redirect_anonymous_as_login_option'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_checkout_redirect_message';
  $strongarm->value = 'Tienes que acceder con tu cuenta para poder realizar una compra.';
  $export['commerce_checkout_redirect_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_checkout_redirect_path';
  $strongarm->value = '';
  $export['commerce_checkout_redirect_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_checkout_redirect_reset_password_message';
  $strongarm->value = 'You can also continue with the checkout process.';
  $export['commerce_checkout_redirect_reset_password_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_checkout_redirect_username_as_order_email';
  $strongarm->value = 0;
  $export['commerce_checkout_redirect_username_as_order_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_customer_profile_billing_addressbook';
  $strongarm->value = 1;
  $export['commerce_customer_profile_billing_addressbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_customer_profile_shipping_addressbook';
  $strongarm->value = 0;
  $export['commerce_customer_profile_shipping_addressbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_customer_profile_shipping_profile_copy';
  $strongarm->value = 1;
  $export['commerce_customer_profile_shipping_profile_copy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_customer_profile_shipping_profile_copy_default';
  $strongarm->value = 1;
  $export['commerce_customer_profile_shipping_profile_copy_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_customer_profile_shipping_profile_copy_source';
  $strongarm->value = 'billing';
  $export['commerce_customer_profile_shipping_profile_copy_source'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_donate_checkout_pane_description';
  $strongarm->value = '';
  $export['commerce_donate_checkout_pane_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_donate_checkout_pane_donate_amounts';
  $strongarm->value = '';
  $export['commerce_donate_checkout_pane_donate_amounts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_donate_checkout_pane_override_options';
  $strongarm->value = 0;
  $export['commerce_donate_checkout_pane_override_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_donate_checkout_pane_product_id';
  $strongarm->value = '76452';
  $export['commerce_donate_checkout_pane_product_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_donate_checkout_pane_title';
  $strongarm->value = 'Donación';
  $export['commerce_donate_checkout_pane_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_order_account_pane_auth_display';
  $strongarm->value = 0;
  $export['commerce_order_account_pane_auth_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_order_account_pane_mail_double_entry';
  $strongarm->value = 0;
  $export['commerce_order_account_pane_mail_double_entry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_order_apply_pricing_rules_link';
  $strongarm->value = FALSE;
  $export['commerce_order_apply_pricing_rules_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_order_simulate_checkout_link';
  $strongarm->value = FALSE;
  $export['commerce_order_simulate_checkout_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_payment_pane_require_method';
  $strongarm->value = 1;
  $export['commerce_payment_pane_require_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_shipping_pane_require_service';
  $strongarm->value = 1;
  $export['commerce_shipping_pane_require_service'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_shipping_recalculate_services';
  $strongarm->value = 1;
  $export['commerce_shipping_recalculate_services'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_commerce_checkout_order_created_date_update';
  $strongarm->value = FALSE;
  $export['enable_commerce_checkout_order_created_date_update'] = $strongarm;

  return $export;
}
