#ifndef CAlerte_h
#define CAlerte_h

class CAlerte
{
  private:
  
  short etatAlerte;// Attribut de etatAlerte en booléen
  bool etatBPAcquittement;// Attribut de etatBPAcquittement en booléen
  
  float tempAlerteMini;// Attribut de tempAlerteMini en float
  float tempAlerteMax;// Attribut de tempAlerteMax en float
  
  unsigned long tempsActuel;// Attribut de tempsActuel en unsigned long
  unsigned long tempsPrecedent;// Attribut de tempsPrecedent en unsigned long
  unsigned long interval;// Attribut de interval en unsigned long

  short pinBUZZER;// Attribut de pinBUZZER en short
  short pinBpACQUITTEMENT;// Attribut de pinBpACQUITTEMENT en short 
  short pinLED;// Attribut de pinLED en short 
  
  public:
  
  //CAlerte();//constructeur
  CAlerte(short pinBuzzer,short pinBpAcquittement,short pinLed,unsigned long intervalTemps);//constructeur surchargé
  ~CAlerte();//destructeur
  
  //void playTone(int tone, int duration);
  //void playNote(char note, int duration);// Fonction de playTone ( BUZZER ) en void
  //void alerte();// Fonction alerte en void
  void acquittement(bool etatBP);// Fonctione acquittement en void
  bool getAcquittement();// Fonction de getAcquittement en booléen
  short verificationAlerte(float temperature, bool etatPorte);// Fonction de verificationAlerte en short
  void setTempAlerte(float temperatureAlerteMini,float temperatureAlerteMax);// Fonction de setTempAlerte en void

};
#endif
