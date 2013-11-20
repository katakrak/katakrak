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
        'last_changed' => '1384884001',
        'last_entity_id' => '23046',
      ),
      'taxonomy_term' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'comment' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'commerce_customer_profile' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'commerce_line_item' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'commerce_order' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'commerce_payment_transaction' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'commerce_product' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'i18n_translation' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'file' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'taxonomy_vocabulary' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'user' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'rules_config' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
    ),
    'apachesolr_index_updated' => 1384958881,
    'apachesolr_last_optimize' => 1384881121,
    'apachesolr_read_only' => '0',
    'apachesolr_search_facet_pages' => '',
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'libro',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
