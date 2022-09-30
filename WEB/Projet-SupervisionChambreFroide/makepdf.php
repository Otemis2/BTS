<?php
session_start(); //déclaré en début de fichier

//Récupére les données
$choixValeur=$_POST["choix"];
$dateDebut = $_POST["dateDebut"];
$dateFin = $_POST["dateFin"];
$tabDonnee= $_SESSION['valeur'];
$tabDonnee = mb_convert_encoding($tabDonnee, "cp1252", "UTF-8");

// $typeHistorique=$_POST["typePDF"];
// printf("typeHistorique ".$typeHistorique."<br>");

$historiqueDonnee=$_POST["donnee"];
// printf("historiqueDonnee ".$historiqueDonnee."<br>");

$historiqueGraph=$_POST["graph"];
// printf("historiqueGraph ".$historiqueGraph."<br>");

//Si le type d'historique est
// if($typeHistorique == "donnee"){ $typeHistorique = "donnee";}//donnee
// if($typeHistorique == "graph"){$typeHistorique = "graph";}//graph
// if($typeHistorique == "donneeGraph")//graph
// {
	// $typeHistorique = "donnee";
	// $typeHistorique2 = "graph";
// }

//$enteteTab = array('Nom de la Chambre', 'Date', 'Heure', 'Valeurs');
if ($choixValeur == "alerte")//Si le radio bouton alerte est coché
{
	$enteteTab = array('Type d\'alerte','Date', 'Heure', 'Acquitement','Date d\'acquitement','Heure d\'acquitement');//prepare l'entête du tableau pour l'alerte
}
else //Sinon
{
	if($choixValeur == "temperature")
	{
		$enteteTab = array('Date', 'Heure', 'Température (°C)'); //prepare l'entête du tableau pour la temperature / porte
	}
	if($choixValeur == "porte")
	{
		$enteteTab = array('Date', 'Heure', 'état de la porte'); //prepare l'entête du tableau pour l'état de la porte
	}
	
}

require('./fpdf/fpdf.php');//Appelle la classe fpdf

class PDF extends FPDF //crée une classe enfants de la classe FPDF
{
function Header()//Qui met le titre en gras et en haut
{
    // Police Arial gras 15
    $this->SetFont('Arial','B',15);
    // Décalage
    $this->Cell(50);
    // Titre encadré
	$this->SetDrawColor(0 ,0, 0);
    $this->Cell(90,10,'Supervision de chambres froides',1,0,'C');
    // Saut de ligne
    $this->Ln(15);
}

function tabDonnee($data,$entete)
{
	// En-tête
	$choixValeur=$_POST["choix"];
	$this->SetFillColor(255,0,0);//définie la couleur de remplissage
	$this->SetTextColor(255);//change la couleur du text
	$this->SetDrawColor(128,0,0);//configure la couleur de la cellule
	$this->SetLineWidth(.3);//Crée une ligne
	$this->SetFont('','B');//Configure la police
	// En-tête
	if($choixValeur == "alerte")//Si le radio bouton alerte est coché
	{
		$this->SetFontSize(10);
		$w = array(30,23,23,30,35,35);
		//print_r($w);
	}
	else
	{
		$w = array(30,30,45);
		//print_r($w);
	}
	
	for($i=0;$i<count($entete);$i++)
	{
		$this->Cell($w[$i],7,$entete[$i],1,0,'C',true);//Affiche l'entête du tableau de donnée 
	}
	$this->Ln();//Saut de ligne
	$this->SetFillColor(224,235,255);//redéfinie la couleur de remplissage
	$this->SetTextColor(0);//change la couleur du text
	$this->SetFont('');//fixe la police

	// Données
	$fill = false;
	foreach($data as $row)
	{
		for($i=0;$i<count($entete);$i++)
		{
			// if($row[$i+1] == "fermée")
			// {
				// $row[$i+1] == "fermeture"
			// }
			// if($row[$i+1] == "ouvert")
			// {
				// $row[$i+1] == "ouverture"
			// }
			$this->Cell($w[$i],6,$row[$i+1],'LR',0,'L',$fill);//Affiche l'entête du tableau de donnée 
		}
		
		$this->Ln();
		$fill = !$fill;
	}

	// Trait de terminaison
	$this->Cell(array_sum($w),0,'','T');//Ferme le tableau

}
}

