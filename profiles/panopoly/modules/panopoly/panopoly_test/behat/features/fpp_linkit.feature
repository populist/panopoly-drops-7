Feature: Use linkit for title links on any widget
  In order to make widget titles into links
  As a site builder
  I need to be able to use the Linkit function

  # NOTE: we use the @panopoly_wysiwyg tag because that is where Linkit comes
  #       from in a default install.
  @api @javascript @panopoly_widgets @panopoly_wysiwyg
  Scenario: Linkit should work when making the title a link
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
    When I fill in "Title" with "Widget title 1"
      And I check the box "Make title a link"
      And I click "Search for existing content" in the "CTools modal" region
    Then I should see "Linkit"

