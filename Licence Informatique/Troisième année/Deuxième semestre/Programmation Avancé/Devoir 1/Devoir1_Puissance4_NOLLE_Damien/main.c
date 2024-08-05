/**
* @file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
* Cette macro-d�finition permet de g�rer le nombre de colonnes du plateau.
*/
#define TAILLE_X 7

/**
* Cette macro-d�finition permet de g�rer le nombre de lignes du plateau.
*/
#define TAILLE_Y 6

/**
* Cette macro-commande permet la r�alisation de tests unitaires en v�rifiant
* l'�galit� de deux valeurs.
*
* @param[in] expected est la valeur attendue .
* @param[in] value est la valeur r�elle, souvent retourn�e par une fonction.
*
* @return la valeur retourn�e est un bool�en, true signifie que le test c'est
* bien pass�, false sinon.
*/
#define ASSERT_EQ(expected, value)\
{\
    if(expected != value)\
    {\
        printf ("[FAIL] Expected %d - Value %d\n", expected , value);\
        return false;\
    }\
    printf("[PASS]\n");\
    return true;\
}\

/**
* Cette structure permet la d�finition de variable correspondant � la position d'un pion.
* Cette position est d�termin�e en fonction de la colonne (pos_x) et de la ligne (pos_y).
* La structure est principalement utilis�e dans la fonction saisiPion.
*/
typedef struct _position_ {
    unsigned pos_x;
    unsigned pos_y;
} position;

/**
* Cette �num�ration permet de d�finir l'�tat de la partie. Soit la partie est en cours,
* soit il y a match nul, soit la partie est fini avec un vainqueur. Elle permet aussi la
* gestion des erreurs. Cette �num�ration est utilis�e dans la fonction verifEtatPartie.
*
* - errJoueur (-5) : Le num�ro du joueur est incorrect (soit 1, soit 2).
* - errNbPionsPltNULL (-4) : Le pointeur sur un entier non sign� correspondant au nombre
* de pions plac�s dans le plateau est NULL.
* - errPionNULL (-3) : Le pointeur qui pointe sur une variable de type "position" (structure)
* correspondant � un pion qui vient d'�tre plac� est NULL.
* - errPltNULL (-2) : Le pointeur sur un tableau multi-dimensionnel de type entier non sign�
* correspondant au plateau de jeu est NULL.
* - partieNull (-1) : Tous les pions ont �t� plac�s, le plateau est donc compl�tement rempli,
* il y a donc match nul.
* - partieEnCours (0) : Un pion vient d'�tre plac�, mais il n'y a pas de vainqueur, la partie
* continue.
* - partieFini (1) : La partie est finie et il y a un vainqueur.
*/
typedef enum _etatPartie_ {
    errJoueur = -5,
    errNbPionsPltNULL,
    errPionNULL,
    errPltNULL,
    partieNull,
    partieEnCours,
    partieFini,
} etatPartie;

/**
* La fonction viderBuffer permet de vider le buffer d�s lors que la longueur de la saisie d�passe une certaine
* taille. Cette fonction est donc principalement utilis�e dans les fonctions de saisie (saisiChoix, saisiPion,
* saisiOuiNon).
*/
void viderBuffer(void);

/**
* La fonction saisiChoix permet � l'utilisateur de r�alis� un choix entre plusieurs options, en saisissant
* un entier non sign� (positif).
*
* @param[out] choix est la variable pass� par r�f�rence permettant de r�cup�rer le choix de l'utilisateur.
* @param[in] msgChoix correspond au message affich� avant que l'utilisateur ne saisisse son choix. Le message est
* donc l� pour rappeler � l'utilisateur quelles options il a.
* @param[in] limiteChx est la valeur limite des choix possibles. Les choix possibles sont compris entre 1
* (inclus) et limiteChx (inclus).
*
* @return un entier est retourn� pour conna�tre l'�tat d'ex�cution de la fonction (cette valeur est
* utilis�e pour les tests unitaires) :
* - -1 : Cette valeur correspond � l'un des pointeurs en param�tres (choix, msgChoix) qui est NULL.
* - -2 : Cette valeur est retourn�e si la limite de choix est �gale � 0 ou sup�rieur � 30.
* - 0 : La fonction c'est bien ex�cut�.
*/
int saisiChoix(unsigned *choix, char *msgChoix, unsigned limiteChx);

