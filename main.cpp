#pragma once

#include "include.h"
#include "NeuralNetwork.h"

int main(int argc, char** argv) {
	vector<int> layerCount;
	
	// Check for command line arguments
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			try {
				layerCount.push_back(stoi(argv[i]));
			}
			catch (invalid_argument) {
				cout << "Invalid command line arguments. Syntax: [1] [2] [3] ..." << endl;
				break;
			}
		}
	}

	NeuralNetwork nn;

	// If no (valid) arguments are given
	if (layerCount.size() > 0)
		nn = NeuralNetwork(layerCount);

	clock_t begin = clock();
	nn.train(1, 1000);
	clock_t end = clock();

	float time = float(end - begin) / (CLOCKS_PER_SEC / 1000);
	cout << "Time elapsed: " << time << endl;

	cout << "Best Result: " << nn.bestResult << endl;

	getchar();

	return 0;
}