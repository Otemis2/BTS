<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<link href="fichierCSV.css" rel="stylesheet" type="text/css"> 
		<!--<meta http-equiv="Refresh" content="0.1" url="index.html">-->
		<title>
			FichierCSV
		</title>
	</head>
	<body>
	<?PHP 
		//voir documentation  du lanquage php : http://www.php.net/manuel/fr/index.php
		printf("<h1>Affichage des données du dossier \"dossier.Csv\" ");
		//lecture d'un fichier CSV
		if (file_exists("inventaire.csv")==true)
		{
			$fichierCsv=fopen("inventaire.csv","r");
			$entete=fgets ($fichierCsv);
			$tab_Ligne=str_getcsv($entete,$delimiter=";");
			//les valeurs de l'entête du fichier csv sont mises dans un tableau
			
			printf("<table>
				    <tr><th>$tab_Ligne[0]</th>
					<th>$tab_Ligne[1]</th>
					<th>$tab_Ligne[2]</th>
					<th>$tab_Ligne[3]</th>
					<th>$tab_Ligne[4]</th></tr>");
			
			//$ligne=fgets($fichierCsv);//lecture de la première ligne de données du fichierCsv
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
	
		}
		else
		{
			printf ("Le fichier \"inventaire.csv\" n'existe pas");
		}
		//Tableau trié

printf ("<br><br>\n");



		printf("<h1>Affichage des données du  \"dossier.Csv\" trié</h1>\n ");
		if (file_exists("inventaire.csv")==true)
		{
			$fichierCsv=fopen("inventaire.csv","r");
			$entete=fgets ($fichierCsv);
			$tab_Ligne=str_getcsv($entete,$delimiter=";");
			
			printf("<table>
				    <tr><th>$tab_Ligne[0]</th>
					<th>$tab_Ligne[1]</th>
					<th>$tab_Ligne[2]</th>
					<th>$tab_Ligne[3]</th>
					<th>$tab_Ligne[4]</th></tr>");
				
			$tab = array();
			$indice = 0;
			while (feof($fichierCsv)==false)
			{
				$ligne=fgets($fichierCsv);
				$tabLigne=str_getcsv($ligne, $delimiter=";");
				$tab[$indice]=$tabLigne;
				$indice++;
			}
					$nbLigne=count($tab);
				 	for ($i=0; $i <= $nbLigne-1; $i++)
					{
						for ($j=0; $j <= ($nbLigne-1-$i); $j++)
						{
							if ($tab[$j][2]>$tab[$j+1][2])
							{
								$temp = $tab[$j];
								$tab[$j]=$tab[$j+1];
								$tab[$j+1]=$temp;
							}
						}
					}
				for ($i=1; $i < $nbLigne; $i++)
				{
					printf("<tr>");
					for ($j=0;$j < 5; $j++)
					{
					printf("<td>".$tab[$i][$j]."</td>");
					}
					printf ("</tr>");
				}

			printf ("</table>");
			fclose($fichierCsv);
		}
		else
		{
			printf ("Le fichier \"inventaire.csv\" n'existe pas");
		}
	
?>
	</body>
</html>