$pdf = new PDF();//Instancie la classe
$pdf->SetFont('Arial','',14);//fixe la police
$pdf->SetSubject("Historique des chambres" , 1);//définit le sujet du document
$pdf->AddPage();//Ajoute une nouvelle page
$pdf->SetAutoPageBreak(1 , 20);

function entetePDF($choixValeur,$dateDebut,$dateFin,$nomChambre)//fonction de l'entête du pdf
{
if($choixValeur =="alerte")
{
ob_start();
?> 

Historique de l'<?php printf($choixValeur); ?> de la chambre <?php printf($nomChambre); ?>

Du : <?php printf($dateDebut);?> au : <?php printf($dateFin);?>
<?php
 $contenu = ob_get_clean();
}
else
{
	ob_start();
?> 

Historique de la <?php printf($choixValeur); ?> de la chambre <?php printf($nomChambre); ?>

Du : <?php printf($dateDebut);?> au : <?php printf($dateFin);?>
<?php
 $contenu = ob_get_clean();
}
 return $contenu;
} 

$i =0;
$axeY = 15;//espacement entre le tableau et le graphique
$long = 200;//longueur du graphique
$haut = 125;//hauteur du graphique
foreach($tabDonnee as $ligne)
{
	$tabTempo[$i] = $ligne;//copie la ligne dans un tableau temporaire
	$i =$i+1;
	if($ligne[0] != $tabDonnee[$i][0])//si le nom de la chambre dans la ligne est différent du nom de la chambre dans le tableau tabDonnee 
	{
		if($tabDonnee[$i][0] != $tabDonnee[$i-1][0])//si le nom de la chambre dans le tableau tabDonnee est différent de la ligne précedente
		{
			if($tabDonnee[$i][0] != "")//si le nom de la chambre dans le tableau tabDonnee différent de rien
			{
				$entete = entetePDF($choixValeur,$dateDebut,$dateFin,$tabDonnee[$i-1][0]);//Récupére de l'entête du pdf
				$pdf->Write(5,$entete);//écrit l'entête du pdf
				$pdf->Ln();//Saut de ligne
				$pdf->Ln();//Saut de ligne
				
				if($historiqueDonnee == "donnee")//Si le type d'historique est donnee Alors
				{
					// $pdf->enteteTableau($enteteTab);//écrit l'entête du tableau dans le pdf
					$pdf->tabDonnee($tabTempo,$enteteTab);//écrit le tableau dans le pdf
				}
				if($historiqueGraph == "graph")//Si le type d'historique est graph Alors
				{
					$Yaxe = $pdf->GetY();//Récupére la valeur de l'axe Y
					$pdf->Image('./graphique'.$tabDonnee[$i-1][0].'.png',0,($Yaxe+$axeY),$long,$haut);//imprime l'image dans la pdf
				}
				$pdf->AddPage();//Ajoute une page
				array_splice($tabTempo, 0, count($tabTempo));//Vide le tableau temporaire
				
			}
			if($tabDonnee[$i][0] == "")//Si le tableau tabDonnee est vide (à la fin du tableau)
			{
				$entete = entetePDF($choixValeur,$dateDebut,$dateFin,$tabDonnee[$i-1][0]);//récupére l'entête de la page
				$pdf->Write(5,$entete);//écrire l'entête de la page
				$pdf->Ln();//Saut de ligne
				$pdf->Ln();//Saut de ligne
				if($historiqueDonnee == "donnee")//Si le type d'historique est donnee Alors
				{
					// $pdf->enteteTableau($enteteTab);//écrit l'entête du tableau dans le pdf
					$pdf->tabDonnee($tabTempo,$enteteTab);//écrit le tableau dans le pdf
				}
				if($historiqueGraph == "graph")//Si le type d'historique est graph Alors
				{
					$Yaxe = $pdf->GetY();//Récupére la valeur de l'axe Y
					$pdf->Image('./graphique'.$tabDonnee[$i-1][0].'.png',0,($Yaxe+$axeY),$long,$haut);//imprime l'image dans la pdf
				}
			}
		
		}

	}
}		
		
$pdf->Output("I" ,"Historique.pdf", 1);
?>