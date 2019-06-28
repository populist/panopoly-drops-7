<?php

use Robo\Contract\VerbosityThresholdInterface;
use Robo\Tasks as RoboTasks;
use Symfony\Component\Process\Process;

/**
 * This is project's console commands configuration for Robo task runner.
 *
 * @see http://robo.li/
 */
class RoboFile extends RoboTasks {

  const PANOPOLY_DEFAULT_BRANCH = '7.x-1.x';

  const DRUPAL_ORG_API_NODE_URL = 'https://www.drupal.org/api-d7/node/%s.json';

  const PANOPOLY_GITHUB_REPO = 'git@github.com:panopoly/panopoly.git';

  protected $PANOPOLY_FEATURES = [
    'panopoly_admin' => 'Panopoly Admin',
    'panopoly_core' => 'Panopoly Core',
    'panopoly_demo' => 'Panopoly Demo',
    'panopoly_images' => 'Panopoly Images',
    'panopoly_pages' => 'Panopoly Pages',
    'panopoly_search' => 'Panopoly Search',
    'panopoly_test' => 'Panopoly Test',
    'panopoly_theme' => 'Panopoly Theme',
    'panopoly_users' => 'Panopoly Users',
    'panopoly_widgets' => 'Panopoly Widgets',
    'panopoly_wysiwyg' => 'Panopoly WYSIWYG',
  ];

  protected $PANOPOLY_COMPONENT_MAP = [
    'Admin' => 'panopoly_admin',
    'Core' => 'panopoly_core',
    'Demo' => 'panopoly_demo',
    'Images' => 'panopoly_images',
    'Magic' => 'panopoly_magic',
    'Media' => 'panopoly_media',
    'Pages' => 'panopoly_pages',
    'Search' => 'panopoly_search',
    'Tests / Continuous Integration' => 'panopoly_test',
    'Theme' => 'panopoly_theme',
    'Users' => 'panopoly_users',
    'Widgets' => 'panopoly_widgets',
    'WYSIWYG' => 'panopoly_wysiwyg',
  ];

  protected $SUBTREE_MERGE_COMMITS = [
    'panopoly_admin' => 'a6ad2cb',
    'panopoly_core' => 'b646732',
    'panopoly_images' => '5b88d30',
    'panopoly_magic' => '9613823',
    'panopoly_pages' => '40b9718',
    'panopoly_search' => '04d6d32',
    'panopoly_test' => 'bc11198',
    'panopoly_theme' => 'a4956a6',
    'panopoly_users' => '309a024',
    'panopoly_widgets' => 'ebe792c',
    'panopoly_wysiwyg' => 'a3d1146',
  ];

  /**
   * Runs Drush directly (not via Robo's ExecTask).
   *
   * This should primarily be used for gathering information, and not performing
   * build steps - that should be done via Robo's ExecTask when possible.
   *
   * @param string $command
   *   The Drush command and arguments to run.
   * @param string|null $cwd
   *   The working directory.
   * @param array|null $env
   *   The environment.
   * @param string|null $input
   *   The standard input.
   * @param int|null $timeout
   *   The timeout.
   *
   * @return \Symfony\Component\Process\Process
   *   The executed Process object.
   *
   * @throws \Symfony\Component\Process\Exception\ProcessFailedException
   *   When Drush exits with a non-zero status.
   */
  protected function runDrush($command, $cwd = NULL, array $env = NULL, $input = NULL, $timeout = NULL) {
    $drush_path = getenv('DRUSH') ?: 'drush';
    $drush_args = getenv('DRUSH_ARGS') ?: '';

    $process = new Process("{$drush_path} {$drush_args} $command", $cwd, $env, $input, $timeout);
    $process->setPty(TRUE);
    $process->mustRun();

    return $process;
  }

  /**
   * Runs Drush directly (not via Robo's ExecTask).
   *
   * This should primarily be used for gathering information, and not performing
   * build steps - that should be done via Robo's ExecTask when possible.
   *
   * This doesn't throw an exception when the process errors - you need to check
   * the exit code (via `$process->getExitCode()`) to see if it succeeded.
   *
   * @param string $command
   *   The Drush command and arguments to run.
   * @param string|null $cwd
   *   The working directory.
   * @param array|null $env
   *   The environment.
   * @param string|null $input
   *   The standard input.
   * @param int|null $timeout
   *   The timeout.
   *
   * @return \Symfony\Component\Process\Process
   *   The executed Process object.
   */
  protected function runProcess($command, $cwd = NULL, array $env = NULL, $input = NULL, $timeout = NULL) {
    $process = new Process($command, $cwd, $env, $input, $timeout);
    $process->run();
    return $process;
  }

