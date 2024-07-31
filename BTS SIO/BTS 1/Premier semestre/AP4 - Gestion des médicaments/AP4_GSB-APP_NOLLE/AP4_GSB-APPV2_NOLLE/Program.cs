using System;

namespace AP4_GSB_APPV2_NOLLE
{
    class Program
    {
        static void Main(string[] args)
        {
            /// Initialisation des variables
            string rechmedic;
            string demande;
            string redemande;
            string chmedic;
            string chvente;
            string svchmedic;
            int D;
            int I;
            int E;
            int S;
            int quantite;
            int vtquantite;
            int ajototal;
            int qtotal;
            float prix;
            float prixtotal;

            /// Le stock des medicaments est remis a zero lorsque le programme se lance ou est relance 
            D = 0;
            I = 0;
            E = 0;
            S = 0;

            Console.WriteLine("Bienvenue sur le logiciel de Gestion du Stock de Médicaments du laboratoire GSB !");
            redemande = "OUI";
            while (redemande == "OUI")
            {
                /// Menu principal
                Console.WriteLine("Quelle est votre demande ? (Ajouter un médicament en stock (AV), Vendre un médicament (VM) ou Visualiser le stock des médicaments (VS).)");
                demande = Console.ReadLine();
                while (demande != "AV" && demande != "VM" && demande != "VS")
                {
                    Console.WriteLine("Désolé, votre demande est incorrecte, veuillez réessayer :");
                    Console.WriteLine("Quelle est votre demande ? (Ajouter un médicament en stock (AV), Vendre un médicament (VM) ou Visualiser le stock des médicaments (VS).)");
                    demande = Console.ReadLine();
                }
                if (demande == "AV") /// Ajout de medicaments dans le stock
                {
                    Console.Clear();
                    rechmedic = "OUI";
                    svchmedic = "";
                    qtotal = 0;
                    ajototal = 0;
                    while (rechmedic == "OUI")
                    {
                        /// Choix du medicament et de la quantite
                        Console.WriteLine("Veuillez saisir le code du médicament que vous voulez ajouter (Doliprane (D), Ibuprofene(I), Efferalgan(E) ou Spasfon(S).) :");
                        chmedic = Console.ReadLine();
                        while (chmedic != "D" && chmedic != "I" && chmedic != "E" && chmedic != "S")
                        {
                            Console.WriteLine("Désolé, le médicament demandé n'est pas disponible ou n'existe pas dans nos stocks, veuillez réessayer :");
                            Console.WriteLine("Veuillez saisir le code du médicament que vous voulez ajouter (Doliprane (D), Ibuprofene(I), Efferalgan(E) ou Spasfon(S).) :");
                            chmedic = Console.ReadLine();
                        }
                        if (chmedic == svchmedic)
                        {
                            Console.WriteLine("Désolé, le médicament demandé à déjà été séléctionné précédement et vous ne pouvez pas re-séléctionner le même pour une nouvelle demande d'ajout, veuillez réessayer :");
                            Console.WriteLine("Veuillez saisir le code du médicament que vous voulez ajouter (Doliprane (D), Ibuprofene(I), Efferalgan(E) ou Spasfon(S).) :");
                            chmedic = Console.ReadLine();
                        }
                        if (chmedic == "D")
                        {
                            Console.WriteLine("Veuillez saisir la quantité : ");
                            quantite = int.Parse(Console.ReadLine());
                            D = D + quantite;
                            svchmedic = "D";
                            qtotal = qtotal + quantite;
                        }
                        else if (chmedic == "I")
                        {
                            Console.WriteLine("Veuillez saisir la quantité : ");
                            quantite = int.Parse(Console.ReadLine());
                            I = I + quantite;
                            svchmedic = "I";
                            qtotal = qtotal + quantite;
                        }
                        else if (chmedic == "E")
                        {
                            Console.WriteLine("Veuillez saisir la quantité : ");
                            quantite = int.Parse(Console.ReadLine());
                            E = E + quantite;
                            svchmedic = "E";
                            qtotal = qtotal + quantite;
                        }
                        else if (chmedic == "S")
                        {
                            Console.WriteLine("Veuillez saisir la quantité : ");
                            quantite = int.Parse(Console.ReadLine());
                            S = S + quantite;
                            svchmedic = "S";
                            qtotal = qtotal + quantite;
                        }
                        /// Demande de nouvel ajout
                        Console.WriteLine("Voullez vous faire un autre ajout ? (Attention le médicament à choisir doit être différent du précédent !) Tapez 'OUI' ou 'NON' :");
                        rechmedic = Console.ReadLine();
                        if (rechmedic != "OUI") /// Si l utilisateur ne souhaite pas faire un autre ajout le programme affiche le nombre total des medicaments ajoute demande si l utilisateur souhaite faire une autre demande
                        {
                            Console.WriteLine("Vous avez ajoutez " + qtotal + " médicaments en stocks.");
                            Console.WriteLine("Voulez-vous faire une autre demande ? Tapez 'OUI' ou 'NON' :");
                            redemande = Console.ReadLine();
                            if (redemande != "OUI") /// Visualisation du stock si l utilisateur ne souhaite pas faire une autre demande et fermeture du programme
                            {
                                Console.WriteLine("Voici le stock actuel de médicament(s) :");
                                Console.WriteLine();
                                Console.WriteLine("Doliprane (D) : " + D);
                                Console.WriteLine();
                                Console.WriteLine("Ibuprofene (I) : " + I);
                                Console.WriteLine();
                                Console.WriteLine("Efferalgan (E) : " + E);
                                Console.WriteLine();
                                Console.WriteLine("Spasfon (S) : " + S);
                                Console.WriteLine();
                                ajototal = D + I + E + S;
                                Console.WriteLine("Nombre total de médicament(s) dans le stock : " + ajototal + " médicament(s).");
                            }
                        }
                    }
                }
                else if (demande == "VM") /// Demande de vente de medicament
                {
                    ///Choix du medicament a vendre avec prix unitaire et quantite
                    Console.Clear();
                    Console.WriteLine("Veuillez saisir le code du médicament que vous shouaitez vendre (Doliprane (D), Ibuprofene(I), Efferalgan(E) ou Spasfon(S).) :");
                    chvente = Console.ReadLine();
                    while (chvente != "D" && chvente != "I" && chvente != "E" && chvente != "S") 
                    {
                        Console.WriteLine("Désolé, le médicament demandé n'est pas disponible ou n'existe pas dans nos stocks, veuillez réessayer :");
                        Console.WriteLine("Veuillez saisir le code du médicament que vous shouaitez vendre (Doliprane (D), Ibuprofene(I), Efferalgan(E) ou Spasfon(S).) :");
                        chvente = Console.ReadLine();
                    }
                    if (chvente == "D")
                    {
                        Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                        vtquantite = int.Parse(Console.ReadLine());
                        while ((vtquantite > D) || (vtquantite == 0) || (vtquantite < 0))
                        {
                            if (vtquantite > D)
                            {
                                Console.WriteLine("Désolé, Vous ne pouvez pas vendre une quantité supérieure à ce qu'il y a dans le stock, veuillez réessayer :");
                                Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                                vtquantite = int.Parse(Console.ReadLine());
                            }
                            else if ((vtquantite == 0) || (vtquantite < 0))
                            {
                                Console.WriteLine("Désolé, Vous ne pouvez pas vendre une quantité nul ou négative, veuillez réessayer :");
                                Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                                vtquantite = int.Parse(Console.ReadLine());
                            }
                        }
                        if ((vtquantite < D) && (vtquantite > 0))
                        {
                            Console.WriteLine("Veuillez saisir le prix à l'unité :");
                            prix = float.Parse(Console.ReadLine());

                            prixtotal = vtquantite * prix;
                            D = D - vtquantite;

                            Console.WriteLine("Vous avez vendu " + vtquantite +" Doliprane (D) pour " + prix + " euros unitaire pour un total de " + prixtotal + " euros.");

                            Console.WriteLine("Voulez-vous faire une autre demande ? Tapez 'OUI' ou 'NON' :");
                            redemande = Console.ReadLine();
                            if (redemande != "OUI")
                            {
                                Console.WriteLine("Voici le stock actuel de médicament(s) :");
                                Console.WriteLine();
                                Console.WriteLine("Doliprane (D) : " + D);
                                Console.WriteLine();
                                Console.WriteLine("Ibuprofene (I) : " + I);
                                Console.WriteLine();
                                Console.WriteLine("Efferalgan (E) : " + E);
                                Console.WriteLine();
                                Console.WriteLine("Spasfon (S) : " + S);
                                Console.WriteLine();
                                ajototal = D + I + E + S;
                                Console.WriteLine("Nombre total de médicament(s) dans le stock : " + ajototal + " médicament(s).");
                            }
                        }
                    }
                    else if (chvente == "I")
                    {
                        Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                        vtquantite = int.Parse(Console.ReadLine());
                        while ((vtquantite > I) || (vtquantite == 0) || (vtquantite < 0))
                        {
                            if (vtquantite > I)
                            {
                                Console.WriteLine("Désolé, Vous ne pouvez pas vendre une quantité supérieure à ce qu'il y a dans le stock, veuillez réessayer :");
                                Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                                vtquantite = int.Parse(Console.ReadLine());
                            }
                            else if ((vtquantite == 0) || (vtquantite < 0))
                            {
                                Console.WriteLine("Désolé, Vous ne pouvez pas vendre une quantité nul ou négative, veuillez réessayer :");
                                Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                                vtquantite = int.Parse(Console.ReadLine());
                            }
                        }
                        if ((vtquantite < I) && (vtquantite > 0))
                        {
                            Console.WriteLine("Veuillez saisir le prix à l'unité :");
                            prix = float.Parse(Console.ReadLine());

                            prixtotal = vtquantite * prix;
                            I = I - vtquantite;

                            Console.WriteLine("Vous avez vendu " + vtquantite + " Ibuprofene (I) pour " + prix + " euros unitaire pour un total de " + prixtotal + " euros.");

                            Console.WriteLine("Voulez-vous faire une autre demande ? Tapez 'OUI' ou 'NON' :");
                            redemande = Console.ReadLine();
                            if (redemande != "OUI")
                            {
                                Console.WriteLine("Voici le stock actuel de médicament(s) :");
                                Console.WriteLine();
                                Console.WriteLine("Doliprane (D) : " + D);
                                Console.WriteLine();
                                Console.WriteLine("Ibuprofene (I) : " + I);
                                Console.WriteLine();
                                Console.WriteLine("Efferalgan (E) : " + E);
                                Console.WriteLine();
                                Console.WriteLine("Spasfon (S) : " + S);
                                Console.WriteLine();
                                ajototal = D + I + E + S;
                                Console.WriteLine("Nombre total de médicament(s) dans le stock : " + ajototal + " médicament(s).");
                            }
                        }
                    }
                    else if (chvente == "E")
                    {
                        Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                        vtquantite = int.Parse(Console.ReadLine());
                        while ((vtquantite > E) || (vtquantite == 0) || (vtquantite < 0))
                        {
                            if (vtquantite > E)
                            {
                                Console.WriteLine("Désolé, Vous ne pouvez pas vendre une quantité supérieure à ce qu'il y a dans le stock, veuillez réessayer :");
                                Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                                vtquantite = int.Parse(Console.ReadLine());
                            }
                            else if ((vtquantite == 0) || (vtquantite < 0))
                            {
                                Console.WriteLine("Désolé, Vous ne pouvez pas vendre une quantité nul ou négative, veuillez réessayer :");
                                Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                                vtquantite = int.Parse(Console.ReadLine());
                            }
                        }
                        if ((vtquantite < E) && (vtquantite > 0))
                        {
                            Console.WriteLine("Veuillez saisir le prix à l'unité :");
                            prix = float.Parse(Console.ReadLine());

                            prixtotal = vtquantite * prix;
                            E = E - vtquantite;

                            Console.WriteLine("Vous avez vendu " + vtquantite + " Efferalgan (E) pour " + prix + " euros unitaire pour un total de " + prixtotal + " euros.");

                            Console.WriteLine("Voulez-vous faire une autre demande ? Tapez 'OUI' ou 'NON' :");
                            redemande = Console.ReadLine();
                            if (redemande != "OUI")
                            {
                                Console.WriteLine("Voici le stock actuel de médicament(s) :");
                                Console.WriteLine();
                                Console.WriteLine("Doliprane (D) : " + D);
                                Console.WriteLine();
                                Console.WriteLine("Ibuprofene (I) : " + I);
                                Console.WriteLine();
                                Console.WriteLine("Efferalgan (E) : " + E);
                                Console.WriteLine();
                                Console.WriteLine("Spasfon (S) : " + S);
                                Console.WriteLine();
                                ajototal = D + I + E + S;
                                Console.WriteLine("Nombre total de médicament(s) dans le stock : " + ajototal + " médicament(s).");
                            }
                        }
                    }
                    else if (chvente == "S")
                    {
                        Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                        vtquantite = int.Parse(Console.ReadLine());
                        while ((vtquantite > S) || (vtquantite == 0) || (vtquantite < 0))
                        {
                            if (vtquantite > S)
                            {
                                Console.WriteLine("Désolé, Vous ne pouvez pas vendre une quantité supérieure à ce qu'il y a dans le stock, veuillez réessayer :");
                                Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                                vtquantite = int.Parse(Console.ReadLine());
                            }
                            else if ((vtquantite == 0) || (vtquantite < 0))
                            {
                                Console.WriteLine("Désolé, Vous ne pouvez pas vendre une quantité nul ou négative, veuillez réessayer :");
                                Console.WriteLine("Veuillez saisir la quantité que vous souhaitez vendre :");
                                vtquantite = int.Parse(Console.ReadLine());
                            }
                        }
                        if ((vtquantite < S) && (vtquantite > 0))
                        {
                            Console.WriteLine("Veuillez saisir le prix à l'unité :");
                            prix = float.Parse(Console.ReadLine());

                            prixtotal = vtquantite * prix;
                            S = S - vtquantite;

                            Console.WriteLine("Vous avez vendu " + vtquantite + " Spasfon (S) pour " + prix + " euros unitaire pour un total de " + prixtotal + " euros.");

                            Console.WriteLine("Voulez-vous faire une autre demande ? Tapez 'OUI' ou 'NON' :");
                            redemande = Console.ReadLine();
                            if (redemande != "OUI")
                            {
                                Console.WriteLine("Voici le stock actuel de médicament(s) :");
                                Console.WriteLine();
                                Console.WriteLine("Doliprane (D) : " + D);
                                Console.WriteLine();
                                Console.WriteLine("Ibuprofene (I) : " + I);
                                Console.WriteLine();
                                Console.WriteLine("Efferalgan (E) : " + E);
                                Console.WriteLine();
                                Console.WriteLine("Spasfon (S) : " + S);
                                Console.WriteLine();
                                ajototal = D + I + E + S;
                                Console.WriteLine("Nombre total de médicament(s) dans le stock : " + ajototal + " médicament(s).");
                            }
                        }
                    }
                }
                else if (demande == "VS") /// Affichage du stock de medicaments
                {
                    Console.Clear();
                    Console.WriteLine("Voici le stock actuel de médicament(s) :");
                    Console.WriteLine();
                    Console.WriteLine("Doliprane (D) : " + D);
                    Console.WriteLine();
                    Console.WriteLine("Ibuprofene (I) : " + I);
                    Console.WriteLine();
                    Console.WriteLine("Efferalgan (E) : " + E);
                    Console.WriteLine();
                    Console.WriteLine("Spasfon (S) : " + S);
                    Console.WriteLine();
                    ajototal = D + I + E + S;
                    Console.WriteLine("Nombre total de médicament(s) dans le stock : " + ajototal + " médicament(s).");
                    Console.WriteLine();
                    Console.WriteLine("Voulez-vous faire une autre demande ? Tapez 'OUI' ou 'NON' :");
                    redemande = Console.ReadLine();
                }
            }
        }
    }
}
