<?php
/**
 * @file
 * katakrak_blog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function katakrak_blog_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resenas_prensa|node|blog|form';
  $field_group->group_name = 'group_resenas_prensa';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Reseñas prensa',
    'weight' => '12',
    'children' => array(
      0 => 'field_cita',
      1 => 'field_fuente_cita',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-resenas-prensa field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_resenas_prensa|node|blog|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Reseñas prensa');

  return $field_groups;
}
