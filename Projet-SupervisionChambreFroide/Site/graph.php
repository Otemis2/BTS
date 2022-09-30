

<?php
	
/*------------------------ CREATION du GRAPHIQUE ---------------------------------------------------------------------*/
			/*Import des classes de la bibliothèque pChart qui permettra de dessiner le graphique */
			/*ATTENTION : chez Alwaydata, ce script php est correctement interprété jusqu'à la version 7.0.33. */
			/*Au-delà le script lève des erreurs */		
			
			
					
		require_once ('jpgraph/jpgraph.php');
		require_once ('jpgraph/jpgraph_line.php');
		require_once ('jpgraph/jpgraph_bar.php');
		printf("<center><b>Historique de la chambre : ".$nom_chambre."</b></center>");

		//preparation de la requete qui récupere les valeurs nessecaire a la creation du graphique
		$requeteGraphique="SELECT chambre_froide.id_chambre,nom_chambre,date,heure,temperature from releverTemperature,chambre_froide where date>\"".$dateDebut."\" && date<\"".$dateFin."\" && releverTemperature.id_Chambre=chambre_froide.id_chambre && releverTemperature.id_chambre=".$id_chambre." ORDER BY date ASC,heure ASC";
		//printf("<BR>Requete= %s<BR>",$requeteGraphique);//affiche la requete [DEBUG]
		//envoie de la requete a la bdd
		$resultatG =$bdd->query($requeteGraphique);
		$i=0;//initialise $i à 0

		while($ligne = mysqli_fetch_array($resultatG)) /*tant qu'il existe une ligne dans le tableau de résultat de la requête sql*/
		{
			$i=$i+1;
			// Valeurs de X-axis
			$Heure[]= $ligne["heure"];
			//$Date[]=$ligne["date"];
			$dateH[$i]=$ligne["date"]." ".$ligne["heure"];
			// Valeurs de Y-axis
			$TemperatureChambre[]=$ligne["temperature"];
		}	
						
		
	// Création du Graphique
		$graph = new Graph(800,500); 
	// Réglage de l'Echelle :
	// int = integer scale for the X-axis
	// int = integer scale for the Y-axis
		$graph->SetScale('textlin'); 
	
	// Titre du Graphique :	
		$graph->title->Set('Graphique évolution des temperature'); 
			
	// Etiquettes X-axis 
		$graph->xaxis->SetTickLabels($dateH);
		$graph->xaxis->SetLabelAngle(90);
		//$graph->xaxis->SetPos("min");
			
	// Titre Y-axis 
		$graph->yaxis->title->Set('Temperature chambre'); 
	// Légende Y-axis
		$graph->legend->SetPos(0.5,0.98,'center','bottom');
	
	// Création 1er courbe : Temperature sous abri
		$graphTempA =new LinePlot($TemperatureChambre); 
	// Légende
		$graphTempA ->SetLegend($nom_chambre);

		
	// Ajout des courbes au graphique
		$graph->Add($graphTempA);

			
	// Création de l'image du graphique
		$graph->Stroke("graphique".$nom_chambre.".png");			
			
	//unset permet de reinitialiser une variable
	//reinitialise les variables pour la prochaine chambre
	unset($TemperatureChambre);	
	unset($Heure);
	unset($Date);

	// Affichage de l'image :
				printf("<div id=\"divGraphique\">");
				printf("<center><img src=\"graphique".$nom_chambre.".png\"></center>");
				printf("</div>")
?>			
			







