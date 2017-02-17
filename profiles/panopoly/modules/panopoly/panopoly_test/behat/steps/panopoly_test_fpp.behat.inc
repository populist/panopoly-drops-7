<?php
/**
 * @file
 * Provide Behat step-definitions for Fieldable Panels Panes.
 *
 * @todo This should become fieldable_panels_panes.behat.inc in the Fieldable Panels Panes module!
 */

use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Drupal\DrupalExtension\Hook\Scope\AfterUserCreateScope;

class FieldablePanelsPanesSubContext extends RawDrupalContext implements DrupalSubContextInterface {

  /**
   * Contains the DrupalDriverManager.
   *
   * @var \Drupal\DrupalDriverManager
   */
  private $drupal;

  /**
   * An array of Drupal users created by other contexts.
   *
   * @var array
   */
  protected $external_users = array();

  /**
   * Initializes context.
   */
  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Get a Fieldable Panels Pane by admin title.
   *
   * @param string $admin_title
   *   The admin title of the FPP to retrieve.
   *
   * @return object
   *   The Fieldable Panels Pane entity object.
   */
  protected function getFPPByAdminTitle($admin_title) {
    $fpps = fieldable_panels_panes_load_multiple(array(), array('admin_title' => $admin_title));
    if (empty($fpps)) {
      throw new \Exception(sprintf('Fieldable panels pane "%s" was not found', $admin_title));
    }
    return reset($fpps);
  }

  /**
   * Get the list of revisions for a Fieldable Panels Pane.
   *
   * @param int $fpid
   *   The ID for the Fieldable Panels Pane.
   */
  protected function getFPPRevisions($fpid) {
    return db_query("SELECT * FROM {fieldable_panels_panes_revision} WHERE fpid = :fpid", array(':fpid' => $fpid))->fetchAll();
  }

  /**
   * Record all the users created during this scenario.
   *
   * We need to use this hook so we can get users created in steps on other
   * contexts (most probably the DrupalContext).
   *
   * @AfterUserCreate
   */
  public function afterUserCreate(AfterUserCreateScope $scope) {
    $user = $scope->getEntity();
    $this->external_users[$user->name] = $user;
  }

  /**
   * Get a list of UIDs.
   *
   * @return
   *   An array of numeric UIDs of users created by Given... steps during this scenario.
   */
  public function getUIDs() {
    $uids = array();
    foreach ($this->external_users as $user) {
      $uids[] = $user->uid;
    }
    return $uids;
  }

  /**
   * Cleans up FPPs.
   *
   * @AfterScenario @api
   */
  public function cleanFPPs($event) {
    $fpids = array();

    // Get UIDs of users created during this scenario.
    $uids = $this->getUIDs();
    if (!empty($uids)) {
      // Find any FPPs created by the test users.
      // First, get a list of FPPs with their first revision VID.
      $fpp_vids = db_query('SELECT min(vid) AS vid FROM {fieldable_panels_panes_revision} GROUP BY fpid')->fetchAll();
      $vids = array();
      if (!empty($fpp_vids)) {
        foreach ($fpp_vids as $vid) {
          $vids[] = $vid->vid;
        }
        // Then, check whether that first revision was created by a current test user.
        $fpp_fpids = db_query('SELECT fpid FROM {fieldable_panels_panes_revision} WHERE vid IN (:vids) AND uid IN (:uids)', array(':uids' => $uids, ':vids' => $vids))->fetchAll();
        if (!empty($fpp_fpids)) {
          foreach ($fpp_fpids as $fpid) {
            $fpids[] = $fpid->fpid;
          }
        }
      }
      // Add FPPs created by users to the $fpps variable.
      $fpids = array_unique($fpids);
    }

    // Delete any fieldable panels panes that were created by test users or a Given step.
    foreach ($fpids as $fpid) {
      fieldable_panels_panes_delete($fpid);
    }

    // Clear out the list.
    $this->external_users = array();
  }

  /**
   * @Then fieldable panels pane :admin_title should have :expected_count revision(s)
   *
   * @todo: Can we only allow this to work with @api tests?
   */
  public function assertRevisionCount($admin_title, $expected_count) {
    $fpp = $this->getFPPByAdminTitle($admin_title);
    $revisions = $this->getFPPRevisions($fpp->fpid);

    $actual_count = count($revisions);
    if ($actual_count != $expected_count) {
      throw new \Exception(sprintf('Fieldable panels pane "%s" has %s revisions (rather than the expected %s)', $admin_title, $actual_count, $expected_count));
    }
  }

  /**
   * @Given I am viewing revision :revision_number of fieldable panels pane :admin_title
   *
   * @todo: Can we only allow this to work with @api tests?
   */
  public function iAmViewingFPPRevision($revision_number, $admin_title) {
    $fpp = $this->getFPPByAdminTitle($admin_title);
    $revisions = $this->getFPPRevisions($fpp->fpid);

    $vid = $revisions[$revision_number - 1]->vid;
    $path = "admin/structure/fieldable-panels-panes/view/{$fpp->fpid}/revision/$vid";

    $this->getSession()->visit($this->locatePath($path));
  }
}
