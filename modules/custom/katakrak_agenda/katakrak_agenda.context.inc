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
        'agenda:agenda_page' => 'agenda:agenda_page',
        'agenda:events_page' => 'agenda:events_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-agenda-highlight' => array(
          'module' => 'views',
          'delta' => 'agenda-highlight',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'agenda',
    ),
    'menu' => array(
      0 => 'main-menu:agenda',
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
        'boxes-twitter_feed' => array(
          'module' => 'boxes',
          'delta' => 'twitter_feed',
          'region' => 'sidebar_second',
          'weight' => '-9',
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
  $export['node_event'] = $context;

  return $export;
}
