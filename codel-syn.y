%{
#include <stdio.h>
// extern NODE *yyroot;
%}
%locations

%union {
int     entier;
char*   str;
double  real;
}

%token BEGIN END CONST
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

%%

start:                  declaration_list BEGIN instruction_list END
                        | error {yyerror("Missing BEGIN or END");}
;
declaration_list:       declaration_list declaration | ;
instruction_list:       instruction_list instruction | ;
type_specifier:         INT | FLOAT | BOOL;

arithmetic_operator:    PLUS | MINUS | MULT | DIV ;
condition_operator:     LESS | GREATER | NOTEQUAL | LESSEQ | GREATEQ | EQUAL;

number: ID { $$ = $1; }
      | INTEGER { $$ = $1; }
      | REAL { $$ = $1; }
      ;

sum: number PLUS number { $$ = $1 + $3; }
   ;

substraction: number MINUS number { $$ = $1 - $3; }
            ;

multiplication: number MULT number { $$ = $1 * $3; }
              ;

division: number DIV number {
            if ($3 == 0)
                printf("Semantic error: Division by zero at line %d\n", yylineno);
            else
                $$ = $1 / $3;
         }
        ;
declaration:            variable_declaration SEMICOLON | constant_declaration SEMICOLON 
                        | variable_declaration error { yyerror("Missing SEMICOLON after variable declaration");}
                        | constant_declaration error { yyerror("Missing SEMICOLON after constant declaration");}
;
variable_declaration:   type_specifier identifier_list COLON ;
identifier_list:        ID | identifier_list COLON ID ;    
constant_declaration:   CONST type_specifier assign_ins;

condition_expression:   ID | INTEGER | REAL | condition_expression condition_operator condition_expression;
arithmetic_expression:  sum | substraction | multiplication | division ;

assign_ins:             ID ASSIGN_OP arithmetic_expression | ID ASSIGN_OP BOOL;

for_loop_ins:           FOR PARENTH_OPEN ID ASSIGN_OP COMMA condition_expression COMMA counter PARENTH_CLOSE 
                        BRACKET_OPEN
                            instruction
                        BRACKET_CLOSE
                        | FOR PARENTH_OPEN ID ASSIGN_OP error condition_expression error counter PARENTH_CLOSE 
                        BRACKET_OPEN
                            instruction
                        BRACKET_CLOSE { yyerror("Missing COMMAS in forloop head"); }
;
if_ins:                 IF PARENTH_OPEN condition_expression PARENTH_CLOSE
                        BRACKET_OPEN
                            instruction
                        BRACKET_CLOSE
                        ELSE BRACKET_OPEN
                                instruction
                        BRACKET_CLOSE ;
                  

instruction:            
                        | assign_ins SEMICOLON
                        | assign_ins error { yyerror("Missing SEMICOLON after assign instruction");}
                        | for_loop_ins 
                        | if_ins
;
counter: ID PLUS PLUS   { /* handle i++ */ }
       | ID MINUS MINUS { /* handle i-- */ }
       | ID ASSIGN_OP ID { /* handle i := j */ }
       | ID ASSIGN_OP ID MULT ID { /* handle i := j * k */ }
       | ID ASSIGN_OP ID DIV ID  { /* handle i := j / k */ }
       | ID ASSIGN_OP INTEGER { /* handle i := 5 */ }
       ; 

%%
// forloop counter
void checkCounterID(char* id) {
    if (strcmp(id, storedID) != 0) {
        fprintf(stderr, "Semantic error: Counter ID '%s' does not match loop head ID '%s'\n", id, storedID);
    }
}
void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}
int main() {
    yyparse();
    // print_tree(yyroot);
    return 0;
}

