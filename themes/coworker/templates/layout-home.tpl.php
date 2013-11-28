<?php include 'page-header.inc' ?>

<?php if (!empty($page['slider'])): ?>
  <div id="slider">
    <?php print render($page['slider']); ?>
  </div>
<?php endif; ?>

<div id="content">
    <div class="content-wrap">
      <div class="container clearfix">
        <!-- content region -->
        <div class="nobottommargin clearfix">

          <?php if ($messages): ?>
            <?php print $messages; ?>
          <?php endif; ?> 

          <?php if ($page['top_page']): ?>
            <div id="page-top">
              <?php print render($page['top_page']); ?>
            </div>
          <?php endif; ?>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>

          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>

          <div class="row-fluid">
            <div class="span8">
              <?php print render($page['content']); ?>
            </div>
            <div class="span4">
              <?php if ($page['sidebar_second']): ?>
              <!-- sidebar right --> 
                <div id="sidebar-second" class="sidebar-right nobottommargin clearfix">
                  <?php print render($page['sidebar_second']); ?>
                </div>
                <!-- // sidebar right -->
              <?php endif; ?>
            </div>
          </div>
         
          <?php print $feed_icons; ?>
        </div>
        <!-- // content region -->

        



    </div>
  </div>

</div>
<?php include 'page-footer.inc' ?>