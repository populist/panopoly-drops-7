<?php
/**
 * @file
 * panopoly_core.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function panopoly_core_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-panopoly_categories-field_featured_image'.
  $field_instances['taxonomy_term-panopoly_categories-field_featured_image'] = array(
    'bundle' => 'panopoly_categories',
    'deleted' => 0,
    'description' => 'This is the primary image to be associated with the taxonomy term',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'panopoly_image_quarter',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_featured_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'categories',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '300x200',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 1,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 0,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 1,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(
          'panopoly_image_full' => 'panopoly_image_full',
        ),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'preview_image_style' => 'panopoly_image_thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');
  t('This is the primary image to be associated with the taxonomy term');

  return $field_instances;
}
