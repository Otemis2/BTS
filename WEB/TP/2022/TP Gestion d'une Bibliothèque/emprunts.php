<html>
<head>
<title>Emprunter livre</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
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
		exit();
	}
	
	$requeteListe = "SELECT numInventaire, ReferenceLivres FROM livres;";//Requete qui comptent combien il y a des stagiaire dans le stage
	$resulteListe = mysqli_query($bdd,$requeteListe) or die (mysqli_error($bdd));//Execute la requete

	$requeteLEmprunteur = "SELECT ReferenceEmprunteurs, Nom, Prenom, Classe FROM emprunteurs;";//Requete qui comptent combien il y a des stagiaire dans le stage
	$resulteLEmprunteur = mysqli_query($bdd,$requeteLEmprunteur) or die (mysqli_error($bdd));//Execute la requete

	printf("<br><br><br>Requete pour la liste des livres : ".$requeteListe);
	printf("<br>Requete pour la Liste des Emprunteurs : ".$requeteLEmprunteur."<br><br>");
?>

<form action="./ajout-emprunt.php" method="GET">
N&deg; Inventaire : 	<select name="numInv">
						<?php
							while($tab = mysqli_fetch_array($resulteListe))
							{
								printf("<OPTION VALUE=".$tab['ReferenceLivres'].">".$tab['numInventaire']);
							}
						?>
				        </select>
				
Nom Prenom : 	<select name="ReferenceEmprunteurs">
				<?php
					while($tab = mysqli_fetch_array($resulteLEmprunteur))
					{
						printf("<OPTION VALUE=".$tab['ReferenceEmprunteurs'].">".$tab['Nom']." ".$tab['Prenom']." ".$tab['Classe']);
					}
				?>
				</select>
				
Date d'emprunt (yyyy-mm-dd) : <input name="date" type="text">
<input type="submit" value="Emprunter">

</form>

<?php	
	$deco = mysqli_close($bdd);//Deconnexion de la base	
?>
<br><br><br>

<br><br><br>
<a href="index.php">retour </a>
</body>

</html>