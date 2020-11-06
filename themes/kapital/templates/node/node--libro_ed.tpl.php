<?php dpm($node) ?>
<!-- Ficha libro -->
<div class="book">
  <div class="cover">
    <?php print render($content['field_libro_portada']) ?>
  </div><!-- /cover -->
  
  <div class="visible-xs-block">
    <h1><?php print $node->title?></h1>
    <h2 class="mt-0"><?php print render($content['field_libro_subtitulo']) ?></h2>
    <p>
      <h4><?php print render($content['field_libro_autores'])  ?></h4>
      <?php if (!empty($node->traductores)): ?>
        <?php print t('Traducción de !name', array('!name' => $node->traductores)) ?>
      <?php endif; ?>
    </p>
  </div>

  <div class="buy">
    <p class="price"><?php print t($content['field_libro_ed_precio'][0]['#markup']) ?>€</p>
    <p class="small text-color-light"><?php print t("IVA incluido" ) ?></p>
    <p class="success"><?php print t('Disponible') ?></p>
    
    <?php //TODO ?>
    <div class="mt-2">
        <button class="btn btn-primary btn-block">Comprar</button>
        <button class="btn btn-secondary btn-block">Añadir a la cesta</button>
    </div>
    <div class="mt-2">
      <button class="btn btn-dark btn-block">Descargar</button>
    </div>
    <?php //ENDTODO ?>
  </div><!-- /buy -->
  <div class="description">
    <h1 class="hidden-xs"><?php print $node->title?></h1>
    <h2 class="hidden-xs mt-0"><?php print render($content['field_libro_subtitulo']) ?></h2>
    <p class="hidden-xs">
      <h4><?php print render($content['field_libro_ed_autor']) ?></h4>
      <?php if (!empty($node->traductores)): ?>
        <?php print t('Traducción de !name', array('!name' => $node->traductores)) ?>
      <?php endif; ?>
    </p>
    <div class="mt-2">
      <table class="table table-condensed table-book">
        <tbody>
          <tr>
            <th>ISBN</th>
            <td><?php print $content['field_libro_isbn'][0]['#markup'] ?></td>
          </tr>
          <tr>
            <th><?php print t('Idioma') ?></th>
            <td><?php print $content['field_libro_idioma'][0]['#markup'] ?></td>
          </tr>
          <tr>
            <th><?php print t('Páginas') ?></th>
            <td><?php print $content['field_libro_paginas'][0]['#markup'] ?></td>
          </tr>
          <tr>
            <th><?php print t('Tamaño') ?></th>
            <td><?php print $content['field_libro_ed_tamano'][0]['#markup'] ?></td>
          </tr>
          <tr>
            <th><?php print t('Encuadernación') ?></th>
            <td><?php print t($content['field_libro_ed_encuadernacion'][0]['#markup']) ?></td>
          </tr>
          <tr>
            <th><?php print t('Precio') ?></th>
            <td><?php print t($content['field_libro_ed_precio'][0]['#markup']) ?></td>
          </tr>
        </tbody>
      </table>
    </div>
    <p class="quote">
      <?php print render($content['field_libro_sinopsis']) ?>
    </p>
    
  </div><!-- /description -->
</div>
<div class="row">
  <div class="col-sm-6">
   <hr class="hr-dark">
   <h2 class="text-center"><?php print t("En la prensa")?></h2>
   <?php foreach ($node->resenas as $resena): ?>
    <div class="resena">
    <p class="resena-cita"><?php print $resena->cita ?></p>
    <p class="resena-fuente"><?php print l($resena->fuente, "node/".$resena->nid); ?></p>
  </div>
  <?php endforeach; ?>
  </div>
  <div class="col-sm-6">
   <hr class="hr-dark">
   <h2 class="text-center">Acerca de Silvia Federici</h2>
   <p>Texto</p>
   <p>
     <a class="btn btn-secondary">Saber más</a>
   </p>
  </div>
</div>
