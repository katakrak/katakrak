<?php

/**
 * @file
 * Bootstrap sub-theme.
 *
 * Place your custom PHP code in this file.
 */
function kapital_preprocess_page(&$vars) {
  dpm(menu_tree_all_data('menu-menu-nagusia'));
  $vars['main_menu'] = menu_build_tree('menu-menu-nagusia');
  global $user;
  //Añadimos fontawesom
  drupal_add_js('https://kit.fontawesome.com/10471300b3.js', 'external');
  
  //Definimos enlace de donde estamos
  $vars['donde_estamos'] = l('<i class="fas fa-location-arrow" aria-hidden="true"></i> <span class="hidden-xs">'.t('¿Dónde estamos?').'</span>', 'contacto', array('html' => TRUE, 'attributes' => array('target' => '_blank')));//<a href="" target="_blank">
  
  //Las dos versiones del logo
  $vars['logo_small'] = 'sites/all/themes/kapital/images/katakrak-icon.svg';
  $vars['logo_medium'] = 'sites/all/themes/kapital/images/katakrak-logo.svg';
  $vars['logo_large'] = 'sites/all/themes/kapital/images/katakrak-logo-h.svg';
  
  
  //Generamos los links de idiomas
  $path = drupal_is_front_page() ? '<front>' : $_GET['q'];
  $links = language_negotiation_get_switch_links('language', $path);
  global $language;
  foreach ($links->links as $langcode => $link) {
    if ($language->language == $langcode){
      $options = array(
        'html' => TRUE,
        'attributes' => array(
          'role' => 'button',
          'data-toggle' => 'dropdown',
          'aria-haspopup' => 'true',
          'aria-expanded' => 'false',
          'class' => array('dropdown-toggle'),
          'id' => 'dropdownIdioma'
        ),
        'language' => $link['language'],
      );     
      $vars['current_language_link'] = l('<i class="fas fa-globe-africa small hidden-xs" aria-hidden="true"></i> '.$link['language']->prefix, $link['href'], $options);
    }
    else{
      $vars['language_switch_link'] = l($link['language']->prefix, $link['href'], array('language' => $link['language'], 'attributes' => array('class' => array('dropdown-item'))) );
    }
  }
  $vars['href_cas'] = url($links->links['es']['href'], array('language' => $links->links['es']['language']));
  $vars['href_eus'] = url($links->links['eu']['href'], array('language' => $links->links['eu']['language']));
  
  if (!user_is_anonymous()){
    $vars['user_name'] = $user->name;
    $vars['uid'] = $user->uid;
  }
  if (!user_access('administer site')) 
    unset($vars['tabs']);
  //dpm($vars);
}

function kapital_preprocess_search_result(&$vars) {
  global $user;
  if ($vars['result']['entity_type'] == 'node') {
    $node = node_load($vars['result']['node']->entity_id);
    
  }
}

function kapital_facetapi_title($vars) {
   return t('@title:', array('@title' => t($vars['title'])));
}

function kapital_preprocess_search_results(&$vars) {
 
  foreach ($vars['results'] as $result) {
    $nids[] = $result['node']->entity_id;
  }
  $nodes = node_load_multiple($nids);
  foreach ($nodes as $node) {
    $node_view = node_view($node, 'card_book_md');
    $output .= drupal_render($node_view);
  }
  $vars['search_results'] = $output;
}


/**
 * Theme function for unified login page.
 *
 * @ingroup themable
 */
function kapital_lt_unified_login_page($variables) {

  $login_form = $variables['login_form'];
  $register_form = $variables['register_form'];
  $active_form = $variables['active_form'];
  $output = '<div class="row">
        <div class="col-md-6 col-md-offset-3">';

  $output .= '<div class="toboggan-unified ' . $active_form . '">';
  $output .= '<h1 class="text-center">'.t('Mi cuenta').'</h1>';

  // Create the initial message and links that people can click on.
  $output .= '<ul class="nav nav-tabs nav-justified mt-2">';
  $output .= '<li class="active"><a href="#login" aria-controls="home" role="tab" data-toggle="tab">'.t('Ya tengo una cuenta').'</a></li>';
  $output .= '<li><a href="#signup" aria-controls="home" role="tab" data-toggle="tab">'.t('Crear nueva cuenta').'</a></li></ul>';
          
  $output .= '<div class="tab-content">';
  // Add the login and registration forms in.
  $output .= '<div role="tabpanel" class="tab-pane active" id="login">' . $login_form . '</div>';
  $output .= '<div role="tabpanel" class="tab-pane" id="signup">' . $register_form . '</div>';

  $output .= '</div></div>';

  return $output;
}
