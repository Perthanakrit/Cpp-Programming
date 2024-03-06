#include <iostream>
#include "Node.h"
using namespace std;

// Position::Position() {}
// Position::Position(float x, float y) : x(x), y(y) {}

Node::Node() // default constructor
{
    id = 0;
    // pos = new Position(0, 0);
    this->x = 0;
    this->y = 0;
}

Node::Node(int id, float x, float y) : id(id)
{
    this->x = x;
    this->y = y;
}

void Node::setPos(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Node::X()
{
    return this->x;
}

float Node::Y()
{
    return this->y;
}