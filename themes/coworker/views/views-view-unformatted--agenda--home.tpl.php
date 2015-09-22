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
<div class="row ">
  <div class="col-lg-7 col-md-7">
    <div class="home-event">
      <?php print l(
      theme('image_style', array('style_name' => 'home_agenda_main', 'path' => $view->result[0]->field_field_event_image[0]['raw']['uri'])).
        '<div class="home-events-title home-events-title-main">'.
        theme('agenda_date', array('time' => $view->result[0]->field_field_event_date[0]['raw']['value'])).
        '<div class="event_info"><h2>'.$view->result[0]->node_title.'</h2>'.
        '<h3>'.$view->result[0]->field_field_event_type[0]['rendered']['#markup'].'</h3></div>'.
        '</div>',
      'node/'.$view->result[0]->nid, array('html' => TRUE)); ?>

    </div>
    <div class="home-event hidden-xs hidden-sm">
      <?php print l(
      theme('image_style', array('style_name' => 'home_agenda_main_secondary', 'path' => $view->result[3]->field_field_event_image[0]['raw']['uri'])).
        '<div class="home-events-title home-events-title-main">'.
        theme('agenda_date', array('time' => $view->result[3]->field_field_event_date[0]['raw']['value'])).
        '<div class="event_info"><h2>'.$view->result[3]->node_title.'</h2>'.
        '<h3>'.$view->result[3]->field_field_event_type[0]['rendered']['#markup'].'</h3></div>'.
        '</div>',
      'node/'.$view->result[3]->nid, array('html' => TRUE, 'attributes' => array('class' => array('home_events_second'))));  ?>
    </div>
  </div>
  <div class="col-lg-5 col-md-5">
    <div class="home-event">
      <?php print l(
        theme('image_style', array('style_name' => 'home_agenda', 'path' => $view->result[1]->field_field_event_image[0]['raw']['uri'])).
        '<div class="home-events-title home-events-title-second">'.
        theme('agenda_date', array('time' => $view->result[1]->field_field_event_date[0]['raw']['value'])).
        '<div class="event_info"><h2>'.$view->result[1]->node_title.'</h2>'.
        '<h3>'.$view->result[1]->field_field_event_type[0]['rendered']['#markup'].'</h3></div>'.
        '</div>',
        'node/'.$view->result[1]->nid, array('html' => TRUE));  ?>
    </div>
    <div class="home-event">
    <?php print l(
      theme('image_style', array('style_name' => 'home_agenda', 'path' => $view->result[2]->field_field_event_image[0]['raw']['uri'])).
        '<div class="home-events-title home-events-title-second">'.
        theme('agenda_date', array('time' => $view->result[2]->field_field_event_date[0]['raw']['value'])).''.
        '<div class="event_info"><h2>'.$view->result[2]->node_title.'</h2>'.
        '<h3>'.$view->result[2]->field_field_event_type[0]['rendered']['#markup'].'</h3></div>'.
        '</div>',
      'node/'.$view->result[2]->nid, array('html' => TRUE, 'attributes' => array('class' => array('home_events_second'))));  ?>
    </div>
    <div class="home-event visible-xs visible-sm"><?php print l(
      theme('image_style', array('style_name' => 'home_agenda', 'path' => $view->result[3]->field_field_event_image[0]['raw']['uri'])).
        '<div class="home-events-title">'.
        theme('agenda_date', array('time' => $view->result[3]->field_field_event_date[0]['raw']['value'])).
        '<div class="event_info"><h2>'.$view->result[3]->node_title.'</h2>'.
        '<h3>'.$view->result[3]->field_field_event_type[0]['rendered']['#markup'].'</h3></div>'.
        '</div>',
      'node/'.$view->result[3]->nid, array('html' => TRUE, 'attributes' => array('class' => array('home_events_second'))));  ?>
  </div>
  </div>
    </div>