  /**
   * Checks if a module (or modules is enabled).
   *
   * @param string[]|string $module_or_modules
   *   A module, or list of modules.
   *
   * @return bool
   *   TRUE if all modules are enabled; FALSE otherwise.
   */
  protected function isModuleEnabled($module_or_modules) {
    $modules = is_array($module_or_modules) ? $module_or_modules : [ $module_or_modules ];
    $modules_string = implode(' ', $modules);

    $process = $this->runDrush("pmi {$modules_string} --format=json");
    $info = json_decode($process->getOutput(), TRUE);

    foreach ($modules as $module) {
      if ($info[$module]['status'] !== 'enabled') {
        return FALSE;
      }
    }

    return TRUE;
  }

  /**
   * Gets the Git branch that is currently checked out.
   *
   * @return string
   */
  protected function getCurrentBranch() {
    $process = new Process('git rev-parse --abbrev-ref HEAD');
    $process->setTimeout(NULL);
    $process->run();

    return trim($process->getOutput());
  }

  /**
   * Reads and parses a JSON file.
   *
   * @param string $filename
   *   The filename to read.
   *
   * @return array|null
   *   The parsed JSON data from the file, or NULL if the file can't be read.
   */
  protected function readJsonFile($filename) {
    return json_decode(file_get_contents($filename), TRUE);
  }

  /**
   * Writes a composer JSON file.
   *
   * This tries to format the JSON in the way a composer.json would be, which
   * may be prettier and/or more verbose than you'd format JSON for machines.
   *
   * @param string $filename
   *   The file name to write.
   * @param array $data
   *   The data to put in the file.
   */
  protected function writeComposerJsonFile($filename, $data) {
    file_put_contents($filename, json_encode($data, JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES));
  }

  /**
   * Gets a list of the panopoly_* features.
   *
   * @return string[]
   *   The machine names of the panopoly_* features.
   */
  protected function getPanopolyFeatures() {
    return array_keys($this->PANOPOLY_FEATURES);
  }

  /**
   * Gets a list of pretty names for the panopoly_* features.
   *
   * @return string[]
   *   The human-readable names of the panpoly_* features, keyed by their
   *   machine name.
   */
  protected function getPanopolyFeaturesNames() {
    return $this->PANOPOLY_FEATURES;
  }

  /**
   * Checks if any of the features are overridden.
   */
  public function checkOverridden() {
    if (!$this->isModuleEnabled(['features', 'diff'])) {
      throw new \Exception("The 'features' and 'diff' modules need to be enabled");
    }

    $overridden = FALSE;
    $first = TRUE;
    foreach ($this->getPanopolyFeatures() as $panopoly_feature) {
      // We prime something or other by running the first feature and discarding
      // the result before running it again.
      if ($first) {
        $this->runDrush("features-diff {$panopoly_feature}");
      }

      $this->say("Checking <info>{$panopoly_feature}</info>...");
      $process = $this->runDrush("features-diff {$panopoly_feature}");
      if ($process->getExitCode() != 0 || strpos($process->getErrorOutput(), "Feature is in its default state") === FALSE) {
        $this->say("*** <error>OVERRIDDEN</error> ***");
        echo $process->getOutput() . $process->getErrorOutput();
        $overridden = TRUE;
      }
    }

    return $overridden ? 1 : 0;
  }

  /**
   * Builds the top-level drupal-org.make file from the panopoly_* features.
   *
   * @todo This should probably use $this->taskConcat()
   */
  public function buildDrupalOrgMake() {
    $drupal_org_make = <<<EOF
;
; GENERATED FILE - DO NOT EDIT!
;

EOF;

    foreach ($this->getPanopolyFeatures() as $panopoly_feature) {
      $panopoly_feature_make = __DIR__ . "/modules/panopoly/{$panopoly_feature}/{$panopoly_feature}.make";
      if (file_exists($panopoly_feature_make)) {
        $drupal_org_make .= "\n" . file_get_contents($panopoly_feature_make);
      }
    }

    file_put_contents(__DIR__ . '/drupal-org.make', $drupal_org_make);
  }

  /**
   * Builds the profile's .make file to pull in modules, themes and libraries.
   */
  public function buildDependencies() {
    /** @var $this|\Robo\Collection\CollectionBuilder $collection */
    $collection = $this->collectionBuilder();

    $collection->addCode([$this, 'buildDrupalOrgMake']);
    $collection->taskExec("drush make drupal-org.make -y --no-core --contrib-destination=.");

    return $collection;
  }

