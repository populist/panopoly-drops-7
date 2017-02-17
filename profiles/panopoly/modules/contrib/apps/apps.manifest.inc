<?php

/**
 * @file
 * Handles pulling and processing of app data from the server
 */

/**
 * Return all local apps for the specified server.
 *
 * @param string $server
 *   A machine name for a server
 *
 * @return array
 *   An array of apps
 */
function apps_server_local($server) {
  $apps = array();
  $modules = system_rebuild_module_data();
  foreach ($modules as $module => $info) {
    // If an app is not limited to a specific server, or the limiting server
    // is this server.
    if (isset($info->info['apps']) && (!isset($info->info['apps']['server']) || $info->info['apps']['server'] == $server['name'])) {
      $manifest = $info->info['apps'];
      $app_path = drupal_get_path('module', $module);

      // Set some defaults, if needed.
      $manifest['machine_name'] = $module;
      $manifest['local'] = TRUE;
      if (!isset($manifest['name'])) {
        $manifest['name'] = $info->info['name'];
      }
      if (!isset($manifest['description'])) {
        $manifest['description'] = $info->info['description'];
      }
      if (!isset($manifest['version'])) {
        $manifest['version'] = $info->info['version'];
      }
      if (isset($manifest['screenshots'])) {
        foreach ($manifest['screenshots'] as $id => $image) {
          $manifest['screenshots'][$id] = $app_path . '/' . $image;
        }
      }
      if (isset($manifest['logo'])) {
        $manifest['logo'] = $app_path . '/' . $manifest['logo'];
      }
      $apps[$module] = $manifest;
    }
  }
  // Add a parent apps key for any apps this app depends on.
  foreach ($apps as $module => $info) {
    $apps[$module]['parent_apps'] = isset($apps[$module]['parent_apps']) ? $apps[$module]['parent_apps'] : array();
    if (!empty($modules[$module]->info['dependencies']) && ($parent_apps = array_intersect($modules[$module]->info['dependencies'], array_keys($apps)))) {
      $apps[$module]['parent_apps'] = array_merge($apps[$module]['parent_apps'], $parent_apps);
    }
  }
  return $apps;
}

/**
 * Returns all app servers configured to work for the current site.
 *
 * @param string $server_name
 *   Optional. The name of a specific server to return
 *
 * @return array
 *   An array of servers, or one server array if $server_name has a valid value
 */
function apps_servers($server_name = FALSE) {
  $servers_cache = cache_get('apps_servers');
  $servers = $servers_cache ? $servers_cache->data : FALSE;
  if (!$servers) {
    $profile = drupal_get_profile();
    // Get apps servers from profile.
    $servers = ($s = module_invoke($profile, 'apps_servers_info')) ? $s : array();
    // Allow modules to add apps servers as well.
    $servers += module_invoke_all('apps_servers_info');

    drupal_alter('apps_servers', $servers);

    foreach ($servers as $name => $server) {
      $servers[$name]['name'] = $name;
    }
  }
  // If we have the dev console turned on add it as a server.
  if (variable_get('apps_enable_dev_console', FALSE)) {
    $servers['development'] = array(
      'name' => 'development',
      'description' => 'Local Apps in Development',
      'title' => 'Development',
      'manifest' => FALSE,
      'featured app' => FALSE,
    );
  }
  cache_set('apps_servers', $servers);
  if ($server_name) {
    if (isset($servers[$server_name])) {
      return $servers[$server_name];
    }
  }
  else {
    return $servers;
  }
  return FALSE;
}

/**
 * Retrieve apps from the server manifest.
 *
 * @param string $server
 *   A server object return from apps_servers
 * @param arrray $condition
 *   An array of key/values to filter the apps
 * @param bool $add_theme
 *   If TRUE apps_apps_add_theme will be called when done getting apps
 *
 * @return array
 *   An array of app info arrays
 */
