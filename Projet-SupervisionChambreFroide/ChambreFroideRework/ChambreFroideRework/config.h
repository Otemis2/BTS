// Pin des différents capteur
extern short pinBuzzer = 14; //Buzzer (alarme sonore)
extern short pinBpAcquittement = 17; //Bouton d'acquittement
extern short pinLed = 18; //Led/Gyrophare (alarme visuel)
extern short pinPorte = 2; //capteur de porte
extern int oneWireBus = 19; //capteur de temperature

extern char nomChambre[] = "test2"; //nom de la chambre 
extern const char ipBroker[] = "10.3.141.1"; //Ip du broker
//Informations du point d'acces
extern const char ssid[] = "chambreFroide";//Nom du wifi 
extern const char pass[] = "TestChambre";//Mdp du wifi

extern String tempMini = "-130.25"; //température mini avant alerte
extern String tempMax = "130.25"; //température maxi avant alerte