/**
* La fonction generPlateau permet de g�n�rer le plateau pour une nouvelle partie en mettant � 0 tous les
* emplacements (ce qui correspond � un emplacement vide, sans pion).
*
* @param[out] plt correspond au plateau du jeu.
*
* @return un entier est retourn� pour conna�tre l'�tat d'ex�cution de la fonction (cette valeur est
* utilis�e pour les tests unitaires) :
* - -1 : Cette valeur correspond � l'un des pointeurs en param�tres (plt) qui est NULL.
* - 0 : La fonction c'est bien ex�cut�.
*/
int generPlateau(unsigned (*plt)[TAILLE_X]);

/**
* La fonction affichPlateau permet d'afficher le plateau :
* - 0 : correspond � un emplacement vide qui est remplac� par le caract�re "O".
* - 1 : correspond � un pion du joueur 1 (Rouge), il est remplac� par le caract�re "R".
* - 2 : correspond � un pion du joueur 2 (Jaune), il est remplac� par le caract�re "J".
*
* @param[out] plt correspond au plateau du jeu (en lecture seulement).
*
* @return un entier est retourn� pour conna�tre l'�tat d'ex�cution de la fonction (cette valeur est
* utilis�e pour les tests unitaires) :
* - -1 : Cette valeur correspond � l'un des pointeurs en param�tres (plt) qui est NULL.
* - 0 : La fonction c'est bien ex�cut�.
*/
int affichPlateau(const unsigned (*plt)[TAILLE_X]);

/**
* La fonction saisiPion permet au joueur de placer un pion sur le plateau. Il choisit la colonne dans laquelle il veut
* placer son pion et cette fonction d�termine dans quelle ligne se trouvera le pion.
*
* @param[out] plt correspond au plateau du jeu.
* @param[out] etat correspond � l'�tat de la partie en cours qui sera d�termin� apr�s que le joueur ait plac� son pion.
* @param[in] joueur correspond au joueur qui est en train de jouer (soit 1, soit 2).
* @param[in] nbPionsPlt correspond au nombre de pions plac� sur le plateau. Sa valeur sera incr�ment�e apr�s que le joueur
* ait plac� son pion.
*
* @return un entier est retourn� pour conna�tre l'�tat d'ex�cution de la fonction (cette valeur est
* utilis�e pour les tests unitaires) :
* - -1 : Cette valeur correspond � l'un des pointeurs en param�tres (plt, etat, nbPionsPlt) qui est NULL.
* - -2 : Cette valeur est retourn�e si le num�ro du joueur est incorrect (soit 1, soit 2).
* - 0 : La fonction c'est bien ex�cut�.
*/
int saisiPion(unsigned (*plt)[TAILLE_X], unsigned joueur, etatPartie *etat, unsigned *nbPionsPlt);

/**
* La fonction saisiOuiNon permet de saisir une r�ponse � une action o� l'on peut r�pondre par oui ("O" ou "o")
* ou par non ("N" ou "n").
*
* @param[in] msg correspond au message affich� lors de la saisie de l'utilisateur qui rappelle l'action qui va s'ex�cuter
* si l'utilisateur saisit oui.
* @param[out] choix correspond � la r�ponse de l'utilisateur.
*
* @return un entier est retourn� pour conna�tre l'�tat d'ex�cution de la fonction (cette valeur est
* utilis�e pour les tests unitaires) :
* - -1 : Cette valeur correspond � l'un des pointeurs en param�tres (msg, choix) qui est NULL.
* - 0 : La fonction c'est bien ex�cut�.
*/
int saisiOuiNon(const char *msg, char *choix);

/**
* La fonction verifEtatPartie permet de donner l'�tat de la partie en cours. Elle est utilis�e dans la fonction de saisie
* du pion afin de v�rifier le cours de la partie � chaque fois qu'un joueur place son pion.
*
* @param[in] plt correspond au plateau du jeu.
* @param[in] pion correspond au pion plac� par un joueur, permettant ainsi de d�terminer l'�tat de la partie (en lecture
* seulement).
* @param[in] joueur correspond au joueur ayant plac� son pion (permet de conna�tre quel sont les pions � v�rifier pour
* d�terminer le cours de la partie).
* @param[in] nbPionsPlt correspond au nombre de pions plac�s sur le plateau. Il permet de d�terminer s'il y a match
* nul.
*
* @return la valeur de retour correspond � l'�num�ration etatPartie, voir la description de etatPartie afin de conna�tre
* les valeurs et leurs significations.
*/
etatPartie verifEtatPartie(unsigned (*plt)[TAILLE_X], const position *pion, unsigned joueur, unsigned *nbPionsPlt);

