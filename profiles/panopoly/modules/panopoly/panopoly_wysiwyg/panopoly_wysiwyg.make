; Panopoly WYSIWYG Makefile

api = 2
core = 7.x

; The WYSIWYG Module Family

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][version] = 2.4
projects[wysiwyg][patch][1489096] = http://drupal.org/files/wysiwyg-table-format.patch
projects[wysiwyg][patch][1786732] = http://drupal.org/files/wysiwyg-arbitrary_image_paths_markitup-1786732-3.patch
projects[wysiwyg][patch][2884691] = https://www.drupal.org/files/issues/wysiwyg-theme-css-v24-2884691-8.patch
projects[wysiwyg][patch][2884761] = https://www.drupal.org/files/issues/wysiwyg-tinymce-css-array-2884761-5.patch
projects[wysiwyg][patch][2890066] = https://www.drupal.org/files/issues/wysiwyg-isnode-2890066-2.patch

projects[wysiwyg_filter][version] = 1.6-rc2
projects[wysiwyg_filter][subdir] = contrib
projects[wysiwyg_filter][patch][1687794] = https://www.drupal.org/files/wysiwyg_filter-1687794-1-skip-validation-if-filter-disabled.patch

; The WYSIWYG Helpers

projects[linkit][version] = 3.5
projects[linkit][subdir] = contrib
projects[linkit][patch][2651404] = https://www.drupal.org/files/issues/linkit-add-to-any-element-2651404-3.patch

projects[image_resize_filter][version] = 1.15
projects[image_resize_filter][subdir] = contrib
projects[image_resize_filter[patch][1929710] = https://www.drupal.org/files/issues/image_resize_filter-query_string-1929710-14-D7.patch

projects[caption_filter][version] = 1.x-dev
projects[caption_filter][subdir] = contrib
projects[caption_filter][download][type] = git
projects[caption_filter][download][revision] = b8097ee
projects[caption_filter][download][branch] = 7.x-1.x
projects[caption_filter][patch][2455253] = https://www.drupal.org/files/issues/caption_filter-single-quotes-to-entities.patch

; Include our Editors

libraries[tinymce][download][type] = get
libraries[tinymce][download][url] = http://download.moxiecode.com/tinymce/tinymce_3.5.11.zip
libraries[tinymce][patch][1561882] = http://drupal.org/files/1561882-cirkuit-theme-tinymce-3.5.8.patch
libraries[tinymce][patch][2876031] = https://www.drupal.org/files/issues/tinymce-chrome58-fix-2876031-5.patch

libraries[markitup][download][type] = git
libraries[markitup][download][url] = https://github.com/markitup/1.x.git
libraries[markitup][download][revision] = 2c88c42
libraries[markitup][download][branch] = master
libraries[markitup][patch][1715642] = http://drupal.org/files/1715642-adding-html-set-markitup-editor.patch
