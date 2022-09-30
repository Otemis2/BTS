<html>
<head>
<title>Emprunteurs</title><!-- Titre de la page -->
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<link href="HUCK_styleFormulaire.css" rel="stylesheet">
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
	if (mysqli_connect_errno()) //Verifie si il y a des erreurs 
	{
		printf("Échec de la connexion : %s\n", mysqli_connect_error());
		exit();//arrete la lecture de la page
	}	
	
	$requete = "SELECT Nom, Prenom, Classes.NomClasse FROM emprunteurs,Classes WHERE emprunteurs.Classe=Classes.ReferenceClasses ORDER BY Classe,Nom ASC";//Requete
	printf("<br><br><br><br><br>Requete SQL : ".$requete);//Affiche la requete
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
	printf("<br><table border=\"1\">");//Crée un tableau
	printf(" <td>Nom</td><td>Prénom</td><td>Classe</td>");//Affiche l'entete du tableau
	while($tab = mysqli_fetch_array($resulte))//met le resultat sous forme de tableaux
	{
		printf("<tr>");
		printf (" <td>%s</td><td>%s</td><td>%s</td>",$tab['Nom'],$tab['Prenom'],$tab['NomClasse']);	//Affiche les données dans un tableaux			   
	
	}
	printf("</table><br><br><br><br><br>");//Ferme du tableau
	
	$deco = mysqli_close($bdd);//Deconnexion de la base	
?>

<a href="index.php">retour</a> <!-- Lien pour retourner la page precedente -->
</body>

</html>