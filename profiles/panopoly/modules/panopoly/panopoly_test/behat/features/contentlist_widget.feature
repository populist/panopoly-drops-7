Feature: Add content list widget
  In order to create a list of certain content
  As a site administrator
  I need to be able to add a list with the content I choose
 
  @api @javascript @panopoly_widgets
  Scenario: Add a content list
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And "panopoly_test_page" content:
      | title       | body      | created            | status |
      | Test Page 3 | Test body | 01/01/2001 11:00am |      1 |
      | Test Page 1 | Test body | 01/02/2001 11:00am |      1 |
      | Test Page 2 | Test body | 01/03/2001 11:00am |      1 |
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add content list" in the "CTools modal" region
    Then I should see "Configure new Add content list"
      When I fill in the following:
       | widget_title    | Content Page List Asc 1 |
       | items_per_page  | 1                       |
#      | Display Type    | Fields                  |
    When I select "Test Page" from "exposed[type]"
      And I select "Asc" from "exposed[sort_order]"
      And I select "Title" from "exposed[sort_by]"
      And I wait 5 seconds
      And I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
      And I wait 5 seconds
    Then I should see "Content Page List Asc 1"
      And I should see "Test Page 1"
      And I should see "January 2, 2001"
      And I should see "Posted by Anonymous"
    # Check that 'Sort by' stays set, per #2153291
    When I customize this page with the Panels IPE
     And I click "Settings" in the "Boxton Content" region
    Then I should see "Configure Add content list"
      And the "exposed[sort_by]" field should contain "Title"
