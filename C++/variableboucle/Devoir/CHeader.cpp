#include <iostream>
#include <string>

#include "CHeader.h"

using namespace std;


CHeader::CHeader()
{

    exercice = 10;
    numExercice = 0;
    configMenu = 0;

}

CHeader::~CHeader()
{

}

short CHeader::getExercice()
{

    return exercice;

}

short CHeader::getNumExercice()
{

    return numExercice;

}

short CHeader::getConfMenu()
{

    return configMenu;

}

void CHeader::setExercice(short exo)
{

    exercice = exo;

}

void CHeader::setNumExercice(short numExo)
{

    numExercice = numExo;

}

void CHeader::setConfMenu(short confMenu)
{

    configMenu = confMenu;

}

std::string CHeader::afficherExerciceMenu()
{

    std::string backExercicesMenu;

    if (numExercice == 1)
    {

        std::cout << "#########################################" << std::endl;
        std::cout << "##             EXERCICE 1              ##" << std::endl;
        std::cout << "#########################################" << std::endl;

    }

    if (numExercice == 2)
    {

        std::cout << "#########################################" << std::endl;
        std::cout << "##             EXERCICE 2              ##" << std::endl;
        std::cout << "#########################################" << std::endl;

    }

    if (numExercice == 3)
    {

        std::cout << "#########################################" << std::endl;
        std::cout << "##             EXERCICE 3              ##" << std::endl;
        std::cout << "#########################################" << std::endl;

    }

    if (numExercice == 6)
    {

        std::cout << "#########################################" << std::endl;
        std::cout << "##             EXERCICE 6              ##" << std::endl;
        std::cout << "#########################################" << std::endl;

    }


    if (numExercice == 8)
    {

        std::cout << "#########################################" << std::endl;
        std::cout << "##             EXERCICE 8              ##" << std::endl;
        std::cout << "#########################################" << std::endl;

    }

    return backExercicesMenu;

}

std::string CHeader::afficherConfigMenu()
{

    std::string backConfigsMenu;

    if (configMenu == 0)
    {

        std::cout << "#####################################" << std::endl;
        std::cout << "##             Config              ##" << std::endl;
        std::cout << "#####################################" << std::endl << std::endl;

    }

    if (configMenu == 1)
    {

        std::cout << "#########################################" << std::endl;
        std::cout << "##              Config Edit            ##" << std::endl;
        std::cout << "#########################################" << std::endl << std::endl;

    }

    if (configMenu == 2)
    {

        std::cout << "##########################################" << std::endl;
        std::cout << "##             Loading Time             ##" << std::endl;
        std::cout << "##########################################" << std::endl << std::endl;

    }

    if (configMenu == 3)
    {

        std::cout << "##########################################" << std::endl;
        std::cout << "##              Ending Time             ##" << std::endl;
        std::cout << "##########################################" << std::endl << std::endl;

    }

    if (configMenu == 4)
    {

        std::cout << "##########################################" << std::endl;
        std::cout << "##              Texte Color             ##" << std::endl;
        std::cout << "##########################################" << std::endl << std::endl;

    }

    if (configMenu == 5)
    {

        std::cout << "##########################################" << std::endl;
        std::cout << "##             Answer Color             ##" << std::endl;
        std::cout << "##########################################" << std::endl << std::endl;

    }

    if (configMenu == 6)
    {

        std::cout << "##########################################" << std::endl;
        std::cout << "##              Title Color             ##" << std::endl;
        std::cout << "##########################################" << std::endl << std::endl;

    }

    return backConfigsMenu;

}

std::string CHeader::afficherMainMenu()
{
    std::string back;

    std::cout << "******************************************************" << std::endl;
    std::cout << " 1 | Exercice 1 (Nombre plus grand | Limite 20) " << std::endl;
    std::cout << " 2 | Exercice 2 (Nombre plus grand | Sans Limite) " << std::endl;
    std::cout << " 3 | Exercice 3 (Table de Multiplication) " << std::endl;
    std::cout << " 4 | Exercice 4 () " << std::endl;
    std::cout << " 5 | Exercice 5 () " << std::endl;
    std::cout << " 6 | Exercice 6 (Juste Prix) " << std::endl;
    std::cout << " 7 | Exercice 7 () " << std::endl;
    std::cout << " 8 | Exercice 8 () " << std::endl;
    std::cout << " 9 | Exercice 9 (Solution equation second degr\x82) " << std::endl;
    std::cout << "10 | Config (Acc" << "\x82" << "der \x85 la config) " << std::endl;
    std::cout << " 0 | Exit" << std::endl;
    std::cout << "******************************************************" << std::endl << std::endl;

    std::cout << "Quels choix voulez vous faire => ";

    return back;

}
