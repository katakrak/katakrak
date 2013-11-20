
<div id="wrapper" class="clearfix">
  <div id="top-bar">

    <div class="container clearfix">

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
      <div id="logo">
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" class="standard-logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" title="<?php print t('Home'); ?>" /></a>
          <?php
          $rentina_logo = theme_get_setting('rentina_logo', 'coworker');
          if (!empty($rentina_logo)) {
            ?>
            <a href="<?php print $front_page; ?>" class="retina-logo"><img src="<?php print $rentina_logo; ?>" /></a>
          <?php } ?>
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



      <?php if (!empty($navigation)): ?>
        <div id="primary-menu">
          <?php print $navigation; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>

  <?php if (!empty($page['slider'])): ?>
    <div id="slider">
      <?php print render($page['slider']); ?>
    </div>
  <?php endif; ?>



  <div id="content">

    <?php if (FALSE && !drupal_is_front_page()): ?>
      <?php if ($title): ?>
        <div id="page-title">
          <div class="clearfix">

            <h1><?php print $title; ?></h1>

            <?php if (!empty($search_block)): ?>
              <div id="top-search">
                <?php print $search_block; ?>
              </div>
            <?php endif; ?>

          </div>
        </div>

      <?php endif; ?>
    <?php endif; ?>

    <?php if (FALSE && drupal_is_front_page() && !theme_get_setting('homepage_title', 'coworker')): ?>
      <?php if ($title): ?>
        <div id="page-title">
          <div class="clearfix">

            <h1><?php print $title; ?></h1>

            <?php if (!empty($search_block)): ?>
              <div id="top-search">
                <?php print $search_block; ?>
              </div>
            <?php endif; ?>

          </div>
        </div>

      <?php endif; ?>
    <?php endif; ?>

    <?php if ($page['contact_map']): ?>
      <div id="google-map" class="contact-map">
        <div style="display: block !important;" class="slider-line"></div>
        <?php print render($page['contact_map']); ?>
      </div>
    <?php endif; ?>

    <div class="content-wrap">
      <div class="clearfix">

        <?php
        $content_class = 'content-main-column';
        $sidebar_class = 'sidebar-column';
        if ($page['sidebar_first']) {
          $content_class = 'postcontent col_last';
        }
        if ($page['sidebar_second']) {
          $sidebar_class = 'col_last';
          $content_class = 'postcontent';
        }
        ?>
        <!-- content region -->
        <div class="<?php print $content_class; ?> nobottommargin clearfix">
          <?php if ($breadcrumb): ?>
            <div id="breadcrumb"><?php print $breadcrumb; ?></div>
          <?php endif; ?>

          <?php if ($messages): ?>
            <?php print $messages; ?>
          <?php endif; ?>

          <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>

          <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>

          <?php print render($page['content']); ?>
          <?php print $feed_icons; ?>
        </div>
        <!-- // content region -->

        <?php if ($page['sidebar_first']): ?>
          <!-- sidebar left -->
          <div id="sidebar-first" class="sidebar nobottommargin clearfix">
            <?php print render($page['sidebar_first']); ?>
          </div>
          <!-- // sidebar left -->
        <?php endif; ?>

        <?php if ($page['sidebar_second']): ?>
          <!-- sidebar right --> 
          <div id="sidebar-second" class="sidebar <?php print $sidebar_class; ?> nobottommargin clearfix">
            <?php print render($page['sidebar_second']); ?>
          </div>
          <!-- // sidebar right -->
        <?php endif; ?>



      </div>
    </div>

  </div>


  <?php $footer_style = theme_get_setting('footer_style', 'coworker'); ?>
  <?php if ($page['footer_first'] || $page['footer_second'] || $page['footer_third'] || $page['footer_fourth']): ?>

    <div id="footer" class="footer-<?php print $footer_style; ?>">


      <div class="container clearfix">


        <div class="footer-widgets-wrap clearfix">


          <?php if ($page['footer_first']): ?>
            <div class="col_one_fourth">
              <?php print render($page['footer_first']); ?>
            </div>
          <?php endif; ?>


          <?php if ($page['footer_second']): ?>
            <div class="col_one_fourth">
              <?php print render($page['footer_second']); ?>
            </div>
          <?php endif; ?>



          <?php if ($page['footer_third']): ?>
            <div class="col_one_fourth">
              <?php print render($page['footer_third']); ?>
            </div>
          <?php endif; ?>



          <?php if ($page['footer_fourth']): ?>
            <div class="col_one_fourth">
              <?php print render($page['footer_fourth']); ?>
            </div>
          <?php endif; ?>

        </div>


      </div>


    </div>
  <?php endif; ?>

  <div class="clear"></div>


  <?php if ($page['footer']): ?>

    <div id="copyrights" class="copyrights-<?php print $footer_style; ?>">

      <div class="container clearfix">
        <?php print render($page['footer']); ?>
      </div>
    </div>
  <?php endif; ?>


</div>
<div id="gotoTop" class="icon-angle-up"></div>
