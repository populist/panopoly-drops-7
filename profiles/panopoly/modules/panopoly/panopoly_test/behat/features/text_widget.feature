Feature: Add text widget
  In order to put additional text on a page (beyond the main content)
  As a site administrator
  I need to be able to add a text widget
 
  @api @javascript @panopoly_widgets
  Scenario: Add text to a page
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
    When I fill in the following:
      | Title   | Text widget title       |
      | Editor  | plain_text              |
      | Text    | Testing text body field |
      And I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Text widget title"
      And I should see "Testing text body field"
