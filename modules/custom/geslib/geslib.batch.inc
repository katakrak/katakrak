<?php


function geslib_process_read_file($geslib_file_path, &$context) {
  $geslib_file = file_get_contents($geslib_file_path);
  $geslib_file_array = explode("\n", $geslib_file);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_line'] = 0;
    $context['sandbox']['max'] = count($geslib_file_array);
  }
  
  
  
  $limit = 1000;
 
  $geslib_lines = array();
  for($i = 0; $i < $limit; $i++) {
    $line = explode("|", $geslib_file_array[$i]);
    geslib_process_line($line, $geslib_lines);
    unset($geslib_file_array[$i]);
  }
  
  foreach ($geslib_lines as $line) {
    $record = array();
    $record['geslib_id'] = $line['geslib_id'];
    $record['type'] = $line['type'];
    $record['content'] = serialize($line);
    try {
      drupal_write_record('geslib_lines', $record);
    }
    catch (Exception $e){
      watchdog('geslib', $e->getMessage());
    }
    
  }
  
  $context['sandbox']['progress'] += $limit;
  file_put_contents($geslib_file_path, implode("\n", $geslib_file_array));
  
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}


function geslib_process_create_items(&$context){
}

function geslib_process_get_data_from_dilve(){
  
}

function geslib_process_finish() {
  
}