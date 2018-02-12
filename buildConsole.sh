#!/bin/bash

echo "===== Building NeuralNetworkConsole ====="
cd NeuralNetworkConsole
cmake -H. -Bbuild
cmake --build build -- -j3

cd ..
