<?php
require('fonctions.php');
$bdd=connectbdd();
$requeteChambre= "SELECT id_chambre FROM chambre_froide WHERE 1";
$resultatNb=mysqli_query($bdd,$requeteChambre);
printf("[");
while($tab=mysqli_fetch_array($resultatNb))
{
	$requete = "select json_object(
	'nomChambre',chambre_froide.nom_chambre,
	'id_chambre',releverTemperature.id_chambre,
	'type',chambre_froide.Type,
	'statut',chambre_froide.statut,
    'temperature',releverTemperature.temperature,
    'etatPorte',etatPorte.nomEtatPorte ) as jsontest
    FROM releverTemperature,etatPorte,releverPorte,chambre_froide
    where releverTemperature.id_chambre= ".$tab['id_chambre']."
    AND releverPorte.id_chambre=  ".$tab['id_chambre']."
    AND chambre_froide.id_chambre= ".$tab['id_chambre']."
    AND releverPorte.etatPorte = etatPorte.id_etatPorte 
    ORDER BY id_releverTemperature DESC,id_releverPorte 
    Desc Limit 1;";
    $resultat=mysqli_query($bdd,$requete);
    $ligne = mysqli_fetch_array($resultat);
	if($ligne[0]!= null)
	{
		print($ligne[0].",");
	}
}
printf("{}]");
mysqli_close($bdd);
?>
