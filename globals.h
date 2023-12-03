// globals.h

#ifndef GLOBALS_H
#define GLOBALS_H

#include "src/utils/stack.h"  // Include the header file for your stack implementation
#include "src/utils/symbol_table.h"  // Include the header file for your symbol table implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/parser/codel-syn.tab.h"

extern stack* parenth_stack;
extern stack* bracket_stack;
extern SymbolTable* symbolTable;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

extern YYSTYPE yylval;

extern void yyerror(const char* msg);

int arr_size(char** arr);

#endif
