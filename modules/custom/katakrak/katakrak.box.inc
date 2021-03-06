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
    'additional_classes' => '',
    'body' => array(
      'format' => 'full_html',
      'value' => 'Katakrak oso gauza interesgarria da zeren eta bla bla bla',
    ),
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
      'format' => 'sinopsis',
      'value' => 'C/Mayor 54 Kale Nagusia - <a href="tel:0034-948225520">948225520</a>',
    ),
  );
  $export['footer'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'twitter_feed';
  $box->plugin_key = 'simple';
  $box->title = 'Facebook';
  $box->description = 'Twitter katakrak';
  $box->options = array(
    'additional_classes' => '',
    'body' => array(
      'format' => 'full_html',
      'value' => '<div class="fb-page" data-href="https://www.facebook.com/katakrak54" data-hide-cover="false" data-show-facepile="true" data-show-posts="true"><div class="fb-xfbml-parse-ignore"><blockquote cite="https://www.facebook.com/katakrak54"><a href="https://www.facebook.com/katakrak54">Katakrak</a></blockquote></div></div><h2>@katakrak54</h2><p><a class="twitter-timeline" data-widget-id="590120917562482689" href="https://twitter.com/katakrak54">Tweets by @katakrak54</a> <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?\'http\':\'https\';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script></p>',
    ),
  );
  $export['twitter_feed'] = $box;

  return $export;
}
