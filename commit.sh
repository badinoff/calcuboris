#!/bin/bash
./update_version.sh
git add main.c calc_ops.c calc_ops.h ui.c ui.h version.h update_version.sh push_version.sh commit.sh
git commit -m "$1"
git push origin main
