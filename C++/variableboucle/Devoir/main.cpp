/*
*************************************
    Programme : Exercices
    Rôle : Exercices Boucles
    Créateur : Noah Louis
    Date de création : 05/10/2020
*************************************
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <string>

#include "CConfig.h"
#include "CHeader.h"

using namespace std;

CConfig maConfig;
CHeader header;

short loadSleep = maConfig.getLoadSleep();
short endSleep = maConfig.getEndSleep();
short colorTitle = maConfig.getColorTitle();
short colorAnswer = maConfig.getColorAnswer();
short colorText = maConfig.getColorText();
short numExercices = 0;
short configMenu;

std::string colorTextTxt = maConfig.trouverColorTextTxt();
std::string colorAnswerTxt = maConfig.trouverColorAnswerTxt();
std::string colorTitleTxt = maConfig.trouverColorTitleTxt();

int main()
{

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);


    short choix;
    short choice;

    system("COLOR 0F");

    system("CLS");
    std::cout << "Chargement en cours... ... ... ..." << std::endl;;
    Sleep(loadSleep);
    system("CLS");

    SetConsoleTextAttribute(color, colorTitle);
    std::cout << header.afficherMainMenu();

    std::cin >> choix;

    header.setExercice(choix);
    choice = header.getExercice();

    if (choice == 1)
    {

        float number;
        float numberStock = -32768;
        float countNumber = 1;
        float position;

        numExercices = 1;

        header.setNumExercice(numExercices);

        while (countNumber <= 20)
        {
            system("CLS");

            SetConsoleTextAttribute(color, colorTitle);
            std::cout << header.afficherExerciceMenu();

            SetConsoleTextAttribute(color, colorText);
            std::cout << "Veuillez entrez la valeur du nombre " << countNumber << " >> ";
            std::cin >> number;

            if (number > numberStock)
            {

                numberStock = number;
                position = countNumber;

            }

            countNumber = countNumber + 1;
        }

        system("CLS");

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << header.afficherExerciceMenu();

        SetConsoleTextAttribute(color, colorText);
        std::cout << "Le nombre le plus grand est >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << numberStock << std::endl;
        SetConsoleTextAttribute(color, colorText);
        std::cout << "Il \x85 \x82tait rentr\x82 en >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << position;
        SetConsoleTextAttribute(color, colorText);
        std::cout << " \x8Ame(s) position(s)" << std::endl;
        Sleep(endSleep);

        return main();
    }

    if (choice == 2)
    {

        double long i, nb0, nb, position, nbStock;

        i = 1;
        nbStock = -32768;
        nb0 = -32768;

        system("CLS");

        numExercices = 2;

        header.setNumExercice(numExercices);

        while (nb0 != 0)
        {
            system("CLS");

            SetConsoleTextAttribute(color, colorTitle);
            std::cout << header.afficherExerciceMenu();

            SetConsoleTextAttribute(color, colorText);
            std::cout << "Veuillez entrez la valeur du nombre " << i << " >> ";
            std::cin >> nb;

            if (nb > nbStock)
            {

                nbStock = nb;
                position = i;

            }

            i = i+1;
            nb0 = nb;

        }

        system("CLS");

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << header.afficherExerciceMenu();

        SetConsoleTextAttribute(color, colorText);
        std::cout << "Le nombre le plus grand est >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << nbStock << std::endl;
        SetConsoleTextAttribute(color, colorText);
        std::cout << "Il \x85 \x82tait rentr\x82 en >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << position;
        SetConsoleTextAttribute(color, colorText);
        std::cout << " \x8Ame(s) position(s)" << std::endl;
        Sleep(endSleep);

        return main();

    }

    if (choice == 3)
    {
        short i, nbMult;
        float mult, result;

        i = 0;

        system("CLS");

        numExercices = 3;

        header.setNumExercice(numExercices);

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << header.afficherExerciceMenu();

        SetConsoleTextAttribute(color, colorText);
        std::cout << "Veuillez entrer la table que vous voulez >> ";
        std::cin >> mult;

        system("CLS");

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << header.afficherExerciceMenu();

        SetConsoleTextAttribute(color, colorText);
        std::cout << "Jusque combien voulez vous aller >> ";
        std::cin >> nbMult;

        system("CLS");

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << header.afficherExerciceMenu();


        while (i != nbMult+1)
        {

            result = mult * i;


            std::cout << "| " << mult << " * " << i << " | Resultat | " << result << " |" << endl;

            i = i+1;

        }

        system("PAUSE");

        return main();
    }

    if (choice == 6)
    {

        srand(time(NULL));
        short hidden, value;

        hidden = rand() %1000 + 1;

        system("CLS");

        numExercices = 6;

        while (value != hidden)
        {

            system("CLS");

            header.setNumExercice(numExercices);

            SetConsoleTextAttribute(color, colorTitle);
            std::cout << header.afficherExerciceMenu();

            SetConsoleTextAttribute(color, colorText);
            std::cout << std::endl << "Bienvenue sur le juste prix veuillez entrez une valeur et essayer de gagner !!!!!" << std::endl << std::endl;
            std::cout << "Qu'elle est votre nombre ? >> ";
            std::cin >> value;

            if (value < hidden)
            {

                std::cout << "Le nombre est plus elev\x82 ! Vous ferez mieux la prochaine fois !" << std::endl;

            }

            if (value > hidden)
            {

                std::cout << "Le nombre est plus bas ! Vous ferez mieux la prochaine fois !" << std::endl << std::endl;

            }

            if (value == hidden)
            {

                std::cout << "Bien jou\x82 vous avez trouv\x82\ le bon nombre ! ... ... ... ... Vous n'avez rien gagn\x82 :,) !" << std::endl << std::endl;
                std::cout << "Le nombre \x82tait >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << hidden << std::endl << std::endl;

            }

            system("PAUSE");

        }

        return main();

    }

    if (choice == 9)
    {

        /*

          VAR : a, b, c, result1, result2, delta
          Debut

          Afficher "Veuillez entrer la valeur de 'a' >> "
          Saisir a
          Afficher "Veuillez entrer la valeur de 'b' >> "
          Saisir b
          Afficher "Veuillez entrer la valeur de 'c' >> "
          Saisir c

          delta = (b * b) - (4 * a * c);

          Si delta > 0

            Afficher "L'équation admet deux solutions"

            result1 = ( -b - racine(delta) ) / ( 2 * a );
            result2 = ( -b + racine(delta) ) / ( 2 * a );

            Afficher result1
            Afficher result2

          fin Si

          Si delta = 0

            Afficher "L'équation admet une solutions double"

            result1 = ( -b ) ) / ( 2 * a );

            Afficher result1

          fin Si

          Si delta < 0

            Afficher "L'équation admet aucune solutions"

          fin Si

          FIN

          #Tests

          A     B     C         Result1     Result2
          1     2     3         rien        rien
          1     2     -3        -3          1
          -2    4     -2        1           rien

        */

        system("CLS");

        float a, b, c, delta, result1, result2;

        numExercices = 8;

        header.setNumExercice(numExercices);

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << header.afficherExerciceMenu();

        SetConsoleTextAttribute(color, colorText);
        std::cout << std::endl << "Veuillez entrer la valeur de 'a' >> ";
        std::cin >> a;

        system("CLS");

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << header.afficherExerciceMenu();

        SetConsoleTextAttribute(color, colorText);
        std::cout << std::endl << "Veuillez entrer la valeur de 'b' >> ";
        std::cin >> b;

        system("CLS");

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << header.afficherExerciceMenu();

        SetConsoleTextAttribute(color, colorText);
        std::cout << std::endl << "Veuillez entrer la valeur de 'c' >> ";
        std::cin >> c;

        delta = (b * b) - (4 * a * c);

        if ( delta > 0 )
        {
            system("CLS");

            result1 = ( -b - sqrt(delta) ) / ( 2 * a);
            result2 = ( -b + sqrt(delta) ) / ( 2 * a);

            SetConsoleTextAttribute(color, colorTitle);
            std::cout << header.afficherExerciceMenu();

            SetConsoleTextAttribute(color, colorText);
            cout << std::endl << "L'\x82quation admet 2 solutions >>" << std::endl << std::endl;

            std::cout << "Solution 1 >> ";

            SetConsoleTextAttribute(color, colorAnswer);
            std::cout << result1 << std::endl << std::endl;

            SetConsoleTextAttribute(color, colorText);
            std::cout << "Solution 2 >> ";

            SetConsoleTextAttribute(color, colorAnswer);
            std::cout << result2 << std::endl;

        }

        if ( delta < 0 )
        {

            system("CLS");

            SetConsoleTextAttribute(color, colorTitle);
            std::cout << header.afficherExerciceMenu();

            SetConsoleTextAttribute(color, colorText);
            std::cout << std::endl << "L'\x82quation admet aucune solution !" << std::endl;

        }

        if ( delta == 0 )
        {

            system("CLS");

            result1 = ( -b ) / ( 2 * a );

            SetConsoleTextAttribute(color, colorTitle);
            std::cout << header.afficherExerciceMenu();

            SetConsoleTextAttribute(color, colorText);
            std::cout << std::endl << "L'\x82quation admet 1 solution double >>";

            std::cout << std::endl << "Solution >> ";

            SetConsoleTextAttribute(color, colorAnswer);
            std::cout << result1 << std::endl;

        }

        system("PAUSE");

        return main();

    }

    if (choice == 10)
    {

        configMenu = 0;
        string configChange;

        system("CLS");

        header.setConfMenu(configMenu);

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << header.afficherConfigMenu();


        std::cout << "         | TEMPS D'ATTENTES |        " << std::endl << std::endl;

        SetConsoleTextAttribute(color, colorText);
        std::cout << "Le temps de chargement >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << loadSleep / 1000 << " seconde(s)" << std::endl;
        SetConsoleTextAttribute(color, colorText);
        std::cout << "Le temps de fin de programme >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << endSleep / 1000 << " seconde(s)" << std::endl << std::endl;

        SetConsoleTextAttribute(color, colorTitle);
        std::cout << "             | COULEURS |            " << std::endl << std::endl;

        SetConsoleTextAttribute(color, colorText);
        std::cout << "Couleur du text >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << colorText;
        SetConsoleTextAttribute(color, colorText);
        std::cout << " soit >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << colorTextTxt << std::endl;
        SetConsoleTextAttribute(color, colorText);
        std::cout << "Couleur des r" << "\x82" << "ponses >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << colorAnswer;
        SetConsoleTextAttribute(color, colorText);
        std::cout << " soit >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << colorAnswerTxt << std::endl;
        SetConsoleTextAttribute(color, colorText);
        std::cout << "Couleur des titres >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << colorTitle;
        SetConsoleTextAttribute(color, colorText);
        std::cout << " soit >> ";
        SetConsoleTextAttribute(color, colorAnswer);
        std::cout << colorTitleTxt << std::endl << std::endl;

        SetConsoleTextAttribute(color, colorText);
        std::cout << "Voulez vous changer la config [y/n] >> ";
        std::cin >> configChange;

        if (configChange == "y")
        {

            configMenu = 1;

            short typeConfig;

            system("CLS");

            header.setConfMenu(configMenu);

            SetConsoleTextAttribute(color, colorTitle);
            std::cout << header.afficherConfigMenu();

            SetConsoleTextAttribute(color, colorAnswer);
            std::cout << "         | TEMPS D'ATTENTES |        " << std::endl << std::endl;

            SetConsoleTextAttribute(color, colorText);
            std::cout << "1 | Temps de chargement" << std::endl;
            std::cout << "2 | Temps de fin de programme " << std::endl << std::endl;

            SetConsoleTextAttribute(color, colorAnswer);
            std::cout << "             | COULEURS |            " << std::endl << std::endl;

            SetConsoleTextAttribute(color, colorText);
            std::cout << "3 | Couleur du Texte " << std::endl;
            std::cout << "4 | Couleur des R" << "\x82" << "ponses " << std::endl;
            std::cout << "5 | Couleur des Titres" << std::endl;
            std::cout << "0 | Exit" << std::endl << std::endl;

            SetConsoleTextAttribute(color, colorText);
            std::cout << "Quels est votre choix >> ";
            std::cin >> typeConfig;

            switch (typeConfig)
            {

            case 1:

                configMenu = 2;

                system("CLS");

                header.setConfMenu(configMenu);

                SetConsoleTextAttribute(color, colorTitle);
                std::cout << header.afficherConfigMenu();

                SetConsoleTextAttribute(color, colorText);
                std::cout << "Le temps actuel est de >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << loadSleep / 1000 << " seconde(s)" << std::endl << std::endl;

                SetConsoleTextAttribute(color, colorText);
                std::cout << "Veuillez rentrer un temps en secondes >> ";
                std::cin >> loadSleep;

                maConfig.setLoadSleep(loadSleep);

                loadSleep = loadSleep * 1000;

                Sleep(1000);
                SetConsoleTextAttribute(color, colorText);
                std::cout << "Le nouveau temps a bien \x82tait mis \x85 jour >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << loadSleep / 1000 << " secondes(s)" << std::endl;
                Sleep(2000);

                break;
            case 2:

                configMenu = 3;

                system("CLS");

                header.setConfMenu(configMenu);

                SetConsoleTextAttribute(color, colorTitle);
                std::cout << header.afficherConfigMenu();

                SetConsoleTextAttribute(color, colorText);
                std::cout << "Le temps actuel est de >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << endSleep / 1000 << " seconde(s)" << std::endl << std::endl;

                SetConsoleTextAttribute(color, colorText);
                std::cout << "Veuillez rentrer un temps en secondes >> ";
                std::cin >> endSleep;
                endSleep = endSleep * 1000;

                maConfig.setEndSleep(endSleep);

                Sleep(1000);
                SetConsoleTextAttribute(color, colorText);
                std::cout << "Le nouveau temps a bien \x82tait mis \x85 jour >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << endSleep / 1000 << " seconde(s)" << std::endl;
                Sleep(2000);
                break;
            case 3:

                configMenu = 4;

                system("CLS");

                header.setConfMenu(configMenu);

                SetConsoleTextAttribute(color, colorTitle);
                std::cout << header.afficherConfigMenu();

                SetConsoleTextAttribute(color, colorText);
                std::cout << "La couleur actuelle est >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << colorText << " soit " << colorTextTxt << std::endl << std::endl;

                SetConsoleTextAttribute(color, colorText);
                std::cout << "Veuillez entrer le num\x82ro de la couleur souhait\x82 >> ";
                std::cin >> colorText;

                maConfig.setColorTxt(colorText);
                colorTextTxt = maConfig.trouverColorTextTxt();

                Sleep(1000);
                SetConsoleTextAttribute(color, colorText);
                std::cout << "La nouvelle couleur a \x82tait mise \x85 jour >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << colorText << " soit " << colorTextTxt << std::endl;
                Sleep(2000);
                break;
            case 4:

                configMenu = 5;

                system("CLS");

                header.setConfMenu(configMenu);

                SetConsoleTextAttribute(color, colorTitle);
                std::cout << header.afficherConfigMenu();

                SetConsoleTextAttribute(color, colorText);
                std::cout << "La couleur actuelle est >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << colorAnswer << " soit " << colorAnswerTxt << std::endl << std::endl;

                SetConsoleTextAttribute(color, colorText);
                std::cout << "Veuillez entrer le num\x82ro de la couleur souhait\x82 >> ";
                std::cin >> colorAnswer;

                maConfig.setColorAnswer(colorAnswer);
                colorAnswerTxt = maConfig.trouverColorAnswerTxt();

                Sleep(1000);
                SetConsoleTextAttribute(color, colorText);
                std::cout << "La nouvelle couleur a \x82tait mise \x85 jour >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << colorAnswer << " soit " << colorAnswerTxt << std::endl;
                Sleep(2000);
                break;
            case 5:

                configMenu = 6;

                system("CLS");

                header.setConfMenu(configMenu);

                SetConsoleTextAttribute(color, colorTitle);
                std::cout << header.afficherConfigMenu();

                SetConsoleTextAttribute(color, colorText);
                std::cout << "La couleur actuelle est >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << colorTitle << " soit " << colorTitleTxt << std::endl << std::endl;

                SetConsoleTextAttribute(color, colorText);
                std::cout << "Veuillez entrer le num\x82ro de la couleur souhait\x82 >> ";
                std::cin >> colorTitle;

                maConfig.setColorTitle(colorTitle);
                colorTitleTxt = maConfig.trouverColorTitleTxt();

                Sleep(1000);
                SetConsoleTextAttribute(color, colorText);
                std::cout << "La nouvelle couleur a \x82tait mise \x85 jour >> ";
                SetConsoleTextAttribute(color, colorAnswer);
                std::cout << colorTitle << " soit " << colorTitleTxt << std::endl;
                Sleep(2000);
                break;
            case 0:
                break;

            }

        return main();


        }

        if (configChange == "n")
        {

            return main();

        }

    }
}

