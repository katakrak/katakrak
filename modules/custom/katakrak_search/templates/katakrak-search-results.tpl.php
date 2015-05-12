<?php
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<?php foreach($rows as $row): ?>
  <div class="row">
    <?php foreach($row as $libro): ?>
    <div class="col-lg-4 col-md-4">
      <div><?php print $libro['image'] ?></div>
      <h3><?php print $libro['title'] ?></h3>
    </div>
    <?php endforeach; ?>
  </div>
<?php endforeach; ?>


