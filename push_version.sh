#!/bin/bash
if [ -z "$1" ]; then
    echo "Error: Please provide a commit message"
    exit 1
fi
cd ~/Documents/Learning/C
./update_version.sh || { echo "Update failed"; exit 1; }
# Grab PATCH from version.h
PATCH=$(grep "VERSION_PATCH" version.h | awk '{print $3}')
git add ~/Documents/Learning/C/calculator.c ~/Documents/Learning/C/version.h ~/Documents/Learning/C/update_version.sh ~/Documents/Learning/C/push_version.sh
git commit -m "CalcuBoris v1.1.$PATCH - $1"
git push origin master
