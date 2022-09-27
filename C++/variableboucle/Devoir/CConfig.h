#ifndef CCONFIG_H
#define CCONFIG_H

#include <string>

class CConfig
{

private:

    short loadSleep;
    short endSleep;
    short colorAnswer;
    short colorText;
    short colorTitle;

public:

    CConfig();
    ~CConfig();
    short getLoadSleep();
    short getEndSleep();
    short getColorAnswer();
    short getColorText();
    short getColorTitle();
    void setLoadSleep(short loadS);
    void setEndSleep(short loadE);
    void setColorAnswer(short colorA);
    void setColorTxt(short colorTxt);
    void setColorTitle(short colorT);
    std::string trouverColorAnswerTxt();
    std::string trouverColorTitleTxt();
    std::string trouverColorTextTxt();

};

#endif // CCONFIG_H
