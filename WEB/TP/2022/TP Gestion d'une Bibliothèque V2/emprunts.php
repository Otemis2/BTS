<html>
<head>
<title>Emprunter livre</title><!-- Titre de la page -->
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<link href="HUCK_styleFormulaire.css" rel="stylesheet">
</head>

<body>
<div align="center"><font size="6">Emprunter un livre </font></div>
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
		exit();//Arrete la lecture de la page
	}
	
	$requeteListe = "SELECT numInventaire, ReferenceLivres FROM livres WHERE ReferenceLivres NOT IN (SELECT ReferenceLivre FROM emprunts WHERE DateRetour=\"0000-00-00\") ORDER BY ReferenceLivres ASC; ";//Requete pour selectionner tous les livres disponibles a l'emprunts
	$resulteListe = mysqli_query($bdd,$requeteListe) or die (mysqli_error($bdd));//Execute la requete

	$requeteLEmprunteur = "SELECT ReferenceEmprunteurs, Nom, Prenom, Classes.NomClasse FROM emprunteurs , Classes WHERE emprunteurs.Classe=Classes.ReferenceClasses;";//Requete
	$resulteLEmprunteur = mysqli_query($bdd,$requeteLEmprunteur) or die (mysqli_error($bdd));//Execute la requete

	printf("<br><br><br>Requete pour la liste des livres : ".$requeteListe);//Affiche la requete pour la liste des livres 
	printf("<br>Requete pour la Liste des Emprunteurs : ".$requeteLEmprunteur."<br><br>");//Affiche la liste des emprunteurs
?>

<form action="./ajout-emprunt.php" method="GET"><!-- crée un formulaire -->
N&deg; Inventaire : 	<select name="numInv" required="required"><!-- ouvre une balise select -->
						<?php
							while($tab = mysqli_fetch_array($resulteListe))
							{
								printf("<OPTION VALUE=".$tab['ReferenceLivres'].">".$tab['numInventaire']);
							}
						?>
				        </select><!-- ferme la balise -->
				
Nom Prenom : 	<select name="ReferenceEmprunteurs"><!-- ouvre une balise select -->
				<?php
					while($tab = mysqli_fetch_array($resulteLEmprunteur))
					{
						printf("<OPTION VALUE=".$tab['ReferenceEmprunteurs'].">".$tab['Nom']." ".$tab['Prenom']." ".$tab['NomClasse']);
					}
				?>
				</select><!-- ferme la balise -->
				
Date d'emprunt (yyyy-mm-dd) : <input type="date" name="date" required="required"><!-- Zone de saisi de type date -->
<!-- required permet de forcer l'utilisateur à saisir les champ pour valider le formulaire -->
<input type="submit" value="Emprunter">

</form><!-- ferme le formulaire-->

<?php	
	$deco = mysqli_close($bdd);//Deconnexion de la base	
?>
<br><br><br>

<br><br><br>
<a href="index.php">retour </a><!-- Lien pour retourner la page precedente -->
</body>

</html>