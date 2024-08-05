#ifndef D5A3CEBB_83CD_45CF_A9ED_B532F81B0406
#define D5A3CEBB_83CD_45CF_A9ED_B532F81B0406
#ifndef _NODE_H_
#define _NODE_H_

#include <cstdlib>

namespace mazeNode
{
   typedef enum _node_type_
   {
      NodeType_Null,
      NodeType_Wall,
      NodeType_Free,
      NodeType_Cheese,
   } eNodeType;

   typedef enum _node_neighbor_
   {
      NodeNeighbor_Null,
      NodeNeighbor_Up,
      NodeNeighbor_Down,
      NodeNeighbor_Left,
      NodeNeighbor_Right,
   } eNodeNeighbor;

   /**
    * @brief Classe de base servant d'interface pour créer des noeuds spécifiques
    */
   class Node
   {
   public:
      Node();
      virtual ~Node();

      eNodeType getType();

      /**
       * @brief Affecte l'instance d'un noeud voisin de sorte à établir des liens entre noeuds.
       *
       * @param position Position du noeud voisin.
       * @param neighbor Instance du noeud voisin.
       */
      void setNeighbor(eNodeNeighbor position, Node* neighbor);

      /**
       * @brief Donne l'instance du noeud correspondant au voisin donné.
       *
       * @param position Position du voisin.
       * @return Instance du noeud voisin.
       */
      Node* getNeighbor(eNodeNeighbor position);

      /**
       * @brief Indique si le voisin donné en paramètre est libre, c'est-à-dire que l'on peut le visiter.
       *
       * @param position Position du voisin.
       * @return true Le voisin peut-être visité.
       * @return false Le voisin n'est pas libre, c'est par exemple un mur, ou alors il n'existe pas.
       */
      bool isNeighborFree(eNodeNeighbor position);

      /**
       * @brief Indique le noeud actuel comme étant visité.
       */
      void setVisited();

      /**
       * @brief Indique si le noeud actuel a été visité.
       *
       * @return true Le noeud a été visité.
       * @return false Le noeux n'a pas été visité.
       */
      bool isVisited();

      /**
       * @brief Indique si le noeud actuel peut-être visité.
       *
       * @return true Le noeud peut-être visité.
       * @return false Le noeud ne peut pas être visité.
       */
      bool isFreeToVisit();

      /**
       * @brief Donne le caractère ascii correspondant au type de noeud.
       *
       * @return Caractère ascii correspondant au type de noeud.
       */
      virtual char getString() = 0;

   protected:
      eNodeType type; // type du noeud
      bool visited;
      // noeuds voisins aux différentes positions
      Node *up;
      Node *down;
      Node *left;
      Node *right;
   };

   /**
    * @brief Noeud de type mur.
    */
   class NodeWall : public Node
   {
   public:
      NodeWall();
      virtual ~NodeWall(){};

      char getString();
   };

   /**
    * @brief Noeud libre pouvant être visité.
    */
   class NodeFree : public Node
   {
   public:
      NodeFree();
      virtual ~NodeFree(){};

      char getString();
   };

   /**
    * @brief Noeud de type fromage.
    */
   class NodeCheese : public Node
   {
   public:
      NodeCheese();
      virtual ~NodeCheese(){};

      char getString();
   };

   /**
   * @brief Noeud de type null.
   */
   class NodeNull : public Node
   {
   public:
      NodeNull();
      virtual ~NodeNull(){};

      char getString();
   };
}

#endif /* _NODE_H_ */


#endif /* D5A3CEBB_83CD_45CF_A9ED_B532F81B0406 */
