#include <iostream>
#include <string>

#include "CConfig.h"

using namespace std;

CConfig::CConfig()
{

    loadSleep = 1000;
    endSleep = 5000;
    colorAnswer = 12;
    colorText = 15;
    colorTitle = 10;

}


CConfig::~CConfig()
{

}


short CConfig::getLoadSleep()
{

    return loadSleep;

}


short CConfig::getEndSleep()
{

    return endSleep;

}


short CConfig::getColorAnswer()
{

    return colorAnswer;

}

short CConfig::getColorText()
{

    return colorText;

}

short CConfig::getColorTitle()
{

    return colorTitle;

}


void CConfig::setLoadSleep(short loadS)
{

        loadSleep = loadS;

}


void CConfig::setEndSleep(short loadE)
{

        endSleep = loadE;

}


void CConfig::setColorAnswer(short colorA)
{

        colorAnswer = colorA;

}

void CConfig::setColorTitle(short colorT)
{

        colorTitle = colorT;

}

void CConfig::setColorTxt(short colorTxt)
{

        colorText = colorTxt;

}


std::string CConfig::trouverColorAnswerTxt()
{

    string formatText1;

    if ( colorAnswer == 0 )
    {

        formatText1 = "Noir\0";

    }

    if ( colorAnswer == 1 )
    {

        formatText1 = "Bleu\0";

    }

    if ( colorAnswer == 2 )
    {

        formatText1 = "Vert\0";

    }

    if ( colorAnswer == 3 )
    {

        formatText1 = "Cyan\0";

    }

    if ( colorAnswer == 4 )
    {

        formatText1 = "Rouge\0";

    }

    if ( colorAnswer == 5 )
    {

        formatText1 = "Magenta\0";

    }

    if ( colorAnswer == 6 )
    {

        formatText1 = "Marron\0";

    }

    if ( colorAnswer == 7 )
    {

        formatText1 = "Gris Clair\0";

    }

    if ( colorAnswer == 8 )
    {

        formatText1 = "Gris Foncé\0";

    }

    if ( colorAnswer == 9 )
    {

        formatText1 = "Bleu Clair\0";

    }

    if ( colorAnswer == 10 )
    {

        formatText1 = "Vert Clair\0";

    }

    if ( colorAnswer == 11 )
    {

        formatText1 = "Cyan Clair\0";

    }

    if ( colorAnswer == 12 )
    {

        formatText1 = "Rouge Clair\0";

    }

    if ( colorAnswer == 13 )
    {

        formatText1 = "Magenta Clair\0";

    }

    if ( colorAnswer == 13 )
    {

        formatText1 = "Jaune\0";

    }

    if ( colorAnswer == 15 )
    {

        formatText1 = "Blanc\0";

    }

    return formatText1;


}


std::string CConfig::trouverColorTitleTxt()
{

    string formatText2;

    if ( colorTitle == 0 )
    {

        formatText2 = "Noir\0";

    }

    if ( colorTitle == 1 )
    {

        formatText2 = "Bleu\0";

    }

    if ( colorTitle == 2 )
    {

        formatText2 = "Vert\0";

    }

    if ( colorTitle == 3 )
    {

        formatText2 = "Cyan\0";

    }

    if ( colorTitle == 4 )
    {

        formatText2 = "Rouge\0";

    }

    if ( colorTitle == 5 )
    {

        formatText2 = "Magenta\0";

    }

    if ( colorTitle == 6 )
    {

        formatText2 = "Marron\0";

    }

    if ( colorTitle == 7 )
    {

        formatText2 = "Gris Clair\0";

    }

    if ( colorTitle == 8 )
    {

        formatText2 = "Gris Foncé\0";

    }

    if ( colorTitle == 9 )
    {

        formatText2 = "Bleu Clair\0";

    }

    if ( colorTitle == 10 )
    {

        formatText2 = "Vert Clair\0";

    }

    if ( colorTitle == 11 )
    {

        formatText2 = "Cyan Clair\0";

    }

    if ( colorTitle == 12 )
    {

        formatText2 = "Rouge Clair\0";

    }

    if ( colorTitle == 13 )
    {

        formatText2 = "Magenta Clair\0";

    }

    if ( colorTitle == 13 )
    {

        formatText2 = "Jaune\0";

    }

    if ( colorTitle == 15 )
    {

        formatText2 = "Blanc\0";

    }

    return formatText2;

}

std::string CConfig::trouverColorTextTxt()
{

    string formatText3;

    if ( colorText == 0 )
    {

        formatText3 = "Noir\0";

    }

    if ( colorText == 1 )
    {

        formatText3 = "Bleu\0";

    }

    if ( colorText == 2 )
    {

        formatText3 = "Vert\0";

    }

    if ( colorText == 3 )
    {

        formatText3 = "Cyan\0";

    }

    if ( colorText == 4 )
    {

        formatText3 = "Rouge\0";

    }

    if ( colorText == 5 )
    {

        formatText3 = "Magenta\0";

    }

    if ( colorText == 6 )
    {

        formatText3 = "Marron\0";

    }

    if ( colorText == 7 )
    {

        formatText3 = "Gris Clair\0";

    }

    if ( colorText == 8 )
    {

        formatText3 = "Gris Foncé\0";

    }

    if ( colorText == 9 )
    {

        formatText3 = "Bleu Clair\0";

    }

    if ( colorText == 10 )
    {

        formatText3 = "Vert Clair\0";

    }

    if ( colorText == 11 )
    {

        formatText3 = "Cyan Clair\0";

    }

    if ( colorText == 12 )
    {

        formatText3 = "Rouge Clair\0";

    }

    if ( colorText == 13 )
    {

        formatText3 = "Magenta Clair\0";

    }

    if ( colorText == 13 )
    {

        formatText3 = "Jaune\0";

    }

    if ( colorText == 15 )
    {

        formatText3 = "Blanc\0";

    }

    return formatText3;

}
