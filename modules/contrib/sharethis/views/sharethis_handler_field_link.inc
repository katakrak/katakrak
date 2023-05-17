<?php

/**
 * @file
 * Field handler to display ShareThis links.
 */

/**
 * Field handler for ShareThis.
 */
class sharethis_handler_field_link extends views_handler_field_entity {

  /**
   * Render values.
   */
  public function render($values) {
    if ($entity = $this->get_value($values)) {
      return $this->renderSharethisLink($entity);
    }
  }

  /**
   * Renders sharethis link.
   */
  public function renderSharethisLink($entity) {
    $path = url('node/' . $entity->nid, ['absolute' => TRUE]);
    sharethis_include_js();

    return theme('sharethis', [
      'data_options' => sharethis_get_options_array(),
      'm_title' => $entity->title,
      'm_path' => $path,
    ]);
  }

}
