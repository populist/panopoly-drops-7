<?php
/**
 * @file
 * Contains views_content_plugin_display_panel_pane class.
 */

/**
 * The plugin that handles a panel_pane.
 */
class panopoly_magic_plugin_display_panel_pane extends views_content_plugin_display_panel_pane {
  function option_definition() {
    $options = parent::option_definition();
    $options['allow']['contains']['panopoly_magic_display_type'] = array('default' => 'panopoly_magic_display_type');
    $options['allow']['contains']['panopoly_magic_view_mode'] = array('default' => 'panopoly_magic_view_mode');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    if ($form_state['section'] == 'allow') {
      $form['allow']['#options']['panopoly_magic_display_type'] = t('Display type override');
      $form['allow']['#options']['panopoly_magic_view_mode'] = t('View mode override');
    }
  }
}
