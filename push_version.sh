#!/bin/bash
if [ -z "$1" ]; then
    echo "Error: Please provide a commit message"
    exit 1
fi
./update_version.sh
git add ~/Documents/Learning/C/calculator.c ~/Documents/Learning/C/version.h ~/Documents/Learning/C/update_version.sh ~/Documents/Learning/C/push_version.sh
git commit -m "CalcuBoris v1.1.XX - $1"
git push origin master
