<?php global $language ?>

<div class="entry_date">
  <?php if ($language->language == 'eu'): ?>
    <div class="month"><?php print format_date($time, 'custom', 'F'); ?></div>
  <?php endif; ?>
    
  <div class="day"><?php print format_date($time, 'custom', 'd'); ?></div>
  
  <?php if ($language->language == 'es'): ?>
    <div class="month"><?php print format_date($time, 'custom', 'F'); ?></div>
  <?php endif; ?>
    
  <div class="hour"><?php print format_date($time, 'custom', 'G:i'); ?></div>
</div>
