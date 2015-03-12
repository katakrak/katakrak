<?php include 'page-header.inc' ?>
<div id="content" class="agenda-page">
    <?php if ($title): ?>
      <div id="page-title">
        <div class="container clearfix">
          <div class="page-title">
          <h1><?php print t($section_title); ?></h1>
          </div>
        </div>
      </div>

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
        $content_rows = "col-md-12";
        $sidebar_class = 'sidebar-column';
        if ($page['sidebar_first']) {
          $content_class = 'postcontent col_last';
        }
        if ($page['sidebar_second']) {
          $sidebar_class = 'col_last';
          $sidebar_rows = "col-md-3";
          $content_rows = "col-md-9";
        }
        ?>
        <!-- content region -->
        <div class="row <?php print $content_class; ?> nobottommargin clearfix">
          
          <?php if ($breadcrumb): ?>
            <div id="breadcrumb"><?php //print $breadcrumb; ?></div>
          <?php endif; ?>

          <?php if ($messages): ?>
            <?php print $messages; ?>
          <?php endif; ?>

          <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
          <?php if ($page['content_top']): ?>
            <div id="content-top">
              <div class="row">
              <div class="col-lg-offset-2 col-sm-8 col-md-8">
                <?php print render($page['content_top']); ?>
              </div>
            </div></div>
          <?php endif; ?>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>

          <?php if ($tabs): ?>
            <div class="tabs"><?php print render($tabs); ?></div>
          <?php endif; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>

          <div class="<?php print $content_rows?>">
            <?php print render($page['content']); ?>
            <?php print $feed_icons; ?>
          </div>
          <?php if ($page['sidebar_second']): ?>
        <div class="<?php print $sidebar_rows?>">
          <!-- sidebar right --> 
          <div id="sidebar-second" class="sidebar <?php print $sidebar_class; ?> nobottommargin clearfix">
            <?php print render($page['sidebar_second']); ?>
          </div>
          </div>
          <!-- // sidebar right -->
          
      <?php endif; ?>
        </div>
        <!-- // content region -->

        



    </div>
  </div>

</div>
<?php include 'page-footer.inc' ?>