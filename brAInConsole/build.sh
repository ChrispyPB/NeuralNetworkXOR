#!/bin/bash

echo "===== Building brAIn console application ====="
cd brAInConsole
cmake -H. -Bbuild
cmake --build build -- -j3

cd ..
