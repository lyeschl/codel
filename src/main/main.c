#include "../../globals.h"
int main()
{
    init();
    yyparse();
    display_symbol_table();
    return 0;
}

int yywrap()
{
    return 1;
}
