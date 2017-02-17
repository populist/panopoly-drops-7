Feature: Panopoly Magic improves the usability of forms (even without previews)
  In order to more easily place and edit widgets
  As a site administrator
  I need to see forms with improved user experience

  @api @javascript @panopoly_magic
  Scenario: Change the settings on an image field formatter
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a "panopoly_test_page" with the title "Testing title"
    When I customize this page with the Panels IPE
      # This only works because the image field pane is the first widget,
      # however, we should really target it directly somehow. The IPE needs to
      # be updated to name the buttons a little different for each pane which
      # would be good for accessibility too!
      And I click "Settings" in the "Bryant Content" region
    Then I should see "General Settings"
    When I press the "Continue" button
    Then I should see "General Settings"
      And the "Image style" select should be set to "Half width (of the containing region - could upscale small images)"
      And the "Link image to" select should be set to "Content"
    # Check that changing the values actually stick per Issue #2443499
    When I select "Full width (of the containing region - could upscale small images)" from "Image style"
      And I select "Nothing" from "Link image to"
      And I press the "Finish" button
    When I click "Settings" in the "Bryant Content" region
      And I press the "Continue" button
    Then I should see "General Settings"
      And the "Image style" select should be set to "Full width (of the containing region - could upscale small images)"
      And the "Link image to" select should be set to "Nothing"
    # Need to close out the dialog and save the IPE to prevent following tests
    # getting stuck!
    When I press the "Finish" button
      And I press "Save as custom"
      And I wait for the Panels IPE to deactivate

  @api @javascript @panopoly_magic
  Scenario: Ability to configure region styles that have settings.
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a "panopoly_test_page" with the title "Testing region style"
    When I customize this page with the Panels IPE
      And I click "Region style" in the "Bryant Content" region
    Then I should see "Style Settings"
    When I select the radio button "Panopoly Test: Style with settings" with the id "edit-style-panopoly-test-settings-style"
      And I press the "Next" button
    Then I should see "General Settings"
      And I should see "Quality of this widget"
      And I should not see the "#edit-cancel-style" element in the "Panopoly Magic Style Settings" region
      But I should see the "Cancel" button in the "CTools modal" region

  @api @javascript @panopoly_magic
  Scenario: Ability to configure pane styles that have settings.
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a "panopoly_test_page" with the title "Testing pane style"
    When I customize this page with the Panels IPE
      And I click "Style" in the "Bryant Content" region
    Then I should see "Style Settings"
    When I select the radio button "Panopoly Test: Style with settings" with the id "edit-style-panopoly-test-settings-style"
      And I press the "Next" button
    Then I should see "General Settings"
      And I should see "Quality of this widget"
      And I should not see the "#edit-cancel-style" element in the "Panopoly Magic Style Settings" region
      But I should see the "Cancel" button in the "CTools modal" region
