<?php if (empty($content['right'])) {$left_col_num = 12;} else {$left_col_num = 9;}?>

  <div class="row">
    <div class="col-md-12">
      <?php print $content['header'] ?>
    </div>
  </div>
  <div class="row">
    <div class="col-md-<?php print $left_col_num ?>">
      <?php print $content['left'] ?>
     </div>
    <?php if ($content['right']): ?>
      <div class="col-md-3">
        <?php print $content['right'] ?>
      </div>
    <?php endif; ?>
  </div>