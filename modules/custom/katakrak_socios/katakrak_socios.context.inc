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
  $context->tag = 'katakrak socios';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'hazte-socio*' => 'hazte-socio*',
        'egin-zaitez-bazkide*' => 'egin-zaitez-bazkide*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-agenda-como_hacer_krak' => array(
          'module' => 'views',
          'delta' => 'agenda-como_hacer_krak',
          'region' => 'content_campana_right',
          'weight' => '-10',
        ),
      ),
      'layout' => 'campana',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('La página de la campaña de socios');
  t('katakrak socios');
  $export['campana-socios'] = $context;

  return $export;
}
