
<div class="container">
<div class="row-fluid">
<?php if ($page['post_content_bottom_right']): ?>
  <div id="top-social" class="span6">
    <?php print render($page['post_content_bottom_right']); ?>
   </div>
<?php endif; ?>
    <div class="span6">
      <div class="banda-footer "></div>
    </div>
  </div>
</div>
<?php $footer_style = theme_get_setting('footer_style', 'coworker'); ?>
  <?php if ($page['footer_first'] || $page['footer_second'] || $page['footer_third'] || $page['footer_fourth']): ?>
    
    <div id="footer" class="footer-<?php print $footer_style; ?>">
      <div class="container clearfix">
        <div class="begiak">
          <img src="/<?php print drupal_get_path('theme', 'coworker')?>/images/begiak.png">
        </div>
        <div class="footer-widgets-wrap clearfix">
          <?php if ($page['footer_first']): ?>
            <div class="col_one_fourth">
              <?php print render($page['footer_first']); ?>
            </div>
          <?php endif; ?>


          <?php if ($page['footer_second']): ?>
            <div class="col_one_fourth">
              <?php print render($page['footer_second']); ?>
            </div>
          <?php endif; ?>



          <?php if ($page['footer_third']): ?>
            <div class="col_one_fourth">
              <?php print render($page['footer_third']); ?>
            </div>
          <?php endif; ?>



          <?php if ($page['footer_fourth']): ?>
            <div class="col_one_fourth">
              <?php print render($page['footer_fourth']); ?>
            </div>
          <?php endif; ?>

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


</div>
<div id="gotoTop" class="icon-angle-up"></div>
