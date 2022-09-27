#include <iostream>

using namespace std;

int main()
{
    short minute , decompte;

    cout << "veulliez saisir les minutes et les secondes du compte a rebourd"<<endl;
    cout << "veulliez saisir les minutes "<<endl;
    cin >> minute;
    cout << "veulliez saisir les secondes du compte a rebourd"<<endl;
    cin >> decompte;

    decompte = decompte + (minute * 60);



        while (decompte != 0)
        {

            minute = (decompte / 60);
            decompte =  (decompte % 60);
            cout << minute << " min " << decompte << "s"<<endl;
            decompte --;
        }
    return 0;
}

