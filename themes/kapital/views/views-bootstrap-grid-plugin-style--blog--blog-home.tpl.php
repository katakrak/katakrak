<?php
/**
 * @file views-bootstrap-grid-plugin-style.tpl.php
 * Default simple view template to display Bootstrap Grids.
 *
 *
 * - $columns contains rows grouped by columns.
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 * - $column_type contains a number (default Bootstrap grid system column type).
 * - $class_prefix defines the default prefix to use for column classes.
 *
 * @ingroup views_templates
 */ dpm ($items);
?>
<div class="wrapper-posts">
  <div class="container">
    <h1 class="h1-lg text-center"><?php print t('Ponte al día') ?></h1>
    <p class="text-center"><?php print t('Si quieres recibir estas noticias en tu email, <a href="#">suscríbete aquí</a>' )?></p>
    <div class="row mt-4">
    <?php foreach ($items as $row): ?>
        <div class="col-md-4 col-sm-6">
          <div class="post">
           <div class="post-image">
            <a href="#"><img src="images/tarkovski.jpg" class="img-responsive" alt=""></a>
           </div>
            <h3 class="post-title">
              <a href="#">¡Ya son más de 100! ¡Faltas tú!</a>
            </h3>
            <p class="small">Jueves 28 de mayo</p>
          </div><!--/.post -->
        </div><!--/.col -->
    <?php     endforeach; ?>
      
        
        <div class="col-md-4 col-sm-6">
          <div class="post">
           <div class="post-image">
            <a href="#"><img src="images/bici.jpg" class="img-responsive" alt=""></a>
           </div>
            <h3 class="post-title">
              <a href="#">Reparto en bici</a>
            </h3>
            <p class="small">Miércoles 27 de mayo</p>
          </div><!--/.post -->
        </div><!--/.col -->
        <div class="col-md-4 col-sm-6">
          <div class="post">
           <div class="post-image">
            <a href="#"><img src="images/diario.jpg" class="img-responsive" alt=""></a>
           </div>
            <h3 class="post-title">
              <a href="#">«Kapitalismoa eta emakumeen aurkako indarkeria» DIARIO VASCOn</a>
            </h3>
            <p class="small">Domingo 24 de mayo</p>
          </div><!--/.post -->
        </div><!--/.col -->
      </div><!--/.row -->
     <div class="text-center mt-3">
      <button class="btn btn-secondary">Ver más posts</button>
     </div>
  </div><!--/.container -->
</div><!--/.wrapper-posts -->
<?php if (!empty($title)): ?>
  <h3><?php print $title ?></h3>
<?php endif ?>
<div id="views-bootstrap-grid-<?php print $id ?>" class="<?php print $classes ?>">
  <?php if ($options['alignment'] == 'horizontal'): ?>

    <?php foreach ($items as $row): ?>
      <div class="row">
        <?php foreach ($row['content'] as $key => $column): ?>
          <div class="<?php print $col_classes ?>">
            <?php print $column['content'] ?>
          </div>

          <?php /* Add clearfix divs if required */ ?>
          <?php if ($options['columns_horizontal'] == -1 && !empty($options['clear_columns']) && $key != 0): ?>
            <?php foreach ($clearfix as $screen => $count): ?>
              <?php if (($key + 1) % $count == 0): ?>
                <div class="clearfix visible-<?php print $screen; ?>-block"></div>
              <?php endif; ?>
            <?php endforeach; ?>
          <?php endif; ?>
        <?php endforeach ?>
      </div>
    <?php endforeach ?>

  <?php else: ?>

    <div class="row">
      <?php foreach ($items as $column): ?>
        <div class="<?php print $col_classes ?>">
          <?php foreach ($column['content'] as $row): ?>
              <?php print $row['content'] ?>
          <?php endforeach ?>
        </div>
      <?php endforeach ?>
    </div>

  <?php endif ?>
</div>
