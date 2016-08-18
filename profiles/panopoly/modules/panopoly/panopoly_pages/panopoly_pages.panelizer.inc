<?php
/**
 * @file
 * panopoly_pages.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function panopoly_pages_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'panopoly_landing_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:panopoly_landing_page:default';
  $panelizer->css_id = '';
  $panelizer->css_class = 'panopoly-landing-page';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'ipe';
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
  $display->title = '%node:title';
  $display->uuid = '5464da8b-9174-42e0-9e98-90cca0a8c98f';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:panopoly_landing_page:default';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:panopoly_landing_page:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'panopoly_page';
  $panelizer->access = '';
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:panopoly_page:default';
  $panelizer->css_id = 'page-page';
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
  $display->layout = 'radix_bryant';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '16346c80-6fcf-4cee-bf7a-9c0173fc2916';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:panopoly_page:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-34b4f35e-bc4b-4819-905c-6b6bf84bffe1';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_link' => 'content',
      'image_style' => 'panopoly_image_half',
    ),
    'context' => 'panelizer',
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
  $pane->uuid = '34b4f35e-bc4b-4819-905c-6b6bf84bffe1';
  $display->content['new-34b4f35e-bc4b-4819-905c-6b6bf84bffe1'] = $pane;
  $display->panels['contentmain'][0] = 'new-34b4f35e-bc4b-4819-905c-6b6bf84bffe1';
  $pane = new stdClass();
  $pane->pid = 'new-59cafe99-f0a0-4a3a-a13f-8f108d69d18b';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '250',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
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
  $pane->uuid = '59cafe99-f0a0-4a3a-a13f-8f108d69d18b';
  $display->content['new-59cafe99-f0a0-4a3a-a13f-8f108d69d18b'] = $pane;
  $display->panels['contentmain'][1] = 'new-59cafe99-f0a0-4a3a-a13f-8f108d69d18b';
  $pane = new stdClass();
  $pane->pid = 'new-f3bf9c22-9b22-41d2-a57e-110951093871';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'featured',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f3bf9c22-9b22-41d2-a57e-110951093871';
  $display->content['new-f3bf9c22-9b22-41d2-a57e-110951093871'] = $pane;
  $display->panels['contentmain'][2] = 'new-f3bf9c22-9b22-41d2-a57e-110951093871';
  $pane = new stdClass();
  $pane->pid = 'new-0a2c7b96-5f45-4e85-8e00-88fee50f4f71';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
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
  $pane->uuid = '0a2c7b96-5f45-4e85-8e00-88fee50f4f71';
  $display->content['new-0a2c7b96-5f45-4e85-8e00-88fee50f4f71'] = $pane;
  $display->panels['contentmain'][3] = 'new-0a2c7b96-5f45-4e85-8e00-88fee50f4f71';
  $pane = new stdClass();
  $pane->pid = 'new-c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1';
  $pane->panel = 'sidebar';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'main-menu',
    'parent_mlid' => '0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '2',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 1,
    'sort' => 0,
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
  $pane->uuid = 'c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1';
  $display->content['new-c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1'] = $pane;
  $display->panels['sidebar'][0] = 'new-c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-34b4f35e-bc4b-4819-905c-6b6bf84bffe1';
  $panelizer->display = $display;
  $export['node:panopoly_page:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'panopoly_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->name = 'node:panopoly_page:default:default';
  $panelizer->css_id = '';
  $panelizer->css_class = 'page-default';
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
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '10c9e351-f69c-4629-b191-77b8b01f4f1c';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:panopoly_page:default:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e0d93093-20b4-42cd-bf23-6f2f487240a6';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'panopoly_image_half',
      'image_link' => '',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e0d93093-20b4-42cd-bf23-6f2f487240a6';
  $display->content['new-e0d93093-20b4-42cd-bf23-6f2f487240a6'] = $pane;
  $display->panels['contentmain'][0] = 'new-e0d93093-20b4-42cd-bf23-6f2f487240a6';
  $pane = new stdClass();
  $pane->pid = 'new-74f82699-93ba-4b15-8bcf-e3bfa1894d40';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '74f82699-93ba-4b15-8bcf-e3bfa1894d40';
  $display->content['new-74f82699-93ba-4b15-8bcf-e3bfa1894d40'] = $pane;
  $display->panels['contentmain'][1] = 'new-74f82699-93ba-4b15-8bcf-e3bfa1894d40';
  $pane = new stdClass();
  $pane->pid = 'new-96fb1bf5-7ac2-4566-9dae-876a363c71c9';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'default',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '96fb1bf5-7ac2-4566-9dae-876a363c71c9';
  $display->content['new-96fb1bf5-7ac2-4566-9dae-876a363c71c9'] = $pane;
  $display->panels['contentmain'][2] = 'new-96fb1bf5-7ac2-4566-9dae-876a363c71c9';
  $pane = new stdClass();
  $pane->pid = 'new-ade8f2e7-1173-418b-8f94-0a2d8f4cdb9d';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_link',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ade8f2e7-1173-418b-8f94-0a2d8f4cdb9d';
  $display->content['new-ade8f2e7-1173-418b-8f94-0a2d8f4cdb9d'] = $pane;
  $display->panels['contentmain'][3] = 'new-ade8f2e7-1173-418b-8f94-0a2d8f4cdb9d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:panopoly_page:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'panopoly_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'featured';
  $panelizer->name = 'node:panopoly_page:default:featured';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
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
      'column1' => NULL,
      'column2' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '5b7d08f9-c351-427e-8015-14433221537b';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:panopoly_page:default:featured';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-af46907d-aa25-43db-995b-b38f9174221e';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_link' => 'content',
      'image_style' => 'panopoly_image_half',
    ),
    'context' => 'panelizer',
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
  $pane->uuid = 'af46907d-aa25-43db-995b-b38f9174221e';
  $display->content['new-af46907d-aa25-43db-995b-b38f9174221e'] = $pane;
  $display->panels['contentmain'][0] = 'new-af46907d-aa25-43db-995b-b38f9174221e';
  $pane = new stdClass();
  $pane->pid = 'new-1ee1b165-ebd0-4115-ad5e-49df79509f82';
  $pane->panel = 'contentmain';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 1,
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
  $pane->uuid = '1ee1b165-ebd0-4115-ad5e-49df79509f82';
  $display->content['new-1ee1b165-ebd0-4115-ad5e-49df79509f82'] = $pane;
  $display->panels['contentmain'][1] = 'new-1ee1b165-ebd0-4115-ad5e-49df79509f82';
  $pane = new stdClass();
  $pane->pid = 'new-a71dc705-b195-439c-b47b-980d8c7fa155';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_summary_or_trimmed',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '250',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
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
  $pane->uuid = 'a71dc705-b195-439c-b47b-980d8c7fa155';
  $display->content['new-a71dc705-b195-439c-b47b-980d8c7fa155'] = $pane;
  $display->panels['contentmain'][2] = 'new-a71dc705-b195-439c-b47b-980d8c7fa155';
  $pane = new stdClass();
  $pane->pid = 'new-1d6308c6-817d-4465-ac63-fa7acca627aa';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'featured',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '1d6308c6-817d-4465-ac63-fa7acca627aa';
  $display->content['new-1d6308c6-817d-4465-ac63-fa7acca627aa'] = $pane;
  $display->panels['contentmain'][3] = 'new-1d6308c6-817d-4465-ac63-fa7acca627aa';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:panopoly_page:default:featured'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'panopoly_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'teaser';
  $panelizer->name = 'node:panopoly_page:default:teaser';
  $panelizer->css_id = '';
  $panelizer->css_class = 'page-teaser';
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
  $display->title = '%node:title';
  $display->uuid = 'f76cbd0c-d182-4bd2-96f2-f1759b4e69d8';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:panopoly_page:default:teaser';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-873d60d8-f80e-41c1-b89d-86ad219285e8';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_link' => 'content',
      'image_style' => 'panopoly_image_quarter',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '873d60d8-f80e-41c1-b89d-86ad219285e8';
  $display->content['new-873d60d8-f80e-41c1-b89d-86ad219285e8'] = $pane;
  $display->panels['contentmain'][0] = 'new-873d60d8-f80e-41c1-b89d-86ad219285e8';
  $pane = new stdClass();
  $pane->pid = 'new-9363564d-7f96-4fa2-a1a5-5b0f5f60ce68';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_summary_or_trimmed',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '600',
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
  $pane->uuid = '9363564d-7f96-4fa2-a1a5-5b0f5f60ce68';
  $display->content['new-9363564d-7f96-4fa2-a1a5-5b0f5f60ce68'] = $pane;
  $display->panels['contentmain'][1] = 'new-9363564d-7f96-4fa2-a1a5-5b0f5f60ce68';
  $pane = new stdClass();
  $pane->pid = 'new-e7b29d80-ad23-4c5d-85fd-13f7a038e3d8';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'teaser',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e7b29d80-ad23-4c5d-85fd-13f7a038e3d8';
  $display->content['new-e7b29d80-ad23-4c5d-85fd-13f7a038e3d8'] = $pane;
  $display->panels['contentmain'][2] = 'new-e7b29d80-ad23-4c5d-85fd-13f7a038e3d8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:panopoly_page:default:teaser'] = $panelizer;

  return $export;
}
