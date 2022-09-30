<!DOCTYPE html>
<html>
<head>
      <meta charset="UTF-8">
      <title>Serre horticole- Génération de valeurs</title>
</head>

<body>
Huck Sylvain<br>
	<br>
	<button onclick="window.location.href='./indexserre.php'">retour</button>
	<br>
	<button onclick="window.location.href='./indexdataserre.html'">Formulaire pour générer valeurs</button>
	<br>
	<button onclick="window.location.href='./insertdataserre.php'">Générer valeurs</button>
	<br>
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
</body>