<html>
<head>
<title>Liste des Stages</title>
<link href="HUCK_styleFormulaire.css" rel="stylesheet">
</head>
<body>
<center><h1>Liste des Stages</h1></center>
HUCK Sylvain <br><br>
<?php
$Serveur ="";//Adresse du "serveur"
$User = "";//Utilisateur (ayant que des droit en lecture)
$Password = "";//Mot de passe 
$Bdd = "";//Base de donnée cible
$bdd = mysqli_connect($Serveur,$User,$Password,$Bdd); //Connection a la base de donnée

$reqSQL = "SELECT * FROM Stages WHERE 1";//Requete qui selection tout de la table Stages
$resultat = mysqli_query($bdd, $reqSQL) or die ("Impossible de joindre le serveur");//Execute la requete ou sinon affiche le message

while($tab = mysqli_fetch_array($resultat))
{
	$DateDebutStage = substr($tab['DateDebutStage'],0,10);//Recupere les 10 premiers characteres du champ 'DateDebutStage'
	$DateFinStage = substr($tab['DateFinStage'],0,10);//Recupere les 10 premiers characteres du champ 'DateFinStage'
	printf ("%s : %s du : %s au : %s<br>",$tab['NomStage'],$tab['CommentaireStage'],$DateDebutStage,$DateFinStage);	//Affiche le nom , commentaire, date de debut et de fin du stage 
	
}
$deco = mysqli_close($bdd);//Deconnexion de la base
?>
<br>
<center><a href="./index.php">Page d'acceuil</a></center><br>
</body>
</html>