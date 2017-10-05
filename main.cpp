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

	const auto start_begin = chrono::high_resolution_clock::now();

	NeuralNetwork nn;

	// If valid arguments are given
	if (layerCount.size() > 0)
		nn = NeuralNetwork(layerCount, 0.9);

	const auto start_end = chrono::high_resolution_clock::now();

	// Training
	const auto train_begin = chrono::high_resolution_clock::now();

	nn.train(1000);

	for (Node &node : (nn.layers.end() - 1)->nodes) {
		cout << "Result: " << node.normalized << endl;
	}

	const auto train_end = chrono::high_resolution_clock::now();

	const auto start_time = chrono::duration_cast<chrono::milliseconds>(start_end - start_begin).count();
	const auto train_time = chrono::duration_cast<chrono::milliseconds>(train_end - train_begin).count();

	cout << "==========================================" << endl 
		<< "Start time elapsed: " << start_time << "ms" << endl
		<< "Train time elapsed: " << train_time << "ms" << endl
		<< endl
		<< "Press any key to exit...";

	getchar();
	return 0;
}