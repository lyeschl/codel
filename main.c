#include <stdio.h>
#include <stdlib.h>
#include "codel-syn.tab.h"
#include "symbol_table.h"
#include "stack.h"
#include <stdbool.h>
#include <string.h>
int main(int argc, char *argv[]) {

symbolTable = createSymbolTable();
init_stack(parenth_stack, 50);
init_stack(bracket_stack, 50);

 if (argc != 2) {
        printf("Usage: %s inputfile.txt\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

  
  
   yyin = inputFile;
   yyparse();
    yylex();

  if (!stackIsEmpty(parenth_stack)) {
    printf("Error: Parentheses are not balanced\n");
    exit(EXIT_FAILURE);
  }

  if (!stackIsEmpty(bracket_stack)) {
    printf("Error: Brackets are not balanced\n");
    exit(EXIT_FAILURE);
  }

  printf("Compilation completed, No Errors found\n");

   printSymbolTable(symbolTable);  // Print the symbol table at the end
  fclose(inputFile);
    // yyparse();
    // print_tree(yyroot);

    freeSymbolTable(symbolTable);
    return 0;
}

