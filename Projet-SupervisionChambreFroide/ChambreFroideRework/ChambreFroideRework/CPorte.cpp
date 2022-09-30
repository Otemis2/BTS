#include <Arduino.h>
#include "CPorte.h"

/*
 CPorte::CPorte()
{
  //constructeur
}
*/

CPorte::CPorte(short pinPorte,short pinLed) //constructeur surchargé
{
  pinMode(pinPorte, INPUT);//capteur de porte (pin 2)
  pinMode (pinLed,OUTPUT);//déclaration de la Pin18 en sortie
  
  etatPorte = digitalRead(pinPorte);// Etat porte
  pinLED = pinLed;// Pin de la LED
  pinPORTE = pinPorte;// Pin de la porte
}

CPorte::~CPorte()
{
  //destructeur
}

bool CPorte::acquerirEtatPorte()
{ 
  etatPorte = digitalRead(pinPORTE);// Etat porte

  if (etatPorte==0)// Porte ouverte
  {
    digitalWrite(pinLED, HIGH);   // // allumer la LED (HIGH est le niveau de tension)
    delay(100); 
  }
  else
  {
    digitalWrite(pinLED, LOW);    // éteindre la LED en rendant la tension BASSE
    delay(100);// delai de 100ms
  }
  
  return etatPorte;// retourne etat de la porte
}
