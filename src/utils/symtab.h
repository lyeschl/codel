#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define UNKNOWN_SIZE -1
typedef struct
{
    char NomEntite[20];
    char CodeEntite[20];
    char TypeEntite[20];
    int estConstant;
} TypeTS;

//initiation d'un tableau qui va contenir les elements de la table de symbole
extern TypeTS symtab[100];

// un compteur global pour la table de symbole
extern int symtab_index;

// Initialiser table a 0, pour eviter les problemes.
void init();

//une fonctione recherche: pour chercher est ce que l'entit� existe ou non d�j� dans la table de symbole.
// i: l'entite existe dej� dans la table de symbole, et sa position est i, -1: l'entit� n'existe pas dans la table de symbole.
int recherche(char entite[]);

//une fontion qui va ins�rer les entit�s de programme dans la table de symbole
void inserer(char entite[], char code[]);

//une fonction pour afficher la table de symbole
void display_symbol_table();

//fonction qui change le type d'une etit� une fois il va �tre reconnu dans la syntaxe 
void insererType(char entite[], char type[]);
void insererConst(char entite[], int estConstant);
char* getTypeFromID(char* id);

//////////////////////////////////////////////////////
////Les routines semantiques
int doubleDeclaration(char entite[]);
int identificateurNonDecl(char entite[]);

const char* isFloat(double num);

const char* getTypeByName(const char* entityName);