/**
* \addtogroup testu Tests Unitaires
* Ici, se trouvent les diff�rents tests unitaires permettant de tester les diff�rentes fonctionnalit�s de ce projet.
* @{
*/

/**
* @defgroup saisiChoix Tests Unitaires de la fonction saisiChoix
* @ingroup testu
* Ici, se trouvent les diff�rents tests unitaires permettant de tester la fonction saisiChoix.
* @{
*/

/**
* Permet de tester le param�tre choix (pointeur) avec la valeur NULL.
*/
bool test_choixNULL(void);

/**
* Permet de tester le param�tre msgChoix (pointeur) avec la valeur NULL.
*/
bool test_msgChoixNULL(void);

/**
* Permet de tester le param�tre limiteChx avec cette limite �gal � 0.
*/
bool test_limiteChx0(void);

/**
* Permet de tester le param�tre limiteChx avec cette limite �gal � 31.
*/
bool test_limiteChx31(void);

/**
* @}
*/

/**
* @defgroup genererPlateau Tests Unitaires de la fonction genererPlateau
* @ingroup testu
* Ici, se trouvent les diff�rents tests unitaires permettant de tester la fonction genererPlateau.
* @{
*/

/**
* Permet de tester le param�tre plt (pointeur) avec la valeur NULL.
*/
bool test_pltGenerNULL(void);

/**
* Permet de tester la fonction dans son fonctionnement normal.
*/
bool test_pltGenerOK(void);

/**
* @}
*/

/**
* @defgroup affichPlateau Tests Unitaires de la fonction affichPlateau
* @ingroup testu
* Ici, se trouvent les diff�rents tests unitaires permettant de tester la fonction affichPlateau.
* @{
*/

/**
* Permet de tester le param�tre plt (pointeur) avec la valeur NULL.
*/
bool test_pltAffichNULL(void);

/**
* @}
*/

/**
* @defgroup saisiPion Tests Unitaires de la fonction saisiPion
* @ingroup testu
* Ici, se trouvent les diff�rents tests unitaires permettant de tester la fonction saisiPion.
* @{
*/

/**
* Permet de tester le param�tre plt (pointeur) avec la valeur NULL.
*/
bool test_pltSaisiPionNULL(void);

/**
* Permet de tester le param�tre etat (pointeur) avec la valeur NULL.
*/
bool test_etatNULL(void);

/**
* Permet de tester le param�tre nbPionsPlt (pointeur) avec la valeur NULL.
*/
bool test_nbPionsPltSaisiPionNULL(void);

/**
* Permet de tester le param�tre joueur avec la valeur 0.
*/
bool test_joueurSaisiPion0(void);

/**
* Permet de tester le param�tre joueur avec la valeur 3.
*/
bool test_joueurSaisiPion3(void);

/**
* @}
*/

/**
* @defgroup saisiOuiNon Tests Unitaires de la fonction saisiOuiNon
* @ingroup testu
* Ici, se trouvent les diff�rents tests unitaires permettant de tester la fonction saisiOuiNon.
* @{
*/

/**
* Permet de tester le param�tre msg (pointeur) avec la valeur NULL.
*/
bool test_msgSaisiOuiNonNULL(void);

/**
* Permet de tester le param�tre choix (pointeur) avec la valeur NULL.
*/
bool test_choixSaisiOuiNonNULL(void);

/**
* @}
*/

/**
* @defgroup verifEtatPartie Tests Unitaires de la fonction verifEtatPartie
* @ingroup testu
* Ici, se trouvent les diff�rents tests unitaires permettant de tester la fonction verifEtatPartie,
* les tests de cette fonction sont d�coup�s en deux parties : une premi�re partie qui concerne les
* tests des diff�rents param�tres de la fonction, et une seconde partie qui concerne les tests nominaux.
* @{
*/

