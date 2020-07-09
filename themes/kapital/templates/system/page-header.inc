<nav class="navbar-secondary">
  <ul class="list-inline mb-0">
    <li class="list-inline-item">
      <a href="mailto:info@katakrak.net" target="_blank"> <i class="far fa-envelope " aria-hidden="true"></i> <span class="hidden-xs">info@katakrak.net</span></a>
    </li>
    <li class="list-inline-item">
      <a href="tel:+34948225520" target="_blank"><i class="fas fa-phone" aria-hidden="true"></i> <span class="hidden-xs">948 225 520</span></a> 
    </li>
    <li class="list-inline-item">
      <?php print $donde_estamos ?> 
    </li>
    <li class="list-inline-item hidden-xs">
      <div class="dropdown ">
        <?php print $current_language_link ?>

        <div class="dropdown-menu" aria-labelledby="dropdownIdioma">
          <?php print $language_switch_link ?>
        </div>
      </div>
    </li>
  </ul>
</nav>


<nav class="navbar navbar-default navbar-custom">
  <div class="container-fluid">
    <div class="navbar-header">
      <button type="button" class="btn btn-transparent navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
        <i class="fas fa-bars" aria-hidden="true"></i>
      </button>
      <a class="navbar-brand" href="<?php print url('<front>') ?>">
        <img src="/<?php print $logo_small ?>" alt="<?php print $site_name ?>" class="logo-main visible-xs-block">
        <img src="/<?php print $logo_medium ?>" alt="<?php print $site_name ?>" class="logo-main visible-sm">
        <img src="/<?php print $logo_large ?>" alt="<?php print $site_name ?>" class="logo-main visible-md visible-lg">
      </a>
    </div>

    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
      <ul class="navbar-nav navbar-centered">
        <?php foreach ($main_menu as $menu_item): ?>
          <li class="nav-item">
            <?php print l($menu_item['title'], $menu_item['href'], array('attributes' => array('class' => array('nav-link')))) ?>
          </li>
        <?php endforeach; ?>
        <li role="separator" class="divider visible-xs-block"></li>
        <li class="nav-item visible-xs-block">
          <a class="nav-link" href="<?php print $href_cas?>">Castellano</a> 
        </li>
        <li class="nav-item visible-xs-block">
          <a class="nav-link" href="<?php print $href_eus?>">Euskera</a> 
        </li>
      </ul>
    </div><!-- /.navbar-collapse -->

    <div class="navbar-xs-items d-flex">
      <a class="btn btn-transparent" href="<?php print $user_url ?>">
        <i class="fas fa-user-circle" aria-hidden="true"></i> <span class="hidden-xs"><?php print t('Mi cuenta') ?></span>
      </a>
      <?php print render($page['header_right']) ?>
      
    
    </div>
  </div><!-- /.container-fluid -->
</nav>