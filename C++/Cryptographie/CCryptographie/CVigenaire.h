#ifndef CVIGENAIRE_H
#define CVIGENAIRE_H


class CVigenaire
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
    CVigenaire();
    ~CVigenaire();
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

#endif // CVIGENAIRE_H
