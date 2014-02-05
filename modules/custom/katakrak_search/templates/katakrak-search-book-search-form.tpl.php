<div class="book-page-search-form">
  <div class="row-fluid">
    <div class="span8">
      <?php print drupal_render($form['search_term']) ?>
    </div>
    <div class="span4">
       <?php print drupal_render($form['submit']) ?>
    </div>
  </div>
  <?php print drupal_render_children($form) ?> 
</div>