/**
* @defgroup verifEtatPartie_Parametres Tests Unitaires de la fonction verifEtatPartie (param�tres)
* @ingroup verifEtatPartie
* Ici, se trouvent les tests de la fonction verifEtatPartie sur les param�tres.
* @{
*/

/**
* Permet de tester le param�tre plt (pointeur) avec la valeur NULL.
*/
bool test_pltVerifPartieNULL(void);

/**
* Permet de tester le param�tre pion (pointeur) avec la valeur NULL.
*/
bool test_pionVerifPartieNULL(void);

/**
* Permet de tester le param�tre joueur avec la valeur 0.
*/
bool test_joueurVerifPartie0(void);

/**
* Permet de tester le param�tre joueur avec la valeur 3.
*/
bool test_joueurVerifPartie3(void);

/**
* Permet de tester le param�tre nbPionsPlt (pointeur) avec la valeur NULL.
*/
bool test_nbPionsPltVerifPartieNULL(void);

/**
* @}
*/

/**
* @defgroup verifEtatPartie_Nominaux Tests Unitaires de la fonction verifEtatPartie (cas nominaux)
* @ingroup verifEtatPartie
* Ici, se trouvent les tests de la fonction verifEtatPartie sur les diff�rents �tats d'une partie.
* @{
*/

/**
* Permet de tester la fonction afin que la partie soit consid�r�e comme en cours.
*/
bool test_etatVerifPartieEnCours(void);

/**
* Permet de tester la fonction afin que la partie soit consid�r�e comme finie (avec 4 pions � la verticale).
*/
bool test_etatVerifPartieFiniVertl(void);

/**
* Permet de tester la fonction afin que la partie soit consid�r�e comme finie (avec 4 pions � la diagonale, en partant d'en bas � gauche).
*/
bool test_etatVerifPartieFiniDiagHaut(void);

/**
* Permet de tester la fonction afin que la partie soit consid�r�e comme finie (avec 4 pions � l'horizontale).
*/
bool test_etatVerifPartieFiniHoriz(void);

/**
* Permet de tester la fonction afin que la partie soit consid�r�e comme finie (avec 4 pions � la diagonale, en partant d'en haut � gauche).
*/
bool test_etatVerifPartieFiniDiagBas(void);

/**
* Permet de tester la fonction afin que la partie soit consid�r�e comme finie (en match nul, tous les pions sont plac�s).
*/
bool test_etatVerifPartieFiniMatchNul(void);

/**
* @}
*/

/**
* @}
*/

/**
* @}
*/

