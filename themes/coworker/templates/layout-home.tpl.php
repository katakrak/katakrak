<?php include 'page-header.inc' ?>

<?php if (!empty($page['slider'])): ?>
  <div id="slider">
    <?php print render($page['slider']); ?>
  </div>
<?php endif; ?>
<div class="clear"></div>
<div id="content">
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

          
            <div class="col_two_third">
              <?php print render($page['content']); ?>
            </div>
            <div class="col_one_third col_last">
              <?php if ($page['sidebar_second']): ?>
              <!-- sidebar right --> 
                <div id="sidebar-second" class="sidebar-right nobottommargin clearfix">
                  <?php print render($page['sidebar_second']); ?>
                </div>
                <!-- // sidebar right -->
              <?php endif; ?>
            </div>
          
         
          <?php print $feed_icons; ?>
        </div>
        <!-- // content region -->

        



    </div>
  </div>

</div>
<?php include 'page-footer.inc' ?>