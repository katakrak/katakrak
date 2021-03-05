<!-- Ficha libro -->
<div class="book">
    <div class="cover">
      <?php print l(theme('image_style', array('style_name' => 'editorial_ficha', 'path' => $node->field_libro_portada['und'][0]['uri'])), 'node/'.$node->nid, array('html' => TRUE)) ?>
    </div><!-- /cover -->


    <div class="description download">
      <p class="text-gray small"><i class="far fa-file-pdf"></i> <?php print t('DESCARGA PDF') ?></p>
        <h1><?php print $node->title ?> </h1>
        <p>
            De <a href="#">Judith Shklar</a>
        </p>
        <p class="lead"><?php print t("Tras el PDF que te descargarás hay mucho trabajo. <br>Haz tu aportación según consideres.") ?></p>
        <form class="mb-2">
          <div class="radio">
            <label>
              <input type="radio" name="optionsRadios" id="optionsRadios1" value="option1" checked>
              3€
            </label>
          </div>
          <div class="radio">
            <label>
              <input type="radio" name="optionsRadios" id="optionsRadios2" value="option2">
              6€
            </label>
          </div>
          <div class="radio">
            <label>
              <input type="radio" name="optionsRadios" id="optionsRadios3" value="option3">
              9€
            </label>
          </div>
          <div class="radio">
            <label>
              <input type="radio" name="optionsRadios" id="optionsRadios3" value="option3">
              15€
            </label>
          </div>
          <div class="radio">
            <label>
              <input type="radio" name="optionsRadios" id="optionsRadios3" value="option3" checked>
              Otra cantidad
            </label>
          </div>
          <div class="field">
<input type="text" class="form-control" id="exampleInputEmail1" placeholder="Indica el precio que quieras donar">
          </div>
          <div class="field mt-2">
            <button class="btn btn-primary btn-xs-block">Donar</button>
          </div>

        </form>
    </div><!-- /description -->

</div>

<div class="row">
  <div class="col col-md-3 col-sm-3 col-xs-12">
    
  </div>
  <div class="col col-md-8 col-sm-8 col-xs-12">
    <div class="">
	<h1><?php print katakrak_editorial_donacion_title($node) ?></h1>
	  <p><strong><?php print t("Tras el PDF que te descargarás hay mucho trabajo. Haz tu aportación según consideres."); ?></strong>
	  </p>
      
    </div>

  </div>
  <div class="col col-md-2 col-sm-2 col-xs-12">
    
  </div>
</div>