<?php
/**
 * @file
 * installer.inc hold all of the function used to download apps and thier deps
 */

/**
 * Download all modules and library to a temp location.
 *
 * Find all downloadables needed (which we do not have) and sets a batch for
 * download. Then proccess that batch and returns to the current
 * apps_install_next page
 *
 * @param string $app
 *   The app modules to download
 */
function apps_download_apps($app) {
  $download_batch = apps_download_apps_batch(array($app));
  batch_set($download_batch);
  batch_process($_SESSION['apps_install_next']);
}

/**
 * Make the batch for downloading modules for app.
 *
 * Split out for use in apps.profile.inc
 */
function apps_download_apps_batch($apps) {
  $download_commands = array();
  foreach ($apps as $app) {
    $downloads = apps_download_apps_list($app);
    foreach ($downloads as $download) {
      $download_commands[] = array(
        'apps_download_batch',
        array(
          $download['name'],
          $download['url'],
          $download['type'],
          $download['version'],
          $app,
        ),
      );
    }
  }
  $batch = array(
    'operations' => $download_commands,
    'file' => drupal_get_path('module', 'apps') . '/apps.installer.inc',
    'title' => t('Downloading modules'),
    'init_message' => t('Preparing to download needed modules'),
    'finished' => 'apps_download_batch_finished',
  );
  return $batch;
}

/**
 * Construct an array of downloadables to download.
 */
function apps_download_apps_list($app) {
  $downloads = array();
  $update = $app['installed'] && !empty($app['upgradeable']);
  // Find all downloads needed for dependencies.
  foreach (array('dependencies' => 'module', 'libraries' => 'library') as $download_key => $download_type) {
    if (!empty($app[$download_key])) {
      foreach ($app[$download_key] as $dep) {
        if (!$dep['installed'] || $update) {
          if ($dep['installed'] && $update && !empty($dep['version']['version'])) {
            $info_file_location = $download_type == 'module' ? drupal_get_path('module', $dep['version']['name'], FALSE) : 'sites/all/libraries/' . $dep['version']['name'];
            if ($info = drupal_parse_info_file($info_file_location . '/' . APPS_APP_INFO)) {
              // if don't have current version of version the same, skip this download.
              if (empty($info['version']) || $dep['version']['version'] == $info['version']) {
                continue;
              }
            }
          }
          $downloads[$dep['downloadable']]['for'][] = $dep['version']['name'];
          $downloads[$dep['downloadable']]['type'] = $download_type;
          $downloads[$dep['downloadable']]['version'] = isset($dep['version']['version']) ? $dep['version']['version'] : $app['version'];
        }
      }
    }
  }
  // Add our core modules download.
  if (!$app['installed'] || !empty($app['upgradeable'])) {
    $downloads[$app['downloadable']]['for'][] = $app['machine_name'];
    $downloads[$app['downloadable']]['type'] = 'app';
    $downloads[$app['downloadable']]['version'] = $app['version'];
  }
  // Foreach download find the URL.
  foreach ($downloads as $key => $download) {
    $downloads[$key]['url'] = $app['downloadables'][$key];
    // Do a quick dirty pull of the name from the key.
    $downloads[$key]['name'] = ($e = strpos($key, " ")) ? substr($key, 0, $e) : $key;
  }
  return $downloads;
}

/**
 * Batch callback invoked when the download batch is completed.
 *
 * A pass though to update_manager_download_batch_finished
 * but we set $_GET['destination'] to control the drupal_goto that is
 * in that function.
 */
function apps_download_batch_finished($success, $results) {
  module_load_include("inc", "update", "update.manager");
  $_GET['destination'] = $_SESSION['apps_install_next'];
  update_manager_download_batch_finished($success, $results);
}

/**
 * Setup the download batch process.
 *
 * Pass though to update_manager_batch_project_get we need this because in a
 * batch set the file param is for both the operations as well as the other
 * callbacks.
 */
