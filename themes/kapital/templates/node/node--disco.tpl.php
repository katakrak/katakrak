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
  <?php var_dump( $user->mail ); ?>
    <?php var_dump( variable_get( 'lista_socixs', '' ) ); ?>
    <?php var_dump( strpos( variable_get( 'lista_socixs', '' ), $user->mail) ); ?>
    <?php if ($user->uid == 1): ?>
      39€
      <p><?php print disco_generar_boton_product($node) ?></p>
      <?php else: ?>
        <p><?php print disco_generar_boton_product($node, "diska-socixs") ?></p>
    <?php endif; ?>

    <hr>
  </div><!-- /.col-->
</div><!-- /.row -->