function apps_apps($server, $condition = array(), $add_theme = FALSE) {
  if (!is_array($server)) {
    $server = apps_servers($server);
  }
  $manifest = apps_manifest($server);
  if (isset($manifest['error'])) {
    $e = new Exception($manifest['error']);
    $e->request = $manifest['request'];
    throw $e;
  }
  $apps = $manifest['apps'];
  foreach ($apps as $id => $app) {
    $intersect = array_intersect_assoc($app, $condition);
    if ($intersect !== $condition) {
      unset($apps[$id]);
    }
  }
  if (!empty($apps) && $add_theme) {
    apps_apps_add_theme($apps);
  }
  return $apps;
}

/**
 * Retrieve apps from all servers.
 *
 * @param arrray $condition
 *   An array of key/values to filter the apps
 * @param bool $add_theme
 *   If TRUE apps_apps_add_theme will be called when done getting apps
 *
 * @return array
 *   An array of app info arrays
 */
function apps_apps_all($condition = array(), $add_theme = FALSE) {
  $apps = array();
  foreach (apps_servers() as $app_server) {
    $apps = array_merge($apps, apps_apps($app_server, $condition, $add_theme));
  }
  return $apps;
}

/**
 * Changes the apps array by reference.
 *
 * Adds #theme properties for a list view of the apps.
 *
 * @param array $apps
 *   array of apps from apps_apps
 */
function apps_apps_add_theme(&$apps) {
  foreach ($apps as $id => $app) {
    // Add teaser theme,
    $apps[$id]['#theme'] = 'apps_app_teaser';
    // Add style name for image_style theming.
    if (!empty($apps[$id]['logo'])) {
      $apps[$id]['logo']['style_name'] = 'apps_logo';
    }
  }
  $apps['#theme'] = 'apps_list';
}

/**
 * Add function description.
 *
 * @todo Document function.
 *
 * @return null|string
 *   returns null or client ID
 */
function apps_client_id() {
  $id = variable_get('apps_client_id', FALSE);
  if (!$id) {
    $id = uniqid(rand(0, 10000), TRUE);
    variable_set('apps_client_id', $id);
  }
  return $id;

}

/**
 * Request manifest and media assets from the app server.
 *
 * @param string $server
 *   A server array
 *
 * @return array
 *   An array representation of the json manifest, with images replaced by
 *   file objects.
 */
function apps_request_manifest($server) {
  if ($cache = cache_get("apps_manifest_{$server['name']}")) {
    return $cache->data;
  }

  // Gather all local apps.
  $local_apps = apps_server_local($server);
  $manifest = $server;
  $manifest['apps'] = $local_apps;

  // If there is no remote server, or we're in offline mode, stop here.
  if (!$server['manifest'] || variable_get('apps_offline_mode', FALSE)) {
    apps_request_manifest_image_process($manifest);
    return $manifest;
  }

  // Now process remote apps.
  $info = drupal_parse_info_file(dirname(__FILE__) . '/apps.info');
  $rest_data = array(
    'client_id' => apps_client_id(),
    'apps_version' => isset($info['version']) ? $info['version'] : NULL,
    'format' => 'json',
  ) + $server;

  $url = url($server['manifest'], array('query' => $rest_data));
  $request = drupal_http_request($url);

  if (isset($request->error)) {
    $msg = t("Manifest error from @server: @error", array('@server' => $server['title'], '@error' => $request->error));
    watchdog("apps", $msg);
    drupal_set_message($msg, 'warning');
  }
  elseif ($remote_manifest = json_decode($request->data, TRUE)) {
    // Translate index to machine name.
    foreach ($remote_manifest['apps'] as $index => $app) {
      // App server has a bug where it puts the server base url for blank logos.
      if (strpos($server['manifest'], $app['logo']) === 0) {
        unset($app['logo']);
      }
      // If it is already a local app, note the remote version.
      if (array_key_exists($app['machine_name'], $manifest['apps'])) {
        $manifest['apps'][$app['machine_name']]['remote manifest'] = $app;
        // Override app info with remote information.
        $manifest['apps'][$app['machine_name']] = $app + $manifest['apps'][$app['machine_name']];
      }
      // Else translate index to machine name.
      else {
        $remote_manifest['apps'][$app['machine_name']] = $app;
        $remote_manifest['apps'][$app['machine_name']]['remote'] = TRUE;
      }
      unset($remote_manifest['apps'][$index]);
    }
    $manifest['apps'] = array_merge($remote_manifest['apps'], $manifest['apps']);
  }
  else {
    $msg = t("Manifest JSON from @server not parsable", array('@server' => $server['title']));
    watchdog("apps", $msg);
    drupal_set_message($msg, 'warning');
  }
  apps_request_manifest_image_process($manifest);
  cache_set("apps_manifest_{$server['name']}", $manifest, 'cache', REQUEST_TIME + 60 + 30);

  return $manifest;
}

