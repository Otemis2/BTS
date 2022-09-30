<html>
<head>
<title>Traitement Cross</title>
<link href="HUCK_styleFormulaireCross.css" rel="stylesheet">
</head>
<body>

<?php
	//Info sur la personne (Nom prenom , etc ...)

	$nom = valid_donnees($_POST["nom"]);
	$prenom = valid_donnees($_POST["prenom"]);
	$nomPrenom = $nom." ".$prenom;
	$genre =  valid_donnees($_POST["genre"]);
	$licence = valid_donnees($_POST["licence"]);
	
	// Info sur la date de naissance

	$jour_naissance = valid_donnees($_POST["jour_naissance"]);
	$mois_naissance = valid_donnees($_POST["mois_naissance"]);
	$annee_naissance = valid_donnees($_POST["annee_naissance"]);
	
	$jouract    = date('d');
	$moisact    = date('m');
	$anneeact   =  date('Y');

	$dateDeNaissance = $jour_naissance."/".$mois_naissance."/".$annee_naissance;
	// Variable qui permet d'afficher le récapitulatif des données
	$user= "<br>".$nomPrenom."<br>Née le : ".$dateDeNaissance."<br> Vous etes un(e) : ".$genre."<br> Numéro de licence : ".$licence;
	// Variable qui determine la age mini (18)
	$agemini = 18;
	
    function valid_donnees($donnees){
        $donnees = trim($donnees); // on vire les espace devant et derrière
        $donnees = stripslashes($donnees); // on vire les '/' et '\'
        $donnees = htmlspecialchars($donnees); // on 'échappe' les caractères HTML comme les balises <script>
        return $donnees;
    }
	
	//verification d'érreur
	$errs = array();
	if (!preg_match("#^[A-Za-z '-]+$#",$nom)) { $errs["nom"] = "Le format du nom n'est pas correct";}
	if (!preg_match("#^[A-Za-z '-]+$#",$prenom)) { $errs["prenom"] = "Le format du prénom n'est pas correct"; }
	if (!preg_match("#[1-9A-Za-z '-]+$#",$licence)) { $errs["licence"] = "Le format du numéro de licence n'est pas correct"; }
	
	// vérification de l'age 
	printf ("<hr>");
	printf ("Nous somme le : ".$jouract."/".$moisact."/".$anneeact."<br>" );
	printf ($annee_naissance."<br>");
	$age = ($anneeact - $annee_naissance);
	printf ($age."<br>");
	printf ("<hr>");

	if ($age == $agemini )
	{
		if ($mois_naissance > $moisact )
		{
			printf ($age."Mois <br>");
			$age = $age - 1;
			printf ($age."Mois <br>");
		}
		else
		{
			if($mois_naissance == $moisact)
			{
				if ($jour_naissance > $jouract)
				{
					printf ($age."Jour <br>");
					$age = $age - 1;
					printf ($age."Jour <br>");
				}
			}
		}
	}
	if ($age < $agemini ) { $errs["age"] = "Désolé, vous ne pouvez pas inscrire un mineur au cross<br>Vous avez : ".$age;}



	// Fin de vérification

	printf("Voici vos informations : <br>");
	$dossard=count(file("inscrit.csv"));
	printf($user."<br>");
	printf("Votre numéro de dossard: ".$dossard."<br><br>");
	

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
		//Ecriture dans le fichier CSV (ouverture , écriture, fermeture, affichage d'une confimation)
		$fichierCSV = fopen("inscrit.csv","a");
		fwrite($fichierCSV,"\n".$genre.";".$nom.";".$prenom.";".$dateDeNaissance.";".$licence.";".$dossard);
		fclose($fichierCSV);
		printf("Votre inscription est validée");
	}
	
	printf("<br><br><a href=\"HUCK_formulaire.php\">Retourner au formulaire</a>");
	printf("<br><br><a href=\"HUCK_tabComplet.php\">Voir les participants</a>");

?>
</body>
</html>