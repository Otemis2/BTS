<!DOCTYPE html>
<html>
<head>
	  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
      <title>Serre horticole - Graphique</title>
     

</head>

<body>
<CENTER>
<FONT color="blue" size=+4>
SERRE HORTICOLE
</FONT>
</CENTER>
<BR>
HUCK Sylvain<br>
	<button onclick="window.location.href='./indexdataserre.html'">Formulaire pour générer valeurs</button>
<br>
	<button onclick="window.location.href='./insertdataserre.php'">Générer valeurs</button>
<br>
	<button onclick="window.location.href='./deletedataserre.php'">Suppression des Données</button>
<br>
	
<?php

	// https://btssnir1.alwaysdata.net/serre/indexserre.php

	//-----------------------------------PARAMETRES DE CONNEXION A LA BASE DE DONNEES---------------------------------------------------//
	$host = "";
	$bdd = "";
	$user = "";
	$password = "";

	// Connexion au serveur BDD :
	$base=mysqli_connect($host, $user, $password,$bdd) or die("erreur de connexion au serveur");
	$sql = $base->query("SET CHARACTER SET utf8");

	// Requête d'extration du dernier enregistrement :
	$requete="SELECT * FROM DonneesSerre WHERE 1 ORDER BY ID_DONNEES DESC LIMIT 1";
		//printf("<BR>=%s<BR>",$requete);
	$resultat =	$base->query($requete);
	$ligne = mysqli_fetch_array($resultat);
	// Affichage des valeurs des dernières grandeurs enregistrées :
	printf ("<FONT size=+1><CENTER> Le %s %s à %s <BR>",$ligne["Jour"],$ligne["Date"],$ligne["Heure"]);
	printf("<TABLE border=\"1\" width=1200><TR>");
	printf("<TD align=\"center\"><FONT color=\"blue\" size=+2>Température Intérieure = <B>%10.1f °C</B></FONT></TD>",$ligne["TemperatureSerre"]);
	printf("<TD align=\"center\"><FONT color=\"red\" size=+2>Hygrométrie de l'Air = <B>%10.1f &#37;</B></TD>",$ligne["HygrometrieAir"]);
	printf("<TD align=\"center\"><FONT color=\"green\" size=+2>Humidité de la Terre = <B>%10.1f &#37;</B></TD>",$ligne["HumiditeTerre"]);
	
	printf("</TR></TABLE>");
	printf("</CENTER></FONT><BR>");
	
	/*------------------------ CREATION du GRAPHIQUE ---------------------------------------------------------------------*/
	/*Import des classes de la bibliothèque pChart qui permettra de dessiner le graphique */
	/*ATTENTION : chez Alwaydata, ce script php est correctement interprété jusqu'à la version 7.0.33. */
	/*Au-delà le script lève des erreurs */
			
	// Requete SQl = SELECT `HEURE`,`TemperatureSerre`,`HygrometrieAir`,`HumiditeTerre` FROM `DonneesSerre` WHERE `DATE`="2021-11-07";
	$queryTemp="SELECT Heure,TemperatureSerre,HygrometrieAir,HumiditeTerre FROM DonneesSerre WHERE 1 ORDER BY DATE DESC,HEURE ASC LIMIT 96;";
		//printf("<BR>Requete= %s<BR>",$queryTemp);
	$resultat =	$base->query($queryTemp);
			
	require_once ('jpgraph/jpgraph.php');
	require_once ('jpgraph/jpgraph_line.php');
	require_once ('jpgraph/jpgraph_bar.php');
			
	while($ligne = mysqli_fetch_array($resultat)) /*tant qu'il existe une ligne dans le tableau de résultat de la requête sql*/
		{
			// Valeurs de X-axis
			$Heure[]= $ligne["Heure"];
			// Valeurs de Y-axis
			$Temperature[]=$ligne["TemperatureSerre"];
			$Hygometrie[]=$ligne["HygrometrieAir"];
			$Humidite[]=$ligne["HumiditeTerre"];
		}	
				
		
	// Création du Graphique
		$graph = new Graph(1200,800); 
	// Réglage de l'Echelle :
	// int = integer scale for the X-axis
	// int = integer scale for the Y-axis
		$graph->SetScale('textlin'); 
	
	// Titre du Graphique :	
		$graph->title->Set('Données SERRE HORTICOLE'); 
			
	// Etiquettes X-axis 
		$graph->xaxis->SetTickLabels($Heure);
		$graph->xaxis->SetLabelAngle(60);
		$graph->xaxis->SetPos("min");
			
	// Titre Y-axis 
		$graph->yaxis->title->Set('Température (°C) / Hygrométrie (%) / Humidité (%)'); 
	// Légende Y-axis
		$graph->legend->SetPos(0.5,0.98,'center','bottom');
	
	// Création 1er courbe : Température Intérieure
		$graphTemp=new LinePlot($Temperature); 
		// Légende
		$graphTemp->SetLegend("Température °c");
			
	// Création 2ème courbe : Hygrométrie de l'Air
		$graphHygro=new LinePlot($Hygometrie); 	;
		// Légende
		$graphHygro->SetLegend("Hygrométrie (%)");
			
	// Création 3ème courbe : Humidité de la Terre
		$graphHumidite =new LinePlot($Humidite); 	;
		// Légende
		$graphHumidite->SetLegend("Humidité (%)");			
			
	// Ajout des courbes au graphique
		$graph->Add($graphTemp);
		$graph->Add($graphHygro);	
		$graph->Add($graphHumidite);	
			
	// Création de l'image du graphique
		$graph->Stroke("graphique.png");			
			
	// Déconnexion de la BDD
		$base->close();
		
	// Affichage de l'image :
			?>			
			<div id="divGraphique">
				<center><img src="graphique.png"></center>
			</div>
			
</body>