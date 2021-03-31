<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
  <div class="container">
    <h1 class="h1-lg text-center"><?php print t('Ponte al día') ?></h1>
    <p class="text-center"><?php print t('Si quieres recibir estas noticias en tu email, <a href="#">suscríbete aquí</a>' )?></p>
    <div class="row" data-aos="fade-up">
      <?php foreach ($rows as $id => $row): ?>
          <?php print $row; ?>
      <?php endforeach; ?>
    </div><!--/.row mt-4 -->
    <div class="text-center mt-3 mb-3">
      <?php print l(t('Ver más posts'), 'blogs', array('attributes' => array('class' => array('btn btn-secondary')))) ?>
    </div>
    
  </div><!--/.container -->

