<?php
/**
 * @file
 * katakrak_agenda.box.inc
 */

/**
 * Implements hook_default_box().
 */
function katakrak_agenda_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'twitter_feed';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Latestt tweets';
  $box->options = array(
    'body' => array(
      'value' => '<a class="twitter-timeline" href="https://twitter.com/katakrak54" data-widget-id="434502326703771648">@katakrak54(r)en Txioak</a>
<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?\'http\':\'https\';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
',
      'format' => 'full_html',
    ),
  );
  $export['twitter_feed'] = $box;

  return $export;
}
