(function($) {

/**
 * Attach this editor to a target element.
 */
Drupal.wysiwyg.editor.attach.markitup = function (context, params, settings) {
  $('#' + params.field, context).markItUp(settings);

  // Adjust CSS for editor buttons.
  $.each(settings.markupSet, function (button) {
    imgdir = (settings.markupSet[button].imageDir) ? settings.markupSet[button].imageDir : settings.root + 'sets/default/images/';
    imgfile = (settings.markupSet[button].imageFile) ? settings.markupSet[button].imageFile : button + '.png';
    if (this.className != 'markItUpSeparator') {
      $('.' + settings.nameSpace + ' .' + this.className + ' a')
        .css({ backgroundImage: 'url(' + imgdir + imgfile + ')' })
        .parents('li').css({ backgroundImage: 'none' });
    }
  });
};

/**
 * Detach a single or all editors.
 */
Drupal.wysiwyg.editor.detach.markitup = function (context, params, trigger) {
  if (trigger == 'serialize') {
    return;
  }
  $('#' + params.field, context).markItUpRemove();
};

Drupal.wysiwyg.editor.instance.markitup = {
  insert: function (content) {
    $.markItUp({ replaceWith: content });
  },

  setContent: function (content) {
    $('#' + this.field).val(content);
  },

  getContent: function () {
    return $('#' + this.field).val();
  }
};

})(jQuery);
