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
        'katakrak-katakrak_contact_bc' => array(
          'delta' => 'katakrak_contact_bc',
          'module' => 'katakrak',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak-katakrak_contact_map' => array(
          'delta' => 'katakrak_contact_map',
          'module' => 'katakrak',
          'region' => 'content_middle',
          'weight' => '-10',
        ),
        'katakrak-katakrak_donde_estamos_contact' => array(
          'delta' => 'katakrak_donde_estamos_contact',
          'module' => 'katakrak',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'delta' => 'main',
          'module' => 'system',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
      'layout' => 'contact',
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
