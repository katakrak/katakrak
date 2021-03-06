<?php

$rows = array();
foreach($view->result as $result) {
  $rows[format_date($result->field_field_event_date[0]['raw']['value'] , 'custom', 'F')][] = $result;
}
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php foreach ($rows as $month => $events): ?>
  <h1><?php print $month ?></h1>
  <div class="row row-posts mt-3">
    <?php foreach ($events as $event): ?>
      <div class="col-md-4 col-sm-6 mb-2 col-post">
        <div class="post">
          <div class="post-image">
            <a href="<?php print url("node/".$event->nid) ?>">
              <?php print theme('agenda_date', array('time' => $event->field_field_event_date[0]['raw']['value'], 'class' => 'date')) ?>
                
              <?php print drupal_render($event->field_field_event_image[0]['rendered']) ?>
            </a>
          </div>
          <h3 class="post-title">
              <a href="<?php print url("node/".$event->nid) ?>"><?php print $event->field_title_field [0]['raw']['value'] ?></a>
          </h3>
          <!-- <p class="mb-0">Tonino Carotone</p> -->
          <p class="small text-gray"><?php print t($event->field_field_event_type[0]['rendered']['#markup']) ?></p>
        </div><!--/.post -->
      </div><!--/.col-post -->
    <?php endforeach; ?>
  </div>
<?php endforeach; ?>
