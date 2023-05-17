/**
 * @file
 * Javascript for Color Field.
 */
(function ($) {
  "use strict";

  Drupal.behaviors.color_field_spectrum = {
    attach: function (context) {
      $.each(Drupal.settings.color_field_spectrum, function (selector) {

        $(selector).spectrum({

          showInitial: true,
          preferredFormat: "hex",
          showInput: this.show_input,
          showAlpha: this.show_alpha,
          showPalette: this.show_palette,
          showPaletteOnly: this.show_palette_only,
          palette:[this.palette],
          showButtons: this.show_buttons,
          allowEmpty: this.allow_empty,
          appendTo: selector.replace("#edit-", ".form-item-"),

          change: function(tinycolor) {
            if (tinycolor) {
              var opacity_selector = selector.replace("-rgb","-opacity");
              if ($(opacity_selector)) {
                $(selector).val(tinycolor.toHexString());
                $(opacity_selector).val(tinycolor._roundA);
              }
            }
          }

        });

        // Set alpha value on load.
        if (this.show_alpha) {
          var tinycolor = $(selector).spectrum("get");
          if (tinycolor) {
            var opacity_selector = selector.replace("-rgb","-opacity");
            var alpha = $(opacity_selector).val();
            // If alpha is set only.
            if (alpha > 0) {
              tinycolor.setAlpha(alpha);
              $(selector).spectrum("set", tinycolor);
            }
          }
        }

      });
    }
  };
})(jQuery);
