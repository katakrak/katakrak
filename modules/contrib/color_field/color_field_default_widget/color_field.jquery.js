/**
 * @file
 * Javascript for Color Field.
 */

(function ($) {
  "use strict";

  Drupal.behaviors.color_field = {
    attach: function (context) {
      $.each(Drupal.settings.color_field, function (selector) {
        // selector is the textfield.

        // Try to get the current selected value so we don't lose the value
        // if the form si submitted but not valid.
        var value = $(selector).val();
        if (value == '') value = this.value;

        $('#' + this.divid).empty().addColorPicker({
          currentColor:value,
          colors:this.colors,
          clickCallback: function(c) {
            $(selector).val(c).trigger('change');
          }
        });
      });
    }
  };
})(jQuery);
