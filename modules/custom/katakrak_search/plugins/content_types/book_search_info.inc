<?php

if (module_exists('apachesolr_search')) {
  $plugin = array(
    'single' => TRUE,
    'title' => t('Book search information'),
    'description' => t('Information about an Apache Solr search.'),
    'icon' => 'icon_search.png',
    'category' => t('Apache Solr Search'),
    'defaults' => array(
      'title_override' => FALSE,
      'title_override_text' => '',
    ),
  );
}


/**
 * Execute the search and render results.
 */
function katakrak_search_book_search_info_content_type_render($subtype, $conf, $panel_args, $context) {
  $query = apachesolr_current_query(variable_get('apachesolr_default_environment', 'default'));
  if ($query) {
    $searcher = $query->getSearcher();
    $response = apachesolr_static_response_cache($searcher);
  }

  $search = apachesolr_panels_static_search_cache();
  

  if (empty($response) || empty($search)) {
    return;
  }
  $block = new stdClass();
  $block->module  = 'katakrak_search';
  $block->delta   = 'info';
  $block->title   = '';
  $block->content = '<h2>'.t('@count libros en @term', array('@count' => $response->response->numFound, '@term' => $search['keys'])).'</h2>';

  return $block;
}

/**
 * Empty form so we can have the default override title.
 */
function katakrak_search_book_search_info__content_type_edit_form($form, &$form_state) {
  return $form;
}

