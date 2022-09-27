/*
#---------------------------------------
#Programme : 7TempMoy
#Sujet : On veut calculer la temperature moyenne des 7 dernier jours
#Auteur : HUCK
#Date de création : 19/10/2020
#---------------------------------------
*/

#include <iostream>

using namespace std;

#include <stdio.h>
#define N 7 // Le 7 c'est le nombre de fois ou on demande la temp
main()
{
    int i;
    float temp, moyenne, total = 0;
    for (i = 0; i < N; i++) {
        cout <<"Entrer une temperature: ";
        scanf("%f", &temp);
        total += temp;
    }
    moyenne = total / N;
    cout <<" La moyenne est : " << moyenne <<endl;
}
/*
#include <stdio.h>
#define N 12
main()
{
    int i;
    float temp, moyenne, sigma = 0;
    for (i = 0; i < N; i++) {
        printf("rentrer une temperature:\t");
        scanf("%f", &temp);
        sigma += temp;
    }
    moyenne = sigma / N;
    printf("\n La moyenne est :\t%f\n", moyenne);
}
*/
