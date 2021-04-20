<?php

/**
 * @file
 * katakrak_agenda.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function katakrak_agenda_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ciclo_info|node|ciclo|form';
  $field_group->group_name = 'group_ciclo_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ciclo';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_image',
      1 => 'field_ciclo_descripci_n',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-ciclo-info field-group-fieldset',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Info',
    'weight' => '2',
  );
  $field_groups['group_ciclo_info|node|ciclo|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Info');

  return $field_groups;
}
