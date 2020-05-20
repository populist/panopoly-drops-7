Feature: Reusable widgets
  In order to reuse content
  As a site administrator
  I need to be able to create and place reusable widgets

  @api @javascript @panopoly_widgets
  Scenario: Create and place reusable widget
    Given I am logged in as a user with the "administrator" role
      And I am viewing a landing page
      And Panopoly magic add content previews are automatic
      And Panopoly magic live previews are automatic
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
    When I check the box "Make this reusable"
      And I fill in "admin_title" with "Reusable widget 1"
      And I fill in "Title" with "Widget title 1"
      And I type "Widget content 1" in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Widget content 1"
    # Then add the reusable widget again, modifying its content while adding it,
    # to ensure that we can modify without saving first.
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Reusable Content"
    Then I should see "Reusable widget 1"
    When I click "Reusable widget 1"
      And I fill in the "edit-field-basic-text-text-und-0-value" WYSIWYG editor with "Changed content 1"
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should not see "Widget content 1"
      And I should see "Changed content 1"

