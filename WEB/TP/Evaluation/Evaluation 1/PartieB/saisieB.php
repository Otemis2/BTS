<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		 <link href="style.css" rel="stylesheet" type="text/css">
		<!--<meta http-equiv="Refresh" content="0.1" url="index.html">-->
		<title>
		SaisieB
		</title>
	</head>
	<body>
		<center><h1>Calcul du volume d'un parallélépipède rectangle : V = L x l x h</h1></center><br>
		<center><img src="../Image/imageRectangle.png"></center>
		<br><br>
		<b><u>Saisir les dimensions :</u></b>
		<form action="traitementB.php" method ="post">
			<li><label for="Longueur">Longueur : </label><input type="text" id="Longueur" name="Longueur" placeholder="0,00">cm.</li>
			<li><label for="Largeur">Largeur : </label><input type="text" id="Largeur" name="Largeur" placeholder="0,00">cm.</li>
			<li><label for="Hauteur">Hauteur : </label><input type="text" id="Hauteur" name="Hauteur" placeholder="0,00">cm.</li>
		<TT><input type="submit" value="Calculer" /></TT>
	</body>
</html>