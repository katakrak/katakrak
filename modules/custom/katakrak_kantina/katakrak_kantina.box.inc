<?php
/**
 * @file
 * katakrak_kantina.box.inc
 */

/**
 * Implements hook_default_box().
 */
function katakrak_kantina_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'twitter_kantina';
  $box->plugin_key = 'simple';
  $box->title = '@kantinaKatakrak';
  $box->description = 'Twitter kantina';
  $box->options = array(
    'body' => array(
      'value' => '<p><a class="twitter-timeline" data-widget-id="587610692305453057" href="https://twitter.com/kantinakatakrak">Tweets por el @kantinakatakrak.</a> <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?\'http\':\'https\';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['twitter_kantina'] = $box;

  return $export;
}
