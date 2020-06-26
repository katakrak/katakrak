<div class="container">
  <h1 class="text-center">Selecciona forma de envío o recogida</h1>
  <div class="row mt-3">
    <div class="col-md-8">
      <?php print render($form['commerce_shipping']) ?>
      <?php print render($form['informacion_envio']) ?>
    </div>
    <div class="col-md-4"><?php print render($form['cart_contents']) ?></div>
  </div>
</div>
<?php print drupal_render_children($form) ?> 