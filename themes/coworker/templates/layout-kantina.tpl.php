<?php include 'page-header.inc' ?>
<div id="content">
  <?php if (!drupal_is_front_page()): ?>
    <?php if ($title): ?>
      <div id="page-title">
        <div class="container clearfix">
          <div class="page-title">
            <h1><?php print $title; ?></h1>
          </div>
        </div>
      </div>

    <?php endif; ?>
  <?php endif; ?>

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
            <div class="col-lg-10">
              <?php print render($page['content']); ?>
            </div>
            <div class="col-lg-2">
              <?php if ($page['sidebar_second']): ?>
                  <?php print render($page['sidebar_second']); ?>
                <!-- // sidebar right -->
              <?php endif; ?>
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