<?php

if (module_exists('apachesolr_search')) {
  $plugin = array(
    'single' => TRUE,
    'title' => t('Search page title'),
    'description' => t('Information about an Apache Solr search.'),
    'icon' => 'icon_search.png',
    'category' => t('Apache Solr Search'),
    'render callback' => 'katakrak_search_search_title_content_type_render',
  );
}

function katakrak_search_search_title_content_type_render() {
  $block = new stdClass();
  $block->module = 'katakrak_search';
  $block->delta = 'title';
  $block->title = t("Buscando @search_term", array('@search_term' => arg(2)));
  return $block;
}