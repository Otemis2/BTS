/*
# -----------------------------------------------------------------------
# Nom Fichier : CMorse.h
# Classe : CMorse
# Sujet : gestion de l'application Morse
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef CMORSE_H
#define CMORSE_H

class CMorse
{
private:
    bool verifierMessageClair();
    bool verifierMessageCode();
    char* messageClair;
    char* messageCode;
    char tCorrespondance [26][5];

public :
    CMorse();
    ~CMorse();
    char* getMessageClaire();
    char* getMessageCode();
    void setMessageCode(char* message);
    void setMessageClair(char* message);
    bool codeMorse();
    bool decoderMorse();


};
















#endif // CMORSE_H
