<?php
/* 
 * Recogemos todos los resultados de la búsqueda y mostramos la vista cardbook. 
 * No es la solución mas elegante, pero funciona
 */
dpm($results);
foreach ($results as $result) {
    $nids[] = node_load($result['node']->entity_id);
  }
?>

  
<div class="row mt-1 row-posts">
 <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
<?php endforeach; ?>
</div>