<div class="hidden-xs hidden-sm">
  
  <div class="kantina-menu-dia-block">
    <?php print l('<i class="fa fa-10x fa-cutlery"></i><h3>'.t("Menú del día").'</h3>', $menu_dia_path, array('html' => TRUE)); ?>
  </div>
  <div class="kantina-fin-semana-block">
    <?php print l(theme('image', array('path' => drupal_get_path('theme', 'coworker').'/images/burger.png')).'<h3>Fines de semana</h3>', $menu_dia_path, array('html' => TRUE)) ?>
  </div>
</div>

<div class="row hidden-md hidden-lg">
  
    <div class="col-xs-4">
      <?php print l('<i class="fa fa-9x fa-cutlery"></i><h3>'.t("Menú del día").'</h3>', $menu_dia_path, array('html' => TRUE)); ?>
    </div>
    <div class="col-xs-4">
      <?php print l(theme('image', array('path' => drupal_get_path('theme', 'coworker').'/images/burger.png')).'<h3>Fines de semana</h3>', $menu_dia_path, array('html' => TRUE)) ?>
    </div>
    <div class="col-xs-4">
      
    </div>
  
</div>

