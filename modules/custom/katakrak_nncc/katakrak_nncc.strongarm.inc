<?php

/**
 * @file
 * katakrak_nncc.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function katakrak_nncc_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_ciclo_options';
  $strongarm->value = array(
    'full' => 0,
    'rss' => 0,
    'search_index' => 0,
    'search_result' => 0,
    'teaser' => 0,
    'token' => 0,
  );
  $export['sharethis_ciclo_options'] = $strongarm;

  return $export;
}
