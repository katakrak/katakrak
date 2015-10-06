<?php
/**
 * @file
 * libro.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function libro_taxonomy_default_vocabularies() {
  return array(
    'autores' => array(
      'name' => 'Autor',
      'machine_name' => 'autores',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'editoriales' => array(
      'name' => 'Editorial',
      'machine_name' => 'editoriales',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'materias' => array(
      'name' => 'Sección',
      'machine_name' => 'materias',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'urtea' => array(
      'name' => 'Año',
      'machine_name' => 'urtea',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
