<p>
  <a href="<?php print url('agenda') ?>" class="btn btn-transparent"> <i class="fas fa-arrow-left small"></i><?php print t('Listado de eventos') ?></a>
</p>
<div class="row mt-2">
  <div class="col-sm-4">
    <?php print render($content['field_image']) ?>
    <hr class="hr-dark">
    <?php $field_url_denda = render($content['field_url_denda']);
 ?>
    <a href="<?php echo $field_url_denda; ?>"><?php print t('Apuntarse'); ?></a>
    <hr class="hr-dark">
    <h3 class="mb-2"><?php print t('Producto relacionado') ?></h3>
     <?php print render($content['field_producto_ciclo']) ?>
    </div><!-- /.col-->
        <div class="col-sm-8">
          <div class="d-flex event-title">
            <div>
              <h1 class="mt-0"><?php print $node->title ?></h1>
             <p class="lead"><?php print render($content['field_ciclo_descripci_n']) ?></p>

            </div>
          </div>
        <hr>

        <!--TODO<h4>Compártelo:</h4>
        <p>RRSS</p>-->
        </div><!-- /.col-->



    </div><!-- /.row -->
    <hr class="hr-dark">
    <h3 class="mb-2"><?php print t('Eventos relacionados') ?></h3>
     <?php print views_embed_view('agenda', 'citas_ciclo', $node->nid) ?>

    <hr class="hr-dark">
    <h3 class="mb-2"><?php print t('Libros relacionados') ?></h3>
     <?php print render($content['field_ciclo_libros']) ?>
