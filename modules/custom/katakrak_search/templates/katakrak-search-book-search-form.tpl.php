<div class="book-page-search-form">
  <div class="row-fluid">
    <div class="span10">
      <?php print drupal_render($form[$term_element]) ?>
    </div>
    <div class="span2">
       <?php print drupal_render($form[$submit_element]) ?>
    </div>
  </div>
  <?php print drupal_render_children($form) ?> 
</div>