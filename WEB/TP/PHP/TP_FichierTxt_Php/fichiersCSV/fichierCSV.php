<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<!-- <link href="MonStyle.css" rel="stylesheet" type="text/css"> -->
		<!--<meta http-equiv="Refresh" content="0.1" url="index.html">-->
		<title>
			FichierCSV
		</title>
	</head>
	<body>
	<?PHP 
		//lecture d'un fichier CSV
		if (file_exists ("inventaire.csv"))
		{
			$fichierCsv=fopen("inventaire.csv","r");
			while (feof ($fichierCsv)==false);//tant que feof() ne renvoie pas true
			{
				//lecture d'une ligne du fichier csv. $ligne est une chaine de caracteres
				$ligne-fgets($fichierCsv);
				//les valeurs de l'entê^te du fichier csv sont mises dans le tableau
				$tabLignes=str_getcsv($ligne,$delimiter=(";");
				for ($i=0; $i < 5; $i++)
				{
					printf($tabLignes($i)."	";
				}
				printf ("<br>");
			}
			fclose($fichierCsv);
		}
		else
		{
			printf ("Le fichier \"inventaire.csv\" n'existe pas");
		}
	?>
	</body>
</html>