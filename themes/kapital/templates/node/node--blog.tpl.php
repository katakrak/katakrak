
<p>
  <a href="<?php print url('blog')?>" class="btn btn-transparent"> <i class="fas fa-arrow-left small"></i> <?php print t('Listado de artículos') ?></a>
</p>

<div class="row mt-2">
  <div class="col-sm-3">
    <?php print render($content['field_image']) ?>
  </div><!-- /.col-->
  <div class="col-sm-9">
    <h1 class="mt-0"><?php print $node->title ?></h1>
    <p><?php print render($content['field_blog_cuerpo']) ?></p>
    <hr>
    <h4>Compártelo:</h4>
    <p>RRSS</p>
  </div><!-- /.col-->
</div><!-- /.row -->
<?php if ($node->field_blog_libro['und'][0]): ?>
  <hr class="hr-dark">
  <h3 class="mb-2"><?php print t('Libro recomendado') ?>:</h3>
  <?php print render($content['field_blog_libro']) ?>
<?php endif; ?>
  
  <hr class="hr-dark">
<?php $related_blogs = views_get_view_result('blog', 'related_blog_posts', $node->field_blog_type['und'][0]['tid'], $node->nid); ?>
<?php if ($related_blogs): ?>
  <h3 class="mb-2"><?php print t('Artículos relacionados')?></h3>
  <div class="row mt-1"><?php print views_embed_view('blog', 'related_blog_posts', $node->field_blog_type['und'][0]['tid'], $node->nid) ?></div>
<?php endif; ?>
