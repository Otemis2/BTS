<!DOCTYPE html>
<html>
<head>
      <meta charset="UTF-8">
      <title>Balise Parapente</title>
	  <link rel="stylesheet" href="css.css">
     

</head>

<body >
<font size=+4><p>Suppression des données</p></font>
<button onclick="window.location.href='./indexdatabalise.html'"></button>
<BR>
<?php

$host = "";
$bdd = "";
$user = "";
$password = "";

$base=mysqli_connect($host, $user, $password,$bdd) or die("erreur de connexion au serveur");

$requete="TRUNCATE TABLE `BaliseParapente`";
printf("<BR>Requete : %s",$requete);
$sql = $base->query($requete);
$base->close();
?>
</body>
</html>