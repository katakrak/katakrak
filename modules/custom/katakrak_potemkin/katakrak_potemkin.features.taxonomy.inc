<?php
/**
 * @file
 * katakrak_potemkin.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function katakrak_potemkin_taxonomy_default_vocabularies() {
  return array(
    'genero_dvd' => array(
      'name' => 'Género DVD',
      'machine_name' => 'genero_dvd',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'movie_stars' => array(
      'name' => 'Movie stars',
      'machine_name' => 'movie_stars',
      'description' => 'Actores de una película',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
