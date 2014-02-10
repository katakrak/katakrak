<?php
/**
 * @file
 * katakrak_dilve.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_dilve_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
