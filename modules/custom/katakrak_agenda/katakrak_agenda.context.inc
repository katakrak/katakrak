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
  $context->name = 'agenda';
  $context->description = 'Agenda';
  $context->tag = 'Agenda';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'agenda:events_page' => 'agenda:events_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ciclos-block' => array(
          'module' => 'views',
          'delta' => 'ciclos-block',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
        'views-agenda-isotope_filter' => array(
          'module' => 'views',
          'delta' => 'agenda-isotope_filter',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'agenda',
    ),
    'menu' => array(
      0 => 'main-menu:agenda',
    ),
    'theme' => array(
      'title' => 'Agenda',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  $export['agenda'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calendario';
  $context->description = 'Calendario view';
  $context->tag = 'Agenda';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'agenda:calendario' => 'agenda:calendario',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'agenda',
    ),
    'menu' => array(
      0 => 'main-menu:agenda',
    ),
    'theme' => array(
      'title' => 'Agenda',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  t('Calendario view');
  $export['calendario'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node_event';
  $context->description = '';
  $context->tag = 'Agenda';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-agenda-next_events_node_block' => array(
          'module' => 'views',
          'delta' => 'agenda-next_events_node_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
      'layout' => 'agenda',
    ),
    'menu' => array(
      0 => 'main-menu:actos',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  $export['node_event'] = $context;

  return $export;
}
