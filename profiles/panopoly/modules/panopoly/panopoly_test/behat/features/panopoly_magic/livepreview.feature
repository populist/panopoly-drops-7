Feature: Live preview
  In order to do more WYSIWYG
  As a site administrator
  I need to be able to have a live preview of my changes to the widgets

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: Automatic live preview should show changes immediately
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are automatic
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add table" in the "CTools modal" region
    Then I should see "Configure new Add table"
    When I fill in "Title" with "Widget title"
      And I wait for live preview to finish
    Then I should see "Widget title" in the "Live preview" region
    When I fill in "field_basic_table_table[und][0][tablefield][cell_0_0]" with "c-1-r-1"
      And I wait for live preview to finish
    # We need to check the table header case insensitively, because it's not
    # uncommon to make table headers capitalized.
    Then I should see text matching "/c-1-r-1/i" in the "Live preview" region
    When I fill in "field_basic_table_table[und][0][tablefield][cell_0_1]" with "c-2-r-1"
      And I wait for live preview to finish
    Then I should see text matching "/c-2-r-1/i" in the "Live preview" region
    # Test that we can make the title into a link
    Then I should not see the link "Widget title" in the "Live preview" region
    When I check the box "Make title a link"
      And I wait for live preview to finish
      And I fill in "path" with "http://drupal.org"
      And I wait for live preview to finish
    Then I should see the link "Widget title" in the "Live preview" region
    When I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Widget title"
      And I should see the link "Widget title"
      And I should see "c-1-r-1"
      And I should see "c-2-r-1"

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: Live preview should work with views
    Given I am logged in as a user with the "administrator" role
      And "panopoly_test_page" content:
      | title       | body      | created            | status |
      | Test Page 3 | Test body | 01/01/2001 11:00am |      1 |
      | Test Page 1 | Test body | 01/02/2001 11:00am |      1 |
      | Test Page 2 | Test body | 01/03/2001 11:00am |      1 |
      And Panopoly magic live previews are automatic
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content list" in the "CTools modal" region
    Then I should see "Configure new Add content list"
    When I fill in "widget_title" with "Content list widget"
      And I wait for live preview to finish
    Then I should see "Content list widget" in the "Live preview" region
    # @todo: we need to test switching the content type, but there's only
    # one included with our demo data.
    # Test changing the "Items to Show".
    When I select "Test Page" from "exposed[type]"
      And I wait for live preview to finish
    Then I should see the link "Test Page 1" in the "Live preview" region
      And I should see the link "Test Page 2" in the "Live preview" region
      And I should see the link "Test Page 3" in the "Live preview" region
    When I fill in "items_per_page" with "1"
      And I wait for live preview to finish
    Then I should see the link "Test Page 2" in the "Live preview" region
      And I should not see the link "Test Page 1" in the "Live preview" region
      And I should not see the link "Test Page 3" in the "Live preview" region
    # Test changing the sort order.
    When I fill in "exposed[sort_order]" with "ASC"
      And I wait for live preview to finish
    Then I should not see the link "Test Page 2" in the "Live preview" region
      And I should see the link "Test Page 3" in the "Live preview" region
    # Test changing the sort by.
    When I fill in "exposed[sort_by]" with "title"
      And I wait for live preview to finish
    Then I should not see the link "Test Page 3" in the "Live preview" region
      And I should see the link "Test Page 1" in the "Live preview" region
    # Test changing the Display Type to "Content".
    Then I should not see the link "Read more" in the "Live preview" region
    When I select the radio button "Content"
      And I wait for live preview to finish
    Then I should see the link "Read more" in the "Live preview" region
    # Test changing the Display Type to "Table".
    When I select the radio button "Table"
      And I wait for live preview to finish
    # @todo: How do I test that there is a table there?
    Then I should not see the link "Read more" in the "Live preview" region
    # Test enabling the table header.
    Then I should not see text matching "/Image/i" in the "Live preview" region
      And I should not see text matching "/Title/i" in the "Live preview" region
      And I should not see text matching "/Date/i" in the "Live preview" region
      And I should not see text matching "/Posted by/i" in the "Live preview" region
    When I fill in "header_type" with "titles"
      And I wait for live preview to finish
    Then I should see text matching "/Image/i" in the "Live preview" region
      And I should see text matching "/Title/i" in the "Live preview" region
      And I should see text matching "/Date/i" in the "Live preview" region
      And I should see text matching "/Posted by/i" in the "Live preview" region
    # Test removing each of the fields.
    When I uncheck the box "fields_override[field_featured_image]"
      And I wait for live preview to finish
    Then I should not see "Image" in the "Live preview" region
    When I uncheck the box "fields_override[title]"
      And I wait for live preview to finish
    Then I should not see "Title" in the "Live preview" region
    When I uncheck the box "fields_override[created]"
      And I wait for live preview to finish
    Then I should not see "Date" in the "Live preview" region
    When I uncheck the box "fields_override[name]"
      And I wait for live preview to finish
    Then I should not see "Posted by" in the "Live preview" region

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: Manual live preview should show changes when requested
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are manual
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
    When I fill in "Title" with "Widget title"
    Then I should not see "Widget title" in the "Live preview" region
    When I press "Update Preview"
      And I wait for live preview to finish
    Then I should see "Widget title" in the "Live preview" region

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: Automatic live preview should validation errors immediately
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are automatic
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add spotlight" in the "CTools modal" region
    Then I should see "Configure new Add spotlight"
    When I fill in "Description" with "Testing description"
      And I wait for live preview to finish
    Then I should see "Image field is required"

  # @todo: We need to test that clicking the WYSIWYG buttons (without typing!)
  #        causes the live preview to update.
  @api @javascript @panopoly_magic @panopoly_widgets @panopoly_wysiwyg
  Scenario: Automatic live preview should update when making changes in the WYSIWYG
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are automatic
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
    # Try with TinyMCE
    When I type "Testing WYSIWYG preview" in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor
      And I wait for live preview to finish
    Then I should see "Testing WYSIWYG preview" in the "Live preview" region
    # Try with MarkItUp
    When I select "HTML" from "Editor"
      And I type "Using HTML editor" in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor
      And I wait for live preview to finish
    Then I should see "Using HTML editor" in the "Live preview" region
    # @todo: This isn't really testing what we want because it's typing after
    #        clicking the "Bold" button.
    When I click the "Bold" button in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor
      And I type "This is strong" in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor
      And I wait for live preview to finish
    Then I should see "This is strong" in the "strong" element in the "Live preview" region
    # Try switching to plain text and make sure this doesn't break anything.
    When I select "Plain text" from "Editor"
      And I fill in "edit-field-basic-text-text-und-0-value" with "Testing plain text"
      And I wait for live preview to finish
    Then I should see "Testing plain text" in the "Live preview" region
    # And verify that switching back to TinyMCE will still work.
    When I select "WYSIWYG" from "Editor"
      And I type "Testing WYSIWYG again" in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor
      And I wait for live preview to finish
    Then I should see "Testing WYSIWYG again" in the "Live preview" region

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: Page should match live preview after saving the widget but before saving the page
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are manual
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
    When I fill in "Title" with "Widget title 1"
      And I type "Widget content 1" in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor
      And I press "Update Preview"
    Then I should see "Widget title 1" in the "Live preview" region
      And I should see "Widget content 1" in the "Live preview" region
    When I press "Add" in the "CTools modal" region
    Then I should see "Widget title 1" in the "h2" element in the "Boxton Content" region
      And I should see "Widget content 1"
    # Now try saving the page, and doing the same test, but with an existing widget.
    When I press "Save"
      And I wait for the Panels IPE to deactivate
      And I customize this page with the Panels IPE
      And I click "Edit" in the "Boxton Content" region
    When I fill in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor with "Widget content 2"
      And I fill in "Title" with "Widget title 2"
      And I press "Update Preview"
    Then I should see "Widget title 2" in the "Live preview" region
      And I should see "Widget content 2" in the "Live preview" region
    When I press "Save" in the "CTools modal" region
    Then I should not see "Widget title 1"
      And I should not see "Widget content 1"
      And I should see "Widget title 2" in the "h2" element in the "Boxton Content" region
      And I should see "Widget content 2"

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: Live preview should work equally well with a reusable widget
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are manual
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
    When I check the box "Make this reusable"
      And I fill in "admin_title" with "Test text widget"
      And I fill in "Title" with "Widget title 1"
      And I type "Widget content 1" in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor
      And I press "Update Preview"
    Then I should see "Widget title 1" in the "Live preview" region
      And I should see "Widget content 1" in the "Live preview" region
    When I press "Add" in the "CTools modal" region
    Then I should see "Widget title 1" in the "h2" element in the "Boxton Content" region
      And I should see "Widget content 1"
    # Now try saving the page, and doing the same test, but with an existing widget.
    When I press "Save"
      And I wait for the Panels IPE to deactivate
      And I customize this page with the Panels IPE
      And I click "Edit" in the "Boxton Content" region
    When I fill in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor with "Widget content 2"
      And I fill in "Title" with "Widget title 2"
      And I press "Update Preview"
    Then I should see "Widget title 2" in the "Live preview" region
      And I should see "Widget content 2" in the "Live preview" region
    When I press "Save" in the "CTools modal" region
    Then I should not see "Widget title 1"
      And I should not see "Widget content 1"
      And I should see "Widget title 2" in the "h2" element in the "Boxton Content" region
      And I should see "Widget content 2"

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: Making the title a link should work for both new and existing widgets
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are manual
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
    When I fill in "Title" with "Widget title 1"
      And I check the box "Make title a link"
      And I fill in "path" with "http://google.com"
      And I type "Widget content 1" in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor
      And I press "Update Preview"
    Then I should see "Widget title 1" in the "Live preview" region
      And I should see "Widget content 1" in the "Live preview" region
      And I should see "Widget title 1" in the "a" element with the "href" attribute set to "http://google.com" in the "Live preview" region
    # Now try saving the page, and doing the same test, but with an existing widget.
    When I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    When I customize this page with the Panels IPE
      And I click "Edit" in the "Boxton Content" region
      And I fill in "path" with "http://yahoo.com"
      And I press "Update Preview"
    Then I should see "Widget title 1" in the "a" element with the "href" attribute set to "http://yahoo.com" in the "Live preview" region
    When I uncheck the box "Make title a link"
      And I press "Update Preview"
    Then I should see "Widget title 1" in the "Live preview" region
      And I should not see the link "Widget title 1" in the "Live preview" region
    # Prevent modal popup from breaking subsequent tests.
    When I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate

  # TODO: This test fails on Travis-CI due to issues with 'drush runserver' not
  # correctly supporting images from image styles. When this is fixed, uncomment
  # this test! See: https://www.drupal.org/node/2428097