function apps_download_batch($project, $url, $type, $version, $app, &$context) {
  module_load_include("inc", "update", "update.manager");

  // This is here to show the user that we are in the process of downloading.
  if (!isset($context['sandbox']['started'])) {
    $context['sandbox']['started'] = TRUE;
    $context['message'] = t('Downloading %project', array('%project' => $project));
    $context['finished'] = 0;
    return;
  }

  // Actually try to download the file.
  if (!($local_cache = update_manager_file_get($url))) {
    $context['results']['errors'][$project] = t('Failed to download %project from %url', array('%project' => $project, '%url' => $url));
    return;
  }

  // Extract it.
  $extract_directory = apps_extract_directory($type);
  try {
    update_manager_archive_extract($local_cache, $extract_directory);
  }
  catch (Exception $e) {
    $context['results']['errors'][$project] = $e->getMessage();
    return;
  }
  // Update might not have been extracted to directory named after project.
  // Github for example extracts to [project name]-[release version].
  if (!is_dir("$extract_directory/$project")) {
     foreach (scandir("$extract_directory") as $file) {
      // Hopefully this is the directory, so move it to project directory for
      // update module.
      if ($file != '.' && $file != '..' && is_dir("$extract_directory/$file") && strpos($file, $project) === 0) {
        rename("$extract_directory/$file", "$extract_directory/$project");
      }
    }
  }

  // Update/create info file with download information for future updating.
  if (is_dir("$extract_directory/$project")) {
    // Need to make version is set.
    $add = array('; Information created by apps module.', '');
    $add[] = 'version = ' . $version;
    $add[] = 'source_app = ' . $app['machine_name'];
    $add[] = 'download_time = ' . time();
    $add[] = '';
    file_put_contents("$extract_directory/$project/" . APPS_APP_INFO, implode("\n", $add));
  }

  // Verify it.
  $archive_errors = update_manager_archive_verify($project, $local_cache, $extract_directory);
  $archive_errors = array();
  if (!empty($archive_errors)) {
    // We just need to make sure our array keys don't collide, so use the
    // numeric keys from the $archive_errors array.
    foreach ($archive_errors as $key => $error) {
      $context['results']['errors']["$project-$key"] = $error;
    }
    return;
  }

  // Yay, success.
  $context['results']['projects'][$type][$project] = $url;
  $context['finished'] = 1;
}

/**
 * Wrapper for _update_manager_extract_directory().
 *
 * Since libraries and modules can live in the same location, we need to
 * namespace the types so they don't collide like the colorbox module.
 */
function apps_extract_directory($type = '') {
  $directory = _update_manager_extract_directory();
  if ($type) {
    $directory .= '/' . $type;
    if (!file_exists($directory)) {
      mkdir($directory);
    }
  }
  return $directory;

}

/**
 * Move modules from there temp location in to the drupal tree.
 *
 * Taken from update_manager_update_ready_form_submit
 * we are using apps_run_install instead of update_authorize_run_update
 *
 * @TODO: Get the install to work when we do not own sites OPIC-377
 */
function apps_install_downloads() {
  module_load_include("inc", "update", "update.manager");
  if (!empty($_SESSION['update_manager_update_projects'])) {
    // Make sure the Updater registry is loaded.
    drupal_get_updaters();

    $updates = array();
    $project_types = $_SESSION['update_manager_update_projects'];
    foreach ($project_types as $type => $projects) {
      $directory = apps_extract_directory($type);
      foreach ($projects as $project => $url) {
        $project_location = $directory . '/' . $project;
        try {
          $updater = Updater::factory($project_location);
        }
        catch (Exception $e) {
          drupal_set_message(t('Error installing @project: @message', array('@project' => $project, '@message' => $e->getMessage())), 'error');
          return FALSE;
        }
  
        $project_real_location = drupal_realpath($project_location);
        $updates[] = array(
          'project' => $project,
          'updater_name' => get_class($updater),
          'local_url' => $project_real_location,
        );
      }
    }

    // If the owner of the last directory we extracted is the same as the
    // owner of our configuration directory (e.g. sites/default) where we're
    // trying to install the code, there's no need to prompt for FTP/SSH
    // credentials. Instead, we instantiate a FileTransferLocal and invoke
    // update_authorize_run_update() directly.
    if (apps_installer_has_write_access()) {
      module_load_include('inc', 'update', 'update.authorize');
      $filetransfer = new FileTransferLocal(DRUPAL_ROOT);
      // This is our change.
      apps_run_install($filetransfer, $updates);
      unset($_SESSION['update_manager_update_projects']);
    }
    // Otherwise, go through the regular workflow to prompt for FTP/SSH
    // credentials and invoke update_authorize_run_update() indirectly with
    // whatever FileTransfer object authorize.php creates for us.
    else {
      // Set the $_SESSION variables so that authorize form knows what to do
      // after authorization.
      system_authorized_init('apps_run_install', drupal_get_path('module', 'apps') . '/apps.installer.inc', array($updates), t('Update manager'));

      // Get the authorize form.
      require_once DRUPAL_ROOT . '/includes/authorize.inc';
      return drupal_get_form('authorize_filetransfer_form');
    }
  }
}


