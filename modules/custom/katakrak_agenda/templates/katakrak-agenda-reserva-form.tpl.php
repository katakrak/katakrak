
<div class="row">
  <div class="col-sm-8 col-sm-offset-2 mt-2">
    <h2><?php print t('Quiero organizar un acto') ?></h2>
    <p><?php print t('Este formulario nos ayudará a saber qué necesitas.') ?></p>
    <div class="mt-2 mb-4">
      <?php print drupal_render($form['nombre']) ?>
      
      <div class="row">
        <div class="col-sm-6">
          <?php print drupal_render($form['email']) ?>
        </div>
        <div class="col-sm-6">
          <?php print drupal_render($form['telefono']) ?>
        </div>
      </div>
      <?php print drupal_render($form['sala']) ?>
      <?php print drupal_render($form['date']) ?>
      <?php print drupal_render($form['explicacion']) ?>
    <?php print drupal_render_children($form) ?>
    </div>
    
    
  </div>
</div>

