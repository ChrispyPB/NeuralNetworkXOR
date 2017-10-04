#pragma once

#include "include.h"
#include "Layer.h"
#include "Connection.h"

enum class NeuralNetworkState {
	RUNNING,
	TRAINING,
	IDLE
};

class NeuralNetwork
{
public:
	vector<Layer> layers;
	vector<Connection> connections;
	NeuralNetworkState state;

	float lastResult;
	float bestResult;

	NeuralNetwork();
	NeuralNetwork(initializer_list<int> layerCount) : NeuralNetwork(vector<int>(layerCount)) {};
	NeuralNetwork(vector<int> layerCount);

	int run(vector<int> input);
	void improve(vector<float> result, vector<float> expectedResult);
	void train(int count);

	void save();
	void load();

	vector<int> layerCount();

private:
	void init(vector<int> layerCount);
	void connectNodes();
};