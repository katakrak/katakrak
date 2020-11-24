<p>
  <a href="<?php print url('agenda') ?>" class="btn btn-transparent"> <i class="fas fa-arrow-left small"></i><?php print t('Listado de eventos') ?></a>
</p>
<div class="row mt-2">
  <div class="col-sm-4">
    <?php print render($content['field_image']) ?>
  </div><!-- /.col-->
        <div class="col-sm-8">
          <div class="d-flex event-title">
            <div>
              <h1 class="mt-0"><?php print $node->title ?></h1>
             <p class="lead"><?php print render($content['field_ciclo_descripci_n']) ?></p>
              
            </div>
          </div>
         <p>(?) Damos información sobre cómo apuntarse... precios si lo hubiere...</p>
        <hr>
            
        <h4>Compártelo:</h4>
        <p>RRSS</p>
        </div><!-- /.col-->
        


    </div><!-- /.row -->
    <hr class="hr-dark">
    <h3 class="mb-2"><?php print t('Eventos relacionados') ?></h3>
     <?php print views_embed_view('agenda', 'citas_ciclo', $node->nid) ?>