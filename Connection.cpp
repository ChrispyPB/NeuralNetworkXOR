#include "Connection.h"
#include "Node.h"

Connection::Connection(Node *from, Node *to)
{
	this->from = from;
	this->to = to;

	weight = (float)rand() / (float)RAND_MAX;
}

void Connection::weighten() {
	to->weighted.push_back(from->normalized * weight);
}