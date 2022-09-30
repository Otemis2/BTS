<html>
    <head>
        <meta charset ="UTF-8">
        <meta name="viewport" content="width=device.width, initial-scale=1.0">
        <link rel="stylesheet" href="./script/style.css"/>
        <title> Gestion Chambre</title>
    </head>
    <?php
    require ('./script/fonctions.php');
    ?>
    <body>
    <?php
    session_start();
    afficherEntete($_SESSION['rank']);
    verif_Connection($_SESSION["email"]); //fonction qui vérifie la connexion de l'utilisateur
    verif_admin($_SESSION["rank"]); //fonction qui vérifie si l'utilisateur est un admin
    $bdd=connectbdd();//Appel la fonction qui permet la connexion à la base de donnée
    
    //initialisation des variables
    $choix=$_POST["choix"];
    $confirm=$_POST["validation"];
    
    //Variable utilisé pour modifier une chambre variable vide si le formulaire n'a pas été validé
    $nomChambre=$_POST["nomChambre"];
    $idChambre=$_POST["idChambre"];
    $tempMini=$_POST['tempMini'];
    $tempMaxi=$_POST['tempMax'];
    $type=$_POST['type'];
	$statut = $_POST['statut']
    
    ?>

    <div class="corp">
    <center>
    <h2>Gestion chambre </h2>
    <p id=titreTabl> Tableau des normes de temperatures</p>
    <table border="2" class="donnee"> 
        <tr>
            <th><center> Type de chambre </center></th>
            <th><center> Température Minimun Autorisé </center></th>
            <th><center> Température Maximum Autorisé </center></th>
        <tr>
        <tr>
            <td><center> Négative </center></td>
            <td><center> -26°C </center></td>
            <td><center> -18°C </center></td>
        <tr>
        <tr>
            <td><center> Positive </center></td>
            <td><center> 0°C </center></td>
            <td><center> 3°C </center></td>
        <tr>
    </table>
    
        <p>
            <?php
            if($_SESSION["rank"]==3) //si l'utilisateur est admin j'affiche les boutons 
            {
            printf("
                <table>
                <td>
                    <form action=\"\" method=\"POST\">
                        <input type=\"hidden\" name=\"choix\" value=\"1\" >
                        <input type=\"submit\" value=\"Modifier une chambre\" class=\"blueBouton\">
                    </form>
                </td>
                <td>
                    <form action=\"\" method=\"POST\">
                        <input type=\"hidden\" name=\"choix\" value=\"2\" >
                        <input type=\"submit\" value=\"Ajouter une chambre\" class=\"blueBouton\">
                    </form>
                </td>
                <td>
                    <form action=\"\" method=\"POST\">
                        <input type=\"hidden\" name=\"choix\" value=\"3\" >
                        <input type=\"submit\" value=\"Modifier statut\" class=\"RedBouton\">
                    </form>
                </td>
                </table>
            ");
            }
            ?>
        </p>
    
    </p>
    <?php
    #affichage des variables [DEBUG]
    // print($confirm."<br>");
    // print($nomChambre."<br>");
    // print($idChambre."<br>");
    // print($tempMini."<br>");
    // print($tempMaxi."<br>");
    // print($type."<br>");
    
    if($choix==1)//choix modifier Chambre
    {
    ?>
        <p> ⚠️ les champs laissés vide ne seront pas modifiés ⚠️<br></p>
        <form method="POST" action="./gestionC.php">
        <p>Chambre à éditer <select name="idChambre" id="idChambre" class="input"></p>
        <?php
            $requete = "SELECT id_chambre,nom_chambre FROM chambre_froide where 1"; //Requête pour récupérer les id des chambres et leurs noms 
            $resultat = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Envoie de la requête à la base de donné ou sinon affiche une erreur 
            while($tab = mysqli_fetch_array($resultat)) //tant qu'il y a des valeurs dans le tableau de valeurs du résultat
            {
                // met en value l'id de la chambre et le nom de la chambre récupéré dans la base de données pour l'option du select
                printf("<option value =".$tab['id_chambre'].">".$tab['nom_chambre']."</option>");
            }
        ?>
        </select><br>
        <p>Nom de la chambre : <input type="text" class="input" name="nomChambre" > <br></p>
        <p>Modifier interval d'alerte :</p>
        <p>Seuil Minimum <input type="number" name="tempMini" class="input" placeholder="0.0" step="0.1" > <br></p>
        <p>Seuil Maximum <input type="number" name="tempMax" class="input" placeholder="3.0" step="0.1" > <br></p>
        <input name="choix" type="hidden" value="1">
        <input name="validation" type="hidden" value="1">
        <p><input type="submit" value="Modifier interval de temperature avant alerte" class="blueBouton"/><br></p>
        <?php
        if($confirm == 1) //bouton confirmation de modifier 
        {
            //crée une requête qui permet de récupérer les valeurs de la chambre avant la modification
            $reqSave="SELECT * FROM chambre_froide,reglageAlerte WHERE chambre_froide.id_chambre = ".$idChambre." AND reglageAlerte.id_Chambre = chambre_froide.id_chambre";
            
            //envoie la requête a la bdd
            $Save=mysqli_query ($bdd,$reqSave) or die ("Impossible de créer la requête!");

            //place les valeurs dans un tableau 
            $ligneSave=mysqli_fetch_row($Save);

            if(($tempMaxi == "")||($tempMini == "")||$nomChambre =="") //si un champ du formulaire et vide alors ..
            {
                if($tempMaxi == "") //si la tempMaxi est vide on place la valeur récupérée dans la bdd avant modification et on la met dans une variable 
                {
                    $tempMaxi = $ligneSave[6];
                }
                
                if($tempMini == "")//si la tempMini est vide on place la valeur récupérée dans la bdd avant modification et on la met dans une variable
                {
                    $tempMini = $ligneSave[5];
                }
                
                if($nomChambre == "") //si le nom de la chambre est vide on place la valeur récupérée dans la bdd avant modification et on la met dans une variable
                {
                    $nomChambre = $ligneSave[1];
                }
                //print_r($ligneSave); //affiche le tableau de valeur [DEBUG]
            }
            if(($tempMaxi!= $ligneSave[6])||($tempMini!=$ligneSave[5])) //si les valeurs de température son différentes de celles actuelles dans la bdd
            {
                if($tempMaxi > $tempMini) //on vérifie que la température mini est bien plus petite que la température maxi
                {
                    $verif = verif_norme($ligneSave[2],$tempMini,$tempMax); //si la tempMini est vide on place la valeur récupérée dans la bdd avant modification et on la met dans une variable
                    if($verif == true) //si les valeurs on passée les vérifications :
                    {
                        //prépare la requête de modification des réglages de la chambre sélectionnée 
                        $requeteUpdateReglage = "UPDATE reglageAlerte SET temperatureMini=".$tempMini.",temperatureMax  =".$tempMaxi." WHERE id_chambre=".$idChambre;
                        //printf($requeteUpdateReglage."<br>"); //affiche la requête [DEBUG]
                        $resultatUpdate= mysqli_query($bdd,$requeteUpdateReglage) or die (mysqli_error($bdd)); //Envoie de la requête a la base de donnée ou sinon affiche une erreur
                        printf("<br>Les valeurs d'alerte ont bien été modifiées avec la température minimum de :".$tempMini." et une température maximum de :".$tempMaxi);
						printf(" <meta http-equiv=\"refresh\" content=\"3;\"> ");//Redirige au bout de 3 secondes
					}
                    else
                    {
                        printf("<br>Les valeurs saisis ne respectent la norme");
                    }
                }
                else
                {
                    printf("<br>Les valeurs de temperature sont inversées");
                }
            }
        
            if ($nomChambre!= $ligneSave[1]) //si les valeurs ne sont pas vides une fois le formulaire compléter et valider,
            {
                $reqNbChambre="SELECT COUNT(nom_chambre) FROM chambre_froide WHERE chambre_froide.nom_chambre = \"".$nomChambre."\""; //préparation de la requête qui compté le nombre de chambre qui ont le nom donné
                $resNbChambre=mysqli_query ($bdd,$reqNbChambre) or die ("Impossible de créer la requête!"); //applique la requête
                $ligneNbChambre=mysqli_fetch_row($resNbChambre);
                if($ligneNbChambre[0] == 0) //si aucune chambre ne possède le même nom
                {
                    $requeteUpdateChambre = "UPDATE chambre_froide SET nom_chambre=\"".$nomChambre."\" WHERE  id_chambre=".$idChambre; //on prépare la requête de modification du nom de la chambre
                    //printf($requeteUpdateChambre."<br>"); //affiche la requête pour débugger
                    $resultatUpChambre= mysqli_query($bdd,$requeteUpdateChambre) or die (mysqli_error($bdd)); //Envoie de la requête a la base de donné ou sinon affiche une erreur
                    printf("<br>La chambre nommée ".$ligneSave[1]." a bien été renommé en ".$nomChambre);
					printf(" <meta http-equiv=\"refresh\" content=\"3;\"> ");//Redirige au bout de 3 secondes
                }
                else //la requête a trouvé une chambre avec le même nom
                {
                    printf("<br>Il y a déjà une chambre nommée ".$nomChambre);
                }
            }
        }
        
    }
    
    
    if($choix==2)//choix d'ajouter
    {

        printf("<form action=\"\" method=\"POST\">");
        printf("<p><br>Nom  de la chambre : <input type=\"text\" name=\"nomChambre\" class=\"input\" required/></p>");
        printf("<p>Type : ");//<input type=\"text\" name=\"type\" required/><br>
        printf("<select name=\"type\"  class=\"input\" required/></p>");
        printf("<option value =\"positive\">Positive</option>");
        printf("<option value =\"negative\">Négative</option>");
        printf("<p></select><br></p>");
        
		printf("<p>Modifier interval d'alerte :</p>");
        printf("<p>Seuil Minimum <input type=\"number\" name=\"tempMini\" class=\"input\" placeholder=\"0.0\" step=\"0.1\" required /></p>");
        printf("<p>Seuil Maximum <input type=\"number\" name=\"tempMax\" class=\"input\" placeholder=\"3.0\" step=\"0.1\" required/></p>");
        printf("<input name=\"validation\" type=\"hidden\" value=\"1\">");
        printf("<input name=\"choix\" type=\"hidden\" value=\"2\">");       
        printf("<p><input type=\"submit\" value=\"Confirmer ajout\" class=\"blueBouton\" /><br></p>");  
        printf("</form>");
        
        if($confirm==1)//quand le bouton de confirmation de l’ajout est cliqué
        {
            //crée la requête qui compte le nombre de chambres qui possède le nom demander
            $requete="SELECT COUNT(nom_chambre) FROM chambre_froide WHERE nom_chambre= \"".$nomChambre."\"";
            // printf("requête : ".$requete); //affiche la requête [DEBUG]
            $resultat=mysqli_query ($bdd,$requete) or die ("Impossible de créer la requête!"); //exécute la requête
            $row=mysqli_fetch_row($resultat); //place les valeurs dans un tableau
            if ($row[0]==0) //si le count est égale à 0 c’est qu’aucune autre chambre a le même nom alors :
            {
                if ($tempMaxi!=""&& $tempMini!="") //on vérifie que les valeurs de température ne sont pas vide
                {
                    if ($tempMaxi > $tempMini) //et que la température maxi est bien supérieure à la température mini
                    {
                        //si la tempMini est vide on place la valeur récupérée dans la bdd avant modification et on la met dans une variable
                        $verif = verif_norme($type,$tempMini,$tempMaxi);
                        if($verif == true) //si les valeurs on passée les tests
                        {
                            //création de la requête d'ajout de la chambre
                            $requetteAjoutChambre="INSERT INTO chambre_froide(id_chambre, nom_chambre, Type) VALUES (NULL,\"".$nomChambre."\",\"".$type."\")";
                            // printf("<br>requête d'ajout : ".$requetteAjoutChambre."<br>");

                            //execute la requête
                            $resultatAjoutChambre=mysqli_query($bdd,$requetteAjoutChambre) or die ("Impossible de créer la requête!");
                            
                            //recupere l'id de la chambre crée
                            $requetteSelectionChambre = "SELECT id_chambre FROM chambre_froide WHERE nom_chambre = \"".$nomChambre."\" ";
                            $resultatSelectionChambre =mysqli_query($bdd,$requetteSelectionChambre) or die ("Impossible de créer la requête!");
                            // printf("<br>requête de sélection: ".$requetteSelectionChambre."<br>"); //Affiche la requête [DEBUG]
                            
                            //place le résultat dans un tableau 
                            $idChambre = mysqli_fetch_row($resultatSelectionChambre);
                            //print_r($idChambre);//affiche le résultat du tableau [DEBUG]
                            
                            //crée la requête qui insère des valeurs par default pour les reglage d'alerte
                            $requeteReglageAlerte="INSERT INTO reglageAlerte(id_reglageAlerte, id_Chambre, temperatureMini, temperatureMax) VALUES (NULL,".$idChambre[0].",".$tempMini.",".$tempMaxi.")";
                            //printf("<br>requête de réglage d'alerte : ".$requeteReglageAlerte."<br>"); //affiche la requête [DEBUG]
                            $resultatReglageChambre=mysqli_query($bdd,$requeteReglageAlerte) or die ("Impossible de créer la requête de l'alerte !");
                            
                            //crée la requête qui insere des valeurs par default pour les relever de température
                            $reqAjoutValeurTemp="INSERT INTO releverTemperature(id_releverTemperature,id_Chambre,date,heure,temperature) VALUE (NULL,".$idChambre[0].",\"0000/00/00\", \"00:00:00\", 99)";
                            //printf("<br>requête de reqAjoutValeurTemp : ".$reqAjoutValeurTemp."<br>"); //affiche la requête [DEBUG]
							$resultAjoutT=mysqli_query($bdd,$reqAjoutValeurTemp) or die("Impossible de créer la requête de la temperature !");
                            
                            //crée la requête qui insère des valeurs par default pour les relever de portes
                            $reqAjoutValeurPorte="INSERT INTO releverPorte(id_releverPorte,id_Chambre,date,heure,etatPorte) VALUE (NULL,".$idChambre[0].",\"0000/00/00\", \"00:00:00\", 2)";
                            //printf("<br>requête de reqAjoutValeurPorte : ".$reqAjoutValeurPorte."<br>"); //affiche la requête [DEBUG]
							$resultAjoutP=mysqli_query($bdd,$reqAjoutValeurPorte) or die("Impossible de créer la requête de la porte!");

                            printf("<br>La chambre a été bien ajouté");
							printf(" <meta http-equiv=\"refresh\" content=\"3;\"> ");//Redirige au bout de 3 secondes
                        }   
                        else
                        {
                            printf("<br>Les valeurs saisis ne respectent la norme donc la création de la chambre a été annulé.");
                        }
                    }
                    else
                    {
                        printf("<br>Les valeurs de température sont inversées");
                    }
                }
                else
                {
                    printf("Saisissez les valeurs et appuyer sur \"Confirmer Ajout\"");
                }
            }
            else
            {
                printf("<br>La chambre existe déjà !");
            }
        }
    }


    
    if($choix==3)//Choix modifier statut
	{
		$reqChambre="SELECT * FROM chambre_froide WHERE 1";//Selectionne tout le contenu de la table chambre_froide

		$resultat=mysqli_query ($bdd,$reqChambre) or die ("Impossible de creer la requete!");//execute la requete
		printf("<form action=\"\" method=\"POST\">");//Comment un formulaire
		printf ("chambre froide à modifier : <select name=\"idChambre\">");//Menu déroulant pour selectionner une chambre
		while($tabChambre = mysqli_fetch_array($resultat))
		{
			printf("<option value=".$tabChambre['id_chambre'].">".$tabChambre['nom_chambre']."</option>");//Valeur envoyer par le formulaire sera l'id de la chambre
		}
		printf("</select> <br><br>");
		
		$reqStatut="SELECT * FROM statut WHERE 1";//selectionnne tout les statut
		$resStatut=mysqli_query ($bdd,$reqStatut) or die ("Impossible de creer la requete!");//execute la requete
		printf ("Statut à modifier : <select name=\"statut\" class=\"input\">");
		while($tabStatut = mysqli_fetch_array($resStatut))
		{
			printf("<option value=".$tabStatut['idStatut'].">".$tabStatut['nomStatut']."</option>");//Valeur envoyer sera l'idStatut
		}
		printf("</select> <br>");
		printf("<input name=\"choix\" type=\"hidden\" class=\"input\" value=\"3\">");//entrée cachée qui précise le choix de l'utilisateur
		printf("<input name=\"validation\" type=\"hidden\" class=\"input\" value=\"1\">");//entrée cachée	
		printf("<p><input type=\"submit\" value=\"Confirmer modification\" class=\"redBouton\"/></p>");
		printf("</form>");//Ferme le formulaire
		if($confirm=="1")//Si c'est confirmer
		{
			$reqModifierChambre="UPDATE chambre_froide SET statut= ".$statut." WHERE id_chambre = '".$idChambre."';";//Met a jour le statut de la chambre froide en fonction de l'id de la chambre et du statut selectionner
			//printf($reqModifierChambre."<br>");
			$ResultatModifierChambre = mysqli_query($bdd,$reqModifierChambre) or die("Impossible de creer la requete de modification !");//Execute la requete
			
			printf("La chambre froide nommé ".$nomChambre." à bien été modifier");
			printf(" <meta http-equiv=\"refresh\" content=\"3;\"> ");//Redirige au bout de 3 secondes

		}
		else //Sinon
		{
			//SELECT * FROM chambre_froide,reglageAlerte WHERE chambre_froide.id_chambre = reglageAlerte.id_Chambre
			$requeteInform="SELECT DISTINCT * FROM chambre_froide,statut WHERE chambre_froide.statut = statut.idStatut";//Selectionne sans doublon les chambres et leur statut
			$resultatInform=mysqli_query($bdd,$requeteInform);//Execute la requete
			printf("<br>Tableau des correspondences des chambres existantes :");
            printf("<div style=\" overflow:auto; width:300px; height:300px; solid;\">");
			printf("<table  border=\"4\" class=\"donnee\"><tr><td> Nom de la chambre </td><td> Type </td><td> Statut </td></tr>");//Affiche l'entete du tableau
			while($tab=mysqli_fetch_array($resultatInform))
			{
				printf("<tr><td>".$tab['nom_chambre']."</td><td>".$tab['Type']."</td><td>".$tab['nomStatut']."</td></tr>");//Affiche les données sous forme de tableau
			}
			printf("</table></div>");//Ferme le tableau
		}
	}
    ?>  
        
    </center></div></body>
    <?php
    afficherFooter();
    ?>
</html>