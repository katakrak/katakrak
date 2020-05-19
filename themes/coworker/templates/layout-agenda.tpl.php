<?php include 'page-header.inc' ?>
<div id="content" class="agenda-page">

    
    <div class="content-wrap">
      <div class="container clearfix">
<div class="row">
            <div class="col-lg-12">
              <?php print render($page['content_top']); ?>
            </div>
          </div>
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
         <?php print render($page['content_bottom']) ?>
        <?php if ($page['content_bottom_first'] || $page['content_bottom_second'] || $page['content_bottom_third'] || $page['content_bottom_fourth']): ?>
        <div id="content-bottom" class="row">
          <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
            <?php print render($page['content_bottom_first']); ?>
          </div>
          <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
            <?php print render($page['content_bottom_second']); ?>
          </div>
          <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
            <?php print render($page['content_bottom_third']); ?>
          </div>
          <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
            <?php print render($page['content_bottom_fourth']); ?>
          </div>
        </div>
        <?php endif; ?>
    </div>
  </div>

</div>
<?php include 'page-footer.inc' ?>