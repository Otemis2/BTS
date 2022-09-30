<html>
	<head> <!-- Page exclusive a L'admin !! -->
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<link rel="stylesheet" href="./script/style.css"/>
	</head>
	<?php 
	//les variables
	require ('./script/fonctions.php');
	session_start(); 
	
	verif_Connection($_SESSION["email"]); //verifie la connection de l'utilisateur
	verif_admin($_SESSION["rank"]); //verifie si l'utilisateur est un admin
	$bdd=connectbdd();//Appel la fonction qui permet la connection a la base de donnée
	$choix=$_POST["choix"];
	$confirm=$_POST["confirm"];

	//Variable pour modifier utilisateur 
	$email=$_POST["email"];
	$user=$_POST["user"];
	$mdp=$_POST["password"];
	//$password sera mis en place plus tard 
	
	//Variable pour ajouter utilisateur (email et mot de passe serons reutilisé)
	$usernom=$_POST["nom"];
	$prenom=$_POST["prenom"];
	$role=$_POST["role"];
	?>
	<body >
	<?php
	afficherEntete($_SESSION['rank']); //affiche l'entete
    printf("<div class=\"corp\">");
	printf("<h2>Gestion des Utilisateurs</h2>");
		if($_SESSION["rank"]==3) //si l'utilisateur est admin affiche :
		{
			printf("
			<center>
			<p>
			<table> 
				<td>	
					<form action=\"\" method=\"POST\">
					<input type=\"hidden\" name=\"choix\" value=\"1\" >
					<input type=\"submit\" value=\"Modifier un utilisateur\" class=\"blueBouton\">
					</form>
				</td>
				<td>
					<form action=\"\" method=\"POST\">
					<input type=\"hidden\" name=\"choix\" value=\"2\" >
					<input type=\"submit\" value=\"Ajouter un utilisateur\" class=\"blueBouton\">
					</form>
				</td>
				<td>
					<form action=\"\" method=\"POST\">
					<input type=\"hidden\" name=\"choix\" value=\"3\" >
					<input type=\"submit\" value=\"supprimer utilisateur\" id=\"\" class=\"redBouton\">
					</form>
				</td>
			</p>	
			</table>
			");
		}
	?>
	</p>
	<p>
    <text> Tableau des autorisation par rôle</text>
    <table border="2"class="donnee">
        <tr>
            <td>Statut</td>
            <td>Visualiser</td>
            <td>Imprimer un PDF</td>
            <td>Modifier des utilisateurs</td>
            <td>Modifier des chambres</td>
        </tr>
        <tr>
            <td>Chef de service</td>
            <td><center><b>X</b></center></td>
            <td><center><b>X</b></center></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td>Technicien</td>
            <td><center><b>X</b></center></td>
            <td><center><b>X</b></center></td>
            <td><center><b>X</b></center></td>
            <td><center><b>X</b></center></td>
        </tr>
    </table>
    
		<?php
        if ($choix==1)//(choix modifier)
        {
            //recupére toutes les informations des comptes
            $query="Select * from compte";

            //printf($query);//affiche la requête [DEBUG]
            //envoie la requête a la bdd
            $resultat=mysqli_query ($bdd,$query) or die ("Impossible de créer la requête!");
        
            printf("<p><form action=\"\" method=\"POST\">");
            printf ("utilisateur à modifier : <select name=\"user\" class=\"input\">");
            while($tab = mysqli_fetch_array($resultat)) //crée des options au Select pour chaque utilisateur existant
                {
                    printf("<option value=".$tab['mail'].">".$tab['prenom']." ".$tab['nom']."</option>"); 
                }
            printf("</select><p>");
            printf("<p>Adresse e-mail : <input type=\"email\" name=\"email\" class=\"input\" /></p>");
            printf("<p>Mot de passe : <input type=\"text\" name=\"password\" class=\"input\" /></p>");
            printf("<input name=\"choix\" type=\"hidden\" value=\"1\">");
            printf ("<p>Statut de l'utilisateur : <select name=\"role\" class=\"input\" ></p>");
            
            //requête qui récupère les rôles existants
            $roleQuery="SELECT idRole,nomRole FROM role WHERE 1";
            //envoie la requête a la bdd
            $resultatRole=mysqli_query($bdd,$roleQuery);
            
            //tant qu'il y a des rôles existants crée des options au sélection des rôles
            while($rank = mysqli_fetch_array($resultatRole))
                {
                    print("<option value=".$rank['idRole'].">".$rank['nomRole']."</option>");
                }
            printf("</select> <br></p>");
            printf("<input name=\"confirm\" type=\"hidden\" value=\"1\">");
            printf("<input type=\"submit\" value=\"Confirmer modification\" class=\"blueBouton\" /><br>");  
            printf("</form>");

            if($confirm==1)//confirmation des données
            {
                //je commence par récupérer les infos de l'utilisateur concerné pour ne pas rendre vide les champs non modifier
                $requeteU="SELECT * FROM compte where mail=\"".$user."\""; //U pour utilisateur
                //printf($requeteU." : requête qui récup les valeurs de l'utilisateur<br>"); //affiche la requête [DEBUG]
                $resultatU=mysqli_query ($bdd,$requeteU) or die ("Impossible de créer la requête!");
                //je récupère les informations actuelles
                while($user=mysqli_fetch_array($resultatU))
                    {
                        $mail=$user["mail"];
                        $nom=$user["nom"];
                        $prenom=$user["prenom"];
                        $password=$user["mdp"];
                        $rank=$user["idRole"];
                    }

                //je vérifie les valeurs à modifier ou pas et j'initialise les valeurs vide aux anciennes valeurs
                if($email=="")
                    {
                        $email=$mail;
                    }
                if($mdp=="") //si le mot de passe est vide je replace l'ancien sinon je crypte le nouveau et l'insère dans la bdd
                {
                    $newMDP=$password;
                }
                else{
                    $newMDP=crypt_mdp($mdp,$prenom);
                }
                if($role=="")
                {
                    $role=$rank;
                }
                //crée la requête de modification de l'utilisateur
                $requeteA="UPDATE compte SET mail=\"".$email."\",mdp=\"".$newMDP."\", idRole=\"".$role."\"  WHERE mail=\"".$mail."\"";
                //printf("requete appliquée à la bdd : ".$requeteA."<br>"); //affiche la requête [DEBUG]
                $resultatAdd=mysqli_query($bdd,$requeteA) or die ("Impossible de creer la requete!");
                printf("L'utilisateur ".$nom." ".$prenom." a bien été modifier");
            }
            else //si la confirmation n'a pas encore été faite, afficher tous les utilisateurs existant dans un tableau afin d'aider à la suppression d'un utilisateur
            {
                //préparation de la requête
                $requeteInform="SELECT nom,prenom,mail FROM compte WHERE 1";
                //application de la requête
                $resultatInform=mysqli_query($bdd,$requeteInform);
                //affichage d'un tableau avec les valeurs nom, prénom, mail
                printf("<br>Tableau des correspondances des adresses mail existante :");
                printf("<div style=\" overflow:auto; width:550px; height:330px; solid;\">");
                printf("<table border=\"4\"class=\"donnee\"><tr><td> Nom </td><td> Prénom </td><td> email </td></tr>");
                while($tab=mysqli_fetch_array($resultatInform))
                {
                    printf("<tr><td>".$tab['nom']."</td><td>".$tab['prenom']."</td><td>".$tab['mail']."</td></tr>");
                }
                printf("</table></div>");
            }
        //printf("<BP> Requête SQL : %s </BP> <br> <br>", $query);  
        }


        if ($choix==2)//choix d'ajouter
        {

            printf("<form action=\"\" method=\"POST\">");
            printf("<p>Nom : <input type=\"text\" name=\"nom\" class=\"input\" required/>");
            printf(" Prenom : <input type=\"text\" name=\"prenom\" class=\"input\" required/></p>");
            printf("<p>Adresse e-mail : <input type=\"email\" name=\"email\" class=\"input\" class=\"input\" required/></p>");
            printf("<p>Mot de passe : <input type=\"text\" name=\"password\" class=\"input\" required/></p>");
            
            printf ("<p>Statut de l'utilisateur : <select name=\"role\" class=\"input\">");
            //requête qui récupère l'id du rôle et le nom du role
            $roleQuery="SELECT idRole,nomRole FROM role WHERE 1";
            //envoie la requête a la bdd
            $resultatRole=mysqli_query($bdd,$roleQuery);
            //tant qu'il y a des rôles existant dans la bdd, on les met en option dans la sélection des rôles
            while($rank = mysqli_fetch_array($resultatRole)) //permet la modification du rôle d'un utilisateur 
                {
                    print("<option value=".$rank['idRole'].">".$rank['nomRole']."</option>");
                }
            printf("</select> </p>");
            printf("<input name=\"choix\" type=\"hidden\" value=\"2\">");
            printf("<input name=\"confirm\" type=\"hidden\" value=\"1\">"); 
            printf("<p><input type=\"submit\" value=\"Ajouter l'utilisateur\" class=\"blueBouton\" /></p>");    
            printf("</form>");
            if ($confirm==1)//si le bouton de confirmation est cliqué
            {   
                if(verif_mail()==true)//si l'email saisie est correct
                {
                    //crypte le mot de passe
                    $newmdp=crypt_mdp($mdp,$prenom);
                    //crée la requête d'ajout du nouvel utilisateur
                    $addRequest="INSERT INTO compte ( mail , mdp , prenom, nom , idRole) VALUES (\"$email\",\"$newmdp\",\"$prenom\",\"$usernom\",\"$role\")";
                    //printf("<br>requête d'ajout : ".$addRequest); //affiche la requête [DEBUG]
                    //envoie la requête a la bdd
                    $resultatadd=mysqli_query($bdd,$addRequest) or die ("Impossible de créer la requête!");
                    printf("<p>L'utilisateur a bien été ajouté.</p>");
                }
                else
                {
                    printf("<p>L'email saisie est déjà associée à un compte enregistrer</p>");
                }   
            }
        }



		if ($choix=="3")//Choix supprimé
		{
			//requête qui recupere tout les informations des comptes
			$query="Select * from compte";
			//envoie la requete a la bdd
			$resultat=mysqli_query ($bdd,$query) or die ("Impossible de creer la requete!");
			printf("<form action=\"\" method=\"POST\">");
			printf ("utilisateur a supprimer : <select name=\"email\" class=\"input\">");
			while($tab = mysqli_fetch_array($resultat)) //affiche toute les adresses mails des utilisateurs present dans la bdd
				{
					printf("<option value=".$tab['mail'].">".$tab['mail']."</option>");
				}
			printf("</select> <br><br>");
			printf("<input name=\"choix\" type=\"hidden\" value=\"3\">");	
			printf("<input name=\"confirm\" type=\"hidden\" value=\"1\">");	
			printf("<input type=\"submit\" value=\"Confirmer suppression\" class=\"redBouton\"/><br>");
			printf("</form>");

			if($confirm=="1")//si on a confirmé la supression d'un utilisateur 
			{
				//preparation de la requete de suppression 
				$Delrequete="DELETE FROM compte WHERE mail=\"".$email."\"";
				//application de la requete de suppression
				$DelResultat=mysqli_query($bdd,$Delrequete) or die("Impossible de creer la requete!");
				printf("L'utilisateur a bien été supprimer, la page va s'actualisée");
				printf(" <meta http-equiv=\"refresh\" content=\"5;\"> ");

			}
			else //si la confirmation n'a pas encore été faite, afficher tout les utilisateurs existant dans un tableau afin d'aider à la suppression d'un utilisateur
			{
				//preparation de la requete
				$requeteInform="SELECT nom,prenom,mail FROM `compte` WHERE 1";
				//application de la requete
				$resultatInform=mysqli_query($bdd,$requeteInform);
				//affichage d'un tableau avec les valeurs nom,prenom,mail
				printf("<br>Tableau des correspondences des adresses mail existante :");
                printf("<div style=\" overflow:auto; width:550px; height:330px; solid;\">");
				printf("<table  border=\"4\"class=\"donnee\"><tr><td> Nom </td><td> Prenom </td><td> email </td></tr>");
				while($tab=mysqli_fetch_array($resultatInform))
				{
					printf("<tr><td>".$tab['nom']."</td><td>".$tab['prenom']."</td><td>".$tab['mail']."</td></tr>");
				}
				printf("</table></div>");
			}
		}
		?>	
	</p>
	</center>
	</div></body>
	<?php
	afficherFooter();
	?>
</html>