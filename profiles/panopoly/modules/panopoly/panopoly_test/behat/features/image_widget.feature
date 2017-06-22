Feature: Add image widget
  In order to add an image to page
  As a site administrator
  I need to be able to use the image widget
 
  @api @javascript @panopoly_widgets @local_files
  Scenario: Add a image
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
      And I should see the "Crop" button
    When I fill in the following:
        | Alt Text   | Testing alt text   |
        | Title Text | Testing title text |
      And I press "Save"
      And I switch out of all frames
      And I wait 2 seconds
    When I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing image widget title"
      And I should see "Testing caption"
      And I should see the image alt "Testing alt text" in the "Boxton Content" region
      And I should not see the link "Testing alt text" in the "Boxton Content" region

  @api @javascript @panopoly_widgets @local_files
  Scenario: Add an image with link
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add image" in the "CTools modal" region
    Then I should see "Configure new Add image"
    When I fill in the following:
      | Title   | Testing image widget title              |
      | Editor  | plain_text                              |
      | URL     | https://www.drupal.org/project/panopoly |
      And I click "Browse"
      And I switch to the frame "mediaBrowser"
      And I attach the file "test-sm.png" to "files[upload]"
      And I press "Next"
    Then I should see "Destination"
    When I select the radio button "Public local files served by the webserver."
      And I press "Next"
      And I wait 2 seconds
    Then I should see a "#edit-submit" element
      And I should see the "Crop" button
    When I fill in the following:
        | Alt Text   | Testing alt text   |
        | Title Text | Testing title text |
      And I press "Save"
      And I switch out of all frames
      And I wait 2 seconds
    When I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Testing image widget title"
      And I should see the image alt "Testing alt text" in the "Boxton Content" region
      And I should see the link "Testing alt text" in the "Boxton Content" region
    When I follow "Testing alt text" in the "Boxton Content" region
    Then the url should match "/project/panopoly"

  # TODO: we use the @panopoly_wysiwyg tag because that is where Linkit comes
  #       from in a default install.
  @api @javascript @panopoly_widgets @panopoly_wysiwyg
  Scenario: Add an image with Linkit support
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add image" in the "CTools modal" region
    Then I should see "Configure new Add image"
    When I click the 2nd "Search for existing content" in the "CTools modal" region
    Then I should see "Linkit"

