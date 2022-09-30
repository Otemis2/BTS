<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<!-- <link href="MonStyle.css" rel="stylesheet" type="text/css"> -->
		<!--<meta http-equiv="Refresh" content="0.1" url="index.html">-->
		<title>
		</title>
	</head>
	<body>
	<?php
		$age = $_GET["age"];
		$school = $_GET["ecole"];
		printf ("Vous êtes de l'école %s <br>" ,
		$school);
		printf ("Vous êtes né en %d <br>",(2020-
		$age));
		
		$user = $_GET["user"];
		$pass = $_GET["pass"];
		printf ("Votre identifiant est : " ,
		$user);
		printf ("Votre mot de passe est : ",$pass);
	?>
	</body>
</html>