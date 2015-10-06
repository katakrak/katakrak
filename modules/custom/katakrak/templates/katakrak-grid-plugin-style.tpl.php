<?php
/**
 * @file views-bootstrap-grid-plugin-style.tpl.php
 * Default simple view template to display Bootstrap Grids.
 *
 *
 * - $columns contains rows grouped by columns.
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 * - $column_type contains a number (default Bootstrap grid system column type).
 *
 * @ingroup views_templates
 */
?>

<div id="views-bootstrap-grid-<?php print $id ?>" class="<?php print $classes ?>">
  <?php if ($options['alignment'] == 'horizontal'): ?>

  <div class="row">
    <?php foreach ($rows as $row): ?>
      <div class="col col-lg-<?php print $columns_lg ?> col-md-<?php print $columns_md ?> col-sm-<?php print $columns_sm ?> col-xs-<?php print $columns_xs ?>">
        <?php print $row ?>
      </div>
    <?php endforeach ?>
    </div>

  <?php else: ?>
    <?php foreach(array('lg', 'md', 'sm', 'xs') as $size): ?>
    <div class="row visible-<?php print $size ?>">
      <?php $items = 'items_'.$size; ?>
      <?php foreach (${$items} as $column): ?>
        <div class="col col-<?php print $size?>-<?php print 12/count(${$items}) ?>">
          <?php foreach ($column['content'] as $row): ?>
            <?php print $row['content'] ?>
          <?php endforeach ?>
        </div>
      <?php endforeach ?>
    </div>
  <?php endforeach; ?>

  <?php endif ?>
</div>
