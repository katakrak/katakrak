<div class="row">
  <div class="col col-md-4 col-sm-4 col-xs-12">
    <div class="views-field-field-image">
      <a href="<?php print url('cantina')?>"></a>
      <?php print theme('image_style', array('path' => 'public://katakrak_home/kantina.jpg', 'style_name' => 'home_promo')) ?>
      <div class="portfolio_shader"></div>
      <div class="name"><h2><?php print t('Cantina') ?></h2></div>
    </div>
  </div>
  <div class="col col-md-4 col-sm-4 col-xs-12">
    <div class="views-field-field-image">
      <a href="<?php print url('libreria')?>"></a>
      <?php print theme('image_style', array('path' => 'public://katakrak_home/libreria_2.jpg', 'style_name' => 'home_promo')) ?>
      <div class="portfolio_shader"></div>
      <div class="name"><h2><?php print t('Librería') ?></h2></div>
    </div>

  </div>
  <div class="col col-md-4 col-sm-4 col-xs-12">
    <div class="views-field-field-image">
      <a href="<?php print url("node/$nid")?>"></a>
      <?php print theme('image_style', array('path' => 'public://katakrak_home/nagusia.jpg', 'style_name' => 'home_promo')) ?>
      <div class="portfolio_shader"></div>
      <div class="name"><h2><?php print t('Sala nagusia') ?></h2></div>
    </div>
  </div>
</div>