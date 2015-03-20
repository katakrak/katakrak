<?php include 'page-header.inc' ?>
<div id="content">
    <div class="content-wrap">
      <div class="container clearfix kantina-page">
        <!-- content region -->
        <div class="<?php print $content_class; ?> nobottommargin clearfix">
          <?php if ($breadcrumb): ?>
            <div id="breadcrumb"><?php //print $breadcrumb; ?></div>
          <?php endif; ?>

          <?php if ($messages): ?>
            <?php print $messages; ?>
          <?php endif; ?>

          <?php if ($page['highlighted']): ?>
            <div id="highlighted"><?php print render($page['highlighted']); ?></div>
          <?php endif; ?>
          <?php if ($page['content_top']): ?>
            <div id="content-top">
              <?php print render($page['content_top']); ?>
            </div>
          <?php endif; ?>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>

          <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
          <div class="row">
            <div class="col-md-offset-1 col-md-10 col-lg-offset-1 col-lg-10 col-sm-offset-1 col-sm-10 col-xs-offset-1 col-xs-10">
              <?php print render($page['content']); ?>
            </div>
          </div>  
          
          <?php print render($page['content_bottom']) ?>
          <?php print $feed_icons; ?>
        </div>
        <!-- // content region -->

    </div>
  </div>

</div>
<?php include 'page-footer.inc' ?>