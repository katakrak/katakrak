(function ($) {
  Drupal.behaviors.katakrakCommerce = {
    attach: function (context, settings) {
      $('#commerce-shipping-service-ajax-wrapper .fieldset-wrapper input.form-radio').each(function(index) {
        $(this).parent('label').removeClass('btn-active');
        if ($(this).attr('checked')) {
          $(this).parent('label').addClass('btn-active');
        }
        }
      );
      $('#commerce-checkout-form-review .fieldset-wrapper input.form-radio').each(function(index) {
        $(this).parent('label').removeClass('btn-active');
        if ($(this).attr('checked')) {
          $(this).parent('label').addClass('btn-active');
        }
        }
      );
    }
  };
})(jQuery);
