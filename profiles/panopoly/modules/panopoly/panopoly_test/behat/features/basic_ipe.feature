Feature: Make basic changes with the IPE
  In order to customize pages
  As a site administrator
  I need to be able to manipulate them with the IPE

  Background: 
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a "panopoly_test_page" with the title "Testing title"

  @api @javascript
  Scenario: Change layout
    When I change layout with the Panels IPE
      And I click "Phelan"
      And I press "Save" in the "CTools modal" region
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing title"

