<?php

/**
 * @file
 * Admin include file.
 */

/**
 * Generates table of keywords associated with a pages
 *
 * @param int|str $pid - page id; the nid (int) or path (str) of the page
 */
function kwresearch_page_keywords_page($pid, $mode = NULL) {
  drupal_add_css(drupal_get_path('module', 'kwresearch') . '/kwresearch.css');
  kwresearch_set_admin_theme();
  $query = db_select('kwresearch_page_keyword', 'pk');
  $k  = $query->innerJoin('kwresearch_keyword', 'k', '%alias.kid = pk.kid');
  drupal_set_title('Page keywords');
  if ($mode == 'node') {
    $pid = $pid->nid;
  }
  if ($pid > 0) {
    $node = node_load($pid);
    $path = 'node/' . $pid;
    $query->condition('pk.nid', $pid);
  }
  else {
    $path = $pid;
    $query->condition('pk.path', $pid);
  }
  $output = t('Page: !page', 
    array(
    '!page' => l($path, $path),
  )      
  );

  $rows = array();

  //dsm($filter);

  $header = array(
    array(
      'data' => t('Keyword'),
      'field' => 'k.keyword',
    ),
    array(
      'data' => t('Page priority'),
      'field' => 'pk.priority',
      'sort' => 'desc',
    ),
    array(
      'data' => t('Site priority'),
      'field' => 'k.priority',
    ),
    array(
      'data' => t('Value'),
      'field' => 'k.value',
    ),
  );
  
  $linkintel_exists = module_exists('linkintel');
  if ($linkintel_exists) {
    $header[] = array(
      'data' => t('Link target'),
      //'field' => 'k.value',
    ); 
    $l = $query->leftJoin('linkintel_request', 'l', "l.kid = pk.kid");
    $query->addField('l', 'path', 'link_target_path');   
  }

  $intel_gwt_exists = module_exists('intel_gwt');
  if ($intel_gwt_exists) {
    // check if data should be refreshed
    if (!empty($_GET['refresh_gwt'])) {
      $options = array(
        'requests' => array()
      );
      $options['requests'][] = array(
        'page' => base_path() . drupal_get_path_alias('node/' . $pid),
      );
      intel_gwt_search_fetch_batch(array(), $options);
    }
    $header[] = array(
      'data' => t('Imprs'),
      'field' => 'g.impressions',
    );
    $header[] = array(
      'data' => t('Clicks'),
      'field' => 'g.clicks',
    );
    $header[] = array(
      'data' => t('Position'),
      'field' => 'g.position',
    );
    kwresearch_add_intel_gwt_query_settings($query);
  }

  $header[] =  array(
      'data' => t('Total Daily'),
      'field' => 'k.daily_volume',
    );
  $header[] = array('data' => t('Operations'));

  /*
  $sql = '
    SELECT pk.priority AS page_priority, pk.uid AS page_uid, k.*, u.name AS username, up.name AS page_username
    FROM {kwresearch_page_keyword} pk
    JOIN {kwresearch_keyword} k ON pk.kid = k.kid
    LEFT JOIN {users} u ON u.uid = k.uid
    LEFT JOIN {users} up ON up.uid = pk.uid
    WHERE ' . $where . '
  ';
  $tablesort = tablesort_sql($header);
  $sql = $sql . $tablesort;
  $result = pager_query($sql, 100, 0, NULL, $pid);
  */
  

  $u  = $query->leftJoin('users', 'u', '%alias.uid = k.uid');
  $up = $query->leftJoin('users', 'up', '%alias.uid = pk.uid');
  $query->fields($k);
  $query->addField('pk', 'priority', 'page_priority');
  $query->addField('pk', 'uid', 'page_uid');
  $query->addField($u, 'name', 'username');
  $query->addField($up, 'name', 'page_username');
  $query->extend('PagerDefault')
    ->limit(100);
  $query->extend('TableSort')
    ->orderByHeader($header);

  if ($intel_gwt_exists) {
    if (!empty($_GET['refresh_gwt'])) {
      $options = array(
        'pages' => array()
      );
      $options['pages'][] = array(
        'page' => base_path() . drupal_get_path_alias('node/' . $pid),
      );
      intel_gwt_search_fetch_batch(array(), $options);
    }
    kwresearch_add_intel_gwt_query_settings($query);
  }

  $result = $query->execute();

  $priorities = kwresearch_get_priority_options();
  $dest = 'admin/structure/kwresearch/page_keywords/' . $pid;
  if ($mode == 'node') {
    $dest = 'node/' . $pid . '/kwresearch';
  }
  $lo = array('query' => array('destination' => $dest)); 
  $lo2 = $lo;
  $lo2['query']['link_request_url'] = $path;
  if (isset($node->title)) {
    $lo2['query']['link_request_title'] = $node->title;
  }
  while ($r = $result->fetchObject()) {
    $ops = l(t('edit page keyword'), 'admin/structure/kwresearch/page_keywords_edit/' . $pid . '/' . $r->kid, $lo)
      . ' | ' . l(t('edit keyword'), 'admin/structure/kwresearch/keyword_list/edit/' . $r->kid, $lo);
    $row = array(
      'data' => array(
        // Cells
        check_plain($r->keyword),
        $priorities[$r->page_priority],
        //($r->page_uid > 0) ? l($r->page_username, 'user/' . $r->page_uid) : '-',
        ($r->priority > 0) ? $priorities[$r->priority] : '-',
        ($r->value >= 0) ?  t('$') . number_format($r->value, 2) : '-',
        //($r->uid > 0) ? l($r->username, 'user/' . $r->uid) : '-',
      ),
      'class' => array('kwresearch'),
    );
    if ($linkintel_exists) {
      $row['data'][] = (!isset($r->link_target_path)) ? '-' : (($r->link_target_path == $path) ? 'this' : l($r->link_target_path, $r->link_target_path));
      $ops .= ' | ' . l(t('set link request'), 'admin/structure/kwresearch/keyword_list/edit/' . $r->kid, $lo2);
    }
    if ($intel_gwt_exists) {
      $row['data'][] = isset($r->gwt_impressions) ? number_format($r->gwt_impressions) : 'NA';
      $row['data'][] = isset($r->gwt_clicks) ? number_format($r->gwt_clicks) : 'NA';
      $row['data'][] = isset($r->gwt_position) ? number_format($r->gwt_position, 1) : 'NA';
    }
    $row['data'][] = ($r->daily_volume >= 0) ? number_format($r->daily_volume) : '-';
    $row['data'][] = $ops;

    $rows[] = $row;
  }

  if (!$rows) {
    $rows[] = array(array(
        'data' => t('No keywords associated with this page.'),
        'colspan' => count($header),
      ));
  }
  $vars = array(
    'header' => $header, 
    'rows' => $rows, 
    'attributes' => array('id' => 'kwresearch-site-keywords'),
  );
  $output .= theme('table', $vars);
  $output .= theme('pager', array('tags' => NULL, 'element' => 0));

  $output .= l(t('Add page keyword'), 'admin/structure/kwresearch/page_keywords_edit/' . $pid, $lo);

  if ($intel_gwt_exists) {
    $output .= '<br /><br />' . '<h3>' . t('GWT Search Analytics') . '</h3>';
    $output .= intel_gwt_search_report(array('conditions' => array(array('s.nid', $pid))));
    $output .= l('Refresh GWT data', current_path(), array('query' => array(
        'refresh_gwt' => 1
      )));
  }

  return $output;
}
