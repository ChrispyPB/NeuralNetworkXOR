#pragma once

#include "include.h"
#include "Layer.h"

enum class NeuralNetworkState {
	RUNNING,
	TRAINING,
	IDLE
};

class NeuralNetwork
{
public:
	NeuralNetwork();
	NeuralNetwork(vector<int> layerCount);

	void start();
	void stop();
	void train(int count);

	vector<int> layerCount();

private:
	vector<Layer> _layers;
	NeuralNetworkState _state;

	void initLayers(vector<int> layerCount);
};

