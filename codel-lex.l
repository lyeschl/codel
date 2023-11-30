%{
#include "codel-syn.tab.h"
#include "symbol_table.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    PARENTH_OPEN,
    PARENTH_CLOSE,
    BRACKET_OPEN,
    BRACKET_CLOSE,
    INTEGER,
    ID,
    UNKNOWN,
} TokenType;

SymbolTable symbolTable = createSymbolTable();
extern YYSTYPE yylval;
int current_line = 1;

stack parenth_stack;
stack bracket_stack;

void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
    exit(EXIT_FAILURE);
}
%}

%option yylineno

BEGIN              "BEGIN"
END                "END"
INT                "INT"
FLOAT              "FLOAT"
BOOL               "BOOL"
CONST              "CONST"
HASHTAG            "#"
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
TRUE               "True"
FALSE              "False"
PARENTH_OPEN       "("     
PARENTH_CLOSE      ")"
BRACKET_OPEN       "{"
BRACKET_CLOSE      "}"
INTEGER            [-+]?([0-9])+
REAL               [-+]?[0-9]+"."[0-9]
ID                 [a-zA-Z]([a-zA-Z]|[0-9]|([_]([a-zA-Z]|[0-9])))*
%%

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

{INTEGER} {
  yylval.entier = atoi(yytext);
  return INTEGER;
}

{ID} {
  if (yyleng > 10){
    printf("Error: Identifier '%s' at line %d exceeds 10 characters\n", yytext, current_line);
    exit(EXIT_FAILURE);
  }
    if (searchSymbol(&symbolTable, yytext) != NULL) {
        yyerror("ID already declared");
        exit(EXIT_FAILURE);
    }

    insertSymbol(&symbolTable, yytext, "UNKNOWN_TYPE", false); // Assuming a default type and not constant
    yylval.str = strdup(yytext); // Allocating memory and copying the identifier
    return ID;
}
[ \t]
\n {
}

. {
  printf("Error: Invalid character '%s' at line %d\n", yytext, yylineno);
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
  yyin = inputFile;
  yyparse();
  // yylex();

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
int yywrap() {
    return 1;  // indicate end of input
}