/**
 * Process images and size with images styles.
 *
 * Process images (logo and screenshots) so that they can be sized with image
 * styles.
 *
 * @param array $manifest
 *   An app manifest for a server
 */
function apps_request_manifest_image_process(&$manifest) {
  foreach ($manifest['apps'] as $id => &$app) {
    if (isset($app['logo'])) {
      $app['logo'] = apps_retrieve_app_image($id, $app['logo'], t("@name Logo", array('@name' => $app['name'])));
    }

    if (isset($app['screenshots'])) {
      foreach ($app['screenshots'] as $index => $url) {
        $name = isset($app['name']) ? $app['name'] : $manifest['name'];
        $screenshot = apps_retrieve_app_image($id, $url, t("@name Screenshot @index", array('@name' => $name, '@index' => $index)));

        if (!empty($screenshot)) {
          $app['screenshots'][$index] = $screenshot;
        }
        else {
          unset($app['screenshots'][$index]);
        }
      }
    }
  }
}

/**
 * Retrieve the image from the manifest.
 *
 * @param string $app
 *   The app machine name
 * @param string $url
 *   The url or local path of the image
 * @param string $title
 *   The title of the image
 * @param string $alt
 *   The alt text of the image
 *
 * @return array
 *   A file object for the download file or FALSE if no image was downloaded
 */
function apps_retrieve_app_image($app, $url, $title = '', $alt = '') {
  // Allow for local files.
  $check = parse_url($url);
  $is_local = FALSE;
  if (!$check || !isset($check['host']) || !$check['host']) {
    $old_url = $url;
    // Quick check that file exists
    if (!file_exists($old_url)) {
      return FALSE;
    }
    $url = file_create_url($url);
    $is_local = TRUE;
  }

  $url_parts = explode("/", parse_url($url, PHP_URL_PATH));
  $file_name = array_pop($url_parts);

  $dir = "apps/$app";
  $uri = file_build_uri("$dir/$file_name");
  $current = FALSE;

  $fids = db_select('file_managed', 'f')
    ->condition('uri', $uri)
    ->fields('f', array('fid'))
    ->execute()
    ->fetchCol();

  if (!empty($fids) && isset($fids[0]) && is_numeric($fids[0])) {
    $current = file_load($fids[0]);
  }

  // Check to see if the remote file is newer than the one that.
  // We have and that the one we have still exists.
  if ($current && file_exists($current->uri)) {
    if ($is_local) {
      $use_current = filemtime($old_url) <= $current->timestamp && $current->filesize == filesize($old_url);
    }
    else {
      // Get the remote headers.
      $remote = drupal_http_request($url, array('method' => 'HEAD'));
      $remote = $remote->headers;
      $use_current = !empty($remote['last-modified']) && strtotime($remote['last-modified']) <= $current->timestamp
        && !empty($remote['content-length']) && $remote['content-length'] == $current->filesize;
    }

    if ($use_current) {
      $current->path = $current->uri;
      $current->title = !empty($title) ? $title : '';
      $current->alt = !empty($alt) ? $alt : $title;
      return (array) $current;
    }
  }

  $request = drupal_http_request($url, array(), 'GET');
  if (isset($request->data) && $request->code == 200) {
    $dir_uri = file_build_uri($dir);
    file_prepare_directory($dir_uri, FILE_CREATE_DIRECTORY || FILE_MODIFY_PERMISSIONS);

    $file = new stdClass();
    $file->filemime = $request->headers['content-type'];
    $file->uri = file_unmanaged_save_data($request->data, $uri, FILE_EXISTS_REPLACE);
    if (empty($file->uri)) {
      watchdog('apps', 'unable to save to @file', array('@file' => $uri));
      return FALSE;
    }
    if ($current) {
      $file->fid = $current->fid;
    }
    $file->title = !empty($title) ? $title : '';
    $file->alt = !empty($alt) ? $alt : $file->title;
    $file->filename = $file_name;
    $file->status = 1;
    file_save($file);
    $file->path = $file->uri;
    return (array) $file;
  }
  return FALSE;
}

