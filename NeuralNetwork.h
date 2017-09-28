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

	float run();
	void improve();
	void train(float expectedResult, int count);

	vector<int> layerCount();

private:
	vector<Layer> _layers;
	NeuralNetworkState _state;

	void initLayers(vector<int> layerCount);
};

