<div class="errezeta-taula">
  <?php print theme('table', $node->produktu_taula) ?>
</div>
<?php if ($node->field_producto_primario['und'][0]['value'] == 0): ?>
  <div class="row">
  <div class="col-md-6">
    <label>Precio por racion:</label>
     <?php print $node->field_errezeta_prezioa['und'][0]['value'] ?>
  </div>
</div>
<?php else: ?>
<div class="row">
  <div class="col-md-6">
    <label>Prezio gomendatua:</label>
     <?php print $node->prezio_gomendatua ?>
  </div>
  <div class="col-md-6">
    <label>Razio kopuru gomendatua:</label> <?php print $node->razio_gomendatua ?>
  </div>
</div>
<div class="row">
  <div class="col-md-6 <?php print $node->field_produktua_prezioa['und'][0]['value'] > $node->prezio_gomendatua ? 'alert-success': 'alert-error'?>">
    <label>Prezioa:</label>
     <?php print $node->field_produktua_prezioa['und'][0]['value'] ?>
  </div>
  <div class="col-md-6 <?php print $node->field_errezeta_porzio_kopurua['und'][0]['value'] > $node->razio_gomendatua ? 'alert-success': 'alert-error'?>">
    <label>Razio kopuru:</label> <?php print $node->field_errezeta_porzio_kopurua['und'][0]['value'] ?>
  </div>
  
</div>
<?php endif; ?>