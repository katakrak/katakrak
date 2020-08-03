<?php

/**
 * @file
 * Bootstrap sub-theme.
 *
 * Place your custom PHP code in this file.
 */
function kapital_preprocess_page(&$vars) {
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
  
  if (user_is_anonymous())
    $vars['user_url'] = url('user');
  else 
    $vars['user_url'] = url('user/'.$user->uid);
  
 // dpm($vars);
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