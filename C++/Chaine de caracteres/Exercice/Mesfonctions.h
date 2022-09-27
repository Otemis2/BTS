#ifndef MESFONCTIONS_H
#define MESFONCTIONS_H

void mettreMajuscules (char* chaine);
void mettreMinuscules (char* chaine);
void nettoyerChaine (char* chaine);

short determinerOccurenceA (char* chaine);
short determinerOccurence (char* chaine,char caractere);

bool etrePalindrome(char* chaine);
bool proposer(char* motSecret, char* motTrouve,char lettreProposer);

#endif // MESFONCTIONS_H
