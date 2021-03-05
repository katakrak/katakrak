<!-- Ficha libro -->
<div class="book">
    <div class="cover">
      <?php print l(theme('image_style', array('style_name' => 'editorial_ficha', 'path' => $node->field_libro_portada['und'][0]['uri'])), 'node/'.$node->nid, array('html' => TRUE)) ?>
    </div><!-- /cover -->


    <div class="description download">
      <p class="text-gray small"><i class="far fa-file-pdf"></i> <?php print t('DESCARGA PDF') ?></p>
        <h1><?php print $node->title ?> </h1>
        <p>
          <?php foreach ($node->autores as $i => $autor): ?>
          <?php print l($autor->title, 'node/'.$autor->nid) ?><?php print $i == count($node->autores)-1? ' ' : ', '; ?>
          <?php endforeach; ?>
        </p>
        <p class="lead"><?php print t("Tras el PDF que te descargarás hay mucho trabajo. <br>Haz tu aportación según consideres.") ?></p>
        <?php print render($form_donate) ?> 
        <?php print $form_download ?> 
    </div><!-- /description -->

</div>
