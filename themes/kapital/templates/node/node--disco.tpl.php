<div class="row mt-2">
  <div class="col-sm-3">
    <?php print render($content['field_imagen']) ?>
  </div><!-- /.col-->
  <div class="col-sm-6">
    <h1 class="mt-0"><?php print $node->title ?></h1>
    <p><?php print render($content['body']) ?></p>
    <hr>
    <!--TODO<h4>Compártelo:</h4>
    <p>RRSS</p>-->
  </div><!-- /.col-->
  <div class="col-sm-3">

    <p>Botones de compra</p>
    <?php //aqui tenemos que poner varias condiciones.
    //Si el usuario está logueado deberíamos mostrar el boton de compra del producto con el precio normal. O el producto con precio rebajado si es socixs. Y un boton de hazte socix
    //Si no está logueado, habría que poner el producto normal y un botón de hazte socixs o que si lo eres te lleve a loguearte.
    //Habrá que comprobar si el usuario es socixs. Por ejemplo, guardando la lista de socixs en una variable de drupal y comprobando el email. ?>
      <strong><?php echo print t('Precio Socios'); ?></strong>
      36 €<br />
      <strong><?php echo print t('Precio Preventa'); ?></strong>
      39 €<br />
      <strong><?php echo print t('Precio completo, a partir del 12/12'); ?></strong>
      44 €<br />
      <?php if (strpos(variable_get( 'lista_socixs', '' ), $user->mail) !== false) : ?>
        <p><?php print disco_generar_boton_product($node, "diska-socixs"); ?></p>
      <?php ?>



      <?php else : ?>
        39 €
        <p><?php print disco_generar_boton_product($node); ?></p>
      <?php endif; ?>


    <hr>
  </div><!-- /.col-->
</div><!-- /.row -->