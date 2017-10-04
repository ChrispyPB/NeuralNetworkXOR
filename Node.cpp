#include "Node.h"
#include "Connection.h"

Node::Node(vector<Connection*> inputs, vector<Connection*> outputs) {
	this->inputs = inputs;
	this->outputs = outputs;
}

void Node::normalize() {
	float sum = 0;
	for (float value: weighted) {
		cout << value << endl;
		sum += value;
	}

	normalized = (sum) / (numeric_limits<float>::max() - numeric_limits<float>::min());
}