%{
#include "codel-syn.tab.h"
#include <stdio.h>
#include<stdbool.h>
int current_line = 1;

// int opened_parenth=0;
// int closed_parenth=0;
// 
// int opened_bracket=0;
// int closed_bracket=0;

// stack data structure used to assure that open and closed brackets and parenths are equal
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
bool stackIsEmpty(stack *s){
    return s->top==-1;
}
void push(stack *s, char c) {
  if (s->top == s->size - 1) {
    printf("Stack overflow\n");
    exit(1);
  }
  s->data[++s->top] = c;
}
char pop(stack *s) {
  if (s->top == -1) {
    printf("Stack underflow\n");
    exit(1);
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
END                 "END"
INT                  "INT"
FLOAT                 "FLOAT"
BOOL                  "BOOL"
CONST               "CONST"
COLON                ":"
SEMICOLON             ";"
COMMA                 ","
PLUS                  "+"
MINUS                 "-"
MULT                  "*"
DIV                   "/"
LESS                  "<"
GREATER                ">"
NOTEQUAL                "<>"
LESSEQ                  "<="
GREATEQ                 ">="
EQUAL                   "=="
NOT                     "!"
ASSIGN_OP                ":="
FOR                     "for"
IF                      "if"
ELSE                    "else"
%%


{ID} {
  if(yyleng<=10){
    return ID;
  }else{
    printf("Error: identifier cannot be longer than 10 chars");
  }
  
};         
{PARENTH_OPEN} {
  push(&parenth_stack,'(');
};

{PARENTH_CLOSE} {
  pop(&parenth_stack);
};

{BRACKET_OPEN} {
  push(&bracket_stack,'{');
};

{BRACKET_CLOSE} {
  pop(&bracket_stack);
};
[ \t]
\n {current_line++;}
.                  { /* Ignore all other characters */ }
{COMMENT} {
  printf("comment detected at line %d",current_line);
  for(int i = 0 ; i<strlen(yytext);i++)
    if(yytext[i] == '\n')
      ++current_line;
}
%%
int main() {
  yylex();
  init_stack(&parenth_stack,50);
  init_stack(&bracket_stack,50);
  if(!stackIsEmpty(&parenth_stack)){
    printf("Error: parentheses are not balanced");
  }

  if(!stackIsEmpty(&bracket_stack)){
    printf("Error: brackets are not balanced");
  }
  // if (yylex() != 0){
  //   printf("Error: Invalid token at line %d \n", yylineno);
  // }
  printf("Compilation completed , No Errors found");
  return 0;
}