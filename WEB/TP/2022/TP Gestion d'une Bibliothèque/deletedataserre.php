<!DOCTYPE html>
<html>
<head>
      <meta charset="UTF-8">
      <title>Serre horticole- Génération de valeurs</title>
     

</head>

<body>
<?php
//-----------------------------------PARAMETRES DE CONNEXION A LA BASE DE DONNEES---------------------------------------------------//
$host = "";
$bdd = "";
$user = "";
$password = "";

// Connexion au serveur
$base=mysqli_connect($host, $user, $password,$bdd) or die("erreur de connexion au serveur");
$requete="TRUNCATE TABLE `DonneesSerre`";
printf("<BR>Requete : %s",$requete);
$sql =	$base->query($requete);
$base->close();
?>

	<br>
	<li><u><a href="./indexserre.php">indexserre.php:</a></u></li>
	<br>
	<br>
	<li><u><a href="./insertdataserre.html">insertdataserre.html :</a></u></li>
	<br>
	<br>
	<li><u><a href="./insertdataserre.php">insertdataserre.php :</a></u></li>
	<br>
</body>