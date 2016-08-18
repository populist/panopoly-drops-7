<?php
/**
 * @file
 * panopoly_admin.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function panopoly_admin_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Node Edit Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'node-edit',
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
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
    'sidebar' => array(
      'style' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '56f6d0a5-d0cb-4670-8442-80de25b84871';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-73569090-5f67-47b1-b6a5-634bc8104c2b';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_title';
  $pane->subtype = 'node_form_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
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
  $pane->uuid = '73569090-5f67-47b1-b6a5-634bc8104c2b';
  $display->content['new-73569090-5f67-47b1-b6a5-634bc8104c2b'] = $pane;
  $display->panels['contentmain'][0] = 'new-73569090-5f67-47b1-b6a5-634bc8104c2b';
  $pane = new stdClass();
  $pane->pid = 'new-17fa67de-e033-46f2-bdd8-a138e91da0e4';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_path';
  $pane->subtype = 'node_form_path';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '17fa67de-e033-46f2-bdd8-a138e91da0e4';
  $display->content['new-17fa67de-e033-46f2-bdd8-a138e91da0e4'] = $pane;
  $display->panels['contentmain'][1] = 'new-17fa67de-e033-46f2-bdd8-a138e91da0e4';
  $pane = new stdClass();
  $pane->pid = 'new-fb4920fb-24fa-425e-b6fc-958b5ccd2d52';
  $pane->panel = 'contentmain';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fb4920fb-24fa-425e-b6fc-958b5ccd2d52';
  $display->content['new-fb4920fb-24fa-425e-b6fc-958b5ccd2d52'] = $pane;
  $display->panels['contentmain'][2] = 'new-fb4920fb-24fa-425e-b6fc-958b5ccd2d52';
  $pane = new stdClass();
  $pane->pid = 'new-373bd769-1e08-4ec5-85b6-0a1d2fc759fd';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Featured image',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '373bd769-1e08-4ec5-85b6-0a1d2fc759fd';
  $display->content['new-373bd769-1e08-4ec5-85b6-0a1d2fc759fd'] = $pane;
  $display->panels['sidebar'][0] = 'new-373bd769-1e08-4ec5-85b6-0a1d2fc759fd';
  $pane = new stdClass();
  $pane->pid = 'new-51126c95-cf51-4ad6-a27a-11e4260d8023';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Content category',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '51126c95-cf51-4ad6-a27a-11e4260d8023';
  $display->content['new-51126c95-cf51-4ad6-a27a-11e4260d8023'] = $pane;
  $display->panels['sidebar'][1] = 'new-51126c95-cf51-4ad6-a27a-11e4260d8023';
  $pane = new stdClass();
  $pane->pid = 'new-99f6c0bd-36fd-411b-9833-c0be0fab7548';
  $pane->panel = 'sidebar';
  $pane->type = 'panelizer_form_default';
  $pane->subtype = 'panelizer_form_default';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '99f6c0bd-36fd-411b-9833-c0be0fab7548';
  $display->content['new-99f6c0bd-36fd-411b-9833-c0be0fab7548'] = $pane;
  $display->panels['sidebar'][2] = 'new-99f6c0bd-36fd-411b-9833-c0be0fab7548';
  $pane = new stdClass();
  $pane->pid = 'new-e38ab3a3-24d0-4ac2-900e-4ddb0248be0c';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_menu';
  $pane->subtype = 'node_form_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e38ab3a3-24d0-4ac2-900e-4ddb0248be0c';
  $display->content['new-e38ab3a3-24d0-4ac2-900e-4ddb0248be0c'] = $pane;
  $display->panels['sidebar'][3] = 'new-e38ab3a3-24d0-4ac2-900e-4ddb0248be0c';
  $pane = new stdClass();
  $pane->pid = 'new-9176b962-e64f-44a6-8ebe-e03ebf0f6c3d';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_publishing';
  $pane->subtype = 'node_form_publishing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9176b962-e64f-44a6-8ebe-e03ebf0f6c3d';
  $display->content['new-9176b962-e64f-44a6-8ebe-e03ebf0f6c3d'] = $pane;
  $display->panels['sidebar'][4] = 'new-9176b962-e64f-44a6-8ebe-e03ebf0f6c3d';
  $pane = new stdClass();
  $pane->pid = 'new-6e4a98d8-3738-41b9-8c33-4b4c905c6834';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_author';
  $pane->subtype = 'node_form_author';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '6e4a98d8-3738-41b9-8c33-4b4c905c6834';
  $display->content['new-6e4a98d8-3738-41b9-8c33-4b4c905c6834'] = $pane;
  $display->panels['sidebar'][5] = 'new-6e4a98d8-3738-41b9-8c33-4b4c905c6834';
  $pane = new stdClass();
  $pane->pid = 'new-c0926cca-059c-4bb1-bccd-2838ec7a93f2';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_buttons';
  $pane->subtype = 'node_form_buttons';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'c0926cca-059c-4bb1-bccd-2838ec7a93f2';
  $display->content['new-c0926cca-059c-4bb1-bccd-2838ec7a93f2'] = $pane;
  $display->panels['sidebar'][6] = 'new-c0926cca-059c-4bb1-bccd-2838ec7a93f2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fb4920fb-24fa-425e-b6fc-958b5ccd2d52';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function panopoly_admin_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panopoly_admin_layout_library';
  $page->task = 'page';
  $page->admin_title = 'Panopoly Layouts';
  $page->admin_description = 'This is the page library that manages page layouts.';
  $page->path = 'admin/panopoly/layouts';
  $page->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access administration pages',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer panels layouts',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Panopoly Layouts',
    'name' => 'management',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Dashboard',
      'name' => 'management',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panopoly_admin_layout_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panopoly_admin_layout_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Layout Library',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'layout-library',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'footer' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Layout Library';
  $display->uuid = '2a4bbcf3-712e-44e2-9fd8-270a2fd6e47d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_panopoly_admin_layout_library_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c481f523-51bb-40ff-99d3-648dc19100a5';
  $pane->panel = 'contentmain';
  $pane->type = 'panels_layouts';
  $pane->subtype = 'panels_layouts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c481f523-51bb-40ff-99d3-648dc19100a5';
  $display->content['new-c481f523-51bb-40ff-99d3-648dc19100a5'] = $pane;
  $display->panels['contentmain'][0] = 'new-c481f523-51bb-40ff-99d3-648dc19100a5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panopoly_admin_layout_library'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panopoly_admin_page_library';
  $page->task = 'page';
  $page->admin_title = 'Panopoly Pages';
  $page->admin_description = 'This is the page library that manages page templates, landing pages, and overridden pages.';
  $page->path = 'admin/panopoly/pages';
  $page->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access administration pages',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'use page manager',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Panopoly Pages',
    'name' => 'management',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Dashboard',
      'name' => 'management',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panopoly_admin_page_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panopoly_admin_page_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Page Library',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'page-library',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'footer' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Page Library';
  $display->uuid = '7f2efae5-50a7-4f07-b1f7-f8edc2dd9326';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_panopoly_admin_page_library_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b63313b3-8b80-4161-a97d-78439cda58f9';
  $pane->panel = 'contentmain';
  $pane->type = 'landing_pages';
  $pane->subtype = 'landing_pages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b63313b3-8b80-4161-a97d-78439cda58f9';
  $display->content['new-b63313b3-8b80-4161-a97d-78439cda58f9'] = $pane;
  $display->panels['contentmain'][0] = 'new-b63313b3-8b80-4161-a97d-78439cda58f9';
  $pane = new stdClass();
  $pane->pid = 'new-a19a23d5-56e9-48a3-82f2-bbdf49d4b929';
  $pane->panel = 'contentmain';
  $pane->type = 'overridden_page_templates';
  $pane->subtype = 'overridden_page_templates';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a19a23d5-56e9-48a3-82f2-bbdf49d4b929';
  $display->content['new-a19a23d5-56e9-48a3-82f2-bbdf49d4b929'] = $pane;
  $display->panels['contentmain'][1] = 'new-a19a23d5-56e9-48a3-82f2-bbdf49d4b929';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panopoly_admin_page_library'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panopoly_admin_pane_library';
  $page->task = 'page';
  $page->admin_title = 'Panopoly Panes';
  $page->admin_description = 'This is the pane library for the site. See all of the panes you can add to your pages.';
  $page->path = 'admin/panopoly/panes';
  $page->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access administration pages',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer page manager',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Panopoly Panes',
    'name' => 'management',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Dashboard',
      'name' => 'management',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panopoly_admin_pane_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panopoly_admin_pane_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Pane Library',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'pane-library',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'footer' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Pane Library';
  $display->uuid = '195ed3e8-b724-48fd-9057-9f5f54aa6a47';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_panopoly_admin_pane_library_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ad96a6eb-e0f3-44c3-b4ef-5d359f13c21a';
  $pane->panel = 'contentmain';
  $pane->type = 'general_panes';
  $pane->subtype = 'general_panes';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ad96a6eb-e0f3-44c3-b4ef-5d359f13c21a';
  $display->content['new-ad96a6eb-e0f3-44c3-b4ef-5d359f13c21a'] = $pane;
  $display->panels['contentmain'][0] = 'new-ad96a6eb-e0f3-44c3-b4ef-5d359f13c21a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panopoly_admin_pane_library'] = $page;

  return $pages;

}
