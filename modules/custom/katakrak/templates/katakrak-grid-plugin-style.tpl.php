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
  <div class="row <?php print $row_class?>">
    <?php foreach ($rows as $row): ?>
      <div class="col col-lg-2 col-md-3 col-sm-6 ">
        <?php print $row ?>
      </div>
    <?php endforeach ?>
  </div>
</div>
