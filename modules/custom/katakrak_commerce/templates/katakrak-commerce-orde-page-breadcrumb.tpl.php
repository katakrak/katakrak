<?php

$steps[] = array('title' => t('Inicial'));
$steps[] = array('title' => t('Procesando'));
$steps[] = array('title' => t('Completado'));

if (katakrak_commerce_cart_is_recogida($commerce_order)) {
  $steps[] = array('title' => t('Listo para recoger'));
}
else 
  $steps[] = array('title' => t('Enviado'));


switch ($commerce_order->status) {
  case 'pending':
    $steps[0]['class//'] = 'is-completed';
    $steps[0]['class'] = 'is-active';
    break;
  case 'processing':
    $steps[0]['class'] = 'is-completed';
    $steps[1]['class'] = 'is-active';
    break;
  case 'completed':
    $steps[0]['class'] = 'is-completed';
    $steps[1]['class'] = 'is-completed';
    $steps[2]['class'] = 'is-completed';
    $steps[3]['class'] = 'is-active';
    break;  
}
?>
<div class="wizard mt-2">
<?php foreach($steps as $i => $step): ?>
  <a class="step <?php print $step['class'] ?>">
    <div class="wizard-dot">
      <div class="wizard-connector <?php print $i == 0 ? 'is-transparent': '' ?>"></div>
      <div class="wizard-number">
        <span><?php print $i+1 ?></span>
      </div><!-- wizard-number -->
      <div class="wizard-connector <?php print  $i+1 == count($steps) ? 'is-transparent': ''?>"></div>
    </div><!-- wizard-dot -->
    <p><?php print $step['title'] ?></p>
  </a><!-- step -->
<?php endforeach; ?>
</div><!-- /.wizard -->