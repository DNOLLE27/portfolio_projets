<?php
if (!isset($_SESSION['idUtil'])) header("Location:index.php");
if (!isset($_SESSION['statut'])) header("Location:index.php");
if (($_SESSION['statut']!=2) && ($_SESSION['statut']!=4)) header("Location:index.php");
if (!isset($_REQUEST['action']))
	$action = "" ;
else
	$action = $_REQUEST['action'] ;
	
switch ($action)
{
	case "afficher" : { 
            //affiche les commandes du jour
            
            $ladateAMJ = date("Y-m-d") ;
            $ladateJMA = date("d/m/Y") ;
            $_SESSION['laDateCde'] = $ladateAMJ ;
            $lesCommandes = getLesCommandesJour($ladateAMJ) ;
            require "vues/v_commande_liste.php" ; 
            break ;             
        }

        case "utilisateurs" : {
            $lesUtilisateurs = getLesUtilisateurs();
            require "vues/v_gestion_utilisateurs.php" ;
            break;
        }

        case "modifier" : {
            $lesUtilisateurs = getLesUtilisateurs();
            require "vues/v_gestion_utilisateurs.php" ;
            break;
        }

        case "validmodif" : {
            echo '<center><h1 style="color:white"> Gestion des utilisateurs </h1></center>';

            $leIDUser = $_POST['idUser'];
            $unUtilisateur = getUnUtilisateur($leIDUser);
            $leNomUser = '"'.strtoupper($_POST['nomUser']).'"';
            $lePrenomUser = '"'.ucfirst($_POST['prenomUser']).'"';
            $laClasseUser = $_POST['ClasseCB'];
            $leLoginUser = '"'.strtoupper($_POST['loginUser']).'"';
            $leMDPUser = '"'.md5($_POST['mdpUser']).'"';
            $leStatutUser = $_POST['StatutCB'];
            $cptVerifModif = 0;

            $lesUtilisateursModif = getLesUtilisateurs();
            $cptLesUtilModif = 0;


            foreach ($lesUtilisateursModif as $unUtilisateurModif)
            {
                if ('"'.$unUtilisateurModif['nom'].'"' == $leNomUser && '"'.$unUtilisateurModif['prenom'].'"' == $lePrenomUser || '"'.$unUtilisateurModif['login'].'"' == $leLoginUser)
                {
                        $cptLesUtilModif++;
                }
            }

            if ($cptLesUtilModif == 0)
            {
                if ('"'.$unUtilisateur['nom'].'"' != $leNomUser && '"'.$unUtilisateur['prenom'].'"' != $lePrenomUser && '"'.$unUtilisateur['login'].'"' != $leLoginUser && '"'.$unUtilisateur['mdp'].'"' != $leMDPUser)
                {
                    if ($leNomUser != '""')
                    {
                        $laColonne = 'nom';
                        modifierUser($leIDUser, $laColonne, $leNomUser);
                        $cptVerifModif++;
                    }

                    if ($lePrenomUser != '""')
                    {
                        $laColonne = 'prenom';
                        modifierUser($leIDUser, $laColonne, $lePrenomUser);
                        $cptVerifModif++;
                    }
            
                    if ($laClasseUser != $unUtilisateur['idClasse'])
                    {
                        $laColonne = 'idClasse';
                        modifierUser($leIDUser, $laColonne, $laClasseUser);
                        $cptVerifModif++;
                    }
            
                    if ($leLoginUser != '""')
                    {
                        $laColonne = 'login';
                        modifierUser($leIDUser, $laColonne, $leLoginUser);
                        $cptVerifModif++;
                    }

                    if ($leMDPUser != '"d41d8cd98f00b204e9800998ecf8427e"')
                    {
                        $laColonne = 'mdp';
                        modifierUser($leIDUser, $laColonne, $leMDPUser);
                        $cptVerifModif++;
                    }

                    if ($leStatutUser != $unUtilisateur['statut'])
                    {
                        $laColonne = 'statut';
                        modifierUser($leIDUser, $laColonne, $leStatutUser);
                        $cptVerifModif++;
                    }
                }
                else
                {
                    $cptVerifModif = $cptVerifModif - 1;
                }

                if ($cptVerifModif == 0)
                {
                    echo '<center><h2 style="color:red"> Modification impossible, aucune donnée saisie ! </h2></center>
                          <center><p style="color:red">Veuillez saisir au moins une données pour faire une modification. </p></center>
                          <center><a href="index.php?uc=gestion&action=utilisateurs">Retour</a></center>';
                }
                else if ($cptVerifModif < 0)
                {
                    echo '<center><h2 style="color:red"> Modification impossible, les données saisies sont identiques ! </h2></center>
                          <center><p style="color:red">Les données saisies pour l'; echo "'"; echo 'utilisateur identifié n°'.$leIDUser.' ('.$unUtilisateur['nom'].' '.$unUtilisateur['prenom'].') sont identiques, veuillez en saisir des différentes.</p></center>
                          <center><a href="index.php?uc=gestion&action=utilisateurs">Retour</a></center>';
                }
                else
                {
                    echo '<center><h2 style="color:green"> Modification réussie ! </h2></center>
                          <center><p style="color:green">'.$cptVerifModif.' modification(s) ont été réalisées pour l'; echo "'"; echo 'utilisateur identifié n°'.$leIDUser.' ('.$unUtilisateur['nom'].' '.$unUtilisateur['prenom'].').</p></center>
                          <center><a href="index.php?uc=gestion&action=utilisateurs">Retour</a></center>';
                }
            }
            else
            {
                echo '<center><h2 style="color:red"> Modification impossible, les données saisies correspondent à un autre utilisateur existant ! </h2></center>
                <center><p style="color:red">Veuillez revoir les données sasies ou modifier l'."'".'utilisateur déjà existant.</p></center>
                <center><a href="index.php?uc=gestion&action=utilisateurs">Retour</a></center>';
            }
            
            break ;
        }

        case "supprimer" : {
            echo '<center><h1 style="color:white"> Gestion des utilisateurs </h1></center>';
            $idSupr = $_POST['utilisateuridsupr'];
            $unUtilisateurSupr = getUnUtilisateur($idSupr);
            supprimerUser($idSupr);
            echo '<center><h2 style="color:green"> Suppression réussie ! </h2></center>
                  <center><p style="color:green"> L'."'".'utilisateur identifié n°'.$idSupr.' ('.$unUtilisateurSupr['nom'].' '.$unUtilisateurSupr['prenom'].') a bien été supprimé.</p></center>
                  <center><a href="index.php?uc=gestion&action=utilisateurs">Retour</a></center>';
            break ;
        }
        
        case "ajouterUser" : {
            require "vues/v_gestion_utilisateurs_ajouter.php" ; 
            break ;
        }

        case "validajoutuser" : {
            echo '<center><h1 style="color:white"> Gestion des utilisateurs </h1></center>';

            $lesUtilisateursAjout = getLesUtilisateurs();
            $cptVerifAjout = 0;

            $NVNomUser = strtoupper($_POST['nomNVUser']);
            $NVPrenomUser = ucfirst($_POST['prenomNVUser']);
            $NVClasseUser = $_POST['ClasseNVCB'];
            $NVLoginUser = strtoupper($_POST['loginNVUser']);
            $NVMDPUser = md5($_POST['mdpNVUser']);
            $NVStatutUser = $_POST['StatutNVCB'];

            if ($NVNomUser != "" && $NVPrenomUser != "" && $NVClasseUser != "" && $NVLoginUser != "" && $NVMDPUser != "d41d8cd98f00b204e9800998ecf8427e" && $NVStatutUser != "")
            {
                foreach ($lesUtilisateursAjout as $unUtilisateurAjout)
                {
                    if ($NVNomUser == $unUtilisateurAjout['nom'] && $NVPrenomUser == $unUtilisateurAjout['prenom'] || $NVLoginUser == $unUtilisateurAjout['login'])
                    {
                        $cptVerifAjout++;
                    }
                }

                if ($cptVerifAjout == 0)
                {
                    nvUtilisateur($NVNomUser, $NVPrenomUser, $NVClasseUser, $NVLoginUser, $NVMDPUser, $NVStatutUser);
                    echo '<center><h2 style="color:green"> Ajout réussie ! </h2></center>
                    <center><p style="color:green"> L'."'".'utilisateur identifié n°'.getDernierUtilisateurID().' ('.$NVNomUser.' '.$NVPrenomUser.') a bien été ajouté.</p></center>
                    <center><a href="index.php?uc=gestion&action=utilisateurs">Retour</a></center>';
                }
                else
                {
                    echo '<center><h2 style="color:red"> Ajout impossible, cet utilisateur est déjà existant ! </h2></center>
                    <center><p style="color:red">Veuillez saisir un autre utilisateur ou modifier l'."'".'utilisateur déjà existant.</p></center>
                    <center><a href="index.php?uc=gestion&action=ajouterUser">Retour</a></center>';
                }
            }
            else
            {
                echo '<center><h2 style="color:red"> Ajout impossible, des données sont manquantes ! </h2></center>
                <center><p style="color:red">Veuillez saisir toutes les données du formulaire pour pouvoir faire un ajout. </p></center>
                <center><a href="index.php?uc=gestion&action=ajouterUser">Retour</a></center>';
            }

            break;
        }

        case "plus" : { 
            //affiche les commandes d'une date choisie
            $lesDates = getLesDatesMenus() ;
            require "vues/v_dates_commande.php" ; 
            break ;             
        }
        
        case "consulter" : { 
            //affiche les commandes d'une date choisie
            $ladateURL = $_REQUEST['date'] ;
            $ladateAMJ = substr($ladateURL,0,4)."-".substr($ladateURL,4,2)."-".substr($ladateURL,6,2) ;
            $ladateJMA = getDateJMA($ladateAMJ) ;
            $_SESSION['laDateCde'] = $ladateAMJ ;
            $lesCommandes = getLesCommandesJour($ladateAMJ) ;
            require "vues/v_commande_liste.php" ;  
            break ;             
        }
        
        case "compte" : { 
            //affiche les comptes des élèves
            $lesComptes = getLesComptesEleves() ;
            require "vues/v_comptes_eleves.php" ;  
            break ;             
        }
        
        case "menu" : { 
            //affiche la vue de saisie des menus
            $lesDates = getLesDatesMenus() ;
            require "vues/v_dates_menu.php" ; 
            break ;               
            break ;             
        }
        
        case "menusaisir" : { 
            //affiche la vue de saisie des menus
            $ladateURL = $_REQUEST['date'] ;
            $ladateAMJ = substr($ladateURL,0,4)."-".substr($ladateURL,4,2)."-".substr($ladateURL,6,2) ;
            $ladateJMA = getDateJMA($ladateAMJ) ;
            $lesMenus = getLesMenusJour($ladateAMJ) ;
            $lesFormules = getLesFormules();
            require "vues/v_saisir_menu.php" ; 
            break ;               
            break ;             
        }
        
        case "menuenregistrer" : { 
            //affiche la vue de saisie des menus
            $ladateAMJ = $_REQUEST['dateMenu'] ;
            $ladateJMA = getDateJMA($ladateAMJ) ;
            $numMenu = $_REQUEST['numMenu'] ;
            $descMenu = $_REQUEST['descMenu'.$numMenu] ;
            majMenu($ladateAMJ, $numMenu, $descMenu) ;
            $lesMenus = getLesMenusJour($ladateAMJ) ;
            $lesFormules = getLesFormules();
            require "vues/v_saisir_menu.php" ; 
            break ;               
            break ;             
        }
        
        case "menusupprimer" : { 
            //affiche la vue de saisie des menus
            $ladateURL = $_REQUEST['dateMenu'] ;
            $ladateAMJ = substr($ladateURL,0,4)."-".substr($ladateURL,4,2)."-".substr($ladateURL,6,2) ;
            $ladateJMA = getDateJMA($ladateAMJ) ;
            $numMenu = $_REQUEST['numMenu'] ;
            supMenu($ladateAMJ, $numMenu) ;
            $lesMenus = getLesMenusJour($ladateAMJ) ;
            $lesFormules = getLesFormules();
            require "vues/v_saisir_menu.php" ; 
            break ;               
            break ;             
        }
        
        case "menuajouter" : { 
            //affiche la vue de saisie des menus
            $ladateAMJ = $_REQUEST['dateMenu'] ;
            $ladateJMA = getDateJMA($ladateAMJ) ;
            $numMenu = $_REQUEST['numMenu'] ;
            $descMenu = $_REQUEST['descMenu'.$numMenu] ;
            $idFormule = $_REQUEST['formule'];
            ajoutMenu($ladateAMJ, $numMenu, $descMenu, $idFormule) ;
            $lesMenus = getLesMenusJour($ladateAMJ) ;
            $lesFormules = getLesFormules();
            require "vues/v_saisir_menu.php" ; 
            break ;                        
        }

        case "formulesAfficher" : { 
            //affiche la vue de saisie des menus
            $lesFormules = getLesFormulesall();
            require "vues/v_saisir_formule.php" ; 
            break ;               
            break ;             
        }

        case "formuleModifer" : {
            $lesFormules = getLesFormulesall() ;
            require "vues/v_saisir_formule.php" ; 
            break ;               
            break ;             
        }

        case "validModifFormule" : {
            $idMofifFormule = $_POST['FormuleModifid'];

            if (isset($_POST['libFormuleModif']) && ($_POST['libFormuleModif'] != ""))
            {
                $libModifFormule = $_POST['libFormuleModif'];
            }
            else
            {
                $libModifFormule = $_POST['libFormuleOrigin'];
            }

            if (isset($_POST['tarifFormuleModif']) && ($_POST['tarifFormuleModif'] != ""))
            {
                $tarifModifFormule = $_POST['tarifFormuleModif'];
            }
            else
            {
                $tarifModifFormule = $_POST['tarifFormuleOrigin'];
            }

            majFormule($idMofifFormule, $libModifFormule, $tarifModifFormule);
            $lesFormules = getLesFormulesall() ;
            require "vues/v_saisir_formule.php" ; 
            break ;               
            break ;             
        }

        case "formuleSupprimer" : { 
            //affiche la vue de saisie des formules
            $id = $_POST['FormuleSuprid'] ;
            supFormule($id) ;
            $lesFormules = getLesFormulesall() ;
            require "vues/v_saisir_formule.php" ; 
            break ;               
            break ;             
        }

        case "formuleAjouter" : { 
            //affiche la vue de saisie des formules
            $libFormuleAjout = $_POST['libFormuleAjout'] ;
            $tarifFormuleAjout = $_REQUEST['tarifFormuleAjout'];
            ajoutFormule($libFormuleAjout, $tarifFormuleAjout) ;
            $lesFormules = getLesFormulesall() ;
            require "vues/v_saisir_formule.php" ; 
            break ;                           
        }
        
        case "param" : { 
            //affiche la vue de saisie des menus
            $params = getParams() ;
            require "vues/v_params_affich.php" ; 
            break ;                        
        }
        
        case "paramenregistrer" : { 
            //affiche la vue de saisie des menus
            $heureDebutCde = $_REQUEST['heureDebutCde'] ;
            //$prixRepas = $_REQUEST['prixRepas'] ;
            $nbRepasDecouvert = $_REQUEST['nbRepasDecouvert'] ;
            if ($heureDebutCde!="") //&& $prixRepas!="")
            {
                majParams($heureDebutCde , $nbRepasDecouvert) ;
                $params = getParams() ;
                require "vues/v_params_affich.php" ; 
            }
            else 
            { 
                $message = "Veuillez renseigner les paramètres" ;
                require "vues/v_erreur.php" ; 
                require "vues/v_params_affich.php" ; 
            }
            
            break ;                        
        }
        
        case "crediter" : { 
            if (!isset($_REQUEST['role']))
                $role = "choixEleve" ;
            else
                $role = $_REQUEST['role'] ;
            switch($role)
            {
                case "choixEleve" : {
                    
                    //affiche la vue de saisie des crédits des comptes élèves : liste déroulante choix de l'élève
                    $lesEleves = getLesEleves();
                    $messageValid = '' ;
                    $_SESSION['enregistrer'] = false ;
                    require "vues/v_crediter_compte.php" ;
                    break ;                        
                }
        
                case "eleve" : {
                    //affiche le crédit actuel de l'élève et formulaire de saisie du règlement
                    $idEleve = $_REQUEST['id'] ;
                    $leEleve = getUnEtudiant($idEleve) ;
                    $_SESSION['enregistrer'] = false ;
                    require "vues/v_crediter_eleve.php" ;
                    break ;
                }
                
                case "enregistrer" : {
                    $idEleve = $_REQUEST['id'] ;
                    if (isset($_SESSION['enregistrer']) && $_SESSION['enregistrer'] == false)
                    {
                    //affiche le crédit actuel de l'élève et formulaire de saisie du règlement
                        
                        $datePaiement = $_REQUEST['datePaiement'] ;
                        $montant = $_REQUEST['montant'] ;
                        $typeReglement = $_REQUEST['typeReglement'] ;
                        $remarques = $_REQUEST['remarques'] ;
                        $_SESSION['enregistrer'] = true ;
                        //enregistrement du paiement
                        enregistrerPaiement($idEleve, $datePaiement, $montant, $typeReglement, $remarques) ;
                    }
                    
                    $leEleve = getUnEtudiant($idEleve) ;
                    $messageValid = 'Le solde de '.$leEleve['nom'].' '.$leEleve['prenom'].' est maintenant de '.$leEleve['creditRepas'].' €' ;
                    $lesEleves = getLesEleves();
                    require "vues/v_crediter_compte.php" ;
                    break ;
                }
            }
            break ;
        }
        
        case "paiement" : { 
            if (!isset($_REQUEST['role']))
                $role = "afficher" ;
            else
                $role = $_REQUEST['role'] ;
            switch($role)
            {
                case "afficher" : {
                    
                    //affiche la vue de consultation des paiements avec filtres
                    $lesEleves = getLesEleves();
                    $messageValid = '' ;
                    require "vues/v_paiement_filtres.php" ;
                    break ;                        
                }
                case "traiter" : {
                    
                    //récupération des données du filtre d'affichage
                    $dateDebut = $_REQUEST['dateDebut'] ;
                    $dateFin = $_REQUEST['dateFin'] ;
                    $typeReglement = $_REQUEST['typeReglement'] ;
                    $idEleve = $_REQUEST['idEleve'] ;
                    
                    //mise en session des paramètres pour l'export Excel
                    $_SESSION['dateDebut'] = $_REQUEST['dateDebut'] ;
                    $_SESSION['dateFin'] = $_REQUEST['dateFin'] ;
                    $_SESSION['typeReglement']= $_REQUEST['typeReglement'] ;
                    $_SESSION['idEleve'] = $_REQUEST['idEleve'] ;
                    
                    $lesEleves = getLesEleves();
                    $lesPaiements = getLesPaiements($dateDebut, $dateFin, $typeReglement, $idEleve) ;
                    $excel = false ;
                    require "vues/v_paiement_liste.php" ;
                    break ;                        
                }
                
                case "export" : {
                    
                    //récupération des données du filtre d'affichage
                    $dateDebut = $_SESSION['dateDebut'];
                    $dateFin = $_SESSION['dateFin'] ;
                    $typeReglement = $_SESSION['typeReglement'] ;
                    $idEleve = $_SESSION['idEleve'] ;

                    $lesEleves = getLesEleves();
                    $lesPaiements = getLesPaiements($dateDebut, $dateFin, $typeReglement, $idEleve) ;
                    exportPaiements($dateDebut, $dateFin, $typeReglement, $idEleve) ;
                    $excel = true ;
                    require "vues/v_paiement_liste.php" ;
                    break ;                        
                }
                
                case "maj" : {
                    
                    //récupération des données du filtre d'affichage
                    $id = $_REQUEST['id'] ;
                    $lePaiement = getLePaiement($id) ;
                    $lesEleves = getLesEleves();
                    $_SESSION['enregistrer'] = false ;
                    require "vues/v_paiement_maj.php" ;
                    break ;                        
                }
                
                case "modifier" : {
                    
                    if ($_SESSION['enregistrer'] == false)
                    {
                        //récupération des données du filtre d'affichage
                        $id = $_REQUEST['id'] ;
                        $datePaiement = $_REQUEST['datePaiement'] ;
                        $montant = $_REQUEST['montant'] ;
                        $typeReglement = $_REQUEST['typeReglement'] ;
                        $remarques = $_REQUEST['remarques'] ;
                        $idEleve = $_REQUEST['idEleve'] ;

                        //enregistrement du paiement
                        modifierPaiement($idEleve, $datePaiement, $montant, $typeReglement, $remarques, $id) ;
                        $_SESSION['enregistrer'] = true ;
                        $leEleve = getUnEtudiant($idEleve) ;
                    }
                    
                    
                    $lesEleves = getLesEleves();
                    $messageValid = 'Le paiement a bien été modifié' ;
                    require "vues/v_paiement_filtres.php" ;
                    break ;                        
                }
                
                case "suppr" : {
                    
                    //récupération des données du filtre d'affichage
                    $id = $_REQUEST['id'] ;
                    //suppression du paiement
                    supprimerPaiement( $id) ;

                    $lesEleves = getLesEleves();
                    $messageValid = 'Le paiement a bien été supprimé' ;
                    require "vues/v_paiement_filtres.php" ;
                    break ;                        
                }
            }
            break ;
        }
        
        case "listerepas" : { 
            if (!isset($_REQUEST['role']))
                $role = "afficher" ;
            else
                $role = $_REQUEST['role'] ;
            switch($role)
            {
                case "afficher" : {
                    
                    //affiche la vue avec filtres
                    $messageValid = '' ;
                    require "vues/v_listerepas_filtres.php" ;
                    break ;                        
                }
                case "traiter" : {
                    
                    //récupération des données du filtre d'affichage
                    $dateDebut = $_REQUEST['dateDebut'] ;
                    $dateFin = $_REQUEST['dateFin'] ;
                    $typeRepas = $_REQUEST['typeRepas'] ;
                    //mise en session des paramètres pour l'export Excel
                    $_SESSION['dateDebut'] = $_REQUEST['dateDebut'] ;
                    $_SESSION['dateFin'] = $_REQUEST['dateFin'] ;
                    $_SESSION['typeRepas'] = $_REQUEST['typeRepas'] ;
                    
                    if ($typeRepas==2)
                        $lesRepasPris = getLesRepasDetail($dateDebut, $dateFin) ;
                    else if ($typeRepas==1)
                        $lesRepasPris = getLesRepasCumul($dateDebut, $dateFin) ;
                    else{
                        $lesRepasPris = getLesRepasFormules($dateDebut, $dateFin);
                    }
                    $excel = false ;
                    require "vues/v_listerepas_liste.php" ;
                    break ;                        
                }                      
                case "export" : {
                    
                    //récupération des données du filtre d'affichage
                    $dateDebut = $_SESSION['dateDebut'];
                    $dateFin = $_SESSION['dateFin'] ;
                    $typeRepas = $_SESSION['typeRepas'] ;
                    //mise en session des paramètres pour l'e
                    if ($typeRepas==2)
                        $lesRepasPris = getLesRepasDetail($dateDebut, $dateFin) ;
                    elseif ($typeRepas ==1)
                        $lesRepasPris = getLesRepasCumul($dateDebut, $dateFin) ;
                    else{
                         $lesRepasPris = getLesRepasFormules($dateDebut, $dateFin);
                        }
                    exportRepas($dateDebut, $dateFin, $typeRepas, $lesRepasPris) ;
                    $excel = true ;
                    require "vues/v_listerepas_liste.php" ;
                    break ;                        
                }               
            }
            break ;
        }
        
        case "mdp" : { 
            //affiche la vue de saisie des menus
            require "vues/v_mdp_saisir.php" ;
            break ;                        
        }
        
        case "mdpenregistrer" : { 
            //affiche la vue de saisie des menus
            $mdp = $_REQUEST['mdp1'] ;
            enrmdp($mdp, $_SESSION['idUtil']);
            $message = "Votre mot de passe a été modifié" ;
            require "vues/v_ok.php" ; 
            break ;                        
        }
}
?>
