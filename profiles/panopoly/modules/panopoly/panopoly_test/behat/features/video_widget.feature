Feature: Add video widget
  In order to add a video
  As a site administrator
  I need to be able to use the video widget

  Background:
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane" in the "Boxton Content" region
      And I click "Add video" in the "CTools modal" region
    Then I should see "Configure new Add video"

  @api @javascript @panopoly_widgets
  Scenario: Add a YouTube video
    When I fill in "Testing video" for "edit-title"
    When I click "Browse"
      And I switch to the frame "mediaBrowser"
    Then I should see "Supported internet media providers"
      And I should see "YouTube"
    When I fill in "File URL or media resource" with "https://www.youtube.com/watch?v=1TV0q4Sdxlc"
      And I press "Next"
      And I switch out of all frames
      And I wait 2 seconds
    Then I should see the "Remove" button in the "CTools modal" region
      # TODO: Disabled until #2264187 is fixed!
      #And I should see "Edit"
    When I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing video"
    Then I should see the "iframe.media-youtube-player" element in the "Boxton Content" region

  @api @javascript @panopoly_widgets
  Scenario: Add a Vimeo video
    When I fill in "Testing video" for "edit-title"
    When I click "Browse"
      And I switch to the frame "mediaBrowser"
    Then I should see "Supported internet media providers"
      And I should see "Vimeo"
    When I fill in "File URL or media resource" with "http://vimeo.com/59482983"
      And I press "Next"
      And I switch out of all frames
      And I wait 2 seconds
    Then I should see the "Remove" button in the "CTools modal" region
      # TODO: Disabled until #2264187 is fixed!
      #And I should see "Edit"
    When I press "Save" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing video"
    Then I should see the "iframe.media-vimeo-player" element in the "Boxton Content" region
