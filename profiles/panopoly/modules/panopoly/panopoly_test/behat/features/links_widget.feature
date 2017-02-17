Feature: Add links widget
  In order to add a list with links
  As a site administrator
  I need to be able to use the links widget
 
  @api @javascript @panopoly_widgets
  Scenario: Add links
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add links" in the "CTools modal" region
    Then I should see "Configure new Add links"
    When I fill in the following:
      | title                                  | Testing link title  |      
      | field_quick_links_links[und][0][title] | Testing url title   |
      | field_quick_links_links[und][0][url]   | http://drupal.org   |
      And I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing link title"
      And I should see "Testing url title"
      # Despite what the docs say, we the XPath for finding links as defined in
      # Mink/Selector/NamedSelector.php doesn't search the 'href' attribute.
      # @todo: We should find a way to test that the link is correct!
      #And I should see the link "http://drupal.org"
