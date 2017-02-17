Feature: Add media using the rich text editor
  In order to add visual interest to my pages
  As a site builder
  I need to be able to insert media using the WYSIWYG editor

  Background:
    Given I am logged in as a user with the "administrator" role
    When I visit "/node/add/panopoly-test-page"
      And I fill in the following:
        | Title  | Testing WYSIWYG       |
        | Editor | panopoly_wysiwyg_text |

  # For some inexplicable reason this is necessary on Travis-CI. Without it,
  # the first test always fails: it can't find the "Bryant Content" region.
  @api @chrome @panopoly_wysiwyg @panopoly_wysiwyg_image @panopoly_images @drupal_private_files
  Scenario: Fix issues on Travis-CI (on Chrome)
    # Normally, here we'd press "Publish", however some child distribtions
    # don't use 'save_draft', and this makes this test compatible with them.
    #When I press "Publish"
    When I press "edit-submit"

  # TODO: About 10% of the time this test will hang with Firefox, so for now,
  # we will run in Chrome only on Travis-CI to get consistent builds.
  @api @javascript @chrome @panopoly_wysiwyg @panopoly_wysiwyg_image @panopoly_images @drupal_private_files
  Scenario: Upload an image with format and alt text
    When I type "Testing body" in the "edit-body-und-0-value" WYSIWYG editor
    # Upload the file.
    When I click the "Add media" button in the "edit-body-und-0-value" WYSIWYG editor
      And I switch to the frame "mediaBrowser"
      And I attach the file "test-sm.png" to "files[upload]"
      And I press "Next"
    Then I should see "Destination"
    # Select the destination (public/private files).
    When I select the radio button "Public local files served by the webserver."
      And I press "Next"
    Then I should see a "#edit-submit" element
      And I should see the "Crop" button
    # Fields for the image.
    When I fill in the following:
        | Alt Text   | Sample alt text   |
        | Title Text | Sample title text |
      And I press "Save"
    # The media style selector.
    When I wait 2 seconds
      And I switch to the frame "mediaStyleSelector"
      And I select "Quarter Size" from "format"
    Then the "Alt Text" field should contain "Sample Alt text"
      And the "Title Text" field should contain "Sample Title text"
      And I click the fake "Submit" button
      And I switch out of all frames
    # Save the whole node.
    #When I press "Publish"
    When I press "edit-submit"
    # See the image on the view page.
    Then I should see the "img" element in the "Bryant Content" region
      And I should see the image alt "Sample alt text" in the "Bryant Content" region

  # TODO: About 10% of the time this test will hang with Firefox, so for now,
  # we will run in Chrome only on Travis-CI to get consistent builds.
  @api @javascript @chrome @panopoly_wysiwyg @panopoly_wysiwyg_image @panopoly_images @drupal_private_files
  Scenario: The second alt/title text sticks
    When I type "Testing body" in the "edit-body-und-0-value" WYSIWYG editor
    When I click the "Add media" button in the "edit-body-und-0-value" WYSIWYG editor
      And I switch to the frame "mediaBrowser"
      And I attach the file "test-sm.png" to "files[upload]"
      And I press "Next"
    Then I should see "Destination"
    When I select the radio button "Public local files served by the webserver."
      And I press "Next"
    Then I should see a "#edit-submit" element
    # We need to set the alt/title text differently in the two steps that ask
    # for it - so, that we can test that the 2nd overrides.
    When I fill in the following:
        | Alt Text   | First alt text   |
        | Title Text | First title text |
      And I press "Save"
    When I wait 2 seconds
      And I switch to the frame "mediaStyleSelector"
    Then the "Alt Text" field should contain "First Alt text"
      And the "Title Text" field should contain "First Title text"
    When I fill in the following:
        | Alt Text   | Second alt text   |
        | Title Text | Second title text |
    When I click the fake "Submit" button
      And I switch out of all frames
    # Save the whole node.
    When I press "edit-submit"
    # See the image with the 2nd alt text.
    Then I should see the "img" element in the "Bryant Content" region
      And I should see the image alt "Second alt text" in the "Bryant Content" region
    # Next, we edit the node again, so we can verify that the second
    # alt text will load when editing the image again.
    When I click "Edit" in the "Tabs" region
      And I click the "img" element in the "edit-body-und-0-value" WYSIWYG editor
      And I click the "Add media" button in the "edit-body-und-0-value" WYSIWYG editor
      And I switch to the frame "mediaStyleSelector"
    Then the "Alt Text" field should contain "Second Alt text"
      And the "Title Text" field should contain "Second Title text"
      And I switch out of all frames

  # TODO: About 10% of the time this test will hang with Firefox, so for now,
  # we will run in Chrome only on Travis-CI to get consistent builds.
  @api @javascript @chrome @panopoly_wysiwyg @panopoly_wysiwyg_image @panopoly_images @drupal_private_files
  Scenario: HTML entities in alt/title text get decoded/encoded correctly
    When I type "Testing body" in the "edit-body-und-0-value" WYSIWYG editor
    When I click the "Add media" button in the "edit-body-und-0-value" WYSIWYG editor
      And I switch to the frame "mediaBrowser"
      And I attach the file "test-sm.png" to "files[upload]"
      And I press "Next"
    Then I should see "Destination"
    When I select the radio button "Public local files served by the webserver."
      And I press "Next"
    Then I should see a "#edit-submit" element
    # We need to set the alt/title text differently in the two steps that ask
    # for it - so, that we can test that the 2nd overrides.
    When I fill in the following:
        | Alt Text   | Alt & some > "character's" <   |
        | Title Text | Title & some > "character's" < |
      And I press "Save"
    When I wait 2 seconds
      And I switch to the frame "mediaStyleSelector"
    When I click the fake "Submit" button
      And I switch out of all frames
    # Save the whole node.
    When I press "edit-submit"
    # See the image with the 2nd alt text.
    Then I should see the "img" element in the "Bryant Content" region
      And I should see the image alt "Alt & some > \"character's\" <" in the "Bryant Content" region
    # Next, we edit the node again, so we can verify that the second
    # alt text will load when editing the image again.
    When I click "Edit" in the "Tabs" region
      And I click the "img" element in the "edit-body-und-0-value" WYSIWYG editor
      And I click the "Add media" button in the "edit-body-und-0-value" WYSIWYG editor
      And I switch to the frame "mediaStyleSelector"
    Then the "Alt Text" field should contain "Alt & some > \"character's\" <"
      And the "Title Text" field should contain "Title & some > \"character's\" <"
      And I switch out of all frames

  @api @javascript @chrome @panopoly_wysiwyg @panopoly_wysiwyg_image @panopoly_images @drupal_private_files
  Scenario: Use an image from elsewhere on the web
    When I type "Testing body" in the "edit-body-und-0-value" WYSIWYG editor
      And I click the "Add media" button in the "edit-body-und-0-value" WYSIWYG editor
      And I switch to the frame "mediaBrowser"
      And I click "Web"
    Then I should see "File URL or media resource"
    When I fill in "File URL or media resource" with "https://www.drupal.org/files/drupal_logo-blue.png"
      And I press "Next" in the "Media web tab" region
    Then I should see "Destination"
    # Select the destination (public/private files).
    When I select the radio button "Public local files served by the webserver."
      And I press "Next" in the "Media web tab" region
    Then I should see a "#edit-submit" element
      And I should see the "Crop" button
    # Fields for the image.
    When I fill in the following:
        | Alt Text   | Sample alt text   |
        | Title Text | Sample title text |
      And I press "Save"
    # The media style selector.
    When I wait 2 seconds
      And I switch to the frame "mediaStyleSelector"
      And I select "Quarter Size" from "format"
    Then the "Alt Text" field should contain "Sample Alt text"
      And the "Title Text" field should contain "Sample Title text"
      And I click the fake "Submit" button
      And I switch out of all frames
      And I press "edit-submit"
    # See the image on the view page.
    Then I should see the "img" element in the "Bryant Content" region
      And I should see the image alt "Sample alt text" in the "Bryant Content" region

  # TODO: About 10% of the time this test will hang with Firefox, so for now,
  # we will run in Chrome only on Travis-CI to get consistent builds.
  @api @javascript @chrome @panopoly_wysiwyg @panopoly_wysiwyg_video @panopoly_widgets
  Scenario: Add a YouTube video
    When I type "Testing body" in the "edit-body-und-0-value" WYSIWYG editor
    # Upload the file.
    When I click the "Add media" button in the "edit-body-und-0-value" WYSIWYG editor
      And I switch to the frame "mediaBrowser"
      And I click "Web"
      And I fill in "File URL or media resource" with "https://www.youtube.com/watch?v=W_-vFa-IyB8"
      And I press "Next" in the "Media web tab" region
      And I wait 2 seconds
    When I switch to the frame "mediaStyleSelector"
    Then I should see "Minecraft: Development history"
    When I select "Default" from "format"
      And I click the fake "Submit" button
      And I switch out of all frames
    # Save the whole node.
    #When I press "Publish"
    When I press "edit-submit"
    # See the image on the view page.
    Then I should see the "iframe.media-youtube-player" element in the "Bryant Content" region

  # TODO: About 10% of the time this test will hang with Firefox, so for now,
  # we will run in Chrome only on Travis-CI to get consistent builds.
  @api @javascript @chrome @panopoly_wysiwyg @panopoly_wysiwyg_video @panopoly_widgets
  Scenario: Add a Vimeo video
    When I type "Testing body" in the "edit-body-und-0-value" WYSIWYG editor
    # Upload the file.
    When I click the "Add media" button in the "edit-body-und-0-value" WYSIWYG editor
      And I switch to the frame "mediaBrowser"
      And I click "Web"
      And I fill in "File URL or media resource" with "http://vimeo.com/59482983"
      And I press "Next" in the "Media web tab" region
      And I wait 2 seconds
    When I switch to the frame "mediaStyleSelector"
    Then I should see "Panopoly by Troels Lenda"
    When I select "Default" from "format"
      And I click the fake "Submit" button
      And I switch out of all frames
    # Save the whole node.
    #When I press "Publish"
    When I press "edit-submit"
    # See the image on the view page.
    Then I should see the "iframe.media-vimeo-player" element in the "Bryant Content" region
