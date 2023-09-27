<?php if ($items): ?>
  <div class="field-items">
    <?php foreach ($items as $delta => $item): ?>
      <?php $class = $element['#object']->field_image_class['und'][0]['value']; ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>">
        <img src="<?php print file_create_url($item['#item']['uri']); ?>" class="<?php print $class; ?>">
      </div>
    <?php endforeach; ?>
  </div>
<?php endif; ?>