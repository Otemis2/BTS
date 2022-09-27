


CAffranchissement::CAffranchissement()
{

    tableauPoid[0] = 20;
    tableauPoid[1] = 50;
    tableauPoid[2] = 100;
    tableauPoid[3] = 250;
    tableauPoid[4] = 500;
    tableauPoid[5] = 1000;
    tableauPoid[6] = 2000;
    tableauPoid[7] = 3000;

     //faire le tableau prix


    tableauPoid[0][0] = 1.42;
    tableauPoid[1][0] = 2.39;
    tableauPoid[2][0] = 2.39;
    tableauPoid[3][0] = 4.33;
    tableauPoid[4][0] = 6.27;
    tableauPoid[5][0] = 8.21;
    tableauPoid[6][0] = 8.21;
    tableauPoid[7][0] = 8.21;

    tableauPrix[0][1]= 0.97;
    tableauPrix[1][1]= 1.94;
    tableauPrix[2][1]= 1.94;
    tableauPrix[3][1]= 3.88;
    tableauPrix[4][1]= 5.82;
    tableauPrix[5][1]= 7.76;
    tableauPrix[6][1]= 7.76;
    tableauPrix[7][1]= 7.76;


    tableauPrix[0][2]= 4.30;
    tableauPrix[1][2]= 4.85;
    tableauPrix[2][2]= 5.50;
    tableauPrix[3][2]= 6.70;
    tableauPrix[4][2]= 7.85;
    tableauPrix[5][2]= 9.00;
    tableauPrix[6][2]= 10.70;
    tableauPrix[7][2]= 11.93;


    tableauPrix[0][3]= 1.16;
    tableauPrix[1][3]= 2.32;
    tableauPrix[2][3]= 2.32;
    tableauPrix[3][3]= 4.64;
    tableauPrix[4][3]= 6.96;
    tableauPrix[5][3]= 9.28;
    tableauPrix[6][3]= 9.28;
    tableauPrix[7][3]= 9.28;

}
/*
Methode affranchireColis
Variable : i: entier court non signé
Debut
    si (tarifcolis >=0 ET tarifcolis <4 ) ET (poidscolis >=0 ET poidscolis <=3000)
    alors
        i<-0
        tant que (poidsColis < tableauPoids[i]) Faire
            i<- i+1
        FIN tant que

        prixColis<-tableauTarif[i][tarifColis]
        prixTotal<-prixTotal+prixColis
        nbColis<-nbColis+1
        retourné vrai
    sinon
        retourné Faux
    Fin Si

Fin

  */
CAffranchissement::AffranchireColis()
{
    if((tarifColis>=0 && tarifColis<=3)&&(poidsColis >=0 && poidsColis <=3000))
    {
        unsigned short i=0;
        while (poidsColis < tableauPoids[i])
        {
                i++;
        }
        prixColis=tableauTarif[i][tarifColis];
        prixTotal=prixTotal+prixColis;
        nbColis=nbColis+;
        return true;
    }
    else
    {
        return false;
    }

}






