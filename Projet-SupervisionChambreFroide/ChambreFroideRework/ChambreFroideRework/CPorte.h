#ifndef CPorte_h
#define CPorte_h

class CPorte// Classe de CPorte
{
  private:
  
  bool etatPorte;// Atribut de etatPorte en booléen  
  short pinLED;// Attribut de pinLED en short
  short pinPORTE;// Attribut de pinPORTE en short 
  
  public:
  
  //CPorte();//constructeur
  CPorte(short pinPorte,short pinLed);//constructeur avec passage de paramètre
  ~CPorte();//destructeur
  bool acquerirEtatPorte();// Fonction acquerirEtatPorte en booléen 

};
#endif
