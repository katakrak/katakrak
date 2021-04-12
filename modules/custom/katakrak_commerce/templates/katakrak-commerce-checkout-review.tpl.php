<div class="row">
  <div class="col-sm-6">
    <div class="well well-custom well-border">
      <h3 class="mt-0"><?php print t('Datos de facturación') ?></h3>
      <p><?php print t('Nombre y apellidos') ?>:<br>
        <strong><?php print $billing->commerce_customer_address['und'][0]['name_line'] ?></strong></p>
      <p><?php print t('Dirección') ?><br>
      <strong><?php print $billing->commerce_customer_address['und'][0]['thoroughfare'] ?> </strong><br>
      <?php print $billing->commerce_customer_address['und'][0]['postal_code'] ?> <?php print $billing->commerce_customer_address['und'][0]['locality'] ?>, <?php print $billing->commerce_customer_address['und'][0]['administrative_area'] ?></p>
      <p><?php print t('Teléfono') ?>:<br>
      <strong><?php print $billing->field_customer_telefono['und'][0]['value'] ?></strong></p>
    </div><!-- /.well-->
  </div><!-- /.col-6 -->
  <div class="col-sm-6">
    <div class="well well-custom well-border">
      <h3 class="mt-0"><?php print t('Datos de envío') ?></h3>
      <p><?php print t('Nombre y apellidos:') ?><br>
      <strong><?php print $shipping->commerce_customer_address['und'][0]['name_line'] ?></strong></p>
      <?php if ($shipping_method == 'recogida'): ?>
      <strong><?php print t('Recogida en tienda') ?></strong>
      <?php else: ?>
      <p><?php print t('Dirección') ?><br>
      <strong><?php print $shipping->commerce_customer_address['und'][0]['thoroughfare'] ?> </strong><br>
      <?php print $shipping->commerce_customer_address['und'][0]['postal_code'] ?> <?php print $shipping->commerce_customer_address['und'][0]['locality'] ?>, <?php print $shipping->commerce_customer_address['und'][0]['administrative_area'] ?> </p>
      <p><?php print t('Teléfono:') ?><br>
      <strong><?php print $billing->field_customer_telefono['und'][0]['value'] ?></strong></p>
      <?php endif; ?>
    </div><!-- /.well-->
  </div><!-- /.col-6 -->
</div><!-- /.row -->