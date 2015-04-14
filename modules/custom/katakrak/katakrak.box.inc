<?php
/**
 * @file
 * katakrak.box.inc
 */

/**
 * Implements hook_default_box().
 */
function katakrak_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'about_us';
  $box->plugin_key = 'simple';
  $box->title = 'About us';
  $box->description = 'About us';
  $box->options = array(
    'body' => array(
      'value' => 'Katakrak oso gauza interesgarria da zeren eta bla bla bla',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['about_us'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer katakrak';
  $box->options = array(
    'body' => array(
      'value' => 'C/Mayor 54 Kale Nagusia - <a href="tel:0034-948225520">948225520</a>',
      'format' => 'sinopsis',
    ),
  );
  $export['footer'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'twitter_feed';
  $box->plugin_key = 'simple';
  $box->title = '@katakrak54';
  $box->description = 'Twitter katakrak';
  $box->options = array(
    'body' => array(
      'value' => '<p><a class="twitter-timeline" data-widget-id="434502326703771648" href="https://twitter.com/katakrak54">@katakrak54(r)en Txioak</a> <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?\'http\':\'https\';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['twitter_feed'] = $box;

  return $export;
}
