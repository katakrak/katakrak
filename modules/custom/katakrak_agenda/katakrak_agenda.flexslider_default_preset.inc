<?php

/**
 * @file
 * katakrak_agenda.flexslider_default_preset.inc
 */

/**
 * Implements hook_flexslider_default_presets().
 */
function katakrak_agenda_flexslider_default_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'home';
  $preset->title = 'Home';
  $preset->theme = 'classic';
  $preset->options = array(
    'animation' => 'fade',
    'animationLoop' => 1,
    'animationSpeed' => '600',
    'asNavFor' => '',
    'controlNav' => '1',
    'controlsContainer' => '.flex-control-nav-container',
    'direction' => 'horizontal',
    'directionNav' => 1,
    'easing' => 'swing',
    'initDelay' => '0',
    'itemMargin' => '0',
    'itemWidth' => '0',
    'keyboard' => 1,
    'manualControls' => '',
    'maxItems' => '0',
    'minItems' => '0',
    'mousewheel' => 0,
    'move' => '0',
    'multipleKeyboard' => 0,
    'namespace' => 'flex-',
    'nextText' => '',
    'pauseOnAction' => 1,
    'pauseOnHover' => 0,
    'pausePlay' => 0,
    'pauseText' => 'Pause',
    'playText' => 'Play',
    'prevText' => '',
    'randomize' => 0,
    'reverse' => 0,
    'selector' => '.slides > li',
    'slideshow' => 1,
    'slideshowSpeed' => '7000',
    'smoothHeight' => 0,
    'startAt' => '0',
    'sync' => '',
    'thumbCaptions' => 0,
    'thumbCaptionsBoth' => 0,
    'touch' => 1,
    'useCSS' => 1,
    'video' => 0,
  );
  $export['home'] = $preset;

  return $export;
}
