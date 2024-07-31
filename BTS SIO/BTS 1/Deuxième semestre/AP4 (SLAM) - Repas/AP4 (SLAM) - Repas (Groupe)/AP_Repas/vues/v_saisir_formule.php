<div class="home">
    <div id="Home_title_ss">
        <br /><br />

        <?php
            echo '<div id="Titles"> Utilisteur Connecté : '.$_SESSION['ident']."</div>";
        ?>

        <center><table style="width : 50%; margin-top:30px">
            <tr>
                <th><center>ID</center></th>
                <th><center>Libellé</center></th>
                <th><center>Tarif</center></th>
                <th colspan="2"><center>Gestion</center></th>
            </tr>
            <?php
                foreach ($lesFormules as $laFormule)
                {
                    $nbMenus = getNbMenu($laFormule['id']) ;

                    if (isset($_REQUEST['action']) && ($_REQUEST['action'] == 'formuleModifer') && isset($_REQUEST['FormuleModifid']) && ($_REQUEST['FormuleModifid'] == $laFormule['id']))
                    {
                        echo '<tr>
                                <form method="POST" action="index.php?uc=gestion&action=validModifFormule">
                                    <td><center>'.$laFormule['id'].'<input id="FormuleModifid" name="FormuleModifid" type="hidden" value="'.$laFormule['id'].'"></center></td>
                                    <td><center><input type="text" name="libFormuleModif" placeholder="'.$laFormule['libelleFormule'].'" style="color:black"><input id="libFormuleOrigin" name="libFormuleOrigin" type="hidden" value="'.$laFormule['libelleFormule'].'"></center></td>
                                    <td><center><input type="text" name="tarifFormuleModif" placeholder="'.$laFormule['tarif'].'" maxlength="4" size="1" style="color:black"><input id="tarifFormuleOrigin" name="tarifFormuleOrigin" type="hidden" value="'.$laFormule['tarif'].'"></td>
                                    <td><center><input type="submit" name="validModifFormule" value="Valider" style="color:black"></center></td>
                                </form>
                            </tr>';
                    }
                    else
                    {
                        echo '<tr>
                            <td><center>'.$laFormule['id'].'</center></td>
                            <td><center>'.$laFormule['libelleFormule'].'</center></td>
                            <td><center>'.$laFormule['tarif'].'</center></td>
                            <td><center><form method="POST" action="index.php?uc=gestion&action=formuleModifer"><input type="submit" name="modifier" value="Modifer" style="color:black"><input id="FormuleModifid" name="FormuleModifid" type="hidden" value="'.$laFormule['id'].'"></form></center></td>';
                            if ($nbMenus == 0)
                            {
                                echo '<td><center><form method="POST" action="index.php?uc=gestion&action=formuleSupprimer"><input type="submit" name="supprimer" value="Supprimer" style="color:black"><input id="FormuleSuprid" name="FormuleSuprid" type="hidden" value="'.$laFormule['id'].'"></form></center></td>';
                            }
                        echo '</tr>';
                    }
                }
            ?>
        </table></center>
        <br />
        <div id="Titles">Ajouter une nouvelle formule :</div>
        <br />
        <center><table style="width : 50%">
            <tr>
                <th><center>Libellé</center></th>
                <th><center>Tarif</center></th>
            </tr>
            <tr>
                <form method="POST" action="index.php?uc=gestion&action=formuleAjouter">
                    <td><center><input type="text" name="libFormuleAjout" placeholder="Libellé" style="color:black"></center></td>
                    <td><center><input type="text" name="tarifFormuleAjout" placeholder="Tarif" style="color:black"></center></td>
                    <td><center><center><input type="submit" name="validAjout" value="Valider" style="color:black"></center></td>
                </form>
            </tr>
        </table></center>
    </div>
</div>