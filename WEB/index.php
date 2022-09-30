
<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<link href="MonStyle.css" rel="styleheet" type="text/css">
		<!-- <meta http-equiv="Refresh" content="5" url="index.html"> -->
		<title>
		index.html
		</title>
	</head>
	<body>
		<script type="text/javascript">
			alert("Ha bonjour !! \n Si vous êtes étudiants ou un professionnel, bonne visite ! \n Si vous êtes un professeur du BTS SN-IR à Pierre Mendes France, Vous êtes les meilleurs !!! \nEt pour les profs de licence , Oui ce site est pas beau, merci du compliment , j'attend votre mail avec impatience \n anidem leunamme !!!");
		 </script>
	<b><center>Bonjour, bienvenu sur l'index </center></b>
	<br>
	HUCK Sylvain
	<br><br>
	<i>Hahaha, Un grain de génie pour deux grains de folie,<br>C'est le meilleurs !!!</i>
	<br>
	<br>
		<li><u><a href="./TP/index.html">Tp et Wordpresse :</a></u></li>
		<br>
		<li><u><a href="./CV/index.php">CV :</a></u></li>
		<br>
		<li><u><a href="./Perso/index.html">Perso :</a></u></li>
		<br>
		<li><u><a href="https://projet-chambre-froide.alwaysdata.net/">Projet BTS :</a></u></li>
		<br>Si vous voulez voir, quelque choses d'utile et de plus ou moins jolis Cliquez sur Projet BTS et venez me demandez les identifiants si vous les avez pas déjà !<br>
		@Email : sylvain8810@gmail.com (réponse rapide, merci la notification).
		<br>
		<?php
			function getIp(){
				if(!empty($_SERVER['HTTP_CLIENT_IP'])){
				$ip = $_SERVER['HTTP_CLIENT_IP'];
				}elseif(!empty($_SERVER['HTTP_X_FORWARDED_FOR'])){
				$ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
				}else{
				$ip = $_SERVER['REMOTE_ADDR'];
				}
				return $ip;
			}
			$ip = getIp();
			printf("<br>");
			echo '<br>Votre IP : '.$ip;
			mail(
			"otenefis@gmail.com",
			"Un nouveau visiteur !!!",
			"Son IP : $ip"
			);
		?>
		<script type="text/javascript">
			function lucas()
			{
				document.title = "Lucas URBAIN"; 
			}
			setTimeout(lucas(),30000000);
		</script>
	</body>
</html>