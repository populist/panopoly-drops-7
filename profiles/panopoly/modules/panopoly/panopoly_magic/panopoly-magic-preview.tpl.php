<?php
/**
 * @file
 * Template for the Panopoly Magic preview.
 */
?>
<?php if (!$use_legacy_fieldset): ?>
  <div class="panopoly-magic-preview-wrapper <?php print $classes; ?>"<?php print $attributes; ?>>
    <div class="panopoly-magic-preview-title-wrapper">
      <?php if (!empty($add_link)): ?>
        <div class="panopoly-magic-preview-title"><?php print $add_link; ?></div>
      <?php endif; ?>
      <span class="panopoly-magic-preview-title-inner"><?php print $title; ?></span>
    </div>
    <div class="panopoly-magic-preview-inner">
      <?php print $preview; ?>
    </div>
  </div>
<?php else: ?>
  <?php
  /**
   * When creating a new Panopoly theme, don't include the legacy fieldset
   * markup below - just use the markup above and leave this out.
   */
  ?>
  <fieldset class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <legend>
      <?php if (!empty($add_link)): ?>
        <?php // Only keeping 'widget-preview-title' for backcompat with 3rd party themes. ?>
        <div class="panopoly-magic-preview-title widget-preview-title"><?php print $add_link; ?></div>
      <?php endif; ?>
      <span class="fieldset-legend"><?php print $title; ?></span>
    </legend>
    <div class="fieldset-wrapper">
      <?php print $preview; ?>
    </div>
  </fieldset>
<?php endif; ?>
