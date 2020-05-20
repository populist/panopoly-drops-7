Feature: Add table widget
  In order to put a table on a page
  As a site administrator
  I need to be able to use the table widget

  Background:
    Given I am logged in as a user with the "administrator" role
      And Panopoly magic live previews are disabled
      And I am viewing a landing page
    When I customize this page with the Panels IPE
      And I click "Add new pane"
      And I click "Add table" in the "CTools modal" region
    Then I should see "Configure new Add table"

  @api @javascript @panopoly_widgets
  Scenario: Add table to a page
    When I fill in the following:
      | Title                 | Widget title |
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_0] | c-1-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_1] | c-2-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_0] | c-1-r-2      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_1] | c-2-r-2      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_2][col_0] | c-1-r-3      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_2][col_1] | c-2-r-3      |
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Widget title"
      And I should see "c-2-r-3"

  @api @javascript @panopoly_widgets
  Scenario: Add table with custom columns and rows
    When I fill in the following:
      | Title                                                            | Widget title |
      | field_basic_table_table[und][0][tablefield][rebuild][count_cols] | 3            |
      | field_basic_table_table[und][0][tablefield][rebuild][count_rows] | 2            |
      And I press "Rebuild Table"
    Then I should see "Table structure rebuilt."
    When I fill in the following:
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_0] | c-1-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_1] | c-2-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_2] | c-3-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_0] | c-1-r-2      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_1] | c-2-r-2      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_2] | c-3-r-2      |
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Widget title"
      And I should see "c-3-r-2"
      And I should see "c-1-r-1" in the "th" element with the "scope" attribute set to "col" in the "Boxton Content" region

  @api @javascript @panopoly_widgets
  Scenario: Set header orientation to Vertical
    When I fill in the following:
      | Title                                                            | Widget title |
      | field_basic_table_table[und][0][tablefield][rebuild][count_cols] | 3            |
      | field_basic_table_table[und][0][tablefield][rebuild][count_rows] | 2            |
      And I select "Vertical" from "Header orientation"
      And I press "Rebuild Table"
    Then I should see "Table structure rebuilt."
    When I fill in the following:
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_0] | c-1-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_1] | c-2-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_2] | c-3-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_0] | c-1-r-2      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_1] | c-2-r-2      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_2] | c-3-r-2      |
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Widget title"
      And I should see "c-3-r-2"
      And I should see "c-1-r-2" in the "th" element in the "Boxton Content" region

  @api @javascript @panopoly_widgets
  Scenario: Set header orientation to Both
    When I fill in the following:
      | Title                                                            | Widget title |
      | field_basic_table_table[und][0][tablefield][rebuild][count_cols] | 3            |
      | field_basic_table_table[und][0][tablefield][rebuild][count_rows] | 2            |
      And I select "Both" from "Header orientation"
      And I press "Rebuild Table"
    Then I should see "Table structure rebuilt."
    When I fill in the following:
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_0] | c-1-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_1] | c-2-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_0][col_2] | c-3-r-1      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_0] | c-1-r-2      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_1] | c-2-r-2      |
      | field_basic_table_table[und][0][tablefield][tabledata][row_1][col_2] | c-3-r-2      |
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Widget title"
      And I should see "c-3-r-2"
      And I should see "c-1-r-2" in the "th" element in the "Boxton Content" region
      And I should see "c-2-r-1" in the "th" element with the "scope" attribute set to "col" in the "Boxton Content" region
