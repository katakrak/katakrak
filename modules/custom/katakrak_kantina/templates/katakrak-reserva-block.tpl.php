<div class="row">
  <div class="col-lg-5 col-lg-offset-2 col-md-5 col-md-offset-2 col-sm-5 col-sm-offset-2">
    <?php print drupal_render($form['datos']) ?>
  </div>
  <div class="col-lg-3 col-md-3 col-sm-3">
    <?php print drupal_render($form['reserva']) ?>
  </div>
</div>
    <?php print drupal_render_children($form) ?>

