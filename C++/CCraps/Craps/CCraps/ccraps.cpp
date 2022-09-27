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
//déstructeur

CCraps::~CCraps()
{

}
//lancerDes
unsigned short CCraps::lancerDes()
{
    unsigned short de1,de2,deuxDes;
    //de1 aléatoire entre 1 et 6
    //de2 aléatoire entre 1 et 6
    de1 = rand()%6 +1;
    de2 = rand()%6 +1;
    deuxDes = de1+de2;
    return deuxDes;

}
