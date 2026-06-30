#!/bin/bash
export PATH=$PATH:/usr/lib/llvm-22/bin/

cmake -S . -B build -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=toolchain-uefi-x64.cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build build