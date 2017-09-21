#include "NeuralNetwork.h"
#include "InputLayer.h"

NeuralNetwork::NeuralNetwork()
{
	vector<int> layerCount{ 2, 3, 1 };

	initLayers(layerCount);
}

// Initialize Neural Network with specific layer counts
NeuralNetwork::NeuralNetwork(vector<int> layerCount) {
	bool error = false;

	if (layerCount.size < 3)
		error = true;
	else if (!error) {
		for (vector<int>::iterator it = layerCount.begin(); it != layerCount.end(); ++it) {
			if (*it <= 0)
				error = true;
		}
	}

	if (error)
		cout << "Layers are invalid. Node counts must be higher than 0 and size must be higher than 3";
	else
		initLayers(layerCount);
}

void NeuralNetwork::start() {

}

void NeuralNetwork::stop() {

}

void NeuralNetwork::train(int count) {

}

void NeuralNetwork::initLayers(vector<int> layerCount) {
	// Initialize 1 Input Layer
	for (int i = 0; i < layerCount[0]; ++i) {
		_layers.push_back(Layer(LayerType::INPUT));
	}

	// Initialize multiple Data Layers
	for (vector<int>::iterator it = layerCount.begin() + 1; it != layerCount.end() - 1; ++it) {
		for (int i = 0; i < *it; ++i) {
			_layers.push_back(Layer(LayerType::DATA));
		}
	}

	// Initialize 1 Output Layer
	for (int i = 0; i < layerCount[layerCount.end()]; ++i) {
		_layers.push_back(Layer(LayerType::OUTPUT));
	}
}
