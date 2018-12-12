<?php
/**
 * @file
 * panopoly_core.profile.inc
 */

/**
 * Task handler to set the language to English since that is the only one
 * we have at the moment.
 */
function panopoly_core_install_locale_selection(&$install_state) {
  $install_state['parameters']['locale'] = 'en';
}

/**
 * Task handler to load our install profile and enhance the dependency information
 */
function panopoly_core_install_load_profile(&$install_state) {

  // Loading the install profile normally
  install_load_profile($install_state);

  // Include any dependencies that we might have missed...
  $dependencies = $install_state['profile_info']['dependencies'];
  foreach ($dependencies as $module) {
    $module_info = drupal_parse_info_file(drupal_get_path('module', $module) . '/' . $module . '.info');
    if (!empty($module_info['dependencies'])) {
      foreach ($module_info['dependencies'] as $dependency) {
        $parts = drupal_parse_dependency($dependency);
        $dependencies[] = $parts['name'];
      }
    }
  }
  $install_state['profile_info']['dependencies'] = array_unique($dependencies);
}
