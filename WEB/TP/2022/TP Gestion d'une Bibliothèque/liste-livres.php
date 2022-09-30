<html>
<head>
<title>Liste des Livres</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
</head>

<body>
<div align="center"><font size="6">Liste des Livres</font> </div>
<br><br><br>
HUCK Sylvain
<br><br><br>
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
	
	$requete = "SELECT * FROM livres WHERE 1;";//Requete qui comptent combien il y a des stagiaire dans le stage
	printf("Requete SQL : ".$requete);
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
	printf("<br><table border=\"1\">");
	printf(" <td>ReferenceLivres</td><td>CodeLivre</td><td>NumInventaire</td><td>Titre</td><td>Auteur</td><td>Editeur</td>");
	while($tab = mysqli_fetch_array($resulte))//met le resultat sous forme de tableaux
	{
		printf("<tr>");
		printf (" <td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td>",$tab['ReferenceLivres'],$tab['CodeLivre'],$tab['NumInventaire'],$tab['Titre'],$tab['Auteur'],$tab['Editeur']);	//Affichage des données du stagiaire						   
	
	}
	printf("</table><br>");
	printf("Requete SQL : ".$requete);
	
	$deco = mysqli_close($bdd);//Deconnexion de la base	
?>

<br><br><br>
<a href="index.php">retour</a> 
</body>

</html>