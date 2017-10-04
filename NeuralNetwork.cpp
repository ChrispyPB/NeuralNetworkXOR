#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork()
{
	init({ 2, 3 });
	this->state = NeuralNetworkState::IDLE;
}

// Initialize Neural Network with specific layer counts
NeuralNetwork::NeuralNetwork(vector<int> layerCount) {
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
		cout << "There must be more than 2 layers and each layer must contain at least 1 node" << endl;
	else
	{
		init(layerCount);
		this->state = NeuralNetworkState::IDLE;
	}
}

int NeuralNetwork::run(vector<int> input) {
	if (input.size() != layers[0].nodes.size()) {
		cout << "Input-Vector must be as big as the Input-Layer" << endl;
		return 1;
	}

	// Fill Input-Layer with values
	for (vector<Node>::iterator node = layers.begin()->nodes.begin(); node != layers.begin()->nodes.end(); ++node) {
		node->normalized = input[node - layers.begin()->nodes.begin()];
	}

	// Start Calculating
	// Step in every layer
	for (vector<Layer>::iterator layer = layers.begin(); layer != layers.end() - 1; ++layer) {
		// Step in every node
		for (Node node: layer->nodes) {
			// Calculate every connection
			for (Connection *connection: node.outputs) {
				connection->weighten();
			}
		}

		// Normalize values of next layer
		for (vector<Node>::iterator node = (layer + 1)->nodes.begin(); node != (layer + 1)->nodes.end(); ++node) {
			node->normalize();
		}
	}
}

void NeuralNetwork::improve(vector<float> result, vector<float> expectedResult) {

}

void NeuralNetwork::train(int count) {
	this->state = NeuralNetworkState::TRAINING;

	for (int i = 0; i < count; ++i) {
		int expectedResult;

		// Test all 4 cases of XOR
		switch (i % 4) {
		case 0:
			this->run({ 0, 0 });
			expectedResult = 0;
			break;
		case 1:
			this->run({ 1, 0 });
			expectedResult = 1;
			break;
		case 2:
			this->run({ 0, 1 });
			expectedResult = 1;
			break;
		case 3:
			this->run({ 1, 1 });
			expectedResult = 0;
			break;
		}

		// Get Outputs from Output-Layer
		vector<float> result;
		string resultString = "";
		for (vector<Node>::iterator node = (layers.end() - 1)->nodes.begin(); node != (layers.end() - 1)->nodes.end(); ++node) {
			result.push_back(node->normalized);

			resultString += to_string(node->normalized);
			if (node != (layers.end() - 1)->nodes.end() - 1)
				resultString += ", ";
		}

		printf("Run: %d Result: %s Expected: %d\n", i + 1, resultString.c_str(), expectedResult);

		this->improve(result, { (float)expectedResult });
	}
}

void NeuralNetwork::save() {

}

void NeuralNetwork::load() {

}

void NeuralNetwork::init(vector<int> layerCount) {
	// Create Input Layer
	layers.push_back(Layer(layerCount[0]));

	// Create Hidden Layers
	for (int nodeCount: layerCount) {
		layers.push_back(Layer(nodeCount));
	}	

	// Create Output Layer
	layers.push_back(Layer(layerCount[layerCount.size() - 1]));

	// Create Connections between nodes
	connectNodes();
}

void NeuralNetwork::connectNodes() {
	// Loop for FROM-layer
	for (vector<Layer>::iterator layer = layers.begin(); layer != layers.end() - 1; ++layer) {
		// Loop for FROM-node
		for (Node from_node : layer->nodes) {
			// Loop for TO-node
			for (Node to_node: (layer + 1)->nodes) {
				// Add Input and Output connections
				Connection *connection = new Connection(&from_node, &to_node);

				from_node.outputs.push_back(connection);
				to_node.inputs.push_back(connection);
			}
		}
	}
}