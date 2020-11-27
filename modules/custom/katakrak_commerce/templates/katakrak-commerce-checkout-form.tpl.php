<div class="container">
  <div class="row mt-3">
    <?php if ($form['checkout_review']): ?>
    <p class="text-center"><?php print t('Antes de continuar, revisa que tus datos sean correctos.') ?></p>
    <?php endif; ?>
    <div class="col-md-8">
      <?php print render($form['checkout_review']) ?>
      <nav class="nav-select"><?php print render($form['commerce_shipping']) ?></nav>
      <?php print render($form['informacion_envio']) ?>
      <?php print render($form['customer_profile_billing']) ?>
      <?php print render($form['customer_profile_shipping']) ?>
      <?php print render($form['recogida']) ?>
    </div>
    <div class="col-md-4"><?php print render($form['cart_contents']) ?></div>
    
  </div>
  <hr class="hr-dark">
  <div class="text-right-sm mb-3">
    <?php print render ($form['buttons']) ?>
  </div>
</div>
<div class=""><?php print drupal_render_children($form) ?> </div>