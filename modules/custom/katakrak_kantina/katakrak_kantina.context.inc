<?php

/**
 * @file
 * katakrak_kantina.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_kantina_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kantina';
  $context->description = 'Kantina';
  $context->tag = 'Kantina';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'kantina' => 'kantina',
        'cantina' => 'cantina',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_kantina-kantina_page_hero' => array(
          'module' => 'katakrak_kantina',
          'delta' => 'kantina_page_hero',
          'region' => 'hero',
          'weight' => '-10',
        ),
        'katakrak_kantina-kantina_page_highlight' => array(
          'module' => 'katakrak_kantina',
          'delta' => 'kantina_page_highlight',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_kantina-kantina_page_carousel' => array(
          'module' => 'katakrak_kantina',
          'delta' => 'kantina_page_carousel',
          'region' => 'content_middle',
          'weight' => '-10',
        ),
      ),
      'layout' => 'landing',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kantina');
  $export['kantina'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kantina-navegacion';
  $context->description = '';
  $context->tag = 'Kantina';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'eguneko_menua' => 'eguneko_menua',
        'receta' => 'receta',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'cantina/denoche' => 'cantina/denoche',
      ),
    ),
    'views' => array(
      'values' => array(
        'kantina_blog:page' => 'kantina_blog:page',
        'kantina_recetas:page' => 'kantina_recetas:page',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:node/2134',
      1 => 'main-menu:node/2133',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kantina');
  $export['kantina-navegacion'] = $context;

  return $export;
}
