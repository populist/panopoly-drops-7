# Date Popup Authored

[![Build Status](https://travis-ci.org/itafroma/drupal-date_popup_authored.svg?branch=7.x-1.x)](https://travis-ci.org/itafroma/drupal-date_popup_authored)

## Introduction

Date Popup Authored provides a jQuery UI datepicker for the "Authored on" date field found on node submission forms.

For a full description of the module, visit the [project page][1] on Drupal.org.
To submit bug reports and feature suggestions, or to track changes, please visit the [issue queue][2].

[1]: https://drupal.org/project/date_popup_authored "Date Popup Authored project page"
[2]: https://drupal.org/project/issues/date_popup_authored "Date Popup Authored issue tracker"

## Requirements

- Drupal 7
- [Date][3] 2.0 or later
- Date Popup, part of the Date module

[3]: https://drupal.org/project/date "Date project page"

## Installation and configuration

Install as usual. See the [handbook page on installing contributed modules][4] for further information.

You can change the behavior of the date-picker by going to the settings page for each content type.

[4]: https://drupal.org/node/895232 "Installing modules (Drupal 7)"

## Caveats

Since Date Popup Authored allows you to choose a date format that's less specific than the default date format Drupal uses for the Authored on field, it will insert default data if you use a more simplified date format.

For example, if the date format you've configured doesn't include a time, when the node is saved, the Authored on time will be set to 12:00AM. Similarly, if you don't include the ability to choose a month, the Authored on month will be set to January (i.e. month 1).

So, if you care about the time a post is authored, make sure you allow the user to set it in the date format. See installation for more information.

## Future development

The functionality this module provides is being considered for core inclusion:

- [#1835016: Polyfill date input type][1]
- [#471942-30: Use Date Popup on 'Authored on' field][2]
- [#504524: Extend Authored on field with jQuery UI Date Picker][3]

Because of this, there will hopefully be no Drupal 8 version.

[5]: https://www.drupal.org/node/1835016 "#1835016: Polyfill date input type"
[6]: https://www.drupal.org/comment/6788664#comment-6788664 "#471942-30: Use Date Popup on 'Authored on' field"
[7]: https://www.drupal.org/node/504524 "#504524: Extend Authored on field with jQuery UI Date Picker"

## Contact

The current maintainer is [Mark Trapp][5] ([Drupal.org profile][6]).

[8]: http://marktrapp.com "Mark Trapp's website"
[9]: https://drupal.org/u/mark-trapp "Mark Trapp's Drupal.org profile"

## Acknowledgments

Date Popup Authored was inspired by the hacks provided by [brice][7] and [Rob Loach][8] in the Date module issue, "[Use Date Popup on 'Authored on' field][9]." It contains additional fixes to account for problems found in their solution, new configuration options, Drupal 7 support, and a full test suite.

[10]: https://drupal.org/user/446296 "brice's Drupal.org profile"
[11]: https://drupal.org/u/robloach "Rob Loach's Drupal.org profile"
[12]: https://drupal.org/node/471942 "Use Date Popup on 'Authored on' field"

## More information

- For additional documentation, see the [online Drupal handbook][10].
- For a list of security announcements, see the [*Security advisories* page][11] (available as an RSS feed). This page also describes how to subscribe to these announcements via e-mail.
- For information about the Drupal security process, or to find out how to report a potential security issue to the Drupal security team, see the [*Security team* page][12].
- For information about the wide range of available support options, see the [*Support* page][13].

[13]: https://drupal.org/handbook "Drupal Handbook"
[14]: https://drupal.org/security "Drupal security advisories"
[15]: https://drupal.org/security-team "Drupal security team"
[16]: https://drupal.org/support] "Drupal support"