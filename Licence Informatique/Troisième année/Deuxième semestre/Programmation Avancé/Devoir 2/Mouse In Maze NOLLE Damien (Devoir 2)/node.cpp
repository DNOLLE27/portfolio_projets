#include "node.h"

using namespace mazeNode;

Node::Node()
{
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    visited = false;
}

Node::~Node()
{

}

eNodeType Node::getType()
{
    return type;
}

void Node::setNeighbor(eNodeNeighbor position, Node *neighbor)
{
    switch (position)
    {
        case NodeNeighbor_Up :
            up = neighbor;
            break;

        case NodeNeighbor_Down :
            down = neighbor;
            break;

        case NodeNeighbor_Left :
            left = neighbor;
            break;

        case NodeNeighbor_Right :
            right = neighbor;
    }
}

Node *Node::getNeighbor(eNodeNeighbor position)
{
    Node *neighbor = NULL;

    switch (position)
    {
        case NodeNeighbor_Up :
            neighbor = up;
            break;

        case NodeNeighbor_Down :
            neighbor = down;
            break;

        case NodeNeighbor_Left :
            neighbor = left;
            break;

        case NodeNeighbor_Right :
            neighbor = right;
    }

    return neighbor;
}

bool Node::isNeighborFree(eNodeNeighbor position)
{
    Node *neighbor = getNeighbor(position);

    if (neighbor != NULL && neighbor->isFreeToVisit())
    {
        return true;
    }

    return false;
}

void Node::setVisited()
{
    visited = true;
}

bool Node::isVisited()
{
    return visited;
}

bool Node::isFreeToVisit()
{
    return getType() != NodeType_Wall;
}

NodeWall::NodeWall() : Node()
{
   this->type = NodeType_Wall;
}

char NodeWall::getString()
{
   return 'w';
}

NodeFree::NodeFree() : Node()
{
   this->type = NodeType_Free;
}

char NodeFree::getString()
{
   if (this->visited)
      return '.';

   return ' ';
}

NodeCheese::NodeCheese() : Node()
{
   this->type = NodeType_Cheese;
}

char NodeCheese::getString()
{
   if (this->visited)
      return 'X';

   return 'c';
}

NodeNull::NodeNull() : Node()
{
   this->type = NodeType_Null;
}

char NodeNull::getString()
{
   return 'N';
}
