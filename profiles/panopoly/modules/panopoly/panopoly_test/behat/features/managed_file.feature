Feature: Managed file
  In order to provide information to visitors
  As a site owner
  I need to be able to link to uploaded files

  @api
  Scenario: Managed file
    Given I am logged in as a user with the "administrator" role
      And the managed file "test.txt"
    When I visit "admin/content/file"
    Then I should see the link "test.txt"
