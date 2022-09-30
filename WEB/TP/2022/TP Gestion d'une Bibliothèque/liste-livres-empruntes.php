<html>
<head>
<title>Livres empruntes</title>
<meta http-equiv="Content-Type" content="text/html; charset=Utf-8">
</head>

<body>


<div align="center"><font size="6">Liste des livre emprunt&eacute;s </font></div>
<br>
HUCK Sylvain
<br><br><br>

<form action="./liste-livres-empruntes.php" method="GET">
N&deg; Inventaire : <input name="numInv" type="text">  Date (yyyy-mm-dd) : <input name="date" type="text">
<input type="submit" value="Rendre">
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
		exit();
	}
	if(!(($numInv=="")&&($date=="")))
	{
		$requete = "UPDATE emprunts, livres SET DateRetour = '".$date."' WHERE livres.NumInventaire ='".$numInv."' AND livres.ReferenceLivres = emprunts.ReferenceLivre";
		$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
		printf("Requete SQL : ".$requete."<br>");
		printf("Requete rendre livre : ".$requete."<br><br><br><br>");
	}
	
	$requete = "SELECT NumInventaire, CodeLivre, Titre, Auteur, Editeur, Nom, Prenom, Classe, DateRetour FROM livres, emprunteurs, emprunts WHERE emprunts.ReferenceLivre = livres.ReferenceLivres AND emprunts.ReferenceEmprunteur = emprunteurs.ReferenceEmprunteurs AND DateRetour=\"0000-00-00\" ORDER BY NumInventaire ASC;";
	$resulte = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Execute la requete
	printf("Requete SQL : ".$requete);
	printf("<br><table border=\"1\">");
	printf(" <td>N° Inventaire</td><td>Code</td><td>Titre</td><td>Auteur</td><td>Editeur</td><td>Nom</td><td>Prénom</td><td>Classe</td>");
	while($tab = mysqli_fetch_array($resulte))//met le resultat sous forme de tableaux
	{
		printf("<tr>");
		printf ("<td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td>",$tab['NumInventaire'],$tab['CodeLivre'],$tab['Titre'],$tab['Auteur'],$tab['Editeur'],$tab['Nom'],$tab['Prenom'],$tab['Classe']);
	
	}
	printf("</table><br>");
	
	$deco = mysqli_close($bdd);//Deconnexion de la base	
?>
<a href="index.php">retour</a> 

</body>

</html>