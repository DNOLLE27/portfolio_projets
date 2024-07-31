<center><h1 style="color:white"> Gestion des utilisateurs </h1></center>

<center><table style="width : 70%; margin-top:30px; border: 1px solid white">
    <tr>
        <td colspan="9"><center><a style="font-size:20px" href="index.php?uc=gestion&action=ajouterUser">Ajouter un nouvel Utilisiateur<img src= "includes/img/plus.png" style="width:30px"></a></center></td>
    </tr>
    <tr style="color:white">
        <th style="border: 1px solid white"><center>ID</center></th>
        <th style="border: 1px solid white"><center>NOM</center></th>
        <th style="border: 1px solid white"><center>Prénom</center></th>
        <th style="border: 1px solid white"><center>Classe</center></th>
        <th style="border: 1px solid white"><center>Login</center></th>
        <th style="border: 1px solid white"><center>Mot de passe</center></th>
        <th style="border: 1px solid white"><center>Statut</center></th>
        <th style="border: 1px solid white" colspan="2"><center>Éditer</center></th>
    </tr>

    <?php
        foreach ($lesUtilisateurs as $unUtilisateur)
        {
            if (isset($_REQUEST['action']) && ($_REQUEST['action'] == 'modifier') && isset($_REQUEST['utilisateurid']) && ($_REQUEST['utilisateurid'] == $unUtilisateur['id']))
            {
                if ($unUtilisateur['statut'] == 1)
                {
                    $leStatut = "Élève";
                }
                else if ($unUtilisateur['statut'] == 2)
                {
                    $leStatut = "Gestionnaire";
                }
                else if ($unUtilisateur['statut'] == 4)
                {
                    $leStatut = "Prestataire";
                }

                if ($unUtilisateur['idClasse'] == 1)
                {
                    $laClasse = "1ère Année";
                }
                else if ($unUtilisateur['idClasse'] == 2)
                {
                    $laClasse = "2ème Année";
                }
                else
                {
                    $laClasse = "/";
                }

                echo '<form method="POST" action="index.php?uc=gestion&action=validmodif">
                            <tr height:30px">
                                <td style="color:white; border: 1px solid white"><center>'.$unUtilisateur['id'].'<input id="idUser" name="idUser" type="hidden" value="'.$unUtilisateur['id'].'"></center></td>
                                <td style="color:black; border: 1px solid white"><center><input type="text" name="nomUser" style="text-transform:uppercase" placeholder="'.$unUtilisateur['nom'].'"></center></td>
                                <td style="color:black; border: 1px solid white"><center><input type="text" name="prenomUser" style="text-transform:capitalize" placeholder="'.$unUtilisateur['prenom'].'"></center></td>
                                <td style="color:black; border: 1px solid white"><center>
                                <select name="ClasseCB" id="ClasseCB">
                                    <option value="'.$unUtilisateur['idClasse'].'" selected>'.$laClasse.'</option>';
                if ($unUtilisateur['idClasse'] != 1)
                {
                    echo '<option value="1">1ère Année</option>';
                }
                
                if ($unUtilisateur['idClasse'] != 2)
                {
                    echo '<option value="2">2ème Année</option>';
                }
                
                if ($unUtilisateur['idClasse'] != 0)
                {
                    echo '<option value="0">/</option>';
                }
                          echo '</select>
                                </center></td>
                                <td style="color:black; border: 1px solid white"><center><input type="text" name="loginUser" style="text-transform:uppercase" placeholder="'.$unUtilisateur['login'].'"></center></td>
                                <td style="color:black; border: 1px solid white"><center><input type="password" name="mdpUser" placeholder="********"></center></td>
                                <td style="color:black; border: 1px solid white"><center>
                                <select name="StatutCB" id="StatutCB">
                                    <option value="'.$unUtilisateur['statut'].'" selected>'.$leStatut.'</option>';
                if ($unUtilisateur['statut'] != 1)
                {
                    echo '<option value="1">Élève</option>';
                }
                
                if ($unUtilisateur['statut'] != 2)
                {
                    echo '<option value="2">Gestionnaire</option>';
                }
                
                if ($unUtilisateur['statut'] != 4)
                {
                    echo '<option value="4">Prestataire</option>';
                }
                          echo '</select>
                                </center></td>
                                <td style="border: 1px solid white" colspan="2"><center><input type="submit" name="validermodif" value="Valider"></center></td>
                            </tr>
                        </form>';
            }
            else
            {
                if ($unUtilisateur['statut'] == 1)
                {
                    $leStatut = "Élève";
                }
                else if ($unUtilisateur['statut'] == 2)
                {
                    $leStatut = "Gestionnaire";
                }
                else if ($unUtilisateur['statut'] == 4)
                {
                    $leStatut = "Prestataire";
                }

                if ($unUtilisateur['idClasse'] == 1)
                {
                    $laClasse = "1ère Année";
                }
                else if ($unUtilisateur['idClasse'] == 2)
                {
                    $laClasse = "2ème Année";
                }
                else
                {
                    $laClasse = "/";
                }
    
                echo '<tr height:30px">
                            <td style="color:white; border: 1px solid white"><center>'.$unUtilisateur['id'].'</center></td>
                            <td style="color:white; border: 1px solid white"><center>'.$unUtilisateur['nom'].'</center></td>
                            <td style="color:white; border: 1px solid white"><center>'.$unUtilisateur['prenom'].'</center></td>
                            <td style="color:white; border: 1px solid white"><center>'.$laClasse.'</center></td>
                            <td style="color:white; border: 1px solid white"><center>'.$unUtilisateur['login'].'</center></td>
                            <td style="color:white; border: 1px solid white"><center>********</center></td>
                            <td style="color:white; border: 1px solid white"><center>'.$leStatut.'</center></td>
                            <td style="border: 1px solid white"><center><form method="POST" action="index.php?uc=gestion&action=modifier"><input type="submit" name="modifier" value="Modifer"><input id="utilisateurid" name="utilisateurid" type="hidden" value="'.$unUtilisateur['id'].'"></form></center></td>
                            <td style="border: 1px solid white"><center><form method="POST" action="index.php?uc=gestion&action=supprimer"><input type="submit" name="supprimer" value="Supprimer"><input id="utilisateuridsupr" name="utilisateuridsupr" type="hidden" value="'.$unUtilisateur['id'].'"></form></center></td>
                      </tr>';
            }
        }
    ?>
</table></center>