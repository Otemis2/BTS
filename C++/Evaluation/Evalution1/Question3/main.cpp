/*
#---------------------------------------
#Programme : Volume
#Sujet : Calculer le volume d'une sphere a l'aide de son rayon
#Auteur : HUCK Sylvain
#Date de création : 28/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
Variable : rayon, volume : réels
Const : PI

Début
PI <- 3,14
Afficher " Veuliez saisir le rayon de la sphère "
Saisir rayon
volume <- 4/3*PI*(rayon*rayon*rayon)
Afficher "Le volume est de ", volume, " metre cube "
Fin
#Tests
rayon volume
2     33.4933
6.14  969.11
*/
int main()
{
    float rayon,volume;

    const float PI = 3.14;

    cout << "Veuliez saisir le rayon de la sphere"<<endl;
    cin >> rayon;
    volume = 4*PI *(rayon*rayon*rayon)/3;
    cout <<  "Le volume est de "<<volume<<" metre cube "<<endl;
    return 0;

}
