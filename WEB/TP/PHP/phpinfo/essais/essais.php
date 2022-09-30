<html>
<head>
<meta charset ="UTF-8">
<title>Test PHP </title>
</head>
<body>
<br><center><u>Partie 1 :</u></center><br>
<?php
	printf ("bonjour<br>");
	echo "salut<br>";
	echo 1+2*3;
?>
<br><center><u>Partie 2 :</u></center><br>
<?php
// mettons 10 dans $variable
$variable = 10;
// affichons $variable
printf ("Variable= %d <br>",$variable);
echo "<p>";
echo "10" + '5.2';
?>
<br><center><u>Partie 3 :</u></center><br>
<?php
	$_SERVER["HTTP_HOST"]; //affiche l' hôte
	printf ( "Le lien du site hebergé est : <br>%s",$_SERVER["HTTP_HOST"]);
	$_SERVER["SERVER_NAME"]; //le nom relatif du serveur qui exécute le script
	printf ( "<br>Le serveur se nomme : <br>%s",$_SERVER["SERVER_NAME"]);
	$_SERVER["HTTP_REFERER"]; //affiche la provenance de votre visiteur
	printf ( "<br>Le lien de référence est : <br>%s",$_SERVER["HTTP_REFERER"]);
	$_SERVER["DOCUMENT_ROOT"]; // le répertoire racine de l'arborescence des document
	printf ( "<br>le chemin d'adresse est :br> %s",$_SERVER["DOCUMENT_ROOT"]);
	$_SERVER["REMOTE_ADDR"]; //Adresse IP du visiteur
	printf ( "<br>mon adresse IP : <br>%s",$_SERVER["REMOTE_ADDR"]);
?>
<br><center><u>Partie 4 :</u></center><br>
<?php printf ( "<b>Ceci est un script PHP !</b>" ); ?>
<br><center><u>Partie 5 :</u></center><br>
<?php
// l'intérêt du $
for ($i=0; $i<4; $i++)
{
printf (" Number %d <br>\n",
$i );
}
?> 
<p> ci-dessus du HTML</p>
</body>
</html>