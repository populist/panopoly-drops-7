<?php
/**
 * @file
 * Provide Behat step-definitions for WYSIWYG editor.
 *
 * @todo This should move to the WYSIWYG module eventually
 */

use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\RawDrupalContext;

class WysiwygSubContext extends RawDrupalContext implements DrupalSubContextInterface {

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
   * Get the instance variable to use in Javascript.
   *
   * @param string $instanceId
   *   The instanceId used by the WYSIWYG module to identify the instance.
   *
   * @throws Exeception
   *   Throws an exception if the editor doesn't exist.
   *
   * @return string
   *   A Javascript expression representing the WYSIWYG instance.
   */
  protected function getWysiwygInstance($instanceId) {
    $instance = "Drupal.wysiwyg.instances['$instanceId']";

    if (!$this->getSession()->evaluateScript("return !!$instance")) {
      throw new \Exception(sprintf('The editor "%s" was not found on the page %s', $instanceId, $this->getSession()->getCurrentUrl()));
    }

    return $instance;
  }

  /**
   * Get a Mink Element representing the WYSIWYG toolbar.
   *
   * @param string $instanceId
   *   The instanceId used by the WYSIWYG module to identify the instance.
   * @param string $editorType
   *   Identifies the underlying editor (for example, "tinymce").
   *
   * @throws Exeception
   *   Throws an exception if the toolbar can't be found.
   *
   * @return \Behat\Mink\Element\NodeElement
   *   The toolbar DOM Node.
   */
  protected function getWysiwygToolbar($instanceId, $editorType) {
    $driver = $this->getSession()->getDriver();

    switch ($editorType) {
      case 'tinymce':
        $toolbarElement = $driver->find("//div[@id='{$instanceId}_toolbargroup']");
        $toolbarElement = !empty($toolbarElement) ? $toolbarElement[0] : NULL;
        break;

      case 'markitup':
        $elementId = 'markItUp' . ucfirst($instanceId);
        $toolbarElement = $driver->find("//div[@id='{$elementId}']//div[@class='markItUpHeader']");
        $toolbarElement = !empty($toolbarElement) ? $toolbarElement[0] : NULL;
        break;
    }

    if (!$toolbarElement) {
      throw new \Exception(sprintf('Toolbar for editor "%s" was not found on the page %s', $instanceId, $this->getSession()->getCurrentUrl()));
    }

    return $toolbarElement;
  }

  /**
   * @When I type :text in the :instanceId WYSIWYG editor
   */
  public function iTypeInTheWysiwygEditor($text, $instanceId) {
    $instance = $this->getWysiwygInstance($instanceId);
    // Necessary for some WYSIWYG editors (namely, markitup) to be focussed
    // before instance.insert() will do anything.
    $this->getSession()->executeScript("jQuery('#$instanceId').focus();");
    $this->getSession()->executeScript("$instance.insert(\"$text\");");
  }

  /**
   * @When I fill in the :instanceId WYSIWYG editor with :text
   */
  public function iFillInTheWysiwygEditor($instanceId, $text) {
    $instance = $this->getWysiwygInstance($instanceId);
    $this->getSession()->executeScript("$instance.setContent(\"$text\");");
  }

  /**
   * @When I click the :action button in the :instanceId WYSIWYG editor
   */
  public function iClickTheButtonInTheWysiwygEditor($action, $instanceId) {
    $driver = $this->getSession()->getDriver();

    $instance = $this->getWysiwygInstance($instanceId);
    $editorType = $this->getSession()->evaluateScript("return $instance.editor");
    $toolbarElement = $this->getWysiwygToolbar($instanceId, $editorType);

    // Click the action button.
    $button = $toolbarElement->find("xpath", "//a[starts-with(@title, '$action')]");
    if (!$button) {
      throw new \Exception(sprintf('Button "%s" was not found on the page %s', $action, $this->getSession()->getCurrentUrl()));
    }
    $button->click();
    $driver->wait(1000, TRUE);
  }

  /**
   * @When I click the :cssSelector element in the :instanceId WYSIWYG editor
   */
  public function iClickTheElementInTheWysiwygEditor($cssSelector, $instanceId) {
    $instance = $this->getWysiwygInstance($instanceId);
    $editorType = $this->getSession()->evaluateScript("return $instance.editor");

    // TODO: This is tinyMCE specific. We should probably do a switch statement
    // based on $editorType.
    $editor_iframe_id = $instanceId . '_ifr';

    // This Javascript only works on Chrome - not Firefox.
    $javascript  = "jQuery('#{$editor_iframe_id}').each(function() {";
    $javascript .= "  jQuery('{$cssSelector}', this.contentWindow.document || this.contentDocument).click();";
    $javascript .= "});";

    $this->getSession()->executeScript($javascript);
  }

  /**
   * @When I expand the toolbar in the :instanceId WYSIWYG editor
   */
  public function iExpandTheToolbarInTheWysiwygEditor($instanceId) {
    $driver = $this->getSession()->getDriver();

    $instance = $this->getWysiwygInstance($instanceId);
    $editorType = $this->getSession()->evaluateScript("return $instance.editor");
    $toolbarElement = $this->getWysiwygToolbar($instanceId, $editorType);

    // TODO: This is tinyMCE specific. We should probably switch on
    // $editorType.
    $action = 'Show/hide toolbars';

    // Expand wysiwyg toolbar.
    $button = $toolbarElement->find("xpath", "//a[starts-with(@title, '$action')]");
    if (!$button) {
      throw new \Exception(sprintf('Button "%s" was not found on the page %s', $action, $this->getSession()->getCurrentUrl()));
    }
    if (strpos($button->getAttribute('class'), 'mceButtonActive') !== FALSE) {
      $button->click();
    }
  }

  /**
   * @Then I should see :text in the :instanceId WYSIWYG editor
   */
  public function assertContentInWysiwygEditor($text, $instanceId) {
    $instance = $this->getWysiwygInstance($instanceId);
    $content = $this->evaluateScript("return $instance.getContent()");
    if (strpos($text, $content) === FALSE) {
      throw new \Exception(sprintf('The text "%s" was not found in the "%s" WYSWIYG editor on the page %s', $text, $instanceId, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @Then I should not see :text in the :instanceId WYSIWYG editor
   */
  public function assertContentNotInWysiwygEditor($text, $instanceId) {
    $instance = $this->getWysiwygInstance($instanceId);
    $content = $this->evaluateScript("return $instance.getContent()");
    if (strpos($text, $content) !== FALSE) {
      throw new \Exception(sprintf('The text "%s" was found in the "%s" WYSWIYG editor on the page %s', $text, $instanceId, $this->getSession()->getCurrentUrl()));
    }
  }
}
