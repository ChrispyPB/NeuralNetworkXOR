#!/bin/bash

echo "===== Building NeuralNetworkCore ====="
cd NeuralNetworkCore
cmake -H. -Bbuild
cmake --build build -- -j3

cd ..

# # Copy NeuralNetworkCore library to NeuralNetworkXOR
# cp -f NeuralNetworkCore/bin/lnncore.so NeuralNetworkXOR/lib
# echo "Copied NeuralNetworkCore library to NeuralNetworkXOR"

# # Copy header files for library
# cp -f NeuralNetworkCore/include/NeuralNetwork.h \
#   NeuralNetworkCore/include/Connection.h \
#   NeuralNetworkCore/include/Globals.h \
#   NeuralNetworkCore/include/Layer.h \
#   NeuralNetworkCore/include/Node.h \
#   NeuralNetworkXOR/include
# echo "Copied header files to NeuralNetworkXOR"
