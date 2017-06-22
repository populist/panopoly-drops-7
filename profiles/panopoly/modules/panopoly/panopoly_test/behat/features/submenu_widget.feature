Feature: Add submenu widget
  In order to make better navigation of the site
  As a site administrator
  I need to be able to add a submenu widget

  Background:
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
    # Create two pages with a parent-child relationship in the menu.
    When I visit "/node/add/panopoly-test-page"
      And I fill in the following:
        | Title               | Parent page    |
        | Editor              | plain_text     |
        | body[und][0][value] | Testing body   |
      And I check the box "menu[enabled]"
      And I fill in "Rodzic" for "menu[link_title]"
      And I select "<Main menu>" from "menu[parent]"
      # Normally, here we'd press "Publish", however some child distribtions
      # don't use 'save_draft', and this makes this test compatible with them.
      #And I press "Publish"
      And I press "edit-submit"
    When I visit "/node/add/panopoly-test-page"
      And I fill in the following:
        | Title               | Child page    |
        | Editor              | plain_text    |
        | body[und][0][value] | Testing body  |
      And I check the box "menu[enabled]"
      And I fill in "Dziecko" for "menu[link_title]"
      And I select "-- Rodzic" from "menu[parent]"
      And I press "edit-submit"
 
  @api @javascript @panopoly_widgets
  Scenario: Add submenu widget to page
    Given I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add submenu"
    Then I should see "Configure new Add submenu"
    When I check the box "override_title"
      And I fill in the following:
        | override_title_text | Submenu title |
    When I select "1st level (primary)" from "edit-level"
      And I check the box "edit-expanded"
    When I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    # Because of #2177417 we have to reload the page for the correct output
    # to be shown. @todo: Remove this when it's finally fixed!
    #When I reload the page
    Then I should see "Rodzic"
      And I should see "Dziecko"
    # Change the starting level to show the parent too.
    When I customize this page with the Panels IPE
      And I click "Settings" in the "Boxton Content" region
    When I select "1st level (primary)" from "edit-level"
    When I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Rodzic"
      And I should see "Dziecko"
    # Verify that #2153277 is fixed by attempting to change the checkboxes
    # after saving originally (see https://www.drupal.org/node/2153277).
    When I customize this page with the Panels IPE
      And I click "Settings" in the "Boxton Content" region
    Then the "edit-follow" checkbox should not be checked
      And the "edit-expanded" checkbox should be checked
    When I check the box "edit-follow"
      And I uncheck the box "edit-expanded"
    When I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
      And I customize this page with the Panels IPE
      And I click "Settings" in the "Boxton Content" region
    Then the "edit-follow" checkbox should be checked
      And the "edit-expanded" checkbox should not be checked

