<?php

/**
 * @file
 * katakrak_user.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function katakrak_user_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_login';
  $context->description = 'Defines the context for login page';
  $context->tag = 'User';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'user/login' => 'user/login',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_user-katakrak_user_login_help' => array(
          'delta' => 'katakrak_user_login_help',
          'module' => 'katakrak_user',
          'region' => 'banners',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => array(
      0 => 'menu-menu-nagusia:tienda',
    ),
    'theme' => array(
      'subtitle' => '',
      'title' => 'login',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Defines the context for login page');
  t('User');
  $export['user_login'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_pages';
  $context->description = 'Defines the context for user pages sucha as orders';
  $context->tag = 'User';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*' => 'user/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'katakrak_user-katakrak_user_nav_secundary' => array(
          'delta' => 'katakrak_user_nav_secundary',
          'module' => 'katakrak_user',
          'region' => 'banners',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => array(
      0 => 'menu-menu-nagusia:tienda',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Defines the context for user pages sucha as orders');
  t('User');
  $export['user_pages'] = $context;

  return $export;
}
