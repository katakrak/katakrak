  <div class="row">
    <div class="suscribe-block suscribe-block-help col-md-4">
      <div class="row">
        <div class="col-md-4">
        <i class="fa fa-envelope fa-5x blue-envelope"></i>
        </div>
        <div class="col-md-8">
          <?php print t('¿Quieres estar al tanto de todo lo que ocurre en Katakrak? Suscribete al <span class="colored-text">boletín de noticias</span>') ?>
        </div>
      </div>
    </div>
    <div class="suscribe-block col-md-6">
      <?php print drupal_render($form['mail']) ?>
    </div>
    <div class=" suscribe-block col-md-2">
       <?php print drupal_render($form['submit']) ?>
    </div>
    <?php print drupal_render_children($form) ?>
</div>
<div class="clear"></div>