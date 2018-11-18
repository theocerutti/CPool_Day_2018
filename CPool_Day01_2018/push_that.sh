#!/bin/bash
# push_that.sh

git add *
git commit -m "$1"
git push origin master
