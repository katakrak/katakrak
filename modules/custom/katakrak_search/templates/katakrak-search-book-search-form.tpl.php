<div class="book-page-search-form">
  <div class="row-fluid">
    <div class="span10">
      <?php print drupal_render($form['search_term']) ?>
    </div>
    <div class="span2">
       <?php print drupal_render($form['submit']) ?>
    </div>
  </div>
  <?php print drupal_render_children($form) ?> 
</div>