  /**
   * Builds a Drupal code base with Panopoly in it at the target path.
   *
   * @param string $target_path
   *   The path to build the Drupal site.
   *
   * @return \Robo\Collection\CollectionBuilder
   *
   * @throws \Exception
   */
  public function buildSite($target_path) {
    if (file_exists($target_path)) {
      throw new \Exception("{$target_path} already exists");
    }

    /** @var $this|\Robo\Collection\CollectionBuilder $collection */
    $collection = $this->collectionBuilder();

    $collection->addTask($this->buildDependencies());

    $drupal_org_make = __DIR__ . '/drupal-org.make';

    $collection->taskExec("drush make drupal-org-core.make {$target_path} -y");
    $collection->taskMirrorDir([ __DIR__ => "{$target_path}/profiles/panopoly"]);

    return $collection;
  }

  /**
   * Does a subtree-split into the individual panopoly_* features' manyrepos.
   *
   * @command subtree-split
   *
   * @option $push Push new commits to the manyrepos repos.
   */
  public function subtreeSplit($opts = ['push' => FALSE]) {
    $branch = static::PANOPOLY_DEFAULT_BRANCH;
    if ($this->getCurrentBranch() !== $branch) {
      throw new \Exception("Only run this command on the {$branch} branch");
    }

    /** @var \Robo\Collection\CollectionBuilder|$this $collection */
    $collection = $this->collectionBuilder();

    // Get a list of panopoly_* features with panopoly_demo removed.
    $panopoly_features_names = $this->getPanopolyFeaturesNames();
    unset($panopoly_features_names['panopoly_demo']);
    $panopoly_features = array_keys($panopoly_features_names);

    foreach ($panopoly_features as $panopoly_feature) {
      $collection->addCode(function () use ($panopoly_feature) {
        $this->say("Fetching from individual repo for {$panopoly_feature}...");
      });

      // Run this way to allow failure, and hide the messages normally.
      $collection->addCode(function () use ($panopoly_feature) {
        $this->taskExec("git remote add {$panopoly_feature} git@git.drupal.org:project/{$panopoly_feature}.git")
          ->setVerbosityThreshold(VerbosityThresholdInterface::VERBOSITY_DEBUG)
          ->run();
      });

      $collection->taskExec("git fetch {$panopoly_feature} --no-tags");
    }

    $collection->completion($this->taskExec("git checkout {$branch}"));

    foreach ($panopoly_features as $panopoly_feature) {
      $collection->addCode(function () use ($panopoly_feature) {
        $this->say("Performing subtree split for {$panopoly_feature}...");
      });

      $collection->taskExecStack()
        ->exec("splitsh-lite --prefix=modules/panopoly/{$panopoly_feature} --target=refs/heads/{$panopoly_feature}-{$branch}")
        ->exec("git checkout {$panopoly_feature}-{$branch}")
        ->exec("git branch --set-upstream-to {$panopoly_feature}/{$branch}");

      if (isset($this->SUBTREE_MERGE_COMMITS[$panopoly_feature])) {
        # TODO: This works, but generates the wrong commit hashes for some reason!

        #if ! git branch --contains ${MERGE_COMMITS[$repo]} >/dev/null 2>&1; then
        #  echo "Injecting the merge commit..."
        #  git rebase ${MERGE_COMMITS[$repo]} || die "Unable to inject the merge commit for $repo"
        #fi

        # This scares me, but the hashes come out OK...
        $collection->taskExec("git pull {$panopoly_feature} {$branch} --rebase");
      }

      $collection->taskExec("git checkout {$branch}");
    }

    if ($opts['push']) {
      foreach ($panopoly_features as $panopoly_feature) {
        $collection->addCode(function () use ($panopoly_feature) {
          $this->say("Pushing {$panopoly_feature}...");
        });

        $collection->taskExecStack()
          ->exec("git checkout {$panopoly_feature}-{$branch}")
          ->exec("git push {$panopoly_feature} {$panopoly_feature}-{$branch}:{$branch}");
      }
    }

    return $collection;
  }

