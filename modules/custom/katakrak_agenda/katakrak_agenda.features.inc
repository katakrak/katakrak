<?php
/**
 * @file
 * katakrak_agenda.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_agenda_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function katakrak_agenda_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function katakrak_agenda_image_default_styles() {
  $styles = array();

  // Exported image style: event_ciclos.
  $styles['event_ciclos'] = array(
    'label' => 'Event ciclos',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_highlight.
  $styles['event_highlight'] = array(
    'label' => 'Event highlight',
    'effects' => array(
      17 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      18 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 600,
          'height' => 400,
          'anchor' => 'left-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: event_home.
  $styles['event_home'] = array(
    'label' => 'Event home',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_node_view.
  $styles['event_node_view'] = array(
    'label' => 'Event node view',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 330,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_teaser.
  $styles['event_teaser'] = array(
    'label' => 'Event teaser',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_thumbnail.
  $styles['event_thumbnail'] = array(
    'label' => 'Event thumbnail',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 80,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: home_agenda.
  $styles['home_agenda'] = array(
    'label' => 'home_agenda',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 450,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: home_agenda_main.
  $styles['home_agenda_main'] = array(
    'label' => 'Home agenda main',
    'effects' => array(
      19 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 650,
          'height' => 390,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: home_agenda_main_secondary.
  $styles['home_agenda_main_secondary'] = array(
    'label' => 'Home agenda main secondary',
    'effects' => array(
      21 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 650,
          'height' => 220,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function katakrak_agenda_node_info() {
  $items = array(
    'ciclo' => array(
      'name' => t('Ciclo'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titulo'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
