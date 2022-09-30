#include <Arduino.h>
#include "CAlerte.h"


/*
CAlerte::CAlerte()
{  
}
*/

CAlerte::CAlerte(short pinBuzzer,short pinBpAcquittement,short pinLed,unsigned long intervalTemps)
{
  pinBUZZER = pinBuzzer;// Numéro du pin correspondant au buzzer
  pinBpACQUITTEMENT = pinBpAcquittement;// Numéro du pin correspondant au bouton d'acquittement 
  pinLED = pinLed;// Numéro du pin qui correspond à la LED

  pinMode (pinLED,OUTPUT);//déclaration de la Pin18 en sortie
  pinMode (pinBpACQUITTEMENT,INPUT);//déclaration de la Pin17 en entrée
  pinMode (pinBUZZER,OUTPUT);//déclaration de la Pin14 en sortie

  etatBPAcquittement=digitalRead(pinBpAcquittement);// lit l'état du bouton 
  digitalWrite(pinLed,LOW);// Eteint la LED

  tempsActuel = millis();// millis depuit le démarrage de l'ESP 
  tempsPrecedent = 0;// Temps précédent quand il y a changement d'état
  interval = intervalTemps;// Intervale de temps depuis l'ouverture de la porte
  
  etatAlerte = 0;// Pas d'alerte
  
}

CAlerte::~CAlerte()
{
}
/*
void CAlerte::alerte()
{
 
  digitalWrite(pinLED, LOW);
  bool etatBP=digitalRead(pinBpACQUITTEMENT);
  while(etatBP == LOW)
  {
    for (short i=0; i<7;i++)
    {
      digitalWrite(pinBUZZER, HIGH); 
      delayMicroseconds((i*500));
      digitalWrite(pinBUZZER, LOW); 
      delayMicroseconds((i*500));
    }
     
    digitalWrite(pinLED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100); 
    etatBP=digitalRead(pinBpACQUITTEMENT);
  }
  if (etatBP == HIGH)
  {
      digitalWrite(pinLED, LOW);    // turn the LED off by making the voltage LOW
      delay(100);
      etatAlerte =0;
      acquittement(etatBP);
  }
}
*/

short CAlerte::verificationAlerte(float temperature, bool etatPorte)
{
  etatAlerte =0;  
  etatBPAcquittement = digitalRead(pinBpACQUITTEMENT);// Lit l'état du bouton
  //Serial.print(String(temperature)+"<="+String(tempAlerteMini)+"||"+String(tempAlerteMax)+"\n");
  if((temperature<= tempAlerteMini)||(temperature>=tempAlerteMax))// Si la température est inférieur au mini ou suppérieur au max
  { 
    etatAlerte =1;// Activé l'alarme
  }

  tempsActuel = millis();// Temps  depuis que l'ESP est allumé
  if (etatPorte==1)// Si la porte est fermer
  {
    tempsPrecedent = tempsActuel;// Reset du temps actuel
  }

  if((etatPorte ==0)&&((tempsActuel - tempsPrecedent) >= interval))// Si la porte est ouverte et suppérieur à l'interval de temps
  {
    tempsPrecedent =tempsActuel;// Reset du temps précédentS
    etatAlerte =2;// Code alerte de la porte
  }
  return etatAlerte;// retourne l'état Alerte
}

void CAlerte::setTempAlerte(float temperatureAlerteMini,float temperatureAlerteMax)
{
  tempAlerteMini = temperatureAlerteMini;//
  tempAlerteMax = temperatureAlerteMax;
}

void CAlerte::acquittement(bool etatBP)// 
{
  etatBPAcquittement = etatBP;// Etat du bouton
}

bool CAlerte::getAcquittement()
{
  return etatBPAcquittement;// Rtourne état acquittement
}
