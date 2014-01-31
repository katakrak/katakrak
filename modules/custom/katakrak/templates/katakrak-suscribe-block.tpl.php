  <div class="row-fluid">
    <div class="suscribe-block suscribe-block-help span4">
      <?php print t('¿Quieres estar al tanto de todo lo que ocurre en Katakrak? Suscribete al boletín de noticias') ?>
    </div>
    <div class="suscribe-block span6">
      <?php print render($form['mail']) ?>
    </div>
    <div class=" suscribe-block span2">
       <?php print render($form['submit']) ?>
    </div>
    <?php print render($form) ?>
</div>
<div class="clear"></div>