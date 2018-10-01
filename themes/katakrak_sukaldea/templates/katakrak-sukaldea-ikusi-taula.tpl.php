<div class="errezeta-taula">
  <?php print theme('table', $node->produktu_taula) ?>
</div>
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