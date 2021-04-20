<?php

/**
 * @file
 * katakrak_contact.box.inc
 */

/**
 * Implements hook_default_box().
 */
function katakrak_contact_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'mapa';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Mapa';
  $box->options = array(
    'additional_classes' => '',
    'body' => array(
      'format' => 'full_html',
      'value' => '<iframe src="https://www.google.com/maps/embed?pb=!1m5!3m3!1m2!1s0xd5092f74996f207%3A0xa6b732eaa3b47b44!2sNagusia+Kalea%2C+54%2C+31001+Iru%C3%B1a%2C+Nafarroa%2C+Espainia!5e0!3m2!1seu!2s!4v1386062278823" width="600" height="450" frameborder="0" style="border:0"></iframe>',
    ),
  );
  $export['mapa'] = $box;

  return $export;
}
