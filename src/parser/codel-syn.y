%{
#include "../../globals.h"
// extern NODE *yyroot;
#define EXIT_FAILURE 1

void yyerror(const char *s);

char save_type[20];
char save_op[10];

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
%token PLUS MINUS MULT <str>DIV INC
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

%type <entier>expression

%start start
%%

start:                  prog_head prog_body;

prog_head:        
                        declaration_list 
;
prog_body:              kw_BEGIN instruction_list kw_END  {printf("\ncompilation finished: symbol table is: \n"); YYACCEPT;}
                        |
                        instruction_list kw_END {yyerror("Missing BEGIN");}
                        |
                        kw_BEGIN instruction_list {yyerror("Missing END");}
                        |
                        instruction_list {yyerror("Missing BEGIN and END");}
                       
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
        operand operator expression {
            if(!strcmp(save_op,"div_op") && $3 == 0){
                yyerror("Sematic error: division on 0");
            }
        }
        |
        operand
;
operator: 
        MULT { strcpy(save_op,"mult_op");}
        |
        DIV { strcpy(save_op,"div_op");}
        |
        PLUS { strcpy(save_op,"add_op");}
        |
        MINUS { strcpy(save_op,"sub_op");}
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
            if(identificateurNonDecl($1)){
                            insererType($1,"UNDECLARED");
                        };
        }
        ;


instruction_list:   
                        instruction instruction_list | ;


instruction:
                         assign_ins SEMICOLON
                        | assign_ins { yyerror("Missing SEMICOLON after assign instruction");}
                        | for_loop_ins {printf("for loop instruction!");}
                        | if_ins  {printf("if ins incoming!");}
;
bool_value:         
                    val_TRUE 
                    |
                    val_FALSE;

assign_ins_bool:    ID ASSIGN_OP bool_value {
                        if(identificateurNonDecl($1)){
                            insererType($1,"UNDECLARED");
                        };

} ;

assign_ins:
                    ID ASSIGN_OP expression {
                        if(identificateurNonDecl($1)){
                            insererType($1,"UNDECLARED");
                        };
                    }
                    |
                    assign_ins_bool;
                    |
                     ID INC { printf($1); };

for_loop_ins:
                   for_loop_head for_loop_body;

for_loop_head:
                FOR PARENTH_OPEN for_loop_head_init COMMA for_loop_head_cond COMMA for_loop_head_incr PARENTH_CLOSE  { printf("for loop here!");}
                |
                FOR PARENTH_OPEN for_loop_head_init for_loop_head_cond for_loop_head_incr PARENTH_CLOSE { yyerror("Missing COMMAS in forloop head"); };

for_loop_head_init:
                 ID ASSIGN_OP operand;

for_loop_head_cond:
                 ID logical_operator operand 
                 |
                 operand logical_operator ID;

for_loop_head_incr:
                 ID INC 
                 |
                 INC ID;

for_loop_body:
                  BRACKET_OPEN instruction_list BRACKET_CLOSE
                  |
                  for_loop_instructions_none;

for_loop_instructions_none: SEMICOLON;


expression_condition:
                   operand logical_operator operand  {printf("exp condition here!");};

condition:
                    expression_condition {printf("condition here!");}
                    |
                    NOT condition 
                    ;

if_ins:
                    IF PARENTH_OPEN condition PARENTH_CLOSE BRACKET_OPEN instruction_list BRACKET_CLOSE else_part {printf("if here!");};
else_part:          
                     ELSE BRACKET_OPEN instruction_list BRACKET_CLOSE | ;


%%
