<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="row">
  <div class="col-lg-7">
    <?php print theme('image_style', array('style_name' => 'home_agenda_main', 'path' => $view->result[0]->field_field_event_image[0]['raw']['uri'])) ?>
  </div>
  <div class="col-lg-5">
    <?php print theme('image_style', array('style_name' => 'home_agenda', 'path' => $view->result[1]->field_field_event_image[0]['raw']['uri'])) ?>
    <?php print theme('image_style', array('style_name' => 'home_agenda', 'path' => $view->result[2]->field_field_event_image[0]['raw']['uri'])) ?>
  </div>
</div>