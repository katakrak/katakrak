<div id="wrapper" class="clearfix">
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
  <div id="header">
    <div class="container clearfix">
      <div class="row">
        <div class="col-md-4">
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
        <div class="col-md-6">
          <?php if (!empty($navigation)): ?>
            <div id="primary-links">
              <?php print $navigation; ?>
            </div>
          <?php endif; ?>
        </div>
        <div class="col-md-2">
          <div id="top-right">
            <?php print render($page['header_right']); ?>
          </div>
        </div>
      </div>
  
    </div>
  </div>
</div>
<div class="container-banda">
  <div class="banda-header"></div>
</div>  
<?php if (!empty($page['slider'])): ?>
  <div id="slider" class="visible-desktop visible-tablet">
    <?php print render($page['slider']); ?>
  </div>
<?php endif; ?>
  