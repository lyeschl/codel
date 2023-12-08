%{

#include "../../globals.h"
// extern NODE *yyroot;
#define EXIT_FAILURE 1

void yyerror(const char *s);
extern int current_line;
char save_type[20];

%}
%locations

%union {
int     entier;
char*   str;
double  real;
int     boolean;
}

%token kw_BEGIN kw_END 
%token CONST
%token val_TRUE val_FALSE
%token <str>BOOL 
%token <str>INT
%token <str>FLOAT  
%token PLUS MINUS MULT DIV INC
%token LESS GREATER EQUAL   
%token NOT     
%token PARENTH_OPEN PARENTH_CLOSE
%token BRACKET_OPEN BRACKET_CLOSE
%token ASSIGN_OP
%token <entier>INTEGER 
%token <real>REAL   
%token <str>ID
%token COMMA COLON SEMICOLON
%token FOR
%token IF ELSE

%left MULT DIV
%left PLUS MINUS
%left NOT
%left EQUAL NOTEQUAL
%left LESS GREATER LESSEQ GREATEQ


%start start
%%

start:        
                        declaration_list kw_BEGIN instruction_list kw_END {printf("correct syntax \n"); YYACCEPT;}
                        |
                        declaration_list instruction_list kw_END {yyerror("Missing BEGIN");}
                        |
                        declaration_list kw_BEGIN instruction_list {yyerror("Missing END");}
                        |
                        declaration_list instruction_list {yyerror("Missing BEGIN and END");}
;
declaration_list:       
                        declaration declaration_list  | ;

declaration:
                        variable_declaration SEMICOLON 
                        | 
                        constant_declaration SEMICOLON 
                        |
                        variable_declaration { yyerror("Missing SEMICOLON after variable declaration");}
                        |
                        constant_declaration { yyerror("Missing SEMICOLON after constant declaration");}
;

type_specifier: 
                    INT {strcpy(save_type,$1);}
                    | 
                    FLOAT {strcpy(save_type,$1);}
                    |
                    BOOL {strcpy(save_type,$1);}
;     
variable_declaration:
                      type_specifier var_dec_id_list
                    ;
var_dec_id_list:
                        var_dec_id COMMA var_dec_id_list 
                        |
                        var_dec_id ;

var_dec_id:
        ID {
        doubleDeclaration($1);
        if (!doubleDeclaration($1))
        {
            insererType($1, save_type);
            insererConst($1,0);
        }
    }
;

const_type:
            INT {strcpy(save_type,$1);} 
            |
            FLOAT {strcpy(save_type,$1);};

constant_declaration:
                         CONST const_type ID ASSIGN_OP const_value {
    // Add the ID to the symbol table with type and isConstant set to True
       if (!doubleDeclaration($3))
        {
            insererType($3, save_type);
            insererConst($3,1);
        }
}
                       | CONST const_type ID { yyerror("Malformed constant declaration"); };

const_value:
             INTEGER 
             |
             REAL;

expression:
        operand operator expression 
        |
        operand
;
operator: 
        MULT
        |
        DIV
        |
        PLUS
        |
        MINUS
;
logical_operator:
        EQUAL
        |
        LESS
        |
        GREATER
        |
        LESS EQUAL
        |
        GREATER EQUAL
        |
        NOT EQUAL
;
operand:
        const_value
        |
        ID {
            identificateurNonDecl($1);
        }
        ;


instruction_list:   
                        instruction instruction_list | ;


instruction:
                         assign_ins SEMICOLON
                        | assign_ins error { yyerror("Missing SEMICOLON after assign instruction");}
                        | for_loop_ins 
                        | if_ins
;
bool_value:         
                    val_TRUE 
                    |
                    val_FALSE;

assign_ins_bool:    ID ASSIGN_OP bool_value {
    identificateurNonDecl($1);
} ;

assign_ins:
                    ID ASSIGN_OP expression {
                        identificateurNonDecl($1);
                    }
                    |
                    assign_ins_bool;
                    |
                     ID INC ;

for_loop_ins:
                   for_loop_head for_loop_body { printf("for loop here!");};

for_loop_head:
                FOR PARENTH_OPEN for_loop_head_init COMMA for_loop_head_cond COMMA for_loop_head_incr PARENTH_CLOSE 
                |
                FOR PARENTH_OPEN for_loop_head_init for_loop_head_cond for_loop_head_incr PARENTH_CLOSE { yyerror("Missing COMMAS in forloop head"); };

for_loop_head_init:
                 ID ASSIGN_OP operand;

for_loop_head_cond:
                 ID logical_operator operand | operand logical_operator ID;

for_loop_head_incr:
                 ID INC 
                 |
                 INC ID;

for_loop_body:
                  BRACKET_OPEN for_loop_instructions BRACKET_CLOSE
                  |
                  for_loop_instructions_none;
for_loop_instructions:
                  instruction_list;
for_loop_instructions_none: ;


expression_condition:
                   operand logical_operator operand ;

condition:
                    PARENTH_OPEN expression_condition PARENTH_CLOSE 
                    |
                    NOT condition 
                    ;

if_ins:
                     IF condition BRACKET_OPEN body BRACKET_CLOSE else_part;
body:
                     instruction_list;
else_part:          |
                     ELSE BRACKET_OPEN body BRACKET_CLOSE;


%%
