/**
 * @file
 * Javascript for Color Field.
 */
(function ($) {
  "use strict";

  Drupal.behaviors.color_field_farbtastic = {
    attach: function (context) {
      $.each(Drupal.settings.color_field_farbtastic, function (selector) {
        $('#' + this.picker_id).farbtastic('#' + this.id);
      });
    }
  };
})(jQuery);
