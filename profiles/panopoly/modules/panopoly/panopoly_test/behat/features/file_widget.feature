Feature: Add a file to a page
  In order to add a file to a page
  As a site administrator
  I need to be able to use the file widget

  Background:
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add file" in the "CTools modal" region
    Then I should see "Configure new Add file"

  @api @javascript @panopoly_widgets @local_files
  Scenario: Add a file
    Then I should see "Allowed file types: txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp."
    When I fill in the following:
      | Title | Testing file title |
      | Editor              | plain_text    |
      | Text | Testing file text   |
      And I attach the file "test.txt" to "files[field_basic_file_file_und_0]"
      And I press "Upload"
    Then I should see "test.txt"
    When I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing file title"
      And I should see "Testing file text"
      And I should see the link "test.txt"
