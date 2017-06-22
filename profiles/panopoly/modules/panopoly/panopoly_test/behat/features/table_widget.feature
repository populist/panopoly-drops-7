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

  @api @javascript
  Scenario: Add table to a page
    When I fill in the following:
      | Title                 | Widget title |
      | field_basic_table_table[und][0][tablefield][cell_0_0] | c-1-r-1      |
      | field_basic_table_table[und][0][tablefield][cell_0_1] | c-2-r-1      |
      | field_basic_table_table[und][0][tablefield][cell_1_0] | c-1-r-2      |
      | field_basic_table_table[und][0][tablefield][cell_1_1] | c-2-r-2      |
      | field_basic_table_table[und][0][tablefield][cell_2_0] | c-1-r-3      |
      | field_basic_table_table[und][0][tablefield][cell_2_1] | c-2-r-3      |
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Widget title"
      And I should see "c-2-r-3"

  @api @javascript
  Scenario: Add table with custom columns and rows
    When I fill in the following:
      | Title                                                            | Widget title |
      | field_basic_table_table[und][0][tablefield][rebuild][count_cols] | 3            |
      | field_basic_table_table[und][0][tablefield][rebuild][count_rows] | 2            |
      And I press "Rebuild Table"
    Then I should see "Table structure rebuilt."
    When I fill in the following:
      | field_basic_table_table[und][0][tablefield][cell_0_0] | c-1-r-1      |
      | field_basic_table_table[und][0][tablefield][cell_0_1] | c-2-r-1      |
      | field_basic_table_table[und][0][tablefield][cell_0_2] | c-3-r-1      |
      | field_basic_table_table[und][0][tablefield][cell_1_0] | c-1-r-2      |
      | field_basic_table_table[und][0][tablefield][cell_1_1] | c-2-r-2      |
      | field_basic_table_table[und][0][tablefield][cell_1_2] | c-3-r-2      |
      And I press "Add" in the "CTools modal" region
      And I press "Save"
      And I wait for the Panels IPE to deactivate
    Then I should see "Widget title"
      And I should see "c-3-r-2"
