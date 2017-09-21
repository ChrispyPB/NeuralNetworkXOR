#pragma once

#include "include.h"
#include "Node.h"

enum class LayerType {
	INPUT,
	DATA,
	OUTPUT
};

class Layer
{
public:
	LayerType type;
	vector<Node> nodes;

	Layer();
	Layer(LayerType type);
};
