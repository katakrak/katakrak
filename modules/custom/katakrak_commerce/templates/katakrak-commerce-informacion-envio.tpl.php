<ul>
  <?php foreach($shipping_methods as $method): ?>
    <li><strong><?php print t($method->data['shipping_service']['display_title'])?></strong>: <?php print t($method->data['shipping_service']['description'])?></li>
  <?php endforeach; ?>
</ul>