int main()
{
    unsigned chxMenu, plateau[TAILLE_Y][TAILLE_X], joueur = 1, nbPionsPlt;
    etatPartie etatP;
    char choixRejouer;

    do
    {
        printf("--------- Puissance 4 ---------\nBienvenue sur le c%cl%cbre jeu du\npuissance 4 !\n", 130, 138);

        saisiChoix(&chxMenu, "\nMenu :\n1. Jouer\n2. Mode test\n\n3. Quitter\n\n> ", 3);

        switch (chxMenu)
        {
            case 1 :
                do
                {
                    generPlateau(plateau);
                    etatP = partieEnCours;
                    nbPionsPlt = 0;

                    while (etatP == partieEnCours)
                    {
                        printf("\nJoueur %d (%s) joue.\n\n", joueur, (joueur == 1 ? "Rouge (R)" : "Jaune (J)"));
                        affichPlateau(plateau);
                        saisiPion(plateau, joueur, &etatP, &nbPionsPlt);

                        if (etatP == partieEnCours)
                        {
                            joueur = (joueur == 1 ? 2 : 1);
                        }
                    }

                    printf("\n");

                    affichPlateau(plateau);

                    if (etatP == partieFini)
                    {
                        printf("\nJoueur %d (%s) a gagn%c !\n\n", joueur, (joueur == 1 ? "Rouge (R)" : "Jaune (J)"), 130);
                    }
                    else
                    {
                        printf("\nMatch nul !\n\n");
                    }

                    saisiOuiNon("Voulez-vous rejouer (O ou N) ?\n> ", &choixRejouer);
                }
                while (choixRejouer == 'O' || choixRejouer == 'o');

                printf("\n");

                break;

            case 2 :
                printf("\nTests de la fonction saisiChoix : \n");
                printf("- Test pointeur choix NULL : ");
                test_choixNULL();
                printf("- Test pointeur msg NULL : ");
                test_msgChoixNULL();
                printf("- Test limite nombre de choix (0) : ");
                test_limiteChx0();
                printf("- Test limite nombre de choix (31) : ");
                test_limiteChx31();

                printf("\nTests de la fonction genererPlateau : \n");
                printf("- Test pointeur plateau NULL : ");
                test_pltGenerNULL();
                printf("- Test g%cn%cration du plateau : ",130,130);
                test_pltGenerOK();

                printf("\nTests de la fonction affichPlateau : \n");
                printf("- Test pointeur plateau NULL : ");
                test_pltAffichNULL();

                printf("\nTests de la fonction saisiPion : \n");
                printf("- Test pointeur plateau NULL : ");
                test_pltSaisiPionNULL();
                printf("- Test pointeur etat NULL : ");
                test_etatNULL();
                printf("- Test pointeur nombre de pions NULL : ");
                test_nbPionsPltSaisiPionNULL();
                printf("- Test limite num%cro joueur (0) : ",130);
                test_joueurSaisiPion0();
                printf("- Test limite num%cro joueur (3) : ",130);
                test_joueurSaisiPion3();

                printf("\nTests de la fonction saisiOuiNon : \n");
                printf("- Test pointeur msg NULL : ");
                test_msgSaisiOuiNonNULL();
                printf("- Test pointeur choix NULL : ");
                test_choixSaisiOuiNonNULL();

                printf("\nTests de la fonction verifEtatPartie : \n");
                printf("1) Tests partie param%ctres :\n",138);
                printf("- Test pointeur plateau NULL : ");
                test_pltVerifPartieNULL();
                printf("- Test pointeur pion NULL : ");
                test_pionVerifPartieNULL();
                printf("- Test limite num%cro joueur (0) : ",130);
                test_joueurVerifPartie0();
                printf("- Test limite num%cro joueur (3) : ",130);
                test_joueurVerifPartie3();
                printf("- Test pointeur nombre de pions NULL : ");
                test_nbPionsPltVerifPartieNULL();

                printf("\n2) Tests %ctat de la partie :\n",130);
                printf("- Test partie en cours : ");
                test_etatVerifPartieEnCours();
                printf("- Test fin de partie (vertical) : ");
                test_etatVerifPartieFiniVertl();
                printf("- Test fin de partie (diagonal bas -> haut) : ");
                test_etatVerifPartieFiniDiagHaut();
                printf("- Test fin de partie (horizontal) : ");
                test_etatVerifPartieFiniHoriz();
                printf("- Test fin de partie (diagonal haut -> bas) : ");
                test_etatVerifPartieFiniDiagBas();
                printf("- Test fin de partie (match nul) : ");
                test_etatVerifPartieFiniMatchNul();
                printf("\n");

                break;
        }
    }
    while (chxMenu != 3);

    return 0;
}

void viderBuffer(void)
{
    char c;

    do
    {
        c = getchar();
    }
    while (c != '\n');
}

int generPlateau(unsigned (*plt)[TAILLE_X])
{
    if (plt == NULL)
    {
        return -1;
    }

    for (size_t y = 0; y < TAILLE_Y; y++)
    {
        for (size_t x = 0; x < TAILLE_X; x++)
        {
            plt[y][x] = 0;
        }
    }

    return 0;
}

int affichPlateau(const unsigned (*plt)[TAILLE_X])
{
    if (plt == NULL)
    {
        return -1;
    }

    for (size_t y = 0; y < TAILLE_Y; y++)
    {
        for (size_t x = 0; x < TAILLE_X; x++)
        {
            switch (plt[y][x])
            {
                case 0:
                    printf("%c ", 'O');
                    break;

                case 1:
                    printf("%c ", 'R');
                    break;

                case 2:
                    printf("%c ", 'J');
                    break;
            }
        }

        printf("\n");
    }

    printf("\n1 2 3 4 5 6 7\n");

    return 0;
}

