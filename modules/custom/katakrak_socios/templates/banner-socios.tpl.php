<?php 
global $language;

$links = language_negotiation_get_switch_links('language', drupal_get_normal_path('hazte-socix', 'es'));

$path = $links->links[$language->language]['href'];

?>  
<div class="panel-content">
      <br /><br />
      <?php print l(theme('image', array('path' => 'sites/all/themes/coworker/images/bansocix.gif')), $path, array('html' => true)) ?>
  </div>