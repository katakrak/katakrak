<?php include 'page-header.inc' ?>
<div class="container">
  <?php if ($messages): ?>
  <?php print $messages; ?>
<?php endif; ?>
<?php print render($page['content']); ?>         
<?php include 'page-footer.inc' ?>
</div>