int saisiChoix(unsigned *choix, char *msgChoix, unsigned limiteChx)
{
    char saisiUsr [3], *verifSaisi = NULL;
    bool errSaisi;

    if (choix == NULL || msgChoix == NULL)
    {
        return -1;
    }

    if (limiteChx == 0 || limiteChx >= 30)
    {
        return -2;
    }

    do
    {
        errSaisi = false;

        printf("%s", msgChoix);
        fgets(saisiUsr, 4, stdin);

        if (saisiUsr[strlen(saisiUsr) - 1] == '\n')
        {
            saisiUsr[strlen(saisiUsr) - 1] = '\0';
        }


        if (strlen(saisiUsr) > 2)
        {
            viderBuffer();
        }

        *choix = strtol(saisiUsr, &verifSaisi, 10);

        if (strlen(verifSaisi) != 0 || *choix == 0 || *choix > limiteChx)
        {
            errSaisi = true;
            printf("\nLa saisi est incorrecte, veuillez r%cessayer\n", 130);
        }
    }
    while (errSaisi);

    return 0;
}

int saisiOuiNon(const char *msg, char *choix)
{
    char saisiUsr [3];
    bool errSaisi;

    if (msg == NULL || choix == NULL)
    {
        return -1;
    }

    do
    {
        errSaisi = false;

        printf("%s",msg);
        fgets(saisiUsr, 4, stdin);

        if (saisiUsr[strlen(saisiUsr) - 1] == '\n')
        {
            saisiUsr[strlen(saisiUsr) - 1] = '\0';
        }

        if (strlen(saisiUsr) > 2)
        {
            viderBuffer();
        }


        if (strlen(saisiUsr) != 1 || (saisiUsr[0] != 'O' && saisiUsr[0] != 'o' && saisiUsr[0] != 'N' && saisiUsr[0] != 'n'))
        {
            errSaisi = true;
            printf("\nLa saisi est incorrecte, veuillez r%cessayer\n\n", 130);
        }
    }
    while (errSaisi);

    *choix = saisiUsr[0];

    return 0;
}

int saisiPion(unsigned (*plt)[TAILLE_X], unsigned joueur, etatPartie *etat, unsigned *nbPionsPlt)
{
    position choixPos;

    choixPos.pos_y = 0;

    if (plt == NULL || etat == NULL || nbPionsPlt == NULL)
    {
        return -1;
    }

    if (joueur == 0 || joueur > 2)
    {
        return -2;
    }

    do
    {
        saisiChoix(&choixPos.pos_x, "\nVeuillez saisir un entier compris entre 1 et 7 :\n> ", 7);

        if (plt[choixPos.pos_y][choixPos.pos_x - 1] > 0)
        {
            printf("\nVous ne pouvez plus mettre de pions dans cette colonne, veuillez en saisir une autre.\n");
        }
    }
    while (plt[choixPos.pos_y][choixPos.pos_x - 1] > 0);

    while (plt[choixPos.pos_y][choixPos.pos_x - 1] == 0 && choixPos.pos_y < TAILLE_Y)
    {
        choixPos.pos_y++;
    }

    plt[choixPos.pos_y - 1][choixPos.pos_x - 1] = joueur;
    *nbPionsPlt = *nbPionsPlt + 1;

    *etat = verifEtatPartie(plt, &choixPos, joueur, nbPionsPlt);

    return 0;
}

