#!/usr/bin/bash
mkdir -p build && cd build
cmake .. -G Ninja
ninja -j 4
./example