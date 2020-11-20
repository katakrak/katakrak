(function ($) {
  Drupal.behaviors.katakrak_editorial = {
    attach: function (context, settings) {
      $('main.main').css('background-color', $('.color-fondo').html());
      console.log($('.color-fondo').html());
    }
  };
})(jQuery);
