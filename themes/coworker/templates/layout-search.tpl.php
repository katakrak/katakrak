<?php include 'page-header.inc' ?>

<?php print render($page['content']); ?>         
 <?php if ($messages): ?>
  <?php print $messages; ?>
<?php endif; ?>
<?php include 'page-footer.inc' ?>