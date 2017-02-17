Feature: Panopoly Magic respects entity view configuration
  In order to place a view pane properly
  As a site administrator
  I cannot change an entity view mode to fields.

  @api @javascript @panopoly_magic
  Scenario: Add view pane that has an entity view mode of Featured
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "View panes" in the "CTools modal" region
      And I click "View: Magic View Modes: Entity Featured" in the "CTools modal" region
    Then I should not see "Display Settings"
    Then I should see "Content Settings"
    Then the "Featured" radio button should be set to "Featured "

  @api @javascript @panopoly_magic
  Scenario: Add view pane that has default view mode
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "View panes" in the "CTools modal" region
      And I click "View: Magic View Modes: Entity Full" in the "CTools modal" region
    Then I should not see "Display Settings"
    Then I should see "Content Settings"
    Then the "Full content " radio button should be set to "Full content "

  @api @javascript @panopoly_magic
  Scenario: Add view pane that supports fields
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "View panes" in the "CTools modal" region
      And I click "View: Magic View Modes: Fields" in the "CTools modal" region
    Then I should see "Display Settings"
      And I should not see "Content Settings"
    When I select the radio button "Content"
    Then I should see "Content Settings"
      And the "Teaser " radio button should be set to "Teaser "
