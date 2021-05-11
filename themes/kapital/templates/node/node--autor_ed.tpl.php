<p>
  <a href="<?php print url('editorial/autores') ?>" class="btn btn-transparent"> <i class="fas fa-arrow-left small"></i> <?php print t('Listado de autores/as') ?></a>
</p>

<div class="row mt-2">
  <div class="col-sm-3">
    <p class="mb-2">
      <?php print render($content['field_imagen']) ?>
    </p>
  </div><!-- /.col-->
  <div class="col-sm-9">
    <h1 class="mt-0"><?php print $node->title?></h1>
    <p class="text-gray"><?php print $content['field_autor_nacimiento']['#items'][0]['value'] ?></p>
      <p><?php print render($content['body']) ?></p>
    <hr>
  </div><!-- /.col-->
</div><!-- /.row -->
    
<hr class="hr-dark">
<?php if ($page): ?>
      <?php $view_libros_pub = views_get_view_result('editorial', 'libros_autor', $node->tnid)?>
      <?php if ($view_libros_pub): ?>
        <h2 class="mb-2"><?php print t('En la editorial:')?></h2>
        <?php print views_embed_view('editorial', 'libros_autor', $node->tnid) ?>
      <?php endif; ?>

      <?php $view_libros_trad = views_get_view_result('editorial', 'libros_traductor', $node->tnid)?>
      <?php if ($view_libros_trad): ?>
        <h2 class="mb-2"><?php print t('Libros traducidos')?>:</h2>
        <?php print views_embed_view('editorial', 'libros_traductor', $node->tnid) ?>
      <?php endif; ?>

      <?php $view_libreria = views_get_view_result('libros', 'libros_rel_autor', $node->field_libro_autores['und'][0]['tid'])?>
      <?php if ($view_libreria): ?>
        <h2 class="mb-2"><?php print t('En la librería')?>:</h2>
        <?php print views_embed_view('libros', 'libros_rel_autor', $node->field_libro_autores['und'][0]['tid']) ?>
      <?php endif; ?>
<?php endif; ?>