<html>
<head>
<title>Ajout livre</title><!-- Titre de la page -->
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
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
		
	$CodeLivre = $_GET["code"];//Recupere les information envoyé 
	$NumInventaire = $_GET["numInv"];//Recupere les information envoyé 
	$Titre = $_GET["titre"];//Recupere les information envoyé 
	$Auteur = $_GET["auteur"];//Recupere les information envoyé 
	$Editeur = $_GET["editeur"];//Recupere les information envoyé 
	
	// Vérification de la connexion
	if (mysqli_connect_errno()) 
	{
		printf("Échec de la connexion : %s\n", mysqli_connect_error());
		exit();//Arrete la lecture de la page
	}
	
	$requete1="SELECT * FROM livres WHERE NumInventaire = '".$_GET['numInv']."';";//Requete pour selectionner toute les infos de la table livre ou le numéro d'inventaire est le meme que celui récuperé
	$select = mysqli_query($bdd, $requete1);//execute la requete
	if(mysqli_num_rows($select)) //vérifie si le numéro d'inventaire existe déjà
	{
		printf("<br>Requete pour vérifier si le numéro d'inventaire existe : ".$requete1."<br><br>");//Affiche la requete
		printf('Le numéro d’inventaire existe déjà !');//Affiche Le numéro d’inventaire existe déjà ! dans la page
		printf("<br><br><a href=\"formu-livre.php\">retour </a>");//affiche un lien pour retourné a la page précedente
		exit();
	}
	$requete = "INSERT INTO livres (CodeLivre, NumInventaire, Titre, Auteur, Editeur) VALUES ('".$CodeLivre."', '".$NumInventaire."', '".$Titre."', '".$Auteur."', '".$Editeur."');";//Requete pour ajouté un livre
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_connect_error());//Execute la requete
	printf("<br>Requete : ".$requete);
	printf("<br><br>Livre ajouté avec succès");//Confirme que le livre est ajouté
?>
<br><br>
<a href="formu-livre.php">retour </a><!-- Lien pour retourner la page precedente -->
</body>

</html>
