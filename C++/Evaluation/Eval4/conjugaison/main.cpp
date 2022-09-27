#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>

using namespace std;

int main()
{
    char verbe [27] ;
    char *adverbefin ;
    char* er = "er";
    char *terminaison[6] = {"ai", "as", "a", "ons", "ez", "ont" } ;
    char * pronom[6] = {"Je_", "Tu_", "Il_", "Nous_", "Vous_", "Ils_"} ;
    int i;
    do{
    cout << "donnez un verbe du premier groupe : " <<endl ;
    cin >> verbe ;
    adverbefin = verbe  + strlen(verbe) - 2 ;
    }while ( strcmp (adverbefin, "er") ) ;
    cout <<"Indicatif present : "<<endl;
    for (i=0 ; i<6 ; i++){

    cout << pronom[i] << verbe <<terminaison[i]<<endl;
    }
    return 0;
}
//printf ("%s %s\n",



