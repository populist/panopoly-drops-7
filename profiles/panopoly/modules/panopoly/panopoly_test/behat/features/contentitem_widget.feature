Feature: Add content item
  In order to put in a particular content item on a page
  As a site administrator
  I need to be able to choose which content item

  @api @javascript @panopoly_widgets
  Scenario: Content item autocomplete should only offer nodes of the selected type
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And "panopoly_test_page" content:
      | title       | body      | created            | status |
      | Test Page 1 | Test body | 01/01/2001 11:00am |      1 |
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content item" in the "CTools modal" region
    Then I should see "Configure new Add content item"
    When I select "- Any -" from "exposed[type]"
      And I select the first autocomplete option for "test" on the "exposed[title]" field
    Then the "exposed[title]" field should contain "Test Page 1"
    When I select "Test Page" from "exposed[type]"
      And I select the first autocomplete option for "test" on the "exposed[title]" field
    Then the "exposed[title]" field should contain "Test Page 1"
    When I select "Content Page" from "exposed[type]"
      And I select the first autocomplete option for "test" on the "exposed[title]" field
    Then the "exposed[title]" field should not contain "Test Page 1"

  @api @javascript @panopoly_widgets
  Scenario: Add content item (as "Fields")
    Given I am logged in as a user with the "administrator" role
    And Panopoly magic live previews are disabled
    And "panopoly_test_page" content:
      | title       | body      | created            | status |
      | Test Page 1 | Test body | 01/01/2001 11:00am |      1 |
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content item" in the "CTools modal" region
    Then I should see "Configure new Add content item"
    When I select "Test Page" from "exposed[type]"
      And I fill in the following:
      | exposed[title] | Test Page 1       |
      | widget_title   | Test Widget Title |
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Test Widget Title"
      And I should see "Test Page 1"
      And I should see "January 1, 2001"
      And I should see "Posted by Anonymous"

  @api @javascript @panopoly_widgets
  Scenario: Add content item (as "Content")
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And "panopoly_test_page" content:
      | title       | body      | created            | status |
      | Test Page 1 | Test body | 01/01/2001 11:00am |      1 |
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content item" in the "CTools modal" region
    Then I should see "Configure new Add content item"
    When I select "Test Page" from "exposed[type]"
      And I fill in the following:
      | exposed[title] | Test Page 1       |
      And I select the radio button "Content"
      And I select the radio button "Teaser"
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Test Page 1"
      And I should see "Test body"
    # Now, if we override the title, the page title should disappear and be
    # replaced by our override.
    When I customize this page with the Panels IPE
      And I click "Settings" in the "Boxton Content" region
    When I fill in the following:
      | widget_title   | Test Widget Title |
      And I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Test Widget Title"
     And I should not see "Test Page 1"

  @api @javascript @panopoly_widgets
  Scenario: Title override should work for all view modes
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And "panopoly_test_page" content:
      | title       | body      | created            | status |
      | Test Page 1 | Test body | 01/01/2001 11:00am |      1 |
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content item" in the "CTools modal" region
    Then I should see "Configure new Add content item"
    When I select "Test Page" from "exposed[type]"
      And I fill in the following:
      | exposed[title] | Test Page 1       |
      | widget_title   | Test Widget Title |
      And I select the radio button "Content"
      And I select the radio button "Teaser"
      And I press "Add" in the "CTools modal" region
    Then I should see "Test Widget Title"
     And I should not see "Test Page 1"
    # Next, try Full content.
    When I click "Settings" in the "Boxton Content" region
      And I select the radio button "Full content"
      And I press "Save" in the "CTools modal" region
    Then I should see "Test Widget Title"
     And I should not see "Test Page 1"
    # Next, try Featured.
    When I click "Settings" in the "Boxton Content" region
      And I select the radio button "Featured"
      And I press "Save" in the "CTools modal" region
    Then I should see "Test Widget Title"
     And I should not see "Test Page 1"
    # Prevent modal popup from breaking subsequent tests.
    When I press "Save"
      And I wait for the Panels IPE to deactivate

  @api @javascript @panopoly_widgets
  Scenario: Title override should work with non-Panelizer content types
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And "panopoly_test_page_simple" content:
      | title       | body      | created            | status |
      | Test Page 1 | Test body | 01/01/2001 11:00am |      1 |
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content item" in the "CTools modal" region
    Then I should see "Configure new Add content item"
    When I select "Test Page (without Panelizer)" from "exposed[type]"
      And I fill in the following:
      | exposed[title] | Test Page 1       |
      | widget_title   | Test Widget Title |
      And I select the radio button "Content"
      And I select the radio button "Teaser"
      And I press "Add" in the "CTools modal" region
    Then I should see "Test Widget Title"
     And I should not see "Test Page 1"
    # Next, try Full content.
    When I click "Settings" in the "Boxton Content" region
      And I select the radio button "Full content"
      And I press "Save" in the "CTools modal" region
    Then I should see "Test Widget Title"
     And I should not see "Test Page 1"
    # Next, try Featured.
    When I click "Settings" in the "Boxton Content" region
      And I select the radio button "Featured"
      And I press "Save" in the "CTools modal" region
    Then I should see "Test Widget Title"
     And I should not see "Test Page 1"
    # Prevent modal popup from breaking subsequent tests.
    When I press "Save"
      And I wait for the Panels IPE to deactivate

  @api @javascript @panopoly_widgets
  Scenario: Content item widget continues to work after renaming content
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And "panopoly_test_page" content:
      | title       | body      | created            | status |
      | Test Page 1 | Test body | 01/01/2001 11:00am |      1 |
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content item" in the "CTools modal" region
    Then I should see "Configure new Add content item"
    When I select "Test Page" from "exposed[type]"
      And I fill in the following:
      | exposed[title] | Test Page 1       |
      | widget_title   | Test Widget Title |
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Test Widget Title"
      And I should see "Test Page 1"
    When follow "Test Page 1"
      And I click "Edit" in the "Tabs" region
      And I fill in "Test Page 2" for "Title"
      And I press "edit-submit"
    # @todo: Find a better way to get back to the original page.
    When I move backward one page
      And I move backward one page
      And I move backward one page
      And I reload the page
    Then I should see "Test Widget Title"
      And I should see "Test Page 2"
    # Check that the edit form shows the new title now too.
    When I customize this page with the Panels IPE
      And I click "Settings" in the "Boxton Content" region
    Then the "exposed[title]" field should contain "Test Page 2"
    # Make sure that saving without changes works OK.
    When I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Test Widget Title"
      And I should see "Test Page 2"
