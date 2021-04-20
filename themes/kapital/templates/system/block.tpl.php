<?php if ($block->subject): ?>
  <h2<?php print $title_attributes; ?>><?php print t($block->subject) ?></h2>
<?php endif;?>
  
<?php print $content ?>