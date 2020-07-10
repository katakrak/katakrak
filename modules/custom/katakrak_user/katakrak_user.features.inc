<?php

/**
 * @file
 * katakrak_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function katakrak_user_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
