<html>
    <head>
        <meta charset ="UTF-8">
        <meta name="viewport" content="width=device.width, initial-scale=1.0">
        <link rel="stylesheet" href="./script/style.css"/>

    </head> 
    <?php
    require ('./script/fonctions.php');
    session_start(); //appel la fonction php session_start
    verif_Connection($_SESSION['email']);//appel la fonction verif_Connection
    $bdd = connectbdd(); //appel la fonction connectbdd
    if($_SESSION['email']!="") //si l'utilisateur est connecté 
    {
        //les variables 
        $choixHistorique=$_POST["type"];
        $dateDebut = $_POST["dateDebut"];
        $dateFin = $_POST["dateFin"];
        $affichageH =0;
        $affichageH = $_POST['affichageHis'];
        $i=0;
        $afficherPDF=false;
        
        
        printf("<body>");
        afficherEntete($_SESSION['rank']);//fonction qui affiche l'entête
        printf("<div class=\"corp\"><center><h1><b>Historique</b></h1></center>");

        //préparation de la requête qui récupère l'id et le nom des chambres froides
        $requete = "SELECT id_chambre,nom_chambre FROM chambre_froide";
        //Envoie de la requête a la base de données ou sinon affiche une erreur
        $resultat = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));
        printf("<form method=\"POST\" action=\"./historique.php\">");
        ?>
        <p> 
            Date début historique :
            <input type="date" name="dateDebut" class="input" required />
            
            Date fin historique :
            <input type="date" name="dateFin" class="input" required />
        </p>
        <p>
        <?php
        printf("Selection la/les chambres froides :</p><p>");
        while($tab = mysqli_fetch_array($resultat))//tant qu'il y a des chambres existantes
        {
            //(if) Permet de check la première check box
            if ($i==0){
                // met en value l'id de la chambre (récupérer dans la base de données) et met en nom, le nom de la chambre récupérer dans la base de donnée) pour l'option du select
                printf("".$tab["nom_chambre"]."<input class=\"checkbox\" type=\"checkbox\" name=\"".$tab["id_chambre"]."\" value=\"value1\" checked></input>");
                $i=$i+1;
            }
            //une fois que le premier checkbox est affiché on affiche les suivant non-check
            else{ printf("".$tab["nom_chambre"]."<input class=\"checkbox\" type=\"checkbox\" name=\"".$tab["id_chambre"]."\" value=\"value1\"></input>"); }
        }
        ?>
        </p>
        <p>Selectionnez le type d'historique: </p>
        <input type="radio" id="temperature" name="type" value="temperature" checked><label for="temperature">Temperature</label>
        <input type="radio" id="porte" name="type" value="porte"><label for="porte">Porte</label>
        <input type="radio" id="alerte" name="type" value="alerte"><label for="alerte">Alerte</label>
        <input type="hidden" name="affichageHis" value=1 />
        <input type="submit" value="Afficher l'historique" class="blueBouton"/><br>
        <!--fin historique-->
        </form>
        <div id="pdf">
        <form  method="POST" target="_blank" action= "./makepdf.php">
        
        <input type="hidden" name="choix" value="<?php printf($choixHistorique); ?>" checked />
        <input type="hidden" name="dateDebut" value="<?php printf($dateDebut); ?>" />
        <input type="hidden" name="dateFin" value="<?php printf($dateFin); ?>" />
        <p>Selectionnez le contenu du PDF: </p>
        <?php
        printf("<input type=\"checkbox\" name=\"donnee\" id=\"donnee\" value=\"donnee\" onclick=\"verif()\"><label for=\"donnee\">Donnée</label>");
        if($choixHistorique == "temperature")
        {
            printf("<input type=\"checkbox\" name=\"graph\" id=\"cbgraph\" value=\"graph\" onclick=\"verif()\"><label id=\"labelGraph\" for=\"graph\">Graphique</label>");
        }
        printf('<br><input type="submit" id="submitPDF" value="Générer pdf" disabled =true class="blueBouton"></form> </div>'); 
        //choix de l'historique température
        if($choixHistorique == "temperature")
        {
            $i =0;//variable pour séparer les
            $requete = "SELECT id_chambre,nom_chambre FROM chambre_froide";
            $resultat = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Envoie de la requête a la base de données ou sinon affiche une erreur
            printf("<center><table>");
            while($tabl = mysqli_fetch_array($resultat))
            {
                $id_chambre=$tabl["id_chambre"];
                $nom_chambre=$tabl["nom_chambre"];
                printf("<tr><td>");
                if(isset($_POST[$id_chambre]))
                {
                    //printf($tabl["nom_chambre"]."<br>"); //test qui affiche la chambre passée dans le isset [DEBUG]
                    printf("<div style=\" overflow:auto; width:300px; height:550px; solid;\">
                    <table border=\"4\" id=\"table\" class=\"donnee\"><tr><td> Date </td><td> Heure </td><td> Valeur Temperature </td></tr>");
                    $afficherPDF=false;
                    $requeteHistorique="SELECT chambre_froide.id_chambre,nom_chambre,date,heure,temperature from releverTemperature,chambre_froide where releverTemperature.id_Chambre=chambre_froide.id_chambre AND releverTemperature.id_chambre= \"".$id_chambre."\" AND releverTemperature.date BETWEEN \"".$dateDebut."\" AND \"".$dateFin."\" ORDER BY releverTemperature.date desc,heure DESC;";
                    $resultatHistorique= mysqli_query($bdd,$requeteHistorique)or mysqli_error($bdd);
                    //printf($requeteHistorique);//affiche la requête [DEBUG]
                    while($historique=mysqli_fetch_array($resultatHistorique))
                    {
                        //Vérification des valeurs contenue dans le tableau.
                        
                        if($historique["temperature"]!=""){
                            printf("<tr><td>".$historique["date"]."</td><td>".$historique["heure"]."</td><td>".$historique["temperature"]."</td></tr>");    
                        
                            $tabDonnee[$i][0] = $historique['nom_chambre'];
                            $tabDonnee[$i][1] = $historique['date'];
                            $tabDonnee[$i][2] = $historique['heure'];
                            $tabDonnee[$i][3] = $historique['temperature'];
                            $i = $i+1;
                            $afficherPDF=true;
                        }
                        else
                        {
                            if($afficherPDF==false)
                            { //si c'est vide je n'affiche pas la possibilité de crée le pdf 
                            //$afficherPDF=false;
                            printf("il n'y a pas de valeurs dans les dates voulue");
                            }
                        }
                    }
                    printf("</table></div></td><td>");
                    
                    if($i>=2)
                    {
                        require("graph.php"); //affiche le graph
                        $i=0; //on passe à la chambre suivante, i repasse a 0
                        printf("</td></tr>");
                    }
                    else
                    {
                        ?>
                        <script> 
							var cbGraph=document.getElementById("cbgraph");
							var labelGraph = document.getElementById("labelGraph");
							cbGraph.style.visibility="hidden"; 
							labelGraph.style.visibility="hidden";
						</script>
                        <?php
                        printf("<br>Pas assez de donnée pour générer le graphique.<br></td></tr>");
                    }   
                    
                }
            }
            printf("</table></center>");
        }
        if($choixHistorique == "porte")
        {
            $i =0;
        
            $requete = "SELECT id_chambre,nom_chambre FROM chambre_froide";
            $resultat = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Envoie de la requete a la base de données ou sinon affiche une erreur
            while($tabl = mysqli_fetch_array($resultat))
            {
                $id_chambre=$tabl["id_chambre"];
                $nom_chambre=$tabl["nom_chambre"];
                //printf("id chambre : ".$tabl["id_chambre"]);

                if(isset($_POST[$id_chambre]))
                {
                    printf($tabl["nom_chambre"]."<br>");
                    printf("<table border=\"4\"><tr><td> Nom de la chambre </td><td> Date </td><td> Heure </td><td> état de la Porte </td></tr>");
                    $requeteHistorique="SELECT chambre_froide.nom_chambre,date,heure,etatPorte.nomEtatPorte FROM releverPorte,chambre_froide,etatPorte WHERE releverPorte.id_Chambre=chambre_froide.id_chambre AND releverPorte.id_chambre= \"".$id_chambre."\" AND etatPorte.id_etatPorte = releverPorte.etatPorte AND releverPorte.date BETWEEN \"".$dateDebut."\" AND \"".$dateFin."\" ORDER BY releverPorte.date desc,heure DESC;";
                    $resultatHistorique= mysqli_query($bdd,$requeteHistorique) or mysqli_error($bdd);
                    //printf($requeteHistorique);
                    while($historique=mysqli_fetch_array($resultatHistorique))
                    {
                        printf("<tr><td>".$historique['nom_chambre']."</td><td>".$historique["date"]."</td><td>".$historique["heure"]."</td><td>".$historique["nomEtatPorte"]."</td></tr>");    
                        
                        $tabDonnee[$i][0] = $historique['nom_chambre'];
                        $tabDonnee[$i][1] = $historique['date'];
                        $tabDonnee[$i][2] = $historique['heure'];
                        
                        if($historique['nomEtatPorte'] == "fermée")
                        {
                            $tabDonnee[$i][3] = "fermeture";
                        }
                        if($historique['nomEtatPorte'] == "ouvert")
                        {
                            $tabDonnee[$i][3] = "ouverture";
                        }
                        
                        $i = $i+1;
                        $afficherPDF=true;
                    }
                    printf("</table>");
                }
            }
        }
        
        if($choixHistorique == "alerte")
        {
            $i =0;
            
            $requete = "SELECT id_chambre,nom_chambre FROM chambre_froide";
            $resultat = mysqli_query($bdd,$requete) or die (mysqli_error($bdd));//Envoie de la requête a la base de données ou sinon affiche une erreur
            while($tabl = mysqli_fetch_array($resultat))
            {
                $id_chambre=$tabl["id_chambre"];
                $nom_chambre=$tabl["nom_chambre"];
                //printf("id chambre : ".$tabl["id_chambre"]);

                if(isset($_POST[$id_chambre]))
                {
                    printf($tabl["nom_chambre"]."<br>");
                    printf("<table border=\"4\"><tr><td> Nom de la chambre </td><td>type d'alerte</td><td> Date alerte </td><td> Heure alerte</td><td> Acquittement </td><td> Date acquittement </td><td> Heure acquittement </td></tr>");
                    $requeteHistorique= "SELECT chambre_froide.nom_chambre,nomAlerte,dateAlerte,heureAlerte,acquitement,dateAcquitement,heureAcquitement 
                    FROM alerte,chambre_froide,typeAlerte
                    WHERE alerte.id_Chambre=chambre_froide.id_chambre 
                    AND alerte.id_chambre= \"".$id_chambre."\"
                    AND alerte.code_alerte = typeAlerte.id_codeAlerte 
                    AND alerte.dateAlerte BETWEEN \"".$dateDebut."\" AND \"".$dateFin."\" 
                    ORDER BY alerte.dateAlerte desc,alerte.heureAlerte DESC";
                    $resultatHistorique= mysqli_query($bdd,$requeteHistorique) or mysqli_error($bdd);
                    //printf($requeteHistorique);
                    while($historique=mysqli_fetch_array($resultatHistorique))
                    {
                        if($historique['acquitement']=="1")
                        {
                            $acquitter = "Acquitter";
                        }
                        if($historique['acquitement']=="0")
                        {
                            $acquitter = "En alerte";
                        }
                        printf("<tr><td>".$historique['nom_chambre']."</td><td>".$historique["nomAlerte"]."</td><td>".$historique["dateAlerte"]."</td><td>".$historique["heureAlerte"]."</td><td>".$acquitter."</td><td>".$historique["dateAcquitement"]."</td><td>".$historique["heureAcquitement"]."</td></tr>"); 
                        
                        $tabDonnee[$i][0] = $historique['nom_chambre'];
                        $tabDonnee[$i][1] = $historique['nomAlerte'];
                        $tabDonnee[$i][2] = $historique['dateAlerte'];
                        $tabDonnee[$i][3] = $historique['heureAlerte'];
                        $tabDonnee[$i][4] = $acquitter;//$historique['acquitement'];
                        $tabDonnee[$i][5] = $historique['dateAcquitement'];
                        $tabDonnee[$i][6] = $historique['heureAlerte'];
                        $i = $i+1;
                        $afficherPDF=true;
                    }
                    printf("</table>");
                }
            }
        }
    $_SESSION['valeur'] =$tabDonnee;
    ?>
    <script>

    var formulairePDF = document.getElementById("pdf");
    formulairePDF.style.visibility="hidden"; //cache le formulaire pdf si il ne doit pas être visible

        var cBDonnee = document.getElementById("donnee");
        var cbGraph = document.getElementById("cbgraph");
        var bPEnvoyer = document.getElementById("submitPDF");

        function verif()
        {
            
            if (cBDonnee.checked == false && cbGraph.checked == false)
            {
                bPEnvoyer.disabled = true;
            }

            
            if (cBDonnee.checked == true || cbGraph.checked == true )
            {
                bPEnvoyer.disabled = false;
            }

            
            if (cBDonnee.checked == true && cbGraph.checked == true)
            {
                bPEnvoyer.disabled = false;
            }
        }
    </script>

    <?php
    if ( $afficherPDF==true)
    {
        printf("<script> formulairePDF.style.visibility=\"visible\"</script>");
    }
    elseif($choixHistorique!=""){
        printf("Création du pdf impossible, valeurs insuffisantes");
    }

    require("./script/script.html");
    }
?>

</div></body>
<?php
    afficherFooter();
?> 
</html>
