/*
#-----------------------------------------------------------------------
# Nom Fichier: CMorse.cpp
# Classe : CMorse
# Sujet : gestion de l'application Morse
# Version : 0.1
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "cmorse.h"
#include <fstream>
#include <string.h>

/*
# --------------------------------------
# Nom Procedure : CMorse
# Classe: CMorse
# Sujet : constructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur :
# Creation : 01/10/2021
# Mise a jour :
# ----------------------------------------
*/
CMorse::CMorse()
{
    messageClair=NULL;
    messageCode=NULL;

    strcpy (tCorrespondance[0],".-");
    strcpy (tCorrespondance[1],"-...");
    strcpy (tCorrespondance[2],"-.-.");
    strcpy (tCorrespondance[3],"-..");
    strcpy (tCorrespondance[4],".");
    strcpy (tCorrespondance[5],"..-.");
    strcpy (tCorrespondance[6],"--.");
    strcpy (tCorrespondance[7],"...-");
    strcpy (tCorrespondance[8],"..");
    strcpy (tCorrespondance[9],".---");
    strcpy (tCorrespondance[10],"-.-");
    strcpy (tCorrespondance[11],".-..");
    strcpy (tCorrespondance[12],"--");
    strcpy (tCorrespondance[13],"-.");
    strcpy (tCorrespondance[14],"---");
    strcpy (tCorrespondance[15],".--.");
    strcpy (tCorrespondance[16],"--.-");
    strcpy (tCorrespondance[17],".-.");
    strcpy (tCorrespondance[18],"...");
    strcpy (tCorrespondance[19],"-");
    strcpy (tCorrespondance[20],"..-");
    strcpy (tCorrespondance[21],"...-");
    strcpy (tCorrespondance[22],".--");
    strcpy (tCorrespondance[23],"-..-");
    strcpy (tCorrespondance[24],"-.--");
    strcpy (tCorrespondance[25],"--..");
}
/*
# --------------------------------------
# Nom Procedure : CMorse
# Classe: CMorse
# Sujet : Destructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur :
# Creation : 01/10/2021
# Mise a jour :
# ----------------------------------------
*/
CMorse::~CMorse()
{

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getMessageClaire
# Classe : CMorse
# Sujet : permettra de revoyer le message clair dans le qmainwindowmorse
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : messageClair:chaine de caractere ;
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
char* CMorse::getMessageClaire()
{
    return messageClair;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getMessageCode
# Classe : CMorse
# Sujet : permettra de revoyer le message code dans le qmainwindowmorse
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : messageCode:chaine de caractere ;
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
char* CMorse::getMessageCode()
{
    return messageCode;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setMessageClair
# Classe : CMorse
# Sujet : permettra de recuper le message clair dans le qmainwindowmorse et de le copier dans une variable privé
# Version : 0.1
# Entrees (in) : message: chaine de caractere
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void CMorse::setMessageClair(char* message)
{
    messageClair=new char[256];
    strcpy(messageClair,message);
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setMessageCode
# Classe : CMorse
# Sujet : permettra de recuper le message code dans le qmainwindowmorse et de le copier dans une variable privé
# Version : 0.1
# Entrees (in) : message: chaine de caractere
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void CMorse::setMessageCode(char* message)
{
    messageCode=new char[256];
    strcpy(messageCode,message);
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : codeMorse
# Classe : CMorse
# Sujet : permettra de coder le message et de renvoyer une confirmation
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# -----------------------------------------------------------------------

ALGORITHME :
Debut
    Réservation memoire de 255 octets
    pour l'attribut message code
    copier(messageCode,"");
    Si verifierMessageClaire= vrais ALORS
        i<- 0, len <-longeur(messageClaire)+1
        Pour i=0 à len FAIRE
            Si messageClaire[i]<> ' ' Alors
                concatener(messageCode,
                tCorrespondance[messageClaire[i]-'a'])
                concatener(messageCode," ")
            Sinon
                concatener(messageCode, " ")
            Fin Si
         Fin Pour
         retournr vrai
    Sinon
        concatener(messageCode," ")
        retourner faux
    Fin si
Fin
*/
bool CMorse::codeMorse()
{
    messageCode =new char[256];
    strcpy (messageCode, "");
    short i =0;
    short len;

    if(verifierMessageClair()==true)
    {

        len = strlen(messageClair);
        for(i =0; i<len; i++)
        {
            if(messageClair[i]!=' ')
            {
                strcat(messageCode,tCorrespondance[messageClair[i]-'A']);
            }
            strcat(messageCode," ");
        }
        return true;
    }
    else
    {
        strcat(messageCode,"Message invalide");
        return false;
    }
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : decoderMorse
# Classe : CMorse
# Sujet : permettra de decoder le message et de renvoyer une confirmation
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
Algo decoderMorse

var i,j,k, numeroLettre, len : entier court

trouve : booleen
lettre : chaine de caractère

Debut
    Réservation mémoire de 255 octects pour l'attribut messageCode
    copier(messageClaire,"");
    Si verifierMessageCode =  vrai ALORS
    i ,- 0 , j <- 0, numeroLettre <- 0, len <- longueur(message)
    POUR i = 0 à len FAIRE
        Si messageCode[i]<> ' 'ALORS
            lettre[j] <- message[i]
            j <- j +1
        SINON
            lettre[j]<-'\0'
            j <- 0
            k <- 0
            trouve <- faux
            REPETER
                Si (compare(lettre,tCorrespondance[k])=0)ALORS
                    trouve <- VRAI
                Sinon
                    k <- k+1
                FSI
            JUSQU'A (k=26)OU(trouve=VRAI)
            Si(trouve = VRAI)ALORS
                messageClaire[numeroLettre] <- 'a'+k
                numeroLettre <-numeroLettre+1
                k<-0
                Si(messageCode[i]=' ')ET(messageCode[i + 1]=' ')ALORS
                    messageClaire[numeroLettre]<-''
                    i <- i +1
                FSi
            SINON
                copier(messageClaire,"");
                retourner FAUX
            FSI
        FSI
    FPour
    messageClaire[i]<-'\0'
    retourner VRAI
    SINON
        concatener(messageCode,"")
        retourner FAUX
    FSi
Fin
*/
bool CMorse::decoderMorse()
{
    short i, j, k, numeroLettre, len;
    bool trouve;
    char* lettre = new char[255];
    messageClair = new char[255];
    strcpy(messageClair, "");
    strcpy(lettre,"");
    if (verifierMessageCode()==true)
    {
        i=0;
        j=0;
        numeroLettre=0;
        len=strlen(messageCode);
        for(i=0;i<len;i++)
        {
            if(messageCode[i]!=' ')
            {
                lettre[j]=messageCode[i];
                j=j+1;
            }
            else
            {
                lettre[j]='\0';
                j=0;
                k=0;
                trouve=false;
                do
                {
                    if(strcmp(lettre, tCorrespondance[k])==0)
                    {
                        trouve=true;
                    }
                    else
                    {
                        k=k+1;
                    }
                }while((k<26)&&(trouve==false));
                if(trouve==true)
                {
                    messageClair[numeroLettre] = 'A'+k;
                    numeroLettre=numeroLettre+1;
                    k=0;
                    if ((messageCode[i]==' ')&&(messageCode[i+1]==' '))
                    {
                        messageClair[numeroLettre]=' ';
                        i=i+1;
                    }
                }
                else
                {
                        strcpy(messageClair,"");
                        return false;
                }
            }
        }
        messageClair[i]='\0';
        return true;
    }
    else
    {
        strcat(messageCode,"");
        return false;
    }

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : verifierMessageClair
# Classe : CMorse
# Sujet : permettra de vérifier le message clair et de renvoyer une confirmation
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool CMorse::verifierMessageClair()
{
    char* copieMessage =new char[256];
    strcpy(copieMessage,messageClair);

    for (short i=0;i<=strlen(copieMessage);i++)
    {
        if (!(messageClair[i]>='A' && messageClair[i]<='Z'))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : verifierMessageCode
# Classe : CMorse
# Sujet : permettra de vérifier le message coder et de renvoyer une confirmation
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 01/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool CMorse::verifierMessageCode()
{
    char* copieMessage =new char[256];
    strcpy(copieMessage,messageCode);

    for (short i=0;i<strlen(copieMessage);i++)
    {
        if (!((messageCode[i]== '.')||(messageCode[i]=='-')))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
