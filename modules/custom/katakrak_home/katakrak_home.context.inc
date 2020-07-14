<?php

/**
 * @file
 * katakrak_home.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_home_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Home context';
  $context->tag = 'Home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-8',
        ),
        'katakrak_home-katakrak_home_banner' => array(
          'module' => 'katakrak_home',
          'delta' => 'katakrak_home_banner',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_home-katakrak_home_libreria' => array(
          'module' => 'katakrak_home',
          'delta' => 'katakrak_home_libreria',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        'katakrak_home-katakrak_home_espacio' => array(
          'module' => 'katakrak_home',
          'delta' => 'katakrak_home_espacio',
          'region' => 'content_top_right',
          'weight' => '-10',
        ),
        'katakrak_home-katakrak_home_kantina' => array(
          'module' => 'katakrak_home',
          'delta' => 'katakrak_home_kantina',
          'region' => 'content_middle_first',
          'weight' => '-10',
        ),
        'katakrak_home-katakrak_home_editorial' => array(
          'module' => 'katakrak_home',
          'delta' => 'katakrak_home_editorial',
          'region' => 'content_middle_second',
          'weight' => '-10',
        ),
        'katakrak_home-katakrak_home_agenda' => array(
          'module' => 'katakrak_home',
          'delta' => 'katakrak_home_agenda',
          'region' => 'content_middle_third',
          'weight' => '-9',
        ),
        'views-agenda-agenda_home' => array(
          'module' => 'views',
          'delta' => 'agenda-agenda_home',
          'region' => 'content_middle_third',
          'weight' => '-8',
        ),
      ),
      'layout' => 'home',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  t('Home context');
  $export['home'] = $context;

  return $export;
}
