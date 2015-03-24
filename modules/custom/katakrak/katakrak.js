(function ($) {
  Drupal.behaviors.katakrak = {
    attach: function (context, settings) {
      $('#block-katakrak-katakrak-user-top a').before('<i class="fa fa-user"></i>&nbsp;');
    }
  };
})(jQuery);
