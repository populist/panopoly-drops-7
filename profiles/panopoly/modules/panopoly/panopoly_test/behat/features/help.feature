Feature: View system help
  In order to understand how to administer the site
  As a site owner
  I need to be able to view content in the system help region

  @api @panopoly_demo
  Scenario: Create Test Page
    Given I am logged in as a user with the "administrator" role
    When I visit "/node/add/panopoly-test-page"
    Then I should see "This message appears in the system help region when you create a node."
