Feature: Panopoly Magic allows the user to change the "Display Type" of a Views widget
  In order to build really flexible Views widgets
  As a site administrator
  I need to be able to change the "Display Type" of a Views widget

  @api @javascript @panopoly_magic
  Scenario: Add Views widget set to Fields with 'Display Type' override allowed
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Panopoly Test" in the "CTools modal" region
      And I click "View: Magic Display Type: Fields and allowed" in the "CTools modal" region
    Then I should see "Display Settings"
      And I should see "Display Type" in the "label" element in the "CTools modal" region
      And the "Display Type" radio button should be set to "Fields "

  @api @javascript @panopoly_magic
  Scenario: Add Views widget set to Fields but WITHOUT the 'Display Type' override allowed
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Panopoly Test" in the "CTools modal" region
      And I click "View: Magic Display Type: Fields but not allowed" in the "CTools modal" region
    Then I should not see "Display Settings"
      And I should not see "Display Type" in the "label" element in the "CTools modal" region
