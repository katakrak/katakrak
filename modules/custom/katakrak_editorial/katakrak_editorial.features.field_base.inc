<?php
/**
 * @file
 * katakrak_editorial.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function katakrak_editorial_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_autor_nacimiento'.
  $field_bases['field_autor_nacimiento'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_autor_nacimiento',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_editorial_libro'.
  $field_bases['field_editorial_libro'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_editorial_libro',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'article' => 0,
        'autor_ed' => 0,
        'blog' => 0,
        'boletin' => 0,
        'ciclo' => 0,
        'eguneko_menua' => 0,
        'event' => 0,
        'imagen' => 0,
        'itinerario' => 0,
        'libro' => 'libro',
        'libro_ed' => 0,
        'page' => 0,
        'portfolio' => 0,
        'receta' => 0,
        'simplenews' => 0,
        'sukalde_errezeta' => 0,
        'sukalde_produktua' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_libro_ed_autor'.
  $field_bases['field_libro_ed_autor'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_libro_ed_autor',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'article' => 0,
        'autor_ed' => 'autor_ed',
        'blog' => 0,
        'boletin' => 0,
        'ciclo' => 0,
        'eguneko_menua' => 0,
        'event' => 0,
        'imagen' => 0,
        'itinerario' => 0,
        'libro' => 0,
        'libro_ed' => 0,
        'page' => 0,
        'portfolio' => 0,
        'receta' => 0,
        'simplenews' => 0,
        'sukalde_errezeta' => 0,
        'sukalde_produktua' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_libro_ed_encuadernacion'.
  $field_bases['field_libro_ed_encuadernacion'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_libro_ed_encuadernacion',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_libro_ed_precio'.
  $field_bases['field_libro_ed_precio'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_libro_ed_precio',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'precision' => 10,
      'scale' => 2,
    ),
    'translatable' => 0,
    'type' => 'number_decimal',
  );

  // Exported field_base: 'field_libro_ed_prologo'.
  $field_bases['field_libro_ed_prologo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_libro_ed_prologo',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_libro_ed_proxima'.
  $field_bases['field_libro_ed_proxima'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_libro_ed_proxima',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => 'Próxima aparición?',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_libro_ed_tamano'.
  $field_bases['field_libro_ed_tamano'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_libro_ed_tamano',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_libro_ed_traductor'.
  $field_bases['field_libro_ed_traductor'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_libro_ed_traductor',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'article' => 0,
        'autor_ed' => 'autor_ed',
        'blog' => 0,
        'boletin' => 0,
        'ciclo' => 0,
        'eguneko_menua' => 0,
        'event' => 0,
        'imagen' => 0,
        'itinerario' => 0,
        'libro' => 0,
        'libro_ed' => 0,
        'page' => 0,
        'portfolio' => 0,
        'receta' => 0,
        'simplenews' => 0,
        'sukalde_errezeta' => 0,
        'sukalde_produktua' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_libro_editorial_nota'.
  $field_bases['field_libro_editorial_nota'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_libro_editorial_nota',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  return $field_bases;
}
