#pragma once

#include "include.h"
#include "Layer.h"
#include "Connection.h"

//enum class NeuralNetworkState {
//	RUNNING,
//	TRAINING,
//	IDLE
//};

class NeuralNetwork
{
public:
	vector<Layer> layers;
	vector<Connection> connections;
	double learningRate;

	NeuralNetwork() : NeuralNetwork({ 2, 3, 1 }, 0.9) {};
	NeuralNetwork(initializer_list<int> layerCount, double learningRate) : NeuralNetwork(vector<int>(layerCount), learningRate) {};
	NeuralNetwork(vector<int> layerCount, double learningRate);

	HRESULT run(vector<int> input);
	void improve(vector<double> result, vector<double> expectedResult);
	void train(int count);
	void resetNodes();

	void save();
	void load();

private:
	void init(vector<int> layerCount);
	void connectNodes();
};