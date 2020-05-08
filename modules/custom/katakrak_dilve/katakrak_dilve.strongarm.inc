<?php
/**
 * @file
 * katakrak_dilve.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function katakrak_dilve_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dilve_pass';
  $strongarm->value = 'HOFO983Z';
  $export['dilve_pass'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dilve_user';
  $strongarm->value = 'xmaezturebole01';
  $export['dilve_user'] = $strongarm;

  return $export;
}
