#include "../../globals.h"

extern int current_line;

int symtab_index = 0;
TypeTS symtab[100];
void init()
{
    memset(symtab, 0, sizeof(symtab));
}

int recherche(char entite[])
{
    int i = 0;
    while (++i < symtab_index)
        if (strcmp(entite, symtab[i].NomEntite) == 0)
            return i;
    return -1;
}

void inserer(char entite[], char code[])
{
    if (recherche(entite) == -1)
    {
        strcpy(symtab[symtab_index].NomEntite, entite); 
        strcpy(symtab[symtab_index].CodeEntite, code);
        symtab_index++;
    }
}

void display_symbol_table()
{
    printf(
        "%s%s%s%s",
        "\n\t/*********************Symbol Table*************************/\n",
        "\t __________________________________________________________ \n",
        "\t| EntityName |  EntityCode  |  EntityType   |  isConstant?  |\n",
        "\t|----------------------------------------------------------|\n"
    );
    int i = 0;
    while (i < symtab_index) {
 
 
 
 
        printf(
            "\t|%11s |%12s  |%12s   | %11d  |\n",
            symtab[i].NomEntite,
            symtab[i].CodeEntite,
            symtab[i].TypeEntite,
            symtab[i].estConstant
        );
        i++;
    }
    printf("\t ----------------------------------------------------------\n");
}

void insererType(char entite[], char type[])
{
    int posEntite = recherche(entite);
    if (posEntite != -1)
        strcpy(symtab[posEntite].TypeEntite, type);
}

void insererConst(char entite[], int estConstant){
    int posEntite = recherche(entite);
    if (posEntite != -1)
        symtab[posEntite].estConstant = estConstant;
}

char* getTypeFromID(char* id)
{
    return symtab[recherche(id)].TypeEntite;
}

//////////////////////////////////////////////////////
////Les routines semantiques
int doubleDeclaration(char entite[])
{
    int posEntite = recherche(entite);
    if (strcmp(symtab[posEntite].TypeEntite, "") == 0)
        return 0;
    printf("erreur sémantique: double-decl de %s à la ligne %d\n", entite, current_line);
    return 1;
}

int identificateurNonDecl(char entite[])
{
    int posEntite = recherche(entite);
    if (0 == strcmp(symtab[posEntite].TypeEntite, ""))
    {
        printf("erreur sémantique à la ligne %d : id non-decl %s\n", current_line, entite);
        return 1;
    }
    return 0;
}
