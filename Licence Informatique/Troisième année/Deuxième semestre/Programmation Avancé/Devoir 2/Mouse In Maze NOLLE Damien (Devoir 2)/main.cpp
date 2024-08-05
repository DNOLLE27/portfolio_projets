#include <iostream>
#include "maze.h"

static const char asciiMaze[16][16] =
{
   {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
   {'w', ' ', 'c', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', 'w', 'w', 'w', 'w', 'w'},
   {'w', ' ', 'w', 'w', 'w', 'w', ' ', 'w', 'w', ' ', ' ', 'w', 'w', 'w', 'w', 'w'},
   {'w', ' ', 'w', ' ', 'w', 'w', ' ', 'w', ' ', ' ', 'w', 'w', 'w', 'w', 'w', 'w'},
   {'w', ' ', ' ', ' ', 'w', 'w', ' ', 'w', ' ', 'w', 'w', ' ', ' ', ' ', ' ', 'w'},
   {'w', ' ', 'w', 'w', 'w', 'w', ' ', 'w', ' ', 'w', 'w', ' ', 'w', 'w', ' ', 'w'},
   {'w', ' ', 'w', ' ', ' ', 'w', ' ', 'w', ' ', ' ', ' ', ' ', 'w', ' ', ' ', 'w'},
   {'w', ' ', 'w', ' ', 'w', 'w', ' ', 'w', 'w', 'w', 'w', 'w', 'w', ' ', 'w', 'w'},
   {'w', ' ', 'w', ' ', 'w', 'w', ' ', 'w', 'w', 'w', 'w', ' ', ' ', ' ', 'w', 'w'},
   {'w', ' ', ' ', ' ', 'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w', 'w', 'w', 'w'},
   {'w', 'w', ' ', 'w', 'w', ' ', 'w', 'w', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w'},
   {'w', 'w', ' ', 'w', 'w', ' ', 'w', ' ', ' ', ' ', 'w', ' ', 'w', 'w', 'w', 'w'},
   {'w', ' ', ' ', 'w', 'w', ' ', ' ', ' ', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w'},
   {'w', 'w', ' ', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', ' ', ' ', ' ', 'w', 'w'},
   {'w', 'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w', 'w', 'w', ' ', 'w', 'w'},
   {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', ' ', 'w', 'w'},
};


int main()
{
   maze::startPoint start = {.line = 15, .col = 13};
   maze::Maze theMaze(asciiMaze, start);

   std::cout << "is the maze valid? " << ((theMaze.checkConsistency()) ? "yes" : "no") << std::endl;
   std::cout << "is there a cheese? " << ((theMaze.solve()) ? "yes" : "no") << std::endl;
   std::cout << std::endl;

   char ascii[16][16];
   theMaze.getAsciiFormat(ascii);
   for (int line = 0; line < 16; line++)
   {
      for (int col = 0; col < 16; col++)
      {
         std::cout << ascii[line][col] << " ";
      }
      std::cout << std::endl;
   }

   return 0;
}
