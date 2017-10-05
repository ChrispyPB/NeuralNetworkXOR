#pragma once

#include "include.h"

class Connection;

class Node
{
public:
	vector<Connection*> inputs;
	vector<Connection*> outputs;
	vector<double> weighted;
	double normalized;

	Node() : Node(vector<Connection*>(), vector<Connection*>()) {};
	Node(vector<Connection*> inputs, vector<Connection*> outputs);

	void normalize();
};