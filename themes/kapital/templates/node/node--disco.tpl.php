<div class="row mt-2">
  <div class="col-sm-3 col-xs-12">
    <?php print render($content['field_imagen']) ?>
  </div><!-- /.col-->
  <div class="col-sm-7 col-xs-12">
    <div class="row">
      <?php //aqui tenemos que poner varias condiciones.
        //Si el usuario está logueado deberíamos mostrar el boton de compra del producto con el precio normal. O el producto con precio rebajado si es socixs. Y un boton de hazte socix
        //Si no está logueado, habría que poner el producto normal y un botón de hazte socixs o que si lo eres te lleve a loguearte.
        //Habrá que comprobar si el usuario es socixs. Por ejemplo, guardando la lista de socixs en una variable de drupal y comprobando el email. ?>
          <div class="col-sm-4 col-xs-12 text-center">
            <h4><strong><?php print t('Socixs'); ?></strong></h4>
            36 €<br />
            <?php if (strpos(variable_get( 'lista_socixs', '' ), $user->mail) !== false) : ?>
              <p><?php print disco_generar_boton_product($node, "diska-socixs"); ?></p>
            <?php else : ?>
              <p></p>
              <p><a class="btn btn-primary btn-block" href="/eus/egin-zaitez-bazkide"><?php print t('Hazte Socix'); ?></a></p>
            <?php endif; ?>
          </div>
          <div class="col-sm-4 col-xs-12 text-center">
          <h4><strong><?php print t('Preventa'); ?></strong></h4>
            39 €<br />
            <p><?php print disco_generar_boton_product($node, "diska-aurresalmenta"); ?></p>
          </div>
          <div class="col-sm-4 col-xs-12 text-center">
            <h4><strong><?php print t('A partir del 14 de noviembre'); ?></strong></h4>
            44 €<br />
            <p><?php print disco_generar_boton_product($node); ?></p>
          </div>
    </div>
    <hr>
    <h1 class="mt-0"><?php print $node->title ?></h1>
    <p><?php print render($content['body']) ?></p>
    <hr>
    <!--TODO<h4>Compártelo:</h4>
    <p>RRSS</p>-->
  </div><!-- /.col-->
  <!-- <div class="col-sm-3">


  </div> --><!-- /.col-->
</div><!-- /.row -->