<?php
/* 
 * Recogemos todos los resultados de la búsqueda y mostramos la vista cardbook. 
 * No es la solución mas elegante, pero funciona
 */
foreach ($results as $result) {
    $nids[] = $result['node']->entity_id;
  }
  $nodes = node_load_multiple($nids);
  foreach ($nodes as $node) {
    $node_view = node_view($node, 'card_book_md');
    $output .= drupal_render($node_view);
  }
  print $output;

?>
  <?php print theme('pager') ?>
