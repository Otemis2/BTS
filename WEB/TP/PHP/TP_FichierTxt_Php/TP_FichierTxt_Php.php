<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<!-- <link href="MonStyle.css" rel="stylesheet" type="text/css"> -->
		<!--<meta http-equiv="Refresh" content="0.1" url="index.html">-->
		<title>
		Cosette
		</title>
	</head>
	<body>
	<center><u>Phrase :</center></u>
		<?php printf("Cosette prit la poupée et la posa doucement à terre avec une sorte de vénération mêlée de désespoir.<br> 
Alors, sans la quitter des yeux, elle joignit les mains, et, ce qui est effrayant à dire dans un enfant de 
cet âge, elle se les tordit; puis, ce que n'avait pu lui arracher aucune des émotions de la journée, ni la course 
dans le bois, ni la pesanteur du seau d'eau, ni la perte de l'argent, ni la vue du martinet, ni même la sombre 
parole qu'elle avait entendu dire à la Thénardier, - elle pleura. <br>
Elle éclata en sanglots.") ?>
	<br>
	<br>
	<center><u>Cosette.php</u></center>
	<br>
		<?php 
			if (file_exists("cosette.txt")==True)
			{
				$contenu = file_get_contents("cosette.txt");
				//$contenu est un string
				printf ( "<h1>Contenu du fichier texte \"cosette.txt\":</h1>");
				printf ($contenu);
			}
			else
			{
				printf ("Le fichier cosette.txt n'existe pas");
			}
		?>	


		<?php 
		//lecture d'un fichier texte :2ème méthode :
		printf ("<p><b>Lecture et affichage du fichier texte \"nemo.txt\" (Utilisation des fonctions fopen(), feof(), fgets() et fclose() :</b></p>");
					
			if (file_exists("nemo.txt")==True)
			{
				$fichier=fopen("nemo.txt","r"); //$fichier est dans la RAM
				//tant que le curseur n'est pas à la fin du fichier
				while (feof($fichier)==False)
				{
					$ligne = fgets($fichier); //lecture de la première ligne
					printf($ligne."<br>");
				}
				fclose($fichier);
				printf("<hr><hr><hr>");
			}
			else
			{
				printf ("Le fichier \"nemo.txt\" n'existe pas");
			}

		?>
		<?php
		//lecture d'un fichier csv et affichage des valeurs dans une 
		?>
	</body>
</html>