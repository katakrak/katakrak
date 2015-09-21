

    <div class="content-wrap">
      <div class="container clearfix">

        <?php
        $content_class = 'content-main-column';
        $sidebar_class = 'sidebar-column';
//        if ($page['sidebar_first']) {
//          $content_class = 'postcontent col_last';
//        }
//        if ($page['sidebar_second']) {
//          $sidebar_class = 'col_last';
//          $content_class = 'postcontent';
//        }
        ?>
        <!-- content region -->
        <div class="<?php print $content_class; ?> nobottommargin clearfix">

          <?php if ($messages): ?>
            <?php print $messages; ?>
          <?php endif; ?>

          <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>

          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>

              <?php print render($page['content']); ?>
          
          <?php print $feed_icons; ?>
        </div>
        <!-- // content region -->

        
    </div>
  </div>

</div>