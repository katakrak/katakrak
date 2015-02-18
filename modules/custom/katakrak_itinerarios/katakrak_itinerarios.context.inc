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
  $context->tag = 'Book';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'itinerario' => 'itinerario',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'theme' => array(
      'title' => 'Leer os hará libros',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Book');
  $export['itinerario'] = $context;

  return $export;
}
