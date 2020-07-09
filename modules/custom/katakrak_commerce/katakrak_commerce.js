(function ($) {
  Drupal.behaviors.katakrakCommerce = {
    attach: function (context, settings) {
      $('#commerce-shipping-service-ajax-wrapper .form-wrapper input.form-radio').each(function(index) {
        $(this).parent('label').parent('div').removeClass('active');
        if ($(this).is(":checked")) {
         $(this).parent('label').parent('div').addClass('active');
         $(this).parent('label').addClass($(this).attr('value'));
         $('#edit-informacion-envio .tipo-envio').each(function(index) {
           $(this).addClass('text-gray');  
         });
         $('#edit-informacion-envio .'+$(this).attr('value')).removeClass('text-gray');
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

