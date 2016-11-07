<div class="kantina-menu">
    <h1 class=""><?php print t("Menú") ?></h1>  
  <div class="eguneko-menua">
      <?php if ($node->field_menu_gosariak['und'][0]['value']): ?>
        <div class="subseccion">
          <?php print theme('image', array('path' => drupal_get_path('theme', 'coworker'). '/images/kantina/desayunos.png')) ?>
          <h4>desayunos</h4>
        </div>
        <?php print $node->field_menu_gosariak['und'][0]['value'] ?>
      <?php endif; ?>
      <div class="dedia_divider"></div>
      
      
      <a id="menu_dia"></a>
      <div class="subseccion">
        <?php print theme('image', array('path' => drupal_get_path('theme', 'coworker'). '/images/kantina/menu_mediodia.png')) ?>
        <h4><?php print t('menú de mediodía') ?>*</h4>
        <p><?php print t("De lunes a viernes") ?></p>
      </div>

      <div class="row">
        <div class="col-md-3 col-md-offset-3">
          <h3><?php print t("Ensaladas") ?></h3>
          <?php foreach ($node->field_menu_hotzak['und'] as $key => $value): ?>
            <p><?php print $value['value'] ?></p>
          <?php endforeach; ?>
        </div>
        <div class="col-md-3">
          <h3><?php print t("Cuencos") ?></h3>
          <?php foreach ($node->field_menu_beroak['und'] as $key => $value): ?>
            <p><?php print $value['value'] ?></p>
          <?php endforeach; ?>
        </div>
      </div>
          
      <div class="row">
        <div class="col-md-2 col-md-offset-5">
          <h3><?php print t("Postres") ?></h3>
          <?php foreach ($node->field_menu_azkenburukoak['und'] as $key => $value): ?>
            <p><?php print $value['value'] ?></p>
          <?php endforeach; ?>
        </div>
      </div>
      
      -----------------------------------------------------------------------------------
      <p><?php print $node->field_menu_oharrak['und'][0]['value']?></p>
    </div>
    
    <div class="eguneko-menua">
            <div class="dedia_divider"></div>

      <a id="menu_sabado"></a>
      <div class="subseccion">
        <?php print theme('image', array('path' => drupal_get_path('theme', 'coworker'). '/images/kantina/dedia.png')) ?>
        <h4><?php print t('menú de sábado') ?>*</h4>
        
      </div>

      <div class="row">
        <div class="col-md-3 col-md-offset-3">
          <h3><?php print t("Entrantes") ?></h3>
            <p><?php print t("Frito de hongos") ?></p>
	    <p><?php print t("Pastel de verduras") ?></p>
	    <p><?php print t("Brandada de bacalao") ?></p>
	    <p><?php print t("Ensalada verde") ?></p>
        </div>
        <div class="col-md-3">
          <h3><?php print t("Segundos") ?></h3>
            <p><?php print t("Rissoto de calabaza y champis") ?></p>
	    <p><?php print t("Carrilleras de cerdo al estilo vietnamita") ?></p>
	    <p><?php print t("Alubias negras con piparras") ?></p>
	    <p><?php print t("Lubina al horno") ?></p>
        </div>
      </div>
          
      <div class="row">
        <div class="col-md-2 col-md-offset-5">
          <h3><?php print t("Postres") ?></h3>
          <p><?php print t("Pastel vasco") ?></p>
	  <p><?php print t("Intxaursaltsa") ?></p>
	  <p><?php print t("Cuajada de chocolate") ?></p>
	  <p><?php print t("Fruta con jarabe de hierbabuena") ?></p>
        </div>
      </div>
      
      -----------------------------------------------------------------------------------
      <p><strong><?php print t("+pan y bebida. 20€") ?></strong></p>
      -----------------------------------------------------------------------------------
    </div>
    
  <div class="gaueko-menua">
    
    <div class="denoche_divider"></div>
    <div class="subseccion">
      <?php print theme('image', array('path' => drupal_get_path('theme', 'coworker'). '/images/kantina/hamburgesas.png')) ?>
      <h4><?php print t('Menú de cenas') ?></h4>
    </div>
     <div class="row">
      <div class="col-md-4 col-md-offset-2">
        <h3><?php print t("Ensaladas") ?></h3>
          <p><?php print t("Ensalada de pasta vegana")?></p>
          <p><?php print t("Taboulé")?></p>
          <p><?php print t("Ensalada del momento")?></p>
      </div>
        <div class="col-md-4">
          <h3><?php print t("Bocatas") ?></h3>
          <p><?php print t("#BlackLivesMatter")?></p>
          <p><?php print t("Txerri Harresia")?></p>
          <p><?php print t("Atlantiko beltza")?></p>
          <p><?php print t("Bocata del momento")?></p>
        </div>
      
     </div>
    <div class="row">
      <div class="col-md-4 col-md-offset-2">
        <h3><?php print t("Burguers") ?></h3>
        <p><?php print t("Kontuz burguer")?></p>
        <p><?php print t("Majaris")?></p>
        <p><?php print t("Refugees welcome")?></p>
        <p><?php print t("Vegetal")?></p>
      </div>  
      <div class="col-md-4">
          <h3><?php print t("Raciones") ?></h3>
          <p><?php print t("Falafel")?></p>
          <p><?php print t("Nachos con chilorio y queso")?></p>
          <p><?php print t("Fish and Chips")?></p>
          <p><?php print t("Quesos del baztán")?></p>
          <p><?php print t("Jamón basatxerri")?></p>
          <p><?php print t("Fritos")?></p>
        </div>
    </div>
    <div class="row">
        <div class="col-md-4 col-md-offset-4">
          <h3><?php print t("Postres") ?></h3>
          <p><?php print t("Coulant")?></p>
          <p><?php print t("Pastel vasco")?></p>
          <p><?php print t("Fruta de temporada con jarabe de hierbabuena")?></p>
        </div>
    </div>
  </div>
</div>