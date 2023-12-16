<?php

/**
 * @file
 * Default theme implementation for entities.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
$estados = array(
  'pending' => t('Inicial'),
  'processing' => t('Procesando'),
  'completed'  => t('Completado')
);

if (katakrak_commerce_cart_is_bizikrak($commerce_order))
  $forma_envio = t('Bizikrak');
elseif (katakrak_commerce_cart_is_mensajeria($commerce_order))
  $forma_envio = t('Mensajería');
elseif (katakrak_commerce_cart_is_recogida($commerce_order))
  $forma_envio = t('Recogida en tienda');
else 
  $forma_envio = t('Correos');


$billing = commerce_customer_profile_load($commerce_order->commerce_customer_billing['und'][0]['profile_id']);

$phone = $billing->field_customer_telefono['und'][0]['value'];
$billing = $billing->commerce_customer_address['und'][0];

$shipping = commerce_customer_profile_load($commerce_order->commerce_customer_shipping['und'][0]['profile_id']);
$shipping = $shipping->commerce_customer_address['und'][0];
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>>
      <?php if ($url): ?>
        <a href="<?php print $url; ?>"><?php print $title; ?></a>
      <?php else: ?>
        <?php print $title; ?>
      <?php endif; ?>
    </h2>
  <?php endif; ?>

  <div class=""<?php print $content_attributes; ?>>
    <h1 class="text-center"><?php print t('Pedido @num', array('@num' => $commerce_order->order_id)) ?></h1>
    <p class="text-center"><?php print t('Resumen del pedido') ?></p>
    <?php print theme('katakrak_commerce_order_page_breadcrumb', array('commerce_order' => $commerce_order)) ?>
    
    <div class="row mt-3">
      <div class="col-md-8">
        <div class="well well-custom well-border">
              <h2 class="mt-0"><?php print t('Datos del pedido') ?></h2>
              <div class="table-responsive mt-2 mb-0">
                <table class="table table-resumen">
                  <tbody>
                    <tr>
                      <th><?php print t('Referencia') ?></th>
                      <td><?php print $commerce_order->order_number?></td>
                    </tr>
                    <tr>
                      <th><?php print t('Importe total') ?></th>
                      <td><?php print commerce_currency_format($commerce_order->commerce_order_total['und'][0]['amount'], 'EUR') ?></td>
                    </tr>
                    <tr>
                      <th><?php print t('Fecha de compra') ?></th>
                      <td><?php print format_date($commerce_order->data['last_cart_refresh']) ?></td>
                    </tr>
                    <tr>
                      <th><?php print t('Email') ?></th>
                      <td><?php print $commerce_order->mail ?></td>
                    </tr>
                    <tr>
                      <th><?php print t('Teléfono') ?></th>
                      <td><?php print $phone ?></td>
                    </tr>
                    <tr>
                      <th><?php print ('Estado') ?></th>
                      <td><?php print $estados[$commerce_order->status] ?></td>
                    </tr>
                  </tbody>
                </table>
              </div>
            </div><!-- /.well -->
            <div class="well well-custom well-border pb-0">
              <h3 class="mt-0"><?php print t('Forma de envío') ?></h3>
              <div class="table-responsive mt-2 mb-0">
                <table class="table table-resumen">
                  <tbody>
                    <tr>
                      <th><?php print $forma_envio ?></th>
                      <?php if (katakrak_commerce_cart_is_mensajeria($commerce_order)): ?>
                      <td class="text-right">
                        <a class="btn btn-primary" href="https://s.correosexpress.com/SeguimientoSinCP/search?request_locale=es_ES&shippingNumber=<?php print $commerce_order->order_number?>" target="_blank"><?php print t('Seguimiento del pedido') ?></a>
                      </td>
                      <?php endif; ?>
                    </tr>
                    
                  </tbody>
                </table>
              </div>
              
            </div><!-- /.well -->
            <div class="well well-custom well-border">
              <h3 class="mt-0"><?php print t('Dirección de envío') ?></h3>
              <div class="table-responsive mt-2 mb-0">
                <table class="table table-resumen">
                  <tbody>
                    <tr>
                      <th><?php print t('Nombre y apellidos') ?></th>
                      <td><?php print $shipping['name_line'] ?></td>
                    </tr>
                    <tr>
                      <th><?php print t('Dirección') ?></th>
                      <td><?php print t('@dir. @cp @cit @prov', array('@dir' => $shipping['thoroughfare'], '@cp' => $shipping['postal_code'], '@cit' => $shipping['locality'], '@prov' => $shipping['administrative_area'],)) ?></td>
                    </tr>
                  </tbody>
                </table>
              </div>
            </div><!-- /.well -->
            <div class="well well-custom well-border">
              <h3 class="mt-0"><?php print t('Dirección de facturación') ?></h3>
              <div class="table-responsive mt-2 mb-0">
                <table class="table table-resumen">
                  <tbody>
                    <tr>
                      <th><?php print t('Nombre y apellidos') ?></th>
                      <td><?php print $billing['name_line'] ?></td>
                    </tr>
                    <tr>
                      <th><?php print t('Dirección') ?></th>
                      <td><?php print t('@dir. @cp @cit @prov', array('@dir' => $billing['thoroughfare'], '@cp' => $billing['postal_code'], '@cit' => $billing['locality'], '@prov' => $billing['administrative_area'],)) ?></td>
                    </tr>
                  </tbody>
                </table>
              </div>
            </div><!-- /.well -->
            
      </div>
      <div class="col-md-4">
        <div class="well well-custom">
        <?php print views_embed_view('katakrak_commerce_cart_summary', 'default', $commerce_order->order_number) ?>
        </div>
      </div>
    </div>
    <?php
      //print render($content);
    ?>
  </div>
</div>
