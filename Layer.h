#pragma once

#include "include.h"
#include "Node.h"

class Layer
{
public:
	vector<Node> nodes;

	Layer();
	Layer(vector<Node> nodes);
	Layer(int nodes);
};
