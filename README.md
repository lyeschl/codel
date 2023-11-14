
ARITHMETIC  ({INTEGER}|{REAL}|{ID}"+"|"-"|"*"|"/")";"
ASSIGN      {ID}":="{ARITHMETIC}

# Notes
### DONE:
- comments
- seperate to flex file and bison file
### TODO
- CST (should) (have) (an) assign
- bruh just ask chatgpt for more help
- add nested for and if statements
- add in for loops to check the condition statement
- add OR AND OPERATORS
- fix simple variable ,
- use yyleng
- learn yylval
routine symantique ; check symboles table
semantic 5/0 type float 
add table symboles , idfs no repition ; check presence before insertion ; afficher table symbole at the end (this is done normally in C)
fonction recherch ; insertion ; afficher
- remove column count
use fopen to read from text file

#### on assign
- a space between IDs should be optional (use ? op)

####
INSTRUC     ({SVAR}|{CST}|{MULTI_SVAR})";"
- add for and if 

### Tests:
```
CONST INT bism=33;
INT A83_n,app,reste;
FLOAT Kms,LL6,Jn5;
BOOL reponse;
```

- fix nibba_ being recognized as an ID, IDs shouldnt have _ in the end
- IDs length should be <10


string            \"(\\.|[^\\"])*\"



Projet de TP : Création d’un Mini Compilateur
Le but de ce projet est de réaliser un mini-compilateur d’un langage appelé « CodeL », en effectuant
les différentes phases de la compilation : lexical, syntaxique et sémantique.
I.
Description du Langage CodeL
II.1 La structure générale
```
Liste Declarations
BEGIN
Liste Instructions
END
```
A) Liste des déclarations
Nous pouvons déclarer dans ce langage des variables simples et des constantes.
-
Variable simple : Type NomVariable ;
-
Constante : CONST Type NomConstante ;
Exemple
```
CONST INT bism=33;
INT A83_n,app,reste;
FLOAT Kms,LL6,Jn5;
BOOL reponse;
```
-
Les trois types possibles sont : INT, FLOAT et BOOL
-
La déclaration d’un ensemble de variables s’effectue en séparant les noms de variables par
‘,’.
-
Chaque nomVariable est un identificateur. Un identificateur (idf) commence par une lettre
alphabétique majuscule (A-Z) suivie d’une suite de chiffres (0-9), lettres alphabétiques (
A-Z et a-z ), ou bien le symbole '_' . Sa taille ne doit pas dépasser 10 caractères.
Les identificateurs doivent respecter les conditions suivantes :
>
L’idf ne doit pas contenir de symboles '_' successifs.
>
Le le symbole '_' ne doit pas apparaître à la fin de l’idf.
-
Un identificateur peut revoir une constante, Il y a deux types de constantes :
a) Les constantes entières : C’est une suite de chiffres, qui peut être signée ou pas
b) Les constantes réelles : C’est une suite de chiffres contenant le point décimal, qui






B) Liste des Instructions
Dans notre langage, SEULES les instructions suivantes sont autorisées :
Affectation
Idf := expression arithmétique ;
A :=C*B;
A :=2;

Boucle
For (var :=valInit, condition, compteur)
{
Bloc Instructions
}
For (I:=1 ;i<=10 ;i++)
{
B:=B+2;
}

condition
If (Condition) { Bloc instructions}
else { Bloc instructions}
If (a==2) {
B :=5 ;
C :=B+1 ;
-
Les expressions arithmétiques utilisent les opérateurs arithmétiques : + - * /
Les conditions utilisent les opérateurs relationnels : < <= <> == > >=
C) Les commentaires
-
Les commentaires sont une suite de caractères quelconques compris entre ‘{‘ et ‘}’, ne
contenant pas de ‘}’.
D) Travail à réaliser :
Ci-dessous les différentes phases à effectuer afin de réaliser le compilateur demandé.
-
Analyse lexicale avec l’outil FLEX.
-
Analyse syntaxique avec l'outil Bison
-
Analyse sémantique pour les erreurs suivantes :
●
Idf non déclaré
●
Idf double déclarée
●
Non compatibilité de type
●
Changement de valeur d’une constante
-
Gestion de la table de symboles La table doit avoir au minimum les champs suivants :
-
Nom : l’identificateur qui indique le nom de la variable ou constante.
-
Type : le type de la variable ou la constante
-
Const : indique si la variable est constante ou non.
-
Traitement des erreurs :
Il est demandé d’afficher les messages d’erreurs adéquats à chaque étape du processus de
compilation, en précisant le numéro de ligne et la colonne de l’erreur.