  /**
   * Gets the individual patch files from an issue on Drupal.org
   *
   * @param int $issue_number
   *   The Drupal.org issue number.
   * @param bool $profile_patch
   *   TRUE if the patches found should be applied to the profile; FALSE if they
   *   are intended for the individual manyrepos.
   *
   * @return array
   *   An associative array of the patches, keyed by repo name.
   *
   * @throws \Exception
   *   If the repo each patch belongs to can't be worked out.
   */
  protected function getPatchFilesForDrupalIssue($issue_number, $profile_patch = FALSE) {
    $node = json_decode(file_get_contents(sprintf(static::DRUPAL_ORG_API_NODE_URL, $issue_number)), TRUE);

    $files = [];
    foreach ($node['field_issue_files'] as $value) {
      if ($value['display'] == '1') {
        $file = json_decode(file_get_contents($value['file']['uri'] . '.json'), TRUE);
        if (!preg_match('/\.patch$/', $file['name'])) {
          continue;
        }

        $component = NULL;
        if ($profile_patch) {
          $component = 'profile';
        }
        else {
          if (preg_match('/^panopoly[_-]([^_-]+)[_-]/', $file['name'], $matches)) {
            $component = 'panopoly_' . $matches[1];
            if (!in_array($component, $this->PANOPOLY_COMPONENT_MAP[$component])) {
              $component = NULL;
            }
          }
          if (!$component) {
            $component = isset($this->PANOPOLY_COMPONENT_MAP[$node['field_issue_component']]) ? $this->PANOPOLY_COMPONENT_MAP[$node['field_issue_component']] : NULL;
          }
          if (!$component) {
            throw new \Exception("Unable to identify project for patch based on name '{$file['name']}' or issue component '{$node['field_issue_component']}'");
          }
        }

        $files[$component] = $file['url'];
      }
    }

    return $files;
  }

  /**
   * Creates a branch which includes patches from a Drupal.org issue, in order to trigger Travis-CI to test them.
   *
   * @command create-test-branch
   *
   * @param int $issue_number
   *   The issue number to run the tests for.
   *
   * @option string $git-repo
   *   The git repo to commit to.
   * @option string $git-old-branch
   *   The branch in the git repo to start from.
   * @option string $git-new-branch
   *   The branch in the git repo to create.
   * @option bool $skip-upgrade-tests
   *   If passed, this will only run tests on the current -dev, skipping the tests against upgraded versions.
   * @option bool $profile-patch
   *   If passed, the discovered patch will be used against the profile, rather than individual components.
   *
   * @return \Robo\Collection\CollectionBuilder
   *
   * @throws \Exception
   */
  public function createTestBranch($issue_number, $opts = ['git-repo' => self::PANOPOLY_GITHUB_REPO, 'git-old-branch' => self::PANOPOLY_DEFAULT_BRANCH, 'git-new-branch' => NULL, 'skip-upgrade-tests' => FALSE, 'profile-patch' => FALSE]) {
    $patch_files = $this->getPatchFilesForDrupalIssue($issue_number, $opts['profile-patch']);
    if (empty($patch_files)) {
      throw new \Exception("Unable to find any patch files on issue {$issue_number}");
    }

    $old_branch = $opts['git-old-branch'];
    $new_branch = $opts['git-new-branch'] ?: 'issue-' . $issue_number;

    /** @var \Robo\Collection\CollectionBuilder|$this $collection */
    $collection = $this->collectionBuilder();
    $tmp_dir = $collection->taskTmpDir()
      ->cwd(TRUE)
      ->getPath();

    $collection->taskGitStack()
      ->cloneShallow($opts['git-repo'], $tmp_dir, $old_branch, 1);

    // Check out the branch.
    $collection->addCode(function () use ($old_branch, $new_branch) {
      $result = $this->_exec("git checkout {$new_branch}");
      if ($result->getExitCode() !== 0) {
        // We have to create the branch, because it doesn't exist.
        $this->_exec("git checkout -b {$new_branch}");
      }
      else {
        // We have to merge from the old branch to catch any changes.
        $this->_exec("git merge {$old_branch} --strategy --recursive -X theirs");
      }
    });

    // Apply the patch files.
    foreach ($patch_files as $component => $patch_url) {
      if ($component === 'profile') {
        $patch_path = '.';
      }
      else {
        $patch_path = 'modules/panopoly/' . $component;
      }

      $patch_file = $collection->taskTmpFile()
        ->text(file_get_contents($patch_url))
        ->getPath();

      $collection->taskExec("patch -p1 -d {$patch_path} < {$patch_file}");
    }

    // Regenerate the .make files (in case a patch changed them)
    $collection->addCode([$this, 'createDrushMakeFiles']);

    // Modify the .travis.yml file.
    $collection->addCode(function () use ($opts) {
      $travis_yml = \Symfony\Component\Yaml\Yaml::parseFile('.travis.yml');

      // We always drop the matrix -> include.
      if (isset($travis_yml['matrix']['include'])) {
        unset($travis_yml['matrix']['include']);
      }

      if ($opts['skip-upgrade-tests']) {
        // Remove all but the first 'env' entry. The rest are upgrade tests.
        $travis_yml['env']['matrix'] = [$travis_yml['env']['matrix'][0]];
      }
      else {
        // Do just the first upgrade test.
        $travis_yml['env']['matrix'] = array_slice($travis_yml['env']['matrix'], 0, 2);
      }

      file_put_contents('.travis.yml', \Symfony\Component\Yaml\Yaml::dump($travis_yml));
    });

    // Make commit message.
    $commit_message = "Trying latest patches on Issue #{$issue_number}: https://www.drupal.org/node/{$issue_number}\n";
    foreach ($patch_files as $patch_url) {
      $commit_message .= " - {$patch_url}\n";
    }
    $collection->taskGitStack()
      ->add('.')
      ->commit($commit_message);
    $collection->taskExec("git push -f origin {$new_branch}");

    return $collection;
  }

