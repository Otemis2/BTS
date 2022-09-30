<html>
<head>
<title>Livres empruntes</title><!-- Titre de la page -->
<meta http-equiv="Content-Type" content="text/html; charset=Utf-8">
<link href="HUCK_styleFormulaire.css" rel="stylesheet">
</head>

<body>
<div align="center"><font size="6">Liste des livre emprunt&eacute;s </font></div>
<br>
HUCK Sylvain
<br><br><br>

<form action="./liste-livres-empruntes.php" method="GET"><!-- crée un formulaire qui redirigera la page et les infos dans la meme page -->
N&deg; Inventaire : <input name="numInv" type="number" pattern="[1-9]"required="required">  Date (yyyy-mm-dd) : <input name="date" type="date"required="required"><!-- Zone de saisi de type number et date -->
<!-- required permet de forcer l'utilisateur à saisir les champ pour valider le formulaire -->
<input type="submit" value="Rendre"><!-- Bouton pour envoyer les informations -->
<br><br><br><br>
</form>
<?php
	$numInv = $_GET["numInv"];//Variable récupérant le numéro inventaire 
	$date = $_GET["date"];//Variable récupérant la date
	
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
		exit();//arrete la lecture de la page
	}
	if(!(($numInv=="")&&($date=="")))//si le numero d'inventaire et la date est different de rien alors faire
	{
		$requete = "UPDATE emprunts, livres SET DateRetour = '".$date."' WHERE livres.NumInventaire ='".$numInv."' AND livres.ReferenceLivres = emprunts.ReferenceLivre";// Requete sql pour mettre à jour le statut du livre qui vient d'etre emprunté en foction de ReferenceLivre
		$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
		printf("Requete SQL : ".$requete."<br>");//Affiche la requete
		printf("Requete rendre livre : ".$requete."<br><br><br><br>");//Affiche la requete
	}
	
	$requete = "SELECT NumInventaire, CodeLivre, Titre, Auteur, Editeur, Nom, Prenom, Classes.NomClasse, DateRetour FROM livres, emprunteurs, emprunts,Classes WHERE emprunts.ReferenceLivre = livres.ReferenceLivres AND emprunts.ReferenceEmprunteur = emprunteurs.ReferenceEmprunteurs AND DateRetour=\"0000-00-00\" AND emprunteurs.Classe=Classes.ReferenceClasses ORDER BY NumInventaire ASC;";//Requete pour afficher toute les information sur l'élève et sur le livre des livres emprunté
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
	printf("Requete SQL : ".$requete);//Affiche la requete
	printf("<br><table border=\"1\">");//Crée le tableau avec une bordure de 1
	printf(" <td>N° Inventaire</td><td>Code</td><td>Titre</td><td>Auteur</td><td>Editeur</td><td>Nom</td><td>Prénom</td><td>Classe</td>");//Affiche l'entete du tableau
	while($tab = mysqli_fetch_array($resulte))//met le resultat sous forme de tableaux
	{
		printf("<tr>");
		printf ("<td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td>",$tab['NumInventaire'],$tab['CodeLivre'],$tab['Titre'],$tab['Auteur'],$tab['Editeur'],$tab['Nom'],$tab['Prenom'],$tab['NomClasse']);//Affiche le contenu de la requete dans les cases
	
	}
	printf("</table><br>");//ferme le tableau
	
	$deco = mysqli_close($bdd);//Deconnexion de la base	
?>
<a href="index.php">retour</a> <!-- Lien pour retourner la page precedente -->

</body>

</html>