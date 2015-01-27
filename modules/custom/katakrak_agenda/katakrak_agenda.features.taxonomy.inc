<?php
/**
 * @file
 * katakrak_agenda.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function katakrak_agenda_taxonomy_default_vocabularies() {
  return array(
    'ciclo' => array(
      'name' => 'Ciclo',
      'machine_name' => 'ciclo',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
    'event_type' => array(
      'name' => 'Event Type',
      'machine_name' => 'event_type',
      'description' => 'Event Categories for the AIO Calendar',
      'hierarchy' => 0,
      'module' => 'aiocalendar',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
