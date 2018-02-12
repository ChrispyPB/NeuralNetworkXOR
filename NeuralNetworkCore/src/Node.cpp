#include "Node.h"
#include "Connection.h"

Node::Node(vector<Connection*> inputs, vector<Connection*> outputs) {
	this->inputs = inputs;
	this->outputs = outputs;
}

void Node::normalize() {
	double sum = 0;
	for (double value: weighted) {
		sum += value;
	}

	normalized = (sum) / (30 - (-30));
}
