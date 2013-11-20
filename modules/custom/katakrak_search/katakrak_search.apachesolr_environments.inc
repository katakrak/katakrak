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
        'last_changed' => '1384881275',
        'last_entity_id' => '2236',
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
    'apachesolr_index_updated' => 1384969501,
    'apachesolr_last_optimize' => 1384959421,
    'apachesolr_search_changed_boost' => '0:0',
    'apachesolr_search_comment_boost' => '0:0',
    'apachesolr_search_date_boost' => '8:500.0',
    'apachesolr_search_promote_boost' => '0',
    'apachesolr_search_sticky_boost' => '0',
    'apachesolr_search_type_boosts' => array(
      'calendar_event' => '0',
      'dvd' => '0',
      'itinerario' => '0',
      'libro' => '21.0',
    ),
    'field_bias' => array(
      'bs_promote' => '0',
      'bs_status' => '0',
      'bs_sticky' => '0',
      'bs_translate' => '0',
      'bundle' => '0',
      'bundle_name' => '0',
      'content' => '13.0',
      'ds_changed' => '0',
      'ds_created' => '0',
      'ds_last_comment_or_change' => '0',
      'entity_id' => '0',
      'entity_type' => '0',
      'hash' => '0',
      'id' => '0',
      'im_field_libro_autores' => '0',
      'im_field_libro_categoria' => '0',
      'im_field_libro_dilve' => '0',
      'im_field_libro_editorial' => '0',
      'im_vid_1' => '0',
      'im_vid_2' => '0',
      'im_vid_3' => '0',
      'is_field_libro_dilve' => '0',
      'is_tnid' => '0',
      'is_uid' => '0',
      'itm_field_libro_ano' => '0',
      'its_field_libro_ano' => '0',
      'label' => '21.0',
      'path' => '0',
      'path_alias' => '21.0',
      'site' => '0',
      'sm_field_libro_estado' => '0',
      'sm_field_libro_idioma' => '0',
      'sm_vid_Autores' => '0',
      'sm_vid_Editoriales' => '0',
      'sm_vid_Materias' => '0',
      'sort_label' => '0',
      'sort_language' => '0',
      'sort_name' => '0',
      'sort_name_formatted' => '0',
      'spell' => '0',
      'ss_language' => '0',
      'ss_name' => '0',
      'ss_name_formatted' => '0',
      'tags_a' => '0',
      'tags_h1' => '5.0',
      'tags_h2_h3' => '3.0',
      'tags_h4_h5_h6' => '2.0',
      'tags_inline' => '1.0',
      'taxonomy_names' => '2.0',
      'tid' => '0',
      'timestamp' => '0',
      'tm_vid_1_names' => '21.0',
      'tm_vid_2_names' => '13.0',
      'tm_vid_3_names' => '21.0',
      'tos_content_extra' => '0.1',
      'tos_name' => '0',
      'tos_name_formatted' => '0',
      'ts_comments' => '0.5',
      'url' => '0',
    ),
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'libro',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
