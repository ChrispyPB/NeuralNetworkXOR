#pragma once

#include "include.h"

class Node;

class Connection
{
public:
	Node *from;
	Node *to;
	float weight;

	Connection() : Connection(nullptr, nullptr) {};
	Connection(Node *from, Node *to);

	void weighten();
};

