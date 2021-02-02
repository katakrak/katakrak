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
?>
<a class="primary" href="#" data-toggle="modal" data-target="#<?php print $row->commerce_order_order_number ?>"><?php print $row->commerce_order_order_number ?></a>
<?php print $row->field_commerce_line_items[0]['rendered']['#markup'] ?>
<p class="small mt-1"><?php print t('Forma de envio: <strong>!method</strong>', array('!method' => $row->_field_data['commerce_order_shipping_line_item_representiative_line_item_']['entity']->line_item_label ))?></p>