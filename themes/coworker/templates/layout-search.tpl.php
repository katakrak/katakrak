<div id="wrapper" class="clearfix">
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

          <div class="row-fluid">
            <?php if ($page['sidebar_first']): ?>
            <!-- sidebar left -->
            <div id="sidebar-first" class="span4">
              <?php print render($page['sidebar_first']); ?>
            </div>
            <!-- // sidebar left -->
            <?php endif; ?>
            <div class="span8">
              <?php print render($page['content']); ?>
            </div>
          </div>
          <?php print $feed_icons; ?>
        </div>
        <!-- // content region -->

      </div>
    </div>

  </div>
</div>

