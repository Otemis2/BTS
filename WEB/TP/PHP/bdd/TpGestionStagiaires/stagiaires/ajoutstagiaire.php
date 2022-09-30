<html>
<head>
<title>ajoutstagiaire</title>
</head>
<body>

<center>HUCK Sylvain</center><br><br>
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
	
	//Info sur la personne (Nom prenom , etc ...)
	$nom = valid_donnees($_POST["nom"]);//Variable récupérant le nom 
	$prenom = valid_donnees($_POST["prenom"]);//Variable récupérant le prenom
	$DateDeNaissance = valid_donnees($_POST["date_de_naissance"]);//Variable récupérant la date de naissance
	$adresse = valid_donnees($_POST["adresse"]);////Variable récupérant l'adresse
	$codePostal = valid_donnees($_POST["codePostal"]);//Le numero du code postal
	$ville = valid_donnees($_POST["ville"]);//Variable récupérant le nom  de la ville
	$numTelDomi = valid_donnees($_POST["numTelPerso"]);//Variable récupérant le Numero perssonnel
	$numTelPro = valid_donnees($_POST["numTelPro"]);//Variable récupérant le Numero professionnel
	$numTelPort = valid_donnees($_POST["numTelPort"]);//Variable récupérant le Numero portable
	$commentaire = valid_donnees($_POST["commentaire"]);//Variable récupérant le contenu du commentaire
	$choixStages = $_POST["classe"];//Variable récupérant la valeur du select
	
	$nomPrenom = $nom." ".$prenom;//Concatenation du nom et du prenom avec un espace entre;
	$date = date("Y-m-d");//Variable de la date du jour
	
    function valid_donnees($donnees)
	{
        $donnees = trim($donnees); // on vire les espace devant et derrière
        $donnees = stripslashes($donnees); // on vire les '/' et '\'
        $donnees = htmlspecialchars($donnees); // on 'échappe' les caractères HTML comme les balises <script>
        return $donnees;
    }
	
	$requete = "SELECT COUNT(*) FROM `Stagiaires` WHERE `ReferenceStage` =".$choixStages;//Requete qui comptent combien il y a des stagiaire dans le stage
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
	$tab = mysqli_fetch_array($resulte);//met le resultat sous forme de tableaux
	// printf("Nombre de stagiaire dans ce stage : ".$tab['COUNT(*)']."<br>");//affiche le nombre de stagiaire dans le stage cible
	// printf("<BR>Requête SQL apres 2 : <code>%s   </code><BR>", $requete  //Affiche la requete comme elle est envoyé au SGDB
	
	//verification d'érreur
	$errs = array();
	if ($tab['COUNT(*)'] >= 20 ) { $errs["classe"] = "Vous pouvez plus ajouter de stagiaire";}//Verifie les donnée
	if (!preg_match("#^[A-Za-z '-]+$#",$nom)) { $errs["nom"] = "Le format du nom n'est pas correct";}//Verifie les donnée du nom
	if (!preg_match("#^[A-Za-z '-]+$#",$prenom)) { $errs["prenom"] = "Le format du prénom n'est pas correct"; }//Verifie les donnée du prenom
	
	// si le erreur sont supérieur à 0 alors faire
	if (count($errs) > 0) 
	{
		printf ("<ul>");
		foreach ($errs as $champEnErreur => $erreursDuChamp) 
		{
			printf ("<li>".$champEnErreur." : ".$erreursDuChamp."</li>");//Affiche l'erreur
		}
    
		printf ("</ul>");
	}
	else
	{
		
	 // Insertion dans la base de donnée

	  $query = "INSERT INTO `Stagiaires`(
		NomStagiaire,
		Prenom,
		ReferenceStage,
		DateNaissance,
		Adresse,
		CodePostal,
		VilleStagiaire,
		TelephoneDomicile,
		TelephoneTravail,
		TelephonePortable,
		CommentairesStagiaire,
		DateCreationFicheStagiaire
	  )
	  VALUES(
		'$nom',
		'$prenom',
		'$choixStages',
		'$DateDeNaissance',
		'$adresse',
		'$codePostal',
		'$ville',
		'$numTelDomi',
		'$numTelPro',
		'$numTelPort',
		'$commentaire','$date')";//Requete permettant d'inseré les donnée récupéré dans le formulaire dans la base de donnée

	  // printf("<BR>Requête SQL : <code>%s</code><BR>", $query);
	  $result = mysqli_query($bdd,$query) or die (mysqli_error($bdd));//Execute la requete
  
		printf("Le Stagiaires ".$nomPrenom." a été ajouté à la Base avec succés");//Affiche un message  de confirmation avec le nom et prenom du stagiaire
	}
$deco = mysqli_close($bdd);//Deconnexion de la base	
?>
<center><a href="./formulaire.php">Retour</a></center><br>
</body>
</html>