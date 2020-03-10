#include "Node.hpp"

Node::Node(string payload)
{
    this->payload = payload;
    this->nextNode = 0;
}

string getPayload()
{
    return this->payload;
}

Node* getNextNode()
{
    return this->nextNode;
}

void setNextNode(Node* n)
{
    this->nextNode = n;
}