<!DOCTYPE html>
<html>
<head>
      <meta charset="UTF-8">
	  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	  <link rel="stylesheet" href="css.css">
      <title>Balise Parapente</title>
     

</head>

<body >
    <script src="./justgage/raphael-2.1.4.min.js"></script>
    <script src="./justgage/justgage.js"></script>
<CENTER>
<font  size=+4>BALISE PARAPENTE</font>
</CENTER>
<BR>
<button onclick="window.location.href='./indexdatabalise.html'">Formulaire</button>
<button onclick="window.location.href='../../index.html'">Retour à la sélection</button>
<!--
     <div id="gauge" class="200x160px"></div>
	<script>
      // var g = new JustGage({
        // id: "gauge",
        // value: 67,
        // min: 0,
        // max: 100,
        // title: "Visitors"
      // });
     </script> -->
<?php
function direction($directionVent)
{
	if($directionVent == "Nord"){$image = "<img src='./image/north-symbol.png' class=\"imageDirection\" >";}
	if($directionVent == "Nord-Est"){$image = "<img src='./image/north-east-symbol.png'class=\"imageDirection\" >";}
	if($directionVent == "Est"){$image = "<img src='./image/east-symbol.png' class=\"imageDirection\" >";}
	if($directionVent == "Sud-Est"){$image = "<img src='./image/south-east-symbol.png' class=\"imageDirection\" >";}
	if($directionVent == "Sud"){$image = "<img src='./image/south-symbol.png' class=\"imageDirection\" >";}
	if($directionVent == "Sud-Ouest"){$image = "<img src='./image/south-west-symbol.png' class=\"imageDirection\" >";}
	if($directionVent == "Ouest"){$image = "<img src='./image/west-symbol.png' class=\"imageDirection\" >";}
	if($directionVent == "Nord-Ouest"){$image = "<img src='./image/north-west-symbol.png' class=\"imageDirection\" >";}
	
	return $image;
}

