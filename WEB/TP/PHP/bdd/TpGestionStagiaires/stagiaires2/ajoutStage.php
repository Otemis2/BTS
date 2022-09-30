<html>
<head>
<title>ajoutStage</title>
<link href="HUCK_styleFormulaire.css" rel="stylesheet">
</head>
<body>

<center>HUCK Sylvain</center><br><br>

<?php
	//Info sur la personne (Nom prenom , etc ...)Recuperation des donnée
	$nomStage = valid_donnees($_POST["nom"]);
	$dateDebut = valid_donnees($_POST["dateDebut"]);
	$dateFin = valid_donnees($_POST["dateFin"]);
	$commentaire = valid_donnees($_POST["commentaire"]);
	
    function valid_donnees($donnees){
        $donnees = trim($donnees); // on vire les espace devant et derrière
        $donnees = stripslashes($donnees); // on vire les '/' et '\'
        $donnees = htmlspecialchars($donnees); // on 'échappe' les caractères HTML comme les balises <script>
        return $donnees;
    }
	
	//verification d'érreur
	$errs = array();
	if (!preg_match("#^[A-Za-z1-9 '-]+$#",$nomStage)) { $errs["nom"] = "Le format du nom n'est pas correct";}
	
	// si le erreur sont supérieur à 0 alors faire
	if (count($errs) > 0) 
	{
		printf ("<ul>");
		foreach ($errs as $champEnErreur => $erreursDuChamp) 
		{
			printf ("<li>".$champEnErreur." : ".$erreursDuChamp."</li>");
		}
    
		printf ("</ul>");
	}
	else
	{
		$Serveur ="";//Adresse du serveur
		$User = "";//Id avec des droits en écritures
		$Password = "";//Mot de passe
		$Bdd = "";//Base de donnée cible
		$bdd = mysqli_connect($Serveur,$User,$Password,$Bdd); //Connexion a la Base de donnée cible
		
		// Vérification de la connexion
		if (mysqli_connect_errno()) 
		{
			printf("Échec de la connexion : %s\n", mysqli_connect_error());
			exit();
		}


	 // Insertion dans la base de donnée
	  $requete = "INSERT INTO `Stages`(`NomStage`, `DateDebutStage`, `DateFinStage`, `CommentaireStage`) VALUES ('$nomStage','$dateDebut','$dateFin','$commentaire')";//Requete permettant d'inserré les valeurs récupéré du formulaire dans la base de donné

	  // printf("<BR>Requête SQL : <code>%s</code><BR>", $query);
	 
	  $result = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));
  
		printf("<center>Le Stage ".$nomStage." a été ajouté à la Base avec succés</center>");//Affiche un confimation du stage 
	}
	$deco = mysqli_close($bdd);//Deconnexion de la base	
?>
<center><a href="./index.php">Page d'acceuil</a></center><br>
</body>
</html>