#include <iostream>

#include <stdio.h>
#include <stdlib.h>


int main()
{
      char pass[20];
      char ch;
      short i = 0;
      short j = 0;
      puts("Entrez votre mot de passe");

      while(i < 20 && j == 0)
      {

              if(ch == '\r')
              {
                    j =20;
              }

              else if( ch != '\r')
              {
                   pass[i] = ch;
                   printf("*");
                   i++;
              }
      }

      pass[i]='\0';

      printf("Votre mot de passe est : %s\n", pass);
    return 0;

return 0;
}