  /**
   * Updates a CHANGELOG.txt file for a new release.
   *
   * @param string $filename
   *   The file to update.
   * @param string $name
   *   The human-readable name of the project.
   * @param string $version
   *   The new version.
   * @param string $entry
   *   The text content of the changelog (from `drush rn --changelog`).
   */
  protected function updateChangelog($filename, $name, $version, $entry) {
    $changelog = file_exists($filename) ? file_get_contents($filename) : '';

    $version_line = "{$name} {$version}, " . date('Y-m-d') . "\n";
    if (strpos($changelog, $version_line) !== FALSE) {
      $this->say("Changes for {$version} already present in {$filename} - skipping!");
      return;
    }

    // Do word wrapping.
    $entry_parts = array_slice(explode("\n", str_replace("\r", "", wordwrap($entry))), 1);
    $entry_parts = array_map(function ($line) {
      return empty($line) || strpos($line, '-') === 0 ? $line : '  ' . $line;
    }, $entry_parts);
    $entry = implode("\n", $entry_parts);

    // Add header and deal with empty data.
    $entry = $version_line . $entry;
    if (strpos($entry, '- ') === FALSE) {
      $entry = str_replace("\n\n", "\n- No changes since last release.\n\n", $entry);
    }

    // Prepend the new entry to the changelog file.
    $changelog = $entry . $changelog;
    file_put_contents($filename, $changelog);
  }

  /**
   * Checks out the many repos for the purpose of making a release.
   *
   * @param string $branch
   *   The branch to checkout.
   * @param bool $clean
   *   If TRUE, then delete the repos before checking them out; if FALSE, try
   *   to simply update the repos already there (if any).
   *
   * @return \Robo\Collection\CollectionBuilder
   */
  protected function checkoutManyreposForRelease($branch, $clean = FALSE) {
    /** @var \Robo\Collection\CollectionBuilder|$this $collection */
    $collection = $this->collectionBuilder();

    // Create (and optionally clean) the release directory.
    if ($clean) {
      $this->_deleteDir('release');
    }
    if (!file_exists('release')) {
      $collection->taskFileSystemStack()
        ->mkdir('release');
    }

    // Check out the individual manyrepos for the child modules.
    foreach ($this->getPanopolyFeatures() as $panopoly_feature) {
      $panopoly_feature_release_path = "release/{$panopoly_feature}";
      if (!file_exists($panopoly_feature_release_path)) {
        $collection->taskExec("git clone git@git.drupal.org:project/{$panopoly_feature}.git --branch {$branch} {$panopoly_feature_release_path}");
      }
      else {
        $collection->taskExecStack()
          ->exec("git -C {$panopoly_feature_release_path} checkout {$branch}")
          ->exec("git -C {$panopoly_feature_release_path} pull")
          ->exec("git -C {$panopoly_feature_release_path} pull --tags");
      }
    }

    return $collection;
  }

