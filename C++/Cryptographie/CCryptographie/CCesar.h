#ifndef CCESAR_H
#define CCESAR_H

class CCesar
{
private:
    char* messageClair;
    char* messageCode;
    char* cle;
    void nettoyerChaine(char* chaine);
    void mettreMajuscules(char* chaine);
    char coderCaractere(char car,char clef);
    char decoderCaractere(char car,char clef);

public:
    CCesar();
    ~CCesar();
    void setMessageClair(char* message);
    void setMessageCode(char* message);
    void setCle(char* clef);
    char* getMessageClair();
    char* getMessageCode();
    char* getCle();
    bool getCleValide();
    void coderMessage();
    void decoderMessage();
};

#endif // CCESAR_H
