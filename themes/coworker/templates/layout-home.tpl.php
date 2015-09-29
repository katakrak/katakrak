<?php include 'page-header.inc' ?>
<div class="container-fluid">
  <div class="banda_header"></div>
</div>
<div class="clear"></div>
<div id="content"class="page-home">
    <div class="content-wrap">
      <div class="container clearfix">
        <!-- content region -->
        <div class="nobottommargin clearfix">

          <?php if ($messages): ?>
            <?php print $messages; ?>
          <?php endif; ?> 

          <?php if ($page['content_top']): ?>
            <div id="content-top">
              <?php print render($page['content_top']); ?>
            </div>
          <?php endif; ?>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>

          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>

          <div class="row">
            <div class="col-md-12 col-lg-12 col-xs-12">
              <?php print render($page['content']); ?>
            </div>
          </div>
          
         
          <?php print $feed_icons; ?>
        </div>
      </div>
      
      <div class="container">
        <?php if ($page['content_bottom_first'] || $page['content_bottom_second'] || $page['content_bottom_third'] || $page['content_bottom_fourth']): ?>
        <div id="content-bottom" class="row">
          <div class="col-lg-8 col-md-12 col-sm-12 col-xs-12  col-lg-offset-2">
            <?php print render($page['content_bottom_first']);?>
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