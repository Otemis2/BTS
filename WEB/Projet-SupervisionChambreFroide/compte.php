<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<link rel="stylesheet" href="./script/style.css"/>	
		
	</head>
	<div> 
	<?php //les variables :
	require ('./script/fonctions.php');
	$confirm=$_POST["confirm"];
	$newemail=$_POST["email"];
	$mdp=$_POST["password"];
	$confirmMdp=$_POST["confirmPassword"];
	$bdd=connectbdd();//appel la fonction connectbdd
	?>
	</div>
	<?php
	session_start();//démarre une session php
	verif_Connection($_SESSION["email"]);//appel la fonction verif_Connection
	?>
	<body><center>
	<?php
	afficherEntete($_SESSION['rank']);//appel la fonction afficherEntete
	printf("<div class=\"corp\">");
	if($_SESSION['email']!="") //si la Session email n'est pas vide...
	{
		//message de bienvenue :)
		printf ("<br><b>Bienvenue dans votre espace utilisateur :</b> %s %s<br>",$_SESSION['prenom'],$_SESSION['nom']);
		printf ("⚠️ Veuillez ne remplir que les informations que vous voulez modifier ⚠️<br><br>
				Votre email actuel est : %s <br>",$_SESSION['email']);
		
		//formulaire
		printf("informations à changer :<br> <form action=\"\" method=\"POST\">");
		printf("<br>Adresse e-mail : <input type=\"email\" name=\"email\" class=\"input\" /><br>");
		printf("<br>Mot de passe : <input type=\"password\" name=\"password\" class=\"input\" id=\"motdepasse\"/>");
		printf("<IMG src=\"./image/oeil.png\" onclick=\"AfficherMdp()\" id=\"oeil\")><br>");
		printf("<br>Confirmer Mot de passe : <input type=\"password\" name=\"confirmPassword\" class=\"input\" />");
		printf("<input name=\"confirm\" type=\"hidden\" value=\"1\">");
		printf("<br><br><input type=\"submit\" value=\"Confirmer modification\" class=\"blueBouton\" /><br>");  
		printf("</from>");

		if($confirm==1)//confirmation des données
		{   
			//Je modifie les données de l'utilisateur et si le champ est laissé vider je reprends les anciennes valeurs
			//je commence par récupérer les infos de l'utilisateur concerné pour ne pas rendre vide les champs non modifier
			$requeteU="SELECT * FROM compte where prenom=\"".$_SESSION["prenom"]."\" && nom=\"".$_SESSION["nom"]."\""; //U pour utilisateur
			//printf($requeteU." : requête qui récup les valeurs de l'utilisateur<br>");//affiche la requête [DEBUG]

			//envoie la requête a la bdd
			$resultatU=mysqli_query ($bdd,$requeteU) or die ("Impossible de créer la requête!");

			while($user=mysqli_fetch_array($resultatU))//je place les valeurs actuelles de l'utilisateurs dans des variables
			{
				$mail=$user["mail"];
				$nom=$user["nom"];
				$prenom=$user["prenom"];
				$password=$user["mdp"];
			}
			//je vérifie les valeurs à modifier et j'initialise les valeurs vide aux valeurs actuelles de l'utilisateur
			if($newemail=="")
			{
				$newemail=$mail;
			}

			if($mdp=="")
			{
				$newMDP=$password;
			}
			else
			{
				if($mdp==$confirmMdp)
				{
					$newMDP=crypt_mdp($mdp,$_SESSION['prenom']);//appel la fonction crypt_mdp

					//crée une requête d'update de l'utilisateur
					$requeteModif="UPDATE compte SET mail=\"".$newemail."\", mdp=\"".$newMDP."\" WHERE nom=\"".$nom."\" && prenom=\"".$prenom."\"";
					//printf($requeteModif);//affiche la requête [DEBUG]

					//envoie la requête a la bdd
					$resultatModif=mysqli_query($bdd,$requeteModif) or die ("échec lors des modifications des informations");
					printf("<p>Les Informations ont bien été mise à jour pour votre compte</p>");
					$_SESSION["email"]=$newemail;
				}
				else{
					printf("Le mot de passe et la confirmation ne corespondent pas.<br>La modification du profil n'a pas pu s'effectuer");
				}
			}	
		}   
		?>
		
		
		</center></div></body>  
		<?php
	}

	afficherFooter();
	$bdd->close();
	?>
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
</html>