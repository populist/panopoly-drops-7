Feature: Crop image
  In order to control display of my images
  As a site administrator
  I need to be able to manually crop an image
 
  @api @javascript @panopoly_widgets @local_files @drupal_private_files
  Scenario: Crop an image in the Image widget
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add image" in the "CTools modal" region
    Then I should see "Configure new Add image"
    When I fill in the following:
      | Title   | Testing image widget title |
      | Editor  | plain_text                 |
      | Caption | Testing caption            |
      And I click "Browse"
      And I switch to the frame "mediaBrowser"
      And I attach the file "test-sm.png" to "files[upload]"
      And I press "Next"
    Then I should see "Destination"
    When I select the radio button "Public local files served by the webserver."
      And I press "Next"
      And I wait 2 seconds
    Then I should see a "#edit-submit" element
      And I should see the "Crop" button in the "Media upload tab" region
      And I should not see the "Crop (cropped)" button in the "Media upload tab" region
    When I press "Crop"
    Then I should see "Maximize selection" in the "Manual Crop" region
    When I click "Maximize selection" in the "Manual Crop" region
      And I click "Save" in the "Manual Crop" region
    Then I should see the "Crop (cropped)" button in the "Media upload tab" region
    When I press the "Crop (cropped)" button
    Then I should see "Remove selection" in the "Manual Crop" region
    When I click "Remove selection" in the "Manual Crop" region
      And I click "Save" in the "Manual Crop" region
    Then I should see the "Crop" button in the "Media upload tab" region
      And I should not see the "Crop (cropped)" button in the "Media upload tab" region
    When I press "Save"
      And I switch out of all frames
      And I wait 2 seconds
    When I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing image widget title"
      And I should see "Testing caption"
