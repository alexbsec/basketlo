#!/bin/sh

BUILD_DIR="./build"

if [ -d "$BUILD_DIR" ]; then
    if [ "$(ls -A "$BUILD_DIR")" ]; then
        echo "build directory already exists"
    else
        echo "running cmake..."
        cmake -B build -DCMAKE_BUILD_TYPE=Release
        echo "cmake finished!"
    fi
fi
echo "bulding..."
make
