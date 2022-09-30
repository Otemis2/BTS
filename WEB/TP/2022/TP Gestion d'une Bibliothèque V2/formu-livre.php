<html>
	<head>
		<title>Formulaire Livre</title><!-- Titre de la page -->
		<meta http-equiv="Content-Type" content="text/html"; charset="UTF-8" />
		<link href="HUCK_styleFormulaire.css" rel="stylesheet">
	</head>

	<body>
		<div align="center"><font size="5">Formulaire - Livres </font></div>
		<center>
			<br><br><br>
			HUCK Sylvain
			<br><br><br>
			<form action="./ajout-livre.php" method="GET" required="required"><!-- Zone de saisie de type text -->
				Code : <input type="text" name="code" pattern="[a-z][A-Z][1-9]"required="required"><!-- Zone de saisie de type text -->
				<!-- required permet de forcer l'utilisateur à saisir les champ pour valider le formulaire -->
				<br><br>
				N&deg; d'inventaire : <input type="number" name="numInv" pattern="[1-9]"required="required"><!-- Zone de saisie de type text -->
				<!-- required permet de forcer l'utilisateur à saisir les champ pour valider le formulaire -->
				<br><br>
				Titre : <input type="text" name="titre"required="required"><!-- Zone de saisie de type text -->
				<!-- required permet de forcer l'utilisateur à saisir les champ pour valider le formulaire -->
				<br><br>
				Auteur(s) : <input type="text" name="auteur"required="required"><!-- Zone de saisie de type text -->
				<!-- required permet de forcer l'utilisateur à saisir les champ pour valider le formulaire -->
				<br><br>
				Editeur : <input type="text" name="editeur"required="required"><!-- Zone de saisie de type text -->
				<!-- required permet de forcer l'utilisateur à saisir les champ pour valider le formulaire -->
				<br><br><br>
				<div align="center"><input type="submit" value="Ajouter"></div>
			</form>

			<br><br><br>
			<a href="index.php">retour </a> <!-- lien pour retourner a la page precendente -->
		</center>
	</body>
</html>