#pragma once

#include "include.h"

class Node;

class Connection
{
public:
	Node *from;
	Node *to;
	double weight;

	Connection() : Connection(NULL, NULL) {};
	Connection(Node *from, Node *to);

	void weighten();
};

