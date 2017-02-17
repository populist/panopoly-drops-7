Feature: Demo content
  In order to test out the site
  As a site owner
  I need to view demo content

  @panopoly_demo
  Scenario: Homepage
    Given I am an anonymous user
    When I visit "/demo"
    Then the "h1" element should contain "Homepage Demo"

  @panopoly_demo
  Scenario: Demo content is imported via Migrate
    Given I am an anonymous user
    When I visit "/demo"
        And I click "Vegetables are Great"
    Then the "h1" element should contain "Vegetables are Great"
    When I click "Great Vegetables" in the "Main menu" region
    Then the "h1" element should contain "Great Vegetables"
    When I click "Lovely Vegetables" in the "Main menu" region
    Then the "h1" element should contain "Lovely Vegetables"

  @panopoly_demo @api
  Scenario: Demo content menu items are created
    Given I am logged in as a user with the "administrator" role
    When I visit "/admin/structure/menu/manage/main-menu/edit"
    Then I should see "Great Vegetables" in the "Content" region
      And I should see "Lovely Vegetables" in the "Content" region