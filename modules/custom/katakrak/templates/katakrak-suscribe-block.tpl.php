  <div class="row-fluid">
    <div class="suscribe-block suscribe-block-help span4">
      <div class="row-fluid">
        <div class="span4">
        <i class="fa fa-envelope fa-5x"></i>
        </div>
      <div class="span8">
        <?php print t('¿Quieres estar al tanto de todo lo que ocurre en Katakrak? Suscribete al <span class="colored-text">boletín de noticias</span>') ?>
      </div>
      </div>
    </div>
    <div class="suscribe-block span6">
      <?php print drupal_render($form['mail']) ?>
    </div>
    <div class=" suscribe-block span2">
       <?php print drupal_render($form['submit']) ?>
    </div>
    <?php print drupal_render_children($form) ?>
</div>
<div class="clear"></div>