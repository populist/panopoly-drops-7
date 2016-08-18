<?php
/**
 * @file
 * panopoly_users.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function panopoly_users_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'user';
  $panelizer->panelizer_key = 'user';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'user:user:default';
  $panelizer->css_id = 'user-panel';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '51ca002d-c24e-4ba7-b2dd-d966ff32e4a3';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'user:user:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d76e85cd-4625-4a52-a17b-e5c65e1a0247';
  $pane->panel = 'column1';
  $pane->type = 'user_profile';
  $pane->subtype = 'user_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'panelizer',
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
  $pane->uuid = 'd76e85cd-4625-4a52-a17b-e5c65e1a0247';
  $display->content['new-d76e85cd-4625-4a52-a17b-e5c65e1a0247'] = $pane;
  $display->panels['column1'][0] = 'new-d76e85cd-4625-4a52-a17b-e5c65e1a0247';
  $pane = new stdClass();
  $pane->pid = 'new-23b1f4f1-cda8-42ca-880a-afc2ae92f3e9';
  $pane->panel = 'column2';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:field_user_picture';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'panopoly_image_full',
      'image_link' => '',
    ),
    'context' => 'panelizer',
    'override_title' => 1,
    'override_title_text' => '',
    'view_mode' => NULL,
    'widget_title' => NULL,
    'items_per_page' => NULL,
    'exposed' => array(
      'sort_by' => NULL,
      'sort_order' => NULL,
    ),
    'use_pager' => NULL,
    'pager_id' => NULL,
    'offset' => NULL,
    'link_to_view' => NULL,
    'more_link' => NULL,
    'path' => NULL,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '23b1f4f1-cda8-42ca-880a-afc2ae92f3e9';
  $display->content['new-23b1f4f1-cda8-42ca-880a-afc2ae92f3e9'] = $pane;
  $display->panels['column2'][0] = 'new-23b1f4f1-cda8-42ca-880a-afc2ae92f3e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['user:user:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'user';
  $panelizer->panelizer_key = 'user';
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->name = 'user:user:default:default';
  $panelizer->css_id = '';
  $panelizer->css_class = 'user-default';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7e27b449-64aa-41ce-86bd-4267def0c988';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'user:user:default:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7b58bea7-aa6f-4daa-9180-9eedc586bde2';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:field_user_about';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
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
  $pane->uuid = '7b58bea7-aa6f-4daa-9180-9eedc586bde2';
  $display->content['new-7b58bea7-aa6f-4daa-9180-9eedc586bde2'] = $pane;
  $display->panels['contentmain'][0] = 'new-7b58bea7-aa6f-4daa-9180-9eedc586bde2';
  $pane = new stdClass();
  $pane->pid = 'new-a48325fb-5137-4640-8fe6-9228d15745b4';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'user:summary';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'panelizer',
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
  $pane->uuid = 'a48325fb-5137-4640-8fe6-9228d15745b4';
  $display->content['new-a48325fb-5137-4640-8fe6-9228d15745b4'] = $pane;
  $display->panels['contentmain'][1] = 'new-a48325fb-5137-4640-8fe6-9228d15745b4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['user:user:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'user';
  $panelizer->panelizer_key = 'user';
  $panelizer->access = array();
  $panelizer->view_mode = 'featured';
  $panelizer->name = 'user:user:default:featured';
  $panelizer->css_id = '';
  $panelizer->css_class = 'user-featured';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '693a059f-078d-41ef-8c11-053b70a597d2';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'user:user:default:featured';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e8b46596-4bed-47f1-a75c-06bc20485822';
  $pane->panel = 'column2';
  $pane->type = 'token';
  $pane->subtype = 'user:name';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'sanitize' => 1,
    'context' => 'panelizer',
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
  $pane->uuid = 'e8b46596-4bed-47f1-a75c-06bc20485822';
  $display->content['new-e8b46596-4bed-47f1-a75c-06bc20485822'] = $pane;
  $display->panels['column2'][0] = 'new-e8b46596-4bed-47f1-a75c-06bc20485822';
  $pane = new stdClass();
  $pane->pid = 'new-2c851d0b-7ef1-4d7e-abd9-651846a2081b';
  $pane->panel = 'column2';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:field_user_about';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_summary_or_trimmed',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '300',
    ),
    'context' => 'panelizer',
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
  $pane->uuid = '2c851d0b-7ef1-4d7e-abd9-651846a2081b';
  $display->content['new-2c851d0b-7ef1-4d7e-abd9-651846a2081b'] = $pane;
  $display->panels['column2'][1] = 'new-2c851d0b-7ef1-4d7e-abd9-651846a2081b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['user:user:default:featured'] = $panelizer;

  return $export;
}