/**
 * Produce the Process Manifest.
 *
 * Starting with the json manifest and adding data around the current status of
 * the app in this install
 *
 * @param $server stdClass
 *   object server object returned from apps_servers
 *
 * @return array
 *   An array of the process json manifest
 *
 * @TODO: Cache status data and clear on changes to any module status
 */
function apps_manifest($server) {
  $manifests =& drupal_static(__FUNCTION__);
  require_once DRUPAL_ROOT . '/includes/install.inc';
  if (empty($manifests[$server['name']]) && !isset($manifests[$server['name']]['error'])) {

    // Get the manifest for apps for this server
    $manifest = apps_request_manifest($server);

    //if there is an error with the manifest jump out now
    if (isset($manifest['error'])) {
      return $manifest;
    }
    $modules = system_rebuild_module_data();
    $apps = array();
    foreach ($manifest['apps'] as $machine_name => $app) {
      $current_app_module = isset($modules[$machine_name]) ? $modules[$machine_name] : FALSE;
      $app_info = isset($modules[$machine_name]) ? drupal_parse_info_file(drupal_get_path('module', $machine_name) . '/' . APPS_APP_INFO) : array();
      $app['enabled'] = $current_app_module && $current_app_module->status;
      $app['incompatible'] = FALSE;
      $app['installed'] = (bool) $current_app_module;
      $app['installed_version'] = isset($app_info['version']) ? $app_info['version'] : (isset($current_app_module->info['version']) ? $current_app_module->info['version'] : NULL);
      $app['upgradeable'] = $app['installed'] && $app['installed_version'] && version_compare($app['installed_version'], $app['version'], 'lt');
      $app['dep_installed'] = TRUE;
      $app['disabled'] = $current_app_module && empty($current_app_module->status) && $current_app_module->schema_version > SCHEMA_UNINSTALLED;
      $app['featured'] = isset($manifest['featured app']) && ($machine_name == $manifest['featured app']);
      $app['server'] = $server;
      $app['dependencies'] = isset($app['dependencies']) ? $app['dependencies'] : array();
      $app['libraries'] = isset($app['libraries']) ? $app['libraries'] : array();
      $app['conflicts'] = isset($app['conflicts']) ? $app['conflicts'] : array();
      // Add info to dependencies
      foreach ($app['dependencies'] as $name_version => $downloadable) {
        // Parse dep versions
        $version = drupal_parse_dependency($name_version);
        // While the version compdability string is stored in $name_version
        // the current version may be in downloadables. Ignore 1.x type versions.
        $version['version'] = NULL;
        if (($space_pos = strpos($downloadable, ' ')) && substr($downloadable, -1) != 'x') {
          $version['version'] = trim(substr($downloadable, $space_pos));
        }
        $name = $version['name'];

        // Check status of modules
        $current = isset($modules[$name]) ? $modules[$name] : FALSE;
        $incompatible = $current ? (bool) drupal_check_incompatibility($version, str_replace(DRUPAL_CORE_COMPATIBILITY . '-', '', $current->info['version'])) : FALSE;
        $installed = (bool) $current;
        $enabled = $current && $current->status;
        $status = $incompatible ? APPS_INCOMPATIBLE : (!$installed ? APPS_INSTALLABLE : ($enabled ? APPS_ENABLED : APPS_DISABLED));

        if ($status == APPS_INCOMPATIBLE) {
          // If any one module is incompatible then the app is incompatible
          $app['incompatible'] = TRUE;
        }
        if ($status == APPS_INSTALLABLE) {
          // If any one module is installable then we are not installed yet
          $app['dep_installed'] = FALSE;
        }
        // Rebuild dep with new data
        $info = array(
          'downloadable' => $downloadable,
          'version' => $version,
          'status' => $status,
          'incompatible' => $incompatible,
          'enabled' => $enabled,
          'installed' => $installed,
        );
        unset($app['dependencies'][$name_version]);
        $app['dependencies'][$version['name']] = $info;
      }
      if (isset($app['libraries'])) {
        $profile = variable_get('install_profile', 'standard');
        $profile_path = drupal_get_path('profile', $profile);
        foreach ($app['libraries'] as $name_version => $downloadable) {
          // While the version compdability string is stored in $name_version
          // the current version may be in downloadables. Ignore 1.x type versions.
          $current_version = NULL;
          if (($space_pos = strpos($downloadable, ' ')) && substr($downloadable, -1) != 'x') {
            $current_version = trim(substr($downloadable, $space_pos));
          }
          $info = array(
            'downloadable' => $downloadable,
            'version' => array('name' => $name_version, 'version' => $current_version),
            'status' => APPS_INSTALLABLE,
            'incompatible' => 0,
            'enabled' => 0,
            'installed' =>  is_dir(DRUPAL_ROOT . "/sites/all/libraries/$name_version") || is_dir($profile_path . "/libraries/$name_version"),
          );
          $app['libraries'][$name_version] = $info;
        }
      }
      $app['status'] = $app['incompatible'] ? APPS_INCOMPATIBLE : (!$app['installed'] || !$app['dep_installed'] ? APPS_INSTALLABLE : ($app['enabled'] ? APPS_ENABLED : APPS_DISABLED));
      $apps[$machine_name] = $app;
    }
    // Override json apps with our enhanced apps
    apps_add_app_info($apps);
    $manifest['apps'] = $apps;
    $manifests[$server['name']] = $manifest;
  }
  return $manifests[$server['name']];
}

