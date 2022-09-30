<!DOCTYPE html>
<html>
<head>
      <meta charset="UTF-8">
      <title>Balise Parapente</title>
	  <link rel="stylesheet" href="css.css">
</head>

<body background="./image/image.jpg" width="100%" height="100%">
<font size=+4>Insertion des données par l'utilisateur dans la Base de Donnée "BaliseParapente"</font>
<BR>
<?php

//-----------------------------------Fonction de calcul de rééls aléatoires---------------------------------------------------//
function random_float($min, $max) {
    return random_int($min, $max - 1) + (random_int(0, PHP_INT_MAX - 1) / PHP_INT_MAX );
}
//-----------------------------------PARAMETRES DE CONNEXION A LA BASE DE DONNEES---------------------------------------------------//
$tempSousAbri= $_GET['tempSousAbri'];
$tempExte= $_GET['tempExte'];
$vitesseVent= $_GET['vitesseVent'];
$directionVent= $_GET['directionVent'];
$precipitation= $_GET['precipitation'];
$date= $_GET['date'];
$heure=$_GET['heure'];
printf ("tempSousAbri= %10.1f <BR> tempExte= %10.1f <BR> vitesseVent= %10.1f <BR> directionVent= %10.1f <BR> precipitation=10.1f<BR>",$tempSousAbri,$tempExte,$vitesseVent,$directionVent,$precipitation);
printf("Date = %s<BR>",$date);
printf("Heure = %s<BR>",$heure);

$host = "";
$bdd = "";
$user = "";
$password = "";

// Connexion au serveur
$bdd=mysqli_connect($host, $user, $password,$bdd) or die("erreur de connexion au serveur");
$sql = $bdd->query("SET CHARACTER SET utf8");

$annee = date("Y", strtotime($date));
$mois = date("m", strtotime($date));
$jour = date("d", strtotime($date));
$joursem = array('dimanche', 'lundi', 'mardi', 'mercredi', 'jeudi', 'vendredi', 'samedi');
$id_jour = date("w", mktime(0, 0, 0, $mois, $jour, $annee));
	
$requete="INSERT INTO BaliseParapente (date, heure, jour, TempSousAbri, TempExterieure, VitesseVent, DirectionVent, precipitation) VALUES ( '".$date."', '".$heure."', '".$joursem[$id_jour]."', '".$tempSousAbri."', '".$tempExte."', '".$vitesseVent."', '".$directionVent."', '".$precipitation."');";
$sql =	$bdd->query($requete);
printf("<BR>Requete : %s",$requete);
	
$bdd->close();
?>
<BR>
<button onclick="window.location.href='./deletedatabalise.php'">Suppression des Données</button>
<button onclick="window.location.href='./indexbalise.php'">Retour à l'accueil</button>
<button onclick="window.location.href='./indexdatabalise.html'">Formulaire</button>
</body>
</html>