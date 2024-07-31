<center><h1 style="color:white"> Gestion des utilisateurs </h1></center>

<center><h2 style="color:white; text-decoration: underline"> Nouvel utilisateur : </h2></center>

<form method="POST" action="index.php?uc=gestion&action=validajoutuser">
    <center><table style="margin-top:30px; height : 300px; width : 500px; border: 1px solid white">
        <tr>
            <td style="color:white; text-align:right">NOM : </td>
            <td><input type="text" name="nomNVUser" style="text-transform:uppercase" placeholder="NOM"></td>
        </tr>
        <tr>
            <td style="color:white; text-align:right">Prénom : </td>
            <td><input type="text" name="prenomNVUser" style="text-transform:capitalize" placeholder="Prénom"></td>
        </tr>
        <tr>
            <td style="color:white; text-align:right">Classe : </td>
            <td>
                <select name="ClasseNVCB" id="ClasseNVCB">
                    <option value="1">1ère Année</option>
                    <option value="2">2ème Année</option>
                    <option value="0">/</option>
                </select>
            </td>
        </tr>
        <tr>
            <td style="color:white; text-align:right">Login : </td>
            <td><input type="text" name="loginNVUser" style="text-transform:uppercase" placeholder="LOGIN"></td>
        </tr>
        <tr>
            <td style="color:white; text-align:right">Mot de passe : </td>
            <td><input type="password" name="mdpNVUser" placeholder="********"></td>
        </tr>
        <tr>
            <td style="color:white; text-align:right">Statut : </td>
            <td>
                <select name="StatutNVCB" id="StatutNVCB">
                    <option value="1">Élève</option>
                    <option value="2">Gestionnaire</option>
                    <option value="4">Prestataire</option>
                </select>
            </td>
        </tr>
        <tr>
            <td colspan="2"><center><input type="submit" name="validerajoutuser" value="Valider"></center></td>
        </tr>
    </table></center>
</form>

</br>
<center><a href="index.php?uc=gestion&action=utilisateurs">Retour</a></center>