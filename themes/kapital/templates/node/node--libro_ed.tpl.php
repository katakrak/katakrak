<?php if ($page): ?>
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

  <?php if ($node->field_editorial_libro['und'][0]['nid']): ?>
  <div class="buy">
    <p class="price"><?php print t($content['field_libro_ed_precio'][0]['#markup']) ?>€</p>
    <p class="small text-color-light"><?php print t("IVA incluido" ) ?></p>
    <p class="success"><?php print t('Disponible') ?></p>
    
    <?php //TODO ?>
    <div class="mt-2">
        <?php print libro_generar_boton_product($node->field_editorial_libro['und'][0]['nid']) ?>
        <?php print libro_generar_boton_product($node->field_editorial_libro['und'][0]['nid'], TRUE) ?>
    </div>
    <?php if ($node->field_donacion['und'][0]['product_id']): ?>
    <div class="mt-2">
      <button class="btn btn-dark btn-block"><?php print l(t("Descargar"), "donate/".$node->nid) ?></button>
    </div>
      <?php endif; ?>
    
    <?php //ENDTODO ?>
  </div><!-- /buy -->
  <?php endif; ?>
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
          <?php if ($content['field_libro_editorial_nota']): ?>
          <tr>
            <th>	<?php  print t($content['field_libro_editorial_nota']['#items'][0]['description'])  ?></th>
            <td><?php print render($content['field_libro_editorial_nota']) ?></td>
          </tr>
			<?php endif; ?>
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
    <?php if ($node->resenas): ?>
    <hr class="hr-dark">
    <h2 class="text-center"><?php print t("En la prensa")?></h2>
    <div class="scroll-v h500">
      <?php foreach ($node->resenas as $resena): ?>
        <a class="post-prensa" href="<?php print url("node/".$resena->nid) ?>">
          <p class="quote"><?php print $resena->cita ?></p>
          <p class="mb-0"><?php print $resena->fuente ?></p>
        </a>
      <?php endforeach; ?>
    </div>
    <?php endif; ?>
  </div>
  <div class="col-sm-6">
    <hr class="hr-dark">
    <?php foreach($node->autores as $autor): ?>
      <h2 class="text-center"><?php print t('Acerca de !autor', array('!autor' => $autor->title)) ?></h2>
      <?php print theme('image_style', array('style_name' => 'autor_editorial_ficha_libro', 'path' => $autor->field_imagen['und'][0]['uri'], 'attributes' => array('class' => array('img-shadow book-author')))) ?>
      <p><?php print $autor->field_autor_nacimiento['und'][0]['value'] ?></p>
      <p><?php print truncate_utf8($autor->body['und'][0]['value'], 640, TRUE, TRUE) ?></p>
      <p><?php print l(t('Saber más'), 'node/'.$autor->nid, array('attributes' => array('class' => array('btn btn-secondary')))) ?></p>
  <?php endforeach; ?>
   
  </div>
</div>

<div class="hidden color-fondo"><?php print $node->field_libro_ed_color['und'][0]['value'] ?></div>
<?php endif; ?>
<?php if ($view_mode == 'card_book'): ?>
<div class="card-book-editorial">
  <div class="cover">
    <?php print render($content['field_libro_portada']) ?>
  </div><!-- /cover -->
    <div class="description">
    <h3 class="book-title-sm mb-1">
      <a href="<?php print url('node/'.$node->nid) ?>">
        <?php print $node->title?>
      </a>
      </h3>
      <p class="mb-05">Louise Michel</p>
      <p class="price">22,00€</p>
      <p class="small success">Disponible</p>
    </div><!-- /.description -->
</div><!-- /.card-book -->
<?php endif; ?>
<?php if ($view_mode == 'card_book_md'): ?>
<div class="card-book-md">
  <div class="cover">
    <?php print render($content['field_libro_portada']) ?>
  </div><!-- /cover -->
    <div class="description">
    <h3 class="mt-0">
      <a href="<?php print url('node/'.$node->nid) ?>">
        <?php print $node->title?>
      </a>
      </h3>
      <p class="mb-05"><?php print render($content['field_libro_ed_autor']) ?></p>
      <p class="price"><?php print t($content['field_libro_ed_precio'][0]['#markup']) ?>€</p>
      <p class="small success"><?php print t("Disponible") ?></p>
    </div><!-- /.description -->
</div><!-- /.card-book -->
<?php endif; ?>