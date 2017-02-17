Feature: Panopoly Magic allows the admin to toggle displaying seldom used pane styles
  In order to view the seldom used pane styles
  As a site administrator
  I need to enable showing seldom used pane styles

  @api @javascript @panopoly_magic
  Scenario: Enable viewing seldom used pane styles
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I run drush "vset" "panopoly_magic_show_panels_styles 1"
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
    Then I should see "Text widget title"
      And I should see "Testing text body field"
    When I click "Style" in the "Boxton Content" region
    Then I should see "No markup at all"
    Then I click "Close window"
      And I press "Save"
      And I wait for the Panels IPE to deactivate

  @api @javascript @panopoly_magic
  Scenario: Disable viewing seldom used pane styles
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I run drush "vset" "panopoly_magic_show_panels_styles 0"
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
    Then I should see "Text widget title"
      And I should see "Testing text body field"
    When I click "Style" in the "Boxton Content" region
    Then I should not see "No markup at all"
    Then I click "Close window"
      And I press "Save"
      And I wait for the Panels IPE to deactivate
