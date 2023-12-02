%{
#include "codel-syn.tab.h"
#include "symbol_table.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern YYSTYPE yylval;

void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
    exit(EXIT_FAILURE);
}
%}

%option yylineno

kw_BEGIN              "BEGIN"
kw_END                "END"
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
  push(parenth_stack, '(');
  return PARENTH_OPEN;
}

{PARENTH_CLOSE} {
  if (stackIsEmpty(parenth_stack)) {
    exit(EXIT_FAILURE);
  }
  pop(parenth_stack);
  return PARENTH_CLOSE;
}

{BRACKET_OPEN} {
  push(bracket_stack, '{');
  return BRACKET_OPEN;
}

{BRACKET_CLOSE} {
  if (stackIsEmpty(bracket_stack)) {
    exit(EXIT_FAILURE);
  }
  pop(bracket_stack);
  return BRACKET_CLOSE;
}

{INTEGER} {
  yylval.entier = atoi(yytext);
  return INTEGER;
}

{ID} {
  if (yyleng > 10){
    printf("Error: Identifier '%s' at line %d exceeds 10 characters\n", yytext, yylineno);
    exit(EXIT_FAILURE);
  }
    if (searchSymbol(symbolTable, yytext) != NULL) {
        yyerror("ID already declared");
        exit(EXIT_FAILURE);
    }

    insertSymbol(symbolTable, yytext, "UNKNOWN_TYPE", false); // Assuming a default type and not constant
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
int yywrap() {
    return 1;  // indicate end of input
}