#!/bin/bash

REPO_NAMES="panopoly_admin panopoly_core panopoly_images panopoly_magic panopoly_pages panopoly_search panopoly_test panopoly_theme panopoly_users panopoly_widgets panopoly_wysiwyg"

BRANCH=$(git rev-parse --abbrev-ref HEAD)
if [ x$BRANCH != x7.x-1.x ]; then
    echo "Only run this command when on the 7.x-1.x branch"
    exit 1
fi

die() {
  echo "$@"
  exit 1
}

for repo in $REPO_NAMES; do
  echo "Fetching from individual repo for $repo..."
  git remote add $repo git@git.drupal.org:project/$repo.git >/dev/null 2>&1
  git fetch $repo --no-tags || die "Unable to fetch repo for $repo"
  echo
done

# We had to do these stupid merge commits, which won't automatically
# get pulled in by splitsh-lite, so we rebase them in manually.
declare -A MERGE_COMMITS
MERGE_COMMITS[panopoly_admin]=a6ad2cb
MERGE_COMMITS[panopoly_core]=b646732
MERGE_COMMITS[panopoly_images]=5b88d30
MERGE_COMMITS[panopoly_magic]=9613823
MERGE_COMMITS[panopoly_pages]=40b9718
MERGE_COMMITS[panopoly_search]=04d6d32
MERGE_COMMITS[panopoly_test]=bc11198
MERGE_COMMITS[panopoly_theme]=a4956a6
MERGE_COMMITS[panopoly_users]=309a024
MERGE_COMMITS[panopoly_widgets]=ebe792c
MERGE_COMMITS[panopoly_wysiwyg]=a3d1146

echo
for repo in $REPO_NAMES; do
  echo "Performing subtree split for $repo..."
  splitsh-lite --prefix=modules/panopoly/$repo --target=refs/heads/$repo-$BRANCH || die "Unable to do subtree split for $repo"

  git checkout $repo-$BRANCH || die "Unable to checkout $repo-$BRANCH"
  git branch --set-upstream-to $repo/$BRANCH

  # TODO: This works, but generates the wrong commit hashes for some reason!

  #if ! git branch --contains ${MERGE_COMMITS[$repo]} >/dev/null 2>&1; then
  #  echo "Injecting the merge commit..."
  #  git rebase ${MERGE_COMMITS[$repo]} || die "Unable to inject the merge commit for $repo"
  #fi

  # This scares me, but the hashes come out OK...
  git pull $repo $BRANCH --rebase || die "Unable to inject the merge commit for $repo"

  git checkout $BRANCH >/dev/null 2>&1 || die "Unable to switch back to branch $BRANCH"
  echo
done

if [ x$1 = 'x--push' ]; then
  echo
  for repo in $REPO_NAMES; do
    echo "Pushing $repo..."
    git checkout $repo-$BRANCH || die "Unable to checkout $repo-$BRANCH"
    git push $repo $repo-$BRANCH:$BRANCH || die "Unable to push to $repo"
    git checkout $BRANCH >/dev/null 2>&1 || die "Unable to switch back to branch $BRANCH"
    echo
  done
fi

