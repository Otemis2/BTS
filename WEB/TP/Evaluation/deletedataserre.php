<!DOCTYPE html>
<html>
<head>
      <meta charset="UTF-8">
      <title>Serre horticole- Génération de valeurs</title>
     

</head>

<body>
Génération de valeurs aléatoires des grandeurs, toutes les 15 min pour une journée dans la base de données "DonneesSerre"
<BR>
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