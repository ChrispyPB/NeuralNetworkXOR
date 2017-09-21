#include "Layer.h"

Layer::Layer() {
	this->type = LayerType::UNDEFINED;

	initNodes(1);
}

Layer::Layer(LayerType type) {
	this->type = type;

	initNodes(1);
}

Layer::Layer(LayerType type, int nodes) {
	this->type = type;

	initNodes(nodes);
}

void Layer::initNodes(int nodeCount) {
	for (int i = 0; i < nodeCount; ++i) {
		this->nodes.push_back(Node());
	}
}