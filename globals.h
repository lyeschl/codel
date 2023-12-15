// globals.h

#ifndef GLOBALS_H
#define GLOBALS_H

#include "src/utils/symtab.h"  // Include the header file symbol table implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "src/parser/codel-syn.tab.h"

extern YYSTYPE yylval;
extern int yylex();
extern int yyparse();
#endif
