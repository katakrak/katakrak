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
        'cantina' => 'cantina',
        'kantina' => 'kantina',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_kantina-kantina_page_carousel' => array(
          'delta' => 'kantina_page_carousel',
          'module' => 'katakrak_kantina',
          'region' => 'content_middle',
          'weight' => '-10',
        ),
        'katakrak_kantina-kantina_page_hero' => array(
          'delta' => 'kantina_page_hero',
          'module' => 'katakrak_kantina',
          'region' => 'hero',
          'weight' => '-10',
        ),
        'katakrak_kantina-kantina_page_highlight' => array(
          'delta' => 'kantina_page_highlight',
          'module' => 'katakrak_kantina',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'katakrak_kantina-katakrak_kantina_nav_submenu' => array(
          'delta' => 'katakrak_kantina_nav_submenu',
          'module' => 'katakrak_kantina',
          'region' => 'banners',
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
      'options' => array(
        'node_form' => '1',
      ),
      'values' => array(
        'eguneko_menua' => 'eguneko_menua',
        'receta' => 'receta',
      ),
    ),
    'path' => array(
      'values' => array(
        'cantina/*' => 'cantina/*',
        'kantina/*' => 'kantina/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'kantina_blog:page' => 'kantina_blog:page',
        'kantina_productores' => 'kantina_productores',
        'kantina_productores:page' => 'kantina_productores:page',
        'kantina_recetas:page' => 'kantina_recetas:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_kantina-katakrak_kantina_nav_submenu' => array(
          'delta' => 'katakrak_kantina_nav_submenu',
          'module' => 'katakrak_kantina',
          'region' => 'banners',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => array(
      0 => 'main-menu:cantina',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kantina');
  $export['kantina-navegacion'] = $context;

  return $export;
}
