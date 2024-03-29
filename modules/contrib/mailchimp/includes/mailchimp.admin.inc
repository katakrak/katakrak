<?php

/**
 * @file
 * MailChimp module admin settings.
 */

/**
 * Return the MailChimp global settings form.
 */
function mailchimp_admin_settings() {
  $form['mailchimp_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('MailChimp API Key'),
    '#required' => TRUE,
    '#default_value' => variable_get('mailchimp_api_key', ''),
    '#description' => t('The API key for your MailChimp account. Get or generate a valid API key at your !apilink.', array('!apilink' => l(t('MailChimp API Dashboard'), 'http://admin.mailchimp.com/account/api'))),
  );

  if (mailchimp_get_api_object() && class_exists('\Mailchimp\MailchimpConnectedSites')) {
    $form['connected_sites'] = array(
      '#type' => 'fieldset',
      '#title' => t('Connected sites'),
    );

    $form['connected_sites']['mailchimp_enable_connected'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable connected site'),
      '#description' => t("Connects this website to MailChimp by automatically embedding MailChimp's !link JavaScript code.", array(
        '!link' => l(t('Connected Sites'), 'https://kb.mailchimp.com/integrations/connected-sites/about-connected-sites'),
      )),
      '#default_value' => variable_get('mailchimp_enable_connected', FALSE),
    );

    $connected_sites_options = array();
    try {
      /* @var \Mailchimp\MailchimpConnectedSites $mc_connected */
      $mc_connected = mailchimp_get_api_object('MailchimpConnectedSites');
      if ($mc_connected) {
        $connected_sites = $mc_connected->getConnectedSites();
        if (!empty($connected_sites) && !empty($connected_sites->sites)) {
          foreach ($connected_sites->sites as $site) {
            $connected_sites_options[$site->foreign_id] = $site->domain;
          }
        }
      }
    }
    catch (\Mailchimp\MailchimpAPIException $e) {
      watchdog(
        'mailchimp',
        'An error occurred while connecting to api. "%message"',
        array('%message' => $e->getMessage()),
        WATCHDOG_ERROR
      );

      drupal_set_message(
        t('Failed connecting to the MailChimp backend with the provided API key.'),
        'error'
      );
    }

    $form['connected_sites']['config'] = array(
      '#type' => 'container',
      '#states' => array(
        'invisible' => array(
          ':input[name="mailchimp_enable_connected"]' => array('checked' => FALSE),
        ),
      ),
    );

    if (!empty($connected_sites_options)) {
      // If the MailChimp account contains connected sites, allow the user to
      // choose one here.
      $form['connected_sites']['config']['mailchimp_connected_id'] = array(
        '#type' => 'radios',
        '#options' => $connected_sites_options,
        '#default_value' => variable_get('mailchimp_connected_id', FALSE),
        '#prefix' => t('<p><b>Choose a connected site from your MailChimp account.</b></p>'),
      );

      // Allow the user to configure which paths to embed JavaScript on.
      $form['connected_sites']['config']['mailchimp_connected_paths'] = array(
        '#type' => 'textarea',
        '#default_value' => variable_get('mailchimp_connected_paths', FALSE),
        '#prefix' => t("<p><b>Configure paths to embed MailChimp's JavaScript code on.</b></p>"),
        '#description' => t('Specify pages using their paths. Enter one path per line. <front> is the front page. If you have created a pop-up subscription form in MailChimp, it will appear on paths defined here.'),
      );
    }
    else {
      // If the MailChimp account does not contain any connected sites, gently
      // encourage the user to create one.
      $form['connected_sites']['sites']['info'] = array(
        '#type' => 'markup',
        '#markup' => t("You'll need to connect this site to MailChimp first! !link.", array(
          '!link' => l(t('Check out the documentation here'), 'https://kb.mailchimp.com/integrations/connected-sites/about-connected-sites'),
        )),
      );
    }
  }
  else {
    drupal_set_message(
      t('Your Mailchimp library version is incorrect. Download the <a href="@release">latest v2 (NOT v3!) release here</a> to make use of the "Connected sites" functionality.', array(
        '@release' => 'https://github.com/thinkshout/mailchimp-api-php/releases',
      )),
    'warning');
  }

  $form['batch'] = array(
    '#type' => 'fieldset',
    '#title' => t('Batch processing'),
  );

  $form['batch']['mailchimp_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use batch processing'),
    '#description' => t('Puts all MailChimp subscription operations into the cron queue. (Includes subscribe, update, and unsubscribe operations.) <i>Note: May cause confusion if caches are cleared, as requested changes will appear to have failed until cron is run.</i>'),
    '#default_value' => variable_get('mailchimp_cron', FALSE),
  );

  $form['batch']['mailchimp_batch_limit'] = array(
    '#type' => 'select',
    '#options' => array(
      '1' => '1',
      '10' => '10',
      '25' => '25',
      '50' => '50',
      '75' => '75',
      '100' => '100',
      '250' => '250',
      '500' => '500',
      '750' => '750',
      '1000' => '1000',
      '2500' => '2500',
      '5000' => '5000',
      '7500' => '7500',
      '10000' => '10000',
    ),
    '#title' => t('Batch limit'),
    '#description' => t('Maximum number of entities to process in a single cron run. MailChimp suggest keeping this at 5000 or below. <i>This value is also used for batch Merge Variable updates on the Fields tab (part of mailchimp_lists).</i>'),
    '#default_value' => variable_get('mailchimp_batch_limit', 100),
  );

  $form['mailchimp_api_timeout'] = [
    '#type'             => 'textfield',
    '#title'            => t('MailChimp API Timeout'),
    '#required'         => TRUE,
    '#default_value'    => variable_get('mailchimp_api_timeout', 60),
    '#description'      => t('The timeout (in seconds) for calls to the MailChimp API. Set to something that won\'t take down the Drupal site.'),
    '#element_validate' => ['element_validate_integer_positive'],
    '#maxlength'        => 10,
  ];

  return system_settings_form($form);
}

/**
 * MailChimp List/Audience cache clear form.
 */
function mailchimp_clear_list_cache_form($form, &$form_state) {
  $cancel_destination = 'admin/config/services/mailchimp';
  return confirm_form($form,
    t('Reset MailChimp Audience Cache'),
    $cancel_destination,
    t('Confirm clearing of MailChimp audience cache.'),
    'Confirm'
  );
}

/**
 * Handler for lists/audiences cache clear form.
 */
function mailchimp_clear_list_cache_form_submit($form, &$form_state) {
  mailchimp_get_lists(array(), TRUE, TRUE, TRUE);
  drupal_set_message(t('MailChimp Audience cache cleared.'));
}
