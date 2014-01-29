<div id="wrapper" class="clearfix">
  <?php if ($page['top_left'] || $page['top_right'] || $page['top_lang']): ?>
    <div id="top-bar">
      <div class="container clearfix">
        <div class="row-fluid">

          <div id="top-menu" class="span4">
          <?php if ($page['top_left']): ?>
              <?php print render($page['top_left']); ?>

          <?php endif; ?>
            </div>
          <?php if ($page['top_right']): ?>
          <div class="span8">
            <div id="top-social">
              <?php print render($page['top_right']); ?>
              </div>
            </div>
          <?php endif; ?>
          <?php if ($page['top_lang']): ?>
          <div id="top-lang" class="span2">
              <?php print render($page['top_lang']); ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <div id="header">
    <div class="container clearfix">
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
  </div>
   <?php if (!empty($navigation)): ?>
        <div id="primary-menu">
          <?php print $navigation; ?>
        </div>
      <?php endif; ?>