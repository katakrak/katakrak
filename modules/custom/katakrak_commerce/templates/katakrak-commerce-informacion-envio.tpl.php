<div class="small">
<?php foreach($shipping_methods as $method): ?>
  <?php //dpm($method) ?>
  <div class="tipo-envio text-gray <?php print $method->data['shipping_service']['name'] ?>">
    <h4><?php print t($method->data['shipping_service']['display_title'])?></h4>
    <p><?php print t($method->data['shipping_service']['description'])?></p>
  </div>
  <?php endforeach;?>
</div>