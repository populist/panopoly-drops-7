SUMMARY
=======
Linkit provides an easy interface for internal and external linking with editors and fields by using an autocomplete
field. Linkit links to nodes, users, managed files, terms and have basic support for all entities by default.

ADVANTAGES
==========
Linkit has three major advantages over traditional linking

1. The user does not have to copy or remember a URL.
2. It is a sustainable solution for internal linking.
3. It has a user friendly UI.

FEATURES
========
* Basic support for all entities.
* Token support (for better descriptions on search results in Linkit).
* Provides a link button, similar to the ordinary link button in most editors.
* Can be attached to fields.
* The button opens a dialog with an autocomplete field for searching content.
* Support for IMCE.
* Settings are handled by profiles, similar to the profiles of the WYSIWYG module. Thus, it is possible to customize
the behavior of Linkit in detail.
* Works with and without Pathologic.
* Internal absolute URL:s converts automatically into Drupal paths, very simple for users who are used to copy-pasting.
* Tested to work in multiple server environments, e.g. with and without clean URL:s, Drupal installation in a
subdirectory or on a different port.
* Uses BAC
* Fully exportable with Features module.

Since Drupal's own autocomplete was not enough, we developed our own Better Autocomplete which provides a rich
autocomplete experience. It is GPL and bundled with Linkit 7.x-2.x and 7.x-3.x.

INSTALLATION
============

* Normal module installation procedure,see http://drupal.org/documentation/install/modules-themes/modules-7
for further information.
* Enable the Linkit button in your editor or on your field.

CONFIGURATION
=============
(admin/config/content/linkit)
After the installation, you have to create a Linkit profile. The profile will contain information about which
attributes and plugins to use.

DEPENDENCIES
============
* ctools
* Entity API

EDITOR SUPPORT
==============
* WYSIWYG with TinyMCE or CKEditor.
* CKEditor.

EXTRA plugins
=============

* Linkit References
* Linkit panel pages
* Linkit Views (is included in 6.x)
* Linkit Picker
* Linkit Upload
* Linkit Target
* Adds the target attribute. (is included in 7.x-3.0 and above)
* Linkit Markdown

API
===
Our new robust and flexible API

* Makes it easy for developers to extend Linkit with custom plugins. Example implementations included.
* Has support for altering db queries, using tags.
* Makes it possible to add HTML attributes to links (or alter existing attributes' interface)
* There is a API file called linkit.api.php

MAINTAINERS
===========
Current maintainer:
*Anon -https://www.drupal.org/u/anon
