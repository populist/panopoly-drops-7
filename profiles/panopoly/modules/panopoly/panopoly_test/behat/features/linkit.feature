Feature: Link to page on the site
  In order to create links to my pages
  As a site builder
  I need to be able to use the Linkit function

  Background:
    Given I am logged in as a user with the "administrator" role
      And a "panopoly_test_page" with the title "Linkit Target"
    When I visit "/node/add/panopoly-test-page"
      And I fill in the following:
        | Title  | Testing Linkit       |
        | Editor | panopoly_wysiwyg_text |

  @api @javascript @panopoly_wysiwyg
  Scenario: Add a link to an internal page
    When I click the "Link to content" button in the "edit-body-und-0-value" WYSIWYG editor
      And I fill in "edit-linkit-search" with "target"
      And I wait 1 seconds
      And I press the "Tab" key in the "edit-linkit-search" field
    When I click "Options" in the "Linkit modal" region
      And I fill in "edit-linkit-title" with "Testing title"
      And I press "Insert link"
      # Normally, here we'd press "Publish", however some child distribtions
      # don't use 'save_draft', and this makes this test compatible with them.
      #And I press "Publish"
      And I press "edit-submit"
    Then I should see "Linkit Target" in the "a" element with the "title" attribute set to "Testing title" in the "Bryant Content" region
    When I click "Linkit Target"
    Then the "h1" element should contain "Linkit Target"

  @api @javascript @panopoly_wysiwyg
  Scenario: Add a link to an external page
    When I click the "Link to content" button in the "edit-body-und-0-value" WYSIWYG editor
      And I fill in "edit-linkit-path" with "https://drupal.org/project/panopoly"
      And I click "Options" in the "Linkit modal" region
      And I fill in "edit-linkit-title" with "Testing title"
      And I press "Insert link"
      # Normally, here we'd press "Publish", however some child distribtions
      # don't use 'save_draft', and this makes this test compatible with them.
      #And I press "Publish"
      And I press "edit-submit"
    Then I should see "https://drupal.org/project/panopoly" in the "a" element with the "title" attribute set to "Testing title" in the "Bryant Content" region
    When I click "https://drupal.org/project/panopoly"
    Then the "h1" element should contain "Panopoly"