/**
 * @TODO: Add function description
 *
 * @param $apps
 */
function apps_add_app_info(&$apps) {
  $info_cache = cache_get("apps_installed_app_info");
  $info = array();
  if ($info_cache) {
    $info = $info_cache->data;
  }
  $set_cache = FALSE;
  foreach ($apps as $id => $app) {
    if (!isset($info[$app['machine_name']])) {
      $info[$app['machine_name']] = array();
      // Check if app is local.
      $module_cache = system_rebuild_module_data();
      if (isset($module_cache[$app['machine_name']])) {
        if (!module_exists($app['machine_name'])) {
          // Module is in the codebase but not installed.
          module_load_include('module', $app['machine_name']);
          module_load_include('app.inc', $app['machine_name']);
        }
        $info[$app['machine_name']] = ($i = module_invoke($app['machine_name'], 'apps_app_info')) ? $i : array();
      }
      $set_cache = TRUE;
    }
    $apps[$id] += $info[$app['machine_name']];
    // Add defaults
    $info_defaults = array(
      'configure form' => $app['machine_name'] . "_apps_app_configure_form",
      'demo content description' => "Enabling the demo content will add content to the site that can help to understand how the app functions.  When it is disabled all of the demo content will be removed.",
      'parent_apps' => array(),
    );
    $apps[$id] += $info_defaults;
    if (!empty($app['dependencies']) && ($parent_apps = array_intersect_key($app['dependencies'], $apps))) {
      $apps[$id]['parent_apps'] = array_merge($apps[$id]['parent_apps'], $parent_apps);
    }

    // Set demo content callbacks if demo content module is set
    if (isset($apps[$id]['demo content module'])) {
      $apps[$id] += array(
        'demo content enabled callback' => 'apps_demo_content_enabled',
        'demo content enable callback' => 'apps_demo_content_enable',
        'demo content disable callback' => 'apps_demo_content_disable',
      );
    }
    // Turn conflicts into array('server' => 'server', name => 'name') as needed.
    foreach ($app['conflicts'] as $conflict_key => $conflict) {
      if (is_string($conflict) && strpos($conflict, ' ')) {
        $conflict = explode(' ', $conflict);
        $apps[$id]['conflicts'][$conflict_key] = array('server' => $conflict[0], 'name' => $conflict[1]);
      }
      elseif (is_string($conflict)) {
        $apps[$id]['conflicts'][$conflict_key] = array('name' => $conflict);
      }
      // Set server to this app's server if empty
      if (empty($apps[$id]['conflicts'][$conflict_key]['server'])) {
        $apps[$id]['conflicts'][$conflict_key]['server'] = $app['server']['name'];
      }
      // Mark as incompatible if enabled conflict.
      // Not checking other servers due to risk of timing issues/endless loop.
      if ($apps[$id]['conflicts'][$conflict_key]['server'] == $app['server']['name'] && !empty($apps[$app['server']['name']]) && $apps[$app['server']['name']]['status'] == APPS_ENABLED) {
        $apps[$id]['status'] = APPS_INCOMPATIBLE;
      }
    }
  }
  if ($set_cache) {
    cache_set("apps_install_app_info", $info);
  }
}

