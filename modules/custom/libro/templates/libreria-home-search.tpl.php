<h1><?php print t('@count libros a tu alcance', array('@count' => $total_count))?></h1>
<?php if ($terms): ?>
  <p><?php print t('En ')?>
    <?php foreach ($terms as $term): ?>
      <?php print l($term->name, 'taxonomy/term/'.$term->tid) ?> 
    <?php endforeach; ?>
  </p>
<?php endif; ?>
<?php print drupal_render($form) ?>