$host = "";
$bdd = "";
$user = "";
$password = "";

	$bdd=mysqli_connect($host, $user, $password,$bdd) or die("erreur de connexion au serveur");
	$requete = "SELECT * FROM BaliseParapente ORDER BY id Desc Limit 1";
	$resultat=mysqli_query($bdd,$requete);
	$ligne = mysqli_fetch_array($resultat);

		printf ("<CENTER> Le %s %s à %s </CENTER><BR>",$ligne["jour"],$ligne["date"],$ligne["heure"]);
		
		$tempSousAbrit = $ligne["TempSousAbri"];
		$tempExt = $ligne["TempExterieure"];
		$vitesseVent = $ligne["VitesseVent"];
		$directionVent = $ligne["DirectionVent"];
		$precipitation = $ligne["precipitation"];
		
		// printf($tempSousAbrit." ".$tempExt." ".$vitesseVent." ".$directionVent." ".$precipitation);
		
		printf("<ul class=\"contenaire\">
		<div id=\"TempSousAbrit\" class=\"graph\">
		<script>
		  var g = new JustGage({
			id: \"TempSousAbrit\",
			value: ".$tempSousAbrit.",
			min: -30.0,
			max: 50.0,
			formatNumber: true,
			title: \"Température Sous Abri\",
			symbol: '°C',
			
			levelColors: [\"#0c00ff\", \"#0013ff\", \"#0000ff\"],
			titleFontColor: \"blue\",
            titleFontFamily: \"blue\",

            valueFontColor: \"blue\",
            valueFontFamily: \"blue\",
		  });
		</script>
		</div>
		<div id=\"TempExt\" class=\"graph\">
		<script>
		  var g = new JustGage({
			id: \"TempExt\",
			value: ".$tempExt.",
			min: -30.0,
			max: 50.0,
			formatNumber: true,
			title: \"Température Extérieure\",
			symbol: '°C',
			
			levelColors: [\"#ea0000\", \"#f10606\", \"#ff0000\"],
			titleFontColor: \"red\",
            titleFontFamily: \"red\",

            valueFontColor: \"red\",
            valueFontFamily: \"red\",
		  });
		</script>
		</div > <div id=\"VitVent\" class=\"graph\">
		<script>
		  var g = new JustGage({
			id: \"VitVent\",
			value: ".$vitesseVent.",
			min: 0.0,
			max: 500.0,
			formatNumber: true,
			title: \"Vitesse du Vent\",
			symbol: 'km/h',
			
			levelColors: [\"#ea0000\", \"#f10606\", \"#ff0000\"],
			titleFontColor: \"red\",
            titleFontFamily: \"red\",

            valueFontColor: \"red\",
            valueFontFamily: \"red\",
		  });
		</script>
		</div >
		<div id=\"precipi\" class=\"graph\">
		<script>
		  var g = new JustGage({
			id: \"precipi\",
			value: ".$precipitation.",
			min: 0.0,
			max: 200.0,
			formatNumber: true,
			title: \"Précipitation\",
			symbol: 'mm',

			color : '#1fff00',
			levelColors: [\"#1be200\", \"#20ed04\", \"#1fff00\"],
			titleFontColor: \"green\",
            titleFontFamily: \"green\",
			
            valueFontColor: \"green\",
            valueFontFamily: \"green\",
		  });
		</script>
		</div>
		<div class=\"graph\"><center>Direction du Vent : ".direction($directionVent)."</center></div>");
		printf("</ul><BR><BR>");
		
		
        
		$queryTemp="SELECT * FROM BaliseParapente WHERE 1 ORDER BY date,heure ASC LIMIT 96;";
		//printf("<BR>Requete= %s<BR>",$queryTemp);
		$resultat =	$bdd->query($queryTemp);
				
		require_once ('jpgraph/jpgraph.php');
		require_once ('jpgraph/jpgraph_line.php');
		require_once ('jpgraph/jpgraph_plotline.php');
		require_once ('jpgraph/jpgraph_bar.php');

		while($ligne = mysqli_fetch_array($resultat)) 
		{
			// Valeurs de X-axis
			$Heure[]= $ligne["heure"];
			// Valeurs de Y-axis
			$TempSAbri[]=$ligne["TempSousAbri"];
			$TempEx[]=$ligne["TempExterieure"];
			$SpeedWind[]=$ligne["VitesseVent"];
			$preccipitation[]=$ligne["precipitation"];

		}		
	
		// Création du Graphique
		$graph = new Graph(1200,800); 
		// Réglage de l'Echelle :
		// int = integer scale for the X-axis
		// int = integer scale for the Y-axis
		$graph->SetScale('textlin'); 

		// Titre du Graphique :	
		$graph->title->Set('Données BALISE PARAPENTE'); 
		
		// Etiquettes X-axis 
		$graph->xaxis->SetTickLabels($Heure);
		$graph->xaxis->SetLabelAngle(60);
		$graph->xaxis->SetPos("min");
		
		// Titre Y-axis 
		$graph->yaxis->title->Set('Température Sous Abri(°C) / Température Extérieure(°C) / Vitesse du vent (km/h) / Précipitation (mm) '); 
		// Légende Y-axis
		$graph->legend->SetPos(0.5,0.98,'center','bottom');

		// Création 1er courbe : Température Sous Abri
		$graphTempSA=new LinePlot($TempSAbri); 
		// Légende
		$graphTempSA->SetLegend("Température Sous Abri °C");
		
		// Création 2ème courbe : Température Extérieure
		$graphTempEX=new LinePlot($TempEx);
		// Légende
		$graphTempEX->SetLegend("Température Extérieure °C");			
		
		// Création 3ème courbe : Vitesse du vent
		$graphSpeedWind=new LinePlot($SpeedWind); 
		// Légende
		$graphSpeedWind->SetLegend("Vitesse du vent km/h");

		// Création 4ème courbe : Précipitation
		$graphPrecipi=new LinePlot($preccipitation); 
		// Légende
		$graphPrecipi->SetLegend("Précipitation mm");
		
		// Ajout des courbes au graphique
		$graph->Add($graphTempSA);
		$graph->Add($graphTempEX);	
		$graph->Add($graphSpeedWind);
		$graph->Add($graphPrecipi);

		$graphTempSA->SetColor("red");
		$graphTempEX->SetColor("pink");
		$graphSpeedWind->SetColor("gray");
		$graphPrecipi->SetColor("green");
		
		// Création de l'image du graphique
		$graph->Stroke("graphique.png");			
			
		// Déconnexion de la BDD
		$bdd->close();

		printf("<div id=\"divGraphique\">");
		printf("<center><img src=\"graphique.png\"></center>");
		printf("</div>");		
	?>			
			
</body>