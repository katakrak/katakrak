<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="wrapper-posts">
  <div class="container">
    <h1 class="h1-lg text-center"><?php print t('Ponte al día') ?></h1>
    <p class="text-center"><?php print t('Si quieres recibir estas noticias en tu email, <a href="#">suscríbete aquí</a>' )?></p>
    <div class="row mt-4" data-aos="fade-up">
      <?php foreach ($rows as $id => $row): ?>
        <div<?php if ($classes_array[$id]): ?> class="col-md-4 col-sm-6 <?php print $classes_array[$id]; ?>"<?php endif; ?>>
          <?php print $row; ?>
        </div>
      <?php endforeach; ?>
    </div><!--/.row mt-4 -->
    <div class="text-center mt-3">
      <?php print l(t('Ver más posts'), 'blogs', array('attributes' => array('class' => array('btn btn-secondary')))) ?>
    </div>
    
  </div><!--/.container -->
</div><!--/.wrapper-posts -->

