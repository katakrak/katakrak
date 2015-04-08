
<div id="header" class="clearfix ">
  <?php if ($page['top_left'] || $page['top_right']): ?>
  <div id="top-bar">

    <div class="clearfix">

      <?php if ($page['top_left']): ?>
        <div id="top-menu">

          <?php print render($page['top_left']); ?>

        </div>
      <?php endif; ?>


      <?php if ($page['top_right']): ?>
        <div id="top-social">

          <?php print render($page['top_right']); ?>
        </div>
      <?php endif; ?>

    </div>
  </div>
<?php endif; ?>
<nav class="navbar navbar-default">
  <div class="container">
    <!-- Brand and toggle get grouped for better mobile display -->
    <div class="navbar-header">
      <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#kata-main-menu">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
       <div id="logo">
           <?php if ($logo): ?>
              <a href="<?php print $front_page; ?>" class="standard-logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" title="<?php print t('Home'); ?>" /></a>
                <?php if ($rentina_logo): ?>
                  <a href="<?php print $front_page; ?>" class="retina-logo"><img src="<?php print $rentina_logo; ?>" /></a>
                <?php endif; ?>
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
    <div class="collapse navbar-collapse" id="kata-main-menu">
      <div id="primary-links">
        <div id="main-menu" class="hidden-xs">
          <?php print $navigation ?>
        </div>
        <div class="hidden-lg hidden-md hidden-sm" >
          <?php print $navigation ?>
        </div>  
      </div>
      <?php print render($search_form) ?>
    </div><!-- /.navbar-collapse -->
  </div><!-- /.container-fluid -->
</nav>
</div>
<div class="container-fluid">
  <div class="banda_header"></div>
</div>  
  