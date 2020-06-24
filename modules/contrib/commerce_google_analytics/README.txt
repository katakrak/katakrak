Description
-----------

This is a contribution to Drupal Commerce. This module adds the possibility to
send the order data to the Google Analytics service.

Requirements
------------

This module requires:

  - Google Analytics module: https://www.drupal.org/project/google_analytics
  - Ga Push module: https://www.drupal.org/project/ga_push

Features
--------

Rules implementation which let you control when to send the analytics code to
google analytics.

Usage
-----

GA Push server-side methods are recommended. e.g:

  - Universal Analytics: UTMP-PHP.
  - Classic Analytics: PHP-GA library (see ga_push README.txt).

Important:

- Server-side methods (php) send data to google analytics directly from the PHP
layer.

- Javascript methods needs a browser with Javascript enabled.

Some payments like PayPal call the drupal commerce site to confirm the payment
in a custom menu callback (e.g. IPN) triggering "order paid in full" but without
javascript support.

Note that "paid in full" is triggered only when the order is first paid in full.
In the other hand order completed (by default) is triggered when the user comes
back from the payment server to "checkout/{order_id}/complete". So if the user
doesn`t come back the action is not triggered.

According to common needs the recommended configuration is utmp-php (universal)
+ "paid in full" event but it depends on your payment enabled methods. You may
even have to use both triggers with rules conditions to support both scenarios.

The module provides the action to send google analytics transaction data from an
order.

If you need to change the default rules action or add a new custom rule do it.
Take into account that both events could be triggered, making the data to be
sent to google twice (add rules conditions logic to avoid this).

You can configure it on:

  - ga_push settings (globally): /admin/config/system/ga-push

  - rules settings:
    /admin/config/workflow/rules/reaction/manage/commerce_google_analytics_rule_ga
