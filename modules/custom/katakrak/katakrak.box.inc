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
  $box->delta = 'social_widget';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'social';
  $box->options = array(
    'body' => array(
      'value' => '<ul>
  <li class="ts-facebook"><a href="#"><span class="ts-icon"></span><span class="ts-text">Facebook</span></a></li>
  <li class="ts-twitter"><a href="#"><span class="ts-icon"></span><span class="ts-text">Twitter</span></a></li>
  <li class="ts-rss"><a href="#"><span class="ts-icon"></span><span class="ts-text">RSS</span></a></li>
  <li class="ts-phone"><a href="tel:+913326789234"><span class="ts-icon"></span><span class="ts-text">+9948225529</span></a></li>
  <li class="ts-mail"><a href="mailto:coworker@abc.com"><span class="ts-icon"></span><span class="ts-text">info@katakrak.cc</span></a></li>
 
</ul>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['social_widget'] = $box;

  return $export;
}
