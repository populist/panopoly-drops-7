Feature: Search
  In order to find content on the site
  As an anonymous user
  I should be able to find content using the site search

  @panopoly_search
  Scenario: Trying an empty search should yield a message
    Given I am on the homepage
    When I press "Search" in the "Search" region
    Then I should not see "Search Results"
      And I should see "Search"
      And I should see "Enter your keywords"
      And I should see "Please enter some keywords"

  @panopoly_search
  Scenario: Trying a search with no results
    Given I am on the homepage
    When I fill in "TkyXNk9NG2U7FjqtMvNvHXpv2xnfVv7Q" for "Enter your keywords" in the "Search" region
      And I press "Search" in the "Search" region
    Then I should see "Search Results"
      And I should see "0 items matched TkyXNk9NG2U7FjqtMvNvHXpv2xnfVv7Q"
      And I should see "Your search did not return any results."

  @api @panopoly_search
  Scenario: Performing a search with results
    Given I am on the homepage
    And "panopoly_test_page" content:
      | title           | body        | created            | status |
      | fxabR86L Page 1 | Test page 1 | 01/01/2001 11:00am |      1 |
      | fxabR86L Page 2 | Test page 2 | 01/02/2001 11:00am |      1 |
      | X9A1YXwc Page 3 | Test page 3 | 01/03/2001 11:00am |      1 |
      And I run drush "cron"
    When I fill in "fxabR86L" for "Enter your keywords" in the "Search" region
      And I press "Search" in the "Search" region
    Then I should see "Search Results"
      And I should see "2 items matched fxabR86L"
      And I should see "Filter by Type"
      And I should not see "X9A1YXwc"

  @api @javascript @panopoly_search
  Scenario: Search for content in widgets (not in the body)
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a "panopoly_test_page" with the title "Abracadabra"
    # Put a text widget on our test node.
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
      And I fill in the following:
        | Title   | Text widget title |
        | Editor  | plain_text        |
        | Text    | Undominable       |
      And I press "Add" in the "CTools modal" region
      And I press "Save as custom"
      And I wait for the Panels IPE to deactivate
      # Run cron to make sure the page is indexed.
      And I run drush "cron"
    # Now, return to the home page and search for it.
    Given I am an anonymous user
      And I am on the homepage
    When I fill in "undominable" for "Enter your keywords" in the "Search" region
      And I press "Search" in the "Search" region
    Then I should see "Search Results"
      And I should see "1 item matched undominable"
      And I should see "Abracadabra"

  @api @panopoly_search
  Scenario: New content should be indexed immediately
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
    When I visit "/node/add/panopoly-test-page"
      And I fill in the following:
        | Title               | Searchable page |
        | Editor              | plain_text |
        | body[und][0][value] | RnJpIEZlYiAgNSAwODoyMToyMiBQU1QgMjAxNgo |
      And I press "edit-submit"
    Then the "h1" element should contain "Searchable page"
    # Check for the content.
    Given I am an anonymous user
      And I am on the homepage
    When I fill in "RnJpIEZlYiAgNSAwODoyMToyMiBQU1QgMjAxNgo" for "Enter your keywords" in the "Search" region
      And I press "Search" in the "Search" region
    Then I should see "Search Results"
      And I should see "1 item matched RnJpIEZlYiAgNSAwODoyMToyMiBQU1QgMjAxNgo"
      And I should see "Searchable page"

  @api @panopoly_search @dblog
  Scenario: Search queries are logged in the 'Top search phrases' report
    Given I am logged in as a user with the "administrator" role
      And I am on the homepage
      And the dblog is empty
    When I fill in "wzbb5bDcKu" for "Enter your keywords" in the "Search" region
      And I press "Search" in the "Search" region
    When I visit "/admin/reports/search"
    Then I should see "Top search phrases"
      And I should see "Searched Content for wzbb5bDcKu"
