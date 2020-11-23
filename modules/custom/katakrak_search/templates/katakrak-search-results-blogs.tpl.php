<?php
/* 
 * Recogemos todos los resultados de la búsqueda y mostramos la vista cardbook. 
 * No es la solución mas elegante, pero funciona
 */

foreach ($results as $result) {
    $nodes[] = node_load($result['node']->entity_id);
  }
?>

 <div class="table-responsive">
  <table class="table table-sm mt-2">
    <thead>
      <tr>
        <th><?php print t('Artículo') ?></th>
        <th><?php print t('Fecha') ?></th>
      </tr>
    </thead>
    <tbody>
      <?php  foreach($nodes as $i => $node): ?>
        <tr>
          <td>
              <p class="mb-0"><?php print l($node->title, 'node/'.$node->nid) ?></p>
              <span class="text-gray"><?php print $results[$i]['snippet'] ?></span>
            </p>
          </td>
          <td><?php print format_date($node->created) ?></td>
        </tr>
      <?php  endforeach; ?>
    </tbody>
  </table>
  <?php print theme('pager') ?>