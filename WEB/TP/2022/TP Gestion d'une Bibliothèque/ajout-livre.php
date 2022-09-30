<html>
<head>
<title>Ajout livre</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
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
	
	$CodeLivre = $_GET["code"];
	$NumInventaire = $_GET["numInv"];
	$Titre = $_GET["titre"];
	$Auteur = $_GET["auteur"];
	$Editeur = $_GET["editeur"];
	
	// Vérification de la connexion
	if (mysqli_connect_errno()) 
	{
		printf("Échec de la connexion : %s\n", mysqli_connect_error());
		exit();
	}
	
	$requete1="SELECT * FROM livres WHERE NumInventaire = '".$_GET['numInv']."';";
	$select = mysqli_query($bdd, $requete1);
	if(mysqli_num_rows($select)) 
	{
		printf("<br>Requete pour vérifier si le numéro d'inventaire existe : ".$requete1."<br><br>");
		printf('Le numéro d’inventaire existe déjà !');
		printf("<br><br><a href=\"formu-livre.php\">retour </a>");
		exit();
	}
	$requete = "INSERT INTO livres (CodeLivre, NumInventaire, Titre, Auteur, Editeur) VALUES ('".$CodeLivre."', '".$NumInventaire."', '".$Titre."', '".$Auteur."', '".$Editeur."');";
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_connect_error());//Execute la requete
	printf("<br>Requete : ".$requete);
	printf("<br><br>Livre ajouté avec succès");
?>
<br><br>
<a href="formu-livre.php">retour </a>
</body>

</html>
