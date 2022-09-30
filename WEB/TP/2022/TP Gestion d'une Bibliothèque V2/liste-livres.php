<html>
<head>
<title>Liste des Livres</title><!-- Titre de la page -->
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<link href="HUCK_styleFormulaire.css" rel="stylesheet">
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
	
	$requete = "SELECT * FROM livres WHERE 1;";//Requete qui selectionnent tout dans la table livre
	printf("Requete SQL : ".$requete);//Affiche la requete
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
	printf("<br><table border=\"1\">");//Crée un tableau
	printf(" <td>ReferenceLivres</td><td>CodeLivre</td><td>NumInventaire</td><td>Titre</td><td>Auteur</td><td>Editeur</td>");//Affiche l'entete du tableaux
	while($tab = mysqli_fetch_array($resulte))//met le resultat sous forme de tableaux
	{
		printf("<tr>");
		printf (" <td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td>",$tab['ReferenceLivres'],$tab['CodeLivre'],$tab['NumInventaire'],$tab['Titre'],$tab['Auteur'],$tab['Editeur']);	//Affichage des données du stagiaire						   
	
	}
	printf("</table><br>");//balise pour fermer le tableau
	printf("Requete SQL : ".$requete);//Affiche la requete
	
	$deco = mysqli_close($bdd);//Deconnexion de la base	
?>

<br><br><br>
<a href="index.php">retour</a> <!-- Lien pour retourner la page precedente -->
</body>

</html>