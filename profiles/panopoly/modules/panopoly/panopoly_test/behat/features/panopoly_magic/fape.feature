Feature: Edit field content in the IPE via FAPE
  In order to edit content in place
  As a site administrator
  I need to be able to edit field content in the IPE

  Background:
  Given I am logged in as a user with the "administrator" role
    And Panopoly magic live previews are automatic
    And I visit "/node/add/panopoly-test-page"

  @api @javascript @panopoly_magic
  Scenario: Edit body field with FAPE
      When I fill in the following:
        | Title               | Testing title                     |
        | Full page override  | node:panopoly_test_page:body_only |
        | Editor              | plain_text                        |
        | body[und][0][value] | Testing body                      |
      And I press "edit-submit"
    Then I should see "Testing body"
    When I customize this page with the Panels IPE
      And I click "Settings" in the "Boxton Content" region
      And I fill in "body[und][0][value]" with "This is the new body"
      And I wait for live preview to finish
    Then I should see "This is the new body" in the "Live preview" region
    When I press "Continue" in the "CTools modal" region
      And I press "Finish" in the "CTools modal" region
      And I press "Save as custom"
      And I wait for the Panels IPE to deactivate
    Then I should not see "Testing body"
      And I should see "This is the new body"

@api @javascript @panopoly_pages @local_files
  Scenario: Change image style with FAPE
    When I fill in the following:
      | Title               | Testing title |
      | Editor              | plain_text    |
      | body[und][0][value] | Testing body  |
      And I attach the file "test-lg.png" to "files[field_featured_image_und_0]"
      And I press "edit-submit"
    Then I should see "Testing body"
    When I customize this page with the Panels IPE
      And I click "Settings" in the "Bryant Content" region
      And I press "Continue" in the "CTools modal" region
    Then I should see the "img" element with the "class" attribute set to "panopoly-image-half" in the "Live preview" region
    When I select "panopoly_image_quarter" from "Image style"
      And I wait for live preview to finish
    Then I should see the "img" element with the "class" attribute set to "panopoly-image-quarter" in the "Live preview" region
