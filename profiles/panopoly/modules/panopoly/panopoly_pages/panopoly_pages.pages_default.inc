<?php
/**
 * @file
 * panopoly_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function panopoly_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_landing_page';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Landing Edit Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'panopoly_landing_page' => 'panopoly_landing_page',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f9b8005f-1975-4cf6-b683-96ee55f9f3bb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_context_landing_page';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-976a2d37-be63-4e79-b68e-a1f0046e2493';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_title';
  $pane->subtype = 'node_form_title';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '976a2d37-be63-4e79-b68e-a1f0046e2493';
  $display->content['new-976a2d37-be63-4e79-b68e-a1f0046e2493'] = $pane;
  $display->panels['contentmain'][0] = 'new-976a2d37-be63-4e79-b68e-a1f0046e2493';
  $pane = new stdClass();
  $pane->pid = 'new-6cbb254d-cda4-45c6-9ee4-e54637d68e2b';
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
  $pane->uuid = '6cbb254d-cda4-45c6-9ee4-e54637d68e2b';
  $display->content['new-6cbb254d-cda4-45c6-9ee4-e54637d68e2b'] = $pane;
  $display->panels['contentmain'][1] = 'new-6cbb254d-cda4-45c6-9ee4-e54637d68e2b';
  $pane = new stdClass();
  $pane->pid = 'new-7ac7a702-b244-4d5f-9a69-62acf27fdb8c';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_menu';
  $pane->subtype = 'node_form_menu';
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
  $pane->uuid = '7ac7a702-b244-4d5f-9a69-62acf27fdb8c';
  $display->content['new-7ac7a702-b244-4d5f-9a69-62acf27fdb8c'] = $pane;
  $display->panels['contentmain'][2] = 'new-7ac7a702-b244-4d5f-9a69-62acf27fdb8c';
  $pane = new stdClass();
  $pane->pid = 'new-5a76829f-fb2b-4f02-9983-55136e36205a';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_buttons';
  $pane->subtype = 'node_form_buttons';
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
  $pane->uuid = '5a76829f-fb2b-4f02-9983-55136e36205a';
  $display->content['new-5a76829f-fb2b-4f02-9983-55136e36205a'] = $pane;
  $display->panels['contentmain'][3] = 'new-5a76829f-fb2b-4f02-9983-55136e36205a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-976a2d37-be63-4e79-b68e-a1f0046e2493';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_landing_page'] = $handler;

  return $export;
}
