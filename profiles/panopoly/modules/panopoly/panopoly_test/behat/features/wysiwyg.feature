Feature: Use rich text editor
  In order to format the content of my pages
  As a site builder
  I need to be able to use a WYSIWYG editor

  Background:
    Given I am logged in as a user with the "administrator" role
    When I visit "/node/add/panopoly-test-page"
      And I fill in the following:
        | Title  | Testing WYSIWYG       |
        | Editor | panopoly_wysiwyg_text |

  # For some inexplicable reason this is necessary on Travis-CI. Without it,
  # the first test always fails: it can't find the "Bryant Content" region.
  @api @panopoly_wysiwyg
  Scenario: Fix issues on Travis-CI (not Chrome)
    # Normally, here we'd press "Publish", however some child distribtions
    # don't use 'save_draft', and this makes this test compatible with them.
    #When I press "Publish"
    When I press "edit-submit"

  @api @javascript @panopoly_wysiwyg
  Scenario Outline: Format text in the editor (first toolbar)
    When I click the "<Action>" button in the "edit-body-und-0-value" WYSIWYG editor
      And I type "Testing body" in the "edit-body-und-0-value" WYSIWYG editor
      #And I press "Publish"
      And I press "edit-submit"
    Then I should see "Testing body" in the "<Element>" element with the "<Property>" CSS property set to "<Value>" in the "Bryant Content" region

    Examples:
      | Action                        | Element    | Property        | Value        |
      | Bold                          | strong     |                 |              |
      | Italic                        | em         |                 |              |
      | Strikethrough                 | span       | text-decoration | line-through |
      | Insert/Remove Bulleted List   | ul > li    |                 |              |
      | Insert/Remove Numbered List   | ol > li    |                 |              |
      | Block Quote                   | blockquote |                 |              |
      | Align Left                    | p          | text-align      | left         |
      | Align Center                  | p          | text-align      | center       |
      | Align Right                   | p          | text-align      | right        |

  @api @javascript @panopoly_wysiwyg
  Scenario Outline: Format text in the editor (advanced toolbar)
    When I expand the toolbar in the "edit-body-und-0-value" WYSIWYG editor
      And I click the "<Action>" button in the "edit-body-und-0-value" WYSIWYG editor
      And I type "Testing body" in the "edit-body-und-0-value" WYSIWYG editor
      #And I press "Publish"
      And I press "edit-submit"
    Then I should see "Testing body" in the "<Element>" element with the "<Property>" CSS property set to "<Value>" in the "Bryant Content" region

    Examples:
      | Action          | Element | Property        | Value     |
      | Underline       | span    | text-decoration | underline |
      | Align Full      | p       | text-align      | justify   |
      | Increase Indent | p       | padding-left    | 30px      |
