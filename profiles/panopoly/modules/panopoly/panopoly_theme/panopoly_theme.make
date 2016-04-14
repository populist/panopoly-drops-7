; Panopoly Theme Makefile

api = 2
core = 7.x

; Radix Layouts
projects[radix_layouts][version] = 3.4
projects[radix_layouts][subdir] = contrib

; Summon the Power of Respond.js

projects[respondjs][version] = 1.5
projects[respondjs][subdir] = contrib

; The RespondJS library is licenesed under the MIT license, and can't be
; packaged on Drupal.org. Copy and paste the below into your distributions
; .make file if you still need it, or clone manually from Git.

;libraries[respondjs][download][type] = git
;libraries[respondjs][download][url] = https://github.com/scottjehl/Respond.git
;libraries[respondjs][download][revision] = 86dea4ab1e93a275e2044965ab7452c3c1e2c6da
;libraries[respondjs][download][branch] = master

; Bundle a Few Panopoly Approved Themes

projects[responsive_bartik][version] = 1.0
projects[responsive_bartik][type] = theme

; projects[radix][version] = 1.x-dev
; projects[radix][type] = theme
; projects[radix][download][type] = git
; projects[radix][download][revision] = b873330
; projects[radix][download][branch] = 7.x-1.x
