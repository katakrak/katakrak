<p>
  <a href="<?php print url('agenda') ?>" class="btn btn-transparent"> <i class="fas fa-arrow-left small"></i><?php print t('Listado de eventos') ?></a>
</p>

<div class="row mt-2">
  <div class="col-sm-3">
    <?php print render($content['field_event_image']) ?>
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
  <h3 class="mb-2">Libro recomendado:</h3>
  <?php print render($content['field_event_libro']) ?>
<?php endif; ?>
