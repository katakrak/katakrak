<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
  
<div class="row mt-1 row-posts">
  <?php foreach ($view->result as $row): ?>
    
    <div class="col-md-4 col-sm-6 mb-2 col-post">
        <div class="post">
            <div class="post-image"><?php print drupal_render($row->field_field_image[0]['rendered']) ?></div>
        </div>
      <h3 class="post-title">
        <?php print l($row->node_title, "node/".$row->nid)?>
      </h3>
      <p class="small">Jueves 28 de mayo</p>
    </div>
  <?php endforeach; ?>
</div>