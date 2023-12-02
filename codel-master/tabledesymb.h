
#ifndef TABLE_SYMBOLE_H
#define TABLE_SYMBOLE_H

// Structure definition
typedef struct TS {
  char NomEntite[20];
  char CodeEntite[20];
  char TypeEntite[20];
} TS;

// Constant for maximum number of entities
#define MAX_ENTITIES 1000

// Function prototypes
int recherche(char entite[]);
void inserer(char entite[], char code[]);
void afficher();
int modifier(char entite[], char nouvelleValeur[]);

// Global variable
extern int CpTabSym;
extern TS tstab[MAX_ENTITIES];

#endif 
