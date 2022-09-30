<html>
<head>
<!-- Ce formulaire permet d'ajouter un stagiaire  -->
<title>Formulaire</title>
<link href="HUCK_styleFormulaire.css" rel="stylesheet">
</head>
<body>
<center><h2>Formulaire de Saisie des information des Stagiaires</h2></center>
HUCK Sylvain<br><br>
<form action="ajoutstagiaire.php" method ="post">

<label for="nom">Nom : </label><input type="text" size ="23" id="nom" name="nom">
<select name= "classe">
<?php	

	// Connexion au serveur
	$Serveur ="";//Adresse du "serveur"
	$User = "";//Utilisateur en écriture
	$Password = "";//Mot de passe
	$Bdd = "";//Base de donné a ciblé
	$bdd = mysqli_connect($Serveur,$User,$Password,$Bdd); //Connexion a la base de donné
	
	$requete = "SELECT ReferenceStage,NomStage FROM Stages";//Requete pour le select
	$resultat = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Envoie de la requete a la base de donné ou sinon affiche une erreur 
	while($tab = mysqli_fetch_array($resultat))
	{
		printf("<option value =".$tab['ReferenceStage'].">".$tab['NomStage']."</option>");// met en value la reference du stage (recuperer dans la base de donnée) et met en nom, le nom du stage  recuperer dans la base de donnée) pour l'option du select
	}
	$deco = mysqli_close($bdd);//Deconnexion de la base
	?>
  </select><br><br>
<label for="prenom">Prénom : </label><input type="text" id="prenom" name="prenom"><br><br><!-- input de type text pour le nom  -->
<label for="date_de_naissance">Date de Naissance (2004-03-27) : </label><input type="text" size ="10" id="date_de_naissance" name="date_de_naissance" PATTERN = "[0-9]{4}[-]{1}[0-9]{2}[-]{1}[0-9]{2}"><br><br><!-- input de type text pour la date avec une taille max d'affichage de 10 charactere et une verification simple -->
<label for="adresse">Adresse : </label><input type="text" size ="80" id="adresse" name="adresse"><br><br>
<label for="codePostal">Code Postal : </label><input type="text" size ="5" id="codePostal" name="codePostal" PATTERN = "[0-9]{5}"><br><br>
<label for="ville">Ville : </label><input type="text" size ="40"id="ville" name="ville"><br><br>
<label for="numTelPerso">N° Tel personnel : </label><input type="text" id="numTelPerso" name="numTelPerso"  PATTERN = "[0-9]{10}" >
<label for="numTelPro">N° Tel professionnel : </label><input type="text" id="numTelPro" name="numTelPro" PATTERN = "[0-9]{10}">
<label for="numTelPort">N° Tel Portable : </label><input type="text" id="numTelPort" name="numTelPort" PATTERN = "[0-9]{10}"><br><br>

Commentaire :<br><br>

<textarea name="commentaire" rows="3" cols="120"></textarea><br><br><!-- input de type textarea pour les commentaire -->
<input type="submit" value="Envoyer"><!-- Bouton pour envoyer  -->
<input type="reset" value="Annuler"><!-- Bouton pour recommencer le formulaire   -->
</form>
<br><br>
<center><a href="./index.php">Page d'acceuil</a></center><br>

</body>
</html>