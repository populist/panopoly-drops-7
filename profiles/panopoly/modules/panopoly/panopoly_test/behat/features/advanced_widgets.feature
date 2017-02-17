Feature: Hide/show advanced widgets
  In order simplify the user interface
  As a site administrator
  I need to be able to hide or show advanced widgets
 
  @api @javascript @panopoly_admin
  Scenario: Configure "Use Advanced Panel Plugins"
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly admin "Use Advanced Panel Plugins" is disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
    Then I should not see "Panopoly Test Advanced" in the "CTools modal" region
    When Panopoly admin "Use Advanced Panel Plugins" is enabled
      And I reload the page
      And I customize this page with the Panels IPE
      And I click "Add new pane"
    Then I should see "Panopoly Test Advanced" in the "CTools modal" region