/**
 * Find an App callback and ensure the proper file is required.
 *
 * @param $app
 *    The app
 * @param $key
 *    The call back key
 * @return string
 *    The callback function on the given App for the provided key
 */
function apps_app_callback($app, $key) {
  module_load_include("inc", $app['machine_name'], $app['machine_name'] . ".app");
  if (isset($app['file'])) {
    require_once $app['file'];
  }
  if (isset($app[$key]) && module_exists($app['machine_name']) && function_exists($app[$key])) {
    return $app[$key];
  }
}


/**
 * Checks if the apps demo content module is enabled
 *
 * @param $app array: an app array
 *
 * @return bool if the module was enabled
 */
function apps_demo_content_enabled($app) {
  return (module_exists($app['demo content module']));
}

/**
 * Enables the app's demo content module
 *
 * @param $app array: an app array
 *
 * @return bool if the module was enabled
 */
function apps_demo_content_enable($app) {
  $success = module_enable(array($app['demo content module']));
  drupal_flush_all_caches();
  return $success;
}

/**
 * Disables the app's demo content module
 *
 * @param $app array: an app array
 *
 * @return bool if the module was disabled
 */
function apps_demo_content_disable($app) {
  $success = module_disable(array($app['demo content module']));
  drupal_flush_all_caches();
  return !apps_demo_content_enabled($app);
}

/**
 * Form callback for demo content
 *
 * @param $form
 * @param $form_state
 * @param $app
 *
 * @return array
 */
function apps_demo_content_form($form, &$form_state, $app) {
  $form = array();
  $cb = apps_app_callback($app, 'demo content enabled callback');
  $enabled = $cb($app);
  $form['demo_content_group'] = array(
    '#type' => 'fieldset',
    '#title' => t("Demo Content for @app", array('@app' => $app['name'])),
  );
  $form['demo_content_group']['demo_content_current'] = array(
    '#markup' => filter_xss($app['demo content description'])
      . " <i>"
      . t("Demo content for @app is currently !state",  array('@app' => $app['name'], '!state' => ($enabled ? t('enabled') : t('disabled'))))
      . ".</i><br /><br />",
  );
  $form['demo_content_action'] = array(
    '#type' => 'value',
    '#value' => !$enabled,
  );
  $form['app'] = array(
    '#type' => 'value',
    '#value' => $app
  );

  $form['demo_content_group']['demo_content_button'] = array(
    '#type' => 'button',
    '#value' => !$enabled ? t('Enable Demo Content') : t('Disable Demo Content'),
    '#submit' => array('apps_demo_content_form_submit'),
    '#executes_submit_callback' => TRUE,
  );
  return $form;
}

/**
 * Submit handler for demo content form
 *
 * @param $form
 * @param $form_state
 */
function apps_demo_content_form_submit($form, &$form_state) {
  $app = $form_state['values']['app'];
  $enable = $form_state['values']['demo_content_action'];
  if ($enable) {
     $cb = apps_app_callback($app, 'demo content enable callback');
     $success = $cb($app);
     if ($success) {
       drupal_set_message(t("Enabled demo content for @app", array('@app' => $app['name'])));
     }
  }
  else {
     $cb = apps_app_callback($app, 'demo content disable callback');
     $success = $cb($app);
     if ($success) {
       drupal_set_message(t("Disabled demo content for  @app", array('@app' => $app['name'])));
     }
  }
}


