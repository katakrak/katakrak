<?php $options = array('html' => TRUE) ?>

<div class="cta cta-tienda">
  <div class="cta-text">
    <div>
      <h1 class="h1-lg"><?php print t("¿Buscas un libro?") ?></h1>
      <p class="lead"><?php print t('Te lo llevamos de la forma más sostenible') ?></p>
    </div>
    <button class="btn btn-dark"><?php print t('Tienda online') ?></button>
  </div><!--/.cta-text -->
  <div class="books">
   <div class="books-col">
     <div class="books-col-item">
       <?php print l(theme('image_style', array('style_name' => $books[0]->field_field_libro_portada[0]['rendered']['#image_style'], 'path' => $books[0]->field_field_libro_portada[0]['raw']['uri'])), 'node/'.$books[0]->nid, $options) ?>
     </div>
     <div class="books-col-item">
       <?php print l(theme('image_style', array('style_name' => $books[1]->field_field_libro_portada[0]['rendered']['#image_style'], 'path' => $books[1]->field_field_libro_portada[0]['raw']['uri'])), 'node/'.$books[1]->nid, $options) ?>
     </div>
    </div><!--/.books-col -->
    <div class="books-col">
      <div class="books-col-item">
        <?php print l(theme('image_style', array('style_name' => $books[2]->field_field_libro_portada[0]['rendered']['#image_style'], 'path' => $books[2]->field_field_libro_portada[0]['raw']['uri'])), 'node/'.$books[2]->nid, $options) ?>
      </div>
      <div class="books-col-item">
        <?php print l(theme('image_style', array('style_name' => $books[3]->field_field_libro_portada[0]['rendered']['#image_style'], 'path' => $books[3]->field_field_libro_portada[0]['raw']['uri'])), 'node/'.$books[3]->nid, $options) ?>
      </div>
      <div class="books-col-item">
        <?php print l(theme('image_style', array('style_name' => $books[4]->field_field_libro_portada[0]['rendered']['#image_style'], 'path' => $books[4]->field_field_libro_portada[0]['raw']['uri'])), 'node/'.$books[4]->nid, $options) ?>
      </div>
    </div><!--/.books-col -->
    <div class="books-col hidden-xs">
      <div class="books-col-item">
        <?php print l(theme('image_style', array('style_name' => $books[5]->field_field_libro_portada[0]['rendered']['#image_style'], 'path' => $books[5]->field_field_libro_portada[0]['raw']['uri'])), 'node/'.$books[5]->nid, $options) ?>
      </div>
      <div class="books-col-item">
        <?php print l(theme('image_style', array('style_name' => $books[6]->field_field_libro_portada[0]['rendered']['#image_style'], 'path' => $books[6]->field_field_libro_portada[0]['raw']['uri'])), 'node/'.$books[6]->nid, $options) ?>
      </div>
    </div><!--/.books-col -->
   </div><!--/.books -->
  </div><!--/.cta-tienda -->