<?php

/**
 * @file
 * Bootstrap sub-theme.
 *
 * Place your custom PHP code in this file.
 */
function kapital_preprocess_page(&$vars) {
//  $variables['primary_nav'] = FALSE;
//  if ($vars['main_menu']) {
//    // Load the tree.
//    $tree = menu_tree_page_data(variable_get('menu_main_links_source', 'main-menu'));
//
//    // Localize the tree.
//    $tree = i18n_menu_localize_tree($tree);
//
//    // Build links.
//    $vars['primary_nav'] = menu_tree_output($tree);
//
//    // Provide default theme wrapper function.
//    $vars['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
//    foreach (element_children($vars['primary_nav']) as $child) {
//      $vars['primary_nav'][$child]['#attributes']['class'][] = 'nav-item';
//      if ($vars['primary_nav'][$child]['#original_link']['in_active_trail']) {
//        $vars['primary_nav'][$child]['#attributes']['class'][] = 'active';
//      }
//    }
//  }
var_dump($vars['theme_hook_suggestions']);
  global $user;
  //Añadimos fontawesome
  drupal_add_js('https://kit.fontawesome.com/10471300b3.js', 'external');

  //Definimos enlace de donde estamos
  $vars['donde_estamos'] = l('<i class="fas fa-location-arrow" aria-hidden="true"></i> <span class="hidden-xs">'.t('¿Dónde estamos?').'</span>', 'contact', array('html' => TRUE, 'attributes' => array('target' => '_blank')));//<a href="" target="_blank">

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
  if (user_is_anonymous())
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

function format_localized_date($timestamp, $format, $locale)
{
    $dateFormatter = new IntlDateFormatter(
        $locale,
        IntlDateFormatter::FULL,
        IntlDateFormatter::FULL,
        date_default_timezone_get(),
        IntlDateFormatter::GREGORIAN,
        $format
    );

    return $dateFormatter->format($timestamp);
}

function kapital_theme_registry_alter(&$registry) {
  // Retrieve the active theme names.
  $themes = _bootstrap_get_base_themes(NULL, TRUE);

  // Return the theme registry unaltered if it is not Bootstrap based.
  if (!in_array('bootstrap', $themes)) {
    return;
  }

  // Inject the "footer" variable default in the existing "table" hook.
  // @see https://www.drupal.org/node/806982
  // @todo Make this discoverable in some way instead of a manual injection.
  $registry['table']['variables']['footer'] = NULL;

  // Process registered hooks in the theme registry.
  _bootstrap_process_theme_registry($registry, $themes);

  // Process registered hooks in the theme registry to add necessary theme hook
  // suggestion phased function invocations. This must be run after separately
  // and after all includes have been loaded.
  _bootstrap_process_theme_registry_suggestions($registry, $themes);

  /* // Merge both "html" and "page" theme hooks into "maintenance_page". Create
  // a fake "page" variable to satisfy both "html" and "page" preprocess/process
  // functions. Whether or not they stumble over each other doesn't matter since
  // the "maintenance_page" theme hook uses the "content" variable instead.
  $registry['maintenance_page']['variables']['page'] = array(
    '#show_messages' => TRUE,
    '#children' => NULL,
    'page_bottom' => array(),
    'page_top' => array(),
  );
  foreach (array('html', 'page') as $theme_hook) {
    foreach (array('includes', 'preprocess functions', 'process functions') as $property) {
      if (!isset($registry['maintenance_page'][$property])) {
        $registry['maintenance_page'][$property] = array();
      }
      if (!isset($registry[$theme_hook][$property])) {
        $registry[$theme_hook][$property] = array();
      }
      $registry['maintenance_page'][$property] = array_merge($registry['maintenance_page'][$property], $registry[$theme_hook][$property]);
    }
  } */

  // Post-process theme registry. This happens after all altering has occurred.
  foreach ($registry as $hook => $info) {
    // Ensure uniqueness.
    if (!empty($registry[$hook]['includes'])) {
      $registry[$hook]['includes'] = array_unique($info['includes']);
    }
    if (!empty($registry[$hook]['preprocess functions'])) {
      $registry[$hook]['preprocess functions'] = array_unique($info['preprocess functions']);
    }
    if (!empty($registry[$hook]['process functions'])) {
      $registry[$hook]['process functions'] = array_unique($info['process functions']);
    }

    // Ensure "theme path" is set.
    if (!isset($registry[$hook]['theme path'])) {
      $registry[$hook]['theme path'] = $GLOBALS['theme_path'];
    }
  }
}

function kapital_preprocess_maintenance_page(&$vars){
  var_dump($vars['theme_hook_suggestions']);
  $vars['custom_message'] = 'This is a custom message.';
}
