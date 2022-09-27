#ifndef CHEADER_H
#define CHEADER_H

#include <string>

class CHeader
{

private:

    short exercice;
    short numExercice;
    short configMenu;

public:

    CHeader();
    ~CHeader();
    short getExercice();
    short getNumExercice();
    short getConfMenu();
    void setExercice(short exo);
    void setNumExercice(short numExo);
    void setConfMenu(short confMenu);
    std::string afficherMainMenu();
    std::string afficherConfigMenu();
    std::string afficherExerciceMenu();

};

#endif // CHEADER_H
