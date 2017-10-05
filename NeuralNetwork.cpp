#include "NeuralNetwork.h"

#pragma warning( disable : 4244)

// Initialize Neural Network with specific layer counts
NeuralNetwork::NeuralNetwork(vector<int> layerCount, double learningRate) {
	bool error = false;

	if (layerCount.size() < 3)
		error = true;
	else if (!error) {
		for (int nodeCount: layerCount) {
			if (nodeCount <= 0)
				error = true;
		}
	}

	if (error)
		cout << "There must be at least 3 layers and each layer must contain at least 1 node" << endl;
	else
	{
		init(layerCount);
		this->learningRate = learningRate;
	}
}

HRESULT NeuralNetwork::run(vector<int> input) {
	resetNodes();

	if (input.size() != layers[0].nodes.size()) {
		cout << "Input-Vector must be as big as Input-Layer" << endl;
		return E_FAIL;
	}

	// Fill Input-Layer with values
	for (vector<Node>::iterator node = layers.begin()->nodes.begin(); node != layers.begin()->nodes.end(); ++node) {
		node->normalized = input[node - layers.begin()->nodes.begin()];
	}

	// Start Calculating
	// Step in every layer
	for (vector<Layer>::iterator layer = layers.begin(); layer != layers.end() - 1; ++layer) {
		// Step in every node
		for (Node &node: layer->nodes) {
			// Calculate every connection
			for (Connection *(&connection): node.outputs) {
				connection->weighten();
			}
		}

		// Normalize values of next layer
		for (vector<Node>::iterator node = (layer + 1)->nodes.begin(); node != (layer + 1)->nodes.end(); ++node) {
			node->normalize();
		}
	}

	return S_OK;
}

void NeuralNetwork::improve(vector<double> result, vector<double> expectedResult) {

}

void NeuralNetwork::train(int count) {
	for (int i = 0; i < count; ++i) {
		int expectedResult;
		HRESULT error;

		// Test all 4 cases of XOR
		switch (i % 4) {
		case 0:
			error = this->run({ 0, 0 });
			expectedResult = 0;
			break;
		case 1:
			error = this->run({ 1, 0 });
			expectedResult = 1;
			break;
		case 2:
			error = this->run({ 0, 1 });
			expectedResult = 1;
			break;
		case 3:
			error = this->run({ 1, 1 });
			expectedResult = 0;
			break;
		}

		if (error != S_OK) continue;

		// Get Outputs from Output-Layer
		vector<double> result;
		string resultString = "";
		for (vector<Node>::iterator node = (layers.end() - 1)->nodes.begin(); node != (layers.end() - 1)->nodes.end(); ++node) {
			result.push_back(node->normalized);

			resultString += to_string(node->normalized);
			if (node != (layers.end() - 1)->nodes.end() - 1)
				resultString += ", ";
		}

		cout << "==========================================" << endl
			<< "Run: " << i + 1 << endl
			<< "Results: " << resultString.c_str() << endl
			<< "Expected: " << expectedResult << endl
			<< "==========================================" << endl;

		this->improve(result, { (double)expectedResult });
	}
}

void NeuralNetwork::resetNodes() {
	for (Layer &layer : layers) {
		for (Node &node : layer.nodes) {
			node.weighted.clear();
		}
	}
}

void NeuralNetwork::save() {

}

void NeuralNetwork::load() {

}

void NeuralNetwork::init(vector<int> layerCount) {
	// Create Input Layer
	layers.push_back(Layer(*layerCount.begin()));

	// Create Hidden Layers
	for (vector<int>::iterator nodeCount = layerCount.begin() + 1; nodeCount != layerCount.end() - 1; ++nodeCount) {
		layers.push_back(Layer(*nodeCount));
	}

	// Create Output Layer
	layers.push_back(Layer(*(layerCount.end() - 1)));

	// Create Connections between nodes
	connectNodes();
}

void NeuralNetwork::connectNodes() {
	srand(time(nullptr));

	// Loop for FROM-layer
	for (vector<Layer>::iterator layer = layers.begin(); layer != layers.end() - 1; ++layer) {
		// Loop for FROM-node
		for (Node &from_node: layer->nodes) {
			// Loop for TO-node
			for (Node &to_node: (layer + 1)->nodes) {
				// Add Input and Output connections
				Connection *connection = new Connection(&from_node, &to_node);

				from_node.outputs.push_back(connection);
				to_node.inputs.push_back(connection);
			}
		}
	}
}
