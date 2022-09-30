<html>
<head>
<title>Stage</title>
<!-- <link href="HUCK_styleFormulaire.css" rel="stylesheet"> -->
</head>
<body>
<center><h1>Liste des Stagiaires</h1></center>
HUCK Sylvain <br><br>
<?php
$Serveur ="";//adresse du serveur php myadmin
$User = "";//Utilisateur (ayant que des droit en lecture
$Password = "";//Mot de passe 
$Bdd = "";//Base de donnée cible
$bdd = mysqli_connect($Serveur,$User,$Password,$Bdd); //Connection a la base de donnée

$Sql = "SELECT * FROM Stages";//Requete sql qui selectione tous dans la table Stages


//recupere les donnée du stagiaire
$resultat = mysqli_query($bdd, $Sql);//Execution de la requete

while($tab = mysqli_fetch_array($resultat))
{
	$DateDebutStage = substr($tab['DateDebutStage'],0,10);//Recupere les 10 premiers characteres du champ 'DateDebutStage'
	$DateFinStage = substr($tab['DateFinStage'],0,10);//Recupere les 10 premiers characteres du champ 'DateFinStage'
	printf("<b>".$tab['NomStage']." : ".$tab['CommentaireStage']." du : ".$DateDebutStage." au : ".$DateFinStage." : </b><br>");//Entete du stage
	$reqSQL = "SELECT `NomStagiaire` , `Prenom` , `Adresse` , `VilleStagiaire` , `TelephoneTravail` FROM `Stagiaires` WHERE `ReferenceStage`=".$tab['ReferenceStage'];//Requete pour afficher le stagiaire en fonction du DTS "n"
	$result = mysqli_query($bdd,$reqSQL);//Exucution de la requete
	while($table = mysqli_fetch_array($result))
{
	printf ("- %s %s %s %s %s<br>",$table['NomStagiaire'],$table['Prenom'],$table['Adresse'],$table['VilleStagiaire'],$table['TelephoneTravail']);	//Affichage des données du stagiaire						   
}
}
$deco = mysqli_close($bdd);//Deconnexion de la base	
?>
<br>
<center><a href="./index.php">Page d'acceuil</a></center><br>
</body>
</html>