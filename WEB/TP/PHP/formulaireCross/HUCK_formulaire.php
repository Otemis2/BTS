<!DOCTYPE html>
<html>
<head>
<title>Formulaire Cross</title>
<link href="HUCK_styleFormulaireCross.css" rel="stylesheet">
</head>
<body>
<form action="HUCK_traitement.php" method ="post">
<label for="nom">Nom : </label><input type="text" id="nom" name="nom"><br>
<label for="prenom">Prénom : </label><input type="text" id="prenom" name="prenom"><br>
<label for="date_de_naissance">Date de naissance: </label>
<?php 
$anneeActuel = date ("Y");

  printf ('<select name= "jour_naissance">'."\n");
  for($i=1; $i<=31; $i++)
  {
    // Affichage de la ligne
    printf ("<option value=" .$i. ">". $i ."</option>");
  }
  printf ("</select>","\n");
  printf ("<select name=\"mois_naissance\">","\n");
  for($i=1; $i<=12; $i++)
  {
    // Affichage de la ligne
    printf ("<option >". $i ."</option>");
  }
  printf ('</select>',"\n");
  printf ('<select name="annee_naissance">',"\n");
  for($i=1960; $i<=$anneeActuel; $i++)
  {
    // Affichage de la ligne
    print ("<option >". $i ."</option>");
  }
  printf ('</select>'."<br>");
?>
<label for="nom">licence : </label><input type="text" id="licence" name="licence"><br>
Vous etes :<br>
<INPUT TYPE="radio" NAME="genre" VALUE="homme">
Un homme 
<INPUT TYPE="radio" NAME="genre" VALUE="femme"> Une femme
<br><br>
<input type="submit" value="Envoyer">
<input type="reset" value="Recommencez">
</form>
<form action="HUCK_tabTrie.php" method ="post">
Voulez vous triez par :
<select name= "Ordre">
	<option value="1" >Ordre alphabétique des noms</option>
	<option value="2">Ordre croissant des dates de naissance</option>
</select>
<br><br>
<input type="submit" value="Envoyer">
</form>

</body>
</html>