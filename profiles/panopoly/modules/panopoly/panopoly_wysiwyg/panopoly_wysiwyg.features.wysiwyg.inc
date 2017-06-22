<?php
/**
 * @file
 * panopoly_wysiwyg.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function panopoly_wysiwyg_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: panopoly_html_text.
  $profiles['panopoly_html_text'] = array(
    'format' => 'panopoly_html_text',
    'editor' => 'markitup',
    'settings' => array(
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'stroke' => 1,
          'link' => 1,
        ),
      ),
      'theme' => '',
      'language' => 'en',
      'css_setting' => 'theme',
      'css_path' => '',
    ),
    'preferences' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'add_to_summaries' => 0,
      'version' => '1.1.14',
    ),
    'name' => 'formatpanopoly_html_text',
  );

  // Exported profile: panopoly_wysiwyg_text.
  $profiles['panopoly_wysiwyg_text'] = array(
    'format' => 'panopoly_wysiwyg_text',
    'editor' => 'tinymce',
    'settings' => array(
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'underline' => 1,
          'strikethrough' => 1,
          'justifyleft' => 1,
          'justifycenter' => 1,
          'justifyright' => 1,
          'justifyfull' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'outdent' => 1,
          'indent' => 1,
          'undo' => 1,
          'redo' => 1,
          'unlink' => 1,
          'formatselect' => 1,
          'forecolor' => 1,
          'blockquote' => 1,
          'removeformat' => 1,
          'charmap' => 1,
        ),
        'fullscreen' => array(
          'fullscreen' => 1,
        ),
        'paste' => array(
          'pastetext' => 1,
          'pasteword' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'pdw' => array(
          'pdw_toggle' => 1,
        ),
        'spellchecker' => array(
          'spellchecker' => 1,
        ),
        'captionfilter' => array(
          'captionfilter' => 1,
        ),
        'drupal' => array(
          'media' => 1,
          'break' => 1,
        ),
      ),
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'css_setting' => 'theme',
      'css_path' => '',
      'theme_advanced_statusbar_location' => 'bottom',
      'theme_advanced_toolbar_location' => 'top',
      'theme_advanced_toolbar_align' => 'left',
      'theme_advanced_blockformats' => 'h1,h2,h3,h4,h5,h6',
      'theme_advanced_styles' => '',
      'theme_advanced_resizing' => 1,
    ),
    'preferences' => array(
      'add_to_summaries' => FALSE,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => '3.5.11',
    ),
    'name' => 'formatpanopoly_wysiwyg_text',
  );

  return $profiles;
}
