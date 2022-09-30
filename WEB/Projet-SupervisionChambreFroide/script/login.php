<?php
session_start();
require ('fonctions.php');

$bdd = connectbdd();
$user_pseudo = htmlspecialchars($_POST['email']);

//crée une requête qui récupère les informations par rapport à l'adresse email saisie 
$requeteMdp="SELECT mdp,prenom,idRole,nom FROM compte WHERE mail = \"".$_POST['email']."\"";
$reponse_mdp = mysqli_query($bdd,$requeteMdp) or die (mysqli_error($bdd));//Envoie de la requête a la base de données ou sinon affiche une erreur
$user = mysqli_fetch_array($reponse_mdp);
$user_mdp = crypt_mdp($_POST['mdp'],$user[1]);//crypte le mdp saisie pour le comparer à celui de la bdd
//printf ("mdp saisis : ".$user_mdp."<br>");//Affiche le mot de passe saisie [DEBUG]
//printf("mdp bdd : ".$user[0]."<br>");//affiche le mot de passe de la bdd [DEBUG]

//si un mot de passe a bien été saisie et que le mot de passe saisie est le même que celui de la bdd
if (isset($_POST['mdp']) && ($user_mdp == $user[0])) 
{  
    //initialise les SESSION nécessaire
    $_SESSION['email'] = htmlspecialchars($_POST['email']);
    $_SESSION['ip'] = $_SERVER['REMOTE_ADDR'];
    $_SESSION['prenom'] = $user[1];
    $_SESSION['rank']= $user[2];
    $_SESSION['nom']=$user[3];
    header('Location: ../accueil.php');//redirige vers l'accueil
}
else //sinon la connexion a échouer 
{
    //une balise alerte s'affiche, une fois valider la page redirige vers la page de connexion 
    printf("<script type=\"text/javascript\">
    alert(\"Votre mot de passe ou email est incorrect !\");
    </script>");
    printf("<meta http-equiv=\"refresh\" content=\"0; URL=../index.php\">");
}

?>

