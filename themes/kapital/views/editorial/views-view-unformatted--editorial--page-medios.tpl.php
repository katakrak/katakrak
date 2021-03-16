<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<h1 class="text-center"><?php print t('En los medios') ?></h1>
<p class="text-center"><?php print t('Todas las referencias en la prensa a nuestros libros') ?></p>
<div class="row mt-3 row-posts">
 <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
<?php endforeach; ?>
</div>