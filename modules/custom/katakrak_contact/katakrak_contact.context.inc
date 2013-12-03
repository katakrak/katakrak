<?php
/**
 * @file
 * katakrak_contact.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_contact_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contacto';
  $context->description = 'Página de contacto';
  $context->tag = 'contacto';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact' => 'contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-mapa' => array(
          'module' => 'boxes',
          'delta' => 'mapa',
          'region' => 'contact_map',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Página de contacto');
  t('contacto');
  $export['contacto'] = $context;

  return $export;
}
