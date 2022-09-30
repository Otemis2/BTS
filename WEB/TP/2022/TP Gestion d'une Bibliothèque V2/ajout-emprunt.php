<html>
<head>
<title>Emprunter</title><!-- Titre de la page -->
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<link href="HUCK_styleFormulaire.css" rel="stylesheet">
</head>

<body>
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
		
	$ReferenceEmprunteur = $_GET["ReferenceEmprunteurs"];//récupére les valeurs envoyé depuis le formulaire
	$ReferenceLivre = $_GET["numInv"];
	$DateEmprunt = $_GET["date"];
	$DateDeRetour = "0000-00-00";//met par défaut la date de retour a 0000-00-00
	
	// Vérification de la connexion
	if (mysqli_connect_errno()) 
	{
		printf("Échec de la connexion : %s\n", mysqli_connect_error());
		exit();//Arrete la lecture de la page
	}

	$requete = "INSERT INTO emprunts (ReferenceEmprunteur, ReferenceLivre, DateEmprunt, DateRetour) VALUES ('".$ReferenceEmprunteur."','".$ReferenceLivre."','".$DateEmprunt."','".$DateDeRetour."');";
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
		
	printf("Requete : ".$requete);//Affiche la requete
	printf("<br><br>Emprunt effectué avec succès");//Confirme à l'utilisateur que l'emprunt a été fait
	
?>
<br><br>
<a href="emprunts.php">retour </a><!-- Lien pour retourner la page precedente -->

</body>
</html>
