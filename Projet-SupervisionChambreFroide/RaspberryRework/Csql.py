##encodage: utf-8
import mysql.connector
class CSql :
    """
    DOCUMENTATION de la classe CSql :
    Cette classe contient :
    - 2 accesseur :
    getTempMini()
    getTempMax()
    - 7 méthodes :
    insertionPorte(msgPorte,date,heure)
    insertionTemperature(msgTemp,date,heure)
    insertionAlerte(codeAlerte,date,heure)
    insertionAcquittement(date,heure)
    selectionMail()
    selectionIdChambre(nomChambre)
    selectionReglageAlerte(idChambre)
    
    Elle permet de se connecter à un serveur de base de données , de sélectionner et d'insérer des données.
    Classes utilisées : 
    mysql.connector
    Documentation source :
    https://dev.mysql.com/doc/connector-python/en/
    """
        #Initialiseur avec passage de paramètre (ip du serveur base de données, la bdd cible , l'identifiant de l'utilisateur et son mot de passe)    
    def __init__(self,ipServeurBdd,bdd,utilisateur,mdp):
        """
        Méthode d'initialisation de la classe CSql
        Nécessitant quatre paramètres :
        - l'ip du serveur de base de données en chaîne de caractères en Ipv4
        - la base de données cibles chaîne de caractères
        - l'utilisateur en chaîne de caractères
        - le mot de passe de l'utilisateur en chaîne de caractères
        Exemple d'appel : monSQL = CSql(127.0.0.1,Supervision,toto,azerty88)
        """
        self.mydb = mysql.connector.connect(
        host=ipServeurBdd,
        user=utilisateur,
        password=mdp,
        database=bdd
        )#Connexion au serveur de bdd
        self.mycursor = self.mydb.cursor()#création d'un curseur
    
    def insertionPorte(self,msgPorte,date,heure):    
        """
        DOCUMENTATION de insertionPorte
        Méthode qui permet d'insérer dans la base de données l'enregistrement de la porte (état de la porte, date, heure)
        Nécessitant trois paramètres :
        - l'état de la porte en booléen "0" => fermée , "1" => ouvert
        - la date en chaîne de caractères en format : 2022/02/20 (AAAA/MM/JJ)
        - l'heure en chaîne de caractères en heure : 13:00 (HH:MM)
        Exemple d'appel : monSQL.insertionPorte(1,2022/02/20,12:00)
        """
        sql = "INSERT INTO releverPorte (id_releverPorte , id_Chambre, date, heure, etatPorte)VALUES (NULL, %s, %s, %s, %s);"
        val = (self.idChambre,date,heure,msgPorte)
        self.mycursor.execute(sql, val)#Exécution de la requête
        self.mydb.commit()#Sauvegarde toutes les modifications 

    def insertionTemperature(self,msgTemp,date,heure):
        """
        DOCUMENTATION de insertionTemperature
        Méthode qui permet d'insérer dans la base de données l'enregistrement de la température (valeur de la température, date, heure)
        Nécessitant trois paramètres :
        - l'état de la porte en flottant 12,75 
        - la date en chaîne de caractères en format : 2022/02/20 (AAAA/MM/JJ)
        - l'heure en chaîne de caractères en heure : 13:00 (HH:MM)
        Exemple d'appel : monSQL.insertionTemperature(12,75,2022/02/20,12:00)
        """  
        sql = "INSERT INTO releverTemperature (id_releverTemperature, id_Chambre, date, heure,temperature)VALUES (NULL, %s, %s, %s, %s);"
        val = (self.idChambre,date,heure,msgTemp)
        self.mycursor.execute(sql, val)#Exécution de la requête
        self.mydb.commit()#Sauvegarde toutes les modifications

    def insertionAlerte(self,codeAlerte,date,heure):
        """
        DOCUMENTATION de insertionAlerte
        Méthode qui permet d'insérer dans la base de données l'enregistrement de l'alerte (valeur du code alerte, date, heure)
        Nécessitant trois paramètres :
        - le code d'alerte en booléen "1" => alerte porte , "2" => alerte température
        - la date en chaîne de caractères en format : 2022/02/20 (AAAA/MM/JJ)
        - l'heure en chaîne de caractères en heure : 13:00 (HH:MM)
        Exemple d'appel : monSQL.insertionAlerte(2,2022/02/20,12:00)
        """
        sql = "INSERT INTO alerte (ID_Chambre,code_alerte, dateAlerte, heureAlerte) VALUES (%s, %s, %s, %s);"
        val = (self.idChambre,codeAlerte,date,heure)
        self.mycursor.execute(sql, val)#Exécution de la requête  
        self.mydb.commit()#Sauvegarde toutes les modifications
        
    def insertionAcquittement(self,date,heure):
        """
        DOCUMENTATION de insertionAcquittement
        Méthode qui permet de mettre à jour le dernier enregistrement de l'alerte dans la base de données(date, heure)
        Nécessitant deux paramètres :
        - la date en chaîne de caractères en format : 2022/02/20 (AAAA/MM/JJ)
        - l'heure en chaîne de caractères en heure : 13:00 (HH:MM)
        Exemple d'appel : monSQL.insertionAcquittement(2022/02/20,12:00)
        """
        idAlerte = None
        requete = "SELECT MAX(id_alerte) FROM alerte WHERE ID_Chambre = "+str(self.idChambre)+" AND acquitement = 0;"
        self.mycursor.execute(requete)#Exécution de la requête
        #Récupère toutes les lignes de la dernière instruction exécutée.
        tab = self.mycursor.fetchall()
        for line in tab:
            idAlerte = line[0]
            
        if idAlerte != None :
            sql = "UPDATE alerte SET acquitement='1',dateAcquitement=%s,heureAcquitement=%s WHERE id_alerte = "+str(idAlerte)+";"
            val = (date,heure)
            self.mycursor.execute(sql, val)#Exécution de la requête
            self.mydb.commit()#Sauvegarde toutes les modifications
            #SELECT MAX(id_alerte) FROM alerte WHERE ID_Chambre = 8 AND acquitement = 0
            #UPDATE alerte SET acquitement='[value-6]',dateAcquitement='[value-7]',heureAcquitement='[value-8]' WHERE id_alerte = 2
            
    def selectionMail(self):
        """
        DOCUMENTATION de selectionMail
        Méthode qui permet de sélectionner le mail de toute les personnes
        Retourne-le ou les destinataire(s)
        Nécessitant aucun paramètre
        Exemple d'appel : listeDestinataire = monSQL.selectionMail()
        """
        #exécuter le curseur avec la méthode execute() et transmet la requête SQL
        self.mycursor.execute("SELECT DISTINCT mail FROM compte,role WHERE compte.idRole = role.idRole;")
        #Récupère toutes les lignes de la dernière instruction exécutée.
        tab = self.mycursor.fetchall()
        destinataire = ""#Initialisation en chaîne de caractères
        for line in tab: #Pour chaque ligne dans le tableau 
            if destinataire =="":#Si la variable "destinataire" est vide
                destinataire = line[0]
            else:#Sinon
                destinataire = destinataire+","+line[0]
        return destinataire #Retourne le ou les destinataire(s)
    # SELECT DISTINCT mail FROM compte,role WHERE compte.idRole = role.idRole AND role.recevoirEmail = 1 AND mail_verif = 1
    
    def selectionIdChambre(self,nomChambre):
        """
        DOCUMENTATION de selectionIdChambre
        Méthode qui permet de sélectionner l'id de la chambre en fonction du nom de la chambre
        Retourne l'idChambre
        Nécessitant un paramètre :
        - nom de la chambre en chaîne de caractères
        Exemple d'appel : idChambre = monSQL.selectionIdChambre(chambre 1)        
        """
        self.idChambre = None;
        #Exécuter le curseur avec la méthode execute() et transmet la requête SQL
        self.mycursor.execute("SELECT id_chambre FROM chambre_froide WHERE nom_chambre = \""+nomChambre+"\";")
        #print("SELECT id_chambre FROM chambre_froide WHERE nom_chambre = \""+nomChambre+"\";")
        #Récupère toutes les lignes de la dernière instruction exécutée.
        res = self.mycursor.fetchall() 
        for line in res: #Pour chaque ligne dans le tableau
            self.idChambre = line[0]
        return self.idChambre #Retourne l'id de la chambre
        #SELECT id_chambre FROM chambre_froide WHERE nom_chambre = "test"

    def selectionReglageAlerte(self,idChambre):
        """
        DOCUMENTATION de selectionReglageAlerte
        Méthode qui permet de sélectionner le réglage de l'alerte de la chambre
        Nécessitant un paramètre :
        - id de la chambre en entier
        Exemple d'appel : reglage = monSQL.selectionReglageAlerte(7) 
        """
        #Exécuter le curseur avec la méthode execute() et transmet la requête SQL
        self.mycursor.execute("SELECT MAX(reglageAlerte.id_reglageAlerte),temperatureMini,temperatureMax FROM reglageAlerte,chambre_froide WHERE reglageAlerte.ID_Chambre = chambre_froide.id_chambre AND chambre_froide.id_chambre = "+str(idChambre)+";")
        #Récupère toutes les lignes de la dernière instruction exécutée.
        res = self.mycursor.fetchall()
        for line in res:#Pour chaque ligne dans le tableau
            self.temperatureMini = line[1]
            self.temperatureMax = line[2]
        # SELECT MAX(reglageAlerte.id_reglageAlerte),temperatureMini,temperatureMax,intervalTemps FROM reglageAlerte,chambre_froide WHERE reglageAlerte.id_reglageAlerte = chambre_froide.id_reglageAlerte AND chambre_froide.id_chambre =     
    
    def getTempMini(self):
        """
        DOCUMENTATION de getTempMini
        Accesseur qui renvois la température minimum toléré de la chambre avant alerte
        Nécessitant aucun paramètre
        Exemple d'appel : tempMini = monSQL.getTempMini()
        """
        return self.temperatureMini #Retourne la température minimum 

    def getTempMax(self):
        """
        DOCUMENTATION de getTempMax
        Accesseur qui renvois la température maximum toléré de la chambre avant alerte
        Nécessitant aucun paramètre
        Exemple d'appel : tempMax = monSQL.getTempMax()
        """
        return self.temperatureMax #Retourne la température maximum 
