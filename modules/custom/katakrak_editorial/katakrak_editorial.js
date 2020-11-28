(function ($) {
  Drupal.behaviors.katakrak_editorial = {
    attach: function (context, settings) {
      $('main.main').css('background-color', $('.color-fondo').html());
       $('.imagen-autor-ed  img').each(function(index) {
          console.log($(this));
          $(this).addClass('img-circle');
       });
    }
    
  };
})(jQuery);
