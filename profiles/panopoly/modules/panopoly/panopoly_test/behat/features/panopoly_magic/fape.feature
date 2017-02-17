Feature: Edit field content in the IPE via FAPE
  In order to edit content in place
  As a site administrator
  I need to be able to edit field content in the IPE

  @api @javascript
  Scenario: Edit body field with FAPE
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
    When I visit "/node/add/panopoly-test-page"
      And I fill in the following:
        | Title               | Testing title                     |
        | Full page override  | node:panopoly_test_page:body_only |
        | Editor              | plain_text                        |
        | body[und][0][value] | Testing body                      |
      And I press "edit-submit"
    Then I should see "Testing body"
    When I customize this page with the Panels IPE
      And I click "Settings" in the "Boxton Content" region
      And I fill in "body[und][0][value]" with "This is the new body"
      And I press "Continue" in the "CTools modal" region
      And I press "Finish" in the "CTools modal" region
      And I press "Save as custom"
      And I wait for the Panels IPE to deactivate
    Then I should not see "Testing body"
      And I should see "This is the new body"
