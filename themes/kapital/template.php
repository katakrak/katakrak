<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function kapital_preprocess_page(&$vars) {
  $path = drupal_is_front_page() ? '<front>' : $_GET['q'];
  $links = language_negotiation_get_switch_links('language', $path);
  global $language;  
  $vars['active_lang'] = ucfirst($language->prefix);
  
  dpm ($links);
}