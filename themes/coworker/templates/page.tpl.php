<?php include 'page-header.inc' ?>
<div id="content">
  <?php if (!drupal_is_front_page()): ?>
    <?php if ($title): ?>
      <div id="page-title">
        <div class="container clearfix">
          <div class="col-3">
          <h1><?php print $title; ?></h1>
          </div>
        </div>
      </div>

    <?php endif; ?>
  <?php endif; ?>

  <?php if (drupal_is_front_page() && !theme_get_setting('homepage_title', 'coworker')): ?>
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

    <?php if ($page['contact_map']): ?>
      <div id="google-map" class="contact-map">
        <div style="display: block !important;" class="slider-line"></div>
        <?php print render($page['contact_map']); ?>
      </div>
    <?php endif; ?>

    <div class="content-wrap">
      <div class="container clearfix">

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
            <div id="breadcrumb"><?php //print $breadcrumb; ?></div>
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
<?php include 'page-footer.inc' ?>