#!/usr/bin/env bash

set -xe

if [[ $1 = "clean" ]] then
    rm -rf build
fi

mkdir -p build
cd build
cmake -G Ninja ..

