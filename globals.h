// globals.h

#ifndef GLOBALS_H
#define GLOBALS_H

// #include "src/utils/stack.h"  // Include the header file for your stack implementation
#include "src/utils/symtab.h"  // Include the header file for your symbol table implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/parser/codel-syn.tab.h"

// extern int symtab_index = 0;
// extern TypeTS symtab[100];
// extern char save_type[20];

extern YYSTYPE yylval;
// extern stack* parenth_stack;
// extern stack* bracket_stack;
// extern SymbolTable* symbolTable;

extern int yylex();
extern int yyparse();
// extern FILE* yyin;
// extern int yylineno;


// extern void yyerror(const char* msg);

#endif
