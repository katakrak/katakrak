<?php


/**
 * Implements hook_commerce_product_type_info().
 */
function libro_commerce_product_type_info() {
  $types = array(
    'libro' => array(
      'type' => 'libro',
      'name' => t('Libro'),
      'description' => t('A physical book in the bookshop.'),
      'revision' => TRUE,
    ),
  );
  return $types;
}
