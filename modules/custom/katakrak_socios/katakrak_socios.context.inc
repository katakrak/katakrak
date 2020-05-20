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
        'hazte-socix*' => 'hazte-socix*',
        'egin-zaitez-bazkide*' => 'egin-zaitez-bazkide*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_socios-banner_socios' => array(
          'module' => 'katakrak_socios',
          'delta' => 'banner_socios',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_socios-alta_socios' => array(
          'module' => 'katakrak_socios',
          'delta' => 'alta_socios',
          'region' => 'content_campana_left',
          'weight' => '-10',
        ),
        'views-agenda-como_hacer_krak' => array(
          'module' => 'views',
          'delta' => 'agenda-como_hacer_krak',
          'region' => 'content_campana_right',
          'weight' => '-57',
        ),
        'views-agenda-radical_may' => array(
          'module' => 'views',
          'delta' => 'agenda-radical_may',
          'region' => 'content_campana_right',
          'weight' => '-56',
        ),
        'katakrak_socios-katakrak_en_datos' => array(
          'module' => 'katakrak_socios',
          'delta' => 'katakrak_en_datos',
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
