Feature: Add content page
  In order to create a page with content
  As a site administrator
  I need to be able create a content page

  Background: 
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
    When I visit "/node/add/panopoly-page"
      And I fill in the following:
        | Title               | Testing title |
        | Editor              | plain_text    |
        | body[und][0][value] | Testing body  |

  @api @panopoly_pages
  Scenario: Add a content page
    # Normally, here we'd press "Publish", however some child distribtions
    # don't use 'save_draft', and this makes this test compatible with them.
    #When I press "Publish"
    When I press "edit-submit"
    Then the "h1" element should contain "Testing title"

  @api @javascript @panopoly_pages @local_files
  Scenario: Add a Featured Image with incorrect dimensions
    When I attach the file "test-sm.png" to "files[field_featured_image_und_0]"
    Then I should see "The specified file test-sm.png could not be uploaded. The image is too small; the minimum dimensions are 300x200 pixels."

  @api @javascript @panopoly_pages @local_files
  Scenario: Add a Featured image
    # Revisting the page will not be necessary when https://drupal.org/node/2281709 is resolved
    When I visit "/node/add/panopoly-page"
      And I fill in the following:
      | Title               | Testing title |
      | Editor              | plain_text    |
      | body[und][0][value] | Testing body  |
      And I attach the file "test-lg.png" to "files[field_featured_image_und_0]"
    Then I should not see "The specified file test-lg.png could not be uploaded. The image is too small; the minimum dimensions are 300x200 pixels."
    When I fill in "Alt Text" with "Panopoly rocks"
      #And I press "Publish"
      And I press "edit-submit"
    Then I should see the link "Edit" in the "Tabs" region
    When I click "Edit" in the "Tabs" region
    Then the "field_featured_image[und][0][alt]" field should contain "Panopoly rocks"
