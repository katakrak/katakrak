<div class="entry_date">
  <div class="day" style="background-color: <?php print $color?>"><?php print format_date($time, 'custom', 'd'); ?></div>
  <div class="month" style="background-color: <?php print $color?>"><?php print format_date($time, 'custom', 'M'); ?></div>
  <div class="weekday" style="background-color: <?php print $color?>"><?php print format_date($time, 'custom', 'D'); ?></div>
  <div class="hour" style="background-color: <?php print $color?>"><?php print format_date($time, 'custom', 'G:i'); ?></div>
</div>