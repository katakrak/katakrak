<?php

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_google_analytics_default_rules_configuration() {
  $rule = rules_reaction_rule();
  $rule->label = 'Send google analytics code when an order is first paid in full';
  $rule->active = TRUE;
  $rule->event('commerce_payment_order_paid_in_full')
    ->action('commerce_google_analytics_send_order', array(
      'commerce_order:select' => 'commerce_order',
      'method' => GA_PUSH_METHOD_UTMP_PHP,
    )
  );
  $configs['commerce_google_analytics_rule_ga'] = $rule;

  // Default rule for storing Analytics cid on order save.
  // @DEPRECATED: action included in "save_extras_to_order" and will be removed.
  $rule = rules_reaction_rule();
  $rule->label = 'Store google analytics session to order on checkout begin';
  $rule->active = FALSE;
  $rule->event('commerce_order_presave')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'checkout_checkout',
    ))
    ->action('commerce_google_analytics_save_ga_session_to_order', array(
      'commerce_order:select' => 'commerce_order',
    )
  );
  $configs['commerce_google_analytics_rule_save_session'] = $rule;

  // Default rule for storing Analytics extra info on order save.
  $rule = rules_reaction_rule();
  $rule->label = 'Store google analytics extra user variables to order on checkout begin';
  $rule->active = TRUE;
  $rule->event('commerce_order_presave')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'checkout_checkout',
    ))
    ->action('commerce_google_analytics_save_ga_session_to_order', array(
      'commerce_order:select' => 'commerce_order',
    ))
    ->action('commerce_google_analytics_save_ga_ua_to_order', array(
      'commerce_order:select' => 'commerce_order',
    ))
    ->action('commerce_google_analytics_save_ga_uip_to_order', array(
      'commerce_order:select' => 'commerce_order',
    )
  );
  $configs['commerce_google_analytics_rule_save_extras_to_order'] = $rule;

  return $configs;
}
