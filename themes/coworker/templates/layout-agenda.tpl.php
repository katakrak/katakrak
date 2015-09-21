<?php include 'page-header.inc' ?>
<div class="container-fluid banda-agenda">
  <div class="banda_header"></div>
</div>
<div id="content" class="agenda-page">
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
        $content_rows = "col-md-12 col-lg-12 col-sd-12";
        if ($page['sidebar_second']) {
          $sidebar_rows = "col-lg-3 col-md-3 col-sm-2";
          $content_rows = "col-lg-9 col-md-9 col-sm-10";
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
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>

          <?php if ($tabs): ?>
            <div class="tabs"><?php print render($tabs); ?></div>
          <?php endif; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>

          
          <div class="row">
            <div class="col-lg-12">
              <?php print render($page['content_top']); ?>
            </div>
          </div>
          
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