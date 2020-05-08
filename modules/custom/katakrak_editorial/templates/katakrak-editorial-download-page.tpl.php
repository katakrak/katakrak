

<div class="row">
  <div class="col col-md-3 col-sm-3 col-xs-12">
    <?php print l(theme('image_style', array('style_name' => 'editorial_ficha', 'path' => $node->field_libro_portada['und'][0]['uri'])), 'node/'.$node->nid, array('html' => TRUE)) ?>
  </div>
  <div class="col col-md-8 col-sm-8 col-xs-12">
    <div class="">
	<h1><?php print katakrak_editorial_donacion_title($node) ?></h1>
	  <p><strong><?php print t("Tras el PDF que te descargarás hay mucho trabajo. Haz tu aportación según consideres."); ?></strong>
	  </p>
      <?php print $form_donate ?>
      <?php print $form_download ?>
    </div>

  </div>
  <div class="col col-md-2 col-sm-2 col-xs-12">
    
  </div>
</div>