%{
#include <stdio.h>
#include <stdlib.h>
#include "codel-syn.tab.h"
#include "symbol_table.h"
#include "stack.h"
#include <stdbool.h>
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
void checkCounterID(char* id) {
    if (strcmp(id, storedID) != 0) {
        fprintf(stderr, "Semantic error: Counter ID '%s' does not match loop head ID '%s'\n", id, storedID);
    }
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
bool    boolean;
}

%token BEGIN END CONST
%token TRUE FALSE
%token BOOL 
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

%type <entier> int_arithmetic_expression
%type <real> float_arithmetic_expression

%type <entier> assign_ins_int
%type <real> assign_ins_float
%type <boolean> assign_ins_bool

%type <boolean> condition expression_condition
%type <str> identifier_list 
%type <str> type_specifier

%left PLUS MINUS
%left MULT DIV
%right UMINUS  // Unary minus

%start start
%%

start:                  declaration_list BEGIN instruction_list END
                        | error {yyerror("Missing BEGIN or END");}
;
declaration_list:       declaration_list declaration | ;
declaration:            variable_declaration SEMICOLON 
                        | constant_declaration SEMICOLON 
                        | variable_declaration error { yyerror("Missing SEMICOLON after variable declaration");}
                        | constant_declaration error { yyerror("Missing SEMICOLON after constant declaration");}
;

variable_declaration:  type_specifier identifier_list COLON {
                        // Add each ID to the symbol table with type and isConstant set to False
                        int size = arr_size($2);
                        for (int i = 0; i < size; i++) {
                            modifyEntry(symbolTable, $2[i], $1, false);
                            free($2[i]);
                        }
                        free($2);
                    }
                    ;

constant_declaration: int_constant_declaration | float_constant_declaration ;

int_constant_declaration: CONST INT ID ASSIGN_OP int_arithmetic_expression {
    // Add the ID to the symbol table with type and isConstant set to True
   modifyEntry(symbolTable, $3, $2, true);
};

float_constant_declaration: CONST FLOAT ID ASSIGN_OP float_arithmetic_expression {
    // Add the ID to the symbol table with type and isConstant set to True
   modifyEntry(symbolTable, $3, $2, true);
};

type_specifier: INT    { $$ = strdup("INT"); }
              | FLOAT  { $$ = strdup("FLOAT"); }
              | BOOL   { $$ = strdup("BOOL"); };

identifier_list: ID { $$ = malloc(sizeof(char*)); $$[0] = strdup($1); }
               | identifier_list COLON ID {
                   int size = arr_size($1);
                   $$ = realloc($1, (size + 1) * sizeof(char*));
                   $$[size] = strdup($3);
               }
               ;


int_arithmetic_expression: int_arithmetic_expression PLUS int_arithmetic_expression { $$ = $1 + $3; }
                    | int_arithmetic_expression MINUS int_arithmetic_expression { $$ = $1 - $3; }
                    | int_arithmetic_expression MULT int_arithmetic_expression { $$ = $1 * $3; }
                    | int_arithmetic_expression DIV int_arithmetic_expression {
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
                        $$ = strdup($1); free($1);}
                    | INTEGER { $$ = atoi($1); }
                    ;


float_arithmetic_expression: float_arithmetic_expression PLUS float_arithmetic_expression { $$ = ($1) + ($3); }
                    | float_arithmetic_expression MINUS float_arithmetic_expression { $$ = ($1) - ($3); }
                    | float_arithmetic_expression MULT float_arithmetic_expression { $$ = ($1) * ($3); }
                    | float_arithmetic_expression DIV float_arithmetic_expression {
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
                        $$ = strdup($1); free($1);
                        }
                    | REAL { 
                        // $$ = atof($1);
                         }
                    ;


instruction_list:       instruction_list instruction | ;

instruction:            
                        | assign_ins SEMICOLON
                        | assign_ins error { yyerror("Missing SEMICOLON after assign instruction");}
                        | for_loop_ins 
                        | if_ins
;

for_loop_ins:            for_loop_head for_loop_body;
for_loop_head:           FOR PARENTH_OPEN assign_ins COMMA condition COMMA counter PARENTH_CLOSE;
                        | FOR PARENTH_OPEN ID ASSIGN_OP error condition error counter PARENTH_CLOSE
                            { yyerror("Missing COMMAS in forloop head"); }
for_loop_body:           BRACKET_OPEN instruction BRACKET_CLOSE;


condition:             PARENTH_OPEN expression_condition PARENTH_CLOSE { $$ = $2; }
                    |   NOT condition { $$ = !$2; }
                    ;

expression_condition:   expression_condition_less
                    |   expression_condition GREATER expression_condition
                    |   expression_condition NOTEQUAL expression_condition
                    |   expression_condition LESSEQ expression_condition
                    |   expression_condition GREATEQ expression_condition
                    |   expression_condition EQUAL expression_condition
                    |   ID {
                    if (searchSymbol(symbolTable, $1) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    }
                    |   INTEGER {$$ = $1;}
                    |   REAL {$$ = $1;}

                    ;
expression_condition_less:      expression_condition LESS expression_condition;
assign_ins:         assign_ins_int | assign_ins_float | assign_ins_bool ; 
                   
assign_ins_int:     ID ASSIGN_OP int_arithmetic_expression {
                    if (searchSymbol(symbolTable, $1) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    $$ = $3;
                    };

assign_ins_float:   ID ASSIGN_OP float_arithmetic_expression {
                    if (searchSymbol(symbolTable, $1) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    $$ = $3;
                    };

assign_ins_bool:    ID ASSIGN_OP TRUE {
                    if (searchSymbol(symbolTable, $1) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    }
                    | ID ASSIGN_OP FALSE {
                    if (searchSymbol(symbolTable, $1) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    }
                    ;


if_ins:             simple_if_ins | complex_if_ins;

simple_if_ins:      if_ins_head if_ins_body            ;
complex_if_ins:     if_ins_head if_ins_body else_statement ;

if_ins_head:        IF condition;
if_ins_body:        BRACKET_OPEN instruction BRACKET_CLOSE;
else_statement:     ELSE instruction;


counter: ID PLUS PLUS { checkCounterID($1); /* handle i++ */ }
       | ID MINUS MINUS { checkCounterID($1); /* handle i-- */ }
       | ID ASSIGN_OP ID { checkCounterID($1); /* handle i := j */ }
       | ID ASSIGN_OP ID MULT ID { checkCounterID($1); /* handle i := j * k */ }
       | ID ASSIGN_OP ID DIV ID  { checkCounterID($1); /* handle i := j / k */ }
       | ID ASSIGN_OP INTEGER { checkCounterID($1); /* handle i := 5 */ }
       | error { yyerror("inappropriate counter in forloop");} 

%%

int main() {
    // symbolTable = createSymbolTable();
    yyparse();
    // print_tree(yyroot);
    printSymbolTable(symbolTable);  // Print the symbol table at the end
    return 0;
}

