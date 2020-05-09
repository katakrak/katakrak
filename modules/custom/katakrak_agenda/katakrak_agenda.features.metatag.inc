<?php

/**
 * @file
 * katakrak_agenda.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function katakrak_agenda_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:event.
  $config['node:event'] = array(
    'instance' => 'node:event',
    'config' => array(
      'og:description' => array(
        'value' => '[node:field_event_description]',
      ),
      'og:image' => array(
        'value' => '[node:field_event_image:event_home:render]',
      ),
    ),
  );

  return $config;
}
