<div class="row mt-2">
  <div class="col-sm-4">
    <?php print render($content['field_imagen']) ?>
    
    <!-- <h3 class="mb-2"><?php //print t('Producto relacionado') ?></h3>-->
     <?php //print render($content['field_producto_ciclo']) ?>
    </div><!-- /.col-->
        <div class="col-sm-8">
          <div class="d-flex event-title">
            <div>
              <h1 class="mt-0"><?php print $node->title ?></h1>
              <p class="lead">
                <?php print render($content['body']) ?>
              </p>
            </div>
          </div>
      

        <!--TODO<h4>Compártelo:</h4>
        <p>RRSS</p>-->
        </div><!-- /.col-->



    </div><!-- /.row -->

    <hr class="hr-dark">
    <h3 class="mb-2"><?php print t('Libros del itinerario') ?></h3>
     <?php //print render($content['field_itinerario_libros']) ?>
     <?php print views_embed_view('libros', 'libros_itinerario', $node->nid) ?>