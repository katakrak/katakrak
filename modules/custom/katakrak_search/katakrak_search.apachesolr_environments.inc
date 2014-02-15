<?php
/**
 * @file
 * katakrak_search.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function katakrak_search_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'hosted_apachesolr';
  $environment->url = 'http://nyc1.hostedapachesolr.com:80/solr/88rDzKkRVe_katakrak_taz';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_index_last' => array(
      'node' => array(
        'last_changed' => '1392354540',
        'last_entity_id' => '17982',
      ),
    ),
    'apachesolr_index_updated' => 1392464162,
    'apachesolr_last_optimize' => 1392455520,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'blog',
      1 => 'event',
      2 => 'libro',
      3 => 'portfolio',
      4 => 'simplenews',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
