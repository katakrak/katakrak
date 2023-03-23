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
  $context->tag = 'Agenda';
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
  t('Agenda');
  t('Agenda landing page');
  $export['agenda_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ciclos_landing';
  $context->description = '';
  $context->tag = 'Ciclos';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'ciclos' => 'ciclos',
        'zikloak' => 'zikloak',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_agenda-centro_estudios_page_hero' => array(
          'delta' => 'centro_estudios_page_hero',
          'module' => 'katakrak_agenda',
          'region' => 'hero',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ciclos');
  $export['ciclos_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pagina_agenda';
  $context->description = 'Página inicial de agenda';
  $context->tag = 'Agenda';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'agenda' => 'agenda',
        'agenda/audios' => 'agenda/audios',
        'agenda/grupos' => 'agenda/grupos',
        'agenda/pasados' => 'agenda/pasados',
        'egitaraua' => 'egitaraua',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_agenda-katakrak_agenda_nav_secundary' => array(
          'delta' => 'katakrak_agenda_nav_secundary',
          'module' => 'katakrak_agenda',
          'region' => 'hero',
          'weight' => '-10',
        ),
        'katakrak_agenda-katakrak_agenda_search' => array(
          'delta' => 'katakrak_agenda_search',
          'module' => 'katakrak_agenda',
          'region' => 'content_top_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  t('Página inicial de agenda');
  $export['pagina_agenda'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pagina_nncc';
  $context->description = 'Páginas NNCC';
  $context->tag = 'Ciclos';
  $context->conditions = array(
    'node' => array(
      'options' => array(
        'node_form' => '1',
      ),
      'values' => array(
        'ciclo' => 'ciclo',
      ),
    ),
    'path' => array(
      'values' => array(
        'ciclos*' => 'ciclos*',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ciclos');
  t('Páginas NNCC');
  $export['pagina_nncc'] = $context;

  return $export;
}
