#pragma once

#include "include.h"
#include "Node.h"

enum class LayerType {
	INPUT,
	HIDDEN,
	OUTPUT,
	UNDEFINED
};

class Layer
{
public:
	LayerType type;
	vector<Node> nodes;

	Layer();
	Layer(LayerType type);
	Layer(LayerType type, int nodes);

private:
	void initNodes(int nodeCount);
};
