
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
		<link rel="stylesheet" href="./script/style.css"/>
		<?php
		require ('./script/fonctions.php');
		session_start(); // appel la fonction php Session
		?>
	</head>

	<body>
	<?php
	afficherEntete(); //affiche l'entete
	?>

	<form method="post" action="./script/login.php">
		<center>
		<br><br>
		<text class="bienvenue">Bienvenue</text>
		<br><br>
			<div class="tab-center">
				Email :<input type="text" name="email" class="input" required /><br>
				Mot de passe :<input type="password" name="mdp" class="input" id="motdepasse" placeholder="****" maxlength="255" required />
				<IMG src="./image/oeil.png" onclick="AfficherMdp()" id="oeil")>
				<br><br>
				<input type="submit" value="Se Connecter !" class="blueBouton"/></td></tr>
			</div>
		</center>
	</form>
	<script>
		function AfficherMdp()
		{ 
			var input = document.getElementById("motdepasse");
			var img= document.getElementById("oeil")
			if (input.type === "password")
			{ 
				input.type = "text";
				img.src ="./image/oeilClose.png";
			} 
			else
			{ 
				input.type = "password";
				img.src ="./image/oeil.png";
			} 
		} 
	</script>
	</body>
	<?php
	afficherFooter();//fonction qui affiche le footer
	?>
</html>