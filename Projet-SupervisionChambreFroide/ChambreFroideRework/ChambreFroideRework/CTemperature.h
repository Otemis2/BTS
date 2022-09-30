#ifndef CTemperature_h
#define CTemperature_h

class CTemperature// Classe de CTemperature
{
  private:
  
  int oneWireBus;// Atribut de oneWireBus en int
  float temperatureChambre;// Attribut de temperatureChambre en float 
  
  public:
  
  //CTemperature();//constructeur
  CTemperature(const int oneWireBus);//constructeur avec passage de paramètre
  ~CTemperature();//destructeur
  float acquerirTemperatureChambre();//Fonction de acquerirTemperatureChambre en float


};
#endif
