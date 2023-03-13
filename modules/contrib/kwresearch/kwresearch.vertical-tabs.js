
(function ($) {

Drupal.behaviors.kwresearchFieldsetSummaries = {
  attach: function (context) {
    $('fieldset#edit-kwresearch', context).drupalSetSummary(function (context) {
      var vals = [];
      $("input[type='text']", context).each(function() {
        var default_name = $(this).attr('name').replace(/\[value\]/, '[default]');
        var default_value = $("input[type='hidden'][name='" + default_name + "']", context);
        if (default_value.length && default_value.val() == $(this).val()) {
          // Meta tag has a default value and form value matches default value.
          return true;
        }
        else if (!default_value.length && !$(this).val().length) {
          // Meta tag has no default value and form value is empty.
          return true;
        }
          vals.push(Drupal.t('@value', {
          '@value': Drupal.truncate($(this).val(), 60) || Drupal.t('None')
        }));
      });
      if (vals.length === 0) {
        return Drupal.t('NONE');
      }
      else {
        return vals.join('<br />');
      }
    });
  }
};

/**
 * Encode special characters in a plain-text string for display as HTML.
 */
Drupal.truncate = function (str, limit) {
  if (str.length > limit) {
    return str.substr(0, limit) + '...';
  }
  else {
    return str;
  }
};

})(jQuery);
