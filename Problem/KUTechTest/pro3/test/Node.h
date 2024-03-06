#ifndef NODE_h
#define NODE_h

#include <iostream>
using namespace std;

class Position
{
private:
    float x;
    float y;

public:
    Position();
    Position(float, float);
    float X();
    float Y();
};

class Node
{

private: // hided data member
    int id;
    float x, y;
    Node **con_nodes;

public:     // public member function (method)
    Node(); // default constructor
    Node(int, float, float);
    // Position getPosition();
    void setNodes(Node **);
    void setPos(float, float);
    float X();
    float Y();
};

#endif