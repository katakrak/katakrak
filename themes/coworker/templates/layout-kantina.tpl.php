<?php 
  if ($page['sidebar_left']) {
   $content_classes = 'col-md-9 col-lg-9 col-sm-12 col-xs-12'; 
  }
  else {
    $content_classes = 'col-md-12 col-lg-12 col-sm-12 col-xs-12';
  }
?>
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
            <div class="<?php print $content_classes ?>">
              <?php print render($page['content']); ?>
            </div>
            <?php if ($page['sidebar_left']): ?>
            <div class="col-md-3 col-lg-3 col-sm-12 col-xs-12">
              <?php print render($page['sidebar_left']) ?>
            </div>
            <?php endif; ?>
          </div>  
          
          <?php print render($page['content_bottom']) ?>
        
          <?php if ($page['bottom_one'] || $page['bottom_two'] || $page['bottom_three'] || $page['bottom_four']): ?>
            <div id="content-bottom" class="row">
              <div class="col-lg-3 col-md-3 col-sm-3">
                <?php print render($page['bottom_one']); ?>
              </div>
              <div class="col-lg-3 col-md-3 col-sm-3">
                <?php print render($page['bottom_two']); ?>
              </div>
              <div class="col-lg-3 col-md-3 col-sm-3">
                <?php print render($page['bottom_three']); ?>
              </div>
              <div class="col-lg-3 col-md-3 col-sm-3">
                <?php print render($page['bottom_four']); ?>
              </div>
            </div>
          <?php endif; ?>
          <?php print $feed_icons; ?>
        </div>
        <!-- // content region -->

    </div>
  </div>

</div>
<?php include 'page-footer.inc' ?>