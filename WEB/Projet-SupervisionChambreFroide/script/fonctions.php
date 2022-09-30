<?php
function connectbdd()
{
    //initialisation des logins de la bdd
    $host='mysql-projet-chambre-froide.alwaysdata.net'; //Adresse de la base de données
    $user='253841'; //Utilisateur (ayant des droits en Ecriture) 
    $mdp= 'DSTPROJET2022';//Mot de passe de la base de données 
    $Bdd= "projet-chambre-froide_bdd";  //Base de données cible
    $bdd = mysqli_connect($host,$user,$mdp,$Bdd); //Connexion à la Base de données cible
    return $bdd;
}

function crypt_mdp ($mdp_a_crypte,$sel) //Fonction de cryptage
{
    //printf("sel : ".$sel."<br>");
    $mdp = $mdp_a_crypte.$sel;//combine le mdp de l'utilisateur et le prénom de l'utilisateur pour le cryptage
    $salt = "$6$rounds=7500$".password_hash($mdp,PASSWORD_BCRYPT)."$chambre-froide$";//Clé "Unique" avec constante et un hachage du prénom de l'utilisateur
    $mdp = crypt($mdp,$salt);//cryptage du mdp en fonction du mot de passe et la clé
    return $mdp;//retourne le mots de passe
}

/*
Algorithme mdp_verif()

Var :
	mdp, chaine de carateres
	mdp_confirmation , chaine de caracteres
	mdp verif, booléen

Debut +
	si mdp == mdp_confirmation
		mdp_verif = vrais
	Sinon
		mdp_verif = faux
	Fin si
revois mdp_verif
FIN
*/
function mdp_verif() //Vérifie le mot de passe
{
    $mdp = htmlspecialchars($_POST['mdp']);//Récupère le mot de passe
    $mdp_confirmation = htmlspecialchars($_POST['mdp_confirmation']);//Récupère le mot de passe 
    if ($mdp == $mdp_confirmation) //Si les 2 mots de passe son correspondant
    {
        $mdp_verif = true; //Verif de mdp passe à vrai
    }
    else 
    {
        $mdp_verif = false; //Verif de mdp passe à faux
    }
    return $mdp_verif;//Renvoi l'état de la vérif
}
	  
function verif_mail() 
{
    $bdd = connectbdd(); 
    //récupère l'email saisie dans le formulaire
    $mail = htmlspecialchars($_POST['email']);//remplace les caractères qui pourrais devenir des balises html [<,>,& et les quottes]
    //prépare une requête qui compte le nombre d'adresse mail similaire à celle saisie
    $requete="SELECT COUNT(mail) FROM compte WHERE mail=\"".$mail."\"";
    //envoie la requête a la bdd
    $resultat=mysqli_query ($bdd,$requete) or die ("Impossible de créer la requête!<br>");
    $row=mysqli_fetch_row($resultat);
    if ($row[0]==0) //si le row[0] est a 0 donc l'email est unique et valide
    {
        $verif_mail=true;
    }
    else
    {
        $verif_mail=false;
    }
    return $verif_mail;
}

function deconnexion() 
{
    //détruis la session, supprime les valeurs des $_Session()
    session_destroy(); 
}

function afficherEntete() //affiche l'entete
{
	
	printf("<center>");
	printf("<header >");
		printf("<div id=header>");
		if($_SESSION['rank']!="")
		{
			printf("<a href=\"./accueil.php\">  Accueil  </a>");
			printf("<a href=\"./historique.php\">|  Historique  </a>");		
			printf("<a href=\"./compte.php\">|  Espace utilisateur  </a>");
			if ($_SESSION['rank']==3){ //si l'utilisateur est admin j'affiche les pages de gestions
				printf("<a href=\"./gestionC.php\">|  Gestion Chambre  </a>");
				printf("<a href=\"./gestion.php\">|  Gestion des utilisateurs  </a>");
			}
            printf("<a href=\"./deconnexion.php\">|  Déconnexion  </a>");	
		}
		printf("</div>");
	printf("</header>");
	printf("</center>");
}

function afficherFooter()//affiche le pied de page
{
	printf("<br><br><div class=\"footer\" <p>© Copyright 2022 PMF</p>");
}
/*
Algorithme Verif_Connection
VAR : 	email, chaine de caracteres
		verif,  booleen

debut 
	si email != " "
		requeteVerif -> bdd
		verif <- bdd
		si verif = faux
			afficher alerte
			rediriger
		fin si
	sinon
	afficher alerte
	rediriger
	Fin Si
Fin
*/
function verif_Connection($email)//verifie la connection d'un utilisateur en récupérant le $_Session['email']
{
    if ($email=="") //si l'email de la session est vide, l'utilisateur ne s'est pas connecté...
    {
        //un script d'alerte apparait, quand l'utilisateur l'aura validé la page va rediriger vers le formulaire de connexion
        printf("<script type=\"text/javascript\">alert(\"Vous n'êtes pas connectez ! Vous allez être redirigé vers la page de connexion !\");</script>");
        printf("<meta http-equiv=\"refresh\" content=\"0; URL=./index.php\">");
    }
    else
    {
        $verif=false;
        //création de la requête qui récupère les emails des comptes existants
		$bdd = connectbdd(); //appel la fonction connectbdd
        $requeteConnection="SELECT mail from compte where 1;";
        //envoie de la requête dans la bdd 
        $resultat=mysqli_query($bdd,$requeteConnection) or die("Impossible de vérifier la connexion");
        while($tab=mysqli_fetch_array($resultat)) //tant qu'il y a des emails dans la base de données 
        {
            if($email==$tab['mail']) //si l'email de la session correspond à un email de la bdd :
            {
                //la variable verif passe à vrais 
                $verif=true;
            }
        }
        if($verif==false) //si l'email après la vérification reste à false l'utilisateur possède un email invalide, on le redirige vers la page de connexion.
        {
            printf("<script type=\"text/javascript\">alert(\"L'email de votre Session est invalide ! Vous allez être redirigé vers la page de connexion !\");</script>");
            printf("<meta http-equiv=\"refresh\" content=\"0; URL=./index.php\">");
        }
    }
}


function verif_admin($rank) //récupère le $_Session['rank'] qui possède le rank de l'utilisateur
{
    if ($rank<3 || $rank=="")//Si le rank de la session utilisateur est inférieur à celui d'un administrateur ou vide
    {
        //une balise d'alerte apparait, une fois valider l'utilisateur est rediriger vers l'accueil
        printf("<script type=\"text/javascript\">alert(\"Cette page est réserver aux administrateurs ! Vous allez être redirigé vers la page d'accueil.\");</script>");
        printf("<meta http-equiv=\"refresh\" content=\"0; URL=../accueil.php\">");
    }
}

function verif_norme($type,$tempMini,$tempMax)//Verifie si la norme est respecté en fonction du type de chambre
{
	if($type == "positive")//Si la chambre est positive ALORS
	{
		$normeTempMini = 0.00;//La température minimum 
		$normeTempMax = 3.00;//La température maximum 
	}
	if($type == "negative")//Si la chambre est négative ALORS
	{
		$normeTempMini = -26.00;//La température minimum 
		$normeTempMax = -18.00;//La température maximum
	}
	
	if(($normeTempMini <= $tempMini )&&($tempMax <= $normeTempMax))//Si la température saisi est compris dans la norme ALORS
	{
		return true;//Retourne vrai
	}
	else
	{
		return false;//Retourne faux
	}
}

?>
 