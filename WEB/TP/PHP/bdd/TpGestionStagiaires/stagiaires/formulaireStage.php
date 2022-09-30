<!-- Ce formulaire permet de crée un nouveau stage  -->
<html>
<head>
<title>ajoutStage</title>
<!-- <link href="HUCK_styleFormulaire.css" rel="stylesheet"> -->
</head>
<body>

<center>HUCK Sylvain</center><br><br>

<form action="ajoutStage.php" method ="post">

<label for="nom">Nom du stage : </label><input type="text" size ="23" id="nom" name="nom" placeholder="DTS1"><br><br>
<label for="dateDebut">Date de debut du stage/heure : </label><input type="text" size ="20" id="dateDebut" name="dateDebut" placeholder="2021-05-25 08:00:00" ><br><br>
<label for="dateFin">Date de fin du stage  : </label><input type="text" size ="20" id="dateFin" name="dateFin" placeholder="2021-06-27 17:00:00"  ><br><br>


Commentaire :<br><br>
<textarea name="commentaire"
   rows="3" cols="120"></textarea><br><br>
<input type="submit" value="Envoyer">
<input type="reset" value="Annuler">
</form>

<center><a href="./index.php">Page d'acceuil</a></center><br>
</body>
</html>