etatPartie verifEtatPartie(unsigned (*plt)[TAILLE_X], const position *pion, unsigned joueur, unsigned *nbPionsPlt)
{
    unsigned cptPions, dir = 0;
    position posVerif;

    if (plt == NULL)
    {
        return errPltNULL;
    }

    if (pion == NULL)
    {
        return errPionNULL;
    }

    if (joueur == 0 || joueur > 2)
    {
        return errJoueur;
    }

    if (nbPionsPlt == NULL)
    {
        return errNbPionsPltNULL;
    }

    do
    {
        cptPions = 0;
        posVerif.pos_x = pion->pos_x - 1;
        posVerif.pos_y = pion->pos_y - 1;

        switch (dir)
        {
            case 0 :
                while (posVerif.pos_x > 0 && posVerif.pos_y < TAILLE_Y - 1 && plt[posVerif.pos_y + 1][posVerif.pos_x - 1] == joueur)
                {
                    posVerif.pos_y++;
                    posVerif.pos_x--;
                }

                while (posVerif.pos_x < TAILLE_X && posVerif.pos_y > 0 && cptPions < 4 && plt[posVerif.pos_y][posVerif.pos_x] == joueur)
                {
                    posVerif.pos_y--;
                    posVerif.pos_x++;
                    cptPions++;
                }

                break;

            case 1 :
                while (posVerif.pos_x > 0 && plt[posVerif.pos_y][posVerif.pos_x - 1] == joueur)
                {
                    posVerif.pos_x--;
                }

                while (posVerif.pos_x < TAILLE_X && cptPions < 4 && plt[posVerif.pos_y][posVerif.pos_x] == joueur)
                {
                    posVerif.pos_x++;
                    cptPions++;
                }

                break;

            case 2 :
                 while (posVerif.pos_x > 0 && posVerif.pos_y > 0 && plt[posVerif.pos_y - 1][posVerif.pos_x - 1] == joueur)
                {
                    posVerif.pos_y--;
                    posVerif.pos_x--;
                }

                while (posVerif.pos_x < TAILLE_X && posVerif.pos_y < TAILLE_Y && cptPions < 4 && plt[posVerif.pos_y][posVerif.pos_x] == joueur)
                {
                    posVerif.pos_y++;
                    posVerif.pos_x++;
                    cptPions++;
                }

                break;

            case 3 :
                while (posVerif.pos_y > 0 && plt[posVerif.pos_y - 1][posVerif.pos_x] == joueur)
                {
                    posVerif.pos_y--;
                }

                while (posVerif.pos_y < TAILLE_Y && cptPions < 4 && plt[posVerif.pos_y][posVerif.pos_x] == joueur)
                {
                    cptPions++;
                    posVerif.pos_y++;
                }

                break;
        }

        dir++;
    }
    while (dir < 4 && cptPions < 4);

    if (*nbPionsPlt == TAILLE_X * TAILLE_Y)
    {
        return partieNull;
    }

    if (cptPions < 4)
    {
        return partieEnCours;
    }

    return partieFini;
}


bool test_choixNULL(void)
{
    ASSERT_EQ(-1,saisiChoix(NULL,"Ceci est un message de choix",4));
}


bool test_msgChoixNULL(void)
{
    unsigned chx;

    ASSERT_EQ(-1,saisiChoix(&chx,NULL,4));
}

bool test_limiteChx0(void)
{
    unsigned chx;

    ASSERT_EQ(-2,saisiChoix(&chx,"Ceci est un message de choix",0));
}

bool test_limiteChx31(void)
{
    unsigned chx;

    ASSERT_EQ(-2,saisiChoix(&chx,"Ceci est un message de choix",31));
}

bool test_pltGenerNULL(void)
{
    ASSERT_EQ(-1,generPlateau(NULL));
}

bool test_pltGenerOK(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X];

    ASSERT_EQ(0,generPlateau(plateauTest));
}

bool test_pltAffichNULL(void)
{
    ASSERT_EQ(-1,affichPlateau(NULL));
}

bool test_pltSaisiPionNULL(void)
{
    unsigned nbPPltTest = 0;
    etatPartie etatPTest;

    ASSERT_EQ(-1,saisiPion(NULL,1,&etatPTest,&nbPPltTest));
}

bool test_etatNULL(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 0;

    ASSERT_EQ(-1,saisiPion(plateauTest,1,NULL,&nbPPltTest));
}

bool test_nbPionsPltSaisiPionNULL(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X];
    etatPartie etatPTest;

    ASSERT_EQ(-1,saisiPion(plateauTest,1,&etatPTest,NULL));
}

bool test_joueurSaisiPion0(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 0;
    etatPartie etatPTest;

    ASSERT_EQ(-2,saisiPion(plateauTest,0,&etatPTest,&nbPPltTest));
}

bool test_joueurSaisiPion3(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 0;
    etatPartie etatPTest;

    ASSERT_EQ(-2,saisiPion(plateauTest,3,&etatPTest,&nbPPltTest));
}

bool test_msgSaisiOuiNonNULL(void)
{
    char choixTest;

    ASSERT_EQ(-1,saisiOuiNon(NULL,&choixTest));
}

bool test_choixSaisiOuiNonNULL(void)
{
    ASSERT_EQ(-1,saisiOuiNon("Ceci est un message",NULL));
}

bool test_pltVerifPartieNULL(void)
{
    unsigned nbPPltTest = 0;
    position pionTest;

    pionTest.pos_x = 1;
    pionTest.pos_y = 1;

    ASSERT_EQ(errPltNULL, verifEtatPartie(NULL, &pionTest, 1, &nbPPltTest));
}

