(function ($) {
  Drupal.behaviors.katakrak_editorial = {
      attach: function (context, settings) {
          $('.form-control.tabs').on('change', function(e) {
             $('.tab-pane').removeClass('active');
             $('#'+$(e.currentTarget).val()).addClass('active');
          });
      }
    };
})(jQuery);

