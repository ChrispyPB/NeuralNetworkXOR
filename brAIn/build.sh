#!/bin/bash

echo "===== Building brAin core ====="
cd brAIn
cmake -H. -Bbuild
cmake --build build -- -j3

cd ..
