<div class="row">
  <div class="col-lg-6">
    <?php print drupal_render($form['datos']) ?>
  </div>
  <div class="col-lg-6">
    
    <?php print drupal_render($form['date']) ?>
  </div>
    
</div>
<?php print drupal_render_children($form) ?>