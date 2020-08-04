<?php global $language ?>
<div class="date date-title">
  <?php if ($language->language == 'eu'): ?>
    <div class="mb-05"><?php print format_date($time, 'custom', 'F'); ?>k</div>
  <?php endif; ?>
  <p class="day"><?php print format_date($time, 'custom', 'd'); ?></p>
  <?php if ($language->language == 'es'): ?>
    <div class="mb-05"><?php print format_date($time, 'custom', 'F'); ?></div>
  <?php endif; ?>
  <p class="strong"><?php print format_date($time, 'custom', 'G:i'); ?></p>
</div>