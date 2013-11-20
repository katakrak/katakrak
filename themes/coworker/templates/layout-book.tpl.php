<div id="wrapper" class="clearfix">
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
  <div id="content">

    <?php if (!drupal_is_front_page()): ?>
      <?php if ($title): ?>
        <div id="page-title">
          <div class="container clearfix">

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

    <div class="content-wrap">
      <div class="container-fluid clearfix">

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

          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>

            <?php if ($page['sidebar_first']): ?>
            <!-- sidebar left -->
            <div id="sidebar-first">
              <?php print render($page['sidebar_first']); ?>
            </div>
            <!-- // sidebar left -->
            <?php endif; ?>
              <?php print render($page['content']); ?>
          <?php print $feed_icons; ?>
        </div>
        <!-- // content region -->

      </div>
    </div>

  </div>
</div>

