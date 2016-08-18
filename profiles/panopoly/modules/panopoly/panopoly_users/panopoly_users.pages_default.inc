<?php
/**
 * @file
 * panopoly_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function panopoly_users_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_user_login_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'user_login';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User Login Page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => 'user-login-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Log in',
    'panels_breadcrumbs_paths' => '',
    'panels_breadcrumbs_home' => 1,
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Log in';
  $display->uuid = 'ec9fdc25-413c-4023-bf92-7a2b2442bb74';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'pm_existing_pages_user_login_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-36405db8-54c5-495c-ba8a-0a5f7ade185a';
  $pane->panel = 'contentmain';
  $pane->type = 'pm_existing_pages';
  $pane->subtype = 'pm_existing_pages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    0 => 'task_id',
    'task_id' => 'user_login',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '36405db8-54c5-495c-ba8a-0a5f7ade185a';
  $display->content['new-36405db8-54c5-495c-ba8a-0a5f7ade185a'] = $pane;
  $display->panels['contentmain'][0] = 'new-36405db8-54c5-495c-ba8a-0a5f7ade185a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_user_login_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_user_password_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'user_password';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User Password Page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => 'user-password-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Log in Request Password',
    'panels_breadcrumbs_paths' => 'user/login',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'de3e6d95-c9f6-4a27-bfc6-c714ec502abc';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'pm_existing_pages_user_password_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-96bd66a6-0c13-490a-8e87-2ce6d4c87b52';
  $pane->panel = 'contentmain';
  $pane->type = 'pm_existing_pages';
  $pane->subtype = 'pm_existing_pages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    0 => 'task_id',
    'task_id' => 'user_password',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '96bd66a6-0c13-490a-8e87-2ce6d4c87b52';
  $display->content['new-96bd66a6-0c13-490a-8e87-2ce6d4c87b52'] = $pane;
  $display->panels['contentmain'][0] = 'new-96bd66a6-0c13-490a-8e87-2ce6d4c87b52';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_user_password_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_user_register_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'user_register';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User Register Page',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'css_id' => 'user-register-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Create an Account',
    'panels_breadcrumbs_paths' => '',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Create an Account';
  $display->uuid = 'ba74d07b-99c9-417c-b452-aa09928a10a6';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'pm_existing_pages_user_register_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f492afc2-f3d5-4ee4-9fa2-4029f6c7c3aa';
  $pane->panel = 'contentmain';
  $pane->type = 'pm_existing_pages';
  $pane->subtype = 'pm_existing_pages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    0 => 'task_id',
    'task_id' => 'user_register',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f492afc2-f3d5-4ee4-9fa2-4029f6c7c3aa';
  $display->content['new-f492afc2-f3d5-4ee4-9fa2-4029f6c7c3aa'] = $pane;
  $display->panels['contentmain'][0] = 'new-f492afc2-f3d5-4ee4-9fa2-4029f6c7c3aa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_user_register_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_edit_panel_context';
  $handler->task = 'user_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User Edit Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'user-edit',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '60334f70-29be-439e-8de7-da92ff5b4d94';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_edit_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4b6bfcfb-860f-42e5-b6a8-43cf7301d3e1';
  $pane->panel = 'contentmain';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_user_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4b6bfcfb-860f-42e5-b6a8-43cf7301d3e1';
  $display->content['new-4b6bfcfb-860f-42e5-b6a8-43cf7301d3e1'] = $pane;
  $display->panels['contentmain'][0] = 'new-4b6bfcfb-860f-42e5-b6a8-43cf7301d3e1';
  $pane = new stdClass();
  $pane->pid = 'new-be0c59f6-016f-4a3d-a888-dd3cf534796f';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'user:field_user_picture';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_user_edit_1',
    'override_title' => 1,
    'override_title_text' => 'User Picture',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'be0c59f6-016f-4a3d-a888-dd3cf534796f';
  $display->content['new-be0c59f6-016f-4a3d-a888-dd3cf534796f'] = $pane;
  $display->panels['sidebar'][0] = 'new-be0c59f6-016f-4a3d-a888-dd3cf534796f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4b6bfcfb-860f-42e5-b6a8-43cf7301d3e1';
  $handler->conf['display'] = $display;
  $export['user_edit_panel_context'] = $handler;

  return $export;
}
