#!/bin/bash

##
# $1 git repo
# $2 the destination folder
# $3 the site host
##

GIT_REPO=$1
BUILD_DEST=$2
SITE_HOST=$3

echo "Removing old cloned repo if exists"
rm -rf /tmp/$BUILD_DEST

echo "Clone $GIT_REPO to /tmp/$BUILD_DEST"
git clone $GIT_REPO /tmp/$BUILD_DEST

echo "Run the make file from /tmp/$BUILD_DEST"
drush make /tmp/$BUILD_DEST/build-liiinabox.make $BUILD_DEST

echo "Remove the tmp clone"
rm -rf /tmp/$BUILD_DEST

cd $BUILD_DEST
mkdir -p sites/$SITE_HOST/files
cp sites/default/default.settings.php sites/$SITE_HOST/settings.php
chmod -R 777 sites/$SITE_HOST/files sites/$SITE_HOST/settings.php

echo "Done"
echo ""
