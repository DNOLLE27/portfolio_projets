#ifndef _MAZE_H_
#define _MAZE_H_

#include "node.h"
#include <cstdlib>

using namespace mazeNode;

namespace maze
{
   typedef struct _start_point_
   {
      int line, col;
   } startPoint;

   class Maze
   {
   public:
      /**
       * @brief Construct a new Maze object.
       *
       * @param ascii Labyrinthe au format ASCII servant à construire le labyrinthe sous forme de noeuds.
       * @param point Coordonnées du point de départ.
       */
      Maze(const char ascii[16][16], startPoint point);
      virtual ~Maze();

      /**
       * @brief Vérifie que le labyrinthe est conforme.
       *
       * @return true Le labyrinthe est conforme.
       * @return false Le labyrinthe n'est pas conforme.
       */
      bool checkConsistency();

      /**
       * @brief Cherche le formage dans la labyrinthe à partir du point de départ.
       *
       * @return true Fromage trouvé.
       * @return false Fromage non trouvé.
       */
      bool solve();

      /**
       * @brief Retourne une version ASCII du labyrinthe.
       *
       * @param ascii Buffer pour stocker la version ASCII.
       */
      void getAsciiFormat(char ascii[16][16]);

   private:
      bool parse(mazeNode::Node *node, eNodeNeighbor , bool isNotVis, int cptFr);

   private:
      // l'ensemble des noeuds du labyrinthe, on ne conserve pas le format ASCII pour travailler.
      mazeNode::Node *nodes[16][16];
      // le noeud de départ
      mazeNode::Node *starter;
   };

}
#endif /* _MAZE_H_ */
