Feature: Add spotlight widget
  In order to promote content
  As a site administrator
  I need to be able to add a spotlight

  Background:
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add spotlight" in the "CTools modal" region
    Then I should see "Configure new Add spotlight"

  @api @javascript @panopoly_widgets
  Scenario: Add a spotlight
    When I fill in the following:
      | Slide Duration                             | 3                   |
      | field_basic_spotlight_items[und][0][title] | Testing item title  |
      | Link                                       | http://drupal.org   |
      | Description                                | Testing description |
      And I attach the file "test-sm.png" to "files[field_basic_spotlight_items_und_0_fid]"
      And I press the "Upload" button
    #Then I should see the "Crop" button in the "CTools modal" region
    When I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing description"
      And I should see "Testing item title"
      # Per an old bug described in issue #2075903
      And I should not see "Spotlight"

  @api @javascript @panopoly_widgets
  Scenario: Image is required per issue #2075903
    When I fill in the following:
      | Slide Duration                             | 3                   |
      | field_basic_spotlight_items[und][0][title] | Testing item title  |
      | Link                                       | http://drupal.org   |
      | Description                                | Testing description |
      And I press "edit-return"
    Then I should see "Image field is required"

  # NOTE: we use the @panopoly_wysiwyg tag because that is where Linkit comes
  #       from in a default install
  @api @javascript @panopoly_widgets @panopoly_wysiwig
  Scenario: Linkit is enabled on the link field
    When I click the 2nd "Search for existing content" in the "CTools modal" region
    Then I should see "Linkit"
