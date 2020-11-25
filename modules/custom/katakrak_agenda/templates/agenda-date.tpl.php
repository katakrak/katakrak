<?php global $language ?>
<div class="<?php print $class?>">
  <?php if ($language->language == 'es'): ?>
    <p class="day"><?php print format_date($time, 'custom', 'd'); ?></p>
    <p class="small"><?php print format_date($time, 'custom', 'F'); ?></p>
    <p class="week-day small"><?php print format_date($time, 'custom', 'l'); ?></p>
    <p class="time"><?php print format_date($time, 'custom', 'G:i'); ?></p>
  <?php else: ?>
    <p class="small"><?php print format_date($time, 'custom', 'F'); ?>k</p>
    <p class="day"><?php print format_date($time, 'custom', 'd'); ?></p>
    <p class="week-day small"><?php print format_date($time, 'custom', 'l'); ?></p>
    <p class="time"><?php print format_date($time, 'custom', 'G:i'); ?>etan</p>
  <?php endif; ?>
</div>