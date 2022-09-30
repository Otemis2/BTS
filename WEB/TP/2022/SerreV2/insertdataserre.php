<!DOCTYPE html>
<html>
<head>
      <meta charset="UTF-8">
      <title>Serre horticole- Génération de valeurs</title>
</head>

<body>
HUCK Sylvain<br>
Génération de valeurs aléatoires des grandeurs, toutes les 15 min pour une journée dans la base de données "DonneesSerre"
<BR>
	<button onclick="window.location.href='./indexserre.php'">retour</button>
	<br>
	<button onclick="window.location.href='./indexdataserre.html'">Formulaire pour générer valeurs</button>
	<br>
	<button onclick="window.location.href='./deletedataserre.php'">Suppression des Données</button>
	<br>
<?php

//https://btssnir1.alwaysdata.net/serre/insertdataserre.php

//-----------------------------------Fonction de calcul de rééls aléatoires---------------------------------------------------//
function random_float($min, $max) {
    return random_int($min, $max - 1) + (random_int(0, PHP_INT_MAX - 1) / PHP_INT_MAX );
}
//-----------------------------------PARAMETRES DE CONNEXION A LA BASE DE DONNEES---------------------------------------------------//
$Tempmini= $_GET["tempMin"];
$Tempmax= $_GET["tempMax"];
$Hygromini= $_GET["hygroMin"];
$Hygromax= $_GET["hygroMax"];
$Hummini= $_GET["HumiditeMin"];
$Hummax= $_GET["HumiditeMax"];
$dategeneration= $_GET["date"];;
printf ("Tempmini= %10.1f Tempmax= %10.1f <BR> Hygromini= %10.1f Hygromax= %10.1f <BR> Hummini= %10.1f Hummax= %10.1f <BR>",$Tempmini,$Tempmax,$Hygromini,$Hygromax,$Hummini,$Hummax);
printf("Date = %s<BR>",$dategeneration);
$host = "";
$bdd = "";
$user = "";
$password = "";


// Connexion au serveur
$base=mysqli_connect($host, $user, $password,$bdd) or die("erreur de connexion au serveur");
$sql = $base->query("SET CHARACTER SET utf8");

$annee = date("Y", strtotime($dategeneration));
$mois = date("m", strtotime($dategeneration));
$jour = date("d", strtotime($dategeneration));
$joursem = array('dimanche', 'lundi', 'mardi', 'mercredi', 'jeudi', 'vendredi', 'samedi');
$date = date("w", mktime(0, 0, 0, $mois, $jour, $annee));

// Boucle toutes les heures
for ($H=0;$H<=23;$H++)
{
	// Boucle toutes les 15 min
for($M=0;$M<60;$M=$M+15)
{
	// Valeurs aléatoires de la température de la serre [19.0°C;27.0°C] 
	$temperature=random_float($Tempmini,$Tempmax);
	// Valeurs aléatoires de l'hygrométrie de l'air [75.0%;95.0%] 
	$Hygrometrie=random_float($Hygromini,$Hygromax);
	
	// Valeurs aléatoires de l'humidité de la terre [20.0%;55.0%] 
	$humidite=random_float($Hummini,$Hummax);
	
	$heure=$H.":".$M.":00";
	
	// Requete : INSERT INTO `DonneesSerre` (`Date`, `Heure`, `Jour`, `TemperatureSerre`, `HygrometrieAir`, `HumiditeTerre`) VALUES ( '2021-11-07', '09:30:00', 'DIMANCHE', '22.0', '75.0', '50.0');
	$requete="INSERT INTO `DonneesSerre` (`Date`, `Heure`, `Jour`, `TemperatureSerre`, `HygrometrieAir`, `HumiditeTerre`) VALUES ( '".$dategeneration."', '".$heure."','".$joursem[$date]."','".$temperature."', '".$Hygrometrie."', '".$humidite."');";
	printf("<BR>Requete : %s",$requete);
	$sql =	$base->query($requete);
	
}
}
$base->close();
?>
</body>