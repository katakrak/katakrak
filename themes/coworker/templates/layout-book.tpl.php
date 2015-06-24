<?php 
  if ($page['sidebar_second']) {
   $content_classes = 'col-md-9 col-lg-9 col-sm-12 col-xs-12'; 
  }
  else {
    $content_classes = 'col-md-12 col-lg-12 col-sm-12 col-xs-12';
  }
?>
<?php include 'page-header.inc' ?>
<div class="container-fluid banda-libreria">
<div class="banda_header"></div>
  <div class="container">
    <?php if ($page['content_top']): ?>
      <div id="content-top">
        <?php print render($page['content_top']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>

<div id="content" class="book-page">
    <div class="content-wrap">
      <div class="container clearfix">
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
          
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>
          
          <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
          <div class="row">
            <div class="<?php print $content_classes ?>">
              <?php print render($page['content']); ?>
            </div>
            <?php if ($page['sidebar_second']): ?>
            <div class="col-md-3 col-lg-3 col-sm-12 col-xs-12">
              <?php print render($page['sidebar_second']) ?>
            </div>
            <?php endif; ?>
          </div>  
          
          <?php print render($page['content_bottom']) ?>
        
          <?php if ($page['content_bottom_first'] || $page['content_bottom_second'] || $page['content_bottom_third'] || $page['content_bottom_fourth']): ?>
        <div id="content-bottom" class="row">
          <div class="col-lg-3 col-md-3 col-sm-3">
            <?php print render($page['content_bottom_first']); ?>
          </div>
          <div class="col-lg-3 col-md-3 col-sm-3">
            <?php print render($page['content_bottom_second']); ?>
          </div>
          <div class="col-lg-3 col-md-3 col-sm-3">
            <?php print render($page['content_bottom_third']); ?>
          </div>
          <div class="col-lg-3 col-md-3 col-sm-3">
            <?php print render($page['content_bottom_fourth']); ?>
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