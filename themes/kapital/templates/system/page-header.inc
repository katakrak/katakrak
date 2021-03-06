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
           
        <?php foreach (element_children($primary_nav) as $menu_id): ?>
         <?php $menu_item = $primary_nav[$menu_id];?>
          <li class="<?php print $menu_item['#below'] ? 'dropdown' : ''; print $menu_item['#original_link']['in_active_trail'] ? ' active': ''  ?> nav-item">
            <?php print l(t($menu_item['#title']), $menu_item['#href'], array('attributes' => array('class' => array('nav-link')))) ?>
          </li>
        <?php endforeach; ?>
        <li role="separator" class="divider visible-xs-block"></li>
        <li class="nav-item visible-xs-block">
          <a class="nav-link" href="<?php print $href_cas?>"><?php print t('Castellano') ?></a> 
        </li>
        <li class="nav-item visible-xs-block">
          <a class="nav-link" href="<?php print $href_eus?>"><?php print t('Euskera') ?></a> 
        </li>
      </ul>
    </div><!-- /.navbar-collapse -->

    <div class="navbar-xs-items d-flex">
      <?php if (!user_is_logged_in()): ?>
        <a class="btn btn-transparent" href="<?php print url('user') ?>">
          <i class="fas fa-user-circle" aria-hidden="true"></i> <span class="hidden-xs"><?php print t('Mi cuenta') ?></span>
        </a>
      <?php else: ?>
      <button class="btn btn-transparent dropdown-toggle" data-toggle="dropdown" aria-expanded-true>
        <i class="fas fa-user-circle " aria-hidden="true"></i> <span class="hidden-xs"><?php print $user_name ?></span>
      </button>
      <ul class="dropdown-menu">
        <li><?php print l(t('Mi cuenta'), 'user') ?></li>
        <li><?php print l(t('Mis pedidos'), "user/$uid/orders") ?></li>
        <li role="separator" class="divider"></li>
        <li><?php print l(t('Cerrar sesión'), 'user/logout') ?></li>
      </ul>
      <?php endif; ?>
      <?php print render($page['header_right']) ?>
      
    
    </div>
  </div><!-- /.container-fluid -->
</nav>