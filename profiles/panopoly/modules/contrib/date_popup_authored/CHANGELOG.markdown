# Date Popup Authored Changelog

## 7.x-1.2

- Travis CI support
- [#2329773][4] by amagdy, Mark Trapp: Clean up variables when no longer in use
- [#2051921][3] by pfrenssen: Warning: strtotime() expects parameter 1 to be string, array given in strtotime
- [#2275593][2] by goodboy: Use date_format_short for default value.
- [#1087616][1] by Mark Trapp: Date Popup Authored does not play nice when $form['authored']['#access'] is modified too late

[1]: https://www.drupal.org/node/1087616
[2]: https://www.drupal.org/node/2275593
[3]: https://www.drupal.org/node/2051921
[4]: https://www.drupal.org/node/2329773

## 7.x-1.1

- Drupal 7 support
- [#1087616][6] by Mark Trapp: Post date resets on save if user can't administer nodes
- [#1012288][5] by pillarsdotnet: Make Date Popup Authored work in PHP 5.2
- [#995934][4] by Mark Trapp: Date Popup Authored needs tests
- [#995060][3] by pillarsdotnet: Date Popup Authored assumes date is a DateObject, shouldn't
- [#970622][2] by Mark Trapp: Saving a node with Date Popup Authored enabled will result in published time drift
- [#970406][1] by Mark Trapp: Creating a new node with Date Popup Authored enabled results in a White Screen of Death

[1]: https://www.drupal.org/node/970406
[2]: https://www.drupal.org/node/970622
[3]: https://www.drupal.org/node/995060
[4]: https://www.drupal.org/node/995934
[5]: https://www.drupal.org/node/1012288
[6]: https://www.drupal.org/node/1087616
