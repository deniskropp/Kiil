#!/bin/bash

# Exit if something fails
set -e

# Create build directory
echo "Creating build directory..."
mkdir -p build


# Run CMake
echo "Running CMake..."
cmake -Bbuild -DKDE_INSTALL_USE_QT_SYS_PATHS=ON -DCMAKE_BUILD_TYPE=RelWithDebInfo .

# Build the project
echo "Building the project..."
cmake --build build

# Install the project
echo "Installing the project..."
sudo cmake --install build

echo "Installation complete!"


# KRunner needs to be restarted for the changes to be applied
# we can just kill it and it will be started when the shortcut is invoked
kquitapp6 krunner
