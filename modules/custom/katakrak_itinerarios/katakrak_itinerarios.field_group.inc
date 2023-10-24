<?php

/**
 * @file
 * katakrak_itinerarios.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function katakrak_itinerarios_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_itinerario_info|node|itinerario|form';
  $field_group->group_name = 'group_itinerario_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'itinerario';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_itinerario_descripcion',
      1 => 'field_itinerario_color',
      2 => 'field_itinerario_linea',
      3 => 'language',
      4 => 'path',
      5 => 'field_itinerario_imagen',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-itinerario-info field-group-fieldset',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Itinerario',
    ),
    'format_type' => 'fieldset',
    'label' => 'Itinerario',
    'weight' => '1',
  );
  $field_groups['group_itinerario_info|node|itinerario|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_itinerario_paradas|node|itinerario|form';
  $field_group->group_name = 'group_itinerario_paradas';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'itinerario';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_itinerario_paradas',
    ),
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'classes' => 'group-itinerario-paradas field-group-fieldset',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Paradas',
    ),
    'format_type' => 'fieldset',
    'label' => 'Paradas',
    'weight' => '2',
  );
  $field_groups['group_itinerario_paradas|node|itinerario|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Itinerario');
  t('Paradas');

  return $field_groups;
}
