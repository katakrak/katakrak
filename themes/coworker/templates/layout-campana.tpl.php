

<?php include 'page-header.inc' ?>
<div id="content" class="book-page">
  <div class="container">
    <div class="content-wrap">
    <?php if ($page['content_top']): ?>
      <div id="content-top">
        <?php print render($page['content_top']); ?>
      </div>
    <?php endif; ?>
      </div>
  </div>


    
      <div class="container clearfix">
        <!-- content region -->
        <div class="nobottommargin clearfix">
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
	<!-- Editar aqui-->
          
  <br /><br />
           <div class="row">
               <!-- Vinculo para la página de altas -->
            <div class="col-md-8 col-lg-8 col-sm-12 col-xs-12 bloque-campana">
              <?php print render($page['content']); ?>
                <?php print render($page['content_campana_left']); ?>
            </div>
               
               
               
            <div class="col-md-4 col-lg-4 col-sm-12 col-xs-12"> 
              <?php print render($page['content_campana_right']) ?>
            </div>
   
            
		  <!-- Fin de editar-->
          
          <?php print render($page['content_bottom']) ?>
        <?php if ($page['content_bottom_first'] || $page['content_bottom_second'] || $page['content_bottom_third'] || $page['content_bottom_fourth']): ?>
        <div id="content-bottom" class="row">
          <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
            <?php print render($page['content_bottom_first']); ?>
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
          <?php print $feed_icons; ?>
        </div>
        <!-- // content region -->

    </div>
  </div>

<?php include 'page-footer.inc' ?>