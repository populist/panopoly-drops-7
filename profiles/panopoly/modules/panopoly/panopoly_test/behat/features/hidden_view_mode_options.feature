Feature: Hidden view mode options
  In order to simplify the widget configuration process
  As a site administrator
  I need to limit the view mode options displayed

  @api @javascript @panopoly_magic
  Scenario: Make sure that the right view modes are hidden by default
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are disabled
      And I run drush "vdel" "panopoly_magic_hidden_view_mode_options -y"
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "View panes" in the "CTools modal" region
      And I click "View: Magic View Modes: Fields" in the "CTools modal" region
    Then I should see "Configure new View: Magic View Modes: Fields"
    When I select the radio button "Content"
    Then I should see the radio button "Full content"
      And I should see the radio button "Teaser"
      And I should see the radio button "Featured"
      And I should not see the radio button "RSS"
      And I should not see the radio button "Search index"
      And I should not see the radio button "Search result"
      And I should not see the radio button "Revision comparison"
      And I should not see the radio button "Tokens"

  @api @javascript @panopoly_magic
  Scenario: Configure which view modes are available on Views
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are disabled
      And I run drush "vdel" "panopoly_magic_hidden_view_mode_options -y"
      And I visit "/admin/panopoly/settings/panopoly_magic"
    When I click "Show Advanced"
      And I fill in "Hidden view mode options" with "full\nteaser\nfeatured\ndiff_standard"
      And I press "Save configuration"
    Given I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "View panes" in the "CTools modal" region
      And I click "View: Magic View Modes: Fields" in the "CTools modal" region
    Then I should see "Configure new View: Magic View Modes: Fields"
    When I select the radio button "Content"
    Then I should not see the radio button "Full content"
      And I should not see the radio button "Teaser"
      And I should not see the radio button "Featured"
      And I should not see the radio button "Revision comparison"
      And I should see the radio button "RSS"
      And I should see the radio button "Search index"
      And I should see the radio button "Search result"
      And I should see the radio button "Tokens"
    # Clean up after ourselves.
    When I run drush "vdel" "panopoly_magic_hidden_view_mode_options -y" 

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: With vanilla Panopoly, we shouldn't see the 'View mode' selector on FPPs
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are manual
      And Panopoly magic add content previews are disabled
      And I run drush "vdel" "panopoly_magic_hidden_view_mode_options -y"
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
      And I should not see "Select a view mode for this pane."

  @api @javascript @panopoly_magic @panopoly_widgets
  Scenario: Configure which view modes are available on FPPs
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And Panopoly magic add content previews are disabled
      And I run drush "vdel" "panopoly_magic_hidden_view_mode_options -y"
      And I visit "/admin/panopoly/settings/panopoly_magic"
    When I click "Show Advanced"
      And I fill in "Hidden view mode options" with "diff_standard"
      And I press "Save configuration"
    Given I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add text" in the "CTools modal" region
    Then I should see "Configure new Add text"
      And I should see "Select a view mode for this pane."
    # Check for the options, but attempting to select them.
    When I select "Full" from "View mode"
      And I select "Preview" from "View mode"
      And I select "Tokens" from "View mode"
    # Clean up after ourselves.
    When I run drush "vdel" "panopoly_magic_hidden_view_mode_options -y" 
