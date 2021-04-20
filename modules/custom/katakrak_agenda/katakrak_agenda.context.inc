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
        'agenda:page_1' => 'agenda:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_agenda-katakrak_agenda_banner_organiza' => array(
          'delta' => 'katakrak_agenda_banner_organiza',
          'module' => 'katakrak_agenda',
          'region' => 'banners',
          'weight' => '-10',
        ),
        'katakrak_agenda-katakrak_agenda_nav_secundary' => array(
          'delta' => 'katakrak_agenda_nav_secundary',
          'module' => 'katakrak_agenda',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_agenda-katakrak_agenda_search' => array(
          'delta' => 'katakrak_agenda_search',
          'module' => 'katakrak_agenda',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
      'layout' => 'agenda',
    ),
    'menu' => array(
      0 => 'menu-menu-nagusia:agenda',
    ),
    'theme' => array(
      'subtitle' => '',
      'title' => 'Agenda',
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
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda landing page');
  t('Landing');
  $export['agenda_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node_event';
  $context->description = '';
  $context->tag = 'Agenda';
  $context->conditions = array(
    'node' => array(
      'options' => array(
        'node_form' => '0',
      ),
      'values' => array(
        'ciclo' => 'ciclo',
        'event' => 'event',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:agenda',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  $export['node_event'] = $context;

  return $export;
}