bool test_pionVerifPartieNULL(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 0;

    ASSERT_EQ(errPionNULL, verifEtatPartie(plateauTest, NULL, 1, &nbPPltTest));
}

bool test_joueurVerifPartie0(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 0;
    position pionTest;

    pionTest.pos_x = 1;
    pionTest.pos_y = 1;

    ASSERT_EQ(errJoueur, verifEtatPartie(plateauTest, &pionTest, 0, &nbPPltTest));
}

bool test_joueurVerifPartie3(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 0;
    position pionTest;

    pionTest.pos_x = 1;
    pionTest.pos_y = 1;

    ASSERT_EQ(errJoueur, verifEtatPartie(plateauTest, &pionTest, 3, &nbPPltTest));
}

bool test_nbPionsPltVerifPartieNULL(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X];
    position pionTest;

    pionTest.pos_x = 1;
    pionTest.pos_y = 1;

    ASSERT_EQ(errNbPionsPltNULL, verifEtatPartie(plateauTest, &pionTest, 1, NULL));
}

bool test_etatVerifPartieEnCours(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 1;
    position pionTest;

    pionTest.pos_y = 6;
    pionTest.pos_x = 1;

    generPlateau(plateauTest);

    plateauTest[pionTest.pos_y - 1][pionTest.pos_x - 1] = 1;

    ASSERT_EQ(partieEnCours, verifEtatPartie(plateauTest, &pionTest, 1, &nbPPltTest));
}

bool test_etatVerifPartieFiniVertl(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 1;
    position pionTest;

    pionTest.pos_y = 3;
    pionTest.pos_x = 1;

    generPlateau(plateauTest);

    plateauTest[5][0] = 1;
    plateauTest[4][0] = 1;
    plateauTest[3][0] = 1;
    plateauTest[pionTest.pos_y - 1][pionTest.pos_x - 1] = 1;

    ASSERT_EQ(partieFini, verifEtatPartie(plateauTest, &pionTest, 1, &nbPPltTest));
}

bool test_etatVerifPartieFiniDiagHaut(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 1;
    position pionTest;

    pionTest.pos_y = 4;
    pionTest.pos_x = 3;

    generPlateau(plateauTest);

    plateauTest[5][0] = 1;
    plateauTest[4][1] = 1;
    plateauTest[2][3] = 1;
    plateauTest[pionTest.pos_y - 1][pionTest.pos_x - 1] = 1;

    ASSERT_EQ(partieFini, verifEtatPartie(plateauTest, &pionTest, 1, &nbPPltTest));
}

bool test_etatVerifPartieFiniHoriz(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 1;
    position pionTest;

    pionTest.pos_y = 6;
    pionTest.pos_x = 3;

    generPlateau(plateauTest);

    plateauTest[5][0] = 1;
    plateauTest[5][1] = 1;
    plateauTest[5][3] = 1;
    plateauTest[pionTest.pos_y - 1][pionTest.pos_x - 1] = 1;

    ASSERT_EQ(partieFini, verifEtatPartie(plateauTest, &pionTest, 1, &nbPPltTest));
}

bool test_etatVerifPartieFiniDiagBas(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 1;
    position pionTest;

    pionTest.pos_y = 6;
    pionTest.pos_x = 4;

    generPlateau(plateauTest);

    plateauTest[2][0] = 1;
    plateauTest[3][1] = 1;
    plateauTest[4][2] = 1;
    plateauTest[pionTest.pos_y - 1][pionTest.pos_x - 1] = 1;

    ASSERT_EQ(partieFini, verifEtatPartie(plateauTest, &pionTest, 1, &nbPPltTest));
}

bool test_etatVerifPartieFiniMatchNul(void)
{
    unsigned plateauTest[TAILLE_Y][TAILLE_X], nbPPltTest = 42;
    position pionTest;

    pionTest.pos_y = 6;
    pionTest.pos_x = 1;

    generPlateau(plateauTest);

    plateauTest[pionTest.pos_y - 1][pionTest.pos_x - 1] = 1;

    ASSERT_EQ(partieNull, verifEtatPartie(plateauTest, &pionTest, 1, &nbPPltTest));
}
