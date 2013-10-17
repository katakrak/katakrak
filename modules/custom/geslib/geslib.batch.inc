<?php

/**
 * Carga el fichero geslib en una tabala de la base de datos
 * para poder procesarlo más tarde
 * 
 * @param type $geslib_file_path
 * @param type $context
 */
function geslib_process_read_file($geslib_file_path, &$context) {
  $geslib_file = file_get_contents($geslib_file_path);
  $geslib_file_array = explode("\n", $geslib_file);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($geslib_file_array);
    $context['results']['lines'] = 0;
    $context['results']['inter_file'] = substr($geslib_file_path, strrpos($geslib_file_path, '/') +1);
  }
  
  $limit = count($geslib_file_array) < 10000 ? count($geslib_file_array): 10000;
  
  $i = 0;
  $geslib_lines = array();
  while($i < $limit) {
    $line = explode("|", $geslib_file_array[$i]);
    geslib_process_line($line, $geslib_lines);
    unset($geslib_file_array[$i]);
    $i++;
  }
  
  foreach ($geslib_lines as $line) {
    if ($line['action'] != 'delete') {
      $record = array();
      $record['geslib_id'] = $line['geslib_id'];
      $record['type'] = $line['type'];
      $record['content'] = serialize($line);

      try {
        drupal_write_record('geslib_lines', $record);
        $context['results']['items']['lines']++;
      }
      catch (Exception $e){
        watchdog('geslib', "Geslib id: @id Type: @type Message: @message", array('@id' => $record['geslib_id'], '@type' => $record['type'], '@message' => $e->getMessage()));
      }
    }
  }
  
  $context['sandbox']['progress'] += $i;
  
  $context['message'] = t("Processed @progress of @max lines", array('@progress' => $context['sandbox']['progress'], '@max' => $context['sandbox']['max']));
  
  file_put_contents($geslib_file_path, implode("\n", $geslib_file_array));
  
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function geslib_process_create_publishers(&$context) {
  if (!isset($context['sandbox']['progress'])) {
    $publishers_db = db_select('geslib_lines', 'g')->condition('type', 'editorial')
      ->fields('g')->execute();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_line'] = 0;
    $context['sandbox']['max'] = $publishers_db->rowCount();
    $context['results']['items']['publishers'] = 0;
  }
  $limit = 200;
  $lines = db_select('geslib_lines', 'g')->condition('type', 'editorial')
      ->fields('g')->range(0, $limit)->execute()->fetchAll();
  
  
  foreach ($lines as $line) {
    $publisher = unserialize($line->content);
    module_invoke_all('geslib_publisher', 'create', $publisher);
    $context['results']['items']['publishers']++;
    $context['sandbox']['progress']++;
    db_delete('geslib_lines')->condition('geslib_id', $line->geslib_id)->condition('type', $line->type)
     ->execute();
  }
  
  $context['message'] = t("Processed @progress of @max publishers", array('@progress' => $context['sandbox']['progress'], '@max' => $context['sandbox']['max']));
  
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function geslib_process_create_categories(&$context) {
  if (!isset($context['sandbox']['progress'])) {
    $categories_db = db_select('geslib_lines', 'g')->condition('type', 'materia')
      ->fields('g')->execute();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $categories_db->rowCount();
    $context['results']['items']['categories'] = 0;
  }
  
  $limit = 100;
  $lines = db_select('geslib_lines', 'g')->condition('type', 'materia')
      ->fields('g')->range(0, $limit)->execute()->fetchAll();
  
  foreach ($lines as $line) {
    $category = unserialize($line->content);
    module_invoke_all('geslib_category', 'create', $category);
    $context['results']['items']['categories']++;
    $context['sandbox']['progress']++;
    db_delete('geslib_lines')->condition('geslib_id', $line->geslib_id)->condition('type', $line->type)
     ->execute();
  }
  
  $context['message'] = t("Processed @progress of @max categories", array('@progress' => $context['sandbox']['progress'], '@max' => $context['sandbox']['max']));
  
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function geslib_process_create_autores(&$context) {
  if (!isset($context['sandbox']['progress'])) {
    $autores_db = db_select('geslib_lines', 'g')->condition('type', 'autor')
      ->fields('g')->execute();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $autores_db->rowCount();
    $context['results']['items']['autores'] = 0;
  }
  
  $limit = 500;
  $lines = db_select('geslib_lines', 'g')->condition('type', 'autor')
      ->fields('g')->range(0, $limit)->execute()->fetchAll();
  
  foreach ($lines as $line) {
    $autor = unserialize($line->content);
    module_invoke_all('geslib_autor', 'create', $autor);
    $context['results']['items']['autores']++;
    $context['sandbox']['progress']++;
    db_delete('geslib_lines')->condition('geslib_id', $line->geslib_id)->condition('type', $line->type)
     ->execute();
  }
  
  $context['message'] = t("Processed @progress of @max autores", array('@progress' => $context['sandbox']['progress'], '@max' => $context['sandbox']['max']));
  
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function geslib_process_create_products(&$context) {
  if (!isset($context['sandbox']['progress'])) {
    $products_db = db_select('geslib_lines', 'g')->condition('type', 'product')
      ->fields('g')->execute();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] =  $products_db->rowCount();
    $context['results']['items']['products'] = 0;
  }
  
  $limit = 1000;
  
  $lines = db_select('geslib_lines', 'g')->condition('type', 'product')->fields('g')
    ->range(0, $limit)->execute()->fetchAll();
  
  foreach ($lines as $line) {
    $product = unserialize($line->content);
    
//    $sinopsis = db_select('geslib_lines', 'g')->condition('type', 'sinopsis')->condition('geslib_id', $line->geslib_id)
//      ->fields('g', array('content'))->execute()->fetchObject();
//    $sinopsis = unserialize($sinopsis->content);
//    $product['sinopsis'] = $sinopsis['sinopsis'];
//    
//    $autores = db_select('geslib_lines', 'g')->condition('type', 'product_author')->condition('geslib_id', $line->geslib_id)
//      ->fields('g', array('content'))->execute()->fetchAll();
//    foreach ($autores as $autor) {
//      $product['authors'][] = unserialize($autor->content);
//    }
    
    
    //module_invoke_all('geslib_product', 'create', $product);
    db_delete('geslib_lines')->condition('geslib_id', $line->geslib_id)->condition('type', $line->type)
     ->execute();
    db_delete('geslib_lines')->condition('geslib_id', $line->geslib_id)->condition('type', 'stock')
     ->execute();
    db_delete('geslib_lines')->condition('geslib_id', $line->geslib_id)->condition('type', 'producto_materia')
     ->execute();
    db_delete('geslib_lines')->condition('geslib_id', $line->geslib_id)->condition('type', 'sinopsis')
     ->execute();
    db_delete('geslib_lines')->condition('geslib_id', $line->geslib_id)->condition('type', 'product_author')
     ->execute();
    $context['results']['items']['products']++;
    $context['sandbox']['progress']++;
  }
  
  $context['message'] = t("Processed @progress of @max products", array('@progress' => $context['sandbox']['progress'], '@max' => $context['sandbox']['max']));
  
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function geslib_process_dilve(&$context){
  include_once 'lib/DilveSearch.php';
  if (!isset($context['sandbox']['progress'])) {
    $nodes = db_select('node', 'n')->condition('type', 'libro')
      ->fields('n', array('nid'))->execute();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $nodes->rowCount();
    
  }
  
  $dilve  = new DilveSearch(variable_get('lha_dilve_user', ''), variable_get('lha_dilve_pass', ''));
  $limit = 100;
  $nids = db_select('node', 'n')->condition('type', 'libro')->fields('n')
    ->range($context['sandbox']['progress'], $limit)->execute()->fetchAll();
  foreach ($nids as $nid) {
    $libro = node_load($nid->nid);
    $book = $dilve->search($libro->field_libro_ean['und'][0]['value']);
    
    if (is_array($book)) {
      module_invoke_all('dilve_process', $libro, $book);
      $context['results']['dilve_good']++;
    }
    else {
      $context['results']['dilve_bad']++;
    }
    $context['sandbox']['progress'] += 1;
  }
  $context['message'] = t("Processed @progress of @max books", array('@progress' => $context['sandbox']['progress'], '@max' => $context['sandbox']['max']));
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}


function geslib_process_finish($success, $results, $operations) {
  if ($success) {
    global $user;
    $total_items = 0;
    foreach ($results['items'] as $type => $count) {
      drupal_set_message(t("Created @count @type", array('@count' => $count, '@type' => $type)));
      $total_items += $count;
    }
    $log = array(
      'start_date' => $results['start_date'],
      'end_date' => time(),
      'imported_file' => $results['inter_file'],
      'count' => $total_items,
      'status' => $success,
      'uid' => $user->uid
    );
    drupal_write_record('geslib_log', $log);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}

function geslib_process_delete_categories(&$context) {
  if (!isset($context['sandbox']['progress'])) {
    $terms = db_select('taxonomy_term_data', 't')->fields('t')->execute();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $terms->rowCount();
  }
  
  $limit = 900;
  
  $terms = db_select('taxonomy_term_data', 't')->fields('t')->range(0, $limit)->execute()->fetchAll();
  
  foreach ($terms as $term) {
    taxonomy_term_delete($term->tid);
    $context['sandbox']['progress']++;
  }
  
  $context['message'] = t("Deleted @progress of @max categories", array('@progress' => $context['sandbox']['progress'], '@max' => $context['sandbox']['max']));
  
  
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  
}

function geslib_process_delete_products(&$context) {
  if (!isset($context['sandbox']['progress'])) {
    $products = db_select('commerce_product', 'p')->fields('p')->execute();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $products->rowCount();
  }
  
  $limit = 100;
  
  $products = db_select('commerce_product', 'p')->fields('p')->range(0, $limit)->execute()->fetchAll();
  
  foreach ($products as $product){
    commerce_product_delete($product->product_id);
    $context['sandbox']['progress']++;
  }
  
  $context['message'] = t("Deleted @progress of @max products", array('@progress' => $context['sandbox']['progress'], '@max' => $context['sandbox']['max']));
    
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  
}


function geslib_process_delete_nodes(&$context){
  if (!isset($context['sandbox']['progress'])) {
    $nodes_db = db_select('node', 'n')->fields('n')->condition('type', 'libro')->execute();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $nodes_db->rowCount();
  }
  
  $limit = 500;

  $nodes = db_select('node', 'n')->fields('n')->condition('type', 'libro')->range(0, $limit)->execute()->fetchAll();
  
  foreach($nodes as $node) {
    node_delete($node->nid);
    $context['sandbox']['progress'] ++;
  }
  
  $context['message'] = t("Deleted @progress of @max nodes", array('@progress' => $context['sandbox']['progress'], '@max' => $context['sandbox']['max']));
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

