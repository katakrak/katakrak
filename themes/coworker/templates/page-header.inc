<?php print render($page['menu_lateral']) ?>
<header id="header" class="clearfix">
<nav class="navbar navbar-default">
  <div class="container">
    <!-- Brand and toggle get grouped for better mobile display -->
    <div class="navbar-header">
      <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#kata-mobile-menu">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
       <div id="logo">
           <?php if ($logo): ?>
              <a href="<?php print $front_page; ?>" class="standard-logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" title="<?php print t('Home'); ?>" /></a>
              <?php endif; ?>
              <?php if ($site_name || $site_slogan): ?>
                <div id="name-and-slogan">
                  <?php if ($site_name): ?>
                    <h1 id="site-name">
                      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
                    </h1>
                  <?php endif; ?>
                  <?php if ($site_slogan): ?>
                    <div id="site-slogan"><?php print $site_slogan; ?></div>
                  <?php endif; ?>
                </div> <!-- /#name-and-slogan -->
              <?php endif; ?>
            </div>
    </div>

    <!-- Collect the nav links, forms, and other content for toggling -->
    <div  id="kata-main-menu" class="hidden-xs">
      <a href="<?php print $front_page; ?>" class="logo-txiki"><img src="/sites/all/themes/coworker/images/logo-txiki.png"></a>
      <div id="primary-links">
        <div id="main-menu" class="hidden-xs">
          <?php print $navigation ?>
        </div>
      </div>  
      <?php print render($page['top_right']); ?>
    </div><!-- /.navbar-collapse -->
    <div class="hidden-lg hidden-md hidden-sm" id="primary-links">
      <div id="kata-mobile-menu" class="collapse navbar-collapse" >
        <?php print $navigation ?>
      </div>  
    </div>
  </div><!-- /.container-fluid -->
  <div class="container-fluid">
  <div class="banda_header"></div>
</div>
</nav>
</header>  

