#!/bin/bash
./update_version.sh
git add calculator.c version.h commit.sh
git commit -m "$1"
git push origin master