<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<div class="modal fade" id="<?php print $fields['order_number']->raw ?>" tabindex="-1" role="dialog" aria-labelledby="detallePedido">
  <div class="modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <i class="far fa-times-circle"></i>
        </button>
        <h4 class="modal-title"><?php print t('Pedido !order', array('!order' => $fields['order_number']->raw)) ?></h4>
      </div>
      <div class="modal-body">
        <?php print $fields['commerce_line_items']->content ?>
          <?php if ($fields['status']->raw == 'completed' && $fields['commerce_shipping_service']->content == 'mensajeria'): ?>
          <a href="https://www.seur.com/livetracking/?segOnlineIdentificador=<?php print $fields['order_number']->raw ?>" target="_blank"><?php print t('Seguimiento de tu paquete')?></a>
          <?php endif; ?>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-dismiss="modal"><?php print t('Cerrar') ?></button>
      </div>
    </div>
  </div>
</div>