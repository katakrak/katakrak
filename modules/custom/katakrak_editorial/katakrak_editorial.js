(function ($) {
  Drupal.behaviors.katakrak_editorial = {
    attach: function (context, settings) {
      $('main.main').css('background-color', convertHex($('.color-fondo').html(), '30'));
       $('.imagen-autor-ed  img').each(function(index) {
          $(this).addClass('img-circle');
       });
       
       // quick search regex
        var qsRegex;

        // init Isotope
        var $grid = $('.grid').isotope({
          itemSelector: '.col',
          layoutMode: 'fitRows',
          filter: function() {
            return qsRegex ? $(this).text().match( qsRegex ) : true;
          }
        });
        

        // use value of search field to filter
        var $quicksearch = $('.quicksearch').keyup( debounce( function() {
          qsRegex = new RegExp( $quicksearch.val(), 'gi' );
          //$grid.isotope();
        }, 200 ) );
        
//        var $filterAutorTraductor = $('select.filter-autores-traductores').on('change', function() {
//           console.log('here we are');
//           $grid.isotope({ filter: '.traductor' });
//        });

        // debounce so filtering doesn't happen every millisecond
        function debounce( fn, threshold ) {
          var timeout;
          threshold = threshold || 100;
          return function debounced() {
            clearTimeout( timeout );
            var args = arguments;
            var _this = this;
            function delayed() {
              fn.apply( _this, args );
            }
            timeout = setTimeout( delayed, threshold );
          };
        }
    }
    
  };
})(jQuery);


function convertHex(hexCode,opacity){
    var hex = hexCode.replace('#','');

    if (hex.length === 3) {
        hex = hex[0] + hex[0] + hex[1] + hex[1] + hex[2] + hex[2];
    }

    var r = parseInt(hex.substring(0,2), 16),
        g = parseInt(hex.substring(2,4), 16),
        b = parseInt(hex.substring(4,6), 16);

    return 'rgba('+r+','+g+','+b+','+opacity/100+')';
}