<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

 <div class="row row-posts mt-3">
<?php foreach ($view->result as $event): ?>
  <div class="col-md-4 col-sm-6 mb-2 col-post">
    <div class="post">
      <div class="post-image">
        <a href="<?php print url("node/".$event->nid) ?>">
          <div class="date">
            <p class="day"><?php print format_date($event->field_field_event_date[0]['raw']['value'], 'custom', 'd') ?></p>
            <p class="small"><?php print format_date($event->field_field_event_date[0]['raw']['value'], 'custom', 'F') ?></p>
            <p class="time"><?php print format_date($event->field_field_event_date[0]['raw']['value'], 'custom', 'H:i') ?></p>
          </div>
          <?php print drupal_render($event->field_field_event_image[0]['rendered']) ?>
        </a>
      </div>
      <h3 class="post-title">
          <a href="<?php print url("node/".$event->nid) ?>"><?php print $event->field_title_field[0]['raw']['value'] ?></a>
      </h3>
    </div><!--/.post -->
  </div><!--/.col-post -->

<?php endforeach; ?>
 </div>