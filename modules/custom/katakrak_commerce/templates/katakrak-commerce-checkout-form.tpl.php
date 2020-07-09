<div class="container">
  <div class="row mt-3">
    <div class="col-md-8">
      <nav class="nav-select"><?php print render($form['commerce_shipping']) ?></nav>
      <?php print render($form['informacion_envio']) ?>
      <?php print render($form['customer_profile_billing']) ?>
      <?php print render($form['customer_profile_shipping']) ?>
      <?php print render($form['recogida']) ?>
    </div>
    <div class="col-md-4"><?php print render($form['cart_contents']) ?></div>
  </div>
</div>
<?php print drupal_render_children($form) ?> 