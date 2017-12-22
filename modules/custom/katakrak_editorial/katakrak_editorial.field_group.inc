<?php
/**
 * @file
 * katakrak_editorial.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function katakrak_editorial_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_libro_ed_ficha|node|libro_ed|form';
  $field_group->group_name = 'group_libro_ed_ficha';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'libro_ed';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ficha técnica',
    'weight' => '11',
    'children' => array(
      0 => 'field_libro_ed_encuadernacion',
      1 => 'field_libro_ed_precio',
      2 => 'field_libro_ed_tamano',
      3 => 'field_libro_idioma',
      4 => 'field_libro_isbn',
      5 => 'field_libro_paginas',
      6 => 'field_libro_editorial_nota',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-libro-ed-ficha field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_libro_ed_ficha|node|libro_ed|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ficha técnica');

  return $field_groups;
}
