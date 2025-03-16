#!/bin/bash
if [ -z "$1" ]; then
    echo "Error: Please provide a commit message"
    exit 1
fi
cd ~/Documents/Learning/C/calcuboris
./update_version.sh || { echo "Update failed"; exit 1; }
PATCH=$(grep "VERSION_PATCH" version.h | awk '{print $3}')
git add main.c calc_ops.c calc_ops.h ui.c ui.h version.h update_version.sh push_version.sh
git commit -m "CalcuBoris v1.4.$PATCH - $1"
git push origin main