  /**
   * Release Stage 1: results in local tag and commit for the new version.
   *
   * @param string $old_version
   *   The previous version.
   * @param string $new_version
   *   The new version.
   *
   * @option $clean
   *   If passed, the repos under `release/` will be cleaned up before starting.
   *
   * @return \Robo\Collection\CollectionBuilder
   *
   * @throws \Exception
   */
  public function releaseCreate($old_version, $new_version, $opts = ['clean' => FALSE]) {
    $branch = static::PANOPOLY_DEFAULT_BRANCH;
    if ($this->getCurrentBranch() !== $branch) {
      throw new \Exception("Only run this command on the {$branch} branch");
    }

    if ($this->runProcess("git status -s -uno")->getOutput() !== '') {
      throw new \Exception("Cannot do release because there are uncommitted changes");
    }

    // If git tag already exists, then bail completely.
    if ($this->runProcess("git rev-parse {$new_version}")->getExitCode() === 0) {
      throw new \Exception("Tag {$new_version} already exists");
    }

    $commit_message = "Updated CHANGELOG.txt for {$new_version} release.";
    $commits = $this->runProcess("git log --oneline --grep='{$commit_message}'")->getOutput();
    if (strpos($commits, $commit_message) !== FALSE) {
      throw new \Exception("The commit message '{$commit_message}' is already used. You should check it, and if all is good, create the {$new_version} tag.");
    }

    /** @var \Robo\Collection\CollectionBuilder|$this $collection */
    $collection = $this->collectionBuilder();

    $collection->taskGitStack()->pull();

    $collection->addTask($this->checkoutManyreposForRelease($branch, $opts['clean']));

    // Update all the CHANGELOG.txt files in the monorepo (except for
    // panopoly_demo, which needs to get updated in its own repo).
    foreach ($this->getPanopolyFeaturesNames() as $panopoly_feature => $panopoly_feature_name) {
      $panopoly_feature_release_path = "release/{$panopoly_feature}";
      $panopoly_feature_source_path = "modules/panopoly/{$panopoly_feature}";

      // For panopoly_demo, this needs to be updated in its separate repo.
      if ($panopoly_feature === 'panopoly_demo') {
        $panopoly_feature_source_path = $panopoly_feature_release_path;
      }

      // @todo Probably should be a custom Task
      $collection->addCode(function () use ($old_version, $new_version, $branch, $panopoly_feature_name, $panopoly_feature_release_path, $panopoly_feature_source_path) {
        $drush_rn = $this->runDrush("rn {$old_version} {$branch} --changelog 2>/dev/null", $panopoly_feature_release_path)->getOutput();
        $this->updateChangelog("{$panopoly_feature_source_path}/CHANGELOG.txt", $panopoly_feature_name, $new_version, $drush_rn);
      });

      if ($panopoly_feature === 'panopoly_demo') {
        $collection->taskExec("git -C {$panopoly_feature_release_path} add CHANGELOG.txt");
      }
      else {
        $collection->taskGitStack()
          ->add("{$panopoly_feature_source_path}/CHANGELOG.txt");
      }
    }

    // Do top-level CHANGELOG.txt too.
    // @todo Probably should be a custom Task
    $collection->addCode(function () use ($old_version, $new_version, $branch) {
      $drush_rn = $this->runDrush("rn {$old_version} {$branch} --changelog 2>/dev/null")->getOutput();
      $this->updateChangelog("CHANGELOG.txt", 'Panopoly', $new_version, $drush_rn);
    });
    $collection->taskGitStack()
      ->add("CHANGELOG.txt");

    // Commit the CHANGELOG.txt changes, and tag everything.
    $collection->taskExecStack()
      ->exec("git -C release/panopoly_demo commit -m '{$commit_message}'")
      ->exec("git -C release/panopoly_demo tag {$new_version}");
    $collection->taskGitStack()
      ->commit($commit_message)
      ->tag($new_version);

    return $collection;
  }

  /**
   * Release Stage 2: Pushes commits and tags to the Git remote.
   *
   * @param string $new_version
   *   The new version that we are pushing.
   *
   * @return \Robo\Collection\CollectionBuilder
   *
   * @throws \Exception
   */
  public function releasePush($new_version) {
    $branch = static::PANOPOLY_DEFAULT_BRANCH;
    if ($this->getCurrentBranch() !== $branch) {
      throw new \Exception("Only run this command on the {$branch} branch");
    }

    // If git tag doesn't exist, then bail completely.
    if ($this->runProcess("git rev-parse {$new_version}")->getExitCode() !== 0) {
      throw new \Exception("Tag {$new_version} doesn't exist");
    }

    /** @var \Robo\Collection\CollectionBuilder|$this $collection */
    $collection = $this->collectionBuilder();

    // Push the changes out to both the monorepo and manyrepos.
    $collection->taskExecStack()
      ->exec("git push")
      ->exec("git push --tags");
    $collection->addTask($this->subtreeSplit(['push' => TRUE]));

    // Pull the commits down into our local checkouts of the manyrepos, so
    // we can tag and push those as well.
    $collection->addTask($this->checkoutManyreposForRelease($branch));
    foreach ($this->getPanopolyFeatures() as $panopoly_feature) {
      $panopoly_feature_release_path = "release/{$panopoly_feature}";
      if ($panopoly_feature === 'panopoly_demo') {
        $collection->taskExecStack()
          ->exec("git -C {$panopoly_feature_release_path} push")
          ->exec("git -C {$panopoly_feature_release_path} push --tags");
      }
      else {
        $collection->taskExecStack()
          ->exec("git -C {$panopoly_feature_release_path} tag {$new_version}")
          ->exec("git -C {$panopoly_feature_release_path} push --tags");
      }
    }

    return $collection;
  }

