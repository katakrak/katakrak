<?php

/**
 * @file
 * Views integration for ShareThis.
 */

/**
 * Implements hook_views_data().
 */
function sharethis_views_data() {
  $data = [];

  // ShareThis link.
  $data['node']['sharethis'] = [
    'title' => t('ShareThis Link'),
    'help' => t('Link provided by the ShareThis service.'),
    'field' => [
      'handler' => 'sharethis_handler_field_link',
      'click sortable' => FALSE,
    ],
  ];

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function sharethis_views_data_alter(&$data) {
  if (module_exists('search_api_views')) {
    foreach (search_api_index_load_multiple(FALSE) as $index) {
      $key = 'search_api_index_' . $index->machine_name;
      if (isset($data[$key])) {
        $data[$key]['sharethis'] = [
          'title' => t('ShareThis Link'),
          'help' => t('Link provided by the ShareThis service.'),
          'field' => [
            'handler' => 'sharethis_handler_field_link',
            'click sortable' => FALSE,
          ],
        ];
      }
    }
  }
}
