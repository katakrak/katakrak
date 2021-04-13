<?php

/**
 * @file
 * katakrak_sukaldea.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function katakrak_sukaldea_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu|node|sukalde_errezeta|form';
  $field_group->group_name = 'group_menu';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sukalde_errezeta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Información para el menu',
    'weight' => '2',
    'children' => array(
      0 => 'field_errezeta_nombre_carta_eus',
      1 => 'field_image',
      2 => 'field_alergenos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-menu field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_menu|node|sukalde_errezeta|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preparacion|node|sukalde_errezeta|form';
  $field_group->group_name = 'group_preparacion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sukalde_errezeta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Preparacion',
    'weight' => '5',
    'children' => array(
      0 => 'field_errezeta_prezioa',
      1 => 'field_produktua_kopurua',
      2 => 'field_errezeta_preparacion',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-preparacion field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_preparacion|node|sukalde_errezeta|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_producto_final|node|sukalde_errezeta|form';
  $field_group->group_name = 'group_producto_final';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sukalde_errezeta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Producto final',
    'weight' => '6',
    'children' => array(
      0 => 'field_errezeta_porzio_kopurua',
      1 => 'field_produktua_prezioa',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-producto-final field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_producto_final|node|sukalde_errezeta|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Información para el menu');
  t('Preparacion');
  t('Producto final');

  return $field_groups;
}
