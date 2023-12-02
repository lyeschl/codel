
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TS
{
char NomEntite[20];
char CodeEntite[20];
char TypeEntite[20];
} TS;
TS tstab[1000];

int CpTabSym=0;

int recherche(char entite[])
{
int i=0;
while(i<CpTabSym)
{
if (strcmp(entite,tstab[i].NomEntite)==0) return i;
i++;
}

return -1;
}

void inserer(char entite[], char code[])
{
if ( recherche(entite)==-1)
{
strcpy(tstab[CpTabSym].NomEntite,entite);
strcpy(tstab[CpTabSym].CodeEntite,code);
CpTabSym++;
}
}

void afficher ()
{
printf("\n/***************Table des symboles ******************/\n");
printf("________________________\n");
printf("\t| NomEntite | CodeEntite \n");
printf("________________________\n");
int i=0;
while(i<CpTabSym)
{
printf("\t|%10s |%12s |\n",tstab[i].NomEntite,tstab[i].CodeEntite,tstab[i].TypeEntite);
i++;
}
}
int modifier(char entite[], char nouvelleValeur[]) {
  int index = recherche(entite);
  if (index == -1) {
    return -1; 
  }
  strcpy(tstab[index].NomEntite, entite); 
  strcpy(tstab[index].CodeEntite, entite); 
  strcpy(tstab[index].TypeEntite, entite); 
  return 1;
}
