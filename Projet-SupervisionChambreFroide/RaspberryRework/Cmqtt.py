##encodage: utf-8
from datetime import datetime
from Csql import CSql
from Cmail import CMail
import paho.mqtt.client as mqtt
from config import *

class CMqtt :
    """
    DOCUMENTATION de la classe CMqtt :
    Cette classe contient :
    - 1 accesseur getClient()
    - 3 méthodes :
    connecter(client, userdata, flags, rc)
    receptionnerMessageMQTT(clientMQTT, userdata, msg)
    envoyerReglageAlerte(nomChambre,TempMini,TempMax)
    
    Elle permet de se connecter à un broker mqtt , de recptionner et traiter des messages et en envoyer
    Elle est composée de 2 classes (CMail et CSql)
    
    Classe utiliser :
    CSql
    CMail
    paho.mqtt
    Documentation source :
    https://pypi.org/project/paho-mqtt/

    """
    #Initialisateur de la classe CMqtt
    def __init__(self):
        """
        Méthode d'initialisation de la classe CMail
        Nécessitant aucun paramètre
        Exemple d'appel : monMqtt = CMqtt()
        """
        self.mqttc = mqtt.Client() #Création d'un client mqtt
        print(ipBroker)
        self.mqttc.connect(ipBroker, 1883) #Connexion au broker MQTT
        self.monSQL = CSql(ipServeurBdd,bdd,utilisateur,mdpBdd) #Instancie la classe CSql
        self.monMail = CMail(monEmail,mdpMail) #Instancie la classe CMail
    
    def getClient(self):
        """
        DOCUMENTATION de getClient
        Accesseur qui renvoie le client 
        Nécessitant aucun paramètre :
        Exemple d'appel : client = monMqtt.getClient()
        """
        return self.mqttc #Retourne le client mqtt
        
    def connecter(self, client, userdata, flags, rc):#on_connect
        """
        DOCUMENTATION de connecter
        Méthode qui permet la souscription à un topic
        Nécessitant quatre paramètres :
        - client est une instance client pour un rappel 
        - userdata données d'utilisateur privées 
        - flags est un indicateur de réponse envoyés par le broker
        - rc correspond au résultat de la connexion
        Exemple d'appel : clientMqtt.on_connect = monMQTT.connecter
        """
        #print("Connected with result code "+str(rc))
        self.mqttc.subscribe("+/porte") #Souscription au topic porte
        self.mqttc.subscribe("+/temperature") #Souscription au topic temperature
        self.mqttc.subscribe("+/Alerte") #Souscription au topic Alerte
        self.mqttc.subscribe("+/acquittement") #Souscription au topic acquittement
        self.mqttc.subscribe("+/etatESP") #Souscription au topic etatESP
    
    def receptionnerMessageMQTT(self,clientMQTT, userdata, msg):#on_message
        """
        DOCUMENTATION de receptionnerMessageMQTT
        Méthode qui réceptionne un message du broker, puis le traite
        En fonction du nom de topic, enregistre les données dans la base de données ou envois un mail d'alerte ou envois des données dans un topic à l'aide d'autre méthode
        Nécessitant trois paramètres :
        - clientMQTT est une instance client pour un rappel 
        - userdata données d'utilisateur privées 
        - msg qui contient les messages renvoyer par le broker
        Exemple d'appel : clientMqtt.on_message = monMQTT.receptionnerMessageMQTT
        """
        # VAR 
            # nomTopic : chaine de caractere
            # message : chaine de caractere
            # msgContenu : chaine de caractere
            # date : chaine de caractere
            # heure : chaine de caractere
        # Debut
            # [...]
            # Si nomTopic = "porte" & nomTopic = "temperature"
                # message <- message.separer)(";")
                # msgContenu <- message[0]
                # date <- message[1]
                # heure <- message[2]
                # Si nomTopic = "porte"
                    # insertionPorte(msgContenu,date,heure)
            # FinSi
            # FinSi
            # [...]
            #Si nomTopic = "Alerte"
                # message <- message.split(';')
                # codeAlerte <- message[0]
                # date <- message[1]
                # heure <- message[2]
                # insertionAlerte(codeAlerte,date,heure)
                # adresse <- self.monSQL.selectionMail()
                # setTo(adresse)
                # setMessage(nomChambre,codeAlerte)
                # envoyerMail()
            # FinSi
        # Fin
        msgContenu="" #Initialisation en char
        date="" #Initialisation en char
        heure="" #Initialisation en char
        nomTopic ="" #Initialisation en char 
        codeAlerte = "" #Initialisation en char

        #print("Message received-> " + msg.topic + " " + str(msg.payload.decode("utf-8")))  # Affiche le message reçu 

        topic = msg.topic #Récupération du nom de topics
        message = msg.payload.decode("utf-8") #récupération du message reçu et décodage en UTF-8
        print(message)
        listeTopic = topic.split('/') #Sépare le nom du topic en deux
        
        nomChambre = listeTopic[0] #Premiere partie du topic nom de la chambre
        #print("SQL pour id de la chambre en fonction du nom")
        idChambre = self.monSQL.selectionIdChambre(nomChambre) #Récupére l'id de la chambre qui porte ce nom
        #print(idChambre)
        if idChambre != None:#Si l'id de la chambre est bien dans la base de donnée
            nomTopic = listeTopic[1] #Deuxième parti du topic le nom de celui-ci
            if nomTopic == "porte" or nomTopic == "temperature" or nomTopic == "Alerte" or nomTopic == "acquittement" or nomTopic == "etatESP":
                if nomTopic == "porte" or nomTopic == "temperature": #Si le topic se nomme porte ou température alors
                    msgContenu = message
                    date = str(datetime.now().date())#récupere la date
                    heure = str(datetime.now().time().isoformat(timespec='seconds'))#récupere l'heure
                   
                    if nomTopic == "porte" : #Si le nom du topic est "porte"
                        if msgContenu == "1" or msgContenu =="0":#Vérifie si le message est bien 0 ou 1
                            self.monSQL.insertionPorte(msgContenu, date, heure) #On insère dans la base de données
                    if nomTopic == "temperature": #Si le nom du topic est "temperature"
                        try:#Essayer
                            float(msgContenu)#convertir msgContenu en float
                            valid = True 
                        except ValueError:#Si il y a une erreur lors de la convertion
                            valid =  False
                        if valid == True:#Si valid est a true ALORS
                            self.monSQL.insertionTemperature(msgContenu, date, heure)#On insère dans la base de données
                        
                if nomTopic == "Alerte" : #Si le nom du topic est "Alerte"
                    #print("codeAlerte;Date;Heure")
                    codeAlerte = message
                    if codeAlerte =="1" or codeAlerte =="2":#Si le code d'alerte est 1 ou 2
                        date = str(datetime.now().date())
                        heure = str(datetime.now().time().isoformat(timespec='seconds'))
                        self.monSQL.insertionAlerte(codeAlerte,date,heure) #Insertion dans la base de données
                        adresse = self.monSQL.selectionMail() #Récupération des adresses emails qui peuvent recevoir un mail d'alerte
                        self.monMail.setTo(adresse) #Configuration de l'adresse de destinataire
                        self.monMail.setMessage(nomChambre,codeAlerte) #Configuration du message d'alerte
                        self.monMail.envoyerMail() #envois du mail

                if nomTopic == "acquittement" : #Si le nom du topic est acquittement
                    #print(type(message))
                    if message == "1":#Si le message envoyé est 1
                        date = str(datetime.now().date())
                        heure = str(datetime.now().time().isoformat(timespec='seconds'))
                        #print("Date;Heure : "+date+";"+heure)
                        self.monSQL.insertionAcquittement(date,heure) #Insertion dans la base de données
                    
                if nomTopic == "etatESP": #Si le nom du topic est etatESP
                    if message == "1":#Si le message envoyé est 1
                        #print("etatEsp")
                        #print(message)
                        self.monSQL.selectionReglageAlerte(idChambre) #Selectionne les réglages d'alerte de la chambre
                        TempMini = self.monSQL.getTempMini() #Récupère la température minimum
                        TempMax  = self.monSQL.getTempMax() #Récupère la température maximum
                        #print(TempMini,TempMax,IntervalTemps)
                        monMQTT = CMqtt()#Instancie la classe CMqtt
                        monMQTT.envoyerReglageAlerte(nomChambre,TempMini,TempMax) #envoie le réglage de la chambre à l'ESP

    def envoyerReglageAlerte(self,nomChambre,TempMini,TempMax):
        """
        DOCUMENTATION de envoyerReglageAlerte
        Méthode qui prépare le message à envoyer dans le topic "reglageAlerte" de la chambre qui a publié dans le topic "etatESP"
        Et publie le message
        Nécessitant trois paramètres :
        - nomChambre en chaîne de caractères qui contient le nom de la chambre 
        - TempMini en flottant qui contient le réglage de déclanchement de l'alerte minimum
        - TempMax en flottant qui contient le réglage de déclanchement de l'alerte maximum
        Exemple d'appel : monMQTT.envoyerReglageAlerte(chambre1,-4.01,0.25)
        """
        messageAEnvoyer = str(TempMini)+";"+str(TempMax) #Prépare le message
        #print(messageAEnvoyer)
        self.mqttc.connect(ipBroker, 1883) #Connexion au broker
        self.mqttc.publish(nomChambre+"/reglageAlerte", messageAEnvoyer) #Publie le message dans le broker


#help(CMqtt)
