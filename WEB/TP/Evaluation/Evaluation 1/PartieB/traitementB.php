<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<link href="style.css" rel="stylesheet" type="text/css">
		<!--<meta http-equiv="Refresh" content="0.1" url="index.html">-->
		<title>
		traitementB
		</title>
	</head>
	<body>
		<center><h1>Calcul du volume d'un parallélépipède rectangle : V = L x l x h</h1></center><br>
		<center><img src="../Image/imageRectangle.png"></center>
		<br><br>
	<?php	
		$Longueur = valid_donnees($_POST["Longueur"]);
		$Largeur = valid_donnees($_POST["Largeur"]);
		$Hauteur = valid_donnees($_POST["Hauteur"]);
		$id = count(file("parallelepipede.csv"));
		
		function valid_donnees($donnees){
        $donnees = trim($donnees); // on enleve les espace devant et derrière
        $donnees = stripslashes($donnees); // on enleve les '/' et '\'
        $donnees = htmlspecialchars($donnees); // on 'échappe' les caractères HTML comme les balises <script>
        return $donnees;
    }
		
		printf ("Hauteur : <b> $Hauteur cm</b><br>");
		printf ("Longueur : <b> $Longueur cm</b><br>");
		printf ("Largeur : <b> $Largeur cm</b><br>");
		
		$volume = $Longueur*$Largeur*$Hauteur;
		printf ("<center>Le volume = $Longueur cm x $Largeur cm x $Hauteur cm = <b>$volume cm3</b>.</center><br>");
	
		$data = array($id,$Longueur,$Largeur,$Hauteur,$volume);
	 
		if (file_exists("parallelepipede.csv")==True)
		{
			$fichiercsv = fopen("parallelepipede.csv", "a");
			fputcsv($fichiercsv,$data,$delimiter=";");
			fclose($fichiercsv);
		}
	?>
	<center><a href="./listeB.php"><u>Voir le tableau des dimensions.</u></a></center>
	<center><a href="./saisieB.php"><u>Retour à la page de saisie des dimensions.</u></a></center>
	</body>
</html>