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
    'apachesolr_direct_commit' => 0,
    'apachesolr_index_last' => array(
      'node' => array(
        'last_changed' => '1392989268',
        'last_entity_id' => '35633',
      ),
    ),
    'apachesolr_index_updated' => 0,
    'apachesolr_last_optimize' => 1393495201,
    'apachesolr_read_only' => '1',
    'apachesolr_soft_commit' => 0,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'blog',
      1 => 'boletin',
      2 => 'event',
      3 => 'libro',
      4 => 'portfolio',
      5 => 'simplenews',
      6 => 'webform',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
