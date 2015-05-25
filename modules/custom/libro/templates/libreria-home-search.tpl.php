
<?php if ($terms): ?>
<h1><?php print t('@count libros a tu alcance', array('@count' => $total_count))?></h1>
  <p><?php print t('En ')?>
    <?php foreach ($terms as $i => $term): ?>
      <?php print l($term->name, 'taxonomy/term/'.$term->tid) ?><?php print ($i < count($terms) - 1) ? ',': ''; ?>
    <?php endforeach; ?>
    <?php print t('y otras tantas') ?>
  </p>
<?php else: ?>
  <h1><?php print t('@count libros en !term', array('@count' => $total_count, '!term' => $seccion->name))?></h1>
<?php endif; ?>
<?php print drupal_render($form) ?>
