(function ($) {
  Drupal.behaviors.katakrakCommerce = {
    attach: function (context, settings) {
      $('#commerce-shipping-service-ajax-wrapper .fieldset-wrapper input.form-radio').each(function(index) {
        $(this).parent('label').removeClass('btn-active');
        if ($(this).is(":checked")) {
         $(this).parent('label').addClass('btn-active');
        }
        }
      );
      $('#commerce-checkout-form-review .fieldset-wrapper input.form-radio').each(function(index) {
        $(this).parent('label').removeClass('btn-active');
        if ($(this).is(":checked")) {
          $(this).parent('label').addClass('btn-active');
        }
        }
      );
      //Borramos el check 
      $('#views-form-commerce-cart-form-katakrak-default .btn.btn-secondary span').each(function(index) {
        $(this).removeClass('glyphicon-ok');  
        }
      );
      $('#views-form-commerce-cart-form-katakrak-default .btn-danger span').each(function(index) {
        $(this).removeClass('glyphicon-trash');  
        }
      );
    }
  };
})(jQuery);

