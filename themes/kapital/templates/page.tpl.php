<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>
<?php include 'page-header.inc' ?>

<main class="main">
<div class="row">
  <section<?php print $content_column_class; ?>>
    <?php if (!empty($page['highlighted'])): ?>
      <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
    <?php endif; ?>
    <?php if (!empty($breadcrumb)): print $breadcrumb;
    endif;?>
    <a id="main-content"></a>
    <?php print render($title_prefix); ?>
    <?php if (!empty($title)): ?>
      <h1 class="page-header"><?php print $title; ?></h1>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php print $messages; ?>
    <?php if (!empty($tabs)): ?>
      <?php print render($tabs); ?>
    <?php endif; ?>
    <?php if (!empty($page['help'])): ?>
      <?php print render($page['help']); ?>
    <?php endif; ?>
    <?php if (!empty($action_links)): ?>
      <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>

  </section>
</div>

<div class="row row-no-gutters">    
  <div class="col-sm-12 col-md-6">
    <?php print render($page['content_top_left']) ?>
  </div>
  <div class="col-sm-12 col-md-6">
    <?php print render($page['content_top_right']) ?>
  </div>
  <div class="clearfix"></div>
  <div class="col-sm-4">

      <div class="cta cta-secondary cta-katering">
        <div class="cta-text">
          <div>
            <h1 class="h1-lg text-color-light">Katering</h1>
            <p class="lead text-color-light">En tu casa, vicio</p>
          </div>
         <button class="btn btn-light">Saboréalo</button>
        </div><!--/.cta-text -->
      </div><!--/.cta-katering -->
    </div><!--/.col -->
    <div class="col-sm-4">
      <div class="cta cta-secondary cta-editorial">
        <div class="cta-text">
          <div>
            <h1 class="title-light">Cuestionamos, traducimos, compartimos. <b>Editamos</b></h1>
          </div>
         <button class="btn btn-dark">La editorial</button>
        </div><!--/.cta-text -->
      </div><!--/.cta-katering -->
    </div><!--/.col -->
    <div class="col-sm-4">
      
      <div class="agenda-module">
        <!-- <p>Agenda</p> -->
        <div id="carousel-agenda" class="carousel slide" data-ride="carousel">
          <!-- Indicators -->
          <ol class="carousel-indicators">
            <li data-target="#carousel-example-generic" data-slide-to="0" class="active"></li>
            <li data-target="#carousel-example-generic" data-slide-to="1"></li>
            <li data-target="#carousel-example-generic" data-slide-to="2"></li>
          </ol>
        
          <!-- slides -->
          <div class="carousel-inner" role="listbox">
            <div class="item active">
              <div class="agenda-item d-flex">
                <div class="agenda-item-text">
                  <p> <span class="strong">Lunes 1 de junio</span>
                    <br>17:00 - 18:00</p>
                  <h2>
                    <a href="#">Economía de plataformas: de los datos a las bicis</a>
                  </h2>
                  <p class="small">Charla online</p>
                </div><!-- agenda-item-text -->
                <div class="agenda-item-photo">
                  <img src="images/agenda-photo.jpg">
                </div><!-- agenda-item-photo -->
              </div><!-- agenda-item-->
            </div><!-- /item-->
            <div class="item">
              <div class="agenda-item d-flex">
                <div class="agenda-item-text">
                  <p> <span class="strong">Lunes 1 de junio</span>
                    <br>17:00 - 18:00</p>
                  <h2>
                    <a href="#">Economía de plataformas: de los datos a las bicis</a>
                  </h2>
                  <p class="small">Charla online</p>
                </div><!-- agenda-item-text -->
                <div class="agenda-item-photo">
                  <img src="images/agenda-photo.jpg">
                </div><!-- agenda-item-photo -->
              </div><!-- agenda-item-->
            </div><!-- /item-->
          </div><!-- carousel-inner-->
        
          <!-- Controls -->
          <a class="left carousel-control" href="#carousel-agenda" role="button" data-slide="prev">
            <img src="images/angle-left.svg" width="30" height="30" alt="Anterior">
          </a>
          <a class="right carousel-control" href="#carousel-agenda" role="button" data-slide="next">
            <img src="images/angle-right.svg" width="30" height="30" alt="Siguiente">
          </a>
        </div>
      </div><!-- /.agenda-module -->
      
     
    </div><!--/.col -->
</div><!--/.row row-no-gutters -->
    
    
<?php print render($page['content']); ?>
  
</main>
<?php include 'page-footer.inc'; ?>
