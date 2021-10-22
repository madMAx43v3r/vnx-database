#!/bin/bash

mkdir -p build

cd build

cmake -D CMAKE_CXX_FLAGS="-fmax-errors=1" -D CMAKE_BUILD_TYPE="Debug" ..

make -j8 $@

