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
    'path' => array(
      'values' => array(
        'buscar/agenda*' => 'buscar/agenda*',
      ),
    ),
    'views' => array(
      'values' => array(
        'agenda:eventos_pasados' => 'agenda:eventos_pasados',
        'agenda:events_page' => 'agenda:events_page',
        'agenda:grupos_de_lectura' => 'agenda:grupos_de_lectura',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_agenda-katakrak_agenda_search' => array(
          'module' => 'katakrak_agenda',
          'delta' => 'katakrak_agenda_search',
          'region' => 'content',
          'weight' => '-10',
        ),
        'katakrak_agenda-katakrak_agenda_banner_organiza' => array(
          'module' => 'katakrak_agenda',
          'delta' => 'katakrak_agenda_banner_organiza',
          'region' => 'banners',
          'weight' => '-10',
        ),
        'katakrak_agenda-katakrak_agenda_nav_secundary' => array(
          'module' => 'katakrak_agenda',
          'delta' => 'katakrak_agenda_nav_secundary',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'agenda',
    ),
    'menu' => array(
      0 => 'menu-menu-nagusia:agenda',
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
  $context->name = 'node_event';
  $context->description = '';
  $context->tag = 'Agenda';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ciclo' => 'ciclo',
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'menu-menu-nagusia:agenda',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  $export['node_event'] = $context;

  return $export;
}
