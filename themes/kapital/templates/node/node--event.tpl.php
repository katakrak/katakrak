<?php 

// Fetch the value of the field_event_image_class from the content array.
$image_class = $content['field_event_image_class'][0]['#markup'];

// Render the image field.
$image_field = render($content['field_event_image']);

// Use PHP's DOM manipulation functions to add the class.
$dom = new DOMDocument();
$dom->loadHTML($image_field, LIBXML_HTML_NOIMPLIED | LIBXML_HTML_NODEFDTD);
$images = $dom->getElementsByTagName('img');
foreach ($images as $image) {
    $existing_class = $image->getAttribute('class');
    $image->setAttribute('class', $existing_class . ' ' . $image_class);
}

// Save the modified HTML.
$modified_image_field = $dom->saveHTML();
?>



<p>
  <a href="<?php print url('agenda') ?>" class="btn btn-transparent"> <i class="fas fa-arrow-left small"></i><?php print t('Listado de eventos') ?></a>
</p>

<div class="row mt-2">
  <div class="col-sm-3">
    <?php print render($content['field_event_image']) ?>
    <?php // Print the modified HTML.
    echo "hello";
          print $modified_image_field; ?>
  </div><!-- /.col-->
  <div class="col-sm-9">
    <div class="d-flex event-title">
      <?php print theme('agenda_date', array('time' => $node->field_event_date['und'][0]['value'], 'class' => 'date date-title')); ?>
      <div>
        <h1 class="mt-0"><?php print $node->title ?></h1>
        <!--<p class="mb-0">Chuck D</p> TODO: Tiene sentido poner aquí la persona que da la charla??-->
        <p class="small text-gray"><?php print render($content['field_event_type']) ?></p>
      </div>
    </div>
  
    <?php if ($node->field_soundcloud['und'][0]['value']): ?>
      <hr>
      <?php print $node->field_soundcloud['und'][0]['value'] ?>
    <?php endif; ?>
    <hr>
     <?php print render($content['field_event_description']) ?>
    <?php print render($content['field_event_soundcloud']) ?>
    <hr>
    <!--<ul class="list-inline list-tags">
      <li>
          <a href="#"><span class="badge">ChuckD</span></a>
      </li>
      <li>
          <a href="#"><span class="badge">ChuckD</span></a>
      </li>
    </ul>-->
  </div><!-- /.col-->



</div><!-- /.row -->
<?php if ($node->field_event_libro['und'][0]): ?>
  <hr class="hr-dark">
  <h3 class="mb-2"><?php print t('Libro recomendado') ?>:</h3>
  <?php print render($content['field_event_libro']) ?>
<?php endif; ?>
