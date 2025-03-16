#!/bin/bash
if [ -f version.h ]; then
    MAJOR=$(grep "VERSION_MAJOR" version.h | awk '{print $3}')
    MINOR=$(grep "VERSION_MINOR" version.h | awk '{print $3}')
    PATCH=$(grep "VERSION_PATCH" version.h | awk '{print $3}')
else
    MAJOR=1
    MINOR=0
    PATCH=0
fi
COMMIT_COUNT=$(git rev-list --count main 2>/dev/null || echo 0)
PATCH=$COMMIT_COUNT  # Fixed: No -1
if [ $PATCH -gt 99 ]; then
    PATCH=99
fi
PATCH=$(printf "%02d" $PATCH)
echo "#ifndef VERSION_H" > version.h
echo "#define VERSION_H" >> version.h
echo "#define VERSION_MAJOR $MAJOR" >> version.h
echo "#define VERSION_MINOR $MINOR" >> version.h
echo "#define VERSION_PATCH $PATCH" >> version.h
echo "#endif" >> version.h
