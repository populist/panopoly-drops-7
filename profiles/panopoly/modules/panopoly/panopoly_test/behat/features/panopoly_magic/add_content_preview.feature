Feature: Preview of widgets on 'Add content' dialog
  In order to understand what a widget is like before adding it
  As a site administrator
  I need to see a preview of widgets on the 'Add content' dialog

  @api @javascript @panopoly_magic
  Scenario: Single previews on the 'Add content' dialog
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are single
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Panopoly Test" in the "CTools modal" region
    Then I should see "Simple Pane" in the "CTools modal" region
      And I should see "Select a widget to show its preview"
      And I should not see "Abracadabra! Here is a simple pane."
    When I click "Simple Pane" in the "CTools modal" region
    Then I should see "Abracadabra! Here is a simple pane."
    When I click "A simple pane for testing." in the "CTools modal" region
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Abracadabra! Here is a simple pane."

  @api @javascript @panopoly_magic
  Scenario: Automatic previews on the 'Add content' dialog
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are automatic
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Panopoly Test" in the "CTools modal" region
    Then I should see "Abracadabra! Here is a simple pane."
    When I click "A simple pane for testing." in the "CTools modal" region
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Abracadabra! Here is a simple pane."

  @api @javascript @panopoly_magic
  Scenario: Manual previews on the 'Add content' dialog
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are manual
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Panopoly Test" in the "CTools modal" region
    Then I should not see "Abracadabra! Here is a simple pane."
      And I should see "Add Simple Pane" in the "div" element with the "class" attribute set to "panopoly-magic-preview-title" in the "CTools modal" region
    When I click "Preview Simple Pane widget" in the "CTools modal" region
    Then I should see "Abracadabra! Here is a simple pane."
    When I click "A simple pane for testing." in the "CTools modal" region
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Abracadabra! Here is a simple pane."

  @api @javascript @panopoly_magic
  Scenario: Previews on the 'Add content' dialog can be disabled
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Panopoly Test" in the "CTools modal" region
    # Check for signs of the automatic preview
    Then I should not see "Abracadabra! Here is a simple pane."
    # ... and manual preview
    And I should not see "Add" in the "div" element with the "class" attribute set to "panopoly-magic-preview-title" in the "CTools modal" region
    # ... and the single preview
    And I should not see "Select a widget to show its preview"
    # Finally, make sure the add link still works
    When I click "Simple Pane" in the "CTools modal" region
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Abracadabra! Here is a simple pane."

  @api @javascript @panopoly_magic
  Scenario: Add Content link text for categories with multiple options contains widget labels
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are automatic
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Panopoly Test" in the "CTools modal" region
    Then I should see "Abracadabra! Here is a simple pane."
    When I click "Add Simple Pane" in the "CTools modal" region
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Abracadabra! Here is a simple pane."
