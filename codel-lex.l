%{
#include "codel-syn.tab.h"
#include "symbole_table.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern YYSTYPE yylval;
int current_line = 1;

stack parenth_stack;
stack bracket_stack;

%}

%option yylineno
%option noyywrap

LETTER             [a-zA-Z]
DIGIT              [0-9]
TRUE               "True"
FALSE              "False"
ID                 [a-zA-Z]([a-zA-Z]|[0-9]|([_]([a-zA-Z]|[0-9])))*
INTEGER            [-+]?({DIGIT})+
REAL               [-+]?{DIGIT}+"."{DIGIT}
PARENTH_OPEN       "("
PARENTH_CLOSE      ")"
BRACKET_OPEN       "{"
BRACKET_CLOSE      "}"
BEGIN              "BEGIN"
END                "END"
INT                "INT"
FLOAT              "FLOAT"
BOOL               "BOOL"
CONST              "CONST"
COLON              ":"
SEMICOLON          ";"
COMMA              ","
PLUS               "+"
MINUS              "-"
MULT               "*"
DIV                "/"
LESS               "<"
GREATER            ">"
NOTEQUAL           "<>"
LESSEQ             "<="
GREATEQ            ">="
EQUAL              "=="
NOT                "!"
ASSIGN_OP          ":="
FOR                "for"
IF                 "if"
ELSE               "else"

%%

"{"[^}]*"}"      /* Ignore comments enclosed in curly braces */
{BEGIN} {
  return "BEGIN";
}
{END} {
  return "END";
}
{INTEGER} {
  yylval.entier = atoi(yytext);
  printf("INTEGER\t%d\tLine %d\n", yylval.entier, current_line);
  return INTEGER;
}

{REAL} {
  // yylval.real is a double 
  yylval.real = atof(yytext);
  return REAL;
}

{PARENTH_OPEN} {
  push(&parenth_stack, '(');
  return PARENTH_OPEN;
}

{PARENTH_CLOSE} {
  if (stackIsEmpty(&parenth_stack)) {
    exit(EXIT_FAILURE);
  }
  pop(&parenth_stack);
  return PARENTH_CLOSE;
}

{BRACKET_OPEN} {
  push(&bracket_stack, '{');
  printf("BRACKET_OPEN\t%s\tLine %d\n", yytext, current_line);
  return BRACKET_OPEN;
}

{BRACKET_CLOSE} {
  if (stackIsEmpty(&bracket_stack)) {
    printf("Error: Unmatched closing bracket '%s' at line %d\n", yytext, current_line);
    exit(EXIT_FAILURE);
  }
  pop(&bracket_stack);
  printf("BRACKET_CLOSE\t%s\tLine %d\n", yytext, current_line);
  return BRACKET_CLOSE;
}

{ID} {
  if (yyleng > 10){
    printf("Error: Identifier '%s' at line %d exceeds 10 characters\n", yytext, current_line);
    exit(EXIT_FAILURE);
  }
  if (searchSymbol(symbolTable, $1) != NULL) {
    yyerror("ID already declared");
    exit(EXIT_FAILURE);
  }
    insertSymbol(symbolTable,$1)
    yylval.str = strdup(yytext); // Allocating memory and copying the identifier
    return ID;
}
[ \t]
\n {
  current_line++;
}

. {
  printf("Error: Invalid character '%s' at line %d\n", yytext, current_line);
  exit(EXIT_FAILURE);
}
%%
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s inputfile.txt\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        perror("Error opening file");
        return 1;
    }
  init_stack(&parenth_stack, 50);
  init_stack(&bracket_stack, 50);
  yylex();

  if (!stackIsEmpty(&parenth_stack)) {
    printf("Error: Parentheses are not balanced\n");
    exit(EXIT_FAILURE);
  }

  if (!stackIsEmpty(&bracket_stack)) {
    printf("Error: Brackets are not balanced\n");
    exit(EXIT_FAILURE);
  }

  printf("Compilation completed, No Errors found\n");

  fclose(inputFile);

  return 0;
}