  /**
   * Uses Mink to submit a form.
   *
   * @param \Behat\Mink\Element\DocumentElement $page
   *   The page via Mink.
   * @param string $form_id
   *   The form id.
   * @param string[] $values
   *   The values to set.
   * @param string $op
   *   The ID or value of the button to press.
   *
   * @throws \Behat\Mink\Exception\ElementNotFoundException
   */
  protected function submitForm(\Behat\Mink\Element\DocumentElement $page, $form_id, array $values, $op) {
    $form = $page->findById($form_id);
    if (!$form) {
      throw new \Exception("Couldn't find form with id: $form_id");
    }
    foreach ($values as $name => $value) {
      if ($field = $form->findField($name)) {
        if ($field->getTagName() === 'select') {
          $field->selectOption($value);
        }
        else {
          $field->setValue($value);
        }
      }
      else {
        // We let individual fields fail, since some are not present depending
        // on configuration.
        //throw new \Exception("Couldn't find field with name: $name");
      }
    }
    $button = $form->findButton($op);
    if (!$button) {
      throw new \Exception("Unable to find button {$op} on {$form_id}");
    }
    $button->click();
  }

  /**
   * Uses Mink to create a release on Drupal.org.
   *
   * @param \Behat\Mink\Session $session
   *   The Mink session.
   * @param string $module
   *   The machine-name of the module to create the release for.
   * @param string $version
   *   The version.
   * @param string $release_notes
   *   The text content of the release notes (from `drush rn`).
   *
   * @throws \Behat\Mink\Exception\ElementNotFoundException
   */
  protected function createRelease(\Behat\Mink\Session $session, $module, $version, $release_notes) {
    $session->visit("https://www.drupal.org/project/{$module}");
    $session->getPage()->clickLink('Add new release');

    try {
      $this->submitForm($session->getPage(), 'project-release-node-form', [
        'versioncontrol_release_label_id' => $version,
      ], 'edit-preview--2');
    }
    catch (\Exception $e) {
      $this->say("Unable to make release {$module} {$version} - skipping for now (but could be a problem)");
      return;
    }

    $this->submitForm($session->getPage(), 'project-release-node-form', [
      'body[und][0][value]' => $release_notes,
    ], 'edit-submit');

    $this->say("{$module} released - see: " . $session->getCurrentUrl());
  }

