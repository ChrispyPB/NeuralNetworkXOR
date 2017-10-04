#include "Layer.h"

Layer::Layer() {
	this->nodes.push_back(Node());
}

Layer::Layer(vector<Node> nodes) {
	this->nodes = nodes;
}

Layer::Layer(int nodeCount) {
	for (int i = 0; i < nodeCount; ++i) {
		this->nodes.push_back(Node());
	}
}