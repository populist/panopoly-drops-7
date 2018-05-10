<?php

/**
 * @file
 * API documentation for the Apps module.
 */

/*
 * Provides configuration information to the apps about an enabled app.
 *
 * One can register demo content as a separate module or as a set of callbacks.
 * hook_apps_app_info() is a hook that will only be called on app modules.
 *
 * @return array
 *   An array containing app configuration information.
 */
function hook_apps_app_info() {
  return array(
    // Demo Content.
    'demo content description' => 'This tells what add demo content will do it is placed on the configure form',
    // The preferred way for an app to provide demo content is to have a module
    // that when enabled will add demo content, and when disabled will removed
    // demo content.
    // This module should be a sub-module or part of the manifest dependent
    // modules.
    'demo content module' => 'appname_demo_content',

    // If the demo content is provided in a different way one should provide the
    // following callbacks:
    // - This callback should return TRUE if demo content is on.
    'demo content enabled' => 'appname_demo_content_enabled',
    // - This callback should turn on demo content and return TRUE.
    'demo content enable' => 'appname_demo_content_enable',
    // - This callback should turn off demo content and return TRUE.
    'demo content disable' => 'appname_demo_content_disable',

    // This form will be rendered on the app config page:
    'configure form' => 'appname_app_configure_form',
    'post install callback' => 'appname_app_post_install',
    // This will be called after the app is enabled initially or when the app
    // has been uninstalled.
    'status callback' => 'appname_app_status',
    // This will provide permission configuration on the configure form.
    // This will also set the permissions on install of the app.
    'permissions' => array(
      'access my app' => array('role 1', 'role 2'),
    ),
    // Same format as permissions but key includes [entity type]:[bundle] of the
    // the og group the permission should default for.
    'og permissions' => array(
      'node:group:create myapp content' => array('role 1', 'role 2'),
    ),
  );
  /*
  This callback is used to render a status table on the config page.
  It should be an array with two keys (and on optional third)
  array(
    'title' =>'Status'  // title of the table,
    'items' => array(  // rows in the table with any keys
      array(
        // REQUIREMENT_OK REQUIREMENT_INFO, REQUIREMENT_ERROR
        'severity' =>    REQUIREMENT_WARNING,
        'title' => 'Example',
        'description' => t("Instructions for Example"),
        'action' => array(l("Link to do something!", "")),
       ),
    ),
    // headers are optional but these are the default
    'headers' => array('severity', 'title', 'description', 'action')
  );
  */
}


/**
 * Provides server information to the apps.
 *
 * This hook is only called on the current profile.
 *
 * @return array
 *   An array of associative server arrays.
 */
function hook_apps_servers_info() {
  return array(
    'servername' => array(
      // The title to be used for the server.
      'title' => t('Store Title'),
      'description' => t('A description of the server and what apps it might have.'),
      // The location of the json manifest.
      'manifest' => 'http://apps.com/app/query',
    ),
  );
}

/**
 * Add an apps install step to an installation profile.
 *
 * Use this in your hook_install_tasks to add all the needed tasks for
 * installing apps. Set the App Server key and any default selected apps.
 *
 * @param array $install_state
 *        Install state to be passed to apps_profile_install_tasks().
 *
 * @return array
 *        Containing needed tasks.
 */
function hook_install_tasks($install_state) {
  $tasks = array();
  require_once drupal_get_path('module', 'apps') . '/apps.profile.inc';
  $server = array(
    'title' => 'App Server Name',
    'machine name' => 'apps_server_machine_name',
    'default apps' => array(
      'app_machine_name_1',
      'app_machine_name_2',
    ),
    'required apps' => array(),
    'default content callback' => 'distro_default_content',
  );
  $tasks = $tasks + apps_profile_install_tasks($install_state, $server);
  return $tasks;
}

/**
 * Called each time an app module is enabled.
 *
 * This hook is called from hook_modules_enabled when an app is enabled.
 * Not that the app array may be missing keys/information (due to
 * performance considerations).
 */
function hook_apps_app_modules_enabled($app) {
  if (!empty($app['something'])) {
    mymodule_something($app);
  }
}

/**
 * This is the structure of the json manifest.
 *
 * A local app can also be defined using the info file in the form:
 *  apps[name] = App name.
 * The same keys and information used below can be used for local apps.
 */

$js = <<<JS
{
  "distro": {
    "distros" : "openpublic",
    "core" : "7"
  },
  "featured app": "ideation",
  "manifest version": 1.0,
  "apps": [
    // This starts a single app manifest
    {
      // The Title of the app
      "name": "Ideation",
      // Description of what the app will do
      "description": "You think it, we log it",
      // The current version of the app
      "version" : "1.0-alpha",
      // Who created the app
      "author" : "Phase2 Technology",
      // Url of the creates site
     "author_url" : "http://www.phase2technology.com",
      // An array of screen shots for display on the detailed page
      "screenshots" : ["http://appserver.openpublicapp.com/sites/default/files/ideation-screenshot1.jpg"],
      // The logo image for the app
      "logo" : "http://drupal.org/files/images/ideation.jpg",
      // The machine_name of the main module
      "machine_name" : "ideation",
      // The key from the downloadables array for where to get the main module
      "downloadable" : "ideation 7.x",
      // A hash of dependant modules. The key is the machine name of the module. The value is the module
      // and a version specification. This uses the .info format for module dependencies.  The values in
      // this hash are the keys used in the downloadables hash later in the manifest.
      "dependencies": {
        "views": "views 7.x-1.0",
        "votingapi": "votingapi 7.x-2.4",
        "fivestar": "fivestar 6.x-2.x-dev"
      },
      // Libraries will be installed to sites/all/libraries/{key}. The values in this hash are the
      // keys used in the downloadables hash later in the manifest.
      "libraries": {
        "jquery_ideation": "jquery_ideation 1.0"
      }
      // Define conflicts that this app has with other apps.
      "conflicts": {
        "app_machine": "app_machine"
      }
      // A hash of resources to be downloaded. The key is used else where in the manifest. The value
      // should be a url to a publicly downloadable archive (tar gz zip)
      "downloadables": {
        "ideation 7.x" : "http://appserver.openpublicapp.com/sites/default/files/fserver/ideation-7.x.tgz",
        "jquery_ideation 1.0" : "http://appserver.openpublicapp.com/sites/default/files/fserver/jquery_ideation-1.0.tgz",
        "views 7.x.3.0-alpha1" : "http://ftp.drupal.org/files/projects/views-7.x-3.0-alpha1.tar.gz",
        "fivestar 6.x-2.x-dev" : "http://ftp.drupal.org/files/projects/fivestar-7.x-2.x-dev.tar.gz",
        "votingapi 7.x-2.4" : "http://ftp.drupal.org/files/projects/votingapi-7.x-2.4.tar.gz"
      }
      // Groups app with other apps from same server.
      "package": "Drupal"
    }
    // This ends a single app manifest
  ]
}


JS;
