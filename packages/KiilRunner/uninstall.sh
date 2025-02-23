#!/bin/bash

# Exit if something fails
set -e

sudo cmake --uninstall build

# KRunner needs to be restarted for the changes to be applied
# we can just kill it and it will be started when the shortcut is invoked
kquitapp6 krunner
