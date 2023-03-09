<?php

/**
 * @file
 * katakrak_agenda.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_agenda_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agenda_landing';
  $context->description = 'Agenda landing page';
  $context->tag = 'Landing';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'organiza_evento' => 'organiza_evento',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_agenda-agenda_landing_baldosas' => array(
          'delta' => 'agenda_landing_baldosas',
          'module' => 'katakrak_agenda',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_agenda-agenda_landing_destacado' => array(
          'delta' => 'agenda_landing_destacado',
          'module' => 'katakrak_agenda',
          'region' => 'banners',
          'weight' => '-10',
        ),
        'katakrak_agenda-agenda_landing_form' => array(
          'delta' => 'agenda_landing_form',
          'module' => 'katakrak_agenda',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'katakrak_agenda-agenda_landing_visitado' => array(
          'delta' => 'agenda_landing_visitado',
          'module' => 'katakrak_agenda',
          'region' => 'content_middle',
          'weight' => '-10',
        ),
      ),
      'layout' => 'landing',
    ),
    'menu' => array(
      0 => 'main-menu:agenda',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda landing page');
  t('Landing');
  $export['agenda_landing'] = $context;

  return $export;
}
