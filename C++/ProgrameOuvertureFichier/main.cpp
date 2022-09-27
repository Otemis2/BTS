#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int main()
{
    fstream fichier ("test1.txt");
    char car;
    unsigned short nbCarLu =0;
    if (fichier.is_open())
    {
        while (fichier.eof()==false)
        {
            fichier.seekg(nbCarLu);
            fichier >> car;
            car = car +1;
            fichier.seekg(nbCarLu);
            fichier << car;
            nbCarLu++;
        }
    }
    else
    {
        cout << "non ouvert"<<endl;
    }

    return 0;
}
