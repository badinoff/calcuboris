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
# Get last committed PATCH
LAST_PATCH=$(git show origin/main:version.h 2>/dev/null | grep VERSION_PATCH | awk '{print $3}' || echo 0)
if [ "$PATCH" -eq "$LAST_PATCH" ]; then
    # No manual change - bump it
    PATCH=$((PATCH + 1))
fi
# If PATCH differs (manual edit) - keep it
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
