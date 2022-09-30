
#include <WiFi.h>// Permet a l'ESP de se connecter à internet 
#include <MQTT.h>// Permet à un objet d'envoyer et/ou de recevoir des messages.

#include "CAlerte.h"// Appel de la classe CAlerte 
#include "CPorte.h"// Appel de la classe CPorte
#include "CTemperature.h"// Appel de la classe CTemperature
#include "config.h"// Appel du module config

unsigned long intervalTemps = 10000;//(60*10) * 1000; //Interval de temps avant déclenchement de l'alarme sonore en ms
//(60x10) x 1000
//(60sx10min) x 1000 ms 

CAlerte Alerte(pinBuzzer,pinBpAcquittement,pinLed,intervalTemps);//Constructeur surcharher CAlerte
CPorte MaPorte(pinPorte,pinLed);//Constructeur surcharger CPorte
CTemperature TemperatureChambre(oneWireBus);//Constructeur surcharger CTemperature

int numMessage = 0;
String messageTemp; //variable qui contien la valeur de la température a envoyé
String messagePorte; //variable qui contien la valeur de l'état de la porte a envoyé
short codeAlerte = 0; // Donne le code de l'alerte
bool aquitter =0; // Permet l'acquittement lors d'une alerte

bool etatPorteAnterieure = MaPorte.acquerirEtatPorte();// Récupère l'état de la porte

unsigned long instant = millis();

WiFiClient net;// Instanciation de la classe WIFIClient
MQTTClient client;// Instanciation du client MQTT

void connect() {
  Serial.print("checking wifi...");// Verification du WiFi
  while (WiFi.status() != WL_CONNECTED)// Statut du WiFi
  {
    Serial.print(".");// Place des points toute les secondes 
    delay(1000);// delais de 1 seconde
  }

  Serial.print("\nconnectingMQTT...");// Connexion broker
  while (!client.connect("arduino", "public", "public")) 
  {
    Serial.print(".");// Place des points toute les secondes
    delay(1000);// delais de 1 seconde
  }

  Serial.println("\nconnected MQTT!");// Connecter au MQTT

  client.subscribe(nomChambre+String("/reglageAlerte"));//Souscription au topic reglageAlerte
  // client.unsubscribe("/hello");
}

void msgRecu(String &topic, String &payload)// Fonction d'accusé de récéption 
{
  Serial.println("incoming: " + topic + " - " + payload);// Affiche le message reçu
  short separateur = payload.indexOf(";");// Utilisation du ";" comme séparateur
  tempMini = payload.substring(0,separateur);// Messagde de la température mini
  tempMax = payload.substring(separateur+1);// Message de la température max
  Alerte.setTempAlerte(tempMini.toFloat(),tempMax.toFloat());// Mehtode pour mettre à jour les température mini et max
  // Note : N'utilisez pas le client dans le callback pour publier, s'abonner ou
  // se désinscrire car cela peut provoquer des blocages lorsque d'autres choses arrivent alors que
  // l'envoi et la réception d'accusés de réception. Au lieu de cela, modifiez une variable globale,
  // ou le pousser dans une file d'attente et le traiter dans la boucle après avoir appelé `client.loop()`.
}

void publication(float temperature,bool etatPorte)
{
	//-------------Publication------------------
  if (!client.connected()) 
    {
      connect();
    }
  
	messageTemp = String(temperature);// Permet d'afficher la température
	messagePorte = String(etatPorte);// Permet d'afficher l'etat de la porte

	aquitter = Alerte.getAcquittement();// 

	if (millis() > instant + 30000)//1000 = Toute les secondes 
	{
		String topicTemp=nomChambre+String("/temperature");
		instant=millis();
		String msgTemp = messageTemp;// Codage du message 
		client.publish(topicTemp, msgTemp, true, 0);//topic, message, retained, QoS

	}
	if(etatPorte != etatPorteAnterieure)
	{
		String topicPorte=nomChambre+String("/porte");
		etatPorteAnterieure = MaPorte.acquerirEtatPorte();
		String msgPorte = messagePorte;// Codage du message
		client.publish(topicPorte, msgPorte, true, 0);//topic, message, retained, QoS
	}
	if (aquitter == 1)// Bouton appuyé
	{
		String msgAcquittement = "1"; 
		client.publish(nomChambre+String("/acquittement"), msgAcquittement, true, 0);//topic, message, retained, QoS
	}
	//-------------FIN Publication------------------
}

