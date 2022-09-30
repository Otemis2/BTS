#include <Arduino.h>
#include "CTemperature.h"
#include <OneWire.h>
#include <DallasTemperature.h> 

/*
CTemperature::CTemperature()
{ }//Constructeur
*/

CTemperature::CTemperature(int oneWireBUS)
{   
  oneWireBus = oneWireBUS;
  pinMode(oneWireBus, INPUT);//capteur de temp (pin 19)
}

CTemperature::~CTemperature()
{
}

float CTemperature::acquerirTemperatureChambre()
{
  
  // Configurer une instance OneWire pour communiquer avec tous les dispositifs OneWire.
  OneWire oneWire(oneWireBus);
  // Passer notre référence oneWire au capteur de température Dallas 
  DallasTemperature sensors(&oneWire);
  sensors.begin(); // Démarrer le capteur DS18B20
  sensors.requestTemperatures();
  
  temperatureChambre = sensors.getTempCByIndex(0);// On récupère la température
  
  //Serial.print(temperatureChambre);
  //Serial.print("\n");
  
  return temperatureChambre;// retourne la température
}
