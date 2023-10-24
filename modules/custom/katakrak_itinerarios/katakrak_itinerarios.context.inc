<?php

/**
 * @file
 * katakrak_itinerarios.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_itinerarios_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'itinerario';
  $context->description = '';
  $context->tag = 'Libro';
  $context->conditions = array(
    'node' => array(
      'options' => array(
        'node_form' => '1',
      ),
      'values' => array(
        'itinerario' => 'itinerario',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'book',
    ),
    'menu' => array(
      0 => 'main-menu:libreria',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Libro');
  $export['itinerario'] = $context;

  return $export;
}
