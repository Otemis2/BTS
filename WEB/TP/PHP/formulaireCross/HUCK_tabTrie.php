<html>
<head>
<title>tabTrie</title>
<link href="HUCK_styleFormulaireCross.css" rel="stylesheet">
</head>
<body>
<?php

$OrdreChoisi = valid_donnees($_POST["Ordre"]);
function valid_donnees($donnees)
	{
        $donnees = trim($donnees); // on vire les espace devant et derrière
        $donnees = stripslashes($donnees); // on vire les '/' et '\'
        $donnees = htmlspecialchars($donnees); // on 'échappe' les caractères HTML comme les balises <script>
        return $donnees;
    }

if (file_exists("inscrit.csv")==true)
{	
	$fichierCsv=fopen("inscrit.csv","r");
	$entete=fgets ($fichierCsv);
	$tab_Ligne=str_getcsv($entete,$delimiter=";");
			
	printf("<table><tr>
			<th>$tab_Ligne[0]</th>
			<th>$tab_Ligne[1]</th>
			<th>$tab_Ligne[2]</th>
			<th>$tab_Ligne[3]</th>
			<th>$tab_Ligne[4]</th>
			<th>$tab_Ligne[5]</th></tr>");

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

	if ($OrdreChoisi==1)
	{
		
		for ($i=0; $i <= $nbLigne-1; $i++)
		{
			for ($j=0; $j <= ($nbLigne-1-$i); $j++)
			{
				if ($tab[$j][1]>$tab[$j+1][1])
				{
					$temp = $tab[$j];
					$tab[$j]=$tab[$j+1];
					$tab[$j+1]=$temp;
				}
			}
		}


				// printf("<tr>");
				// for ($i=0; $i < 6; $i++)
				// {
					// printf("<td>$tabLigne[$i]</td>");
				// }
				// printf ("</tr>");

					// printf ("<tr>");
					
					// for ($j=0; $j < 6; $j++)
					// {
						// printf("<td>$tabLigne[$j]</td>");
					// }
					// printf ("</tr>");
	
	}
	else 
	{

		for ($i=0; $i <= $nbLigne-1; $i++)
		{
			for ($j=0; $j <= ($nbLigne-1-$i); $j++)
			{
				if ($tab[$j][3]>$tab[$j+1][3])
				{
					$temp = $tab[$j];
					$tab[$j]=$tab[$j+1];
					$tab[$j+1]=$temp;
				}
			}
		}		
	}
	
	//affichage du tableau
	for ($i=1; $i < $nbLigne+1; $i++)
	{
		printf("<tr>");
		for ($j=0;$j < 6; $j++)
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
	printf ("Une erreur est survenu lors du traitement de votre requete");
}
?>
</body>
</html>