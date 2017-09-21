#include "Node.h"

Node::Node() {
	this->name = "node";

	this->d = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);
	this->wij = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

Node::Node(string name) {
	this->name = name;

	this->d = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);
	this->wij = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}