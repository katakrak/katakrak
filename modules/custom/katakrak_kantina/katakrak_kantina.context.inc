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
        'views-kantina_blog-block_1' => array(
          'module' => 'views',
          'delta' => 'kantina_blog-block_1',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
        'views-kantina_recetas-block_1' => array(
          'module' => 'views',
          'delta' => 'kantina_recetas-block_1',
          'region' => 'content_bottom_second',
          'weight' => '-10',
        ),
        'katakrak_kantina-katakrak_reserva_block' => array(
          'module' => 'katakrak_kantina',
          'delta' => 'katakrak_reserva_block',
          'region' => 'content_bottom_third',
          'weight' => '-10',
        ),
        'boxes-twitter_kantina' => array(
          'module' => 'boxes',
          'delta' => 'twitter_kantina',
          'region' => 'content_bottom_third',
          'weight' => '-9',
        ),
        'katakrak_kantina-katakrak_kantina_page_header' => array(
          'module' => 'katakrak_kantina',
          'delta' => 'katakrak_kantina_page_header',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'kantina',
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
    'block' => array(
      'blocks' => array(
        'katakrak_kantina-katakrak_kantina_page_header' => array(
          'module' => 'katakrak_kantina',
          'delta' => 'katakrak_kantina_page_header',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
      'layout' => 'kantina',
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
