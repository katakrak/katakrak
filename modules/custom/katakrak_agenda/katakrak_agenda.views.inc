<?php
/**
 * @file
 * Provide views data and handlers.
 */

/**
 * Implements hook_views_plugins().
 */
function katakrak_agenda_views_plugins() {
  $module_path = drupal_get_path('module', 'katakrak_agenda');

  return array(
    'style' => array(
      'katakrak_agenda_grid_plugin_style' => array(
        'title' => t('Katakrak Agenda Grid'),
        'help' => t('Grid with a three items highlighted'),
        'handler' => 'katakrak_agenda_grid_plugin_style',
        'parent' => 'default',
        'theme' => 'katakrak_agenda_grid_plugin_style',
        'theme path' => $module_path . '/templates',
        'theme file' => 'theme.inc',
        'uses row plugin' => TRUE,
        'uses grouping' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
