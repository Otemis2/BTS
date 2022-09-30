<html>
	<head>
		<meta charset="UTF-8">
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
		<link rel="stylesheet" href="./script/style.css"/>
		<script src="./justgage/raphael-2.1.4.min.js"></script>
		<script src="./justgage/justgage.js"></script>
		<!--<meta http-equiv="refresh" content="300;">-->
	</head>
	<?php
	
	require ('./script/fonctions.php');
	//connection a la bdd 
	$bdd=connectbdd();
	//initiation de la session 
	session_start();
	$i=0;
	$j=0;
	
	//appel la fonction qui affiche l'entete
		afficherEntete($_SESSION['rank']);
		
	//appel la fonction qui verifie que l'utilisateur est bien connecter
		verif_Connection($_SESSION['email']);
	if($_SESSION['email']!="")
	{
		?>
		<body onLoad="envoyerRequete()"><center>
		<p><h1>Accueil</h1></p>
		
		<table id="tabValeur"></table>
		
		<script>
		function envoyerRequete()
		{
			oReq.open("get", "script/getChambre.php", true);//Ouvre le fichier getChambre en méthode get de manière asynchrone
			oReq.send(null);// envoie la requête au serveur
		}
		setInterval(envoyerRequete, 5000);//Execute la fonction toute les 5 secondes

		var oReq = new XMLHttpRequest();//Crée un objet XMLHttpRequest
		oReq.responseType = "json";//Précise le type de donnée recu
		oReq.onload = reqListener;// fonction appellé quand une XMLHttpRequest est un succes 
		
		var jauge = [];//initilise un tableau
		
		function reqListener() 
		{
			//console.log(oReq.response);
			var result = oReq.response;//recupere les donnée dans une variable
			var count = result.length //calcule la taille (1 chambre par {} sauf le dernier qui reste vide)
			k=0;
			for (var j = 0; j < count-1;j++)// j = 0 = 1ere chambre 
			{
				//{"nomChambre","id_chambre","type","statut","temperature","etatPorte"}
				let idChambre = result[j]["id_chambre"];//Récupère les valeurs et les placent dans les variables
				let temperature = result[j]["temperature"];
				let etatPorte = result[j]["etatPorte"];
				let nomChambre = result[j]["nomChambre"];
				let type = result[j]["type"];
				let statut = result[j]["statut"];
				
				let nomIdPorte = "divPorte"+idChambre;//construit le nom des id des balises div
				let nomIdJauge = "divJauge"+idChambre;
				let nomIdEtatPorte = "textEtatPorte"+idChambre;
				let divPorte = document.getElementById(nomIdPorte);//renvoie un objet représentant l'élément dont l'id est le nom de la div
				let divJauge = document.getElementById(nomIdJauge);
				
			if(temperature == 99)
			{
				temperature = "@";
			}
			
				if(statut ==1)//Si la chambre est en service
				{
					k=k+1;
					//console.log("avant if "+nomChambre);
					if((divPorte == null)||(divJauge == null))//si les div n'existe pas
					{
						//console.log("dans if "+nomChambre);
						tabValeur = document.getElementById("tabValeur");
						let td = document.createElement("td");//Crée une balise td
						td.id = "td"+idChambre;//précise son id
						tabValeur.insertAdjacentElement('beforeend',td);//insere la balise td le tableau avant la fin du tableau
						if(divJauge == null)//Si la div de la jauge existe pas
						{
							//console.log("if construction  "+nomChambre);
							let divJauge = document.createElement('div');//crée une balise div
							divJauge.id = nomIdJauge;//précise son id
							td.insertAdjacentElement('afterbegin',divJauge);//insere la div apres la balise d'ouverture td 
							jauge[j] = afficherJauge(idChambre,nomIdJauge,nomChambre,temperature,type);//crée la jauge de la chambre et met l'objet retourner dans la tableau
						}
						if(divPorte == null)//si la div de la porte existe pas
						{
							let divPorte = document.createElement('div');//crée la div
							divPorte.id = nomIdPorte;//précise son id
							td.insertAdjacentElement('beforeend',divPorte);//insere la div apres la fin du td
							
							let center = document.createElement('center');//cree une balise center
							divPorte.insertAdjacentElement('afterbegin',center);//insère la balise center apres la balise d'ouverture de la div porte
							let text = document.createElement('text');//crée une balise text
							//text.textContent="état de la porte : ";
							center.insertAdjacentElement('afterbegin',text);//insere la balise text apres la balise d'ouverture center
							
							const contenuText = document.createTextNode("Porte : ");//Prepare le contenu de la balise
							text.appendChild(contenuText);//Ajoute le contenu de la balise
							
							let textEtatPorte = document.createElement('text');//cree une balise text
							textEtatPorte.id = nomIdEtatPorte;//precise son id
							text.insertAdjacentElement('afterend',textEtatPorte);//insere apres la fin de la balise text
							const contenuEtatPorte = document.createTextNode(etatPorte);//prepare le contenu
							textEtatPorte.appendChild(contenuEtatPorte);//ajoute le contenu
							//console.log(nomIdEtatPorte);
							
						}
						if(k==5)//si il y a 5 chambres dans une lignes
						{
							let sautDeligne = document.createElement('tr');//crée une balise tr
							td.insertAdjacentElement('afterend',sautDeligne);//place la balise tr apres la derniere balise td
							k =0;
						}
					}
					//console.log(typeof temperature);
					eval(jauge[j]).refresh(temperature);//converti le contenu de la variable jauge en nom de variable pour apellé l'objet et raffraichir sa valeur
					let idPorte = document.getElementById(nomIdEtatPorte);
					idPorte.innerHTML = etatPorte;//ajoute l'état de la porte
					//console.log(idPorte);
					if(etatPorte =="ouverte")//si l'etat de la porte est ouvert
					{
						idPorte.setAttribute("style", "color:red");//change la couleur du texte en rouge
					}
					if(etatPorte =="fermée")//si l'etat de la porte est fermée
					{
						idPorte.setAttribute("style", "color:green");//change la couleur du texte en vert
					}
					if(etatPorte =="--")//si l'etat de la porte est fermée
					{
						idPorte.setAttribute("style", "color:orange");//change la couleur du texte en orange
					}					
					if(statut ==0)//si la chambre est hors service
					{
						let tdChambre=document.getElementById("td"+idChambre);
						if(tdChambre != null)//Si la chambre existe
						{
							tdChambre.parentNode.removeChild(tdChambre);//Supprime la balise td de la chambre en question
						}
					}
				}
			} 
		}
		
		function afficherJauge(i,idDivJauge,nomChambre,temperature,type)
		{
			if((type)==("positive"))//si le type de chambre est positive alors prepare l'interval de couleur
			{
				couleurJauge = [
				{
				color:'#ff0000',//rouge
					lo:-50,//low (mini)
					hi:-4,//hight (maxi)
				},{
				color:'#ffc400',//orange
					lo:-4,
					hi:0,
				},{
				color:'#0000ff',//Bleu
					lo:0,
					hi:3,
				},{
				color:'#ffc400',//orange
					lo:3,
					hi:7,
				},{
				color:'#ff0000',//rouge
					lo:7,
					hi:50,
				}
				];
			}
			if((type)==("negative"))//si le type de chambre est negative alors prepare l'interval de couleur
			{
				couleurJauge = [
				{
				color:'#ff0000',//rouge
					lo:-50,//low (mini)
					hi:-30,//hight (maxi)
				},{
				color:'#ffc400',//orange
					lo:-30,
					hi:-26,
				},{
				color:'#0000ff',//Bleu
					lo:-26,
					hi:-18,
				},{
				color:'#ffc400',//orange
					lo:-19,
					hi:-11,
				},{
				color:'#ff0000',//rouge
					lo:-11,
					hi:50,
				}
				];
			}
			
			var jauge = new JustGage({
				id: idDivJauge,//id de la div (là ou elle s'affiche)
				value: temperature,//valeur par défaut
				min: -50.0,
				max: 50.0,
				formatNumber: true,
				title: nomChambre,
				symbol: "°C",
				decimals:1,//nombre chiffre affiché après la virgule
				
				titleFontColor: "blue",//precise la couleur du titre
				titleFontFamily: "blue",

				valueFontColor: "blue",
				valueFontFamily: "blue",
				customSectors: couleurJauge
				});
			return jauge;//retourne l'objet jauge
		}
        </script>

		</body></center>
		<?php
	}
	afficherFooter();	
	// Déconnexion de la BDD
	$bdd->close();	
	?>
</html>