#  @api @javascript @panopoly_magic @panopoly_widgets @local_files
#  Scenario: Previewing an image widget should show a valid image
#    Given I am logged in as a user with the "administrator" role
#      And Panopoly magic live previews are manual
#      And I am viewing a landing page
#    When I customize this page with the Panels IPE
#      And I click "Add new pane"
#      And I click "Add image" in the "CTools modal" region
#    Then I should see "Configure new Add image"
#    When I fill in the following:
#      | Title   | Testing image widget title |
#      | Editor  | plain_text                 |
#      | Caption | Testing caption            |
#      And I attach the file "test-sm.png" to "files[field_basic_image_image_und_0]"
#      And I press "Upload"
#      And I press "Update Preview"
#    Then I should see "Testing image widget title" in the "Live preview" region
#      And I should see "Testing caption" in the "Live preview" region
#      And I should see an image in the "Live preview" region

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: Making changes ONLY in the live preview shouldn't create new revisions
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are manual
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
    When I check the box "Make this reusable"
      And I fill in "admin_title" with "Testing FPP revisions"
      And I fill in "Title" with "Widget title 1"
      And I fill in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor with "ONLY IN PREVIEW"
      And I press "Update Preview"
    Then I should see "Widget title 1" in the "Live preview" region
      And I should see "ONLY IN PREVIEW" in the "Live preview" region
    When I fill in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor with "Widget content 1"
      And I press "Update Preview"
    Then I should not see "ONLY IN PREVIEW" in the "Live preview" region
      And I should see "Widget content 1" in the "Live preview" region
    # Save for real, and then start editing again.
    When I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
      And I customize this page with the Panels IPE
      And I click "Edit" in the "Boxton Content" region
    When I fill in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor with "THIS WILL BE CANCELLED"
      And I press "Update Preview"
    Then I should not see "Widget content 1" in the "Live preview" region
      And I should see "THIS WILL BE CANCELLED" in the "Live preview" region
    When I click "Close Window"
      And I click "Edit" in the "Boxton Content" region
    Then I should see "Widget content 1" in the "Live preview" region
    When I fill in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor with "Widget content 2"
      And I fill in "Title" with "Widget title 2"
      And I press "Update Preview"
    Then I should not see "Widget content 1" in the "Live preview" region
      And I should see "Widget content 2" in the "Live preview" region
    When I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then fieldable panels pane "Testing FPP revisions" should have 2 revisions
    When I am viewing revision 1 of fieldable panels pane "Testing FPP revisions"
    Then I should see "Widget title 1"
      And I should see "Widget content 1"
    When I am viewing revision 2 of fieldable panels pane "Testing FPP revisions"
    Then I should see "Widget title 2"
      And I should see "Widget content 2"

  @api @javascript @panopoly_magic
  Scenario: There should be NO live preview when configuring region style
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are automatic
      And I am viewing a "panopoly_test_page" with the title "Testing region style"
    When I customize this page with the Panels IPE
      And I click "Region style" in the "Bryant Content" region
    Then I should see "Style Settings"
      And I should not see "Preview" in the "CTools modal" region
    When I select the radio button "Panopoly Test: Style with settings" with the id "edit-style-panopoly-test-settings-style"
      And I press the "Next" button
    Then I should see "General Settings"
      But I should not see "Preview" in the "CTools modal" region

  @api @javascript @panopoly_magic
  Scenario: Live preview should work when configuring a pane style
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are automatic
    # We need to use the 'body_only' panel so that the first pane has some
    # content. Otherwise, it won't render the style plugin!
    When I visit "/node/add/panopoly-test-page"
      And I fill in the following:
        | Title               | Testing title                     |
        | Full page override  | node:panopoly_test_page:body_only |
        | Editor              | plain_text                        |
        | body[und][0][value] | Testing body                      |
      And I press "edit-submit"
    Then I should see "Testing body"
    # Ok, now let's style it.
    When I customize this page with the Panels IPE
      And I click "Style" in the "Boxton Content" region
    Then I should see "Style Settings"
      And I should see "Preview" in the "CTools modal" region
      And I should not see "This widget is patentedly awesome!"
    When I select the radio button "Panopoly Test: Style with settings" with the id "edit-style-panopoly-test-settings-style"
      And I wait for live preview to finish
    Then I should see "This widget is patentedly awesome!"
    When I press the "Next" button
    Then I should see "General Settings"
      And I should see "Preview" in the "CTools modal" region
      And I should see "This widget is patentedly awesome!"
    When I select "Terrible" from "Quality of this widget"
      And I wait for live preview to finish
    Then I should see "Avert your eyes! It's not even worth to cast your gaze upon this widget."

  @api @javascript @panopoly_magic
  Scenario: Manual live preview should work when configuring a pane style
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are manual
    # We need to use the 'body_only' panel so that the first pane has some
    # content. Otherwise, it won't render the style plugin!
    When I visit "/node/add/panopoly-test-page"
      And I fill in the following:
        | Title               | Testing title                     |
        | Full page override  | node:panopoly_test_page:body_only |
        | Editor              | plain_text                        |
        | body[und][0][value] | Testing body                      |
      And I press "edit-submit"
    Then I should see "Testing body"
    # Ok, now let's style it.
    When I customize this page with the Panels IPE
      And I click "Style" in the "Boxton Content" region
    Then I should see "Style Settings"
      And I should see "Preview" in the "CTools modal" region
      And I should not see "This widget is patentedly awesome!"
    When I select the radio button "Panopoly Test: Style with settings" with the id "edit-style-panopoly-test-settings-style"
    Then I should not see "This widget is patentedly awesome!"
    When I press "Update Preview"
      And I wait for live preview to finish
    Then I should see "This widget is patentedly awesome!"
    When I press the "Next" button
    Then I should see "General Settings"
      And I should see "Preview" in the "CTools modal" region
      And I should see "This widget is patentedly awesome!"
    When I select "Terrible" from "Quality of this widget"
    Then I should not see "Avert your eyes! It's not even worth to cast your gaze upon this widget."
    When I press "Update Preview"
      And I wait for live preview to finish
    Then I should see "Avert your eyes! It's not even worth to cast your gaze upon this widget."

  @api @javascript @panopoly_widgets
    Scenario: Make text widget title a link
      Given I am logged in as a user with the "administrator" role
        And Panopoly magic live previews are automatic
        And I am viewing a landing page
      When I customize this page with the Panels IPE
        And I click "Add new pane"
        And I click "Add text" in the "CTools modal" region
      Then I should see "Configure new Add text"
      When I fill in the following:
        | Title   | Here's a title & then some |
        And I check the box "Make title a link"
        And I wait for AJAX to finish
      Then I should see "Here's a title & then some"
