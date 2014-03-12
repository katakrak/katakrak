<?php
/**
 * @file
 * katakrak_kantina.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function katakrak_kantina_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_portfolio_es_pattern';
  $strongarm->value = 'cantina/producto/[node:title]';
  $export['pathauto_node_portfolio_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_portfolio_eu_pattern';
  $strongarm->value = 'kantina/produktua/[node:title]';
  $export['pathauto_node_portfolio_eu_pattern'] = $strongarm;

  return $export;
}
