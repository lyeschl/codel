%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
// extern NODE *yyroot;
SymbolTable* symbolTable;
#define EXIT_FAILURE 1
char* storedID;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;
// forloop counter
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
%token BOOL INT FLOAT  
%token PLUS MINUS MULT DIV  
%token LESS GREATER NOTEQUAL LESSEQ GREATEQ EQUAL   
%token NOT     
%token PARENTH_OPEN PARENTH_CLOSE
%token BRACKET_OPEN BRACKET_CLOSE
%token ASSIGN_OP
%token <entier> INTEGER 
%token <real> REAL   
%token <str> ID
%token COMMA COLON SEMICOLON
%token FOR
%token IF
%token ELSE

%type <real> arithmetic_expression
%type <real> assign_ins
%type <boolean> condition expression_condition

%left PLUS MINUS
%left MULT DIV
%left UMINUS  // Unary minus

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

variable_declaration: type_specifier identifier_list COLON ;
constant_declaration:   CONST type_specifier assign_ins;

type_specifier:         INT | FLOAT | BOOL;
identifier_list:        ID | identifier_list COLON ID;


arithmetic_expression: arithmetic_expression PLUS arithmetic_expression { $$ = $1 + $3; }
                    | arithmetic_expression MINUS arithmetic_expression { $$ = $1 - $3; }
                    | arithmetic_expression MULT arithmetic_expression { $$ = $1 * $3; }
                    | arithmetic_expression DIV arithmetic_expression {
                        if ($3 == 0)
                            printf("Semantic error: Division by zero at line %d\n", yylineno);
                        else
                            $$ = $1 / $3;
                         }
                    | MINUS arithmetic_expression %prec UMINUS { $$ = -($2); }  
                    | ID { 
                        if (searchSymbol(symbolTable, $1) == NULL) {
                            yyerror("Undeclared variable used in assignment");
                        }
                        $$ = strdup($1); free($1);}
                    | INTEGER { $$ = atoi($1); }
                    | REAL { $$ = atof($1); }
                    ;


instruction_list:       instruction_list instruction | ;

instruction:            
                        | assign_ins SEMICOLON
                        | assign_ins error { yyerror("Missing SEMICOLON after assign instruction");}
                        | for_loop_ins 
                        | if_ins
;

for_loop_ins:           FOR PARENTH_OPEN ID ASSIGN_OP COMMA condition COMMA counter PARENTH_CLOSE 
                        BRACKET_OPEN
                            instruction
                        BRACKET_CLOSE
{ 
                        if (searchSymbol(symbolTable, $3) == NULL) {
                            yyerror("Undeclared variable used in assignment");
                        }
                        }

                        | FOR PARENTH_OPEN ID ASSIGN_OP error condition error counter PARENTH_CLOSE 
                        BRACKET_OPEN
                            instruction
                        BRACKET_CLOSE { yyerror("Missing COMMAS in forloop head"); }
;
condition:             PARENTH_OPEN expression_condition PARENTH_CLOSE { $$ = $2 }
                    |   NOT condition %prec UMINUS
                    ;

expression_condition:    expression_condition LESS expression_condition
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

                    |   INTEGER {$$ = $1}
                    |   REAL {$$ = $1}

                    ;
assign_ins:             ID ASSIGN_OP arithmetic_expression {
                    if (searchSymbol(symbolTable, $1) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    $$ = $3;
                    }

                    | ID ASSIGN_OP TRUE {
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


if_ins:                 IF PARENTH_OPEN condition PARENTH_CLOSE
                        BRACKET_OPEN
                            instruction
                        BRACKET_CLOSE
                        ELSE BRACKET_OPEN
                                instruction
                        BRACKET_CLOSE ;
                  


counter: ID PLUS PLUS { checkCounterID($1); /* handle i++ */ }
       | ID MINUS MINUS { checkCounterID($1); /* handle i-- */ }
       | ID ASSIGN_OP ID { checkCounterID($1); /* handle i := j */ }
       | ID ASSIGN_OP ID MULT ID { checkCounterID($1); /* handle i := j * k */ }
       | ID ASSIGN_OP ID DIV ID  { checkCounterID($1); /* handle i := j / k */ }
       | ID ASSIGN_OP INTEGER { checkCounterID($1); /* handle i := 5 */ }
       | error { yyerror("inappropriate counter in forloop");} 

%%

int main() {
    symbolTable = createSymbolTable();
    yyparse();
    // print_tree(yyroot);
    printSymbolTable(symbolTable);  // Print the symbol table at the end
    return 0;
}

