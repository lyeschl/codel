%{
#include "../../globals.h"
int current_line = 1;
extern YYSTYPE yylval;
void yyerror(const char* msg) {
  fprintf(stderr, "Error at line %d: %s\n", current_line, msg);
  exit(EXIT_FAILURE);
}
%}

INTEGER            [-+]?([0-9])+
REAL               [-+]?[0-9]+"."[0-9]
ID                 [a-zA-Z]([a-zA-Z]|[0-9]|([_]([a-zA-Z]|[0-9])))*
comment            \{[^}]*\}
%%
"INT"    {
    yylval.str = strdup(yytext);
    return INT;
}
"FLOAT"   {
    yylval.str = strdup(yytext);
    return FLOAT;
}
"BOOL" {
    yylval.str = strdup(yytext);
    return BOOL;
}

"(" return PARENTH_OPEN;
")" return PARENTH_CLOSE;
"{" return BRACKET_OPEN;
"}" return BRACKET_CLOSE;

"<" return LESS;
">" return GREATER;
"==" return EQUAL;
"!" return NOT;
"," return COMMA;
"++" return INC;
"*" return MULT;
"/" return DIV;
"+" return PLUS;
"-" return MINUS;
":=" return ASSIGN_OP;
";" return SEMICOLON; 
"for" return FOR;
"if" return IF;
"else" return ELSE;
"CONST" return CONST;
"True" return val_TRUE;
"False" return val_FALSE;
"BEGIN"   return kw_BEGIN;
"END"     return kw_END;

{INTEGER} {
  yylval.entier = atoi(yytext);
  return INTEGER;
}
{REAL} {
  yylval.entier = atof(yytext);
  return REAL;
}

{ID} {
  if (yyleng > 10){
    printf("Error: Identifier '%s' at line %d exceeds 10 characters\n", yytext, yylineno);
    exit(EXIT_FAILURE);
  }
  yylval.str = strdup(yytext);
  inserer(yytext,"idf");
  return ID;
}
[ \t]
\n {++current_line;}
{comment} {
 // printf("commentaire detecté au ligne %d\n", current_line);
    // BugFix: The loop below adds line count that is eaten within comment.
    // NB: Test other "multi-line-capable" blocks of code for the same bug...
    for (int i = 0; i < strlen(yytext); i++)
        if (yytext[i] == '\n')
            ++current_line;
}
. {
  printf("Lexical Error: Invalid character '%s' at line %d\n", yytext, current_line);
  exit(EXIT_FAILURE);
}
%%
