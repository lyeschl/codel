%{
#include <stdio.h>
#include <stdlib.h>
#include "codel-syn.tab.h"
#include "symbol_table.h"
#include "stack.h"
#include <stdbool.h>
#include <string.h>
// extern NODE *yyroot;
SymbolTable* symbolTable;
#define EXIT_FAILURE 1
char* storedID;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;
// forloop counter
// Helper function to get the size of the array
int arr_size(char** arr) {
    int size = 0;
    while (arr[size] != NULL) {
        size++;
    }
    return size;
}
void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
    exit(EXIT_FAILURE);
}
%}
%locations

%union {
int     entier;
char*   str;
double  real;
int    boolean;
}

%token BEGIN END CONST
%token TRUE FALSE
%token <str>BOOL 
%token <str> INT
%token <str> FLOAT  
%token PLUS MINUS MULT DIV  
%token LESS GREATER NOTEQUAL LESSEQ GREATEQ EQUAL   
%token NOT     
%token PARENTH_OPEN
%token PARENTH_CLOSE
%token BRACKET_OPEN
%token BRACKET_CLOSE
%token ASSIGN_OP
%token <entier> INTEGER 
%token <real> REAL   
%token <str> ID
%token COMMA COLON SEMICOLON
%token FOR
%token IF
%token ELSE
%token HASHTAG


%type <entier> int_arithmetic_expression
%type <real> float_arithmetic_expression


%type <boolean> condition expression_condition
%type <str> identifier_list 
%type <str> const_type 
%type <str> type_specifier 

%left MULT DIV
%left PLUS MINUS
%left NOT
%left EQUAL NOTEQUAL
%left LESS GREATER LESSEQ GREATEQ
%right UMINUS  // Unary minus


%start start
%%

start:                  declaration_list BEGIN instruction_list END
                        | declaration_list error instruction_list END {yyerror("Missing BEGIN");}
                        | declaration_list BEGIN instruction_list error {yyerror("Missing END");}
;
declaration_list:       declaration_list declaration | empty_statement ;
empty_statement: ;
declaration:            variable_declaration SEMICOLON 
                        | constant_declaration SEMICOLON 
                        | variable_declaration error { yyerror("Missing SEMICOLON after variable declaration");}
                        | constant_declaration error { yyerror("Missing SEMICOLON after constant declaration");}
;

type_specifier:        INT | FLOAT | BOOL;
variable_declaration:  type_specifier identifier_list {
                        // Add each ID to the symbol table with type and isConstant set to False
                        int size = arr_size($2);
                        for (int i = 0; i < size; i++) {
                            modifyEntry(symbolTable, $2[i], $1, false);
                            free($2[i]);
                        }
                        free($2);
                    }
                    ;



const_type: INT | FLOAT;
constant_declaration: CONST const_type ID ASSIGN_OP const_arithmetic_expression {
    // Add the ID to the symbol table with type and isConstant set to True
   modifyEntry(symbolTable, $3, $2, true);
};
const_arithmetic_expression: int_arithmetic_expression | float_arithmetic_expression;


identifier_list: ID {
     $$ = malloc(sizeof(char*)); $$[0] = strdup($1);
      }
               | identifier_list COLON ID {
                   int size = arr_size($1);
                   $$ = realloc($1, (size + 1) * sizeof(char*));
                   $$[size] = strdup($3);
               }
               ;


arithmetic_operator: PLUS | MINUS | MULT | DIV;
int_arithmetic_expression: int_arithmetic_expression arithmetic_operator int_arithmetic_expression { 
    $$ = $1 + $3; 
                        if ($3 == 0)
                            printf("Semantic error: Division by zero at line %d\n", yylineno);
                        else
                            $$ = $1 / $3;
                         }
                    | MINUS int_arithmetic_expression %prec UMINUS { $$ = -($2); }  
                    | ID { 
                        if (searchSymbol(symbolTable, $1) == NULL) {
                            yyerror("Undeclared variable used in assignment");
                        }
                        $$ = strdup($1); free($1);
                        }
                    | INTEGER {
                         $$ = atoi($1);
                          }
                    ;

float_arithmetic_expression: float_arithmetic_expression arithmetic_operator float_arithmetic_expression { 
    $$ = ($1) + ($3);
     
                        if ($3 == 0)
                            printf("Semantic error: Division by zero at line %d\n", yylineno);
                        else
                            $$ = $1 / $3;
                         }
                    | MINUS float_arithmetic_expression %prec UMINUS { $$ = -($2); }  
                    | ID { 
                        if (searchSymbol(symbolTable, $1) == NULL) {
                            yyerror("Undeclared variable used in assignment");
                        }
                        $$ = atof($1); free($1);
                        }
                    | REAL { 
                        $$ = $1;
                         }
                    ;


instruction_list:       instruction_list instruction | empty_statement;
instruction:             assign_ins SEMICOLON
                        | assign_ins error { yyerror("Missing SEMICOLON after assign instruction");}
                        | for_loop_ins 
                        | conditional_ins
;

arithmetic_expression: int_arithmetic_expression | float_arithmetic_expression;

id_assign_op: ID ASSIGN_OP;
bool_value:         TRUE | FALSE;
assign_ins_bool:    id_assign_op bool_value ;
assign_ins:         id_assign_op arithmetic_expression | assign_ins_bool;

for_loop_ins:   for_loop_head for_loop_body;
for_loop_head: FOR PARENTH_OPEN assign_ins COMMA condition COMMA assign_ins PARENTH_CLOSE
                | FOR PARENTH_OPEN assign_ins error condition error assign_ins PARENTH_CLOSE { yyerror("Missing COMMAS in forloop head"); };

for_loop_body:  BRACKET_OPEN for_loop_instructions BRACKET_CLOSE
                    | error PARENTH_CLOSE BRACKET_OPEN for_loop_body BRACKET_CLOSE ;

for_loop_instructions: instruction_list ;


condition:             PARENTH_OPEN expression_condition PARENTH_CLOSE { $$ = $2; }
                    |   NOT condition { $$ = !$2; }
                    ;

logical_operator: LESS | LESSEQ | GREATER | GREATEQ | EQUAL | NOTEQUAL;
expression_condition:   expression_condition logical_operator expression_condition
                    |   ID {
                    if (searchSymbol(symbolTable, $1) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    }
                    |   INTEGER {
                        $$ = $1;
                        }
                    |   REAL {
                        $$ = $1;
                        }

                    ;

conditional_ins: IF condition BRACKET_OPEN body BRACKET_CLOSE else_part;
body: instruction_list;
else_part: empty_else| ELSE BRACKET_OPEN body BRACKET_CLOSE;
empty_else: ;


%%

int main() {
    symbolTable = createSymbolTable();
    yyparse();
    // print_tree(yyroot);
    printSymbolTable(symbolTable);  // Print the symbol table at the end
    return 0;
}

