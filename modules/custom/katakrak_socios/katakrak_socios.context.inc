<?php

/**
 * @file
 * katakrak_socios.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_socios_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'campana-socios';
  $context->description = 'La página de la campaña de socios';
  $context->tag = 'Landing';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'hazte-socix*' => 'hazte-socix*',
        'egin-zaitez-bazkide*' => 'egin-zaitez-bazkide*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak-breadcrumb_home' => array(
          'module' => 'katakrak',
          'delta' => 'breadcrumb_home',
          'region' => 'banners',
          'weight' => '-10',
        ),
        'katakrak_socios-katakrak_socixs_campana' => array(
          'module' => 'katakrak_socios',
          'delta' => 'katakrak_socixs_campana',
          'region' => 'hero',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('La página de la campaña de socios');
  t('Landing');
  $export['campana-socios'] = $context;

  return $export;
}