void setup() {
  Serial.begin(115200);// Initialisation du moniteur serie à 115200
  WiFi.begin(ssid, pass);// Connexion au WiFi

  // Remarque : les noms de domaine locaux (par exemple "Computer.local" sous OSX) ne sont pas pris en charge.
  // par Arduino. Vous devez définir l'adresse IP directement.
  client.begin(ipBroker, net);// Connexion au broker
  client.onMessage(msgRecu);// fonction de la callback lors de l'envoi d'un message

  connect();

  String topicESP=nomChambre+String("/etatESP");
  client.publish(topicESP, "1", true, 0);//topic, message, retained, QoS
  Alerte.setTempAlerte(tempMini.toFloat(),tempMax.toFloat()); //Configuration des valeurs par défaut(tempMini,tempMax);
}

void loop() 
{

  client.loop();
  delay(10);  // <- corrige quelques problèmes de stabilité WiFi

  if (!client.connected()) 
  {
    connect();
  }
  
  float temperature = TemperatureChambre.acquerirTemperatureChambre();// Récupération de la température de la chambre
  bool etatPorte = MaPorte.acquerirEtatPorte();// Récupération de l'etat de la porte
  //Serial.print("etat porte "+String(etatPorte)+"\n");
  //Serial.print("temperature "+String(temperature)+"\n");
  
  //------Alerte-------
  codeAlerte = Alerte.verificationAlerte(temperature, etatPorte);
  if ((codeAlerte == 1)||(codeAlerte == 2))
  {
    Serial.print("Code Alerte : "+String(codeAlerte)+"\n");
    String msgAlerte = String(codeAlerte);// Codage du message
    client.publish(nomChambre+String("/Alerte"), msgAlerte, true, 0);//topic, message, retained, QoS
    //Alerte.alerte();// Déclanchement de l'alerte
	
	digitalWrite(pinLed, LOW);// Tention de la LED au niveau bas(LED eteint)
	bool etatBP=digitalRead(pinBpAcquittement);// Etat du bouton d'acquittement
	while(etatBP == LOW)// Etat du bouton et au niveau bas
	{
    
    if(codeAlerte == 1)
    {
        digitalWrite(14, HIGH);
    
        delayMicroseconds(10000);
    
        digitalWrite(14, LOW);
    
        delayMicroseconds(7000);

        digitalWrite(14, HIGH);
     }
        
    if(codeAlerte == 2)
    {
        digitalWrite(14, HIGH);

        delayMicroseconds(2000);

        digitalWrite(14, LOW);

        delayMicroseconds(5000);

        digitalWrite(14, HIGH);
    } 
		
		digitalWrite(pinLed, HIGH);   // allumer la LED (HIGH est le niveau de tension)
		delay(100);// Delai de 1ms
		etatBP=digitalRead(pinBpAcquittement);// Etat du bouton 
		
		temperature = TemperatureChambre.acquerirTemperatureChambre();
		etatPorte = MaPorte.acquerirEtatPorte(); 
    Serial.print("etat porte : "+String(etatPorte)+"\n");
    Serial.print("temperature : "+String(temperature)+"\n");
		publication(temperature,etatPorte);
	}
	if (etatBP == HIGH)
	{
		digitalWrite(pinLed, LOW);// éteindre la LED en rendant la tension BASSE
		delay(100);// Delai de 1ms
		codeAlerte =0;// Code alerte a 0 (Aucun alerte)
		Alerte.acquittement(etatBP);// Etat du bouton
   digitalWrite(14, LOW);
	}
	  
  }
  //------Publication-------
	publication(temperature,etatPorte);// Publication de la température et de l'etat de la porte
  Serial.print("\ntemperature : "+String(temperature));// Affichage de la temperature dans le moniteur serie
  Serial.print("\netatPorte : "+String(etatPorte));// Affichage  de l'etat de la porte dans le moniteur serie
}   
       
