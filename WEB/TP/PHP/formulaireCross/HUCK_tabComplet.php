<html>
	<head>
		<title>	Tableau des inscrit</title>
		<meta charset="UTF-8">
		<link href="HUCK_styleFormulaireCross.css" rel="stylesheet">
	</head>
	<body>
		<?php
		printf ("Voici les participants du cross : <br>"); 
		if (file_exists("inscrit.csv")==true)
		{
			$fichierCsv=fopen("inscrit.csv","r");
			$entete=fgets ($fichierCsv);
			$tab_Ligne=str_getcsv($entete,$delimiter=";");
			$tailleTab=count(file("inscrit.csv"));
			//les valeurs de l'entête du fichier csv sont mises dans un tableau
			
			printf("<table>
				    <tr><th>$tab_Ligne[0]</th>
					<th>$tab_Ligne[1]</th>
					<th>$tab_Ligne[2]</th>
					<th>$tab_Ligne[3]</th>
					<th>$tab_Ligne[4]</th>
					<th>$tab_Ligne[5]</th></tr>");
					
			//$ligne=fgets($fichierCsv);//lecture de la première ligne de données du fichierCsv
			while (feof($fichierCsv)==false)//tant que feof() ne renvoie pas true
			{
				//lecture d'une ligne du fichier csv. $ligne est une chaine de caracteres
				$ligne=fgets($fichierCsv);
				//les valeurs de l'entête du fichier csv sont mises dans le tableau
				$tabLigne=str_getcsv($ligne, $delimiter=";");
				printf("<tr>");
				for ($i=0; $i < 6; $i++)
				{
					printf("<td>$tabLigne[$i]</td>");
				}
				printf ("</tr>");
				
			}
			printf ("</table>\n");
			fclose($fichierCsv);
	
		}
		else
		{
			printf ("Il n'y as pas de d'inscrit");
		}
										
			printf("<br><br><a href=\"HUCK_formulaire.php\">Retourner au formulaire</a>");
	?>
	</body>
</html>