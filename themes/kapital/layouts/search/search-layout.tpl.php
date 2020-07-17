<?php print $content['content_top']; ?>

<div class="row mt-2">
  <div class="col-sm-8 col-sm-offset-2">
    <div class="row mt-2">
      <div class="col-sm-4">
        <?php print $content['facet_left'] ?>
      </div>
      <div class="col-sm-4">
        <?php print $content['facet_middle'] ?>
      </div>
      <div class="col-sm-4">
        <?php print $content['facet_right'] ?>
      </div>
    </div>
  </div>
</div>
<hr>
<div class="d-flex space-between">
  <?php print $content['facetapi_badge'] ?>
  <?php print $content['search_sort'] ?>
</div>

<?php print $content['content'] ?>