(function ($) {
  Drupal.behaviors.setDropdownBack = {
    attach: function () {
      $('.top-bar-section .has-dropdown li.title.back a').each(function () {
        $(this).html('<i class="material-icons">keyboard_arrow_left</i>');
      });
    }
  };
})(jQuery);