<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
$product = commerce_product_load($row->commerce_product_field_data_field_libro_producto_product_id);
$default_quantity = 1;
$product_ids = array($product->product_id);

// Build the line item we'll pass to the Add to Cart form.
$line_item = commerce_product_line_item_new($product, $default_quantity, 0, array(), 0);
$line_item->data['context']['product_ids'] = $product_ids;
$line_item->data['context']['add_to_cart_combine'] = 1;

// Generate a form ID for this add to cart form.
$form_id = commerce_cart_add_to_cart_form_id($product_ids);
$line_item->data['context']['display_path'] = current_path();



// Build the Add to Cart form using the prepared values.
$form = drupal_get_form($form_id, $line_item, 0, array());
$add_to_cart = drupal_render($form);
?>
<?php print $output; ?>
<div class="prod-info">
  <h4>
    <?php print l($row->node_title, 'node/'.$row->nid); ?>
    <!--<a class="product_link" href="http://livedemo00.template-help.com/prestashop_40228/product.php?id_product=1" title="Lorem ipsum dolor sit amet...">Lorem ipsum dolor sit amet conse ctetur </a>-->
  </h4>
 <span class="price"><?php print $row->field_commerce_price[0]['rendered']['#markup'] ?></span>
 <?php print $add_to_cart ?>
 <!--<a class="exclusive ajax_add_to_cart_button" rel="ajax_id_product_1" href="http://livedemo00.template-help.com/prestashop_40228/cart.php?qty=1&amp;id_product=1&amp;token=9fbbee26e8d009d66d597040a025a688&amp;add" title="Add to cart">Add to cart</a>-->
</div>