#include "../../globals.h"
int main()
{
    init();
    yylex();
    yyparse();
    display_symbol_table();
    return 0;
}

int yywrap()
{
    return 1;
}
