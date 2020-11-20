(function ($) {
  Drupal.behaviors.katakrakSocios = {
    attach: function (context, settings) {
      $('#socixs-menu a.selector').click(function() {
      $('a.selector-label').html($(this).html()+' <span class="caret"></span>');
    });
    }
  };
})(jQuery);