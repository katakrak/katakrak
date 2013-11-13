<?php
/**
 * @file commerce_shipping_weight_tariff.commerce.inc
 * Contains admin page callbacks.
 */

/**
 * Page callback for the matrix overview.
 */
function commerce_shipping_weight_tariff_admin_matrix() {
  // Get all products of our bundle.
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'commerce_product')
    ->entityCondition('bundle', 'shipping_tariff');
  $result = $query->execute();
  if (empty($result['commerce_product'])) {
    return t('No tariff products found.');
  }

  $products = commerce_product_load_multiple(array_keys($result['commerce_product']));

  // Get the services for our method.
  $services = commerce_shipping_services('weight_tariff_shipping');
  //dsm($services);

  // Build up an array of services => tariffs, where tariffs is an array of
  // weight => product id.
  $tariffs = array_fill_keys(array_keys($services), array());
  // Build up an array of of all the different weights we see.
  $weights = array();
  foreach ($products as $product) {
    $wrapper = entity_metadata_wrapper('commerce_product', $product);
    $weight = $wrapper->commerce_product_tariff_weight->weight->value();
    $unit = $wrapper->commerce_product_tariff_weight->unit->value();

    // Convert to SI.
    if ($unit == 'g') {
      $weight /= 1000;
    }

    $service = $wrapper->commerce_product_tariff_service->value();

    $tariffs[$service][$weight] = $product->product_id;
    // Build the array of weights we've seen.
    $weights[$weight] = $weight;
  }
  //dsm($tariffs);
  //dsm($weights, 'weights');

  // Sort the weights. These will form the columns of the table.
  asort($weights);

  // Build a table with rows of services and columns of weights.
  $rows = array();
  foreach ($tariffs as $service_name => $service_tariffs) {
    $row = array();

    // First column is the shipping method label.
    $row[] = $services[$service_name]['title'];

    // Column for each weight, which may be empty if the current method has
    // no price point for this weight.
    foreach ($weights as $weight) {
      if (isset($service_tariffs[$weight])) {
        $product_id = $service_tariffs[$weight];
        $product = $products[$product_id];
        $wrapper = entity_metadata_wrapper('commerce_product', $product);
        $price = $wrapper->commerce_price->value();
        $price_format = commerce_currency_format($price['amount'], $price['currency_code']);
        $row[] = l($price_format, 'admin/commerce/products/' . $product_id, array('query' => drupal_get_destination()));
      }
      else {
        $row[] = '';
      }
    }

    $rows[] = $row;
  }

  // The weights form the header, with a first column to account for the service
  // names.
  $header = array();
  $header[] = t('Shipping service');
  foreach ($weights as $weight) {
    $header[] = '< ' . number_format($weight, 3) . 'kg';
  }

  $table = theme('table', array(
    'rows' => $rows,
    'header' => $header,
  ));

  return $table;
}
