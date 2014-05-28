<?php

function coworker_form_system_theme_settings_alter(&$form, $form_state) {

  $path = drupal_get_path('theme', 'coworker');
  drupal_add_library('system', 'ui');
  drupal_add_library('system', 'farbtastic');

  drupal_add_js($path . '/js/theme_admin.js');

  $form['settings'] = array(
      '#type' => 'vertical_tabs',
      '#title' => t('Theme settings'),
      '#weight' => 2,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );

  $form['settings']['general'] = array(
      '#type' => 'fieldset',
      '#title' => t('General settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );
  /* $form['settings']['general']['enable_responsive'] = array(
    '#type' => 'select',
    '#title' => t('Enable responsive'),
    '#default_value' => theme_get_setting('enable_responsive'),
    '#options' => array(
    1 => t('Yes'),
    0 => t('No')
    ),
    ); */
  $form['settings']['general']['homepage_title'] = array(
      '#type' => 'checkbox',
      '#title' => t('Disable homepage title'),
      '#default_value' => theme_get_setting('homepage_title', 'coworker'),
  );
  if (module_exists('imce')) {
    $form['settings']['general']['rentina_logo'] = array(
        '#type' => 'textfield',
        '#title' => t('Rentina Logo'),
        '#default_value' => theme_get_setting('rentina_logo', 'coworker'),
        '#description' => t('Setting Rentina logo, requires module http://drupal.org/project/imce'),
    );
  } else {
    drupal_set_message(t('Module Imce is required for Rentina logo settings. http://drupal.org/project/imce'), 'error');
  }





  $form['settings']['footer'] = array(
      '#type' => 'fieldset',
      '#title' => t('Footer settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );

  $form['settings']['footer']['footer_style'] = array(
      '#type' => 'select',
      '#title' => t('Footer style'),
      '#options' => array(
          'light' => t('Light'),
          'dark' => t('Dark'),
      ),
      '#default_value' => theme_get_setting('footer_style', 'coworker'),
  );

  $form['settings']['skin'] = array(
      '#type' => 'fieldset',
      '#title' => t('Skin settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );


  $form['settings']['skin']['theme_layout'] = array(
      '#title' => t('Theme layout'),
      '#type' => 'select',
      '#options' => array(
          'stretched' => t('Full width'),
          'boxed-layout' => t('Boxed'),
      ),
      '#default_value' => theme_get_setting('theme_layout'),
  );

  $form['settings']['skin']['coworker_theme_color'] = array(
      '#title' => t('Theme color'),
      '#type' => 'textfield',
      '#default_value' => theme_get_setting('coworker_theme_color', 'coworker'),
      '#attributes' => array('class' => array('input color')),
      '#description' => t('Default color hex code is: #2780AF'),
  );
  
  // bg background
  $dir = drupal_get_path('theme', 'coworker') . DIRECTORY_SEPARATOR . 'images' . DIRECTORY_SEPARATOR . 'patterns';

  $files = file_scan_directory($dir, '/.*\.png/');


  $bg_files = array();
  if (!empty($files)) {
    foreach ($files as $file) {
      if (isset($file->filename)) {
        $bg_files[$file->filename] = $file->filename;
      }
    }
  }

  $form['settings']['skin']['theme_background_image'] = array(
      '#title' => t('Background image'),
      '#type' => 'select',
      '#default_value' => theme_get_setting('theme_background_image', 'coworker'),
      '#options' => $bg_files,
      '#description' => t('All images background in <strong>!url</strong>', array('!url' => $dir)),
  );
  
  
  $form['settings']['skin']['theme_custom_css'] = array(
      '#type' => 'textarea',
      '#title' => t('Custom css'),
      '#default_value' => theme_get_setting('theme_custom_css', 'coworker'),
      '#description' => t('Custom your own css eg: <strong> body{background: transparent url("http://domain.com/bg.jpg") scroll 0 0 no-repeat;}</strong>'),
  );

  $form['#submit'][] = '_coworker_form_submit';
}

function _coworker_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  if (!empty($values['coworker_theme_color'])) {
    _save_css_color_file($values['coworker_theme_color']);
  }
}

function _save_css_color_file($color) {
  $file = 'css/colors.css';
  $style = _get_color_css_temp($color);

  $palette = 'coworker';
  $theme = 'coworker';
  $id = $theme . '_color_cache';  //'-' . substr(hash('sha256', serialize($palette) . microtime()), 0, 8);
  $paths['color'] = 'public://color';
  $paths['target'] = $paths['color'] . '/' . $id;





  foreach ($paths as $path) {
    file_prepare_directory($path, FILE_CREATE_DIRECTORY);
  }

  $paths['target'] = $paths['target'] . '/';
  $paths['id'] = $id;
  $paths['source'] = drupal_get_path('theme', $theme) . '/';
  $paths['files'] = $paths['map'] = array();


  $base = base_path() . dirname($paths['source'] . $file) . '/';
  _drupal_build_css_path(NULL, $base);

  $base_file = drupal_basename($file);

  $file = $paths['target'] . $base_file;

  $filepath = file_unmanaged_save_data($style, $file, FILE_EXISTS_REPLACE);

  variable_set('coworker_theme_color', $filepath);
}

function _get_color_css_temp($color) {



  $css = "
a,
h1 span,
h2 span,
h3 span,
h4 span,
h5 span,
h6 span,
#top-menu li a:hover,
#lp-contacts li span,
#portfolio-filter li a:hover,
#portfolio-filter li.activeFilter a,
.portfolio-item:hover h3 a,
.entry_date div.post-icon,
.entry_meta li a:hover,
.ipost .ipost-title a:hover,
.comment-content .comment-author a:hover,
.promo h3 > span,
.error-404,
.tab_widget ul.tabs li.active a,
.product-feature3:hover span,
.team-skills li span,
.best-price .pricing-title h4,
.best-price .pricing-price { color: $color; }

.pricing-style2 .pricing-price { color: #FFF !important; }


/* ----------------------------------------------------------------
    Background Colors
-----------------------------------------------------------------*/


#top-menu li.top-menu-em a,
#primary-menu > ul > li:hover,
#primary-menu > ul > li.active-trail,
#primary-menu ul li.current,
#primary-menu > div > ul > li:hover,
#primary-menu div ul li.current,
#primary-menu > div > ul > li.current-menu-ancestor,
#primary-menu > div > ul > li.current-menu-parent,
#primary-menu > div > ul > li.current-menu-item,
#primary-menu > div > ul > li.current_page_parent,
#primary-menu ul ul li,
.lp-subscribe input[type=\"submit\"],
.portfolio-overlay,
#portfolio-navigation a:hover,
.entry_date div.month,
.entry_date div.day,
.entry_date div.hour,
.entry_date div.weekday,
.sidenav > .active > a,
.sidenav > .active > a:hover,
.promo-action a:hover,
.error-404-meta input[type=\"submit\"],
.product-feature img,
.product-feature > span,
.team-image span,
.icon-rounded:hover,
.icon-circled:hover,
.simple-button.inverse,
.simple-button:hover,
.pricing-style2 .best-price .pricing-price,
#twitter-panel,
#gotoTop:hover,
a.twitter-follow-me:hover,
#footer.footer-dark a.twitter-follow-me:hover,
.sposts-list .spost-image:hover,
#footer.footer-dark .sposts-list .spost-image:hover,
.tagcloud a:hover,
#footer.footer-dark .tagcloud a:hover,
.widget-scroll-prev:hover,
.widget-scroll-next:hover,
#footer.footer-dark .widget-scroll-prev,
#footer.footer-dark .widget-scroll-next { background-color: $color; }

.ei-title h2 span,
.ei-title h3 span,
.ei-slider-thumbs li.ei-slider-element,
.flex-prev:hover,
.flex-next:hover,
.rs-prev:hover,
.rs-next:hover,
.nivo-prevNav:hover,
.nivo-nextNav:hover,
.camera_prev:hover,
.camera_next:hover,
.camera_commands:hover,
.tp-leftarrow.large:hover,
.tp-rightarrow.large:hover,
.ls-noskin .ls-nav-prev:hover,
.ls-noskin .ls-nav-next:hover { background-color: $color !important; }

.ei-title h3 span { background-color: rgba(11,11,11,0.8) !important; }


/* ----------------------------------------------------------------
    Border Colors
-----------------------------------------------------------------*/


#top-menu li a:hover,
.comment-content .comment-author a:hover,
.our-clients li:hover { border-color: $color; }


#header.header2,
.flex-control-thumbs li img.flex-active,
.rs-thumb-wrap a.active,
.tab_widget ul.tabs li.active,".
#footer,
"#copyrights { border-top-color: $color; }


span.page-divider span,
#portfolio-filter li.activeFilter,
.portfolio-item:hover .portfolio-title,
#footer.footer-dark .portfolio-item:hover .portfolio-title { border-bottom-color: $color; }


.slide-caption,
.rs-caption,
.nivo-caption,
.promo,
.side-tabs ul.tabs li.active { border-left-color: $color; }

.ei-title h3 span { border-left-color: $color !important; }


/* ----------------------------------------------------------------
    Selection Colors
-----------------------------------------------------------------*/


::selection,
::-moz-selection,
::-webkit-selection { background-color: $color; }";




  return $css;
}