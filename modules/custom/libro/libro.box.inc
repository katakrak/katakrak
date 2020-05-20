<?php

/**
 * @file
 * libro.box.inc
 */

/**
 * Implements hook_default_box().
 */
function libro_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'bizikrak';
  $box->plugin_key = 'simple';
  $box->title = 'Bizikrak';
  $box->description = 'Bizikrak banner';
  $box->options = array(
    'body' => array(
      'value' => '<img src="https://katakrak.net/sites/all/themes/coworker/images/bizikrak.gif" >',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['bizikrak'] = $box;

  return $export;
}
