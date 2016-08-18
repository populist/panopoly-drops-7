<?php
/**
 * @file
 * panopoly_core.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function panopoly_core_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'taxonomy_term';
  $panelizer->panelizer_key = 'panopoly_categories';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'taxonomy_term:panopoly_categories:default';
  $panelizer->css_id = 'taxonomy-term';
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
  $display->layout = 'radix_burr';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f460f0ba-59f1-4d87-a78c-22fac4b91ce7';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'taxonomy_term:panopoly_categories:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3386209f-d6b4-4941-ba89-a30ea33146ce';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'panopoly_taxonomy-taxonomy_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '10',
    'fields_override' => array(
      'field_featured_image' => 1,
      'title' => 1,
      'created' => 1,
      'name' => 0,
      'body' => 1,
    ),
    'exposed' => array(
      'widget_title' => '',
      'sort_by' => 'created',
      'sort_order' => 'DESC',
    ),
    'context' => array(
      0 => 'panelizer',
    ),
    'override_title' => '',
    'override_title_text' => '',
    'view_mode' => 'teaser',
    'widget_title' => NULL,
    'view_settings' => 'fields',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3386209f-d6b4-4941-ba89-a30ea33146ce';
  $display->content['new-3386209f-d6b4-4941-ba89-a30ea33146ce'] = $pane;
  $display->panels['contentmain'][0] = 'new-3386209f-d6b4-4941-ba89-a30ea33146ce';
  $pane = new stdClass();
  $pane->pid = 'new-f32d7549-cba1-4344-ae23-9e90ac298e1a';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_link' => '',
      'image_style' => 'panopoly_image_featured',
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
  $pane->uuid = 'f32d7549-cba1-4344-ae23-9e90ac298e1a';
  $display->content['new-f32d7549-cba1-4344-ae23-9e90ac298e1a'] = $pane;
  $display->panels['sidebar'][0] = 'new-f32d7549-cba1-4344-ae23-9e90ac298e1a';
  $pane = new stdClass();
  $pane->pid = 'new-e910698d-eee1-4a4c-b721-cd47cca92681';
  $pane->panel = 'sidebar';
  $pane->type = 'term_description';
  $pane->subtype = 'term_description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = 'e910698d-eee1-4a4c-b721-cd47cca92681';
  $display->content['new-e910698d-eee1-4a4c-b721-cd47cca92681'] = $pane;
  $display->panels['sidebar'][1] = 'new-e910698d-eee1-4a4c-b721-cd47cca92681';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f32d7549-cba1-4344-ae23-9e90ac298e1a';
  $panelizer->display = $display;
  $export['taxonomy_term:panopoly_categories:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'taxonomy_term';
  $panelizer->panelizer_key = 'panopoly_categories';
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->name = 'taxonomy_term:panopoly_categories:default:default';
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
      'center' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a68b2d24-77c7-4ad3-be84-7d8d537416ce';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'taxonomy_term:panopoly_categories:default:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0c8d8fde-7a93-4242-bd92-f5810efb1b2a';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_link' => '',
      'image_style' => 'panopoly_image_half',
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
  $pane->uuid = '0c8d8fde-7a93-4242-bd92-f5810efb1b2a';
  $display->content['new-0c8d8fde-7a93-4242-bd92-f5810efb1b2a'] = $pane;
  $display->panels['contentmain'][0] = 'new-0c8d8fde-7a93-4242-bd92-f5810efb1b2a';
  $pane = new stdClass();
  $pane->pid = 'new-2263de4c-477a-4889-b074-16ca4286ee86';
  $pane->panel = 'contentmain';
  $pane->type = 'term_description';
  $pane->subtype = 'term_description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '2263de4c-477a-4889-b074-16ca4286ee86';
  $display->content['new-2263de4c-477a-4889-b074-16ca4286ee86'] = $pane;
  $display->panels['contentmain'][1] = 'new-2263de4c-477a-4889-b074-16ca4286ee86';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0c8d8fde-7a93-4242-bd92-f5810efb1b2a';
  $panelizer->display = $display;
  $export['taxonomy_term:panopoly_categories:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'taxonomy_term';
  $panelizer->panelizer_key = 'panopoly_categories';
  $panelizer->access = array();
  $panelizer->view_mode = 'featured';
  $panelizer->name = 'taxonomy_term:panopoly_categories:default:featured';
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
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8279fd0a-0c0a-491f-950b-fe73fff94d66';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'taxonomy_term:panopoly_categories:default:featured';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-11bc2cac-aa66-4bf0-b5e2-52068a69b9c3';
  $pane->panel = 'column1';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'panopoly_image_featured',
      'image_link' => 'content',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
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
  $pane->uuid = '11bc2cac-aa66-4bf0-b5e2-52068a69b9c3';
  $display->content['new-11bc2cac-aa66-4bf0-b5e2-52068a69b9c3'] = $pane;
  $display->panels['column1'][0] = 'new-11bc2cac-aa66-4bf0-b5e2-52068a69b9c3';
  $pane = new stdClass();
  $pane->pid = 'new-92686c6d-d579-4830-85a3-8e67e42b3ee7';
  $pane->panel = 'column2';
  $pane->type = 'term_description';
  $pane->subtype = 'term_description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '92686c6d-d579-4830-85a3-8e67e42b3ee7';
  $display->content['new-92686c6d-d579-4830-85a3-8e67e42b3ee7'] = $pane;
  $display->panels['column2'][0] = 'new-92686c6d-d579-4830-85a3-8e67e42b3ee7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-11bc2cac-aa66-4bf0-b5e2-52068a69b9c3';
  $panelizer->display = $display;
  $export['taxonomy_term:panopoly_categories:default:featured'] = $panelizer;

  return $export;
}
