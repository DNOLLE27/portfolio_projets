/*
NOLLE Damien - L3 Informatique

Toutes les fonctionnalit�s demand�es dans le cahier des charges fonctionnent. Un menu a �t�
ajout� en plus.

Probl�me(s) rencontr�(s) :
- Lors de la g�n�ration du plateau, certaines g�n�rations donnent des bateaux perpendiculaire,
ils sont "coll�s" mais ne se chevauchent pas. En revanche, ce n'est pas cens� se produire car
des v�rifications sont faites pour qu'il y ait au moins une cellule d'espace entre un bateau
et un autre (horizontalement et verticalement).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define TAILLE 10 // Correspond � la taille du plateau TAILLExTAILLE.
#define DEBUG 0 // Le mode Debug permet d'afficher les bateaux non d�couverts tout au long de la partie.
                // - 0 : Mode Debug d�sactiv�.
                // - 1 : Mode Debug activ�.

void generer_partie (void); // Cette proc�dure permet de "g�n�rer" et "lancer" une partie.
                            // Elle ne comporte aucun param�tre et ne retourne aucune valeur.
                            // Elle s'occupe donc de la partie "jeu" du programme.
                            // Elle est utilis�e dans le menu pr�sent dans main().

void generer_jeu (int (*tab)[TAILLE], char (*p_bat)[5][6]); // Cette proc�dure permet de g�n�rer le plateau du jeu et s'occupe donc du
                                                            // positionnement des bateaux.
                                                            // - Le param�tre int (*tab)[TAILLE] permet de faire passer la matrice (le
                                                            // plateau) par r�f�rence afin de pouvoir modifier celui-ci.
                                                            // - Le param�tre char (*p_bat)[5][6] permet aussi de faire passer un tableau
                                                            // par r�f�rence, mais il s'agit ici d'un tableau � 3 dimensions (ou un tableau
                                                            // de tableaux de chaines de caract�res) qui va contenir la positions des points,
                                                            // pr�sent sur le plateau, repr�sentant les bateaux.
                                                            // Cette proc�dure est utilis� dans generer_partie.

void generer_dir_bat (int t_bat, int px_depart, int py_depart, int (*tab)[TAILLE], int *etat_proc, char (*p_bat)[5][6]); // Cette proc�dure permet de g�n�rer la direction et le reste des points
                                                                                                                         // formant le corps d'un bateau.
                                                                                                                         // - Le param�tre int t_bat correspond � la taille du bateau et donc au
                                                                                                                         // nombre de points � g�n�rer.
                                                                                                                         // - Les param�tres int px_depart et int py_depart correspond aux
                                                                                                                         // coordonn�es de d�part du bateau (� savoir le premier point g�n�r�).
                                                                                                                         // - Le param�tre int (*tab)[TAILLE] permet de faire passer la matrice (le
                                                                                                                         // plateau) par r�f�rence afin de pouvoir modifier celui-ci.
                                                                                                                         // - Le param�tre int *etat_proc permet de faire ressortir une erreur de
                                                                                                                         // g�n�ration. Cela permet soit de reg�n�rer le point de d�part du bateau,
                                                                                                                         // soit de reg�n�rer enti�rement le plateau. C'est une variable pass� par
                                                                                                                         // r�f�rence qui se verra attribu�e -1 si il y a une erreur, 0 sinon.
                                                                                                                         // - Le param�tre char (*p_bat)[5][6] permet de faire passer par r�f�rence
                                                                                                                         // le tableau contenant tous les bateaux et leurs points afin d'ajouter le
                                                                                                                         // reste du corps des bateaux.
                                                                                                                         // Cette proc�dure est utilis� dans generer_jeu.

void generer_pos_bat (const int (*tab)[TAILLE], size_t *x, size_t *y); // Cette proc�dure permet de g�n�rer la position de d�part d'un bateau sur le plateau.
                                                                       // - Le param�tre const int (*tab)[TAILLE] permet de faire passer le plateau par r�f�rence,
                                                                       // mais en lecture seulement. Car on a pas besoin de le modifier.
                                                                       // - Les param�tres size_t *x et size_t *y sont des variables pass� par r�f�rence qui vont
                                                                       // accueillir les coordonn�es du point de d�part du bateau.
                                                                       // Cette proc�dure est utilis� dans generer_jeu.

void afficher_jeu (const int (*tab)[TAILLE], int court_partie, char opt_plouf); // Cette proc�cure permet d'afficher le plateau du jeu. La matrice qui repr�sente
                                                                                // le plateau du jeu contient en r�alit� que des valeurs num�rique, elle permet
                                                                                // donc de "convertir" ces valeurs en un symbole afin de repr�senter les bateaux,
                                                                                // l'oc�an, les tires sur un bateau ou dans l'eau.
                                                                                // - Le param�tre const int (*tab)[TAILLE] permet de faire passer le plateau par r�f�rence,
                                                                                // mais en lecture seulement. Car on a pas besoin de le modifier.
                                                                                // - Le param�tre court_partie permet de changer l'affichage du plateau en fonction de si
                                                                                // c'est la fin de la partie (1) ou si celle-ci est en cours (0). La fin de la partie
                                                                                // signifie que les bateaux non d�couverts doivent �tre affich�s.
                                                                                // /!\ Le mode debugage n'est pas impact�. Si celui-ci est activ�, peut importe la valeur
                                                                                // du param�tre pr�c�dent, les bateaux non d�couverts seront affich�s.
                                                                                // Cette proc�dure est utilis� dans generer_jeu.

void saisi_O_N (char *str, size_t limite, char *msg); // Cette proc�dure permet de saisir une r�ponse � une question o� l'on peut r�pondre par oui ou par non.
                                                      // - Le param�tre char *str permet de faire passer une variable de chaine de caract�res par r�f�rence qui
                                                      // va recueillir la r�ponse ("O", "o", "N" ou "n").
                                                      // - Le param�tre size_t limite correspond � la taille de la chaine de caract�res du param�tre pr�c�dent.
                                                      // Elle est utilis� pour les v�rifications de saisi.
                                                      // - Le param�tre char *msg correspond au message/� la question affich� lors de la saisi de la r�ponse.
                                                      // Cette proc�dure est utilis� dans generer_partie.

void saisi_coord (size_t *ps_x, size_t *ps_y); // Cette proc�dure permet la saisi de coordonn�es par l'utilisateur. Permettant ainsi de jouer � la bataille navale.
                                               // - Les param�tres size_t *ps_x, size_t *ps_y vont accueillir les coordonn�es saisies. Ce sont des variables pass�es par
                                               // r�f�rence et qui seront utilis�es pour le plateau.
                                               // Cette proc�dure est utilis� dans generer_partie.

void vider_buffer (void); // Cette proc�dure permet de vider le cache buffer lors d'une saisie. Elle est utilis�e lors des saisies afin de ne pas
                          // engendrer de probl�mes lors d'une prochaine saisi.
                          // Cette proc�dure ne prend aucun param�tre et est principalement utilis� dans les proc�dures de saisies (saisi_O_N et
                          // saisi_coord) mais aussi dans main().

int main()
{
    char saisi_menu [3];
    bool aff_head = true;;

    do
    {
        if (aff_head)
        {
            printf("------------ BATAILLE NAVALE ------------\nBienvenue au jeu de la bataille navale !\n\n- Menu :\n1. Jouer\n2. R%cgles\n3. Quitter",138);
        }

        printf("\n\n> ");
        fgets(saisi_menu, 3, stdin);

        if (saisi_menu[strlen(saisi_menu) - 1] == '\n')
        {
            saisi_menu[strlen(saisi_menu) - 1] = '\0';
        }

        if (strlen(saisi_menu) >= 2)
        {
            vider_buffer();
        }

        if (
            strlen(saisi_menu) != 1
            || (saisi_menu[0] != '1'
            && saisi_menu[0] != '2'
            && saisi_menu[0] != '3')
            )
        {
            while (strlen(saisi_menu) != 1
                || (saisi_menu[0] != '1'
                && saisi_menu[0] != '2'
                && saisi_menu[0] != '3')
                )
            {
                printf("\nErreur de saisie : Vous avez soit saisie une cha%cne de caract%cres trop longue ou trop courte, soit un caract%cre non valide.\nNouvelle saisie> ", 140, 138, 138);
                fgets(saisi_menu, 3, stdin);

                if (saisi_menu[strlen(saisi_menu) - 1] == '\n')
                {
                    saisi_menu[strlen(saisi_menu) - 1] = '\0';
                }

                if (strlen(saisi_menu) >= 2)
                {
                    vider_buffer();
                }
            }
        }

        switch (saisi_menu[0])
        {
            case '1' :
                printf("\n");
                generer_partie();
                aff_head = true;
                break;

            case '2' :
                aff_head = false;
                printf("\n----------------- REGLES -----------------\nL'objectif de la bataille navale est de\nd%ctruire les 9 navires ennemis. Pour cela,\nvous aurez acc%cs %c une grille (%dx%d)\nrepr%csentant le champ de bataille. Vous\ndevez saisir les coordonn%ces des cellules\nafin de d%ccouvrir et couler ces navires.\n\nLes coordonn%ces ce note de la fa%cons\nsuivante : [A-J][0-9]\nPar exemple : A0, C6, B4, etc...\n\nLorsque vous aurez tir%c sur une cellule,\ncette derni%cre changera sur la grille avec\nl'un des symboles suivant :\n- X : Une partie du navire est touch%c.\n- O : Vous avez tir%c dans l'eau.\n\nLe symbole ~ repr%csente l'oc%can.", 130, 138, 133, TAILLE, TAILLE, 130, 130, 130, 130, 135, 130, 138, 130, 130, 130, 130);
                break;
        }
    }
    while (saisi_menu[0] != '3');

    return 0;
}

void saisi_coord (size_t *ps_x, size_t *ps_y)
{
    char saisi[4];
    bool err_saisi;
    int ret;
    char * str;

    printf("Veuillez saisir les coordonn%ces de la cellule cible :\n> ",130);

    do
    {
        err_saisi = false;

        fgets(saisi, 4, stdin);

        if (saisi[strlen(saisi) - 1] == '\n')
        {
            saisi[strlen(saisi) - 1] = '\0';
        }

        if (strlen(saisi) >= 3)
        {
            vider_buffer();
        }

        if (strlen(saisi) == 2)
        {
            switch (saisi[0])
            {
                case 'A' :
                    *ps_x = 0;
                    break;

                case 'B' :
                    *ps_x = 1;
                    break;

                case 'C' :
                    *ps_x = 2;
                    break;

                case 'D' :
                    *ps_x = 3;
                    break;

                case 'E' :
                    *ps_x = 4;
                    break;

                case 'F' :
                    *ps_x = 5;
                    break;

                case 'G' :
                    *ps_x = 6;
                    break;

                case 'H' :
                    *ps_x = 7;
                    break;

                case 'I' :
                    *ps_x = 8;
                    break;

                case 'J' :
                    *ps_x = 9;
                    break;

                default :
                    err_saisi = true;
            }

            if (!err_saisi)
            {
                ret = strtol(&saisi[1],&str,10);

                if (strlen(str) == 0)
                {
                    *ps_y = ret;
                }
                else
                {
                    err_saisi = true;
                }

                printf("\n");
            }
        }
        else
        {
            err_saisi = true;
        }

        if (err_saisi)
        {
            printf("\nErreur de saisie : Veuillez saisir les coordonn%ces de la cellule sous la forme \"A0\", le premier caract%cre doit %ctre une lettre majuscule (compris entre A et J) et un chiffre (compris entre 0 et 9).\nNouvelle saisie> ", 130, 138, 136);
        }
    }
    while (err_saisi);
}

void saisi_O_N (char *str, size_t limite, char *msg)
{
    printf("%s [O ou N]\n> ", msg);
    fgets(str, limite, stdin);

    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    if (strlen(str) >= limite - 1)
    {
        vider_buffer();
    }

    if (
        strlen(str) != 1
        || (str[0] != 'O'
        && str[0] != 'o'
        && str[0] != 'N'
        && str[0] != 'n')
        )
    {
        while (
               strlen(str) != 1
                || (str[0] != 'O'
                && str[0] != 'o'
                && str[0] != 'N'
                && str[0] != 'n')
               )
        {
            printf("\nErreur de saisie : Vous avez soit saisie une cha%cne de caract%cres trop longue ou trop courte, soit un caract%cre non valide.\nNouvelle saisie> ", 140, 138, 138);
            fgets(str, limite, stdin);

            if (str[strlen(str) - 1] == '\n')
            {
                str[strlen(str) - 1] = '\0';
            }

            if (strlen(str) >= limite - 1)
            {
                vider_buffer();
            }
        }
    }

    if (str[0] != 'O' && str[0] != 'o')
    {
        printf("\n");
    }
}

void vider_buffer (void)
{
    char c;

    do
    {
        c = getchar();
    }
    while (c != '\n');
}

void generer_partie (void)
{
    char choix_plouf [3], choix_abandonner [3], choix_rejouer [3];
    size_t px, py;
    int plateau [TAILLE] [TAILLE], cpt_coups, nb_bat_jeu, cpt_points_touch, cpt_points;
    char pos_bat [9][5][6];
    char pos_rech [6];
    bool pos_trouv;

    do
    {
        cpt_coups = 0;
        nb_bat_jeu = 9;

        saisi_O_N(choix_plouf, 3, "Voulez-vous afficher les tirs dans l'eau ?");
        generer_jeu(plateau,pos_bat);

        do
        {
            afficher_jeu(plateau, 0, choix_plouf[0]);

            if (cpt_coups != 0 && nb_bat_jeu > 0)
            {
                saisi_O_N(choix_abandonner, 3, "Voulez-vous Abandonner ?");

                if (choix_abandonner[0] == 'O' || choix_abandonner[0] == 'o')
                {
                    break;
                }
            }
            else
            {
                choix_abandonner[0] = 'N';
                choix_abandonner[1] = '\0';
            }

            saisi_coord(&px, &py);

            switch (plateau[px][py])
            {
                case 0 :
                    plateau[px][py] = 2;
                    printf("Et plouf... Rat%c !\n", 130);
                    break;

                case 1 :
                    plateau[px][py] = 3;
                    pos_trouv = false;

                    sprintf(pos_rech, "x%d-y%d", (int) px, (int) py);

                    for (size_t pos_rch_i = 0; pos_rch_i < 9 && !pos_trouv; pos_rch_i++)
                    {
                        cpt_points = 0;
                        cpt_points_touch = 0;

                        for (size_t pos_rch_y = 0; pos_rch_y < 5; pos_rch_y++)
                        {
                            if (pos_bat[pos_rch_i][pos_rch_y][0] != '\0')
                            {
                                cpt_points++;

                                if (pos_bat[pos_rch_i][pos_rch_y][0] == 'X')
                                {
                                    cpt_points_touch++;
                                }
                            }

                            if (strncmp(pos_rech, pos_bat[pos_rch_i][pos_rch_y], 6) == 0)
                            {
                                sprintf(pos_bat[pos_rch_i][pos_rch_y], "X");
                                cpt_points_touch++;
                                pos_trouv = true;
                            }
                        }
                    }

                    if (cpt_points_touch < cpt_points)
                    {
                        printf("Touch%c !\n", 130);
                    }
                    else
                    {
                        nb_bat_jeu--;
                        printf("Touch%c... Coul%c !\n", 130, 130);
                    }

                    break;

                default :
                    printf("Zone d%cj%c d%ccouverte... Rat%c ! \n", 130, 133, 130, 130);
            }

            cpt_coups++;
        }
        while ((choix_abandonner[0] == 'N' || choix_abandonner[0] == 'n') && nb_bat_jeu > 0);

        printf("\n------ FIN DE LA PARTIE ------\n");
        afficher_jeu(plateau, 1, choix_plouf[0]);
        printf("Vous avez coul%c %d bateau(x) en %d coup(s) !\n\n", 130, 9 - nb_bat_jeu, cpt_coups);

        saisi_O_N(choix_rejouer, 3, "Voulez-vous rejouer ?");

        if (choix_rejouer[0] == 'O' || choix_rejouer[0] == 'o')
        {
            printf("\n");
        }
    }
    while (choix_rejouer[0] == 'O' || choix_rejouer[0] == 'o');
}

void generer_jeu (int (*tab)[TAILLE], char (*p_bat)[5][6])
{
    srand(time(NULL));
    int type_bat[4], nb_bat, etat_genr_dir, cpt_err_gen_jeu;
    size_t pos_x, pos_y, typ_bat_pos;


    for (int i = 0; i < 9; i++)
    {
        for (int y = 0; y < 5; y++)
        {
             sprintf(p_bat[i][y], "%c", '\0');
        }
    }

    do
    {
        type_bat[0] = 4;
        type_bat[1] = 3;
        type_bat[2] = 1;
        type_bat[3] = 1;
        nb_bat = 9;


        for (size_t i = 0; i < TAILLE; i++)
        {
            for (size_t y = 0; y < TAILLE; y++)
            {
                tab[i][y] = 0;
            }
        }

        while (nb_bat > 0)
        {
            cpt_err_gen_jeu = 0;
            generer_pos_bat(tab,&pos_x,&pos_y);

            tab[pos_x][pos_y] = 1;

            do
            {
                typ_bat_pos = rand() % 4;
            }
            while (type_bat[typ_bat_pos] == 0);

            do
            {
                sprintf(p_bat[9 - nb_bat][0], "x%d-y%d", (int)pos_x, (int)pos_y);

                etat_genr_dir = 0;

                switch (typ_bat_pos)
                {
                    case 0: // Bateau de taille 2
                        generer_dir_bat(2, pos_x, pos_y, tab, &etat_genr_dir, &p_bat[9 - nb_bat]);
                        break;

                    case 1: // Bateau de taille 3
                        generer_dir_bat(3, pos_x, pos_y, tab, &etat_genr_dir, &p_bat[9 - nb_bat]);
                        break;

                    case 2: // Bateau de taille 4
                        generer_dir_bat(4, pos_x, pos_y, tab, &etat_genr_dir, &p_bat[9 - nb_bat]);
                        break;

                    case 3: // Bateau de taille 5
                        generer_dir_bat(5, pos_x, pos_y, tab, &etat_genr_dir, &p_bat[9 - nb_bat]);
                        break;
                }

                if (etat_genr_dir == -1)
                {
                    tab[pos_x][pos_y] = 0;

                    generer_pos_bat(tab, &pos_x, &pos_y);

                    tab[pos_x][pos_y] = 1;

                    cpt_err_gen_jeu++;
                }
            }
            while (etat_genr_dir == -1 && cpt_err_gen_jeu < 5);

            if (cpt_err_gen_jeu >= 5)
            {
                break;
            }

            type_bat[typ_bat_pos]--;
            nb_bat--;
        }
    }
    while (cpt_err_gen_jeu >= 5);
}

void generer_pos_bat (const int (*tab)[TAILLE], size_t *x, size_t *y)
{
        do
        {
            *x = rand() % TAILLE;
            *y = rand() % TAILLE;
        }
        while (
                tab[*x][*y] != 0 ||
                (*x + 1 < TAILLE && tab[*x + 1][*y] != 0) ||
                (*x > 0 && tab[*x - 1][*y] != 0) ||
                (*y + 1 < TAILLE && tab[*x][*y + 1] != 0) ||
                (*y > 0 && tab[*x][*y - 1] != 0) ||
                (*x > 0 && *y + 1 < TAILLE && tab[*x - 1][*y + 1] != 0) ||
                (*x + 1 < TAILLE && *y + 1 < TAILLE && tab[*x + 1][*y + 1] != 0) ||
                (*x > 0 && *y > 0 && tab[*x - 1][*y - 1] != 0) ||
                (*x + 1 < TAILLE && *y > 0 && tab[*x + 1][*y - 1] != 0)
               );
}

void generer_dir_bat (int t_bat, int px_depart, int py_depart, int (*tab)[TAILLE], int *etat_proc, char (*p_bat)[5][6])
{
    char dirs[] = {'N','S','E','O'};
    size_t dir_pos;
    int i, cpt_err = 0;
    bool err_dir;

    dir_pos = rand() % 4;

    do
    {
        i = 1;
        err_dir = false;

        while (i < t_bat && !err_dir)
        {
            switch (dirs[dir_pos])
            {
                case 'N' :
                    if (
                        px_depart - i < 0
                        || tab[px_depart - i][py_depart] != 0
                        || (px_depart - i - 1 > 0 && tab[px_depart - i - 1][py_depart] != 0)
                        || (py_depart - 1 > 0 && tab[px_depart - i][py_depart - 1] != 0)
                        || (py_depart + 1 <= TAILLE - 1 && tab[px_depart - i][py_depart + 1] != 0)
                        )
                    {
                        err_dir = true;
                    }

                    break;

                case 'S' :
                    if (
                        px_depart + i > TAILLE - 1
                        || tab[px_depart + i][py_depart] != 0
                        || (px_depart + i + 1 <= TAILLE - 1 && tab[px_depart + i + 1][py_depart] != 0)
                        || (py_depart - 1 > 0 && tab[px_depart + i][py_depart - 1] != 0)
                        || (py_depart + 1 <= TAILLE - 1 && tab[px_depart + i][py_depart + 1] != 0)
                        )
                    {
                        err_dir = true;
                    }

                    break;

                case 'E' :
                    if (
                        py_depart + i > TAILLE - 1
                        || tab[px_depart][py_depart + i] != 0
                        || (py_depart + i + 1 <= TAILLE - 1 && tab[px_depart][py_depart + i + 1] != 0)
                        || (px_depart - 1 > 0 && tab[px_depart - 1][py_depart + i] != 0)
                        || (px_depart + 1 <= TAILLE - 1 && tab[px_depart + 1][py_depart + i] != 0)
                        )
                    {
                        err_dir = true;
                    }

                    break;

                case 'O' :
                    if (
                        py_depart - i < 0
                        || tab[px_depart][py_depart - i] != 0
                        || (py_depart - i - 1 > 0 && tab[px_depart][py_depart - i - 1] != 0)
                        || (px_depart - 1 > 0 && tab[px_depart - 1][py_depart - i] != 0)
                        || (px_depart + 1 <= TAILLE - 1 && tab[px_depart + 1][py_depart - i] != 0)
                        )
                    {
                        err_dir = true;
                    }

                    break;
            }

            if (err_dir)
            {
                cpt_err++;

                if (dir_pos + 1 > 3)
                {
                    dir_pos = 0;
                }
                else
                {
                    dir_pos++;
                }
            }

            i++;
        }
    }
    while (err_dir && cpt_err < 4);

    if (!err_dir)
    {
        switch (dirs[dir_pos])
        {
            case 'N' :
                for (i = 1; i <= t_bat - 1; i++)
                {
                    tab[px_depart - i][py_depart] = 1;
                    sprintf(p_bat[0][i], "x%d-y%d", px_depart - i, py_depart);
                }

                break;

            case 'S' :
                for (i = 1; i <= t_bat - 1; i++)
                {
                    tab[px_depart + i][py_depart] = 1;
                    sprintf(p_bat[0][i], "x%d-y%d", px_depart + i, py_depart);
                }

                break;

            case 'E' :
                for (i = 1; i <= t_bat - 1; i++)
                {
                    tab[px_depart][py_depart + i] = 1;
                    sprintf(p_bat[0][i], "x%d-y%d", px_depart, py_depart + i);
                }

                break;

            case 'O' :
                for (i = 1; i <= t_bat - 1; i++)
                {
                    tab[px_depart][py_depart - i] = 1;
                    sprintf(p_bat[0][i], "x%d-y%d", px_depart, py_depart - i);
                }

                break;
        }
    }
    else
    {
        *etat_proc = -1;
    }
}

void afficher_jeu (const int (*tab)[TAILLE], int court_partie, char opt_plouf)
{
    char alpha[] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("\n  0 1 2 3 4 5 6 7 8 9\n");

    for (size_t i = 0; i < TAILLE; i++)
    {
        printf("%c ", alpha[i]);
        for (size_t y = 0; y < TAILLE; y++)
        {
            switch (tab[i][y])
            {
                case 0 :
                    printf("%c ", '~');

                    break;

                case 1 :
                    if (DEBUG == 1 || court_partie == 1)
                    {
                        printf("%c ", 'B');
                    }
                    else
                    {
                        printf("%c ", '~');
                    }

                    break;

                case 2 :
                    if (opt_plouf == 'O' || opt_plouf == 'o')
                    {
                        printf("%c ", 'O');
                    }
                    else
                    {
                        printf("%c ", '~');
                    }

                    break;

                case 3 :
                    printf("%c ", 'X');

                    break;
            }
        }

        printf("\n");
    }

    printf("\n");
}
