(function ($) {
  Drupal.behaviors.katakrak_editorial = {
    attach: function (context, settings) {
      $('main.main').css('background-color', $('.color-fondo').html());
    }
  };
})(jQuery);
