<html>
<head>
<title>Emprunteurs</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
</head>

<body>
<div align="center"><font size="6">Liste des emprunteurs</font> </div>
<br><br><br>
HUCK Sylvain
<?php
	//Connexion à la base de donnée
	$Serveur ="";//Adresse du "serveur"
	$User = "";//Utilisateur (ayant des droit en Ecriture)
	$Password = "";//Mot de passe 
	$Bdd = "";//Base de donnée cible
	$bdd = mysqli_connect($Serveur,$User,$Password,$Bdd); //Connexion a la Base de donnée cible
	
	// Vérification de la connexion
	if (mysqli_connect_errno()) 
	{
		printf("Échec de la connexion : %s\n", mysqli_connect_error());
		exit();
	}	
	
	$requete = "SELECT Nom, Prenom, Classe FROM emprunteurs WHERE 1 ORDER BY Classe,Nom ASC";//Requete qui comptent combien il y a des stagiaire dans le stage
	printf("<br><br><br><br><br>Requete SQL : ".$requete);
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
	printf("<br><table border=\"1\">");
	printf(" <td>Nom</td><td>Prénom</td><td>Classe</td>");
	while($tab = mysqli_fetch_array($resulte))//met le resultat sous forme de tableaux
	{
		printf("<tr>");
		printf (" <td>%s</td><td>%s</td><td>%s</td>",$tab['Nom'],$tab['Prenom'],$tab['Classe']);	//Affichage des données du stagiaire						   
	
	}
	printf("</table><br><br><br><br><br>");
	
	$deco = mysqli_close($bdd);//Deconnexion de la base	
?>

<a href="index.php">retour</a> 
</body>

</html>