<?php
/**
 * @file
 * potemkin.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function katakrak_potemkin_taxonomy_default_vocabularies() {
  return array(
    'actores' => array(
      'name' => 'Actores',
      'machine_name' => 'actores',
      'description' => 'Actores de una película',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'directores' => array(
      'name' => 'Directores',
      'machine_name' => 'directores',
      'description' => 'Director de una película',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
