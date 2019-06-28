#!/bin/bash
# @file
# Behat integration - Script step.

set -e $DRUPAL_TI_DEBUG

# Ensure we are in the right directory.
cd "$TRAVIS_BUILD_DIR"

panopoly_header Running tests

# If this isn't an upgrade, we test if any features are overridden.
if [[ "$UPGRADE" == none ]]
then
	drush --root=$DRUPAL_TI_DRUPAL_DIR --uri=$DRUPAL_TI_WEBSERVER_URL:$DRUPAL_TI_WEBSERVER_PORT en -y features diff
	DRUSH_ARGS="--root=$DRUPAL_TI_DRUPAL_DIR --uri=$DRUPAL_TI_WEBSERVER_URL:$DRUPAL_TI_WEBSERVER_PORT" "$TRAVIS_BUILD_DIR"/vendor/bin/robo check:overridden
fi

# Now go to the local behat tests, being within the module installation is
# needed for example for the drush runner.
cd "$DRUPAL_TI_DRUPAL_DIR"
cd "$DRUPAL_TI_BEHAT_DIR"

# Copy into place because it doesn't come with panopoly_test.
mv -f "$TRAVIS_BUILD_DIR"/behat.travis.yml.dist .

# This replaces environment vars from $DRUPAL_TI_BEHAT_YML into 'behat.yml'.
drupal_ti_replace_behat_vars

BEHAT="$TRAVIS_BUILD_DIR/vendor/bin/behat"

ARGS=( $DRUPAL_TI_BEHAT_ARGS )

# First, run all the tests in Firefox.
if ! $BEHAT --rerun "${ARGS[@]}"; then
	echo "Failures detected. Re-running failed scenarios."
	$BEHAT --rerun "${ARGS[@]}"
fi