  /**
   * Release Stage 3: Publishes new releases on Drupal.org.
   *
   * @param string $old_version
   *   The previous version.
   * @param string $new_version
   *   The new version.
   *
   * @option string $username
   *   The Drupal.org username.
   * @option string $password
   *   The Drupal.org password.
   * @option string $totp-secret
   *   The TOTP secret, if your Drupal.org account uses TFA.
   * @option bool $skip-checkout-repos
   *   Skip checking out the release repos if they are already up-to-date.
   * @option bool $no-stop
   *   Don't stop Mink after the release is done or errors out.
   * @option string $wd-host
   *   The Webdriver (aka Selenium) end-point to connect to.
   *
   * @return $this|\Robo\Collection\CollectionBuilder
   *
   * @throws \Exception
   */
  public function releasePublish($old_version, $new_version, $opts = ['username' => NULL, 'password' => NULL, 'totp-secret' => NULL, 'skip-checkout-repos' => FALSE, 'no-stop' => FALSE, 'wd-host' => 'http://chromedriver:4444/wd/hub']) {
    if (empty($opts['username']) || empty($opts['password'])) {
      throw new \Exception("Must pass in --username and --pasword");
    }

    $branch = static::PANOPOLY_DEFAULT_BRANCH;
    list ($drupal_major,) = explode('-', $branch);

    /** @var \Robo\Collection\CollectionBuilder|$this $collection */
    $collection = $this->collectionBuilder();

    // @todo Make this more configurable.
    $session = new \Behat\Mink\Session(
      new \Behat\Mink\Driver\Selenium2Driver('chrome', [
        'chrome' => [
          'switches' => [
            //'--headless',
            '--disable-gpu',
          ],
          // This hides the fact that Chrome is being driven by automation.
          'excludeSwitches' => [
            'enable-automation',
          ],
        ],
      ], $opts['wd-host'])
    );

    if (!$opts['no-stop']) {
      $collection->completionCode(function () use ($session) {
        $session->stop();
      });
    }

    $panopoly_features = array_merge(['panopoly'], $this->getPanopolyFeatures());
    foreach ($panopoly_features as $index => $panopoly_feature) {
      $panopoly_feature_releases = $this->runDrush("pm-releases {$panopoly_feature}-{$drupal_major}")->getOutput();
      if (strpos($panopoly_feature_releases, $new_version) !== FALSE) {
        $this->say("{$panopoly_feature} {$new_version} already released - skipping");
        unset($panopoly_features[$index]);
      }
    }
    if (empty($panopoly_features)) {
      $this->say("Nothing to release!");
      return $collection;
    }

    if (!$opts['skip-checkout-repos']) {
      $collection->addTask($this->checkoutManyreposForRelease($branch));
    }

    $collection->addCode(function () use ($session, $opts) {
      $session->visit('https://drupal.org/user/login');

      $this->submitForm($session->getPage(), 'user-login', [
        'name' => $opts['username'],
        'pass' => $opts['password'],
      ], 'edit-submit');

      if (!empty($opts['totp-secret'])) {
        $this->submitForm($session->getPage(), 'tfa-form', [
          'code' => \OTPHP\TOTP::create($opts['totp-secret'])->now(),
        ], 'edit-login');
      }
    });

    foreach ($panopoly_features as $panopoly_feature) {
      $collection->addCode(function () use ($session, $panopoly_feature, $old_version, $new_version) {
        if ($panopoly_feature === 'panopoly') {
          $panopoly_feature_release_path = NULL;
        }
        else {
          $panopoly_feature_release_path = "release/{$panopoly_feature}";
        }

        $release_notes = $this->runDrush("rn {$old_version} {$new_version} 2>/dev/null", $panopoly_feature_release_path)->getOutput();
        $this->createRelease($session, $panopoly_feature, $new_version, $release_notes);
      });
    }

    return $collection;
  }

  /**
   * Runs all 3 stages of the release process in order.
   *
   * @param string $old_version
   *   The previous version.
   * @param string $new_version
   *   The new version.
   *
   * @option bool $clean
   *   If passed, the repos under `release/` will be cleaned up before starting.
   * @option bool $push-and-publish
   *   If passed, will not only create the release, but will also push and publish it.
   * @option string $username
   *   The Drupal.org username.
   * @option string $password
   *   The Drupal.org password.
   * @option string $totp-secret
   *   The TOTP secret, if your Drupal.org account uses TFA.
   * @option bool $skip-checkout-repos
   *   Skip checking out the release repos if they are already up-to-date.
   * @option bool $no-stop
   *   Don't stop Mink after the release is done or errors out.
   * @option string $wd-host
   *   The Webdriver (aka Selenium) end-point to connect to.
   *
   * @return \Robo\Collection\CollectionBuilder
   *
   * @throws \Exception
   */
  public function release($old_version, $new_version, $opts = ['clean' => FALSE, 'push-and-publish' => FALSE, 'username' => NULL, 'password' => NULL, 'totp-secret' => NULL, 'no-stop' => FALSE, 'wd-host' => 'http://chromedriver:4444/wd/hub']) {
    /** @var \Robo\Collection\CollectionBuilder|$this $collection */
    $collection = $this->collectionBuilder();

    // If git tag already exists, then bail completely.
    if ($this->runProcess("git rev-parse {$new_version}")->getExitCode() !== 0) {
      $collection->addTask($this->releaseCreate($old_version, $new_version, [
        'clean' => $opts['clean'],
      ]));
    }

    if ($opts['push-and-publish']) {
      $collection->addTask($this->releasePush($new_version));
      $collection->addTask($this->releasePublish($old_version, $new_version, [
        'username' => $opts['username'],
        'password' => $opts['password'],
        'totp-secret' => $opts['totp-secret'],
        'wd-host' => $opts['wd-host'],
        'no-stop' => $opts['no-stop'],
        // We don't need to check because we just did in releasePush().
        'skip-checkout-repos' => TRUE
      ]));
    }

    return $collection;
  }

}