/**
 * The batch builder and processor for moving files to drupal.
 *
 * taken from update_authorize_run_update
 * builds a batch and process it for installing modules from the templocation
 */
function apps_run_install($filetransfer, $projects) {
  $operations = array();
  foreach ($projects as $project => $project_info) {
    $operations[] = array(
      'apps_update_authorize_batch_copy_project',
      array(
        $project_info['project'],
        $project_info['updater_name'],
        $project_info['local_url'],
        $filetransfer,
      ),
    );
  }

  $batch = array(
    'title' => t('Downloading apps'),
    'init_message' => t('Preparing to download apps.'),
    'operations' => $operations,
    'finished' => 'apps_update_authorize_update_batch_finished',
    'file' => drupal_get_path('module', 'apps') . '/apps.installer.inc',
  );

  batch_set($batch);
  // Invoke the batch via authorize.php.

  batch_process($_SESSION['apps_install_next']);
}

/**
 * Wrapper around update_authorize_update_batch_finished to include file.
 *
 * Since need to override update_authorize_batch_copy_project, need to have the
 * path be this file, so need the 'finished' operation to be in this file also.
 */
function apps_update_authorize_update_batch_finished($success, $results) {
  module_load_include('authorize.inc','update');
  update_authorize_update_batch_finished($success, $results);
}

/**
 * Copy of update_authorize_batch_copy_project cept override install_dir. 
 */
function apps_update_authorize_batch_copy_project($project, $updater_name, $local_url, $filetransfer, &$context) {
  module_load_include('authorize.inc','update');

  // Initialize some variables in the Batch API $context array.
  if (!isset($context['results']['log'])) {
    $context['results']['log'] = array();
  }
  if (!isset($context['results']['log'][$project])) {
    $context['results']['log'][$project] = array();
  }

  if (!isset($context['results']['tasks'])) {
    $context['results']['tasks'] = array();
  }

  // The batch API uses a session, and since all the arguments are serialized
  // and unserialized between requests, although the FileTransfer object itself
  // will be reconstructed, the connection pointer itself will be lost. However,
  // the FileTransfer object will still have the connection variable, even
  // though the connection itself is now gone. So, although it's ugly, we have
  // to unset the connection variable at this point so that the FileTransfer
  // object will re-initiate the actual connection.
  unset($filetransfer->connection);

  if (!empty($context['results']['log'][$project]['#abort'])) {
    $context['finished'] = 1;
    return;
  }

  $updater = new $updater_name($local_url);

  try {
    $args = array();
    if ($updater->isInstalled()) {
      // This is an update.
      $tasks = $updater->update($filetransfer, $args);
    }
    else {
      if ($updater_name == 'ModuleUpdater') {
        $args = array(
          'install_dir' => DRUPAL_ROOT . '/' . variable_get('apps_install_path', APPS_INSTALL_PATH),
        );
      }
      $tasks = $updater->install($filetransfer, $args);
    }
  }
  catch (UpdaterException $e) {
    _update_batch_create_message($context['results']['log'][$project], t('Error installing / updating'), FALSE);
    _update_batch_create_message($context['results']['log'][$project], $e->getMessage(), FALSE);
    $context['results']['log'][$project]['#abort'] = TRUE;
    return;
  }

  _update_batch_create_message($context['results']['log'][$project], t('Installed %project_name successfully', array('%project_name' => $project)));
  if (!empty($tasks)) {
    $context['results']['tasks'] += $tasks;
  }

  // This particular operation is now complete, even though the batch might
  // have other operations to perform.
  $context['finished'] = 1;
}

/**
 * Delete the update cache directories so clean update is run.
 */
function apps_clear_update_disk_cache() {
  file_unmanaged_delete_recursive(_update_manager_cache_directory(FALSE));
  file_unmanaged_delete_recursive(_update_manager_extract_directory(FALSE));
  // Recreate the directories.
  _update_manager_cache_directory();
   _update_manager_extract_directory();
}
