#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork()
{
	vector<int> layerCount{ 2, 3, 1 };

	initLayers(layerCount);
}

// Initialize Neural Network with specific layer counts
NeuralNetwork::NeuralNetwork(vector<int> layerCount) {
	bool error = false;

	if (layerCount.size() < 3)
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

vector<int> NeuralNetwork::layerCount() {
	vector<int> layerCount;

	for (vector<Layer>::iterator it = _layers.begin(); it < _layers.end(); ++it) {
		layerCount.push_back((*it).nodes.size());
	}

	return layerCount;
}

void NeuralNetwork::initLayers(vector<int> layerCount) {
	// Initialize 1 Input Layer
	_layers.push_back(Layer(LayerType::INPUT, layerCount[0]));

	// Initialize multiple Data Layers
	for (vector<int>::iterator it = layerCount.begin() + 1; it != layerCount.end() - 1; ++it) {
		_layers.push_back(Layer(LayerType::DATA, *it));
	}

	// Initialize 1 Output Layer
	_layers.push_back(Layer(LayerType::INPUT, layerCount.back()));
}
