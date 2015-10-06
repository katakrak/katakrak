
<div class="container">
  <div class="row">
    <?php if ($page['post_content_bottom_right']): ?>
      <div id="bottom-social" class="col-md-6 col-sm-6">
        <?php print render($page['post_content_bottom_right']); ?>
      </div>
    <?php endif; ?>
    <div class="col-md-6 col-sm-6">
      <div class="banda_footer "></div>
    </div>
  </div>
</div>
<?php $footer_style = theme_get_setting('footer_style', 'coworker'); ?>
  <?php if ($page['footer_first'] || $page['footer_second'] || $page['footer_third']): ?>
    
    <div id="footer" class="footer-<?php print $footer_style; ?>">
      <div class="container clearfix">
        <div class="begiak">
        </div>
        <div class="footer-widgets-wrap clearfix">
          <div class="row">
            <div class="col-md-3 col-sm-3">
              <?php print render($page['footer_first']); ?>
            </div>          
            <div class="col-md-3 col-sm-3">
              <?php print render($page['footer_second']); ?>
            </div>
            <div class="col-md-3 col-sm-3">
              <?php print render($page['footer_third']); ?>
            </div>
        </div>

        </div>


      </div>


    </div>
  <?php endif; ?>

  <div class="clear"></div>


  <?php if ($page['footer']): ?>

    <div id="copyrights" class="copyrights-<?php print $footer_style; ?>">

      <div class="container clearfix">
        <?php print render($page['footer']); ?>
      </div>
    </div>
  <?php endif; ?>

<div id="gotoTop" class="icon-angle-up"></div>
