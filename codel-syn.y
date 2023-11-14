%{
#include <stdio.h>
// extern NODE *yyroot;
%}
%locations

%union {
int     entier;
char*   str;
}

%token BEGIN END
%token DIGIT  
%token BOOL INT FLOAT  
%token PLUS MINUS MULT DIV  
%token LESS GREATER NOTEQUAL LESSEQ GREATEQ EQUAL   
%token NOT     
%token PARENTH_OPEN PARENTH_CLOSE
%token BRACKET_OPEN BRACKET_CLOSE
%token ASSIGN_OP
%token LETTER 
%token INTEGER
%token REAL   
%token <str> ID
%token COMMA COLON SEMICOLON
%token FOR
%token IF
%token ELSE

%%

start:                  declaration_list BEGIN instruction_list END;
declaration_list:       declaration_list declaration | ;
instruction_list:       instruction_list instruction | {
  // Check for unbalanced parentheses
  if (!check_parentheses()){
    printf("Unbalanced parentheses");
  }
}
 ;
type_specifier:         INT | FLOAT | BOOL;
arithmetic_operator:    PLUS | MINUS | MULT | DIV ;
condition_operator:     LESS | GREATER | NOTEQUAL | LESSEQ | GREATEQ | EQUAL;
number:                 ID | INTEGER | REAL;
sum:                    number PLUS number ;
substraction:           number MINUS number;
multiplication:         number MULT number ; {
  if()
}
division:               number DIV number {
  if ($3==0)
   printf("erreur semantique divsion sur 0 at line %d",yylineno);
  };

declaration:            variable_declaration | constant_declaration;
variable_declaration:   "VAR" ID COLON type_specifier;
constant_declaration:   "CONST" type_specifier assign;

condition_expression:   ID | INTEGER | REAL | condition_expression condition_operator condition_expression;
arithmetic_expression:  ID | INTEGER | REAL | arithmetic_expression operator arithmetic_expression;

simple_variable:        type_specifier ID | type_specifier ID "," ID; 
assign_ins:                 ID ASSIGN_OP arithmetic_expression | ID ASSIGN_OP BOOL;

for_loop_ins:               FOR PARENTH_OPEN ID ASSIGN_OP COMMA condition_expression COMMA counter PARENTH_CLOSE 
                        BRACKET_OPEN
                            instruction
                        BRACKET_CLOSE;

if_ins:           IF PARENTH_OPEN condition_expression PARENTH_CLOSE
                        BRACKET_OPEN
                            instruction
                        BRACKET_CLOSE
                        ELSE BRACKET_OPEN
                                instruction
                        BRACKET_CLOSE ;

instruction:            
                        | assign_ins SEMICOLON
                        | for_loop_ins 
                        | if_ins
;
counter:                 ID PLUS PLUS | ID MINUS MINUS ; // ID has to be same as for loop variable, add more ops
%%

int main() {
    yyparse();
    // print_tree(yyroot);
    return 0;
}

