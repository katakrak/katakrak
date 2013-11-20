<?php
/**
 * @file
 * katakrak_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_page';
  $context->description = 'Search page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/books*' => 'search/books*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-gsuabqVf0AVVqe53zFv7k6te9HVy12PJ' => array(
          'module' => 'facetapi',
          'delta' => 'gsuabqVf0AVVqe53zFv7k6te9HVy12PJ',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-R2UTz6TzAt7lw1croPaTispTk1IwtN2e' => array(
          'module' => 'facetapi',
          'delta' => 'R2UTz6TzAt7lw1croPaTispTk1IwtN2e',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-FM9Alkv8hyOtkShgOh3ba7QsdDWF4EHK' => array(
          'module' => 'facetapi',
          'delta' => 'FM9Alkv8hyOtkShgOh3ba7QsdDWF4EHK',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-mc01YGkWD97iRq1vO20ttHT3XfyBiTtb' => array(
          'module' => 'facetapi',
          'delta' => 'mc01YGkWD97iRq1vO20ttHT3XfyBiTtb',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
      'layout' => 'search',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search page');
  $export['search_page'] = $context;

  return $export;
}
