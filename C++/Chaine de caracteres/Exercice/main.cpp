#include <iostream>
#include "Mesfonctions.h"
//#define "Mesfonctions.h"

using namespace std;

int main()
{

/*    //Minuscules en Majuscules
    char* chaine=new char[256];
    cout << "Saisir une chaine de caractere Minuscules" << endl;
    cin >> chaine;
    mettreMajuscules(chaine);
    cout<<chaine<<endl;

    //Majuscules en Minuscules
    cout << "Saisir une chaine de caractere Majuscules" << endl;
    cin >> chaine;
    mettreMinuscules(chaine);
    cout<<chaine<<endl;

    //Nettoyage des characteres
    cout << "Saisir une chaine de caractere avec plein de betise" << endl;
    cin >> chaine;
    nettoyerChaine(chaine);
    cout<<chaine<<endl;

    //determinerOcurence

    //Etre palindrome
    if (etrePalindrome(chaine))// c'est la meme chose que "if (etrePalindrome(chaine)==true)" cela fonctionne parce que c'est déjà un bool
    {
        cout<<"La chaine de caracteres saisie est un palindrome "<<endl;
    }
    else
    {
        cout<<"La chaine de caracteres saisie n'est pas un palindrome "<<endl;
    }
*/
    char motSecret[8]={"chapeau"};
    char motTrouve[8]={"*h**e*u"};
    char lettre;
    cout<<"Proposer une lettre "<<endl;
    cin>>lettre;
    if (proposer(motSecret,motTrouve,lettre)==true)
    {
        cout<<"La lettre proposee est dans le mot"<<endl;
    }
    else
    {
        cout<<"La lettre proposee n'est pas dans le mot"<<endl;
    }
    cout<<"mot a trouver "<<motTrouve<<endl;
return 0;
}

