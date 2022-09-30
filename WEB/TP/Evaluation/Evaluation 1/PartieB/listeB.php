<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<link href="MonStyle.css" rel="stylesheet" type="text/css">
		<!--<meta http-equiv="Refresh" content="0.1" url="index.html">-->
		<title>
		ListeB
		</title>
	</head>
	<body>
		<center><h1>Affichage de l'ensemble des calculs :</h1></center><br>
		<?php
		$fichierCsv=fopen("parallelepipede.csv","r");
		$entete=fgets ($fichierCsv);
		$tab_Ligne=str_getcsv($entete,$delimiter=";");
		printf("<table>
				    <tr>
					<th>$tab_Ligne[0]</th>
					<th>$tab_Ligne[1]</th>
					<th>$tab_Ligne[2]</th>
					<th>$tab_Ligne[3]</th>
					<th>$tab_Ligne[4]</th></tr>");//affichage de l'entete
		
		while (feof($fichierCsv)==false)//tant que feof() ne renvoie pas true
			{
				//lecture d'une ligne du fichier csv. $ligne est une chaine de caracteres
				$ligne=fgets($fichierCsv);
				//les valeurs de l'entête du fichier csv sont mises dans le tableau
				$tabLigne=str_getcsv($ligne, $delimiter=";");
				printf("<tr>");
				for ($i=0; $i < 5; $i++)
				{
					printf("<td>$tabLigne[$i]</td>");
				}
				printf ("</tr>");
				
			}
			printf ("</table>\n");
			fclose($fichierCsv);
		?>
		<center><a href="./saisieB.php"><u>Retour à la page de saisie des dimensions.</u></a></center>
	</body>
</html>