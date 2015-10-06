(function($) {

  $(document).ready(function() {
      $("#kata-main-menu").sticky({ topSpacing: 0 });
    
    $('#main-menu a.sf-depth-1.active, #main-menu a.sf-depth-1.active-trail').parent().addClass('current');


    function tab_widget(tabid) {

      var $sidebarWidgets = $('.sidebar-widgets-wrap');
      var $footerWidgets = $('.footer-widgets-wrap');

      $(tabid + " .tab_content").hide();
      $(tabid + " ul.tabs li:first").addClass("active").show();
      $(tabid + " .tab_content:first").show();

      if (window.location.hash != '') {

        var getTabHash = window.location.hash;

        if ($(getTabHash).hasClass('tab_content')) {

          $(tabid + " ul.tabs li").removeClass("active");
          $(tabid + ' ul.tabs li a[data-href="' + getTabHash + '"]').parent('li').addClass("active");
          $(tabid + " .tab_content").hide();
          $(getTabHash + '.tab_content').show();

        }

      }

      $(tabid + " ul.tabs li").click(function() {

        $(tabid + " ul.tabs li").removeClass("active");
        $(this).addClass("active");
        $(tabid + " .tab_content").hide();
        var activeTab = $(this).find("a").attr("data-href");
        var $selectTab = $(this);
        $(activeTab).fadeIn(600, function() {
          if ($selectTab.parent().parent().hasClass("side-tabs")) {
            if ($(window).width() < 768) {
              if ($().scrollTo) {
                jQuery.scrollTo(activeTab, 400, {offset: -20});
              }
            }
          }
        });
        return false;

      });

    }

    tab_widget('#tabwidget-1');




    var clientsCarousel = $("#clients-scroller");

    clientsCarousel.carouFredSel({
      width: "100%",
      height: "auto",
      circular: false,
      responsive: true,
      infinite: false,
      auto: false,
      items: {
        width: 160,
        visible: {
          min: 1,
          max: 6
        }
      },
      scroll: {
        wipe: true
      },
      prev: {
        button: "#ourclients_prev",
        key: "left"
      },
      next: {
        button: "#ourclients_next",
        key: "right"
      },
      onCreate: function() {
        $(window).on('resize', function() {
          clientsCarousel.parent().add(clientsCarousel).css('height', clientsCarousel.children().first().outerHeight() + 'px');
        }).trigger('resize');
      }
    });


    var $faqItems = $('#faqs .faq');

    $('#portfolio-filter a').click(function() {

      $('#portfolio-filter li').removeClass('activeFilter');

      $(this).parent('li').addClass('activeFilter');

      var faqSelector = $(this).attr('data-filter');

      $faqItems.css('display', 'none');

      if (faqSelector != 'all') {

        $(faqSelector).fadeIn(500);

      } else {

        $faqItems.fadeIn(500);

      }

      return false;

    });



  }); // end document


})(jQuery);