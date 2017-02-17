<?php
/**
 * @file
 * Provide Behat step-definitions for Panels.
 *
 * @todo This should become panels.behat.inc in the Panels module!
 */

use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalDriverManager;
use Drupal\Component\Utility\Random;
use Drupal\DrupalExtension\Context\RawDrupalContext;

class PanelsSubContext extends RawDrupalContext implements DrupalSubContextInterface {

  /**
   * Contains the DrupalDriverManager.
   *
   * @var \Drupal\DrupalDriverManager
   */
  private $drupal;

  /**
   * Initializes context.
   */
  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Wait until the Panels IPE is activated.
   *
   * @When I wait for the Panels IPE to activate
   */
  public function waitForIPEtoActivate() {
    $this->getSession()->wait(5000, 'jQuery(".panels-ipe-editing").length > 0');
  }

  /**
   * Wait until the Panels IPE is deactivated.
   *
   * @When I wait for the Panels IPE to deactivate
   */
  public function waitForIPEtoDeactivate() {
    $this->getSession()->wait(5000, 'jQuery(".panels-ipe-editing").length === 0');
  }

  /**
   * Enable the Panels IPE if it's available on the current page.
   *
   * @When I customize this page with the Panels IPE
   */
  public function customizeThisPageIPE() {
    $this->getSession()->getDriver()->maximizeWindow();
    $this->waitForIPEtoDeactivate();
    $this->getSession()->getPage()->clickLink('Customize this page');
    $this->waitForIPEtoActivate();
  }

  /**
   * Open 'Change layout' dialog if it's available on the current page.
   *
   * @When I change layout with the Panels IPE
   */
  public function changeLayoutIPE() {
    $this->getSession()->wait(5000, 'jQuery(".panels-choose-layout").length === 0');
    $this->getSession()->getPage()->clickLink('Change layout');
    $this->getSession()->wait(5000, 'jQuery(".panels-choose-layout").length > 0');
  }

}
