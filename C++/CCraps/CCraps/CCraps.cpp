
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "CCraps.h"
using namespace std;

CCraps::CCraps()
{
    srand(time(NULL));
    //initialise la fonction rand
}

CCraps::~CCraps()
{

}

unsigned short CCraps::lancerDes()
{
    unsigned short de1;
    unsigned short de2;

    de1 = rand()%6 +1;
    de2 = rand()%6 +1;
    return de1+de2;

}
