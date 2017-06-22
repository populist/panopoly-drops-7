Feature: Add map widget
  In order to put a map on a page
  As a site administrator
  I need to be able to use the map widget
 
  @api @javascript @panopoly_widgets
  Scenario: Add map to a page
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add map" in the "CTools modal" region
    Then I should see "Configure new Add map"
    When I fill in the following:
      | Title       | Widget title            |
      | Editor      | plain_text              |
      | Information | Testing text body field |
      | Address     | Ørnebjergvej 28, Vejle  |
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Widget title"
      And I should see "Testing text body field"
