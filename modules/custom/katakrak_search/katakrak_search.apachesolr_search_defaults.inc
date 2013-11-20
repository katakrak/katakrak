<?php
/**
 * @file
 * katakrak_search.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function katakrak_search_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'book_search';
  $searcher->label = 'Book Search';
  $searcher->description = '';
  $searcher->search_path = 'search/books';
  $searcher->page_title = '%value';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:libro',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 10,
    'apachesolr_search_spellcheck' => 0,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'none',
  );
  $export['book_search'] = $searcher;

  return $export;
}
