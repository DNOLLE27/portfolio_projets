#include "maze.h"

using namespace maze;
using namespace mazeNode;

#include <iostream>
using namespace std;

Maze::Maze(const char ascii[16][16], startPoint point)
{
    for (size_t i = 0; i < 16; i++)
    {
        for (size_t y = 0; y < 16; y++)
        {
            switch (ascii[i][y])
            {
                case 'w' :
                    nodes[i][y] = new NodeWall;
                    break;
                case ' ' :
                    nodes[i][y] = new NodeFree;
                    break;
                case 'c' :
                    nodes[i][y] = new NodeCheese;
                    break;
                default :
                    nodes[i][y] = new NodeNull;
            }
        }
    }

    for (size_t i = 0; i < 16; i++)
    {
        for (size_t y = 0; y < 16; y++)
        {
            if (i > 0)
            {
                nodes[i][y]->setNeighbor(NodeNeighbor_Up, nodes[i - 1][y]);
            }

            if (y > 0)
            {
                nodes[i][y]->setNeighbor(NodeNeighbor_Left, nodes[i][y - 1]);
            }

            if (i < 15)
            {
                nodes[i][y]->setNeighbor(NodeNeighbor_Down, nodes[i + 1][y]);
            }

            if (y < 15)
            {
                nodes[i][y]->setNeighbor(NodeNeighbor_Right, nodes[i][y + 1]);
            }
        }
    }

    starter = nodes[point.line][point.col];
}

Maze::~Maze()
{
    /*for (size_t i = 0; i < 16; i++)
    {
        for (size_t y = 0; y < 16; y++)
        {
            delete nodes[i][y];
        }
    }*/

   delete starter;
}

bool Maze::checkConsistency()
{
    size_t i = 0, y;
    bool verifMaze = true;

    while (verifMaze && i < 16)
    {
        y = 0;

        while (verifMaze && y < 16)
        {
            if (nodes[i][y]->getType() == NodeType_Null)
            {
                verifMaze = false;
            }

            y++;
        }

        i++;
    }

    if (!starter->isFreeToVisit())
    {
        verifMaze = false;
    }

    return verifMaze;
}

bool Maze::solve()
{
    int cptFree = 0;
    for (size_t i = 0; i < 16; i++)
    {
        for (size_t y = 0; y < 16; y++)
        {
            if (nodes[i][y]->getType() == NodeType_Free)
            {
                cptFree++;
            }
        }
    }


    return this->parse(this->starter, NodeNeighbor_Null, true, cptFree);
}

void Maze::getAsciiFormat(char ascii[16][16])
{
   for (size_t i = 0; i < 16; i++)
   {
      for (size_t y = 0; y < 16; y++)
      {
        ascii[i][y] = nodes[i][y]->getString();
      }
   }
}

bool Maze::parse(mazeNode::Node *node, eNodeNeighbor posPrecedente, bool isNotVis, int cptFr)
{
    eNodeNeighbor pos, pos_prec;
    bool isNotVisited = isNotVis;
    int cptF = cptFr;

    if (
            !isNotVisited && ((node->isNeighborFree(NodeNeighbor_Up) && !node->getNeighbor(NodeNeighbor_Up)->isVisited()) ||
            (node->isNeighborFree(NodeNeighbor_Down) && !node->getNeighbor(NodeNeighbor_Down)->isVisited()) ||
            (node->isNeighborFree(NodeNeighbor_Left) && !node->getNeighbor(NodeNeighbor_Left)->isVisited()) ||
            (node->isNeighborFree(NodeNeighbor_Right) && !node->getNeighbor(NodeNeighbor_Right)->isVisited()))
        )
    {
        isNotVisited = true;
    }
    else
    {
         pos_prec = posPrecedente;
    }

    do
    {
        if ((isNotVisited
            && posPrecedente != NodeNeighbor_Up
            && node->isNeighborFree(NodeNeighbor_Up)
            && !node->getNeighbor(NodeNeighbor_Up)->isVisited())
            ||
            (!isNotVisited
            && pos_prec != NodeNeighbor_Up
            && node->isNeighborFree(NodeNeighbor_Up)))
        {
            pos = NodeNeighbor_Up;
            pos_prec = NodeNeighbor_Down;
        }
        else if ((isNotVisited
            && posPrecedente != NodeNeighbor_Left
            && node->isNeighborFree(NodeNeighbor_Left)
            && !node->getNeighbor(NodeNeighbor_Left)->isVisited())
            ||
            (!isNotVisited
            && pos_prec != NodeNeighbor_Left
            && node->isNeighborFree(NodeNeighbor_Left)))
        {
            pos = NodeNeighbor_Left;
            pos_prec = NodeNeighbor_Right;
        }
        else if ((isNotVisited
            && posPrecedente != NodeNeighbor_Right
            && node->isNeighborFree(NodeNeighbor_Right)
            && !node->getNeighbor(NodeNeighbor_Right)->isVisited())
            ||
            (!isNotVisited
            && pos_prec != NodeNeighbor_Right
            && node->isNeighborFree(NodeNeighbor_Right)))
        {
            pos = NodeNeighbor_Right;
            pos_prec = NodeNeighbor_Left;
        }
        else if ((isNotVisited
            && posPrecedente != NodeNeighbor_Down
            && node->isNeighborFree(NodeNeighbor_Down)
            && !node->getNeighbor(NodeNeighbor_Down)->isVisited())
            ||
            (!isNotVisited
            && pos_prec != NodeNeighbor_Down
            && node->isNeighborFree(NodeNeighbor_Down)))
        {
            pos = NodeNeighbor_Down;
            pos_prec = NodeNeighbor_Up;
        }
        else
        {
            pos = NodeNeighbor_Null;
            pos_prec = NodeNeighbor_Null;
        }

        if (pos == NodeNeighbor_Null)
        {
            isNotVisited = false;

            switch (posPrecedente)
            {
                case NodeNeighbor_Down :
                    pos_prec = NodeNeighbor_Up;
                    break;

                case NodeNeighbor_Up :
                    pos_prec = NodeNeighbor_Down;
                    break;

                case NodeNeighbor_Left :
                    pos_prec = NodeNeighbor_Right;
                    break;

                case NodeNeighbor_Right :
                    pos_prec = NodeNeighbor_Left;
                    break;
                default:
                    pos_prec = NodeNeighbor_Null;
            }
        }
    }
    while (pos == NodeNeighbor_Null);

    if (!node->isVisited())
    {
        node->setVisited();
        cptF--;
    }

    if (node->getType() == NodeType_Cheese)
    {
        return true;
    }

    if (cptF == 0)
    {
        return false;
    }

    return parse(node->getNeighbor(pos), pos_prec, isNotVisited, cptF);
}
