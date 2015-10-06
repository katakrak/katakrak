<?php include 'page-header.inc' ?>
<div class="container-fluid">
  <div class="container">
    <?php if ($section_title): ?>
      <h2><?php print $section_title ?></h2>
    <?php endif; ?>
    <?php if ($page['content_top']): ?>
      <div id="content-top">
        <?php print render($page['content_top']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>
<div id="content">

  <?php if (drupal_is_front_page() && !theme_get_setting('homepage_title', 'coworker')): ?>
    <?php if ($title): ?>
      <div id="page-title">
        <div class="container clearfix">
          <div class="col-3">
            <h1><?php print $title; ?></h1>
          </div>
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
          if ($page['sidebar_left']) {
           $content_classes = 'col-md-9 col-lg-9 col-sm-12 col-xs-12'; 
          }
          else {
            $content_classes = 'col-md-12 col-lg-12 col-sm-12 col-xs-12';
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