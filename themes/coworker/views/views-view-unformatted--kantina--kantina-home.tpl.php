<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 * 
        '<p>'.$view->result[0]->field_field_event_descripcion[0]['raw']['summary'].'</p>'.
 */
?>
<div class="row">
  <div class="col-lg-7 col-md-7 col-sm-7 col-kantina">
    <div class="views-field-field-image">
      <?php print theme('image_style', array('style_name' => 'kantina_large', 'path' => $view->result[0]->field_field_imagen[0]['raw']['uri'])) ?>
<!--      <div class="term-name">
        <h3><?php print $view->result[0]->node_title?></h3>
      </div>-->
    </div>
  </div>
  <div class="col-lg-5 col-md-5 col-sm-5 col-kantina">
    <div class="views-field-field-image">
      <?php print theme('image_style', array('style_name' => 'kantina_medium', 'path' => $view->result[1]->field_field_imagen[0]['raw']['uri'])) ?>
<!--      <div class="term-name">
        <h3><?php print $view->result[1]->node_title?></h3>
      </div>-->
    </div>
  </div> 
</div>

<div class="row kantina-images-second-row">
  <div class="col-lg-5 col-md-5 col-sm-5">
    <div class="views-field-field-image">
      <?php print theme('image_style', array('style_name' => 'kantina_medium', 'path' => $view->result[2]->field_field_imagen[0]['raw']['uri'])) ?>
<!--      <div class="term-name">
        <h3><?php print $view->result[2]->node_title?></h3>
      </div>-->
    </div>
  </div>
  <div class="col-lg-7 col-md-7 col-sm-7">
    <div class="views-field-field-image">
    <?php print theme('image_style', array('style_name' => 'kantina_large', 'path' => $view->result[3]->field_field_imagen[0]['raw']['uri'])) ?>
<!--      <div class="term-name">
        <h3><?php print $view->result[3]->node_title?></h3>
      </div>-->
    </div>
  </div> 
</div>