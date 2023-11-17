%{
#include "codel-syn.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern YYSTYPE yylval;
int current_line = 1;

typedef struct stack {
  char *data;
  int top;
  int size;
} stack;

void init_stack(stack *s, int size) {
  s->data = malloc(sizeof(char) * size);
  s->top = -1;
  s->size = size;
}

bool stackIsEmpty(stack *s) {
  return s->top == -1;
}

void push(stack *s, char c) {
  if (s->top == s->size - 1) {
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
  }
  s->data[++s->top] = c;
}

char pop(stack *s) {
  if (s->top == -1) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
  }
  return s->data[s->top--];
}

stack parenth_stack;
stack bracket_stack;

%}

%option yylineno
%option noyywrap

LETTER             [a-zA-Z]
DIGIT              [0-9]
ID                 {LETTER}({LETTER}|{DIGIT}|"_"{1}) 
INTEGER            [-+]?({DIGIT})+
REAL               [-+]?{DIGIT}+"."{DIGIT}
COMMENT            \{[^}]*\}
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

{ID} {
  if (yyleng <= 10) {
    yylval.str = strdup(yytext); // Allocating memory and copying the identifier
    printf("ID\t%s\tLine %d\n", yylval.str, current_line);
    return ID;
  } else {
    printf("Error: Identifier '%s' at line %d exceeds 10 characters\n", yytext, current_line);
    exit(EXIT_FAILURE);
  }
}

{INTEGER} {
  yylval.entier = atoi(yytext);
  printf("INTEGER\t%d\tLine %d\n", yylval.entier, current_line);
  return INTEGER;
}

{REAL} {
  // yylval.real is a double 
  yylval.real = atof(yytext);
  printf("REAL\t%f\tLine %d\n", yylval.real, current_line);
  return REAL;
}

{PARENTH_OPEN} {
  push(&parenth_stack, '(');
  printf("PARENTH_OPEN\t%s\tLine %d\n", yytext, current_line);
  return PARENTH_OPEN;
}

{PARENTH_CLOSE} {
  if (stackIsEmpty(&parenth_stack)) {
    printf("Error: Unmatched closing parenthesis '%s' at line %d\n", yytext, current_line);
    exit(EXIT_FAILURE);
  }
  pop(&parenth_stack);
  printf("PARENTH_CLOSE\t%s\tLine %d\n", yytext, current_line);
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

[ \t]
\n {
  current_line++;
}

. {
  printf("Error: Invalid character '%s' at line %d\n", yytext, current_line);
  exit(EXIT_FAILURE);
}

{COMMENT} {
  printf("COMMENT\t%s\tLine %d\n", yytext, current_line);
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
