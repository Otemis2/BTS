#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "ccraps.h"
using namespace std;
//Constructeur
CCraps::CCraps()
{
    srand(time(NULL));
    //initialise la fonction rand
}
//d�structeur

CCraps::~CCraps()
{

}
//lancerDes
unsigned short CCraps::lancerDes()
{
    unsigned short de1,de2,deuxDes;
    //de1 al�atoire entre 1 et 6
    //de2 al�atoire entre 1 et 6
    de1 = rand()%6 +1;
    de2 = rand()%6 +1;
    deuxDes = de1+de2;
    return deuxDes;

}
